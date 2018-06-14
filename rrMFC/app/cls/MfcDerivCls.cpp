/// \copyright The MIT License

#include "stdafx.h"
#include "MfcDerivCls.h"

//------------------------------------------------------------------------------

#// Overridables

#ifdef _DEBUG

VOID BasciMfcDerivedClass::
AssertValid() CONST
{
    CObject::AssertValid();
    ASSERT(TRUE);
}

VOID BasciMfcDerivedClass::
Dump(CDumpContext &dc) CONST
{
    CObject::Dump(dc);
    dc << "property a: " << 123 << "\n"
        << "property b: " << 234 << "\n";
}

#endif//_DEBUG

//------------------------------------------------------------------------------

IMPLEMENT_DYNAMIC(DynamicMfcDerivedClass, CObject)

//------------------------------------------------------------------------------

IMPLEMENT_DYNCREATE(DynCreateMfcDerivedClass, CObject)

#// Constructors

DynCreateMfcDerivedClass::
DynCreateMfcDerivedClass()
{}

//------------------------------------------------------------------------------

IMPLEMENT_SERIAL(SerialMfcDerivedClass, CObject, 0)

#// Constructors

SerialMfcDerivedClass::
SerialMfcDerivedClass()
{}

#// Overridables

VOID SerialMfcDerivedClass::
Serialize(CArchive &ar)
{
    if (ar.IsStoring()) {
        // storing
    } else {
        // loading
    }
}
