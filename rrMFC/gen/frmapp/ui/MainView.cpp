/// \copyright The MIT License

#include "stdafx.h"
#include "MainView.h"

#include <conio.h>

#include "../sysmsgstr.inl"

MainView::MainView()
{
    _cputts(TEXT("MainView::Constructor\n"));
}

MainView::~MainView()
{
    _cputts(TEXT("MainView::Destructor\n"));
}

BOOL MainView::OnWndMsg(UINT message, WPARAM wParam, LPARAM lParam, LRESULT* pResult)
{
    _tcprintf_s(TEXT("MainView::OnWndMsg 0x%04X(%s), with %u, %ld, 0x%p\n"), message, SysMsgStr(message), wParam, lParam, pResult);
    return CWnd::OnWndMsg(message, wParam, lParam, pResult);
}
