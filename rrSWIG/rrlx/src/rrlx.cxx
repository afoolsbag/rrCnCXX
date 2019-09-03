/// \copyright Unlicense

#include "rrlx/rrlx.hxx"

#ifdef _WIN32
#include <Windows.h>
#endif

#include "cfg.hxx"

using namespace std;

#ifdef _WIN32
BOOL WINAPI DllMain(_In_ HINSTANCE hinstDLL, _In_ DWORD fdwReason, _In_ LPVOID lpvReserved)
{
    (void)hinstDLL;

    switch (fdwReason) {
    case DLL_PROCESS_DETACH: {
        const bool is_unloading {lpvReserved == NULL};
        const bool is_terminating {lpvReserved != NULL};
        (void)is_unloading;
        (void)is_terminating;
        return TRUE;
    }
    case DLL_PROCESS_ATTACH: {
        const bool is_dynamic_loading {lpvReserved == NULL};
        const bool is_static_loading {lpvReserved != NULL};
        (void)is_dynamic_loading;
        (void)is_static_loading;
        return TRUE;
    }
    case DLL_THREAD_ATTACH: {
        return TRUE;
    }
    case DLL_THREAD_DETACH: {
        return TRUE;
    }
    default:
        return FALSE;
    }
}
#endif

#ifdef __linux__
EXTERN_C void __attribute__ ((constructor)) init(void)
{

}
EXTERN_C void __attribute__ ((destructor)) fini(void)
{

}
#endif

namespace rrlx {

RRLX_API version_t STDCALL version()
{
    return {
        static_cast<int>(project_version_major),
        static_cast<int>(project_version_minor),
        static_cast<int>(project_version_patch),
        static_cast<int>(project_version_tweak)
    };
}

class clazz::impl final {
public:
    explicit impl() = default;
    explicit impl(const impl &) = default;
    impl &operator=(const impl &) = default;
    explicit impl(impl &&) noexcept = default;
    impl &operator=(impl &&) noexcept = default;
    ~impl() noexcept = default;

    inline void basic(int value);
    [[nodiscard]] inline int basic() const;

    void array(const array_t &value);
    [[nodiscard]] inline const array_t &array() const;

    inline void string(const std::string &value);
    [[nodiscard]] inline const std::string &string() const;

    inline void set_callback(const callback_t &callback, void *p_user_data);
    inline void invoke_callback() const;

private:
    int basic_ {};
    array_t array_;
    std::string string_;
    callback_t callback_;
    void *p_user_data_ {};
};

RRLX_API clazz::clazz() : impl_ {make_unique<impl>()} {}
RRLX_API clazz::clazz(clazz &&) noexcept = default;
RRLX_API clazz &clazz::operator=(clazz&&) noexcept = default;
RRLX_API clazz::~clazz() noexcept = default;

RRLX_API void clazz::basic(int value) { return impl_->basic(value); }
inline void clazz::impl::basic(int value)
{
    basic_ = value;
}

[[nodiscard]] RRLX_API int clazz::basic() const { return impl_->basic(); }
[[nodiscard]] inline int clazz::impl::basic() const
{
    return basic_;
}

RRLX_API void clazz::array(const array_t &value) { return impl_->array(value); }
inline void clazz::impl::array(const array_t &value)
{
    array_ = value;
}

[[nodiscard]] RRLX_API const clazz::array_t &clazz::array() const { return impl_->array(); }
[[nodiscard]] inline const clazz::array_t &clazz::impl::array() const
{
    return array_;
}

RRLX_API void clazz::string(const std::string &value) { return impl_->string(value); }
inline void clazz::impl::string(const std::string &value)
{
    string_ = value;
}

[[nodiscard]] RRLX_API const std::string &clazz::string() const { return impl_->string(); }
[[nodiscard]] inline const std::string &clazz::impl::string() const
{
    return string_;
}

RRLX_API void clazz::set_callback(const callback_t &callback, void *p_user_data) { return impl_->set_callback(callback, p_user_data); }
inline void clazz::impl::set_callback(const callback_t &callback, void *p_user_data)
{
    callback_ = callback;
    p_user_data_ = p_user_data;
}

RRLX_API void clazz::invoke_callback() const { return impl_->invoke_callback(); }
inline void clazz::impl::invoke_callback() const
{
    if (callback_)
        callback_(p_user_data_);
}

}
