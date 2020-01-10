//===-- Flyweight -----------------------------------------------*- C++ -*-===//
///
/// \defgroup groupFlyweight 享元
/// \ingroup groupDesignPatterns
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
/// \version 2020-01-09
/// \since 2018-11-23
/// \authors zhengrr
/// \copyright Unlicense
///
//===----------------------------------------------------------------------===//

namespace rrcxx {

/// \addtogroup groupFlyweight
/// @{

/// @}

}
