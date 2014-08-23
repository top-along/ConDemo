#pragma once
#include "DockableForm.h"
#include "afxwin.h"

// CStatusDialog 对话框

class CStatusDialog : public CDockableForm
{
	DECLARE_DYNAMIC(CStatusDialog)

public:
	CStatusDialog(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CStatusDialog();

// 对话框数据
	enum { IDD = IDD_STATUS };



protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnSize(UINT nType, int cx, int cy);
private:
	CEdit m_editStatus;
	CStatic m_staticStatus;
};
