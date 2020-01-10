//===-- Template Method -----------------------------------------*- C++ -*-===//
///
/// \defgroup groupTemplateMethod 模板方法
/// \ingroup groupDesignPatterns
///
/// \startuml
///   abstract "游戏" as game {
///     + {abstract} initialize_game()
///     + {abstract} make_play()
///     + {abstract} end_of_game() : bool
///     + {abstract} print_winner()
///     + play_one_game()
///   }
///   note right
///     play_one_game() {
///         initialize_game()
///         while (!end_of_game())
///             make_play()
///         print_winner()
///     }
///   end note
///
///   class "大富翁" as monopoly {
///     + initialize_game()
///     + make_play()
///     + end_of_game()
///     + print_winner()
///   }
///   class "西洋棋" as chess {
///     + initialize_game()
///     + make_play()
///     + end_of_game()
///     + print_winner()
///   }
///
///   game <|-- monopoly
///   game <|-- chess
/// \enduml
///
/// \version 2020-01-09
/// \since 2018-11-23
/// \authors zhengrr
/// \copyright Unlicense
///
//===----------------------------------------------------------------------===//

namespace rrcxx {

/// \addtogroup groupTemplateMethod
/// @{

/// @}

}
