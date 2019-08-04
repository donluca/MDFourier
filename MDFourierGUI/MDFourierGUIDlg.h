
// MDFourierGUIDlg.h : header file
//

#pragma once
#include "afxwin.h"
#include "DOSExecute.h"

#define	IDT_DOS	1000

#define	COUNT_CURVES	6
#define COUNT_WINDOWS	5
#define	COUNT_PROFILES	255

typedef struct commandline_st {
	CString	Name;
	CString	valueMDF;
} CommandLineArray;

// CMDFourierGUIDlg dialog
class CMDFourierGUIDlg : public CDialogEx
{
// Construction
public:
	CMDFourierGUIDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	enum { IDD = IDD_MDFOURIERGUI_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


// Implementation
protected:
	HICON m_hIcon;

	CString m_ComparisonFile;
	CString m_Reference;
	CString m_Output;
	CString resultsFolder;

	CStatic m_ReferenceLbl;
	CStatic m_ComparisonLbl;
	CEdit	m_OutputCtrl;
	CEdit	m_ExtraParamsEditBox;
	CButton m_OpenResultsBttn;
	CButton m_ExecuteBttn;
	CButton m_ReferenceFileBttn;
	CButton m_ComparisonFileBttn;
	CButton m_AlignFFTW;
	CButton m_AveragePlot_Bttn;
	CButton m_VerboseLog_Bttn;
	CButton m_EnableExtraBttn;
	CButton m_DiffBttn;
	CButton m_MissBttn;
	CButton m_SpectrBttn;

	CComboBox m_WindowTypeSelect;
	CComboBox m_CurveAdjustSelect;
	CComboBox m_Profiles;

	int			DosWaitCount;
	CDOSExecute	cDos;
	CommandLineArray WindowConvert[COUNT_WINDOWS];
	CommandLineArray CurveConvert[COUNT_CURVES];
	CommandLineArray Profiles[COUNT_PROFILES];

	CString listName;
	CString	*elements;
	int		elementCount;
	int		elementPos;

	void FillComboBoxes();
	int CheckDependencies();
	void ManageWindows(BOOL Enable);
	void InsertValueInCombo(CString Name, CString value, CommandLineArray &Data, CComboBox &Combo);
	CString GetSelectedCommandLineValue(CComboBox &Combo, int size);
	void ExecuteCommand(CString Compare);
	void CheckPlotSelection(CButton &clicked);
	int FindProfiles(CString sPath, CString pattern);

	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedSelectReferenceFile();
	afx_msg void OnBnClickedSelectReferenceCompare();
	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedCancel();
	afx_msg void OnBnClickedOpenresults();
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	afx_msg void OnBnClickedAbout();
	afx_msg void OnBnClickedEnableextra();
	afx_msg void OnBnClickedDifferences();
	afx_msg void OnBnClickedMissing();
	afx_msg void OnBnClickedSpectrogram();
	afx_msg void OnBnClickedAverage();
};
