#pragma once
#include "pch.h"
#include "resource.h"
#include "CMyDialog.h"

class CMyDialog1 : public CMyDialog {
	DECLARE_DYNAMIC(CMyDialog1)
   public:
	CMyDialog1(CWnd *pParent = nullptr) : CMyDialog(IDD_MY_DIALOG1, pParent) {}

	virtual ~CMyDialog1();

	// enum { IDD = IDD_MY_DIALOG1 };

   protected:
	virtual void DoDataExchange(CDataExchange *pDX) override;
	DECLARE_MESSAGE_MAP()
};
