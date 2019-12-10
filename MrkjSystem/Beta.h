#pragma once


// Beta 对话框

class Beta : public CDialog
{
	DECLARE_DYNAMIC(Beta)

public:
	Beta(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~Beta();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_BEITA };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	// 股票标准差
	CString m_gpbzc;
	// 市场标准差
	CString m_scbzc;
	// 股票的贝塔值
	CEdit m_beta;
	// 股票和市场的相关系数
	CString m_xgxs;
	afx_msg void OnClickedButtonCalOnlybeta();
};
