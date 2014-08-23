#pragma once
#include "afxwin.h"

class CDockablePaneAsContainer : public CDockablePane
{
public:
	CDockablePaneAsContainer(CDialog* pDialog) : m_pDialog(pDialog) { }

private:
	CDialog* m_pDialog;

public:
	DECLARE_MESSAGE_MAP()
	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg void OnDestroy();
};

class CDockableForm : public CDialog
{
public:
	CDockableForm(UINT nIDTemplate);

	virtual BOOL Create(LPCTSTR lpszCaption, CWnd* pParentWnd, const RECT& rect, BOOL bHasGripper, UINT nID, DWORD dwStyle, DWORD dwTabbedStyle = AFX_CBRS_REGULAR_TABS, DWORD dwControlBarStyle = AFX_DEFAULT_DOCKING_PANE_STYLE, CCreateContext* pContext = NULL);

	CDockablePane& GetDockablePane() { return m_wndPane; }

private:
	CDockablePaneAsContainer m_wndPane;

};

class CDockableScrollForm : public CDockableForm
{
public:
	CDockableScrollForm(UINT nIDTemplate);
	virtual BOOL OnInitDialog();
	
private:
	int		m_nCurWidth;
	int		m_nScrollPos;
	CRect	m_rect;


public:
	DECLARE_MESSAGE_MAP()
	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg void OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);
};
