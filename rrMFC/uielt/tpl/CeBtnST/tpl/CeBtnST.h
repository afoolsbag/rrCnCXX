//
//	Class:		CCeButtonST
//
//	Compiler:	eMbedded Visual C++
//	Tested on:	Windows CE 3.0
//
//	Version:	See GetVersionC() or GetVersionI()
//
//	Created:	17/August/2001
//	Updated:	18/December/2001
//
//	Author:		Davide Calabro'		davide_calabro@yahoo.com
//									http://www.softechsoftware.it
//
//	Note:		Code for the PreSubclassWindow and OnSetStyle functions
//				has been taken from the COddButton class
//				published by Paolo Messina and Jerzy Kaczorowski
//
//	Disclaimer
//	----------
//	THIS SOFTWARE AND THE ACCOMPANYING FILES ARE DISTRIBUTED "AS IS" AND WITHOUT
//	ANY WARRANTIES WHETHER EXPRESSED OR IMPLIED. NO REPONSIBILITIES FOR POSSIBLE
//	DAMAGES OR EVEN FUNCTIONALITY CAN BE TAKEN. THE USER MUST ASSUME THE ENTIRE
//	RISK OF USING THIS SOFTWARE.
//
//	Terms of use
//	------------
//	THIS SOFTWARE IS FREE FOR PERSONAL USE OR FREEWARE APPLICATIONS.
//	IF YOU USE THIS SOFTWARE IN COMMERCIAL OR SHAREWARE APPLICATIONS YOU
//	ARE GENTLY ASKED TO DONATE 1$ (ONE U.S. DOLLAR) TO THE AUTHOR:
//
//		Davide Calabro'
//		P.O. Box 65
//		21019 Somma Lombardo (VA)
//		Italy
//
#ifndef _CEBTNST_H_
#define _CEBTNST_H_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

// Return values
#ifndef	BTNST_OK
#define	BTNST_OK						0
#endif
#ifndef	BTNST_INVALIDRESOURCE
#define	BTNST_INVALIDRESOURCE			1
#endif
#ifndef	BTNST_FAILEDMASK
#define	BTNST_FAILEDMASK				2
#endif
#ifndef	BTNST_INVALIDINDEX
#define	BTNST_INVALIDINDEX				3
#endif
#ifndef	BTNST_INVALIDALIGN
#define	BTNST_INVALIDALIGN				4
#endif

class CCeButtonST : public CButton
{
public:
	CCeButtonST();
	virtual ~CCeButtonST();

    enum	{	ST_ALIGN_HORIZ	= 0,			// Icon/bitmap on the left, text on the right
				ST_ALIGN_VERT,					// Icon/bitmap on the top, text on the bottom
				ST_ALIGN_HORIZ_RIGHT			// Icon/bitmap on the right, text on the left
			};

	enum	{	BTNST_COLOR_BK_IN	= 0,		// Background color when mouse is INside
				BTNST_COLOR_FG_IN,				// Text color when mouse is INside
				BTNST_COLOR_BK_OUT,				// Background color when mouse is OUTside
				BTNST_COLOR_FG_OUT,				// Text color when mouse is OUTside
				BTNST_COLOR_BK_FOCUS,			// Background color when the button is focused
				BTNST_COLOR_FG_FOCUS,			// Text color when the button is focused

				BTNST_MAX_COLORS
			};

	DWORD SetDefaultColors(BOOL bRepaint = TRUE);
	DWORD SetColor(BYTE byColorIndex, COLORREF crColor, BOOL bRepaint = TRUE);
	DWORD GetColor(BYTE byColorIndex, COLORREF* crpColor);

	DWORD SetCheck(int nCheck, BOOL bRepaint = TRUE);
	int GetCheck();

	DWORD SetURL(LPCTSTR lpszURL = NULL);

	BOOL GetDefault();
	DWORD SetAlwaysTrack(BOOL bAlwaysTrack = TRUE);

	DWORD SetBtnCursor(int nCursorId = NULL, BOOL bRepaint = TRUE);

	DWORD SetFlat(BOOL bFlat = TRUE, BOOL bRepaint = TRUE);
	DWORD SetAlign(BYTE byAlign, BOOL bRepaint = TRUE);

	DWORD DrawBorder(BOOL bDrawBorder = TRUE, BOOL bRepaint = TRUE);
	DWORD DrawFlatFocus(BOOL bDrawFlatFocus, BOOL bRepaint = TRUE);

	DWORD SetIcon(int nIconIn, CSize sizeIn = CSize(32,32), int nIconOut = NULL, CSize sizeOut = CSize(32,32), int nIconDis = NULL, CSize sizeDis = CSize(32,32));
	DWORD SetIcon(HICON hIconIn, CSize sizeIn = CSize(32,32), HICON hIconOut = NULL, CSize sizeOut = CSize(32,32), HICON hIconDis = NULL, CSize sizeDis = CSize(32,32));

	DWORD SetMenu(UINT nMenu, HWND hParentWnd, BOOL bRepaint = TRUE);

	static short GetVersionI()		{return 12;}
	static LPCTSTR GetVersionC()	{return (LPCTSTR)_T("1.2");}

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCeButtonST)
	protected:
	virtual void PreSubclassWindow();
	virtual LRESULT DefWindowProc(UINT message, WPARAM wParam, LPARAM lParam);
	//}}AFX_VIRTUAL

	// Generated message map functions
protected:
	//{{AFX_MSG(CCeButtonST)
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg BOOL OnClicked();
	afx_msg void OnEnable(BOOL bEnable);
	afx_msg UINT OnGetDlgCode();
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	afx_msg void OnDestroy();
	afx_msg void OnKillFocus(CWnd* pNewWnd);
	afx_msg void OnActivate(UINT nState, CWnd* pWndOther, BOOL bMinimized);
	afx_msg void OnCancelMode();
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	//}}AFX_MSG
	afx_msg BOOL OnSetCursor(CWnd* pWnd, UINT nHitTest, UINT message);

	virtual DWORD OnDrawBorder(CDC* pDC, LPCRECT pRect);
	virtual DWORD OnDrawBackground(CDC* pDC, LPCRECT pRect);

	BOOL		m_bIsFlat;			// Is a flat button?
	BOOL		m_bMouseOnButton;	// Is mouse over the button?
	BOOL		m_bIsPressed;		// Is button pressed?
	BOOL		m_bIsFocused;		// Is button focused?
	BOOL		m_bIsDisabled;		// Is button disabled?
	BOOL		m_bIsDefault;		// Is default button?
	BOOL		m_bIsCheckBox;		// Is the button a checkbox?
	BYTE		m_byAlign;			// Align mode
	BOOL		m_bDrawBorder;		// Draw border?
	BOOL		m_bDrawFlatFocus;	// Draw focus rectangle for flat button?
	COLORREF	m_crColors[BTNST_MAX_COLORS];	// Colors to be used
	HMENU		m_hMenu;			// Handle to associated menu
	HWND		m_hParentWndMenu;	// Handle to window for menu selection
	BOOL		m_bMenuDisplayed;	// Is menu displayed ?

private:
	LRESULT OnMouseLeave(WPARAM wParam, LPARAM lParam);
	LRESULT OnSetStyle(WPARAM wParam, LPARAM lParam);
	static void CALLBACK TimerProc(HWND hwnd, UINT uMsg, UINT idEvent, DWORD dwTime);

	void CancelHover();
	void FreeResources(BOOL bCheckForNULL = TRUE);
	virtual void DrawItem(LPDRAWITEMSTRUCT lpDIS);
	void PrepareImageRect(BOOL bHasTitle, RECT* rpItem, CRect* rpTitle, BOOL bIsPressed, DWORD dwWidth, DWORD dwHeight, CRect* rpImage);
	void DrawTheIcon(CDC* pDC, BOOL bHasTitle, RECT* rpItem, CRect* rpTitle, BOOL bIsPressed, BOOL bIsDisabled);

#pragma pack(1)
	typedef struct _STRUCT_ICONS
	{
		HICON		hIcon;			// Handle to icon
		DWORD		dwWidth;		// Width of icon
		DWORD		dwHeight;		// Height of icon
	} STRUCT_ICONS;
#pragma pack()

	STRUCT_ICONS	m_csIcons[3];

	HCURSOR		m_hCursor;			// Handle to cursor
	HCURSOR		m_hOldCursor;		// Handle to old cursor

	BOOL		m_bAlwaysTrack;		// Always hilight button?
	int			m_nCheck;			// Current value for checkbox
	UINT		m_nTypeStyle;		// Button style
	UINT		m_nTimerId;			// Timer ID used for mouse-leave

	TCHAR		m_szURL[_MAX_PATH];	// URL to open when clicked

	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif 
