//===-- Adapter -------------------------------------------------*- C++ -*-===//
///
/// \defgroup gAdapter 适配器
/// \ingroup gDesignPatterns
///
/// \startuml
///   package "难以变动的客户方" <<Rectangle>> {
///     class "客户方" as client
///     interface "接口 1" as interface1
///   }
///   
///   class "适配器" as adapter
///
///   package "难以变动的服务方" <<Rectangle>> {
///     interface "接口 2" as interface2
///     class "服务方" as server
///   }
///
///   client .r> interface1
///   interface1 <|.d. adapter
///   adapter .r> interface2
///   interface2 <|.d. server
/// \enduml
///
/// \version 2018-11-23
/// \since 2018-11-23
/// \authors zhengrr
/// \copyright Unlicense
///
//===----------------------------------------------------------------------===//

namespace rrcxx {

/// \addtogroup gAdapter
/// @{

/// @}

}//namespace rrcxx
