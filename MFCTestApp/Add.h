#pragma once


// Add dialog

class Add : public CDialogEx
{
	DECLARE_DYNAMIC(Add)

public:
	Add(CWnd* pParent = nullptr);   // standard constructor
	virtual ~Add();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG1 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	int a, b, c;
	CEdit res;
	
	afx_msg void OnBnClickedButAdd();
	virtual BOOL OnInitDialog();
	
	
	afx_msg void OnBnClickedButDetails();
	afx_msg void OnBnClickedButDefadd();
	afx_msg void OnBnClickedButMul();
	afx_msg void OnBnClickedButDiv();
	CListBox pyScript;
};
