#pragma once
#include "pch.h"
#include "resource.h"
#include "CMyDialog.h"

class CMyDialog2 : public CMyDialog {
	DECLARE_DYNAMIC(CMyDialog2)
   public:
	CMyDialog2(CWnd *pParent = nullptr) : CMyDialog(IDD_MY_DIALOG2, pParent) {}

	virtual ~CMyDialog2();

   protected:
	virtual void OnOK() override {}

	virtual BOOL PreTranslateMessage(MSG *pMsg) override;
	virtual void DoDataExchange(CDataExchange *pDX) override;
	void OnShowWindow(BOOL bShow, UINT nStatus);
	DECLARE_MESSAGE_MAP()
};
