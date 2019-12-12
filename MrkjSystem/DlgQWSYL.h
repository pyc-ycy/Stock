#pragma once


// DlgQWSYL 对话框

class DlgQWSYL : public CDialogEx
{
	DECLARE_DYNAMIC(DlgQWSYL)

public:
	DlgQWSYL(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~DlgQWSYL();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_QWSYL };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	// 列表视图控件
	CListCtrl m_list;
	// 期初价格
	CString m_strQC;
	// 平均期望收益率
	CEdit m_strPJQWSYL;
	// 现金股息
	CString m_strXJGX;
	// 期末价格
	CString m_strQM;
	enum {
		EListIndexYear=0,
		EListIndexQC,
		EListIndexQM,
		EListIndexXJGX,
		EListIndexQWSYL,
		EListIndexLimit
	};
	virtual BOOL OnInitDialog();
	// 年度
	CString m_strYear;
	double* QWSYL;
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedButton4();
	afx_msg void OnBnClickedButton6();
	// 期望收益率标准差
	CEdit m_QWSYLBZC;
	afx_msg void OnBnClickedButton7();
};
