#include "pch.h"
#include "ShowSomaResults.h"
#include "resource.h"

IMPLEMENT_DYNAMIC(CShowSomaResults, CDialog)

CShowSomaResults::CShowSomaResults(CWnd *pParent) : CDialog(IDD_SHOW_SOMA_RESULTS, pParent) {}

CShowSomaResults::~CShowSomaResults() {}

BOOL CShowSomaResults::OnInitDialog() {
	CDialog::OnInitDialog();

	m_listOutput.AddString(_T("015-GABRIEL"));
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

BEGIN_MESSAGE_MAP(CShowSomaResults, CDialog)
ON_BN_CLICKED(IDC_SHOW_SOMA_CLOSE, &CShowSomaResults::OnBnClickedClose)
END_MESSAGE_MAP()
