//===-- MFC Derived Class ---------------------------------------*- C++ -*-===//
///
/// \file
/// \brief MFC派生类。
///
/// \sa <https://docs.microsoft.com/cpp/mfc/deriving-a-class-from-cobject>
///
/// \version 2018-06-11
/// \since 2018-06-11
/// \authors zhengrr
/// \copyright The MIT License
///
//===----------------------------------------------------------------------===//

#pragma once

//------------------------------------------------------------------------------

///
/// \brief 基本的MFC派生类。
/// \details 支持内存诊断管理。
///
class BasciMfcDerivedClass: public CObject {

#// Overridables
public:
#ifdef _DEBUG
    /// \brief 调用以通过检查对象的内部状态在该对象上执行有效性检查。
    virtual VOID AssertValid() CONST override;
    /// \brief 调用以显示关于对象的诊断信息。
    virtual VOID Dump(CDumpContext &dc) CONST override;
#endif

};

//------------------------------------------------------------------------------

///
/// \brief 动态支持的MFC派生类。
/// \details 支持`CObject::IsKindOf`。
///
class DynamicMfcDerivedClass: public CObject {
    DECLARE_DYNAMIC(DynamicMfcDerivedClass)

};

//------------------------------------------------------------------------------

///
/// \brief 动态创建支持的MFC派生类。
/// \details 支持`CRuntimeClass::CreateObject`。
///
class DynCreateMfcDerivedClass: CObject {
    DECLARE_DYNCREATE(DynCreateMfcDerivedClass)

#// Constructors
public:
    /// \brief 无参构造函数。
    explicit DynCreateMfcDerivedClass();

};

//------------------------------------------------------------------------------

///
/// \brief 序列化支持的MFC派生类。
/// \details 支持`CArchive::operator >>`和`CArchive::operator <<`。
///
class SerialMfcDerivedClass: public CObject {
    DECLARE_SERIAL(SerialMfcDerivedClass)

#// Constructors
public:
    /// \brief 无参构造函数。
    explicit SerialMfcDerivedClass();

#// Overridables
public:
    /// \brief 从存档读取该对象或将该对象写入存档。
    virtual VOID Serialize(CArchive &ar) override;

};
