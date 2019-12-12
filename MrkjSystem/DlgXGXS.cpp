// DlgXGXS.cpp: 实现文件
//

#include "stdafx.h"
#include "DlgXGXS.h"
#include "afxdialogex.h"


// DlgXGXS 对话框

IMPLEMENT_DYNAMIC(DlgXGXS, CDialogEx)

DlgXGXS::DlgXGXS(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG_XGXS, pParent)
	, m_strX(_T(""))
	, m_strY(_T(""))
{

}

DlgXGXS::~DlgXGXS()
{
}

void DlgXGXS::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST1, m_list);
	DDX_Text(pDX, IDC_EDIT_X, m_strX);
	DDX_Text(pDX, IDC_EDIT_Y, m_strY);
	DDX_Control(pDX, IDC_EDIT_XGXS, m_XGXS);
}


BEGIN_MESSAGE_MAP(DlgXGXS, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &DlgXGXS::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &DlgXGXS::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON3, &DlgXGXS::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON4, &DlgXGXS::OnBnClickedButton4)
END_MESSAGE_MAP()


// DlgXGXS 消息处理程序
// 计算相关系数
double calculate(double arr1[], double average1, double arr2[], double average2, int n)
{
	double sum1 = 0.0, sum2 = 0.0, sum3 = 0.0;
	for (int i = 0; i < n; i++)
	{
		sum1 += ((arr1[i] - average1) * (arr2[i] - average2));
		double temp1, temp2;
		temp1 = (arr1[i] - average1);
		sum2 += pow(temp1, 2);
		temp2 = (arr2[i] - average2);
		sum3 += pow(temp2, 2);
	}
	double num1, num2;
	num1 = sqrt(sum2);
	num2 = sqrt(sum3);
	double result = sum1 / (num1 * num2);
	return result;
}

BOOL DlgXGXS::OnInitDialog()
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
			m_list.InsertColumn(EListIndexX, _T("X"), LVCFMT_CENTER, rc.Width() / EListIndexLimit);
			m_list.InsertColumn(EListIndexY, _T("Y"), LVCFMT_CENTER, rc.Width() / EListIndexLimit);
		}
	}
	return TRUE;  // return TRUE unless you set the focus to a control
				  // 异常: OCX 属性页应返回 FALSE
}

//添加
void DlgXGXS::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(true);
	int index = m_list.GetItemCount();
	m_list.InsertItem(index, m_strX);
	m_list.SetItemText(index, EListIndexY, m_strY);
}

//计算
void DlgXGXS::OnBnClickedButton2()
{
	// TODO: 在此添加控件通知处理程序代码
	int num = m_list.GetItemCount();
	double* num1 = new double[num];
	double* num2 = new double[num];
	double count1=0.0, count2=0.0, avg1, avg2;
	for (int i = 0; i < num; i++)
	{
		num1[i] = _ttof(m_list.GetItemText(i, EListIndexX));
		num2[i] = _ttof(m_list.GetItemText(i, EListIndexY));
		count1 += num1[i];
		count2 += num2[i];
	}
	avg1 = count1 / num;
	avg2 = count2 / num;
	double result = calculate(num1, avg1, num2, avg2, num);
	CString tmp;
	tmp.Format(L"%lf", result);
	m_XGXS.SetWindowText(tmp);
	delete[] num1, num2;
}

//清空
void DlgXGXS::OnBnClickedButton3()
{
	// TODO: 在此添加控件通知处理程序代码
	m_strX = L"";
	m_strY = L"";
	UpdateData(false);
}

//清空列表
void DlgXGXS::OnBnClickedButton4()
{
	// TODO: 在此添加控件通知处理程序代码
	m_list.DeleteAllItems();
}
