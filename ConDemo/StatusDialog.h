#pragma once
#include "DockableForm.h"
#include "afxwin.h"

// CStatusDialog �Ի���

class CStatusDialog : public CDockableForm
{
	DECLARE_DYNAMIC(CStatusDialog)

public:
	CStatusDialog(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CStatusDialog();

// �Ի�������
	enum { IDD = IDD_STATUS };



protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnSize(UINT nType, int cx, int cy);
private:
	CEdit m_editStatus;
	CStatic m_staticStatus;
};
