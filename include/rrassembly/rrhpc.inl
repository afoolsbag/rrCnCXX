/// \copyright Unlicense

#pragma once
#ifndef RRASSEMBLY_RRHCP_INL_
#define RRASSEMBLY_RRHCP_INL_

#include "rrhpc.hxx"

#include <cmath>
#include <utility>

#include "rrcpuid.hxx"

#if RRASSEMBLY_AVX_SUPPORTED
#include <immintrin.h>
#endif

namespace rrassembly {

namespace internal {

template<std::size_t pt_dim>
float euclidean_distance(const std::array<float, pt_dim> &pt1, const std::array<float, pt_dim> &pt2)
{
    float sum_of_sqr {};  // 平方和（sum of square）
    for (size_t i = 0; i < pt_dim; ++i)
        sum_of_sqr += (pt1[i] - pt2[i]) * (pt1[i] - pt2[i]);
    return std::sqrt(sum_of_sqr);
}

#if RRASSEMBLY_AVX_SUPPORTED
template<std::size_t pt_dim>
float euclidean_distance_128(const std::array<float, pt_dim> &pt1, const std::array<float, pt_dim> &pt2)
{
    float sum_of_sqr {};
    constexpr size_t step_len {sizeof(__m128) / sizeof(float)};
    static_assert(pt_dim % step_len == 0);
    for (std::ptrdiff_t offset = 0; offset < static_cast<std::ptrdiff_t>(pt_dim); offset += step_len) {
        const __m128 xmm0 = _mm_loadu_ps(pt1.data() + offset);  // SSE：加载（load）未对齐（u）紧缩单精度（ps）
        const __m128 xmm1 = _mm_loadu_ps(pt2.data() + offset);
        const __m128 xmm2 = _mm_sub_ps(xmm0, xmm1);  // SSE：减（sub）紧缩单精度（ps）
        const __m128 xmm3 = _mm_dp_ps(xmm2, xmm2, 0b1111'0001);  // SSE4.1：点积（dp）紧缩单精度（ps）
        sum_of_sqr += xmm3.m128_f32[0];
    }
    return sum_of_sqr;
}
#endif

#if RRASSEMBLY_AVX2_SUPPORTED
template<std::size_t pt_dim>
float euclidean_distance_256(const std::array<float, pt_dim> &pt1, const std::array<float, pt_dim> &pt2)
{
    float sum_of_sqr {};
    constexpr size_t step_len {sizeof(__m256) / sizeof(float)};
    static_assert(pt_dim % step_len == 0);
    for (std::ptrdiff_t offset = 0; offset < static_cast<std::ptrdiff_t>(pt_dim); offset += step_len) {
        const __m256 ymm0 = _mm256_loadu_ps(pt1.data() + offset);  // AVX：加载（load）未对齐（u）紧缩单精度（ps）
        const __m256 ymm1 = _mm256_loadu_ps(pt2.data() + offset);
        const __m256 ymm2 = _mm256_sub_ps(ymm0, ymm1);  // AVX：减（sub）紧缩单精度（ps）
        const __m256 ymm3 = _mm256_dp_ps(ymm2, ymm2, 0b1111'0001);  // AVX：点积（dp）紧缩单精度（ps）
        sum_of_sqr += ymm3.m256_f32[0] + ymm3.m256_f32[4];
    }
    return sum_of_sqr;
}
#endif

}

template<std::size_t pt_dim>
float euclidean_distance(const std::array<float, pt_dim> &pt1, const std::array<float, pt_dim> &pt2)
{
#if RRASSEMBLY_AVX2_SUPPORTED
    return internal::euclidean_distance_256(std::forward<const std::array<float, pt_dim> &>(pt1), std::forward<const std::array<float, pt_dim> &>(pt2));
#elif RRASSEMBLY_AVX_SUPPORTED
    return internal::euclidean_distance_128(std::forward<const std::array<float, pt_dim> &>(pt1), std::forward<const std::array<float, pt_dim> &>(pt2));
#else
    return internal::euclidean_distance(std::forward<const std::array<float, pt_dim> &>(pt1), std::forward<const std::array<float, pt_dim> &>(pt2));
#endif
}

namespace internal {

template<std::size_t vec_dim>
float length(const std::array<float, vec_dim> &v)
{
    float sum_of_sqr {};  // 平方和（sum of square）
    for (size_t i = 0; i < vec_dim; ++i)
        sum_of_sqr += v[i] * v[i];
    return std::sqrt(sum_of_sqr);
}

#if RRASSEMBLY_AVX_SUPPORTED
template<std::size_t vec_dim>
float length_128(const std::array<float, vec_dim> &v)
{
    float sum_of_sqr {};
    constexpr size_t step_len {sizeof(__m128) / sizeof(float)};
    static_assert(vec_dim % step_len == 0);
    for (std::ptrdiff_t offset = 0; offset < static_cast<std::ptrdiff_t>(vec_dim); offset += step_len) {
        const __m128 xmm0 = _mm_loadu_ps(v.data() + offset);  // AVX：加载（load）未对齐（u）紧缩单精度（ps）
        const __m128 xmm1 = _mm_dp_ps(xmm0, xmm0, 0b1111'0001);  // AVX：点积（dp）紧缩单精度（ps）
        sum_of_sqr += xmm1.m128_f32[0];
    }
    return std::sqrt(sum_of_sqr);
}
#endif

#if RRASSEMBLY_AVX2_SUPPORTED
template<std::size_t vec_dim>
float length_256(const std::array<float, vec_dim> &v)
{
    float sum_of_sqr {};
    constexpr size_t step_len {sizeof(__m256) / sizeof(float)};
    static_assert(vec_dim % step_len == 0);
    for (std::ptrdiff_t offset = 0; offset < static_cast<std::ptrdiff_t>(vec_dim); offset += step_len) {
        const __m256 ymm0 = _mm256_loadu_ps(v.data() + offset);  // AVX：加载（load）未对齐（u）紧缩单精度（ps）
        const __m256 ymm1 = _mm256_dp_ps(ymm0, ymm0, 0b1111'0001);  // AVX：点积（dp）紧缩单精度（ps）
        sum_of_sqr += ymm1.m256_f32[0] + ymm1.m256_f32[4];
    }
    return std::sqrt(sum_of_sqr);
}
#endif

}

template<std::size_t vec_dim>
float length(const std::array<float, vec_dim> &v)
{
#if RRASSEMBLY_AVX2_SUPPORTED
    return internal::length_256(std::forward<const std::array<float, vec_dim> &>(v));
#elif RRASSEMBLY_AVX_SUPPORTED
    return internal::length_128(std::forward<const std::array<float, vec_dim> &>(v));
#else
    return internal::length(std::forward<const std::array<float, vec_dim> &>(v));
#endif
}

namespace internal {

template<std::size_t vec_dim>
float dot_product(const std::array<float, vec_dim> &v1, const std::array<float, vec_dim> &v2)
{
    float sum_of_prd {};  // 乘积和（sum of product）
    for (std::size_t i = 0; i < vec_dim; ++i)
        sum_of_prd += v1[i] * v2[i];
    return sum_of_prd;
}

#if RRASSEMBLY_AVX_SUPPORTED
template<std::size_t vec_dim>
float dot_product_128(const std::array<float, vec_dim> &v1, const std::array<float, vec_dim> &v2)
{
    float sum_of_prd {};
    // xmm2 = _mm_dp_ps(xmm0, xmm1, mask)
    //
    //         xmm0 {float float float float   mask {bit bit bit bit bit bit bit bit}
    //                (x)   (x)   (x)   (x)           :   :   :   :   :   :   :   :
    //         xmm1 {float float float float          :   :   :   :   :   :   :   :
    //                 |     |     |     |            :   :   :   :   :   :   :   :
    //               float float float float          :   :   :   :   :   :   :   :
    //                 |<4.. |<5.. |<6.. |<7..........7 ..6 ..5 ..4   :   :   :   :
    //                 '-----'-(+)-'-----'                            :   :   :   :
    //                          |                                     :   :   :   :
    //                        float                                   :   :   :   :
    //                          |                                     :   :   :   :
    //                 .-----.--'--.-----.                            :   :   :   :
    //                 |<0.. |<1.. |<2.. |<3..........................3 ..2 ..1 ..0
    //         xmm2 {float float float float
    constexpr size_t step_len {sizeof(__m128) / sizeof(float)};
    static_assert(vec_dim % step_len == 0);
    for (std::ptrdiff_t offset = 0; offset < static_cast<std::ptrdiff_t>(vec_dim); offset += step_len) {
        const __m128 xmm0 = _mm_loadu_ps(v1.data() + offset);    // 加载（load）未对齐（u）紧缩单精度（ps）
        const __m128 xmm1 = _mm_loadu_ps(v2.data() + offset);
        const __m128 xmm2 = _mm_dp_ps(xmm0, xmm1, 0b1111'0001);  // 点积（dp）紧缩单精度（ps）
        sum_of_prd += xmm2.m128_f32[0];
    }
    return sum_of_prd;
}
#endif

#if RRASSEMBLY_AVX2_SUPPORTED
template<std::size_t vec_dim>
float dot_product_256(const std::array<float, vec_dim> &v1, const std::array<float, vec_dim> &v2)
{
    float sum_of_prd {};
    // ymm2 = _mm256_dp_ps(ymm0, ymm1, mask)
    //
    //         ymm0 {float float float float float float float float}   mask {bit bit bit bit bit bit bit bit}
    //                (x)   (x)   (x)   (x)   (x)   (x)   (x)   (x)            :   :   :   :   :   :   :   :
    //         ymm1 {float float float float float float float float}          :   :   :   :   :   :   :   :
    //                 |     |     |     |     |     |     |     |             :   :   :   :   :   :   :   :
    //               float float float float float float float float           :   :   :   :   :   :   :   :
    //                 |<4.. |<5.. |<6.. |<7.. |<4.. |<5.. |<6.. |<7...........7 ..6 ..5 ..4   :   :   :   :
    //                 '-----'-(+)-'-----'     '-----'-(+)-'-----'                             :   :   :   :
    //                          |                       |                                      :   :   :   :
    //                        float                   float                                    :   :   :   :
    //                          |                       |                                      :   :   :   :
    //                 .-----.--'--.-----.     .-----.--'--.-----.                             :   :   :   :
    //                 |<0.. |<1.. |<2.. |<3.. |<0.. |<1.. |<2.. |<3...........................3 ..2 ..1 ..0
    //         ymm2 {float float float float float float float float}
    constexpr size_t step_len {sizeof(__m256) / sizeof(float)};
    static_assert(vec_dim % step_len == 0);
    for (std::ptrdiff_t offset = 0; offset < static_cast<std::ptrdiff_t>(vec_dim); offset += step_len) {
        const __m256 ymm0 = _mm256_loadu_ps(v1.data() + offset);    // 加载（load）未对齐（u）紧缩单精度（ps）
        const __m256 ymm1 = _mm256_loadu_ps(v2.data() + offset);
        const __m256 ymm2 = _mm256_dp_ps(ymm0, ymm1, 0b1111'0001);  // 点积（dp）紧缩单精度（ps）
        sum_of_prd += ymm2.m256_f32[0] + ymm2.m256_f32[4];
    }
    return sum_of_prd;
}
#endif

}

template<std::size_t vec_dim>
float dot_product(const std::array<float, vec_dim> &v1, const std::array<float, vec_dim> &v2)
{
#if RRASSEMBLY_AVX2_SUPPORTED
    return internal::dot_product_256(std::forward<const std::array<float, vec_dim> &>(v1), std::forward<const std::array<float, vec_dim> &>(v2));
#elif RRASSEMBLY_AVX_SUPPORTED
    return internal::dot_product_128(std::forward<const std::array<float, vec_dim> &>(v1), std::forward<const std::array<float, vec_dim> &>(v2));
#else
    return internal::dot_product(std::forward<const std::array<float, vec_dim> &>(v1), std::forward<const std::array<float, vec_dim> &>(v2));
#endif
}

template<std::size_t vec_dim>
float cosine_similarity(const std::array<float, vec_dim> &v1, const std::array<float, vec_dim> &v2)
{
    const float dp = dot_product(v1, v2);  // 点积（dot product）
    const float v1_len = length(v1);
    const float v2_len = length(v2);
    return dp / (v1_len * v2_len);
}

}

#endif
