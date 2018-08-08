//===-- Geometry ------------------------------------------------*- C++ -*-===//
///
/// \defgroup gGeom 几何
/// \ingroup gNumr
///
/// \version 2018-08-06
/// \since 2018-07-25
/// \authors zhengrr
/// \copyright The MIT License
///
//===----------------------------------------------------------------------===//

#pragma once
#ifndef RRCXX_GEOM_HXX_
#define RRCXX_GEOM_HXX_

#include "rrCXX/numr/gemo/c2/ApRect.hxx"
#include "rrCXX/numr/gemo/c2/BndVec.hxx"
#include "rrCXX/numr/gemo/c2/Line.hxx"
#include "rrCXX/numr/gemo/c2/LineSeg.hxx"
#include "rrCXX/numr/gemo/c2/Polygon.hxx"
#include "rrCXX/numr/gemo/c2/Pt.hxx"
#include "rrCXX/numr/gemo/c2/Ray.hxx"
#include "rrCXX/numr/gemo/c2/Vec.hxx"
#include "rrCXX/numr/gemo/nl1/Inr.hxx"
#include "rrCXX/numr/gemo/nl1/Pt.hxx"

namespace rrcxx {

/// @addtogroup gGeom
/// @{

///
/// \brief 几何。
///
namespace geom {

///
/// \brief 数轴。\n
///        Number Line 1-Dimensional.
///
namespace nl1 {
using Interval = Interval_<double>;
using Point = Point_<double>;
}//namespace nl1

///
/// \brief 平面直角坐标系。\n
///        Cartesian Coordinate System 2-Dimensional.
///
namespace c2 {
using AxisParallelRectangle = AxisParallelRectangle_<double>;
using BoundVector = BoundVector_<double>;
using Line = Line_<double>;
using LineSegment = LineSegment_<double>;
using Polygon = Polygon_<double>;
using Point = Point_<double>;
using Ray = Ray_<double>;
using Vector = Vector_<double>;
}//namespace c2

}//namespace geom

/// @}

}//namespace rrcxx

#endif//RRCXX_GEOM_HXX_
