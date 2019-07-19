/// \copyright Unlicense

#include "wrapper.hxx"

#include <any>
#include <exception>
#include <filesystem>
#include <future>
#include <memory>
#include <optional>
#include <regex>
#include <stdexcept>
#include <system_error>
#include <variant>

#include "rrlx/exception.hxx"

using namespace std;

namespace rrlx {

rrlx_handle_t wrapper::alloc()
{
    auto p = make_unique<wrapper>();
    const auto h = reinterpret_cast<rrlx_handle_t>(p.get());
    wrapper_owner_.insert(make_pair(h, move(p)));
    return h;
}

void wrapper::free(rrlx_handle_t handle)
{
    wrapper_owner_.erase(handle);
}

wrapper &wrapper::ref(rrlx_handle_t handle)
{
    return *wrapper_owner_.at(handle);
}

unordered_map<rrlx_handle_t, unique_ptr<wrapper>> wrapper::wrapper_owner_;

clazz *wrapper::operator->()
{
    return &content;
}

void wrapper::last_error_message(const string &value)
{
    last_error_message_[this_thread::get_id()] = value;
}

void wrapper::last_error_message(string &&value)
{
    last_error_message_[this_thread::get_id()] = move(value);
}

[[nodiscard]]  const string &wrapper::last_error_message()
{
    return last_error_message_[this_thread::get_id()];
}

rrlx_status_t exception_to_status(function<rrlx_status_t()> &&lambda) noexcept
{
    return exception_to_status(nullptr, move(lambda));
}

rrlx_status_t exception_to_status(rrlx_handle_t handle, function<rrlx_status_t()> &&lambda) noexcept
{
    try {
        return lambda();
    } catch (const internal_exception &e) {
        if (handle) ref(handle).last_error_message(e.what()); return rrlx_internal_exception;
    } catch (const invalid_argument &e) {
        if (handle) ref(handle).last_error_message(e.what()); return rrlx_invalid_argument;
    } catch (const domain_error &e) {
        if (handle) ref(handle).last_error_message(e.what()); return rrlx_domain_error;
    } catch (const length_error &e) {
        if (handle) ref(handle).last_error_message(e.what()); return rrlx_length_error;
    } catch (const out_of_range &e) {
        if (handle) ref(handle).last_error_message(e.what()); return rrlx_out_of_range;
    } catch (const future_error &e) {
        if (handle) ref(handle).last_error_message(e.what()); return rrlx_future_error;
    } catch (const logic_error &e) {
        if (handle) ref(handle).last_error_message(e.what()); return rrlx_logic_error;
    } catch (const bad_optional_access &e) {
        if (handle) ref(handle).last_error_message(e.what()); return rrlx_bad_optional_access;
    } catch (const range_error &e) {
        if (handle) ref(handle).last_error_message(e.what()); return rrlx_range_error;
    } catch (const overflow_error &e) {
        if (handle) ref(handle).last_error_message(e.what()); return rrlx_overflow_error;
    } catch (const underflow_error &e) {
        if (handle) ref(handle).last_error_message(e.what()); return rrlx_underflow_error;
    } catch (const regex_error &e) {
        if (handle) ref(handle).last_error_message(e.what()); return rrlx_regex_error;
    } catch (const ios_base::failure &e) {
        if (handle) ref(handle).last_error_message(e.what()); return rrlx_ios_base_failure;
    } catch (const filesystem::filesystem_error &e) {
        if (handle) ref(handle).last_error_message(e.what()); return rrlx_filesystem_filesystem_error;
    } catch (const system_error &e) {
        if (handle) ref(handle).last_error_message(e.what()); return rrlx_system_error;
    } catch (const runtime_error &e) {
        if (handle) ref(handle).last_error_message(e.what()); return rrlx_runtime_error;
    } catch (const bad_typeid &e) {
        if (handle) ref(handle).last_error_message(e.what()); return rrlx_bad_typeid;
    } catch (const bad_any_cast &e) {
        if (handle) ref(handle).last_error_message(e.what()); return rrlx_bad_any_cast;
    } catch (const bad_cast &e) {
        if (handle) ref(handle).last_error_message(e.what()); return rrlx_bad_cast;
    } catch (const bad_weak_ptr &e) {
        if (handle) ref(handle).last_error_message(e.what()); return rrlx_bad_weak_ptr;
    } catch (const bad_function_call &e) {
        if (handle) ref(handle).last_error_message(e.what()); return rrlx_bad_function_call;
    } catch (const bad_array_new_length &e) {
        if (handle) ref(handle).last_error_message(e.what()); return rrlx_bad_array_new_length;
    } catch (const bad_alloc &e) {
        if (handle) ref(handle).last_error_message(e.what()); return rrlx_bad_alloc;
    } catch (const bad_exception &e) {
        if (handle) ref(handle).last_error_message(e.what()); return rrlx_bad_exception;
    } catch (const bad_variant_access &e) {
        if (handle) ref(handle).last_error_message(e.what()); return rrlx_bad_variant_access;
    } catch (const std::exception &e) {
        if (handle) ref(handle).last_error_message(e.what()); return rrlx_exception;
    } catch (...) {
        return rrlx_unexpected_exception;
    }
}

}
