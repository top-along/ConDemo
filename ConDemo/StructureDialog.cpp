// StructureDialog.cpp : 实现文件
//

#include "stdafx.h"
#include "ConDemo.h"
#include "StructureDialog.h"
#include "afxdialogex.h"


// CStructureDialog 对话框

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


// CStructureDialog 消息处理程序


void CStructureDialog::OnSize(UINT nType, int cx, int cy)
{
	CDockableScrollForm::OnSize(nType, cx, cy);

	// TODO: 在此处添加消息处理程序代码
}


void CStructureDialog::OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值

	CDockableScrollForm::OnHScroll(nSBCode, nPos, pScrollBar);
}
