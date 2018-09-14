//===-- MFC Class -----------------------------------------------*- C++ -*-===//
///
/// \file
/// \brief MFC 派生类。
///
/// \sa <https://docs.microsoft.com/cpp/mfc/deriving-a-class-from-cobject>
///
/// \version 2018-09-04
/// \since 2018-06-11
/// \authors zhengrr
/// \copyright The Unlicense
///
//===----------------------------------------------------------------------===//

#pragma once

//------------------------------------------------------------------------------

///
/// \brief MFC 派生类。
/// \details 支持内存诊断管理。
///
class MfcClass: public CObject {

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
/// \brief 动态支持的 MFC 派生类。
/// \details 支持 `CObject::IsKindOf`。
///
class MfcDynamicClass: public CObject {
    DECLARE_DYNAMIC(MfcDynamicClass)

};

//------------------------------------------------------------------------------

///
/// \brief 动态创建支持的 MFC 派生类。
/// \details 支持 `CRuntimeClass::CreateObject`。
///
class MfcDynCreateClass: CObject {
    DECLARE_DYNCREATE(MfcDynCreateClass)

#// Constructors
public:
    /// \brief 无参构造函数。
    explicit MfcDynCreateClass();

};

//------------------------------------------------------------------------------

///
/// \brief 序列化支持的MFC派生类。
/// \details 支持 `CArchive::operator >>` 和 `CArchive::operator <<`。
///
class MfcSerialClass: public CObject {
    DECLARE_SERIAL(MfcSerialClass)

#// Constructors
public:
    /// \brief 无参构造函数。
    explicit MfcSerialClass();

#// Overridables
public:
    /// \brief 从存档读取该对象或将该对象写入存档。
    virtual VOID Serialize(CArchive &ar) override;

};