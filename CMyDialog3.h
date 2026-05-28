#pragma once
#include "pch.h"
#include "resource.h"
#include "CMyDialog.h"

class CMyDialog3 : public CMyDialog {
	DECLARE_DYNAMIC(CMyDialog3)
   public:
	CMyDialog3(CWnd *pParent = nullptr) : CMyDialog(IDD_MY_DIALOG3, pParent) {}

	virtual ~CMyDialog3();

	// enum { IDD = IDD_MY_DIALOG1 };

   protected:
	virtual void DoDataExchange(CDataExchange *pDX) override;
	DECLARE_MESSAGE_MAP()
};
