/// \copyright Unlicense

#include <random>

#include <benchmark/benchmark.h>

#include "rrassembly/rrhpc.hxx"

using namespace std;

namespace {

void euclidean_distance_base_benchmark(benchmark::State &state)
{
    random_device dev;
    default_random_engine eng {dev()};
    const uniform_real_distribution<float> dis {};

    array<float, 512> pt1 {};
    for (auto &i : pt1)
        i = dis(eng);
    array<float, 512> pt2 {};
    for (auto &i : pt2)
        i = dis(eng);

    volatile float r {};
    for (auto _ : state) {
        r = rrassembly::internal::euclidean_distance(pt1, pt2);
    }
}
BENCHMARK(euclidean_distance_base_benchmark);

void euclidean_distance_128_benchmark(benchmark::State &state)
{
    random_device dev;
    default_random_engine eng {dev()};
    const uniform_real_distribution<float> dis {};

    array<float, 512> pt1 {};
    for (auto &i : pt1)
        i = dis(eng);
    array<float, 512> pt2 {};
    for (auto &i : pt2)
        i = dis(eng);

    volatile float r {};
    for (auto _ : state) {
        r = rrassembly::internal::euclidean_distance_128(pt1, pt2);
    }
}
BENCHMARK(euclidean_distance_128_benchmark);

void euclidean_distance_256_benchmark(benchmark::State &state)
{
    random_device dev;
    default_random_engine eng {dev()};
    const uniform_real_distribution<float> dis {};

    array<float, 512> pt1 {};
    for (auto &i : pt1)
        i = dis(eng);
    array<float, 512> pt2 {};
    for (auto &i : pt2)
        i = dis(eng);

    volatile float r {};
    for (auto _ : state) {
        r = rrassembly::internal::euclidean_distance_256(pt1, pt2);
    }
}
BENCHMARK(euclidean_distance_256_benchmark);

}
