#pragma once


// DlgVar 对话框

class DlgVar : public CDialogEx
{
	DECLARE_DYNAMIC(DlgVar)

public:
	DlgVar(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~DlgVar();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_VAR };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	// 期望收益率框内的列表框
	CListCtrl m_list1;
	// 股票代码
	CString m_strID;
	// 期望收益率
	CString m_strSYL;
	// 标准差
	CString m_strBZC;
	// 投资比例
	CString m_strBL;
	enum {
		EListIndexID = 0,
		EListIndexSYL,
		ElistIndexBZC,
		EListIndexBL,
		EListIndexMaxLimit
	};
	virtual BOOL OnInitDialog();
	afx_msg void OnClickedButtonAddtolistone();
	afx_msg void OnClickedButtonClc();
	afx_msg void OnClickedButtonClearListone();
	// 相关系数
	CListCtrl m_list2;
	// 股票数量
	CString m_strGS;
	afx_msg void OnClickedButtonConfire();
	// 行标
	CString m_strX;
	// 列标
	CString m_strY;
	// 值
	CString m_strValue;
	afx_msg void OnBnClickedButton6();
	afx_msg void OnBnClickedButtonClctwo();
	// 投资总额// 投资总额
	CString m_strZE;
	// 置信度
	CString m_strZXD;
	// 风险价值
	CEdit m_FXJZ;
	// 非分散风险价值
	CEdit m_FFSFXJZ;
	// 分散风险价值
	CEdit m_FSFXJZ;
	// 组合期望收益率
	CEdit m_strZHQWSYL;
	// 非分散标准差
	CEdit m_FFSBZC;
	// 分散标准差
	CEdit m_FSBZC;
	afx_msg void OnBnClickedButton8();
	afx_msg void OnBnClickedButton9();
};
