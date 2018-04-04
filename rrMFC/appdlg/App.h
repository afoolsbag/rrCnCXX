//===-- Class Application ---------------------------------------*- C++ -*-===//
///
/// \file
/// \brief 应用类
///
/// \verison 2018-04-04
/// \since 2017-04-04
/// \authors zhengrr
/// \copyright The MIT License
///
//===----------------------------------------------------------------------===//

#pragma once

class CApp : public CWinApp
{
public:
	virtual BOOL InitInstance();

	DECLARE_MESSAGE_MAP()
};
