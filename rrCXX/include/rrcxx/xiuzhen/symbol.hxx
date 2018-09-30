//===-- Symbol --------------------------------------------------*- C++ -*-===//
///
/// \file
/// \brief 符号。
///
/// \version 2018-09-27
/// \since 2018-09-26
/// \authors zhengrr
/// \copyright The Unlicense
///
//===----------------------------------------------------------------------===//

#pragma once
#ifndef RRCXX_SYMBOL_HXX_
#define RRCXX_SYMBOL_HXX_

#include <array>

namespace rrcxx::xiuzhen::symbol {

/// \brief 爻。
enum class yao {
    x6 = 6,  ///< 六，阴爻。
    x9 = 9   ///< 九，阳爻。
};

/// \brief 无极。
using wuji = std::array<yao, 0>;

/// \brief 两仪。
using x2yi = std::array<yao, 1>;

/// \brief 四象。
using x4xiang = std::array<yao, 2>;

/// \brief 八卦。
using x8gua = std::array<yao, 3>;

/// \brief 六十四卦。
using x64gua = std::array<yao, 6>;

/// \brief 叠加。
/// \param bottom 下（两仪）。
/// \param top    上（两仪）。
/// \returns 四象。
constexpr x4xiang operator+(const x2yi &bottom, const x2yi &top)
{
    return x4xiang {bottom[0], top[0]};
}

/// \brief 叠加。
/// \param bottom 下（四象）。
/// \param top    上（两仪）。
/// \returns 卦。
constexpr x8gua operator+(const x4xiang &bottom, const x2yi &top)
{
    return x8gua {bottom[0], bottom[1], top[0]};
}

/// \brief 叠加。
/// \param nei 内（八卦）。
/// \param wai 外（八卦）。
/// \returns 六十四卦。
constexpr x64gua operator+(const x8gua &nei, const x8gua &wai)
{
    return x64gua {nei[0], nei[1], nei[2], wai[0], wai[1], wai[2]};
}

constexpr wuji taiji {};  ///< 太极（☯）。

constexpr x2yi yin {yao::x6};   ///< 阴（⚋）。
constexpr x2yi yang {yao::x9};  ///< 阳（⚊）。

constexpr x4xiang taiyin {yin + yin};     ///< 太阴（⚏）。
constexpr x4xiang shaoyang {yin + yang};  ///< 少阳（⚎）。
constexpr x4xiang shaoyin {yang + yin};   ///< 少阴（⚍）。
constexpr x4xiang taiyang {yang + yang};  ///< 太阳（⚌）。

constexpr x8gua kun {yin + yin + yin};      ///< 坤（☷）。
constexpr x8gua gen {yin + yin + yang};     ///< 艮（☶）。
constexpr x8gua kan {yin + yang + yin};     ///< 坎（☵）。
constexpr x8gua xun {yin + yang + yang};    ///< 巽（☴）。
constexpr x8gua zhen {yang + yin + yin};    ///< 震（☳）。
constexpr x8gua li {yang + yin + yang};     ///< 离（☲）。
constexpr x8gua dui {yang + yang + yin};    ///< 兌（☱）。
constexpr x8gua qian {yang + yang + yang};  ///< 乾（☰）。

/// \brief 伏羲八卦。
/// \details 兑乾巽　☱☰☴　６７３\n
///          离　坎　☲☯☵　５　２\n
///          震坤艮　☳☷☶　４０１
constexpr std::array<x8gua, 8> fuxi8 {
    qian, dui, li, zhen, xun, kan, gen, kun
};

/// \brief 连山八卦（神农，夏易）。
/// \details 坤艮离　☷☶☲　０１５\n
///          巽　震　☴☯☳　３　４\n
///          坎兑乾　☵☱☰　２６７
constexpr std::array<x8gua, 8> lianshan8 {
    gen, kun, xun, kan, li, zhen, qian, dui
};

/// \brief 归藏八卦（轩辕，商易）。
/// \details 艮坤震　☶☷☳　１０４\n
///          坎　离　☵☯☲　２　５\n
///          巽乾兑　☴☰☱　３７６
constexpr std::array<x8gua, 8> guicang8 {
    kun, gen, kan, xun, zhen, li, dui, qian
};

/// \brief 文王八卦（姬昌，周易）。
/// \details 巽离坤　☴☲☷　３５０\n
///          震　兑　☳☯☱　４　６\n
///          艮坎乾　☶☵☰　１２７
constexpr std::array<x8gua, 8> wenwang8 {
    li, xun, zhen, gen, kun, dui, qian, kan
};

constexpr x64gua kun64 {kun + kun};       ///< 坤（䷁）。
constexpr x64gua bo {kun + gen};          ///< 剥（䷖）。
constexpr x64gua bi3 {kun + kan};         ///< 比（䷇）。
constexpr x64gua guan {kun + xun};        ///< 观（䷓）。
constexpr x64gua yu {kun + zhen};         ///< 豫（䷏）。
constexpr x64gua jin {kun + li};          ///< 晋（䷢）。
constexpr x64gua cui {kun + dui};         ///< 萃（䷬）。
constexpr x64gua pi {kun + qian};         ///< 否（䷋）。
constexpr x64gua qian1 {gen + kun};       ///< 谦（䷎）。
constexpr x64gua gen64 {gen + gen};       ///< 艮（䷳）。
constexpr x64gua jian3 {gen + kan};       ///< 蹇（䷦）。
constexpr x64gua jian4 {gen + xun};       ///< 渐（䷴）。
constexpr x64gua xiaoguo {gen + zhen};    ///< 小过（䷽）。
constexpr x64gua lvhs {gen + li};         ///< 旅（䷷），火山旅。
constexpr x64gua xian {gen + dui};        ///< 咸（䷞）。
constexpr x64gua dun {gen + qian};        ///< 遁（䷠）。
constexpr x64gua shi {kan + kun};         ///< 师（䷆）。
constexpr x64gua meng {kan + gen};        ///< 蒙（䷃）。
constexpr x64gua kan64 {kan + kan};       ///< 坎（䷜）。
constexpr x64gua huan {kan + xun};        ///< 涣（䷺）。
constexpr x64gua jie4 {kan + zhen};       ///< 解（䷧）。
constexpr x64gua weiji {kan + li};        ///< 未济（䷿）。
constexpr x64gua kun4 {kan + dui};        ///< 困（䷮）。
constexpr x64gua song {kan + qian};       ///< 讼（䷅）。
constexpr x64gua sheng {xun + kun};       ///< 升（䷭）。
constexpr x64gua gu {xun + gen};          ///< 蛊（䷑）。
constexpr x64gua jing {xun + kan};        ///< 井（䷯）。
constexpr x64gua xun64 {xun + xun};       ///< 巽（䷸）。
constexpr x64gua heng {xun + zhen};       ///< 恒（䷟）。
constexpr x64gua ding {xun + li};         ///< 鼎（䷱）。
constexpr x64gua daguo {xun + dui};       ///< 大过（䷛）。
constexpr x64gua gou {xun + qian};        ///< 姤（䷫）。
constexpr x64gua fu {zhen + kun};         ///< 复（䷗）。
constexpr x64gua yi2 {zhen + gen};        ///< 颐（䷚）。
constexpr x64gua zhun {zhen + kan};       ///< 屯（䷂）。
constexpr x64gua yi4 {zhen + xun};        ///< 益（䷩）。
constexpr x64gua zhen64 {zhen + zhen};    ///< 震（䷲）。
constexpr x64gua shihe {zhen + li};       ///< 噬嗑（䷔）。
constexpr x64gua sui {zhen + dui};        ///< 随（䷐）。
constexpr x64gua wuwang {zhen + qian};    ///< 无妄（䷘）。
constexpr x64gua mingyi {li + kun};       ///< 明夷（䷣）。
constexpr x64gua bi4 {li + gen};          ///< 贲（䷕）。
constexpr x64gua jiji {li + kan};         ///< 既济（䷾）。
constexpr x64gua jiaren {li + xun};       ///< 家人（䷤）。
constexpr x64gua feng {li + zhen};        ///< 丰（䷶）。
constexpr x64gua li64 {li + li};          ///< 离（䷝）。
constexpr x64gua ge {li + dui};           ///< 革（䷰）。
constexpr x64gua tongren {li + qian};     ///< 同人（䷌）。
constexpr x64gua lin {dui + kun};         ///< 临（䷒）。
constexpr x64gua sun {dui + gen};         ///< 损（䷨）。
constexpr x64gua jie2 {dui + kan};        ///< 节（䷻）。
constexpr x64gua zhongfu {dui + xun};     ///< 中孚（䷼）。
constexpr x64gua guimei {dui + zhen};     ///< 归妹（䷵）。
constexpr x64gua kui {dui + li};          ///< 睽（䷥）。
constexpr x64gua dui64 {dui + dui};       ///< 兑（䷹）。
constexpr x64gua lvtz {dui + qian};       ///< 履（䷉），天泽履。
constexpr x64gua tai {qian + kun};        ///< 泰（䷊）。
constexpr x64gua daxu {qian + gen};       ///< 大畜（䷙）。
constexpr x64gua xu {qian + kan};         ///< 需（䷄）。
constexpr x64gua xiaoxu {qian + xun};     ///< 小畜（䷈）。
constexpr x64gua dazhuang {qian + zhen};  ///< 大壮（䷡）。
constexpr x64gua dayou {qian + li};       ///< 大有（䷍）。
constexpr x64gua guai {qian + dui};       ///< 夬（䷪）。
constexpr x64gua qian64 {qian + qian};    ///< 乾（䷀）。

/// \brief 伏羲六十四卦。
constexpr std::array<x64gua, 64> fuxi64 {
    kun64, bo, bi3, guan, yu, jin, cui, pi,
    qian1, gen64, jian3, jian4, xiaoguo, lvhs, xian, dun,
    shi, meng, kan64, huan, jie4, weiji, kun4, song,
    sheng, gu, jing, xun64, heng, ding, daguo, gou,
    fu, yi2, zhun, yi4, zhen64, shihe, sui, wuwang,
    mingyi, bi4, jiji, jiaren, feng, li64, ge, tongren,
    lin, sun, jie2, zhongfu, guimei, kui, dui64, lvtz,
    tai, daxu, xu, xiaoxu, dazhuang, dayou, guai, qian64
};

/// \brief 文王六十四卦。
constexpr std::array<x64gua, 64> wenwang64 {
    qian64, kun64, zhun, meng, xu, song,
    shi, bi3, xiaoxu, lvtz, tai, pi,
    tongren, dayou, qian1, yu, sui, gu,
    lin, guan, shihe, bi4, bo, fu,
    wuwang, daxu, yi2, daguo, kan64, li64,
    xian, heng, dun, dazhuang, jin, mingyi,
    jiaren, kui, jian3, jie4, sun, yi4,
    guai, gou, cui, sheng, kun4, jing,
    ge, ding, zhen64, gen64, jian4, guimei,
    feng, lvhs, xun64, dui64, huan, jie2,
    zhongfu, xiaoguo, jiji, weiji
};

// alias

constexpr auto &earth {kun};
constexpr auto &mountain {gen};
constexpr auto &water {kan};
constexpr auto &wind {kun};
constexpr auto &thunder {zhen};
constexpr auto &flame {li};
constexpr auto &lake {dui};
constexpr auto &heaven {qian};

constexpr auto &field {kun64};
constexpr auto &stripping {bo};
constexpr auto &grouping {bi3};
constexpr auto &viewing {guan};
constexpr auto &providing_for {yu};
constexpr auto &prospering {jin};
constexpr auto &clustering {cui};
constexpr auto &obstruction {pi};
constexpr auto &humbling {qian1};
constexpr auto &bound {gen64};
constexpr auto &limping {jian3};
constexpr auto &infiltrating {jian4};
constexpr auto &small_exceeding {xiaoguo};
constexpr auto &sojourning {lvhs};
constexpr auto &conjoining {xian};
constexpr auto &retiring {dun};
constexpr auto &leading {shi};
constexpr auto &enveloping {meng};
constexpr auto &gorge {kan64};
constexpr auto &dispersing {huan};
constexpr auto &taking_apart {jie4};
constexpr auto &not_yet_fording {weiji};
constexpr auto &confining {kun4};
constexpr auto &arguing {song};
constexpr auto &ascending {sheng};
constexpr auto &correcting {gu};
constexpr auto &welling {jing};
constexpr auto &ground {xun64};
constexpr auto &persevering {heng};
constexpr auto &holding {ding};
constexpr auto &great_exceeding {daguo};
constexpr auto &coupling {gou};
constexpr auto &returning {fu};
constexpr auto &swallowing {yi2};
constexpr auto &sprouting {zhun};
constexpr auto &augmenting {yi4};
constexpr auto &shake {zhen64};
constexpr auto &gnawing_bite {shihe};
constexpr auto &following {sui};
constexpr auto &without_embroiling {wuwang};
constexpr auto &darkening_of_the_light {mingyi};
constexpr auto &adorning {bi4};
constexpr auto &already_fording {jiji};
constexpr auto &dwelling_people {jiaren};
constexpr auto &abounding {feng};
constexpr auto &radiance {li64};
constexpr auto &skinning {ge};
constexpr auto &concording_people {tongren};
constexpr auto &nearing {lin};
constexpr auto &diminishing {sun};
constexpr auto &articulating {jie2};
constexpr auto &center_returning {zhongfu};
constexpr auto &converting_the_maiden {guimei};
constexpr auto &polarising {kui};
constexpr auto &open {dui64};
constexpr auto &treading {lvtz};
constexpr auto &pervading {tai};
constexpr auto &great_accumulating {daxu};
constexpr auto &attending {xu};
constexpr auto &small_accumulating {xiaoxu};
constexpr auto &great_invigorating {dazhuang};
constexpr auto &great_possessing {dayou};
constexpr auto &displacement {guai};
constexpr auto &force {qian64};

}//namespace rrcxx::xiuzhen::symbol

#endif//RRCXX_SYMBOL_HXX_
