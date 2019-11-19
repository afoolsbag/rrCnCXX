/// \copyright Unlicense

#include <random>

#include <benchmark/benchmark.h>

#include "rrassembly/rrhpc.hxx"

using namespace std;

namespace {

void length_base_benchmark(benchmark::State &state)
{
    random_device dev;
    default_random_engine eng {dev()};
    const uniform_real_distribution<float> dis {};

    array<float, 512> v {};
    for (auto &i : v)
        i = dis(eng);

    for (auto _ : state) {
        benchmark::DoNotOptimize(rrassembly::internal::length(v));
    }
}
BENCHMARK(length_base_benchmark);

#if RRASSEMBLY_AVX_SUPPORTED
void length_128_benchmark(benchmark::State &state)
{
    random_device dev;
    default_random_engine eng {dev()};
    const uniform_real_distribution<float> dis {};

    array<float, 512> v {};
    for (auto &i : v)
        i = dis(eng);

    for (auto _ : state) {
        benchmark::DoNotOptimize(rrassembly::internal::length_128(v));
    }
}
BENCHMARK(length_128_benchmark);
#endif

#if RRASSEMBLY_AVX2_SUPPORTED
void length_256_benchmark(benchmark::State &state)
{
    random_device dev;
    default_random_engine eng {dev()};
    const uniform_real_distribution<float> dis {};

    array<float, 512> v {};
    for (auto &i : v)
        i = dis(eng);

    for (auto _ : state) {
        benchmark::DoNotOptimize(rrassembly::internal::length_256(v));
    }
}
BENCHMARK(length_256_benchmark);
#endif

}
