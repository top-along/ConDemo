#include "StdAfx.h"
#include "DockableForm.h"


BEGIN_MESSAGE_MAP(CDockablePaneAsContainer, CDockablePane)
	ON_WM_SIZE()
	ON_WM_DESTROY()
END_MESSAGE_MAP()

void CDockablePaneAsContainer::OnSize(UINT nType, int cx, int cy)
{
	CDockablePane::OnSize(nType, cx, cy);

	// TODO: 在此处添加消息处理程序代码
	if (m_pDialog->GetSafeHwnd())
	{
		CRect rc;
		GetClientRect(rc);
		m_pDialog->MoveWindow(rc);
	}
}

void CDockablePaneAsContainer::OnDestroy()
{
	CDockablePane::OnDestroy();

	// TODO: 在此处添加消息处理程序代码
	m_pDialog->DestroyWindow();
}

CDockableForm::CDockableForm(UINT nIDTemplate)
	: CDialog(nIDTemplate, &m_wndPane)
	, m_wndPane(this)
{
}

BOOL CDockableForm::Create(LPCTSTR lpszCaption, CWnd *pParentWnd, const RECT &rect, BOOL bHasGripper, UINT nID, DWORD dwStyle, DWORD dwTabbedStyle, DWORD dwControlBarStyle, CCreateContext *pContext)
{
	m_wndPane.Create(lpszCaption, pParentWnd, rect, bHasGripper, nID, dwStyle, dwTabbedStyle, dwControlBarStyle, pContext);
	CDialog::Create(m_nIDHelp, &m_wndPane);
	SetParent(&m_wndPane);
	ShowWindow(SW_SHOW);
	return TRUE;
}

CDockableScrollForm::CDockableScrollForm(UINT nIDTemplate)
	: CDockableForm(nIDTemplate)
{

}

BOOL CDockableScrollForm::OnInitDialog()
{
	CDialog::OnInitDialog();
	GetWindowRect(&m_rect);
	m_nScrollPos = 0;
	return true;
}
BEGIN_MESSAGE_MAP(CDockableScrollForm, CDockableForm)
	ON_WM_SIZE()
	ON_WM_HSCROLL()
END_MESSAGE_MAP()


void CDockableScrollForm::OnSize(UINT nType, int cx, int cy)
{
	CDockableForm::OnSize(nType, cx, cy);

	// TODO: 在此处添加消息处理程序代码
	m_nCurWidth = cx;
	int nScrollMax; 
	if (cx < m_rect.Width()) 
	{ 
		nScrollMax = m_rect.Width() - cx; 
	}  
	else 
		nScrollMax = 0; 
	
	SCROLLINFO si; 
	si.cbSize = sizeof(SCROLLINFO); 
	si.fMask = SIF_ALL; // SIF_ALL = SIF_PAGE | SIF_RANGE | SIF_POS;
	si.nMin = 0;  
	si.nMax = nScrollMax; 
	si.nPage = si.nMax/10; 
	si.nPos = 0;  
	SetScrollInfo(SB_HORZ, &si, TRUE); 

}


void CDockableScrollForm::OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	int nDelta; 
	int nMaxPos = m_rect.Width() - m_nCurWidth; 
	
	switch (nSBCode) 
	{ 
	case SB_LINEDOWN: 
		if (m_nScrollPos >= nMaxPos) 
			return; 
		nDelta =  min(nMaxPos/100,nMaxPos-m_nScrollPos); 
		break; 
	
	case SB_LINEUP: 
		if (m_nScrollPos <= 0) 
			return; 
		nDelta = -min(nMaxPos/100,m_nScrollPos); 
		break; 
	
	case SB_PAGEDOWN:
		if (m_nScrollPos >= nMaxPos) 
			return; 
		nDelta =  min(nMaxPos/10,nMaxPos-m_nScrollPos); 
		break; 
	
	case SB_THUMBPOSITION: 
		nDelta = (int)nPos - m_nScrollPos; 
		break; 
	
	case SB_PAGEUP: 
		if (m_nScrollPos <= 0) 
			return; 
		nDelta = -min(nMaxPos/10,m_nScrollPos); 
		break;
	
	default: 
		return; 
	} 
	m_nScrollPos += nDelta; 
	SetScrollPos(SB_HORZ,m_nScrollPos,TRUE); 
	ScrollWindow(-nDelta, 0); 

	CDialog::OnVScroll(nSBCode, nPos, pScrollBar);

}
