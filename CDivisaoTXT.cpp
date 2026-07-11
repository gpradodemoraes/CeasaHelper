#include "pch.h"
#include "CDivisaoTXT.h"

IMPLEMENT_DYNAMIC(CDivisaoTXT, CMyDialog) // ← must be here!

// CDivisaoTXT::CDivisaoTXT(CWnd *pParent) : CMyDialog(IDD_MY_DIALOG1, pParent) {}

void CDivisaoTXT::OnProcurarArquivoClick() {
	CFileDialog fileDlg(TRUE,												  // TRUE = Open dialog, FALSE = Save dialog
						_T("txt"),											  // Default file extension
						NULL,												  // Default filename (none)
						OFN_FILEMUSTEXIST | OFN_HIDEREADONLY,				  // Flags
						_T("Text Files (*.txt)|*.txt|All Files (*.*)|*.*||"), // Filter
						this												  // Parent window
	);

	if (fileDlg.DoModal() == IDOK) {
		CString strPath = fileDlg.GetPathName();	 // Full path
		CString strFileName = fileDlg.GetFileName(); // Just the filename

		// Do something with the selected file
		AfxMessageBox(strPath);
	}
}

CDivisaoTXT::~CDivisaoTXT() {}

void CDivisaoTXT::DoDataExchange(CDataExchange *pDX) { CDialog::DoDataExchange(pDX); }

BEGIN_MESSAGE_MAP(CDivisaoTXT, CDialog) // ← must be here!
ON_WM_KEYDOWN()
ON_BN_CLICKED(IDC_DIVISAOTXT_B, &CDivisaoTXT::OnProcurarArquivoClick)
END_MESSAGE_MAP()
