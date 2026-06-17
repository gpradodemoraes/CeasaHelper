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

BEGIN_MESSAGE_MAP(CSomaProgressBarDlg, CDialogEx)
END_MESSAGE_MAP()
