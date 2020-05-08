// Add.cpp : implementation file
//

#include "pch.h"
#include "MFCTestApp.h"
#include "Add.h"
#include "afxdialogex.h"
#include "MyMath.h"
#include "GlobalFuncs.h"
// Add dialog

#define FN "myPyScrpt.py"

void resetPyScriptFile()
{
	FILE* fp = 0;
	fopen_s(&fp, FN, "w");
	if (!fp) return;
	fclose(fp);
}
void updatePyScriptFile(string str, CListBox *pScript)
{
	FILE* fp = 0;
	fopen_s(&fp, FN, "a+");
	if (!fp) return;
	fprintf(fp, "\n%s", str.c_str());
	fclose(fp);

	if (pScript)
	{
		CString str2(str.c_str());
		pScript->AddString(str2);
	}
}


IMPLEMENT_DYNAMIC(Add, CDialogEx)

Add::Add(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG1, pParent)
{
	resetPyScriptFile();
	
}

Add::~Add()
{
}

void Add::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, a);
	DDX_Text(pDX, IDC_EDIT2, b);
	//DDX_Text(pDX, IDC_EDIT3, c);
	DDX_Control(pDX, IDC_EDIT3, res);
	DDX_Control(pDX, IDC_LIST1, pyScript);
}


BEGIN_MESSAGE_MAP(Add, CDialogEx)
	ON_BN_CLICKED(IDC_BUT_ADD, &Add::OnBnClickedButAdd)
	
	ON_BN_CLICKED(IDC_BUT_DETAILS, &Add::OnBnClickedButDetails)
	ON_BN_CLICKED(IDC_BUT_DEFADD, &Add::OnBnClickedButDefadd)
	ON_BN_CLICKED(IDC_BUT_MUL, &Add::OnBnClickedButMul)
	ON_BN_CLICKED(IDC_BUT_DIV, &Add::OnBnClickedButDiv)
END_MESSAGE_MAP()


// Add message handlers
BOOL Add::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	updatePyScriptFile("import igold as igt", &pyScript);
	updatePyScriptFile("m = igt.igtMath()", &pyScript);
	return TRUE;
}

void Add::OnBnClickedButDefadd()
{
	UpdateData();

	MyMath obj;
	CString str;
	str.Format(_T("%d"), obj.add());
	res.SetWindowText(str);

	updatePyScriptFile("m.add()", &pyScript);

	UpdateData(FALSE);
}

void Add::OnBnClickedButAdd()
{
	UpdateData();

	MyMath obj;
	CString str ;
	str.Format(_T("%d"), obj.add(a, b));
	res.SetWindowText(str);

	string cmd;
	char buf[100];
	_itoa_s(a, buf, 10);
	cmd = "m.add(" + string(buf);
	cmd += ",";

	_itoa_s(b, buf, 10);
	cmd += string(buf);
	cmd += ")";
	updatePyScriptFile(cmd, &pyScript);
	
	UpdateData(FALSE);
	
}

void Add::OnBnClickedButDetails()
{
	UpdateData();

	MyMath obj;
	CString str(obj.details().c_str());
	res.SetWindowText(str);
	updatePyScriptFile("m.details()", &pyScript);

	UpdateData(FALSE);
}


void Add::OnBnClickedButMul()
{
	UpdateData();

	CString str;
	str.Format(_T("%d"), mul(a, b));
	res.SetWindowText(str);

	string cmd;
	char buf[100];
	_itoa_s(a, buf, 10);
	cmd = "igt.mul(" + string(buf);
	cmd += ",";

	_itoa_s(b, buf, 10);
	cmd += string(buf);
	cmd += ")";
	updatePyScriptFile(cmd, &pyScript);

	UpdateData(FALSE);
}


void Add::OnBnClickedButDiv()
{
	UpdateData();

	CString str;
	str.Format(_T("%d"), division(a, b));
	res.SetWindowText(str);

	string cmd;
	char buf[100];
	_itoa_s(a, buf, 10);
	cmd = "igt.div(" + string(buf);
	cmd += ",";

	_itoa_s(b, buf, 10);
	cmd += string(buf);
	cmd += ")";
	updatePyScriptFile(cmd, &pyScript);

	UpdateData(FALSE);
}
