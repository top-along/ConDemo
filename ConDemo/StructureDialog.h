#pragma once
#include "DockableForm.h"

// CStructureDialog �Ի���

class CStructureDialog : public CDockableScrollForm
{
	DECLARE_DYNAMIC(CStructureDialog)

public:
	CStructureDialog(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CStructureDialog();

// �Ի�������
	enum { IDD = IDD_STRUCTURE };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg void OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);
};
