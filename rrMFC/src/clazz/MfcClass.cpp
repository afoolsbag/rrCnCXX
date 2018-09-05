/// \copyright The Unlicense

#include "stdafx.h"
#include "MfcClass.h"

//------------------------------------------------------------------------------

#// Overridables

#ifdef _DEBUG

VOID MfcClass::
AssertValid() CONST
{
    CObject::AssertValid();
    ASSERT(TRUE);
}

VOID MfcClass::
Dump(CDumpContext &dc) CONST
{
    CObject::Dump(dc);
    dc << "property a: " << 123 << "\n"
        << "property b: " << 234 << "\n";
}

#endif//_DEBUG

//------------------------------------------------------------------------------

IMPLEMENT_DYNAMIC(MfcDynamicClass, CObject)

//------------------------------------------------------------------------------

IMPLEMENT_DYNCREATE(MfcDynCreateClass, CObject)

#// Constructors

MfcDynCreateClass::
MfcDynCreateClass()
{}

//------------------------------------------------------------------------------

IMPLEMENT_SERIAL(MfcSerialClass, CObject, 0)

#// Constructors

MfcSerialClass::
MfcSerialClass()
{}

#// Overridables

VOID MfcSerialClass::
Serialize(CArchive &ar)
{
    if (ar.IsStoring()) {
        // storing
    } else {
        // loading
    }
}
