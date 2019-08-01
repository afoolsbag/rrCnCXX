/// \copyright Unlicense

#include "double_huge_buffer.hxx"

#include <cstdlib>

using namespace std;

namespace rrcxx::double_huge_buffer {

double_huge_buffer::double_huge_buffer(std::size_t item_max_count) :
    item_max_count {item_max_count},
    lbuf_ {nullptr, [](item_type *p) -> void { free(p); }},
    rbuf_ {nullptr, [](item_type *p) -> void { free(p); }}
{
    lbuf_.reset(reinterpret_cast<item_type*>(malloc(buffer_size())));
    rbuf_.reset(reinterpret_cast<item_type*>(malloc(buffer_size())));
}

double_huge_buffer::~double_huge_buffer() noexcept
{
    destructing_ = true;
    scoped_lock sl {lmtx_, rmtx_};
}

write_reference &&double_huge_buffer::get_reference_for_write_buffer()
{
    for (;;) {
        if (destructing_)
            throw logic_error {"the buffer is destructing"};

        switch (available_) {
        case both_unavailable: {
            unique_lock lk {lmtx_, defer_lock};
            if (lk.try_lock()) {
                return move(write_reference {lbuf_.get(), lcnt_, *this, move(lk)});
            }
            break;
        }

        case available_unavailable: {
            unique_lock lk {rmtx_, defer_lock};
            if (lk.try_lock()) {
                return move(write_reference {rbuf_.get(), rcnt_, *this, move(lk)});
            }
            break;
        }

        case unavailable_available: {
            unique_lock lk {lmtx_, defer_lock};
            if (lk.try_lock()) {
                return move(write_reference {lbuf_.get(), lcnt_, *this, move(lk)});
            }
            break;
        }

        default:
            throw runtime_error {"unexpected switch-case routing"};
        }

        // double-buffer hit missing
    }
}

read_reference &&double_huge_buffer::get_reference_for_read_buffer()
{
    for (;;) {
        if (destructing_)
            throw logic_error {"the buffer is destructing"};

        switch (available_) {
        case both_unavailable:
            throw logic_error {"the buffer not yet available"};

        case available_unavailable: {
            shared_lock lk {lmtx_, defer_lock};
            if (lk.try_lock()) {
                return move(read_reference {lbuf_.get(), lcnt_, move(lk)});
            }
            break;
        }

        case unavailable_available: {
            shared_lock lk {rmtx_, defer_lock};
            if (lk.try_lock()) {
                return move(read_reference {rbuf_.get(), rcnt_, move(lk)});
            }
            break;
        }

        default:
            throw runtime_error {"unexpected switch-case routing"};
        }

        // double-buffer hit missing
    }
}

write_reference::~write_reference() noexcept
{
    if (owner_.destructing_)
        return;

    switch (owner_.available_) {

    case double_huge_buffer::both_unavailable: {
        owner_.lcnt_ = item_count;
        owner_.available_ = double_huge_buffer::available_unavailable;
    }

    case double_huge_buffer::available_unavailable: {
        owner_.rcnt_ = item_count;
        owner_.available_ = double_huge_buffer::unavailable_available;
        break;
    }

    case double_huge_buffer::unavailable_available: {
        owner_.lcnt_ = item_count;
        owner_.available_ = double_huge_buffer::available_unavailable;
        break;
    }

    default:
        break;
    }
}

}
