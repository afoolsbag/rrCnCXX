//===-- Circular Buffer -----------------------------------------*- C++ -*-===//
///
/// \file
/// \brief 循环缓冲区
/// \sa <https://boost.org/doc/libs/1_71_0/doc/html/circular_buffer.html>
///
/// \version 2019-09-02
/// \since 2019-08-29
/// \authors zhengrr
/// \copyright Unlicense
///
//===----------------------------------------------------------------------===//

#include <cinttypes>
#include <cstdlib>
#include <iostream>
#include <gsl/gsl>

#include <boost/circular_buffer.hpp>
#include <boost/interprocess/managed_shared_memory.hpp>
#include <boost/interprocess/shared_memory_object.hpp>
#include <gtest/gtest.h>

using namespace std;
using namespace gsl;
namespace bip = boost::interprocess;

namespace rrboost {

//------------------------------------------------------------------------------
// VERIFICATION
constexpr uint64_t verification {201909021652};
constexpr size_t size_of_verification {sizeof(verification)};
constexpr char shm_verification_name[] {"verification"};

//------------------------------------------------------------------------------
// INFORMATION
struct information_t {
    uint64_t expired_limit;  ///< 过期限制
    time_t last_update;      ///< 最后更新时间
};
constexpr size_t size_of_information {sizeof(information_t)};
constexpr char shm_information_name[] {"information"};

//------------------------------------------------------------------------------
// CIRCULAR BUFFER
struct item_t {
    uint64_t sn;          ///< serial number  序列号
    array<float, 64> fv;  ///< feature vector 特征向量
};
constexpr size_t size_of_item {sizeof(item_t)};
using shm_item_allocator = bip::allocator<item_t, bip::managed_shared_memory::segment_manager>;

constexpr size_t limit_of_items {100};
constexpr size_t size_of_items {limit_of_items * size_of_item};
using shm_circular_buffer = boost::circular_buffer<item_t, shm_item_allocator>;
constexpr char shm_circular_buffer_name[] {"circular buffer"};

//------------------------------------------------------------------------------
// SHARED MEMORY
constexpr char shm_name[] {"100GiB"};
constexpr bip::managed_shared_memory::size_type shm_size {size_of_verification + size_of_information + size_of_items + 512uLL};

TEST(circular_buffer, save_shm)
{
    bip::shared_memory_object::remove(shm_name);

    bip::managed_shared_memory segment {bip::create_only, shm_name, shm_size};

    uint64_t *const veri = segment.construct<uint64_t>(shm_verification_name)();
    *veri = verification;

    information_t *const info = segment.construct<information_t>(shm_information_name)();
    info->expired_limit = 0;

    shm_circular_buffer *const circ = segment.construct<shm_circular_buffer>(shm_circular_buffer_name)(limit_of_items, shm_item_allocator {segment.get_segment_manager()});
    circ->push_back({0, {}});
    circ->push_back({1, {}});
    circ->push_back({2, {}});
    circ->push_back({3, {}});
}

TEST(circular_buffer, load_shm)
{
    bip::managed_shared_memory segment {bip::open_only, shm_name};

    uint64_t *const veri {segment.find<uint64_t>(shm_verification_name).first};
    ASSERT_NE(nullptr, veri);
    ASSERT_EQ(verification, *veri);

    information_t *const info {segment.find<information_t>(shm_information_name).first};
    ASSERT_NE(nullptr, info);
    ASSERT_EQ(0, info->expired_limit);

    shm_circular_buffer *const circ {segment.find<shm_circular_buffer>(shm_circular_buffer_name).first};
    ASSERT_NE(nullptr, circ);

    for (size_t i = 0; i < circ->size(); ++i)
        ASSERT_EQ((*circ)[i].sn, i);

    bip::shared_memory_object::remove(shm_name);
}

}
