//===-- Chain of Responsibility ---------------------------------*- C++ -*-===//
///
/// \defgroup groupChainOfResponsibility 责任链
/// \ingroup groupDesignPatterns
///
/// \startuml
///   abstract logger {
///     + next : logger
///     + {abstract} message()
///   }
///   class cmd_logger {
///     + next : logger
///     + message()
///   }
///   class txt_logger {
///     + next : logger
///     + message()
///   }
///   class net_logger {
///     + next : logger
///     + message()
///   }
///
///   logger -> logger
///   logger <|-- cmd_logger
///   logger <|-- txt_logger
///   logger <|-- net_logger
/// \enduml
///
/// \version 2020-01-09
/// \since 2018-11-23
/// \authors zhengrr
/// \copyright Unlicense
///
//===----------------------------------------------------------------------===//

namespace rrcxx {

/// \addtogroup groupChainOfResponsibility
/// @{

/// @}

}
