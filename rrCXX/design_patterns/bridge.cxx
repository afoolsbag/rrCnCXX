//===-- Bridge --------------------------------------------------*- C++ -*-===//
///
/// \defgroup gBridge 桥接器
/// \ingroup gDesignPatterns
///
/// \startuml
///   interface "绘制器" as drawer {
///     + {abstract} draw_to_device()
///   }
///   interface "形状" as shape {
///     - drawer : drawer
///     + {abstract} draw()
///   }
///
///   class "圆形" as circle {
///     - drawer : drawing
///     + draw()
///   }
///
///   class "矩形" as rectangle {
///     - drawer : drawer
///     + draw()
///   }
///
///   class "设备 1 绘制器" as device1_drawer {
///     + draw_to_device()
///   }
///
///   class "设备 2 绘制器" as device2_drawer {
///     + draw_to_device()
///   }
///
///   shape o- drawer
///   shape <|.. circle
///   shape <|.. rectangle
///   drawing <|.. device1_drawer
///   drawing <|.. device2_drawer
/// \enduml
///
/// \version 2018-11-27
/// \since 2018-11-23
/// \authors zhengrr
/// \copyright Unlicense
///
//===----------------------------------------------------------------------===//

namespace rrcxx {

/// \addtogroup gBridge
/// @{

/// @}

}
