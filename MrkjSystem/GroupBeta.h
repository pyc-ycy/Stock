#pragma once


// GroupBeta 对话框

class GroupBeta : public CDialogEx
{
	DECLARE_DYNAMIC(GroupBeta)

public:
	GroupBeta(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~GroupBeta();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_GROUPBETA };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CListCtrl m_list;
	// 股票代码
	CString m_StockID;
	// 股票β系数
	CString m_StockBeta;
	// 股价
	CString m_StockValue;
	// 股票数量
	CString m_StockNum;
	// 组合β系数
	CEdit m_GroupBeta;
	enum {
		EListIndexID = 0,
		EListIndexBeta,
		ElistIndexValue,
		EListIndexNum,
		EListIndexMaxLimit
	};
	virtual BOOL OnInitDialog();
	afx_msg void OnClickedButtonCalGroupbeta();
	afx_msg void OnClickedButtonAddlistitem();
};
