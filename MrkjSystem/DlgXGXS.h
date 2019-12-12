#pragma once


// DlgXGXS 对话框

class DlgXGXS : public CDialogEx
{
	DECLARE_DYNAMIC(DlgXGXS)

public:
	DlgXGXS(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~DlgXGXS();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_XGXS };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CListCtrl m_list;
	CString m_strX;
	CString m_strY;
	enum {
		EListIndexX=0,
		EListIndexY,
		EListIndexLimit
	};
	// 相关系数
	CEdit m_XGXS;
	virtual BOOL OnInitDialog();
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedButton3();
	afx_msg void OnBnClickedButton4();
};
