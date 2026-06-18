#pragma once
#include "pch.h"
#include "resource.h"
#include "CMyDialog.h"

class CDivisaoTXT : public CMyDialog {
	DECLARE_DYNAMIC(CDivisaoTXT)
   public:
	CDivisaoTXT(CWnd *pParent = nullptr) : CMyDialog(IDD_MY_DIALOG3, pParent) {}

	virtual ~CDivisaoTXT();

	// enum { IDD = IDD_MY_DIALOG1 };

   protected:
	virtual void DoDataExchange(CDataExchange *pDX) override;
	DECLARE_MESSAGE_MAP()
};
