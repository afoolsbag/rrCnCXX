/*===-- Message Box --------------------------------------------*- C -*-===*//**
 *
 * \file
 * \brief 消息框。
 *
 * \version 2018-07-24
 * \since 2018-07-24
 * \authors zhengrr
 * \copyright The MIT License
 *
**//*===-------------------------------------------------------------------===*/

#pragma once

#define WIN32_LEAN_AND_MEAN
#include <Windows.h>

#ifdef __cplusplus
#include <afxwin.h>

/**
 * \brief AFX 消息框：失败和最后错误。\n
 *        AFX Message Box: Failed with Last Error.
 * \param desc 操作描述。
 * \since 2018-06-25
 */
AFX_INLINE
VOID
AFXAPI
AfxMessageBoxFwLE(LPCTSTR CONST desc)
{
    CONST DWORD ec = GetLastError();
    CString text;
    text.Format(TEXT("%s failed with %lu, %s"), desc, ec, ErrorTextOf(ec));
    AfxMessageBox(text, MB_ICONWARNING);
}

/**
 * \brief AFX 消息框：期望为真。\n
 *        AFX Message Box: Expect True.
 * \param proc 处理，返回 `TRUE` 或 `FALSE`。
 * \since 2018-07-02
 */
#define AfxMessageBoxExpectTrue(proc)                                          \
    ((proc) || (AfxMessageBoxFwLE(_T(#proc)), FALSE))

/**
 * \brief 消息框：期望为假。\n
 *        AFX Message Box: Expect False.
 * \param proc 处理，返回 `TRUE` 或 `FALSE`。
 * \since 2018-07-02
 */
#define AfxMessageBoxExpectFalse(proc)                                         \
    ((proc) && (AfxMessageBoxFwLE(_T(#proc)), TRUE))

#endif
