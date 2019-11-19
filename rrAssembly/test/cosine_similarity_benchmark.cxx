/// \copyright Unlicense

#include <iostream>
#include <random>

#include <benchmark/benchmark.h>

#include "rrassembly/rrhpc.hxx"

using namespace std;

namespace {

void cosine_similarity_benchmark(benchmark::State &state)
{
    static auto once = []() noexcept -> bool {
        const rrassembly::cpuid_report rep;
        cerr << "CPU Supports:\n";
        cerr << "  OSXSAVE:           " << rep.is_osxsave_supported() << '\n';
        cerr << "  AES:               " << rep.is_aes_supported() << '\n';
        cerr << "  FMA:               " << rep.is_fma_supported() << '\n';
        cerr << "  PCLMULQDQ:         " << rep.is_pclmulqdq_supported() << '\n';
        cerr << "  AVX:               " << rep.is_avx_supported() << '\n';
        cerr << "  AVX2:              " << rep.is_avx2_supported() << '\n';
        cerr << "  AVX-512-F:         " << rep.is_avx512_f_supported() << '\n';
        cerr << "  AVX-512-CD:        " << rep.is_avx512_cd_supported() << '\n';
        cerr << "  AVX-512-ER:        " << rep.is_avx512_er_supported() << '\n';
        cerr << "  AVX-512-PF:        " << rep.is_avx512_pf_supported() << '\n';
        cerr << "  AVX-512-VL:        " << rep.is_avx512_vl_supported() << '\n';
        cerr << "  AVX-512-DQ:        " << rep.is_avx512_dq_supported() << '\n';
        cerr << "  AVX-512-BW:        " << rep.is_avx512_bw_supported() << '\n';
        cerr << "  AVX-512-IFMA:      " << rep.is_avx512_ifma_supported() << '\n';
        cerr << "  AVX-512-VBMI:      " << rep.is_avx512_vbmi_supported() << '\n';
        cerr << "  AVX-512-4VNNIW:    " << rep.is_avx512_4vnniw_supported() << '\n';
        cerr << "  AVX-512-4FMAPS:    " << rep.is_avx512_4fmaps_supported() << '\n';
        cerr << "  AVX-512-VPOPCNTDQ: " << rep.is_avx512_vpopcntdq_supported() << '\n';
        cerr << "  AVX-512-VNNI:      " << rep.is_avx512_vnni_supported() << '\n';
        cerr << "  AVX-512-VBMI2:     " << rep.is_avx512_vbmi2_supported() << '\n';
        cerr << "  AVX-512-BITALG:    " << rep.is_avx512_bitalg_supported() << '\n';
        return true;
    }();

    random_device dev;
    default_random_engine eng {dev()};
    const uniform_real_distribution<float> dis {};

    array<float, 512> v1 {};
    for (auto &i : v1)
        i = dis(eng);
    array<float, 512> v2 {};
    for (auto &i : v2)
        i = dis(eng);

    for (auto _ : state) {
        benchmark::DoNotOptimize(rrassembly::cosine_similarity(v1, v2));
    }
}
BENCHMARK(cosine_similarity_benchmark);

}
