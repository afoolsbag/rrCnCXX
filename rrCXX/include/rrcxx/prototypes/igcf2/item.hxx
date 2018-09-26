//===-- Item ----------------------------------------------------*- C++ -*-===//
///
/// \file
/// \brief 物项。
///
/// \version 2018-09-21
/// \since 2018-09-21
/// \authors zhengrr
/// \copyright The Unlicense
///
//===----------------------------------------------------------------------===//

#pragma once
#ifndef RRCXX_ITEM_HXX_
#define RRCXX_ITEM_HXX_

#include <string>

#include "uri.hxx"
#include "uuid.hxx"

namespace rrcxx::prototypes::igcf2 {

///
/// \brief 物项基类。
///
struct item_base {
    /// \brief 物项种类。
    enum class type {
        remote,   ///< 远端的
        local,    ///< 本地的
        regular,  ///< 规则的
        labeled,  ///< 标签的
    };

    /// \brief 获取物项种类。
    virtual type type() const = 0;

    virtual ~item_base() = default;

    uuid id {};  ///< 标识符。
    url  rl;     ///< 资源定位符。
};

/// \brief 远端物项。
struct remote_item: item_base {
    static constexpr auto static_type {type::remote};

    enum class type type() const final
    {
        return static_type;
    }

    ~remote_item() final = default;

    std::string usr;  ///< 用户名。
    std::string pwd;  ///< 密码。
};

/// \brief 本地物项。
struct local_item: item_base {
    static constexpr auto static_type {type::local};

    enum class type type() const final
    {
        return static_type;
    }

    ~local_item() final = default;
};

/// \brief 规则物项。
struct regular_item: item_base {
    static constexpr auto static_type {type::regular};

    enum class type type() const final
    {
        return static_type;
    }

    ~regular_item() final = default;
};

/// \brief 标签物项。
struct labeled_item: item_base {
    static constexpr auto static_type {type::labeled};

    enum class type type() const final
    {
        return static_type;
    }

    ~labeled_item() final = default;
};

}//namespace rrcxx::prototypes::igcf2

#endif//RRCXX_ITEM_HXX_
