#pragma once
#include "DockableForm.h"
#include "resource.h"
#include "afxwin.h"
#include "afxeditbrowsectrl.h"

// CControlDialog �Ի���

class CControlDialog : public CDockableScrollForm
{
	DECLARE_DYNAMIC(CControlDialog)

public:
	CControlDialog(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CControlDialog();

// �Ի�������
	enum { IDD = IDD_CONTROL };



protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��
private:
	virtual BOOL OnInitDialog();

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg void OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);



private:
	// �����Ŀ
	int m_nNodeNum;
	// ������������ھӾ���
	int m_nRange;
	// ��ó�ʼλ�÷�ʽ
	CComboBox m_comboInitPos;
	// ��λ�ó�ʼ�ٶ�
	CComboBox m_comboInitVel;
	// ��������ṹ
	CComboBox m_comboStructure;
	// ��������ʱ��
	CComboBox m_comboTimeVaring;
	// ����
	double m_dStep;
	// ʱ���ܳ�
	int m_nTotalTime;
private:
	// �����쵼��
	CButton m_checkHasLeader;
	// ���쵼�ߵ�����������쵼��
	CEdit m_editLeaderExp;
private:
	// �򿪲��������ļ�
	CMFCEditBrowseCtrl m_browseFile;

	// ��ť
	CButton m_btnInitPara;
	CButton m_btnSavePara;
	CButton m_btnStart;
	CButton m_btnPause;
	CBitmapButton m_btnStop;

	
public:
	afx_msg void OnBnClickedCheckHasLeader();
};

void InitCombo(CComboBox& combo, const CString* pStr, const int len);


const CString InitPos[2]	= {_T("���ȷֲ�"), _T("�ֶ�����")};
const CString InitVel[2]	= {_T("���ȷֲ�"), _T("��̬�ֲ�")};
const CString Structure[2]	= {_T("Эͬ����"), _T("�Կ�����")};
const CString TimeVaring[2]	= {_T("��ʼ�̶�"), _T("ʱʱ����")};