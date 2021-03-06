/// \copyright Unlicense

#include "rrx/rrx.hxx"

#ifdef _WIN32
#include <Windows.h>
#endif

#include "cfg.hxx"

using namespace std;

#ifdef _WIN32
BOOL WINAPI DllMain(_In_ HINSTANCE hinstDLL, _In_ DWORD fdwReason, _In_ LPVOID lpvReserved)
{
    UNREFERENCED_PARAMETER(hinstDLL);
    switch (fdwReason) {
    case DLL_PROCESS_DETACH: {
        const bool is_unloading {lpvReserved == NULL};
        const bool is_terminating {lpvReserved != NULL};
        UNREFERENCED_PARAMETER(is_unloading);
        UNREFERENCED_PARAMETER(is_terminating);
        return TRUE;
    }
    case DLL_PROCESS_ATTACH: {
        const bool is_dynamic_loading {lpvReserved == NULL};
        const bool is_static_loading {lpvReserved != NULL};
        UNREFERENCED_PARAMETER(is_dynamic_loading);
        UNREFERENCED_PARAMETER(is_static_loading);
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

namespace rrx {

RRX_API version_t STDCALL version()
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

    /// \brief 基础赋值的具体实现。
    inline void basic(int value);
    /// \brief 基础取值的具体实现。
    [[nodiscard]] inline int basic() const;

    /// \brief 数组赋值的具体实现。
    void array(const array_t &value);
    /// \brief 数组取值的具体实现。
    [[nodiscard]] inline const array_t &array() const;

    /// \brief 字串赋值的具体实现。
    inline void string(const std::string &value);
    /// \brief 字串取值的具体实现。
    [[nodiscard]] inline const std::string &string() const;

    /// \brief 回调设置的具体实现。
    inline void set_callback(const callback_t &callback, void *p_user_data);
    /// \brief 回调调用的具体实现。
    inline void invoke_callback() const;

private:
    /// \brief 存储的基础数据。
    int basic_ {};
    /// \brief 存储的数组数据。
    array_t array_;
    /// \brief 存储的字串数据。
    std::string string_;
    /// \brief 存储的回调函数。
    callback_t callback_;
    /// \brief 存储的用于回调函数的用户数据指针。
    void *p_user_data_ {};
};

RRX_API clazz::clazz() : impl_ {make_unique<impl>()} {}
RRX_API clazz::clazz(clazz &&) noexcept = default;
RRX_API clazz &clazz::operator=(clazz&&) noexcept = default;
RRX_API clazz::~clazz() noexcept = default;

RRX_API void clazz::basic(int value) { return impl_->basic(value); }
inline void clazz::impl::basic(int value)
{
    basic_ = value;
}

[[nodiscard]] RRX_API int clazz::basic() const { return impl_->basic(); }
[[nodiscard]] inline int clazz::impl::basic() const
{
    return basic_;
}

RRX_API void clazz::array(const array_t &value) { return impl_->array(value); }
inline void clazz::impl::array(const array_t &value)
{
    array_ = value;
}

[[nodiscard]] RRX_API const clazz::array_t &clazz::array() const { return impl_->array(); }
[[nodiscard]] inline const clazz::array_t &clazz::impl::array() const
{
    return array_;
}

RRX_API void clazz::string(const std::string &value) { return impl_->string(value); }
inline void clazz::impl::string(const std::string &value)
{
    string_ = value;
}

[[nodiscard]] RRX_API const std::string &clazz::string() const { return impl_->string(); }
[[nodiscard]] inline const std::string &clazz::impl::string() const
{
    return string_;
}

RRX_API void clazz::set_callback(const callback_t &callback, void *p_user_data) { return impl_->set_callback(callback, p_user_data); }
inline void clazz::impl::set_callback(const callback_t &callback, void *p_user_data)
{
    callback_ = callback;
    p_user_data_ = p_user_data;
}

RRX_API void clazz::invoke_callback() const { return impl_->invoke_callback(); }
inline void clazz::impl::invoke_callback() const
{
    if (callback_)
        callback_(p_user_data_);
}

}
