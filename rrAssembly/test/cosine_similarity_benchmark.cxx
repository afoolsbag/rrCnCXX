/// \copyright Unlicense

#include <random>

#include <benchmark/benchmark.h>

#include "rrassembly/rrhpc.hxx"

using namespace std;

namespace {

void cosine_similarity_benchmark(benchmark::State &state)
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
        r = rrassembly::cosine_similarity(v1, v2);
    }
}
BENCHMARK(cosine_similarity_benchmark);

}
