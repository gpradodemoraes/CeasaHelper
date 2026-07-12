#include "pch.h"
#include "CDivisaoTXT.h"
#include "CeasaDllHeader.h"
#include <afxdlgs.h>
#include <atlconv.h>

IMPLEMENT_DYNAMIC(CDivisaoTXT, CMyDialog) // ← must be here!

// CDivisaoTXT::CDivisaoTXT(CWnd *pParent) : CMyDialog(IDD_MY_DIALOG1, pParent) {}

void CDivisaoTXT::OnProcurarArquivoClick() {
	TRACE(L"NOME ATUAL: %s\n", fileDivisaoTXTfullPath);
	CFileDialog fileDlg(TRUE,												  // TRUE = Open dialog, FALSE = Save dialog
						_T("txt"),											  // Default file extension
						NULL,												  // Default filename (none)
						OFN_FILEMUSTEXIST | OFN_HIDEREADONLY,				  // Flags
						_T("Text Files (*.txt)|*.txt|All Files (*.*)|*.*||"), // Filter
						this												  // Parent window
	);

	if (fileDlg.DoModal() == IDOK) {
		fileDivisaoTXTfullPath = fileDlg.GetPathName(); // Full path
		m_staticFilePath.SetWindowTextW(fileDivisaoTXTfullPath);
		// CString strFileName = fileDlg.GetFileName(); // Just the filename
	}
}

void CDivisaoTXT::OnProcessarArquivoClick() {
	char error[1024] = { 0 };

	CT2CA utf8Str(fileDivisaoTXTfullPath, CP_UTF8);
	const char *utf8FilePath = utf8Str;

	if (callDivisaoTXT(utf8FilePath, error) > 0) {
		CA2W wideStr(error, CP_UTF8); // explicit UTF-8 -> wide conversion
		CString str(wideStr);		  // now a normal CString (Unicode build)
		AfxMessageBox(wideStr, MB_OK | MB_ICONERROR);
		return;
	}
}

CDivisaoTXT::~CDivisaoTXT() {}

void CDivisaoTXT::DoDataExchange(CDataExchange *pDX) {
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_TXT_FILE_PATH, m_staticFilePath);
	m_staticFilePath.SetWindowTextW(fileDivisaoTXTfullPath);
}

BEGIN_MESSAGE_MAP(CDivisaoTXT, CDialog) // ← must be here!
ON_WM_KEYDOWN()
ON_BN_CLICKED(IDC_DIVISAOTXT_B, &CDivisaoTXT::OnProcurarArquivoClick)
ON_BN_CLICKED(IDC_DIVISAOTXT_PROCESSAR_B, &CDivisaoTXT::OnProcessarArquivoClick)
END_MESSAGE_MAP()
