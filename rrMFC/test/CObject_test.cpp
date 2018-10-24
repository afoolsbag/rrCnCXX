//===-- CObject Derived Class -----------------------------------*- C++ -*-===//
///
/// \file
/// \brief CObject 派生类。
///
/// \sa <https://docs.microsoft.com/cpp/mfc/deriving-a-class-from-cobject>
///
/// \version 2018-10-24
/// \since 2018-06-11
/// \authors zhengrr
/// \copyright The Unlicense
///
//===----------------------------------------------------------------------===//

#include <gtest/gtest.h>

///
/// \brief CObject 派生类。
/// \details 支持内存诊断管理。
///
class Clazz: public CObject {
// Overridables
public:
#ifdef _DEBUG
    /// \brief 调用以通过检查对象的内部状态在该对象上执行有效性检查。
    void AssertValid() const override
    {
        CObject::AssertValid();
        TRACE(__FUNCTION__ "\n");
    }
    /// \brief 调用以显示关于对象的诊断信息。
    void Dump(CDumpContext &dc) const override
    {
        CObject::Dump(dc);
        dc << "property a: " << 123 << "\n"
            << "property b: " << 456 << "\n";
    }
#endif
};

///
/// \brief 动态支持的 CObject 派生类。
/// \details 支持 `CObject::IsKindOf`。
///
class DynamicClazz: public CObject {
    DECLARE_DYNAMIC(DynamicClazz)
};

IMPLEMENT_DYNAMIC(DynamicClazz, CObject)

///
/// \brief 动态创建支持的 CObject 派生类。
/// \details 支持 `CRuntimeClass::CreateObject`。
///
class DynCreateClazz: CObject {
    DECLARE_DYNCREATE(DynCreateClazz)
public:
    /// \brief 无参构造函数。
    explicit DynCreateClazz() {}
};

IMPLEMENT_DYNCREATE(DynCreateClazz, CObject)

///
/// \brief 序列化支持的 CObject 派生类。
/// \details 支持 `CArchive::operator >>` 和 `CArchive::operator <<`。
///
class SerialClazz: public CObject {
    DECLARE_SERIAL(SerialClazz)
public:
    /// \brief 无参构造函数。
    explicit SerialClazz() {}
    /// \brief 从存档读取该对象或将该对象写入存档。
    void Serialize(CArchive &ar) override
    {
        if (ar.IsStoring()) {
            // storing
        } else {
            // loading
        }
    }
};

IMPLEMENT_SERIAL(SerialClazz, CObject, 0)
