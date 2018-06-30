//===-- Boxes Application ---------------------------------------*- C++ -*-===//
///
/// \file
/// \brief 盒子应用（类）。
///
/// \verison 2018-06-28
/// \since 2018-05-29
/// \authors zhengrr
/// \copyright The MIT License
///
//===----------------------------------------------------------------------===//

#pragma once

struct BoxesOption {
    DWORD  ServiceIpaddress = 0uL;
    UINT16 ServiceIpport = 0u;
};

/// \brief 盒子应用（类）。
class BoxesApplication: public CWinApp {

#// Constructors
public:
    BoxesApplication();
    virtual ~BoxesApplication() override;

#// Attributes
public:
    BoxesOption Option;

#// Operations
public:
    VOID ReadOptionFromProfile();
    VOID WriteOptionToProfile();

#// Overridables
public:
    virtual BOOL InitInstance() override;

#// Implementation
protected:

#// Message Handlers
protected:
};
