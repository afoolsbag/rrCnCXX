//===-- Facade --------------------------------------------------*- C++ -*-===//
///
/// \defgroup gFacade 外观器
/// \ingroup gDesignPatterns
///
/// \startuml
///   class "客户方" as client
///   class "外观器" as facade {
///     + do_somthing1()
///     + do_somthing2()
///     + do_somthing3()
///   }
///   package "子系统" <<Rectangle>> {
///     class "组件 1" as module1
///     class "组件 2" as module2
///     class "组件 3" as module3
///     class "组件 4" as module4
///     class "组件 5" as module5
///   }
///   
///   client .> facade
///   facade --> module1
///   facade --> module2
///   facade --> module3
///   facade --> module4
///   facade --> module5
/// \enduml
///
/// \version 2018-11-23
/// \since 2018-11-23
/// \authors zhengrr
/// \copyright Unlicense
///
//===----------------------------------------------------------------------===//

namespace rrcxx {

/// \addtogroup gFacade
/// @{

/// @}

}
