// StructureDialog.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "ConDemo.h"
#include "StructureDialog.h"
#include "afxdialogex.h"


// CStructureDialog �Ի���

IMPLEMENT_DYNAMIC(CStructureDialog, CDockableScrollForm)

CStructureDialog::CStructureDialog(CWnd* pParent /*=NULL*/)
	: CDockableScrollForm(CStructureDialog::IDD)
{

}

CStructureDialog::~CStructureDialog()
{
}

void CStructureDialog::DoDataExchange(CDataExchange* pDX)
{
	CDockableForm::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CStructureDialog, CDockableForm)
	ON_WM_SIZE()
	ON_WM_HSCROLL()
END_MESSAGE_MAP()


// CStructureDialog ��Ϣ�������


void CStructureDialog::OnSize(UINT nType, int cx, int cy)
{
	CDockableScrollForm::OnSize(nType, cx, cy);

	// TODO: �ڴ˴������Ϣ����������
}


void CStructureDialog::OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ

	CDockableScrollForm::OnHScroll(nSBCode, nPos, pScrollBar);
}
