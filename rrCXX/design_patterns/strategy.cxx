//===-- Strategy ------------------------------------------------*- C++ -*-===//
///
/// \defgroup groupStrategy 策略
/// \ingroup groupDesignPatterns
///
/// \startuml
///   class "内容" as context {
///     - strategy : strategy &
///     + operation()
///   }
///   interface "策略" as strategy {
///     + {abstract} algorithm()
///   }
///
///   class "策略 1" as strategy1 {
///     + algorithm()
///   }
///   class "策略 2" as strategy2 {
///     + algorithm()
///   }
///   class "策略 3" as strategy3 {
///     + algorithm()
///   }
///
///   context *-> strategy
///   strategy <|.. strategy1
///   strategy <|.. strategy2
///   strategy <|.. strategy3
/// \enduml
///
/// \version 2020-01-09
/// \since 2018-11-23
/// \authors zhengrr
/// \copyright Unlicense
///
//===----------------------------------------------------------------------===//

namespace rrcxx {

/// \addtogroup groupStrategy
/// @{

/// @}

}
