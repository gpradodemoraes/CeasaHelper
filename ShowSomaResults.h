#pragma once
#include <afxwin.h>
#include "resource.h"

class CShowSomaResults : public CDialog {
	DECLARE_DYNAMIC(CShowSomaResults)

   public:
	CShowSomaResults(CWnd *pParent = nullptr);
	virtual ~CShowSomaResults();
	CListBox m_listOutput;
	BOOL CShowSomaResults::OnInitDialog();

	afx_msg void CShowSomaResults::OnBnClickedClose() { EndDialog(IDOK); }

	enum { IDD = IDD_SHOW_SOMA_RESULTS };

   protected:
	virtual void DoDataExchange(CDataExchange *pDX) override;
	void PostNcDestroy() override;
	DECLARE_MESSAGE_MAP()
};
