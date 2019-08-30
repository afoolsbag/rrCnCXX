//===-- Circular Buffer -----------------------------------------*- C++ -*-===//
///
/// \file
/// \brief 循环缓冲区
/// \sa <https://boost.org/doc/libs/1_71_0/doc/html/circular_buffer.html>
///
/// \version 2019-08-30
/// \since 2019-08-29
/// \authors zhengrr
/// \copyright Unlicense
///
//===----------------------------------------------------------------------===//

#include <cinttypes>
#include <cstdlib>
#include <iostream>
#include <type_traits>

#include <boost/circular_buffer.hpp>
#include <gtest/gtest.h>

#define __linux__

#ifdef __linux__
#include <fcntl.h>
#include <sys/mman.h>
#include <sys/types.h>
#include <sys/stat.h>
#endif

using namespace std;

#ifdef __linux__

int get_shm_fd()
{
    constexpr char shm_name[] {"huge-memory-100GiB"};

    // 尝试严格地创建共享内存
    auto fd = shm_open(shm_name, O_CREAT | O_EXCL | O_RDWR, 0);
    long siz = 0;

    if (fd == -1) {
        // 创建失败，尝试打开共享内存
        fd = shm_open(shm_name, O_RDWR, 0);
        if (fd == -1) {
            // 打开共享内存失败，报告错误
            throw runtime_error {"create or open SHM failed"};
        }
        struct stat tmp{};
        fstat(fd, &tmp);
        siz = tmp.st_size;
    }

    // 创建失败，转而尝试打开共享内存
    ftruncate(fd, 100uLL * 1024 * 1024 * 1024);
}

template <typename T>
class custom_allocator {
    static_assert(!is_const_v<T>, "The T must be a cv-unqualified object type.");
    static_assert(!is_volatile_v<T>, "The T must be a cv-unqualified object type.");

public:
    typedef T *                  pointer;             ///< (optional)
    typedef const T *            const_pointer;       ///< (optional)
    typedef void *               void_pointer;        ///< (optional)
    typedef const void *         const_void_pointer;  ///< (optional)
    typedef T                    value_type;
    typedef size_t               size_type;           ///< (optional)
    typedef ptrdiff_t            difference_type;     ///< (optional)
    template <typename U> struct rebind { typedef custom_allocator<U> other; };  ///< (optional)
    typedef T &                  reference;           ///< (dinkumware)
    typedef const T &            const_reference;     ///< (dinkumware)

    /// \brief 分配存储。
    /// \details 分配适合 n 个 T 类型对象的存储，但不构造它们。
    /// \throws 可以抛异常。
    pointer allocate(size_type n)
    {
        if (memsiz_ < n * sizeof(value_type))
            throw bad_alloc {};
        return reinterpret_cast<pointer>(memptr_);
    }

    /// \brief 解分配存储。
    /// \details 解分配 p 所指向的存储。
    /// \param ptr 先前从对 `allocate` 的调用获得的指针，且未因中间对 `deallocate` 的调用而失效。
    /// \param n   先前传递给 `allocate` 的值。
    /// \throws 不抛异常。
    void deallocate(pointer ptr, [[maybe_unused]] size_type n) noexcept
    {
        (void)ptr;
    }

    explicit custom_allocator(void_pointer memptr, size_type memsiz) :
        memptr_ {memptr}, memsiz_ {memsiz}
    {}

private:
    const void_pointer memptr_;  ///< memory pointer
    const size_type memsiz_;     ///< memory size (in bytes)
};

#endif



namespace rrboost {

TEST(circular_buffer, gfs)
{
    auto p = make_unique<int[]>(20);
    custom_allocator<int> a_allocator {p.get(), 20};

    boost::circular_buffer<int, custom_allocator<int>> cb {3, a_allocator};
    cb.push_back(0);
    cb.push_back(1);
    cb.push_back(2);
    cb.push_back(3);
    for (const auto &i : cb) {
        cout << i << '\n';
    }
}

}
