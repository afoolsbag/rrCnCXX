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

    uuid insert_remote_item();
    remote_item &find_remote_item(const uuid &uuid);
};

}//namespace rrcxx::prototypes::igcf2

#endif//RRCXX_ORDER_HXX_
