#pragma once
#include "pch.h"
#include "resource.h"

class CMyDialog : public CDialog {
	DECLARE_DYNAMIC(CMyDialog)
   public:
	CMyDialog::CMyDialog(UINT nIDTemplate, CWnd *pParentWnd = NULL) : CDialog(nIDTemplate, pParentWnd) {}

	virtual ~CMyDialog();

	virtual BOOL PreTranslateMessage(MSG *pMsg) override;

   protected:
	DECLARE_MESSAGE_MAP()
};
