// Beta.cpp: 实现文件
//

#include "stdafx.h"
#include "Beta.h"
#include "afxdialogex.h"
#include <math.h>


// Beta 对话框

IMPLEMENT_DYNAMIC(Beta, CDialog)

Beta::Beta(CWnd* pParent /*=nullptr*/)
	: CDialog(IDD_DIALOG_BEITA, pParent)
	, m_gpbzc(_T(""))
	, m_scbzc(_T(""))
	, m_xgxs(_T(""))
{

}

Beta::~Beta()
{
}

void Beta::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT_GPBZC, m_gpbzc);
	DDX_Text(pDX, IDC_EDIT_SCBZC, m_scbzc);
	DDX_Control(pDX, IDC_EDIT_ONLYBETA, m_beta);
	DDX_Text(pDX, IDC_EDIT_XGXS, m_xgxs);
}


BEGIN_MESSAGE_MAP(Beta, CDialog)
	ON_BN_CLICKED(IDC_BUTTON_CAL_ONLYBETA, &Beta::OnClickedButtonCalOnlybeta)
END_MESSAGE_MAP()


// Beta 消息处理程序


BOOL Beta::OnInitDialog()
{
	CDialog::OnInitDialog();

	// TODO:  在此添加额外的初始化
	SetWindowPos(&wndNoTopMost, 0, 0, 0, 0, SWP_NOMOVE | SWP_NOSIZE);

	return TRUE;  // return TRUE unless you set the focus to a control
				  // 异常: OCX 属性页应返回 FALSE
}


void Beta::OnClickedButtonCalOnlybeta()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(true);
	double gpbzc, scbzc, xgxs, beta;
	gpbzc = _wtof(m_gpbzc.GetBuffer());
	scbzc = _wtof(m_scbzc.GetBuffer());
	xgxs = _wtof(m_xgxs.GetBuffer());
	double tmp = gpbzc * pow(scbzc, -1);
	beta = xgxs * tmp;
	CString str;
	str.Format(L"%.8lf", beta);
	m_beta.SetWindowText(str);
	CString str2;
	str2.Format(L"%lf,%lf,%lf,%lf", gpbzc, scbzc, xgxs, beta);
	MessageBox(str2, L"提示");
}
