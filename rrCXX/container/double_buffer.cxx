/// \copyright Unlicense

#include "double_buffer.hxx"

#include <cstdlib>

using namespace std;

namespace rrcxx::double_buffer {

double_buffer::double_buffer(std::size_t item_max) :
    item_max_ {item_max},
    left_buf_ {nullptr, [](item_type *p) -> void { free(p); }},
    right_buf_ {nullptr, [](item_type *p) -> void { free(p); }}
{
    left_buf_.reset(reinterpret_cast<item_type *>(malloc(buffer_size())));
    right_buf_.reset(reinterpret_cast<item_type *>(malloc(buffer_size())));
}

double_buffer::~double_buffer() noexcept
{
    change_status(de);
    scoped_lock sl {left_mtx_, right_mtx_};
}

write_token double_buffer::get_write_token()
{
    while (true) {
        // 若正在析构，放弃操作，抛出异常
        if (stat_ == de)
            throw runtime_error {"the buffer is destructing"};

        switch (stat_) {
        case uu: {
            unique_lock lk {left_mtx_, defer_lock};
            if (lk.try_lock())
                return write_token {left_buf_.get(), left_cnt_, *this, move(lk)};
            break;
        }
        case au: {
            unique_lock lk {right_mtx_, defer_lock};
            if (lk.try_lock())
                return write_token {right_buf_.get(), right_cnt_, *this, move(lk)};
            break;
        }
        case ua: {
            unique_lock lk {left_mtx_, defer_lock};
            if (lk.try_lock())
                return write_token {left_buf_.get(), left_cnt_, *this, move(lk)};
            break;
        }
        default:
            throw runtime_error {"unexpected switch-case routing"};
        }

        // 双缓存命中丢失，稍事等待后再次尝试
        this_thread::sleep_for(10ms);
    }
}

read_token double_buffer::get_read_token()
{
    while (true) {
        // 若正在析构，放弃操作，抛出异常
        if (stat_ == de)
            throw runtime_error {"the buffer is destructing"};

        switch (stat_) {
        case uu:
            throw runtime_error {"the buffer not yet available"};
        case au: {
            shared_lock lk {left_mtx_, defer_lock};
            if (lk.try_lock())
                return read_token {left_buf_.get(), left_cnt_, move(lk)};
            break;
        }
        case ua: {
            shared_lock lk {right_mtx_, defer_lock};
            if (lk.try_lock())
                return read_token {right_buf_.get(), right_cnt_, move(lk)};
            break;
        }
        default:
            throw runtime_error {"unexpected switch-case routing"};
        }

        // 双缓存命中丢失，稍事等待后再次尝试
        this_thread::sleep_for(10ms);
    }
}

void double_buffer::change_status(status_t target) noexcept
{
    // 若正在析构，放弃操作，直接返回
    if (stat_ == de)
        return;

    lock_guard lg {stat_write_mtx_};
    switch (target) {
    case de:
        stat_ = de;
        break;

    case sw:
        switch (stat_) {
        case uu:
            stat_ = au;
            break;
        case au:
            stat_ = ua;
            break;
        case ua:
            stat_ = au;
            break;
        default:
            break;
        }
        break;

    default:
#       if 1
        abort();
#       else
        throw runtime_error {"unexpected switch-case routing"};
#       endif

    }
}

}
