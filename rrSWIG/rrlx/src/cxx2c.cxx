/// \copyright Unlicense

#include "cxx2c.hxx"

#include <any>
#include <exception>
#ifdef __GNUC__
#include <experimental/filesystem>
#else
#include <filesystem>
#endif
#include <future>
#include <memory>
#include <optional>
#include <regex>
#include <stdexcept>
#include <system_error>
#include <variant>

#include "rrlx/exception.hxx"

using namespace std;
#ifdef __GNUC__
using namespace std::experimental;
#endif

namespace rrlx {

rrlx_handle_t clazz2handle::alloc()
{
    auto p = make_unique<clazz2handle>();
    const auto h = reinterpret_cast<rrlx_handle_t>(p.get());
    wrappers_owner_.insert(make_pair(h, move(p)));
    return h;
}

void clazz2handle::free(rrlx_handle_t handle)
{
    wrappers_owner_.erase(handle);
}

clazz2handle &clazz2handle::ref(rrlx_handle_t handle)
{
    return *wrappers_owner_.at(handle);
}

unordered_map<rrlx_handle_t, unique_ptr<clazz2handle>> clazz2handle::wrappers_owner_;

clazz *clazz2handle::operator->()
{
    return &content;
}

void clazz2handle::last_error_message(const string &value)
{
    last_error_message_[this_thread::get_id()] = value;
}

[[nodiscard]] const string &clazz2handle::last_error_message()
{
    return last_error_message_[this_thread::get_id()];
}

rrlx_status_t exception2status(rrlx_handle_t handle, const function<rrlx_status_t()> &lambda) noexcept
{
    try {
        return lambda();
    } catch (const internal_exception &e) {
        if (handle) { ref(handle).last_error_message(e.what()); } return rrlx_internal_exception;
    } catch (const invalid_argument &e) {
        if (handle) { ref(handle).last_error_message(e.what()); } return rrlx_invalid_argument;
    } catch (const domain_error &e) {
        if (handle) { ref(handle).last_error_message(e.what()); } return rrlx_domain_error;
    } catch (const length_error &e) {
        if (handle) { ref(handle).last_error_message(e.what()); } return rrlx_length_error;
    } catch (const out_of_range &e) {
        if (handle) { ref(handle).last_error_message(e.what()); } return rrlx_out_of_range;
    } catch (const future_error &e) {
        if (handle) { ref(handle).last_error_message(e.what()); } return rrlx_future_error;
    } catch (const logic_error &e) {
        if (handle) { ref(handle).last_error_message(e.what()); } return rrlx_logic_error;
    } catch (const bad_optional_access &e) {
        if (handle) { ref(handle).last_error_message(e.what()); } return rrlx_bad_optional_access;
    } catch (const range_error &e) {
        if (handle) { ref(handle).last_error_message(e.what()); } return rrlx_range_error;
    } catch (const overflow_error &e) {
        if (handle) { ref(handle).last_error_message(e.what()); } return rrlx_overflow_error;
    } catch (const underflow_error &e) {
        if (handle) { ref(handle).last_error_message(e.what()); } return rrlx_underflow_error;
    } catch (const regex_error &e) {
        if (handle) { ref(handle).last_error_message(e.what()); } return rrlx_regex_error;
    } catch (const ios_base::failure &e) {
        if (handle) { ref(handle).last_error_message(e.what()); } return rrlx_ios_base_failure;
    } catch (const filesystem::filesystem_error &e) {
        if (handle) { ref(handle).last_error_message(e.what()); } return rrlx_filesystem_filesystem_error;
    } catch (const system_error &e) {
        if (handle) { ref(handle).last_error_message(e.what()); } return rrlx_system_error;
    } catch (const runtime_error &e) {
        if (handle) { ref(handle).last_error_message(e.what()); } return rrlx_runtime_error;
    } catch (const bad_typeid &e) {
        if (handle) { ref(handle).last_error_message(e.what()); } return rrlx_bad_typeid;
    } catch (const bad_any_cast &e) {
        if (handle) { ref(handle).last_error_message(e.what()); } return rrlx_bad_any_cast;
    } catch (const bad_cast &e) {
        if (handle) { ref(handle).last_error_message(e.what()); } return rrlx_bad_cast;
    } catch (const bad_weak_ptr &e) {
        if (handle) { ref(handle).last_error_message(e.what()); } return rrlx_bad_weak_ptr;
    } catch (const bad_function_call &e) {
        if (handle) { ref(handle).last_error_message(e.what()); } return rrlx_bad_function_call;
    } catch (const bad_array_new_length &e) {
        if (handle) { ref(handle).last_error_message(e.what()); } return rrlx_bad_array_new_length;
    } catch (const bad_alloc &e) {
        if (handle) { ref(handle).last_error_message(e.what()); } return rrlx_bad_alloc;
    } catch (const bad_exception &e) {
        if (handle) { ref(handle).last_error_message(e.what()); } return rrlx_bad_exception;
    } catch (const bad_variant_access &e) {
        if (handle) { ref(handle).last_error_message(e.what()); } return rrlx_bad_variant_access;
    } catch (const std::exception &e) {
        if (handle) { ref(handle).last_error_message(e.what()); } return rrlx_exception;
    } catch (...) {
        if (handle) { ref(handle).last_error_message("a unexpected exception occured"); } return rrlx_unexpected_exception;
    }
}

}
