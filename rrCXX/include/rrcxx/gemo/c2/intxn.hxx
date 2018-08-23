//===-- Intersection (2C) ----------------------------------------*- C++ -*-===//
///
/// \file
/// \brief 交集（平面直角坐标系）。
///
/// \version 2018-08-09
/// \since 2018-07-25
/// \authors zhengrr
/// \copyright The MIT License
///
//===----------------------------------------------------------------------===//

#pragma once
#ifndef RRCXX_C2_INTXN_HXX_
#define RRCXX_C2_INTXN_HXX_

#include "AxisAlignedRectangle.hxx"
#include "Digon.hxx"
#include "Point.hxx"
#include "Vector.hxx"

namespace rrcxx {
namespace geom {
namespace c2 {

// Point & AxisAlignedRectangle

/// \brief 点与轴对齐矩形是否相交 \f$ p: P \cap Raa \ne \emptyset \f$。
/// \pre AxisAlignedRectangle.xMin <= AxisAlignedRectangle.xMax
/// \pre AxisAlignedRectangle.yMin <= AxisAlignedRectangle.yMax
inline bool Intersected(const Point &p, const AxisAlignedRectangle &raa)
{
    assert(raa.xMin <= raa.xMax && raa.yMin <= raa.yMax);
    return raa.xMin <= p.x && p.x <= raa.xMax && raa.yMin <= p.y && p.y <= raa.yMax;
}

/// \brief 轴对齐矩形与点是否相交 \f$ p: Raa \cap P \ne \emptyset \f$。
/// \pre AxisAlignedRectangle.xMin <= AxisAlignedRectangle.xMax
/// \pre AxisAlignedRectangle.yMin <= AxisAlignedRectangle.yMax
inline bool Intersected(const AxisAlignedRectangle &raa, const Point &p)
{
    return Intersected(p, raa);
}

// AxisAlignedRectangle & AxisAlignedRectangle

/// \brief 两轴对齐矩形是否相交 \f$ p: Raa_1 \cap Raa_2 \ne \emptyset \f$。
/// \pre AxisAlignedRectangle.xMin <= AxisAlignedRectangle.xMax
/// \pre AxisAlignedRectangle.yMin <= AxisAlignedRectangle.yMax
inline bool Intersected(const AxisAlignedRectangle &raa1, const AxisAlignedRectangle &raa2)
{
    assert(raa1.xMin <= raa1.xMax && raa1.yMin <= raa1.yMax);
    assert(raa2.xMin <= raa2.xMax && raa2.yMin <= raa2.yMax);
    return !(raa1.xMax < raa2.xMin || raa2.xMax < raa1.xMin ||
             raa1.yMax < raa2.yMin || raa2.yMax < raa1.yMin);
}

// Point & Digon

/// \brief 点与线段是否相交 \f$ p: P \cap \overline{S_{AB}} \ne \emptyset \f$。
inline bool Intersected(const Point &ptP, const Digon &segAB)
{
    // 排除特殊情形：
    if (segAB.ept1 == segAB.ept2)
        return ptP == segAB.ept1;

    // 进行快速判定：
    if (!Intersected(ptP, segAB.aabb()))
        return false;

    // 进行严格判定：
    const Vector vecAB(segAB.ept1, segAB.ept2);
    const Vector vecAP(segAB.ept1, ptP);
    // 因已通过快速判定，共线必然相交，不共线必然相离：
    return CrossProduct(vecAB, vecAP) == 0;
}

/// \brief 线段与点是否相交 \f$ p: \overline{S} \cap P \ne \emptyset \f$。
inline bool Intersected(const Digon &s, const Point &p)
{
    return Intersected(p, s);
}

// AxisAlignedRectangle & Digon

/// \brief 轴对齐矩形与线段是否相交 \f$ p: Raa_{ABCD} \cap \overline{S_{MN}} \ne \emptyset \f$。
inline bool Intersected(const AxisAlignedRectangle &raaABCD, const Digon &segMN)
{
    // 进行快速判定：
    if (!Intersected(raaABCD, segMN.aabb()))
        return false;

    // 进行严格判定：
    const Vector vecMN(segMN.ept1, segMN.ept2);
    const Vector vecMA(segMN.ept1, Point(raaABCD.xMin, raaABCD.yMin));
    const Vector vecMB(segMN.ept1, Point(raaABCD.xMin, raaABCD.yMax));
    const Vector vecMC(segMN.ept1, Point(raaABCD.xMax, raaABCD.yMin));
    const Vector vecMD(segMN.ept1, Point(raaABCD.xMax, raaABCD.yMax));
    // 因已通过快速判定，共线必然相交，同边必然相离：
    const double ref = CrossProduct(vecMN, vecMA);
    if (0 < ref) {
        if (CrossProduct(vecMN, vecMB) <= 0)
            return true;
        if (CrossProduct(vecMN, vecMC) <= 0)
            return true;
        if (CrossProduct(vecMN, vecMD) <= 0)
            return true;
        return false;
    } else if (ref < 0) {
        if (0 <= CrossProduct(vecMN, vecMB))
            return true;
        if (0 <= CrossProduct(vecMN, vecMC))
            return true;
        if (0 <= CrossProduct(vecMN, vecMD))
            return true;
        return false;
    } else /* ref == 0 */ {
        return true;
    }
}

/// \brief 线段与轴对齐矩形是否相交 \f$ p: \overline{S} \cap Raa \ne \emptyset \f$。
inline bool Intersected(const Digon &s, const AxisAlignedRectangle &raa)
{
    return Intersected(raa, s);
}

// Digon & Digon

/// \brief 两线段是否相交 \f$ p: \overline{S_{AB}} \cap \overline{S_{CD}} \ne \emptyset \f$。
/// \details 设两线段 \f$ \overline{AB} \f$ 和 \f$ \overline{CD} \f$ 交于点 \f$ X \f$，则有：
///          \f[ \left\{ \begin{align}
///            \vec{OX} &= \vec{OA} + \vec{AX}              && \vec{AX} = \lambda_{AB} \vec{AB} \\
///                     &= \vec{OA} + \lambda_{AB} \vec{AB}
///          \end{align} \right. \f]
///          \f[ \left\{ \begin{align}
///            \vec{OX} &= \vec{OC} + \vec{CX}              && \vec{CX} = \lambda_{CD} \vec{CD} \\
///                     &= \vec{OC} + \lambda_{CD} \vec{CD}
///          \end{align} \right. \f]
///          \f[ \left\{ \begin{align}
///                                            \vec{OA} + \lambda_{AB} \vec{AB} &= \vec{OC} + \lambda_{CD} \vec{CD}                                 && \times \vec{CD}              \\
///            \vec{OA} \times \vec{CD} + \lambda_{AB} \vec{AB} \times \vec{CD} &= \vec{OC} \times \vec{CD} + \lambda_{CD} \vec{CD} \times \vec{CD} && \vec{CD} \times \vec{CD} = 0 \\
///                                                                \lambda_{AB} &= \frac{ \vec{OC} \times \vec{CD} - \vec{OA} \times \vec{CD} }{ \vec{AB} \times \vec{CD} }         \\
///                                                                \lambda_{AB} &= \frac{ \vec{AC} \times \vec{CD} }{ \vec{AB} \times \vec{CD} }
///          \end{align} \right. \f]
///          \f[ \left\{ \begin{align}
///            \lambda_{CD} &= \frac{ \vec{CA} \times \vec{AB} }{ \vec{CD} \times \vec{AB} } \\
///                         &= \frac{ \vec{AB} \times \vec{CA} }{ \vec{AB} \times \vec{CD} } \\
///                         &= \frac{ \vec{AC} \times \vec{AB} }{ \vec{AB} \times \vec{CD} }
///          \end{align} \right. \f]
///          + 若 \f$ \vec{AB} × \vec{CD} \f$ 为零（两线段平行），且 \f$ \vec{AC} × \vec{CD} \f$ 和 \f$ \vec{AC} × \vec{AB} \f$ 为零（两线段共线），则通过投影判断是否相交；
///          + 若平行而不共线，则必然不相交；
///          + 若不平行，则通过判断 \f$ \lambda_{AB} \f$ 和 \f$ \lambda_{CD} \f$ 是否处于 \f$ [0, 1] \f$ 判断是否相交。
///
/// \sa <https://stackoverflow.com/questions/563198/how-do-you-detect-where-two-line-segments-intersect>
inline bool Intersected(const Digon &segAB, const Digon &segCD)
{
    // 进行快速判定：
    if (!Intersected(segAB.aabb(), segCD.aabb()))
        return false;

    // 进行严格判定：
    const Vector vecAB(segAB.ept1, segAB.ept2);
    const Vector vecAC(segAB.ept1, segCD.ept1);
    const Vector vecCD(segCD.ept1, segCD.ept2);

    const double cpABxCD = CrossProduct(vecAB, vecCD);
    const double cpACxCD = CrossProduct(vecAC, vecCD);
    const double cpACxAB = CrossProduct(vecAC, vecAB);

    if (cpABxCD == 0) {
        // 因已通过快速判定，平行且共线必然相交，平行不共线必然相离：
        return cpACxCD == 0 && cpACxAB == 0;
    } else {
        const double lambdaAB = cpACxCD / cpABxCD;
        const double lambdaCD = cpACxAB / cpABxCD;
        return 0 <= lambdaAB && lambdaAB <= 1 && 0 <= lambdaCD && lambdaCD <= 1;
    }
}

// Point & Polygon

/// \brief 点与多边形是否相交 \f$ p: P \cap G \ne \emptyset \f$。
inline bool Intersected(const Point &ptP, const Polygon &gon)
{
    // 排除特殊情形：
    switch (gon.epts.size()) {
    case 0: return false;
    case 1: return ptP == gon.epts.front();
    case 2: return Intersected(ptP, Digon(gon.epts.front(), gon.epts.back()));
    default: break;
    }

    // 进行快速判定：
    const auto frame = gon.aabb();
    if (!Intersected(ptP, frame))
        return false;

    // 进行严格判定：
    const Digon segPX(ptP, Point(frame.xMax, ptP.y));
    const Digon segPY(ptP, Point(ptP.x, frame.yMax));
    const Vector vecPX(segPX.ept1, segPX.ept2);
    const Vector vecPY(segPY.ept1, segPY.ept2);
    double xPreOrien = 0;
    double yPreOrien = 0;
    int xIntxns = 0;
    int yIntxns = 0;

    bool xPreOrienInited = false;
    bool yPreOrienInited = false;
    for (auto it = gon.epts.crbegin(); it != gon.epts.crend(); ++it) {
        const Point &ptA = (it == gon.epts.crbegin()) ? (*(gon.epts.crend() - 1)) : (*(it - 1));
        const Point &ptC = *it;
        if (!xPreOrienInited) {
            if (Intersected(segPX, ptA)) {
                if (Intersected(segPX, ptC)) {
                    // continue
                } else {
                    xPreOrien = CrossProduct(vecPX, Vector(ptP, ptC));
                    xPreOrienInited = true;
                }
            } else {
                xPreOrienInited = true;
            }
        }
        if (!yPreOrienInited) {
            if (Intersected(segPY, ptA)) {
                if (Intersected(segPY, ptC)) {
                    // continue
                } else {
                    yPreOrien = CrossProduct(vecPY, Vector(ptP, ptC));
                    yPreOrienInited = true;
                }
            } else {
                yPreOrienInited = true;
            }
        }
        if (xPreOrienInited && yPreOrienInited)
            break;
    }

    for (auto it = gon.epts.cbegin(); it != gon.epts.cend(); ++it) {
        const Point &ptA = *it;
        const Point &ptB = (it + 1 == gon.epts.cend()) ? (*gon.epts.cbegin()) : (*(it + 1));
        const Digon segAB(ptA, ptB);
        if (Intersected(ptP, segAB))
            return true;
        if (Intersected(segPX, segAB)) {
            const bool intxnPXxA = Intersected(segPX, ptA);
            const bool intxnPXxB = Intersected(segPX, ptB);
            if (!intxnPXxA && !intxnPXxB) {
                ++xIntxns;
            } else if (intxnPXxA && !intxnPXxB) {
                const double orien = CrossProduct(vecPX, Vector(ptP, ptB));
                if (0 < orien && 0 < xPreOrien || orien < 0 && xPreOrien < 0)
                    ++xIntxns;
            } else if (!intxnPXxA && intxnPXxB) {
                xPreOrien = CrossProduct(vecPX, Vector(ptP, ptA));
            }
        }
        if (Intersected(segPY, segAB)) {
            const bool intxnPYxA = Intersected(segPY, ptA);
            const bool intxnPYxB = Intersected(segPY, ptB);
            if (!intxnPYxA && !intxnPYxB) {
                ++yIntxns;
            } else if (intxnPYxA && !intxnPYxB) {
                const double orien = CrossProduct(vecPY, Vector(ptP, ptB));
                if (0 < orien && 0 < yPreOrien || orien < 0 && yPreOrien < 0)
                    ++yIntxns;
            } else if (!intxnPYxA && intxnPYxB) {
                yPreOrien = CrossProduct(vecPY, Vector(ptP, ptA));
            }
        }
    }

    return xIntxns % 2 || yIntxns % 2;
}

/// \brief 多边形与点是否相交 \f$ p: G \cap P \ne \emptyset \f$。
inline bool Intersected(const Polygon &g, const Point &p)
{
    return Intersected(p, g);
}

}//namespace c2
}//namespace geom
}//namespace rrcxx

#endif//RRCXX_C2_INTXN_HXX_
