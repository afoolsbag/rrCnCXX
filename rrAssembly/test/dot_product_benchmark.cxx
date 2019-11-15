/// \copyright Unlicense

#include <random>

#include <benchmark/benchmark.h>

#include "rrassembly/rrhpc.hxx"

using namespace std;

namespace {

void dot_product_base_benchmark(benchmark::State &state)
{
    random_device dev;
    default_random_engine eng {dev()};
    const uniform_real_distribution<float> dis {};

    array<float, 512> v1 {};
    for (auto &i : v1)
        i = dis(eng);
    array<float, 512> v2 {};
    for (auto &i : v2)
        i = dis(eng);

    volatile float r {};
    for (auto _ : state) {
        r = rrassembly::internal::dot_product(v1, v2);
    }
}
BENCHMARK(dot_product_base_benchmark);

void dot_product_128_benchmark(benchmark::State &state)
{
    random_device dev;
    default_random_engine eng {dev()};
    const uniform_real_distribution<float> dis {};

    array<float, 512> v1 {};
    for (auto &i : v1)
        i = dis(eng);
    array<float, 512> v2 {};
    for (auto &i : v2)
        i = dis(eng);

    volatile float r {};
    for (auto _ : state) {
        r = rrassembly::internal::dot_product_128(v1, v2);
    }
}
BENCHMARK(dot_product_128_benchmark);

void dot_product_256_benchmark(benchmark::State &state)
{
    random_device dev;
    default_random_engine eng {dev()};
    const uniform_real_distribution<float> dis {};

    array<float, 512> v1 {};
    for (auto &i : v1)
        i = dis(eng);
    array<float, 512> v2 {};
    for (auto &i : v2)
        i = dis(eng);

    volatile float r {};
    for (auto _ : state) {
        r = rrassembly::internal::dot_product_256(v1, v2);
    }
}
BENCHMARK(dot_product_256_benchmark);

}
