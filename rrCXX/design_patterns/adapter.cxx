//===-- Adapter -------------------------------------------------*- C++ -*-===//
///
/// \defgroup groupAdapter 适配器
/// \ingroup groupDesignPatterns
///
/// 将某个类的接口转换成客户端期望的另一个接口表示。适配器模式可以消除由于接口不匹配所造成的类兼容性问题。
///
/// \startuml
///   title 适配器模式（Adapter Pattern）
///
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
/// \version 2020-01-09
/// \since 2018-11-23
/// \authors zhengrr
/// \copyright Unlicense
///
//===----------------------------------------------------------------------===//

namespace rrcxx {

/// \addtogroup groupAdapter
/// @{

/// @}

}
