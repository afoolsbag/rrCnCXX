//===-- Observer ------------------------------------------------*- C++ -*-===//
///
/// \defgroup gObserver 观察者
/// \ingroup gDesignPatterns
///
/// \startuml
///   interface "观察者" as observer {
///     + {abstract} update()
///   }
///   abstract subject {
///     - observers : list<observer>
///     + {abstract} attach(observer &)
///     + {abstract} detach(observer &)
///     + {abstract} notify()
///   }
///   subject "1" o-> "*" observer : notify/update
/// \enduml
///
/// \version 2018-11-23
/// \since 2018-11-23
/// \authors zhengrr
/// \copyright Unlicense
///
//===----------------------------------------------------------------------===//

namespace rrcxx {

/// \addtogroup gObserver
/// @{

/// @}

}//namespace rrcxx
