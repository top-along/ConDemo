// StatusDialog.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "ConDemo.h"
#include "StatusDialog.h"
#include "afxdialogex.h"


// CStatusDialog �Ի���

IMPLEMENT_DYNAMIC(CStatusDialog, CDockableForm)

CStatusDialog::CStatusDialog(CWnd* pParent /*=NULL*/)
	: CDockableForm(CStatusDialog::IDD)
{

}

CStatusDialog::~CStatusDialog()
{
}

void CStatusDialog::DoDataExchange(CDataExchange* pDX)
{
	CDockableForm::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT_STATUS, m_editStatus);
	DDX_Control(pDX, IDC_STATIC_STATUS, m_staticStatus);
}


BEGIN_MESSAGE_MAP(CStatusDialog, CDockableForm)
	ON_WM_SIZE()
END_MESSAGE_MAP()


// CStatusDialog ��Ϣ�������


void CStatusDialog::OnSize(UINT nType, int cx, int cy)
{
	CDockableForm::OnSize(nType, cx, cy);

	// TODO: �ڴ˴������Ϣ����������
	if (m_editStatus.GetSafeHwnd() && m_staticStatus.GetSafeHwnd())
	{
		CRect rc;
		rc.left += 10; rc.right -= 10; rc.top += 20; rc.bottom -= 10;
		GetClientRect(rc);
		m_staticStatus.MoveWindow(rc);
		rc.left += 10; rc.right -= 10; rc.top += 20; rc.bottom -= 10;
		m_editStatus.MoveWindow(rc);
	};
}
