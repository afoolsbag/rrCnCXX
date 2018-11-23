//===-- Flyweight -----------------------------------------------*- C++ -*-===//
///
/// \defgroup gFlyweight 享元
/// \ingroup gDesignPatterns
///
/// \startuml
///   class "贴图" as map {
///     - texture : const texture &
///   }
///   class "纹理" as texture {
///     - {static} cache : map<const texture>
///     + create_texture() : const texture &
///   }
///
///   map o- texture
///   texture o- texture
/// \enduml
///
/// \version 2018-11-23
/// \since 2018-11-23
/// \authors zhengrr
/// \copyright Unlicense
///
//===----------------------------------------------------------------------===//

namespace rrcxx {

/// \addtogroup gFlyweight
/// @{

/// @}

}//namespace rrcxx
