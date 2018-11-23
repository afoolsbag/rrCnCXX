//===-- Proxy ---------------------------------------------------*- C++ -*-===//
///
/// \defgroup gProxy 代理
/// \ingroup gDesignPatterns
///
/// \startuml
///   interface "图像" as image {
///     + {abstract} display()
///   }
///   class "实际图像" as real_image {
///     + load()
///     + display()
///   }
///   class "代理图像" as proxy_image {
///     + display()
///   }
///
///   image <|.. real_image
///   image <|.. proxy_image
///   proxy_image -> real_image
/// \enduml
///
/// \version 2018-11-23
/// \since 2018-11-23
/// \authors zhengrr
/// \copyright Unlicense
///
//===----------------------------------------------------------------------===//

namespace rrcxx {

/// \addtogroup gProxy
/// @{

/// @}

}//namespace rrcxx
