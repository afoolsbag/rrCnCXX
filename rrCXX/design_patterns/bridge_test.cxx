//===-- Bridge --------------------------------------------------*- C++ -*-===//
///
/// \defgroup gBridge 桥接器
/// \ingroup gDesignPatterns
///
/// \startuml
///   interface "形状" as shape {
///     - drawer : drawing
///     + {abstract} draw()
///   }
///   interface "绘制" as drawing {
///     + {abstract} draw_to_device()
///   }
///
///   class "圆形" as circle {
///     - drawer : drawing
///     + draw()
///   }
///
///   class "矩形" as rectangle {
///     - drawer : drawing
///     + draw()
///   }
///
///   class "绘制到设备 1" as device1_drawing {
///     + draw_to_device()
///   }
///
///   class "绘制到设备 2" as device2_drawing {
///     + draw_to_device()
///   }
///
///   shape o- drawing
///   circle .r.|> shape
///   rectangle .u.|> shape
///   device1_drawing .l.|> drawing
///   device2_drawing .d.|> drawing
/// \enduml
///
/// \version 2018-11-23
/// \since 2018-11-23
/// \authors zhengrr
/// \copyright Unlicense
///
//===----------------------------------------------------------------------===//

namespace rrcxx {

/// \addtogroup gBridge
/// @{

/// @}

}//namespace rrcxx
