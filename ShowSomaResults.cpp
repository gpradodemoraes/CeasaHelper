#include "pch.h"
#include "ShowSomaResults.h"
#include "resource.h"

IMPLEMENT_DYNAMIC(CShowSomaResults, CDialog)

CShowSomaResults::~CShowSomaResults() {}

BOOL CShowSomaResults::OnInitDialog() {
	CDialog::OnInitDialog();

	SetWindowText(_T("Somas encontradas..."));
	// Auto-scroll to last item
	m_listOutput.SetTopIndex(m_listOutput.GetCount() - 1);
	// GetDlgItem(IDC_SOMA_LIST_RESULTS)->SetWindowText(m_resultsText);
	return TRUE;
}

void CShowSomaResults::DoDataExchange(CDataExchange *pDX) {
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_SOMA_LIST_RESULTS, m_listOutput);
}

void CShowSomaResults::PostNcDestroy() {
	CDialog::PostNcDestroy();
	delete this;
}

void CShowSomaResults::OnClose() {
	if (m_pParentWnd) m_pParentWnd->PostMessage(WM_SOMA_DIALOG_CLOSED, 0, 0);
	CDialog::OnClose();
}

BEGIN_MESSAGE_MAP(CShowSomaResults, CDialog)
ON_BN_CLICKED(IDC_SHOW_SOMA_CLOSE, &CShowSomaResults::OnBnClickedClose)
ON_WM_CLOSE()
END_MESSAGE_MAP()
