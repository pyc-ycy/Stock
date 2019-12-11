// DlgVar.cpp: 实现文件
//

#include "stdafx.h"
#include "DlgVar.h"
#include "afxdialogex.h"


// DlgVar 对话框

IMPLEMENT_DYNAMIC(DlgVar, CDialogEx)

DlgVar::DlgVar(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG_VAR, pParent)
	, m_strID(_T(""))
	, m_strSYL(_T(""))
	, m_strBZC(_T(""))
	, m_strBL(_T(""))
	, m_strGS(_T(""))
	, m_strX(_T(""))
	, m_strY(_T(""))
	, m_strValue(_T(""))
	, m_strZE(_T(""))
	, m_strZXD(_T(""))
{

}

DlgVar::~DlgVar()
{
}

void DlgVar::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST1, m_list1);
	DDX_Text(pDX, IDC_EDIT_STOCKID, m_strID);
	DDX_Text(pDX, IDC_EDIT_SYL, m_strSYL);
	DDX_Text(pDX, IDC_EDIT_BZC, m_strBZC);
	DDX_Text(pDX, IDC_EDIT_BL, m_strBL);
	DDX_Control(pDX, IDC_LIST_TWO, m_list2);
	DDX_Text(pDX, IDC_EDIT_GS, m_strGS);
	DDX_Text(pDX, IDC_EDIT_X, m_strX);
	DDX_Text(pDX, IDC_EDITY, m_strY);
	DDX_Text(pDX, IDC_EDIT_XY, m_strValue);
	DDX_Text(pDX, IDC_EDIT_MONEYSUM, m_strZE);
	DDX_Text(pDX, IDC_EDIT_ALPA, m_strZXD);
	DDX_Control(pDX, IDC_EDIT12, m_FXJZ);
	DDX_Control(pDX, IDC_EDIT13, m_FFSFXJZ);
	DDX_Control(pDX, IDC_EDIT14, m_FSFXJZ);
	DDX_Control(pDX, IDC_EDIT15, m_strZHQWSYL);
	DDX_Control(pDX, IDC_EDIT16, m_FFSBZC);
	DDX_Control(pDX, IDC_EDIT17, m_FSBZC);
}


BEGIN_MESSAGE_MAP(DlgVar, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON_ADDTOLISTONE, &DlgVar::OnClickedButtonAddtolistone)
	ON_BN_CLICKED(IDC_BUTTON_CLC, &DlgVar::OnClickedButtonClc)
	ON_BN_CLICKED(IDC_BUTTON_CLEAR_LISTONE, &DlgVar::OnClickedButtonClearListone)
	ON_BN_CLICKED(IDC_BUTTON_CONFIRE, &DlgVar::OnClickedButtonConfire)
	ON_BN_CLICKED(IDC_BUTTON6, &DlgVar::OnBnClickedButton6)
	ON_BN_CLICKED(IDC_BUTTON_CLCTWO, &DlgVar::OnBnClickedButtonClctwo)
//	ON_EN_CHANGE(IDC_EDIT10, &DlgVar::OnEnChangeEdit10)
ON_BN_CLICKED(IDC_BUTTON8, &DlgVar::OnBnClickedButton8)
ON_BN_CLICKED(IDC_BUTTON9, &DlgVar::OnBnClickedButton9)
END_MESSAGE_MAP()


// DlgVar 消息处理程序


BOOL DlgVar::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	{
		LONG lStyle = GetWindowLong(m_list1.m_hWnd, GWL_STYLE);
		lStyle &= ~LVS_TYPEMASK;
		lStyle |= LVS_REPORT;
		SetWindowLong(m_list1.GetSafeHwnd(), GWL_STYLE, lStyle);
		DWORD dwStyle = m_list1.GetExtendedStyle();
		dwStyle |= LVS_EX_FULLROWSELECT; // 选中行，整行高亮
		dwStyle |= LVS_EX_GRIDLINES; // 网格线
		m_list1.SetExtendedStyle(dwStyle);
		//设置列，并设置大小
		{
			CRect rc;
			m_list1.GetClientRect(rc);
			m_list1.InsertColumn(EListIndexID, _T("股票代码"), LVCFMT_CENTER, rc.Width() / EListIndexMaxLimit);
			m_list1.InsertColumn(EListIndexSYL, _T("期望收益率"), LVCFMT_CENTER, rc.Width() / EListIndexMaxLimit);
			m_list1.InsertColumn(ElistIndexBZC, _T("标准差"), LVCFMT_CENTER, rc.Width() / EListIndexMaxLimit);
			m_list1.InsertColumn(EListIndexBL, _T("投资比例"), LVCFMT_CENTER, rc.Width() / EListIndexMaxLimit);
		}
	}
	// TODO:  在此添加额外的初始化
	{
		LONG lStyle = GetWindowLong(m_list2.m_hWnd, GWL_STYLE);
		lStyle &= ~LVS_TYPEMASK;
		lStyle |= LVS_REPORT;
		SetWindowLong(m_list2.GetSafeHwnd(), GWL_STYLE, lStyle);
		DWORD dwStyle = m_list2.GetExtendedStyle();
		dwStyle |= LVS_EX_FULLROWSELECT; // 选中行，整行高亮
		dwStyle |= LVS_EX_GRIDLINES; // 网格线
		m_list2.SetExtendedStyle(dwStyle);
		//设置列，并设置大小
		{
			CRect rc;
			m_list2.GetClientRect(rc);
			m_list2.InsertColumn(EListIndexID, _T("行标\\列标"), LVCFMT_CENTER, rc.Width() / 8);
		}
	}

	return TRUE;  // return TRUE unless you set the focus to a control
				  // 异常: OCX 属性页应返回 FALSE
}


void DlgVar::OnClickedButtonAddtolistone()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(true);
	int index = m_list1.GetItemCount();
	m_list1.InsertItem(index, m_strID);
	m_list1.SetItemText(index, EListIndexSYL, m_strSYL);
	m_list1.SetItemText(index, ElistIndexBZC, m_strBZC);
	m_list1.SetItemText(index, EListIndexBL, m_strBL);
}


void DlgVar::OnClickedButtonClc()
{
	// TODO: 在此添加控件通知处理程序代码
	m_strID = L"";
	m_strSYL = L"";
	m_strBZC = L"";
	m_strBL = L"";
	UpdateData(false);
}


void DlgVar::OnClickedButtonClearListone()
{
	// TODO: 在此添加控件通知处理程序代码
	m_list1.DeleteAllItems();
}


void DlgVar::OnClickedButtonConfire()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(true);
	int num = _wtoi(m_strGS);
	CRect rc;
	m_list2.GetClientRect(rc);
	CString temp;
	for (int i = 1; i < num + 1; i++)
	{
		temp.Format(L"证券%d", i);
		m_list2.InsertColumn(i, temp, LVCFMT_CENTER, rc.Width() / 8);
	}
	int index = m_list1.GetItemCount();
	for (int i = 0; i < num; i++)
	{
		temp.Format(L"证券%d", i+1);
		m_list2.InsertItem(index+i, temp);
	}
}


void DlgVar::OnBnClickedButton6()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(true);
	int x = _wtoi(m_strX);
	int y = _wtoi(m_strY);
	m_list2.SetItemText(x-1, y, m_strValue);
}


void DlgVar::OnBnClickedButtonClctwo()
{
	// TODO: 在此添加控件通知处理程序代码
	m_strX = L"";
	m_strY = L"";
	m_strValue = L"";
	UpdateData(false);
}
const double PI = 3.1415926;
double Normal(double z)
{
	double temp;
	temp = exp((-1) * z * z / 2) / sqrt(2 * PI);
	return temp;

}
/***************************************************************/
/* 返回标准正态分布的累积函数，该分布的平均值为 0，标准偏差为 1。                           */
/***************************************************************/
double NormSDist(const double z)
{
	// this guards against overflow
	if (z > 6) return 1;
	if (z < -6) return 0;

	static const double gamma = 0.231641900,
		a1 = 0.319381530,
		a2 = -0.356563782,
		a3 = 1.781477973,
		a4 = -1.821255978,
		a5 = 1.330274429;

	double k = 1.0 / (1 + fabs(z) * gamma);
	double n = k * (a1 + k * (a2 + k * (a3 + k * (a4 + k * a5))));
	n = 1 - Normal(z) * n;
	if (z < 0)
		return 1.0 - n;

	return n;
}


/***************************************************************/
/* 返回标准正态分布累积函数的逆函数。该分布的平均值为 0，标准偏差为 1。                    */
/***************************************************************/
double normsinv(const double p)
{
	static const double LOW = 0.02425;
	static const double HIGH = 0.97575;

	/* Coefficients in rational approximations. */
	static const double a[] =
	{
		-3.969683028665376e+01,
			2.209460984245205e+02,
			-2.759285104469687e+02,
			1.383577518672690e+02,
			-3.066479806614716e+01,
			2.506628277459239e+00
	};

	static const double b[] =
	{
		-5.447609879822406e+01,
			1.615858368580409e+02,
			-1.556989798598866e+02,
			6.680131188771972e+01,
			-1.328068155288572e+01
	};

	static const double c[] =
	{
		-7.784894002430293e-03,
			-3.223964580411365e-01,
			-2.400758277161838e+00,
			-2.549732539343734e+00,
			4.374664141464968e+00,
			2.938163982698783e+00
	};

	static const double d[] =
	{
		7.784695709041462e-03,
			3.224671290700398e-01,
			2.445134137142996e+00,
			3.754408661907416e+00
	};

	double q, r;

	errno = 0;

	if (p < 0 || p > 1)
	{
		errno = EDOM;
		return 0.0;
	}
	else if (p == 0)
	{
		errno = ERANGE;
		return -HUGE_VAL /* minus "infinity" */;
	}
	else if (p == 1)
	{
		errno = ERANGE;
		return HUGE_VAL /* "infinity" */;
	}
	else if (p < LOW)
	{
		/* Rational approximation for lower region */
		q = sqrt(-2 * log(p));
		return (((((c[0] * q + c[1]) * q + c[2]) * q + c[3]) * q + c[4]) * q + c[5]) /
			((((d[0] * q + d[1]) * q + d[2]) * q + d[3]) * q + 1);
	}
	else if (p > HIGH)
	{
		/* Rational approximation for upper region */
		q = sqrt(-2 * log(1 - p));
		return -(((((c[0] * q + c[1]) * q + c[2]) * q + c[3]) * q + c[4]) * q + c[5]) /
			((((d[0] * q + d[1]) * q + d[2]) * q + d[3]) * q + 1);
	}
	else
	{
		/* Rational approximation for central region */
		q = p - 0.5;
		r = q * q;
		return (((((a[0] * r + a[1]) * r + a[2]) * r + a[3]) * r + a[4]) * r + a[5]) * q /
			(((((b[0] * r + b[1]) * r + b[2]) * r + b[3]) * r + b[4]) * r + 1);
	}
}

//计算投资组合期望收益率,参数依次为期望收益率数组、投资比例数组、股票支数
double expectedRateOfReturn(double num1[], double num2[], int len)
{
	double result = 0.0;
	for (int i = 0; i < len; i++)
	{
		result += (num1[i] * num2[i]);
	}
	return result;
}

//计算协方差矩阵,参数依次为协方差矩阵、相关系数矩阵、标准差数组、维数
void covarianceMatrix(double** num, double** num1, double num2[], int len)
{
	for (int i = 0; i < len; i++)
	{
		for (int j = 0; j < len; j++)
		{
			num[i][j] = num1[i][j] * num2[i] * num2[j];
		}
	}
}

// 计算组合标准差(分散标准差）,参数依次为标准差、投资比例、相关系数矩阵、维度
double StandardDeviation(double num1[], double num2[], double** num3, int len)
{
	double* temp1, * temp2;
	temp1 = new double[len];
	temp2 = new double[len];
	for (int i = 0; i < len; i++)
	{
		double t = num1[i] * num2[i];
		temp1[i] = pow(t, 2);
	}
	int k = 0;
	for (int i = 0; i < len - 1; i++)
	{
		for (int j = i + 1; j < len; j++)
		{
			temp2[k++] = 2 * (num1[i] * num2[i]) * (num1[j] * num2[j]) * num3[i][j];
		}
	}
	double sum = 0.0;
	for (int i = 0; i < len; i++)
		sum += (temp1[i] + temp2[i]);
	double result = sqrt(sum);
	return result;
}

// 非分散标准差计算，参数依次为标准差数组、投资比例数组、长度
double nonDispersiveStandardDeviation(double num1[], double num2[], int len)
{
	double sum = 0.0;
	for (int i = 0; i < len; i++)
		sum += (num1[i] * num2[i]);
	return sum;

}

// 风险价值计算，参数依次为投资总额、Z值（标准正态分布的抽样分位数）、标准差、期望收益率
double VaR(double W, double Z, double R, double Q)
{
	double result = W * (Z * R + Q);
	return result;
}

// 非分散风险价值，参数依次为总资本、Z值（标准正态分布的抽样分位数）、投资组合非分散标准差
double VaR_Undx(double W, double Z, double R)
{
	double result = W * abs(Z) * R;
	return result;
}

// 分散风险价值计算，参数依次为总资本、Z值（标准正态分布的抽样分位数）、投资组合分散标准差
double VaR_dx(double W, double Z, double R)
{
	double result = W * abs(Z) * R;
	return result;
}


void DlgVar::OnBnClickedButton8()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(true);
	double a = _wtof(m_strZXD);	// 置信度
	double Z = Normal(a);	// Z 值
	double ze = _wtof(m_strZE);	//投资总额
	int num = _wtoi(m_strGS);	//股票支数
	double* numQWSYL = new double[num];	//期望收益率
	double* numBZC = new double[num];	//标准差
	double* numBL = new double[num];	//投资比例
	double** numXGXS = new double* [num]; //相关系数矩阵
	for (int i = 0; i < num; i++)
		numXGXS[i] = new double[num];
	double** numXFC = new double* [num];	// 协方差矩阵
	for (int i = 0; i < num; i++)
		numXFC[i] = new double[num];
	//期望收益数组、标准差数组和投资总额数组赋值
	int len = m_list1.GetItemCount();
	for (int i = 0; i < len; i++)
	{
		numQWSYL[i] = _wtof(m_list1.GetItemText(i, 1).GetBuffer());
		numBZC[i] = _wtof(m_list1.GetItemText(i, 2).GetBuffer());
		numBL[i] = _wtof(m_list1.GetItemText(i, 3).GetBuffer());
	}
	for (int i = 0; i < num; i++)
	{
		for (int j = 1; j < num+1; j++)
			numXGXS[i][j] = _wtof(m_list2.GetItemText(i, j).GetBuffer());
	}
	double ZHQWSYL = expectedRateOfReturn(numQWSYL, numBL, num);	//组合期望收益率
	CString temp;
	temp.Format(L"%lf", ZHQWSYL);
	m_strZHQWSYL.SetWindowText(temp);
	double ZHBZC = StandardDeviation(numBZC, numBL, numXGXS, num); //组合标准差
	temp.Format(L"%lf", ZHBZC);
	m_FSBZC.SetWindowText(temp);
	double FFSBZC = nonDispersiveStandardDeviation(numBZC, numBL, num);	//非分散标准差
	temp.Format(L"%lf", FFSBZC);
	m_FFSBZC.SetWindowText(temp);
	covarianceMatrix(numXFC, numXGXS, numBZC, num);
	double FXJZ = VaR(ze, Z, ZHBZC, ZHQWSYL);
	temp.Format(L"%lf", FXJZ);
	m_FXJZ.SetWindowText(temp);
	double FFSFXJZ = VaR_Undx(ze, Z, FFSBZC);
	temp.Format(L"%lf", FFSFXJZ);
	m_FFSFXJZ.SetWindowText(temp);
	double FSFXJZ = VaR_dx(ze, Z, ZHBZC);
	temp.Format(L"%lf", FSFXJZ);
	m_FSFXJZ.SetWindowText(temp);
}


void DlgVar::OnBnClickedButton9()
{
	// TODO: 在此添加控件通知处理程序代码
	m_FXJZ.SetWindowText(L"");
	m_FFSFXJZ.SetWindowText(L"");
	m_FSFXJZ.SetWindowText(L"");
	m_strZHQWSYL.SetWindowText(L"");
	m_FFSBZC.SetWindowText(L"");
	m_FSBZC.SetWindowText(L"");
}
