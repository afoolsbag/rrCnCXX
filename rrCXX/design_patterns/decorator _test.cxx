//===-- Decorator -----------------------------------------------*- C++ -*-===//
///
/// \defgroup gDecorator 修饰器
/// \ingroup gDesignPatterns
///
/// \startuml
///   interface "部件" as widget {
///     + {abstract} draw()
///   }
///   abstract "修饰器" as decorator {
///     - widget : widget &
///     + draw()
///   }
///
///   class "窗口" as window {
///     + draw()
///   }
///
///   class "边框修饰器" as border_decorator {
///     + draw()
///   }
///
///   class "滚动条修饰器" as scroll_decorator {
///     + draw()
///   }
///
///   widget <|- decorator
///   decorator o- widget
///   widget <|.d. window
///   decorator <|.d. border_decorator
///   decorator <|.d. scroll_decorator
/// \enduml
///
/// \version 2018-11-23
/// \since 2018-11-23
/// \authors zhengrr
/// \copyright Unlicense
///
//===----------------------------------------------------------------------===//

namespace rrcxx {

/// \addtogroup gDecorator
/// @{

/// @}

}//namespace rrcxx
