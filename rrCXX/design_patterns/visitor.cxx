//===-- Visitor -------------------------------------------------*- C++ -*-===//
///
/// \defgroup gVisitor 访问者
/// \ingroup gDesignPatterns
///
/// \startuml
///   interface "元素" as element {
///     + {abstract} accept(visitor)
///   }
///   class "水" as water {
///     + accept(visitor)
///   }
///   class "地" as earth {
///     + accept(visitor)
///   }
///   class "风" as wind {
///     + accept(visitor)
///   }
///   class "火" as fire {
///     + accept(visitor)
///   }
///   note bottom
///     accept(visitor) {
///         visitor.visit(*this)
///     }
///   end note
///
///   element <|.. water
///   element <|.. earth
///   element <|.. wind
///   element <|.. fire
///   
///   interface "元素访问者" as element_visitor {
///     + {abstract} visit(water)
///     + {abstract} visit(earth)
///     + {abstract} visit(wind)
///     + {abstract} visit(fire)
///   }
///   class "元素增强访问者" as element_enhance_visitor {
///     + visit(water)
///     + visit(earth)
///     + visit(wind)
///     + visit(fire)
///   }
///   class "元素削弱访问者" as element_weaken_visitor {
///     + visit(water)
///     + visit(earth)
///     + visit(wind)
///     + visit(fire)
///   }
///
///   element_visitor <|.. element_enhance_visitor
///   element_visitor <|.. element_weaken_visitor
/// \enduml
///
/// \version 2018-11-23
/// \since 2018-11-23
/// \authors zhengrr
/// \copyright Unlicense
///
//===----------------------------------------------------------------------===//

namespace rrcxx {

/// \addtogroup gVisitor
/// @{

/// @}

}//namespace rrcxx
