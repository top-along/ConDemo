// ControlDialog.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "ConDemo.h"
#include "ControlDialog.h"
#include "afxdialogex.h"


// CControlDialog �Ի���

IMPLEMENT_DYNAMIC(CControlDialog, CDockableScrollForm)

CControlDialog::CControlDialog(CWnd* pParent /*=NULL*/)
	: CDockableScrollForm(CControlDialog::IDD)
	, m_nNodeNum(0)
	, m_nRange(0)
	, m_dStep(0)
	, m_nTotalTime(0)
{
}

CControlDialog::~CControlDialog()
{
}

void CControlDialog::DoDataExchange(CDataExchange* pDX)
{
	CDockableForm::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT_NODENUM, m_nNodeNum);
	DDV_MinMaxInt(pDX, m_nNodeNum, 0, 10000);
	DDX_Text(pDX, IDC_EDIT_RANGE, m_nRange);
	//  DDX_CBString(pDX, IDC_COMBO_INIT_POS, m_strInitPos);
	//  DDX_CBString(pDX, IDC_COMBO_INIT_VEL, m_strInitVel);
	//  DDX_CBString(pDX, IDC_COMBO_STRUCTURE, m_strNodeStructure);
	DDX_Control(pDX, IDC_COMBO_INIT_POS, m_comboInitPos);
	DDX_Control(pDX, IDC_COMBO_INIT_VEL, m_comboInitVel);
	DDX_Control(pDX, IDC_COMBO_STRUCTURE, m_comboStructure);
	DDX_Control(pDX, IDC_COMBO_TIME_VARING, m_comboTimeVaring);
	DDX_Text(pDX, IDC_EDIT_STEP, m_dStep);
	DDV_MinMaxDouble(pDX, m_dStep, 0.00000001, 1);
	DDX_Text(pDX, IDC_EDIT_TOTAL_TIME, m_nTotalTime);
	DDV_MinMaxInt(pDX, m_nTotalTime, 0, 10000);
	DDX_Control(pDX, IDC_CHECK_HAS_LEADER, m_checkHasLeader);
	//  DDX_Text(pDX, IDC_EDIT_LEADER_EXP, m_strLeaderExp);
	DDX_Control(pDX, IDC_EDIT_LEADER_EXP, m_editLeaderExp);
	DDX_Control(pDX, IDC_MFCEDITBROWSE, m_browseFile);
	DDX_Control(pDX, IDC_BUTTON_INIT, m_btnInitPara);
	DDX_Control(pDX, IDC_BUTTON_SAVE_PARA, m_btnSavePara);
	DDX_Control(pDX, IDC_BUTTON_START, m_btnStart);
	DDX_Control(pDX, IDC_BUTTON_PAUSE, m_btnPause);
	DDX_Control(pDX, IDC_BUTTON_STOP, m_btnStop);
}


BEGIN_MESSAGE_MAP(CControlDialog, CDockableForm)
	ON_WM_SIZE()
	ON_WM_HSCROLL()
	ON_BN_CLICKED(IDC_CHECK_HAS_LEADER, &CControlDialog::OnBnClickedCheckHasLeader)
END_MESSAGE_MAP()


// CControlDialog ��Ϣ�������


void CControlDialog::OnSize(UINT nType, int cx, int cy)
{
	CDockableScrollForm::OnSize(nType, cx, cy);

	// TODO: �ڴ˴������Ϣ����������
}


void CControlDialog::OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ

	CDockableScrollForm::OnHScroll(nSBCode, nPos, pScrollBar);
}


//BOOL CControlDialog::Create(LPCTSTR lpszTemplateName, CWnd* pParentWnd)
//{
//	// TODO: �ڴ����ר�ô����/����û���
//	m_comboInitPos.AddString(_T("���ȷֲ�"));
//	m_comboInitPos.AddString(_T("�ֶ�����"));
//
//	return CDialog::Create(lpszTemplateName, pParentWnd);
//}


BOOL CControlDialog::OnInitDialog()
{
	CDockableScrollForm::OnInitDialog();

	// TODO:  �ڴ���Ӷ���ĳ�ʼ��
	// combo���
	InitCombo(m_comboInitPos, InitPos, 2);
	InitCombo(m_comboInitVel, InitVel, 2);
	InitCombo(m_comboStructure, Structure, 2);
	InitCombo(m_comboTimeVaring, TimeVaring, 2);


	m_checkHasLeader.SetCheck(0);
	m_editLeaderExp.EnableWindow(FALSE);

	/*HBITMAP   hBitmap;   
	hBitmap = LoadBitmap(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDB_BMP_START));
	m_btnStart.SetBitmap(hBitmap);
	hBitmap = LoadBitmap(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDB_BMP_PAUSE));
	m_btnPause.SetBitmap(hBitmap);
	hBitmap = LoadBitmap(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDB_BMP_STOP));
	m_btnStop.SetBitmap(hBitmap);*/
	
		
	return TRUE;  // return TRUE unless you set the focus to a control
	// �쳣: OCX ����ҳӦ���� FALSE
}

void InitCombo(CComboBox& combo, const CString* pStr, const int len)
{
	for (int i = 0; i < len; i++)
	{
		combo.AddString(pStr[i]);
	}
	combo.SetCurSel(0);
}



void CControlDialog::OnBnClickedCheckHasLeader()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	if (BST_CHECKED == IsDlgButtonChecked(IDC_CHECK_HAS_LEADER))
	{
		m_editLeaderExp.EnableWindow(TRUE);
	}
	else
	{
		m_editLeaderExp.EnableWindow(FALSE);
	}
}
