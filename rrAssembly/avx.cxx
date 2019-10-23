//===-- Advanced Vector Extensions ------------------------------*- C++ -*-===//
///
/// \file
/// \brief 高级矢量扩展指令集
/// \sa [Introduction to Intel® Advanced Vector Extensions](https://software.intel.com/articles/introduction-to-intel-advanced-vector-extensions/)
/// \sa [Intel® Intrinsics Guide](https://software.intel.com/sites/landingpage/IntrinsicsGuide/)
///
/// \version 2019-10-18
/// \since 2019-10-15
/// \authors zhengrr
/// \copyright Unlicense
///
//===----------------------------------------------------------------------===//

#include <array>
#include <iostream>

#include <benchmark/benchmark.h>

#ifdef __AVX__
#include <immintrin.h>  // AVX
#endif

#include "rrcpuid.hxx"

using namespace std;

namespace rrassembly {

void show_cpu_supported()
{
    const cpuid_report rep;
    cout << "OSXSAVE:           " << rep.is_osxsave_supported() << '\n';
    cout << "AES:               " << rep.is_aes_supported() << '\n';
    cout << "FMA:               " << rep.is_fma_supported() << '\n';
    cout << "PCLMULQDQ:         " << rep.is_pclmulqdq_supported() << '\n';
    cout << "AVX:               " << rep.is_avx_supported() << '\n';
    cout << "AVX2:              " << rep.is_avx2_supported() << '\n';
    cout << "AVX-512-F:         " << rep.is_avx512_f_supported() << '\n';
    cout << "AVX-512-CD:        " << rep.is_avx512_cd_supported() << '\n';
    cout << "AVX-512-ER:        " << rep.is_avx512_er_supported() << '\n';
    cout << "AVX-512-PF:        " << rep.is_avx512_pf_supported() << '\n';
    cout << "AVX-512-VL:        " << rep.is_avx512_vl_supported() << '\n';
    cout << "AVX-512-DQ:        " << rep.is_avx512_dq_supported() << '\n';
    cout << "AVX-512-BW:        " << rep.is_avx512_bw_supported() << '\n';
    cout << "AVX-512-IFMA:      " << rep.is_avx512_ifma_supported() << '\n';
    cout << "AVX-512-VBMI:      " << rep.is_avx512_vbmi_supported() << '\n';
    cout << "AVX-512-4VNNIW:    " << rep.is_avx512_4vnniw_supported() << '\n';
    cout << "AVX-512-4FMAPS:    " << rep.is_avx512_4fmaps_supported() << '\n';
    cout << "AVX-512-VPOPCNTDQ: " << rep.is_avx512_vpopcntdq_supported() << '\n';
    cout << "AVX-512-VNNI:      " << rep.is_avx512_vnni_supported() << '\n';
    cout << "AVX-512-VBMI2:     " << rep.is_avx512_vbmi2_supported() << '\n';
    cout << "AVX-512-BITALG:    " << rep.is_avx512_bitalg_supported() << '\n';
}

/// \brief 余弦相似性（cosine similarity）
/// \details 即两个向量的夹角的余弦值，取值在 [-1, 1]；同向时为 1、反向时为 -1，垂直时为 0。
///          即两向量的点积、连续除以两向量的模、得到的值。
///
/// \pre 假定 `fv1` 和 `fv2` 是单位向量。
/// \tparam fvlen 特征向量长度（feature vector length），指向量维度，或向量所含单精度浮点值的个数。
/// \param fv1 特征向量（feature vector）
/// \param fv2 特征向量（feature vector）
/// \returns 余弦距离
///
/// \note 假定 fv1 和 fv2 是单位向量，即 |fv1| 和 |fv2| 都为一，有：\n
///       cosine(fv1, fv2) = fv1 . fv2 / (|fv1| * |fv2|)\n
///                        = fv1 . fv2
template<std::size_t fvlen = 512>
double cosine_similarity(const std::array<float, fvlen> &fv1, const std::array<float, fvlen> &fv2)
{
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

    constexpr size_t steplen {8};  // 步长，指单次处理的单精度浮点值的个数，恒为 8 个（256 位）
    static_assert(fvlen % steplen == 0);

    float dp {};
#ifdef __AVX2__
    for (std::ptrdiff_t offset = 0; offset < static_cast<std::ptrdiff_t>(fvlen); offset += steplen) {
        const __m256 ymm0 = _mm256_loadu_ps(fv1.data() + offset);   // 加载（load）未对齐（u）紧缩单精度（ps）
        const __m256 ymm1 = _mm256_loadu_ps(fv2.data() + offset);
        const __m256 ymm2 = _mm256_dp_ps(ymm0, ymm1, 0b1111'0001);  // 点积（dp）紧缩单精度（ps）
        dp += ymm2.m256_f32[0] + ymm2.m256_f32[4];
    }
#endif
    return dp;
}

}

static void cosine_similarity_benchmark(benchmark::State &state)
{
    static constexpr array<float, 512> fv1 {};
    static constexpr array<float, 512> fv2 {};
    for (auto _ : state) {
        rrassembly::cosine_similarity(fv1, fv2);
    }
}
BENCHMARK(cosine_similarity_benchmark);
