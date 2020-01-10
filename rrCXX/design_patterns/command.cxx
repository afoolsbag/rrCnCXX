//===-- Command -------------------------------------------------*- C++ -*-===//
///
/// \defgroup groupCommand 命令
/// \ingroup groupDesignPatterns
///
/// \startuml
///   interface "命令" as command {
///     + {abstract} execute()
///   }
///
///   class "开关" as switch {
///     - history : list<command>
///     + store_and_execute(command &)
///   }
///   class "灯" as light {
///     + turnOn()
///     + turnOff()
///   }
///   class "开灯命令" as flip_up_command {
///     - light &
///     + constructor(light &)
///     + execute()
///   }
///   class "关灯命令" as flip_down_command {
///     - light &
///     + constructor(light &)
///     + execute()
///   }
///
///   switch -> command
///   command <|.. flip_up_command
///   command <|.. flip_down_command
///   flip_up_command -> light
///   flip_down_command -> light
/// \enduml
///
/// \version 2020-01-09
/// \since 2018-11-23
/// \authors zhengrr
/// \copyright Unlicense
///
//===----------------------------------------------------------------------===//

namespace rrcxx {

/// \addtogroup groupCommand
/// @{

/// @}

}
