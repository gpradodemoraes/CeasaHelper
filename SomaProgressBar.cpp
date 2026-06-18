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
	int myprogress = (int)wParam;
	if (myprogress > 0) m_progressBar.SetPos(myprogress);
	return 0;
}

LRESULT CSomaProgressBarDlg::OnWorkDone(WPARAM wParam, LPARAM lParam) {
	m_progressBar.SetPos(100); // ensure it shows complete
							   // re-enable your Start button here if you have one

	EndDialog(static_cast<int>(wParam));
	return 0;
}

void CSomaProgressBarDlg::OnCancel() {
	// Optionally, you can handle cancellation here
	// For example, you might want to signal the worker thread to stop
	*this->progress = -1.0; // sinalizar o worker para parar de calcular
	m_progressBar.SetPos(100);
	// Chamar o EndDialog(IDCANCEL); abaixo seria um erro , pois o worker thread ainda está rodando e pode tentar
	// atualizar a barra de progresso depois que o diálogo for destruído.
	// EndDialog(IDCANCEL);
}

BEGIN_MESSAGE_MAP(CSomaProgressBarDlg, CDialogEx)
ON_MESSAGE(WM_UPDATE_PROGRESS, OnUpdateProgress)
ON_MESSAGE(WM_WORK_DONE, OnWorkDone)
ON_BN_CLICKED(IDC_SOMA_PROGRESS_CANCELA, &CSomaProgressBarDlg::OnCancel)
END_MESSAGE_MAP()
