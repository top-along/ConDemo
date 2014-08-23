#pragma once
#include "DockableForm.h"
#include "resource.h"
#include "afxwin.h"
#include "afxeditbrowsectrl.h"

// CControlDialog 对话框

class CControlDialog : public CDockableScrollForm
{
	DECLARE_DYNAMIC(CControlDialog)

public:
	CControlDialog(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CControlDialog();

// 对话框数据
	enum { IDD = IDD_CONTROL };



protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持
private:
	virtual BOOL OnInitDialog();

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg void OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);



private:
	// 结点数目
	int m_nNodeNum;
	// 用于描述最大邻居距离
	int m_nRange;
	// 获得初始位置方式
	CComboBox m_comboInitPos;
	// 如何获得初始速度
	CComboBox m_comboInitVel;
	// 描述网络结构
	CComboBox m_comboStructure;
	// 描述网络时变
	CComboBox m_comboTimeVaring;
	// 步长
	double m_dStep;
	// 时间总长
	int m_nTotalTime;
private:
	// 有无领导者
	CButton m_checkHasLeader;
	// 有领导者的情况下描述领导者
	CEdit m_editLeaderExp;
private:
	// 打开参数保存文件
	CMFCEditBrowseCtrl m_browseFile;

	// 按钮
	CButton m_btnInitPara;
	CButton m_btnSavePara;
	CButton m_btnStart;
	CButton m_btnPause;
	CBitmapButton m_btnStop;

	
public:
	afx_msg void OnBnClickedCheckHasLeader();
};

void InitCombo(CComboBox& combo, const CString* pStr, const int len);


const CString InitPos[2]	= {_T("均匀分布"), _T("手动设置")};
const CString InitVel[2]	= {_T("均匀分布"), _T("正态分布")};
const CString Structure[2]	= {_T("协同网络"), _T("对抗网络")};
const CString TimeVaring[2]	= {_T("初始固定"), _T("时时更新")};