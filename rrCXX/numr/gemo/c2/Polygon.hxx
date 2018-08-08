//===-- C2: Polygon ---------------------------------------------*- C++ -*-===//
///
/// \defgroup gC2Polygon 平面直角坐标系：多边形
/// \ingroup gGeom
///
/// \version 2018-08-08
/// \since 2018-08-08
/// \authors zhengrr
/// \copyright The MIT License
///
//===----------------------------------------------------------------------===//

#pragma once
#ifndef RRCXX_C2_POLYGON_HXX_
#define RRCXX_C2_POLYGON_HXX_

#include <array>
#include <vector>

#include "rrCXX/numr/gemo/c2/ApRect.hxx"
#include "rrCXX/numr/gemo/c2/LineSeg.hxx"
#include "rrCXX/numr/gemo/c2/Pt.hxx"

namespace rrcxx {
namespace geom {
namespace c2 {

/// @addtogroup gC2Polygon
/// @{

///
/// \brief 多边形 \f$ G \f$。
///
template<typename ScalarType>
struct Polygon_ {
    std::vector<Point_<ScalarType>> epts;  ///< 端点集。

    /// \brief 外接轴平行矩形。
    AxisParallelRectangle_<ScalarType> circumscribedAxisParallelRectangle() const
    {
        AxisParallelRectangle_<ScalarType> tmp;
        for (const auto &ept : epts) {
            tmp.xMin = std::min(ept.x, tmp.xMin);
            tmp.xMax = std::max(tmp.xMax, ept.x);
            tmp.yMin = std::min(ept.y, tmp.yMin);
            tmp.yMax = std::max(tmp.yMax, ept.y);
        }
        return tmp;
    }
};

/// \brief 是否相交 \f$ p: P \cap G \ne \emptyset \f$。
template<typename ScalarType>
inline bool Intersected(const Point_<ScalarType> p, const Polygon_<ScalarType> g)
{
    using LineSegment_ = LineSegment_<ScalarType>;
    using Point_ = Point_<ScalarType>;

    switch (g.epts.size()) {
    case 0:  // 若多边形为空：
        return false;
        break;
    case 1:  // 若多边形为点：
        return p == g.epts.front();
        break;
    case 2:  // 若多边形为线段：
        return Intersected(LineSegment_(g.epts.front(), g.epts.back()), p);
        break;
    default: {  // 三端点及以上的多边形：

        // 进行快速判定，排除明显不相交的情形：
        const auto frame = g.circumscribedAxisParallelRectangle();
        if (!Intersected(p, frame))
            return false;

        // 若通过快速判定，则进行严格判定：
        LineSegment_ sPX = (p, Point_(frame.xMax, p.y));
        size_t sPXintxns = 0;
        for (auto it = g.epts.cbegin(); it != g.epts.cend(); ++it) {
            const LineSegment_ sSide = [&]{
                if (it + 1 != g.epts.cend())
                    return LineSegment_(*it, *(it + 1));
                else
                    return LineSegment_(*it, *g.epts.cbegin());
            };

            if (!Intersected(sPX, sSide))
                continue;



        }
        if (sPXintxns % 2)
            return true;

        return false;

    } break;
    }
}

/// \brief 是否相交 \f$ p: G \cap P \ne \emptyset \f$。
template<typename ScalarType = double>
inline bool Intersected(const Polygon_<ScalarType> g, const Point_<ScalarType> p)
{
    return Intersected(p, g);
}

///
/// \brief n-边形 \f$ G_n \f$。
///
template<std::size_t N, typename ScalarType = double>
struct Ngon_ {
    std::array<Point_<ScalarType>, N> epts;
};

/// \brief 三角形 \f$ \triangle \f$。
template<typename ScalarType> using Triangle_ = Ngon_<3, ScalarType>;
/// \brief 四边形。
template<typename ScalarType> using Quadrilateral_ = Ngon_<4, ScalarType>;
/// \brief 五边形。
template<typename ScalarType> using Pentagon_ = Ngon_<5, ScalarType>;
/// \brief 六边形。
template<typename ScalarType> using Hexagon_ = Ngon_<6, ScalarType>;
/// \brief 七边形。
template<typename ScalarType> using Heptagon_ = Ngon_<7, ScalarType>;
/// \brief 八边形。
template<typename ScalarType> using Octagon_ = Ngon_<8, ScalarType>;
/// \brief 九边形。
template<typename ScalarType> using Nonagon_ = Ngon_<9, ScalarType>;
/// \brief 十边形。
template<typename ScalarType> using Decagon_ = Ngon_<10, ScalarType>;
/// \brief 十一边形。
template<typename ScalarType> using Hendecagon_ = Ngon_<11, ScalarType>;
/// \brief 十二边形。
template<typename ScalarType> using Dodecagon_ = Ngon_<12, ScalarType>;
/// \brief 十三边形。
template<typename ScalarType> using Tridecagon_ = Ngon_<13, ScalarType>;
/// \brief 十四边形。
template<typename ScalarType> using Tetradecagon_ = Ngon_<14, ScalarType>;
/// \brief 十五边形。
template<typename ScalarType> using Pentadecagon_ = Ngon_<15, ScalarType>;
/// \brief 十六边形。
template<typename ScalarType> using Hexadecagon_ = Ngon_<16, ScalarType>;
/// \brief 十七边形。
template<typename ScalarType> using Heptadecagon_ = Ngon_<17, ScalarType>;
/// \brief 十八边形。
template<typename ScalarType> using Octadecagon_ = Ngon_<18, ScalarType>;
/// \brief 十九边形。
template<typename ScalarType> using Enneadecagon_ = Ngon_<19, ScalarType>;
/// \brief 二十边形。
template<typename ScalarType> using Icosagon_ = Ngon_<20, ScalarType>;
/// \brief 三十边形。
template<typename ScalarType> using Triacontagon_ = Ngon_<30, ScalarType>;
/// \brief 四十边形。
template<typename ScalarType> using Tetracontagon_ = Ngon_<40, ScalarType>;
/// \brief 五十边形。
template<typename ScalarType> using Pentacontagon_ = Ngon_<50, ScalarType>;
/// \brief 六十边形。
template<typename ScalarType> using Hexacontagon_ = Ngon_<60, ScalarType>;
/// \brief 七十边形。
template<typename ScalarType> using Heptacontagon_ = Ngon_<70, ScalarType>;
/// \brief 八十边形。
template<typename ScalarType> using Octacontagon_ = Ngon_<80, ScalarType>;
/// \brief 九十边形。
template<typename ScalarType> using Enneacontagon_ = Ngon_<90, ScalarType>;
/// \brief 百边形。
template<typename ScalarType> using Hectogon_ = Ngon_<100, ScalarType>;
/// \brief 万边形。
template<typename ScalarType> using Myriagon_ = Ngon_<10000, ScalarType>;

/// @}

}//namespace c2
}//namespace geom
}//namespace rrcxx

#endif//RRCXX_C2_POLYGON_HXX_
