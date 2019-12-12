// DlgQWSYL.cpp: 实现文件
//

#include "stdafx.h"
#include "DlgQWSYL.h"
#include "afxdialogex.h"


// DlgQWSYL 对话框

IMPLEMENT_DYNAMIC(DlgQWSYL, CDialogEx)

DlgQWSYL::DlgQWSYL(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG_QWSYL, pParent)
	, m_strQC(_T(""))
	, m_strXJGX(_T(""))
	, m_strQM(_T(""))
{

}

DlgQWSYL::~DlgQWSYL()
{
}

void DlgQWSYL::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST1, m_list);
	DDX_Text(pDX, IDC_EDIT_QC, m_strQC);
	DDX_Control(pDX, IDC_EDIT_PJQWSYL, m_strPJQWSYL);
	DDX_Text(pDX, IDC_EDIT3, m_strXJGX);
	DDX_Text(pDX, IDC_EDIT_QM, m_strQM);
	DDX_Text(pDX, IDC_EDIT_YEAR, m_strYear);
	DDX_Control(pDX, IDC_EDIT_QWSYLBZC, m_QWSYLBZC);
}


BEGIN_MESSAGE_MAP(DlgQWSYL, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &DlgQWSYL::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &DlgQWSYL::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON4, &DlgQWSYL::OnBnClickedButton4)
	ON_BN_CLICKED(IDC_BUTTON6, &DlgQWSYL::OnBnClickedButton6)
	ON_BN_CLICKED(IDC_BUTTON7, &DlgQWSYL::OnBnClickedButton7)
END_MESSAGE_MAP()


// DlgQWSYL 消息处理程序


BOOL DlgQWSYL::OnInitDialog()
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
			m_list.InsertColumn(EListIndexYear, _T("年份"), LVCFMT_CENTER, rc.Width() / EListIndexLimit);
			m_list.InsertColumn(EListIndexQC, _T("期初价格"), LVCFMT_CENTER, rc.Width() / EListIndexLimit);
			m_list.InsertColumn(EListIndexQM, _T("期末价格"), LVCFMT_CENTER, rc.Width() / EListIndexLimit);
			m_list.InsertColumn(EListIndexXJGX, _T("现金股息"), LVCFMT_CENTER, rc.Width() / EListIndexLimit);
			m_list.InsertColumn(EListIndexQWSYL, _T("期望收益率"), LVCFMT_CENTER, rc.Width() / EListIndexLimit);
		}
	}

	return TRUE;  // return TRUE unless you set the focus to a control
				  // 异常: OCX 属性页应返回 FALSE
}

//添加
void DlgQWSYL::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(true);
	int index = m_list.GetItemCount();
	m_list.InsertItem(index, m_strYear);
	m_list.SetItemText(index, EListIndexQC, m_strQC);
	m_list.SetItemText(index, EListIndexQM, m_strQM);
	m_list.SetItemText(index, EListIndexXJGX, m_strXJGX);
}

//清空
void DlgQWSYL::OnBnClickedButton2()
{
	// TODO: 在此添加控件通知处理程序代码
	m_strYear = L"";
	m_strQC = L"";
	m_strQM = L"";
	m_strXJGX = L"";
	UpdateData(false);
}

//计算
void DlgQWSYL::OnBnClickedButton4()
{
	// TODO: 在此添加控件通知处理程序代码
	double num1, num2, num3;
	double sum = 0;
	CString str1;
	int num = m_list.GetItemCount();
	QWSYL = new double[num];
	for (int i = 0; i < num; i++)
	{
		num1 = _ttof(m_list.GetItemText(i, EListIndexQC));
		num2 = _ttof(m_list.GetItemText(i, EListIndexQM));
		num3 = _ttof(m_list.GetItemText(i, EListIndexXJGX));
		QWSYL[i] = (num2 - num1 + num3) / num1;
		sum += QWSYL[i];
		str1.Format(L"%lf", QWSYL[i]);
		m_list.SetItemText(i, EListIndexQWSYL, str1);
	}
	str1.Format(L"%lf", sum / num);
	m_strPJQWSYL.SetWindowText(str1);
}

//清空列表
void DlgQWSYL::OnBnClickedButton6()
{
	// TODO: 在此添加控件通知处理程序代码
	m_list.DeleteAllItems();
}
double standard_deviation(double arr[], double average, int n)
{
	double sum = 0.0;
	for (int i = 0; i < n; i++)
	{
		double temp = (arr[i] - average);
		sum += pow(temp, 2);
	}
	double temp1 = sum / (1.0 * n - 1.0);
	double result = sqrt(temp1);
	return result;
}

//计算期望收益率标准差
void DlgQWSYL::OnBnClickedButton7()
{
	// TODO: 在此添加控件通知处理程序代码
	CString str;
	m_strPJQWSYL.GetWindowText(str);
	int len = m_list.GetItemCount();
	double avg = _ttof(str);
	double result = standard_deviation(QWSYL, avg, len);
	str.Format(L"%lf", result);
	m_QWSYLBZC.SetWindowText(str);
}
