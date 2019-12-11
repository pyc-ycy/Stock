// GroupBeta.cpp: 实现文件
//

#include "stdafx.h"
#include "GroupBeta.h"
#include "afxdialogex.h"


// GroupBeta 对话框

IMPLEMENT_DYNAMIC(GroupBeta, CDialogEx)

GroupBeta::GroupBeta(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG_GROUPBETA, pParent)
	, m_StockID(_T(""))
	, m_StockBeta(_T(""))
	, m_StockValue(_T(""))
	, m_StockNum(_T(""))
{

}

GroupBeta::~GroupBeta()
{
}

void GroupBeta::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST_GROUP_BETA, m_list);
	DDX_Text(pDX, IDC_EDIT_ID, m_StockID);
	DDX_Text(pDX, IDC_EDIT_BETA, m_StockBeta);
	DDX_Text(pDX, IDC_EDIT_VALUE, m_StockValue);
	DDX_Text(pDX, IDC_EDIT_NUM, m_StockNum);
	DDX_Control(pDX, IDC_EDIT_GROUPBETA, m_GroupBeta);
}


BEGIN_MESSAGE_MAP(GroupBeta, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON_CAL_GROUPBETA, &GroupBeta::OnClickedButtonCalGroupbeta)
	ON_BN_CLICKED(IDC_BUTTON_ADDLISTITEM, &GroupBeta::OnClickedButtonAddlistitem)
END_MESSAGE_MAP()


// GroupBeta 消息处理程序


BOOL GroupBeta::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化
	{
		LONG lStyle = GetWindowLong(m_list.m_hWnd, GWL_STYLE);
		lStyle &= ~LVS_TYPEMASK;
		lStyle |= LVS_REPORT;
		SetWindowLong(m_list.GetSafeHwnd(), GWL_STYLE, lStyle);
		DWORD dwStyle = m_list.GetExtendedStyle();
		dwStyle |= LVS_EX_FULLROWSELECT; // 选中行，整行高亮
		dwStyle |= LVS_EX_GRIDLINES; // 网格线
		m_list.SetExtendedStyle(dwStyle);
		//设置列，并设置大小
		{
			CRect rc;
			m_list.GetClientRect(rc);
			m_list.InsertColumn(EListIndexID, _T("股票代码"), LVCFMT_CENTER, rc.Width() / EListIndexMaxLimit);
			m_list.InsertColumn(EListIndexBeta, _T("β系数"), LVCFMT_CENTER, rc.Width() / EListIndexMaxLimit);
			m_list.InsertColumn(ElistIndexValue, _T("每股现价"), LVCFMT_CENTER, rc.Width() / EListIndexMaxLimit);
			m_list.InsertColumn(EListIndexNum, _T("股票数量"), LVCFMT_CENTER, rc.Width() / EListIndexMaxLimit);
		}
	}

	return TRUE;  // return TRUE unless you set the focus to a control
				  // 异常: OCX 属性页应返回 FALSE
}


void GroupBeta::OnClickedButtonCalGroupbeta()
{
	// TODO: 在此添加控件通知处理程序代码
	int num = m_list.GetItemCount();
	double* beta = new double[num];
	double* xj = new double[num];
	double* sl = new double[num];
	double* qz = new double[num];
	double count = 0;
	CString str1, str2, str3;
	for (int i = 0; i < num; i++)
	{
		str1 = m_list.GetItemText(i, EListIndexBeta);
		beta[i] = _wtof(str1.GetBuffer());
		str2 = m_list.GetItemText(i, ElistIndexValue);
		xj[i] = _wtof(str2.GetBuffer());
		str3 = m_list.GetItemText(i, EListIndexNum);
		sl[i] = _wtof(str3.GetBuffer());
		count = count + (xj[i] * sl[i]);
	}
	for (int i = 0; i < num; i++)
	{
		qz[i] = (xj[i] * sl[i]) / count;
	}
	double result = 0;
	for (int i = 0; i < num; i++)
		result = result + (qz[i] * beta[i]);
	CString str;
	str.Format(L"%lf", result);
	m_GroupBeta.SetWindowText(str);
}


void GroupBeta::OnClickedButtonAddlistitem()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(true);
	int index = m_list.GetItemCount();
	m_list.InsertItem(index, m_StockID);
	m_list.SetItemText(index, EListIndexBeta, m_StockBeta);
	m_list.SetItemText(index, ElistIndexValue, m_StockValue);
	m_list.SetItemText(index, EListIndexNum, m_StockNum);
}
