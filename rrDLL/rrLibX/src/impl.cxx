/// \copyright Unlicense

#define _CRT_SECURE_NO_WARNINGS

#include "impl.hxx"

using namespace std;

namespace rrlibx {

handle impl::alloc()
{
    auto mov_ptr = unique_ptr<impl> {new impl};
    const auto h = reinterpret_cast<handle>(mov_ptr.get());
    instance_owner_.insert(make_pair(h, move(mov_ptr)));
    return h;
}

void impl::free(handle h)
{
    instance_owner_.erase(h);
}

impl &impl::ref(handle h)
{
    return *instance_owner_.at(h);
}

unordered_map<handle, unique_ptr<impl>> impl::instance_owner_;

void impl::last_internal_error_message(const std::string &val)
{
    last_internal_error_message_[this_thread::get_id()] = val;
}

const std::string &impl::last_internal_error_message()
{
    return last_internal_error_message_[this_thread::get_id()];
}

}
