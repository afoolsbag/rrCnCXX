//===-- DBSCAN --------------------------------------------------*- C++ -*-===//
///
/// \defgroup groupDBSCAN 带噪声应用的基于密度的空间聚类（Density-Based Spatial Clustering of Applications with Noise）
/// \ingroup groupDataStructuresAndAlgorithms
///
/// \sa [“DBSCAN”](https://zh.wikipedia.org/wiki/DBSCAN). *Wikipedia*.
///
/// \version 2019-11-07
/// \since 2019-11-07
/// \authors zhengrr
/// \copyright Unlicense
///
//===----------------------------------------------------------------------===//

#include <cmath>
#include <array>
#include <queue>
#include <set>
#include <utility>

#include <gtest/gtest.h>

using namespace std;

namespace rrcxx {

/// \brief 点
/// \tparam dimension 维度
/// \tparam Scalar    标量存储类型
template<size_t dimension, typename Scalar = float> using point = array<Scalar, dimension>;

/// \brief 点的集合
/// \tparam dimension 维度
/// \tparam Scalar    标量存储类型
template<size_t dimension, typename Scalar = float> using point_set = set<point<dimension, Scalar>>;

/// \brief 点的聚类
/// \tparam dimension 维度
/// \tparam Scalar    标量存储类型
template<size_t dimension, typename Scalar = float> using point_cluster = point_set<dimension, Scalar>;

/// \brief 点的聚类的集合
/// \tparam dimension 维度
/// \tparam Scalar    标量存储类型
template<size_t dimension, typename Scalar = float> using point_cluster_set = set<point_cluster<dimension, Scalar>>;

/// \brief 欧几里得距离策略。
struct euclidean_distance_policy {
    /// \brief 点 `pt1` 与点 `pt2` 的欧氏距离。
    /// \warning 未考虑精度损失。
    /// \param pt1 点 1（point 1）
    /// \param pt2 点 2（point 2）
    /// \returns 距离。
    template<size_t dimension, typename Scalar = float>
    static Scalar distance(const point<dimension, Scalar> &pt1, const point<dimension, Scalar> &pt2)
    {
        Scalar sum_of_sqr {};
        for (size_t d = 0; d < dimension; ++d)
            sum_of_sqr += (pt1[d] - pt2[d]) * (pt1[d] - pt2[d]);
        return sqrt(sum_of_sqr);
    }
};

/// \brief 单位向量余弦相似性（unit vector cosine similarity）距离策略。
struct uvcs_distance_policy {
    /// \brief 点 `pt1` 与点 `pt2` 的余弦距离。
    /// \warning 未考虑精度损失。
    /// \param pt1 点 1（point 1）
    /// \param pt2 点 2（point 2）
    /// \returns 距离。
    template<size_t dimension, typename Scalar = float>
    static Scalar distance(const point<dimension, Scalar> &pt1, const point<dimension, Scalar> &pt2)
    {
        Scalar sum_of_prd {};
        for (std::size_t i = 0; i < dimension; ++i)
            sum_of_prd += pt1[i] * pt2[i];
        return sum_of_prd;
    }
};

/// \brief 邻点。
/// \details 点集 `pts` 中，与点 `pt` 距离小于 `eps` 的点的集合。
/// \param pts 点集（point set）
/// \param pt  点（point）
/// \param eps 指定距离（epsilon）
/// \returns 邻点。
template<size_t dimension, typename Scalar = float, typename DistancePolicy = euclidean_distance_policy>
point_set<dimension, Scalar> neighbors(const point_set<dimension, Scalar> &pts, const point<dimension, Scalar> &pt, Scalar eps)
{
    point_set<dimension, Scalar> neighbors;
    for (const auto &it : pts) {
        if (DistancePolicy::distance(pt, it) < eps)
            neighbors.insert(it);
    }
    return neighbors;
}

/// \brief 带噪声应用的基于密度的空间聚类（density-based spatial clustering of applications with noise）
/// \details 核心点（core point）：若一个点 p 在距离 eps 范围内至少有 min 个点（包括它自身），则称点 p 为核心点；范围内的点称为点 p 的直接可达点。\n
///          可达点：若存在一条道路 p1, p2, ..., pn，其中每个 pi+1 都是 pi 直接可达的，则称点 pn 是点 p1 的可达点。\n
///          局外点：不由任何点可达的点，称为局外点。\n
///          聚类：若点 c 是核心点，则由点 c 的所有可达点形成一个聚类。
///
/// \param pts 点集（point set）
/// \param eps 核心点范围距离（epsilon）
/// \param min 核心点范围内必须的最少的点的个数（minimum number of points）
/// \returns “噪点集－聚类集”对
template<size_t dimension, typename Scalar = float, typename DistancePolicy = euclidean_distance_policy>
pair<point_set<dimension, Scalar>, point_cluster_set<dimension, Scalar>> dbscan(const point_set<dimension, Scalar> &pts, Scalar eps, size_t min)
{
    point_set<dimension, Scalar> noises;            // 噪点集
    point_cluster_set<dimension, Scalar> clusters;  // 聚类集

    set<const point<dimension, Scalar> &> visited_mark;

    for (const auto &cur : pts) {
        // 忽略已访问的点
        if (visited_mark.count(cur))
            continue;

        // 标记当前点已访问
        visited_mark.insert(cur);

        // 找出当前点的邻点
        const auto &cur_nbs = neighbors<dimension, Scalar, DistancePolicy>(pts, cur, eps);

        // 邻点数目不足以使该点成为核心点，暂且将该点记为局外点（噪点）
        if (cur_nbs.count() < min) {
            noises.insert(cur);
            continue;
        }

        // 该点足以成为核心点，以该点为起始，遍历扩张聚类
        point_cluster<dimension, Scalar> cluster;

        // 将所有邻点列入待做列表
        queue<const point<dimension, Scalar> &> todo_list;
        for (const auto &nb : cur_nbs)
            todo_list.push(nb);

        // 遍历待做列表
        while (!todo_list.empty()) {
            // 取待做点，并将其移出列表
            const auto &todo = todo_list.front();
            todo_list.pop();

            // 若待做点是噪点，将其移至聚类
            if (noises.count(todo)) {
                noises.erase(todo);
                cluster.insert(todo);
                continue;
            }

            // 忽略已访问的点
            if (visited_mark.count(todo))
                continue;

            // 标记待做点已访问
            visited_mark.insert(todo);

            // 将待做点归入聚类
            cluster.insert(todo);

            // 找出待做点的邻点
            const auto &todo_nbs = neighbors<dimension, Scalar, DistancePolicy>(pts, todo, eps);

            // 邻点数目足以使待做点成为核心点，将邻点加入待做列表
            if (min <= todo_nbs.count())
                for (const auto &nb : todo_nbs)
                    todo_list.push(nb);
        }

        // 将聚类纳入集合
        clusters.insert(cluster);
    }

    return make_pair(noises, clusters);
}

TEST(dbscan, tfs)
{
#if 0
    point_set<2> pts;

    pts.insert(point<2>{10, 10});
    pts.insert(point<2>{10, 11});
    pts.insert(point<2>{11, 10});
    pts.insert(point<2>{11, 11});

    pts.insert(point<2>{0, 0});

    point_set<2> noises;            // 噪点集
    point_cluster_set<2> clusters;  // 聚类集
    tie(noises, clusters) = dbscan(pts, 3.0f, 3);
    cout << noises.size();
#endif
}

}
