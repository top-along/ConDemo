#pragma once
#include "DockableForm.h"

// CStructureDialog 对话框

class CStructureDialog : public CDockableScrollForm
{
	DECLARE_DYNAMIC(CStructureDialog)

public:
	CStructureDialog(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CStructureDialog();

// 对话框数据
	enum { IDD = IDD_STRUCTURE };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg void OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);
};
