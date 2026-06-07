#pragma once
#include <afxwin.h>
#include "resource.h"

class CShowSomaResults : public CDialog {
	DECLARE_DYNAMIC(CShowSomaResults)

   public:
	CShowSomaResults(CWnd *pParent = nullptr);
	virtual ~CShowSomaResults();
	CString m_resultsText;
	CListBox m_listOutput;
	BOOL CShowSomaResults::OnInitDialog();

	enum { IDD = IDD_SHOW_SOMA_RESULTS };

   protected:
	virtual void DoDataExchange(CDataExchange *pDX) override;
	DECLARE_MESSAGE_MAP()
};
