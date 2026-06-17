#include "pch.h"
#include "SomaProgressBar.hpp"
#include "resource.h"

CSomaProgressBarDlg::CSomaProgressBarDlg() noexcept : CDialogEx(IDD_SOMA_DIALOGBAR) {}

BOOL CSomaProgressBarDlg::OnInitDialog() {
	CDialogEx::OnInitDialog();

	m_progressBar.SetRange(0, 100); // min, max
	m_progressBar.SetStep(1);		// step increment
	m_progressBar.SetPos(0);		// starting position

	return TRUE;
}

void CSomaProgressBarDlg::DoDataExchange(CDataExchange *pDX) {
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_SOMA_PROGRESS, m_progressBar);
}

LRESULT CSomaProgressBarDlg::OnUpdateProgress(WPARAM wParam, LPARAM lParam) {
	m_progressBar.SetPos((int)wParam);
	return 0;
}

LRESULT CSomaProgressBarDlg::OnWorkDone(WPARAM wParam, LPARAM lParam) {
	m_progressBar.SetPos(100); // ensure it shows complete
							   // re-enable your Start button here if you have one
	EndDialog(IDOK);
	return 0;
}

BEGIN_MESSAGE_MAP(CSomaProgressBarDlg, CDialogEx)
ON_MESSAGE(WM_UPDATE_PROGRESS, OnUpdateProgress)
ON_MESSAGE(WM_WORK_DONE, OnWorkDone)
END_MESSAGE_MAP()
