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

#include "rrx/exception.hxx"

using namespace std;
#ifdef __GNUC__
using namespace std::experimental;
#endif

namespace rrx {

rrx_handle_t clazz2handle::alloc()
{
    auto p = make_unique<clazz2handle>();
    auto *const h = reinterpret_cast<rrx_handle_t>(p.get());
    wrappers_owner_.insert(make_pair(h, move(p)));
    return h;
}

void clazz2handle::free(rrx_handle_t handle)
{
    wrappers_owner_.erase(handle);
}

clazz2handle &clazz2handle::ref(rrx_handle_t handle)
{
    return *wrappers_owner_.at(handle);
}

unordered_map<rrx_handle_t, unique_ptr<clazz2handle>> clazz2handle::wrappers_owner_;

void clazz2handle::last_error_message(const string &value)
{
    last_error_message_[this_thread::get_id()] = value;
}

[[nodiscard]] const string &clazz2handle::last_error_message()
{
    return last_error_message_[this_thread::get_id()];
}

rrx_status_t exception2status(rrx_handle_t handle, const function<rrx_status_t()> &lambda) noexcept
{
    try {
        return lambda();
    } catch (const internal_exception &e) {
        if (handle) { ref(handle).last_error_message(e.what()); } return rrx_internal_exception;
    } catch (const invalid_argument &e) {
        if (handle) { ref(handle).last_error_message(e.what()); } return rrx_invalid_argument;
    } catch (const domain_error &e) {
        if (handle) { ref(handle).last_error_message(e.what()); } return rrx_domain_error;
    } catch (const length_error &e) {
        if (handle) { ref(handle).last_error_message(e.what()); } return rrx_length_error;
    } catch (const out_of_range &e) {
        if (handle) { ref(handle).last_error_message(e.what()); } return rrx_out_of_range;
    } catch (const future_error &e) {
        if (handle) { ref(handle).last_error_message(e.what()); } return rrx_future_error;
    } catch (const logic_error &e) {
        if (handle) { ref(handle).last_error_message(e.what()); } return rrx_logic_error;
    } catch (const bad_optional_access &e) {
        if (handle) { ref(handle).last_error_message(e.what()); } return rrx_bad_optional_access;
    } catch (const range_error &e) {
        if (handle) { ref(handle).last_error_message(e.what()); } return rrx_range_error;
    } catch (const overflow_error &e) {
        if (handle) { ref(handle).last_error_message(e.what()); } return rrx_overflow_error;
    } catch (const underflow_error &e) {
        if (handle) { ref(handle).last_error_message(e.what()); } return rrx_underflow_error;
    } catch (const regex_error &e) {
        if (handle) { ref(handle).last_error_message(e.what()); } return rrx_regex_error;
    } catch (const ios_base::failure &e) {
        if (handle) { ref(handle).last_error_message(e.what()); } return rrx_ios_base_failure;
    } catch (const filesystem::filesystem_error &e) {
        if (handle) { ref(handle).last_error_message(e.what()); } return rrx_filesystem_filesystem_error;
    } catch (const system_error &e) {
        if (handle) { ref(handle).last_error_message(e.what()); } return rrx_system_error;
    } catch (const runtime_error &e) {
        if (handle) { ref(handle).last_error_message(e.what()); } return rrx_runtime_error;
    } catch (const bad_typeid &e) {
        if (handle) { ref(handle).last_error_message(e.what()); } return rrx_bad_typeid;
    } catch (const bad_any_cast &e) {
        if (handle) { ref(handle).last_error_message(e.what()); } return rrx_bad_any_cast;
    } catch (const bad_cast &e) {
        if (handle) { ref(handle).last_error_message(e.what()); } return rrx_bad_cast;
    } catch (const bad_weak_ptr &e) {
        if (handle) { ref(handle).last_error_message(e.what()); } return rrx_bad_weak_ptr;
    } catch (const bad_function_call &e) {
        if (handle) { ref(handle).last_error_message(e.what()); } return rrx_bad_function_call;
    } catch (const bad_array_new_length &e) {
        if (handle) { ref(handle).last_error_message(e.what()); } return rrx_bad_array_new_length;
    } catch (const bad_alloc &e) {
        if (handle) { ref(handle).last_error_message(e.what()); } return rrx_bad_alloc;
    } catch (const bad_exception &e) {
        if (handle) { ref(handle).last_error_message(e.what()); } return rrx_bad_exception;
    } catch (const bad_variant_access &e) {
        if (handle) { ref(handle).last_error_message(e.what()); } return rrx_bad_variant_access;
    } catch (const std::exception &e) {
        if (handle) { ref(handle).last_error_message(e.what()); } return rrx_exception;
    } catch (...) {
        if (handle) { ref(handle).last_error_message("a unexpected exception occured"); } return rrx_unexpected_exception;
    }
}

}
