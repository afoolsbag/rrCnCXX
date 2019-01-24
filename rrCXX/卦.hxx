//===-- 卦 ------------------------------------------------------*- C++ -*-===//
///
/// \file
/// \brief 卦。
/// \details C++ 对 Unicode 标识符的支持。
///
/// \version 2019-01-24
/// \since 2018-09-26
/// \authors zhengrr
/// \copyright Unlicense
///
//===----------------------------------------------------------------------===//

#pragma once
#ifndef RRCXX_卦_HXX_
#define RRCXX_卦_HXX_

#include <array>

namespace rrcxx::卦 {

enum class 爻 { 六 = 6, 九 = 9 };

using 极 = std::array<爻, 0>;  ///< 无极、太极
using 仪 = std::array<爻, 1>;  ///< 两仪
using 象 = std::array<爻, 2>;  ///< 四象
using 经 = std::array<爻, 3>;  ///< 经卦、单挂、八卦
using 别 = std::array<爻, 6>;  ///< 别卦、重卦、六十四卦

constexpr 象 operator+(const 仪 &下, const 仪 &上) { return 象 {下[0], 上[0]}; }
constexpr 经 operator+(const 象 &下, const 仪 &上) { return 经 {下[0], 下[1], 上[0]}; }
constexpr 别 operator+(const 经 &内, const 经 &外) { return 别 {内[0], 内[1], 内[2], 外[0], 外[1], 外[2]}; }

constexpr 极 无极 {};
constexpr 极 太极 {};  ///< ☯

constexpr 仪 阴 {爻::六};  ///< ⚋
constexpr 仪 阳 {爻::九};  ///< ⚊

constexpr 象 太阴 {阴 + 阴};  ///< ⚏
constexpr 象 少阳 {阴 + 阳};  ///< ⚎
constexpr 象 少阴 {阳 + 阴};  ///< ⚍
constexpr 象 太阳 {阳 + 阳};  ///< ⚌

constexpr 经 坤 {阴 + 阴 + 阴};  ///< ☷
constexpr 经 艮 {阴 + 阴 + 阳};  ///< ☶
constexpr 经 坎 {阴 + 阳 + 阴};  ///< ☵
constexpr 经 巽 {阴 + 阳 + 阳};  ///< ☴
constexpr 经 震 {阳 + 阴 + 阴};  ///< ☳
constexpr 经 离 {阳 + 阴 + 阳};  ///< ☲
constexpr 经 兑 {阳 + 阳 + 阴};  ///< ☱
constexpr 经 乾 {阳 + 阳 + 阳};  ///< ☰

/// \brief 伏羲八卦、先天八卦
/// \details 兑乾巽　☱☰☴　６７３\n
///          离　坎　☲☯☵　５　２\n
///          震坤艮　☳☷☶　４０１
constexpr std::array<经, 8> 伏羲八卦 {乾, 兑, 离, 震, 巽, 坎, 艮, 坤};

/// \brief 连山八卦、神农八卦，夏易八卦
/// \details 坤艮离　☷☶☲　０１５\n
///          巽　震　☴☯☳　３　４\n
///          坎兑乾　☵☱☰　２６７
constexpr std::array<经, 8> 连山八卦 {艮, 坤, 巽, 坎, 离, 震, 乾, 兑};

/// \brief 归藏八卦、轩辕八卦、商易八卦
/// \details 艮坤震　☶☷☳　１０４\n
///          坎　离　☵☯☲　２　５\n
///          巽乾兑　☴☰☱　３７６
constexpr std::array<经, 8> 归藏八卦 {坤, 艮, 坎, 巽, 震, 离, 兑, 乾};

/// \brief 文王八卦、姬昌八卦、周易八卦、后天八卦
/// \details 巽离坤　☴☲☷　３５０\n
///          震　兑　☳☯☱　４　６\n
///          艮坎乾　☶☵☰　１２７
constexpr std::array<经, 8> 文王八卦 {离, 巽, 震, 艮, 坤, 兑, 乾, 坎};

constexpr 别 坤卦 {坤 + 坤};  ///< ䷁
constexpr 别 剥 {坤 + 艮};    ///< ䷖
constexpr 别 比 {坤 + 坎};    ///< ䷇
constexpr 别 观 {坤 + 巽};    ///< ䷓
constexpr 别 豫 {坤 + 震};    ///< ䷏
constexpr 别 晋 {坤 + 离};    ///< ䷢
constexpr 别 萃 {坤 + 兑};    ///< ䷬
constexpr 别 否 {坤 + 乾};    ///< ䷋
constexpr 别 谦 {艮 + 坤};    ///< ䷎
constexpr 别 艮卦 {艮 + 艮};  ///< ䷳
constexpr 别 蹇 {艮 + 坎};    ///< ䷦
constexpr 别 渐 {艮 + 巽};    ///< ䷴
constexpr 别 小过 {艮 + 震};  ///< ䷽
constexpr 别 旅 {艮 + 离};    ///< ䷷
constexpr 别 咸 {艮 + 兑};    ///< ䷞
constexpr 别 遁 {艮 + 乾};    ///< ䷠
constexpr 别 师 {坎 + 坤};    ///< ䷆
constexpr 别 蒙 {坎 + 艮};    ///< ䷃
constexpr 别 坎卦 {坎 + 坎};  ///< ䷜
constexpr 别 涣 {坎 + 巽};    ///< ䷺
constexpr 别 解 {坎 + 震};    ///< ䷧
constexpr 别 未济 {坎 + 离};  ///< ䷿
constexpr 别 困 {坎 + 兑};    ///< ䷮
constexpr 别 讼 {坎 + 乾};    ///< ䷅
constexpr 别 升 {巽 + 坤};    ///< ䷭
constexpr 别 蛊 {巽 + 艮};    ///< ䷑
constexpr 别 井 {巽 + 坎};    ///< ䷯
constexpr 别 巽卦 {巽 + 巽};  ///< ䷸
constexpr 别 恒 {巽 + 震};    ///< ䷟
constexpr 别 鼎 {巽 + 离};    ///< ䷱
constexpr 别 大过 {巽 + 兑};  ///< ䷛
constexpr 别 姤 {巽 + 乾};    ///< ䷫
constexpr 别 复 {震 + 坤};    ///< ䷗
constexpr 别 颐 {震 + 艮};    ///< ䷚
constexpr 别 屯 {震 + 坎};    ///< ䷂
constexpr 别 益 {震 + 巽};    ///< ䷩
constexpr 别 震卦 {震 + 震};  ///< ䷲
constexpr 别 噬嗑 {震 + 离};  ///< ䷔
constexpr 别 随 {震 + 兑};    ///< ䷐
constexpr 别 无妄 {震 + 乾};  ///< ䷘
constexpr 别 明夷 {离 + 坤};  ///< ䷣
constexpr 别 贲 {离 + 艮};    ///< ䷕
constexpr 别 既济 {离 + 坎};  ///< ䷾
constexpr 别 家人 {离 + 巽};  ///< ䷤
constexpr 别 丰 {离 + 震};    ///< ䷶
constexpr 别 离卦 {离 + 离};  ///< ䷝
constexpr 别 革 {离 + 兑};    ///< ䷰
constexpr 别 同人 {离 + 乾};  ///< ䷌
constexpr 别 临 {兑 + 坤};    ///< ䷒
constexpr 别 损 {兑 + 艮};    ///< ䷨
constexpr 别 节 {兑 + 坎};    ///< ䷻
constexpr 别 中孚 {兑 + 巽};  ///< ䷼
constexpr 别 归妹 {兑 + 震};  ///< ䷵
constexpr 别 睽 {兑 + 离};    ///< ䷥
constexpr 别 兑卦 {兑 + 兑};  ///< ䷹
constexpr 别 履 {兑 + 乾};    ///< ䷉
constexpr 别 泰 {乾 + 坤};    ///< ䷊
constexpr 别 大畜 {乾 + 艮};  ///< ䷙
constexpr 别 需 {乾 + 坎};    ///< ䷄
constexpr 别 小畜 {乾 + 巽};  ///< ䷈
constexpr 别 大壮 {乾 + 震};  ///< ䷡
constexpr 别 大有 {乾 + 离};  ///< ䷍
constexpr 别 夬 {乾 + 兑};    ///< ䷪
constexpr 别 乾卦 {乾 + 乾};  ///< ䷀

/// \brief 伏羲六十四卦、先天六十四卦
constexpr std::array<别, 64> 先天六十四卦 {
    坤卦, 剥, 比, 观, 豫, 晋, 萃, 否,
    谦, 艮卦, 蹇, 渐, 小过, 旅, 咸, 遁,
    师, 蒙, 坎卦, 涣, 解, 未济, 困, 讼,
    升, 蛊, 井, 巽卦, 恒, 鼎, 大过, 姤,
    复, 颐, 屯, 益, 震卦, 噬嗑, 随, 无妄,
    明夷, 贲, 既济, 家人, 丰, 离卦, 革, 同人,
    临, 损, 节, 中孚, 归妹, 睽, 兑卦, 履,
    泰, 大畜, 需, 小畜, 大壮, 大有, 夬, 乾卦
};

/// \brief 文王六十四卦、后天六十四卦
constexpr std::array<别, 64> 后天六十四卦 {
    乾卦, 坤卦, 屯, 蒙, 需, 讼,
    师, 比, 小畜, 履, 泰, 否,
    同人, 大有, 谦, 豫, 随, 蛊,
    临, 观, 噬嗑, 贲, 剥, 复,
    无妄, 大畜, 颐, 大过, 坎卦, 离卦,
    咸, 恒, 遁, 大壮, 晋, 明夷,
    家人, 睽, 蹇, 解, 损, 益,
    夬, 姤, 萃, 升, 困, 井,
    革, 鼎, 震卦, 艮卦, 渐, 归妹,
    丰, 旅, 巽卦, 兑卦, 涣, 节,
    中孚, 小过, 既济, 未济
};

}//namespace rrcxx::卦

#endif//RRCXX_卦_HXX_
