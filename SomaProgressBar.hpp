#include <afxdialogex.h>
#include <afxcmn.h>
#include <afxwin.h>
#include "resource.h"

// CSomaProgressBarDlg dialog used for App About

class CSomaProgressBarDlg : public CDialogEx {
   public:
	CSomaProgressBarDlg() noexcept;
	BOOL OnInitDialog();
	CProgressCtrl m_progressBar;
	double *progress;

	enum { IDD = IDD_SOMA_DIALOGBAR };

   protected:
	virtual void DoDataExchange(CDataExchange *pDX); // DDX/DDV support

	// Implementation
   protected:
	afx_msg LRESULT OnUpdateProgress(WPARAM wParam, LPARAM lParam);
	afx_msg LRESULT OnWorkDone(WPARAM wParam, LPARAM lParam);
	DECLARE_MESSAGE_MAP()
};
