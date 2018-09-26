//===-- Order ---------------------------------------------------*- C++ -*-===//
///
/// \file
/// \brief 订单。
///
/// \version 2018-09-21
/// \since 2018-09-21
/// \authors zhengrr
/// \copyright The Unlicense
///
//===----------------------------------------------------------------------===//

#pragma once
#ifndef RRCXX_ORDER_HXX_
#define RRCXX_ORDER_HXX_

#include <map>
#include <memory>
#include <mutex>

#include "item.hxx"
#include "process.hxx"
#include "uuid.hxx"

namespace rrcxx::prototypes::igcf2 {

///
/// \brief 订单。
///
struct order {
    /// \brief 趋势。
    enum class trend {
        run,     ///< 运行。
        pause,   ///< 暂停。
        cancel,  ///< 取消。
    };

    uuid id {};            ///< 标识符。

    bool pausing {false};  ///< 请求暂停、恢复。
    bool cancel {false};   ///< 请求取消、重试。

    std::map<uuid, std::unique_ptr<item_base>>    items;
    std::mutex                                    items_mutex;
    std::map<uuid, std::unique_ptr<process_base>> processes;
    std::mutex                                    processes_mutex;

    template<typename item_type>
    uuid insert_item(std::unique_ptr<item_type> &&derived_ptr);
    template<typename item_type>
    item_type &find_item_as_(const uuid &uuid);
};

template <typename item_type>
uuid order::insert_item(std::unique_ptr<item_type> &&derived_ptr)
{
    static_assert(std::is_base_of<item_base, item_type>::value);

    const uuid uuid {derived_ptr->id};
    auto base_ptr {std::unique_ptr<item_base>(derived_ptr.release())};
    auto pair {std::make_pair(uuid, std::move(base_ptr))};
    {
        std::lock_guard<std::mutex> lock_guard(items_mutex);
        items.insert(std::move(pair));
    }
    return uuid;
}

template <typename item_type>
item_type &order::find_item_as_(const uuid &uuid)
{
    static_assert(std::is_base_of<item_base, item_type>::value);

    const auto it {items.find(uuid)};
    if (it == items.end())
        throw std::exception("The item not found.");

    const auto &base_ptr {it->second.get()};
    if (base_ptr->type() != item_type::static_type)
        throw std::exception("The item mismatch item_type::static_type.");

    const auto derived_ptr {dynamic_cast<item_type *>(base_ptr)};
    return *derived_ptr;
}

}//namespace rrcxx::prototypes::igcf2

#endif//RRCXX_ORDER_HXX_
