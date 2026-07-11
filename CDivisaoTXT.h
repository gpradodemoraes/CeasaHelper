#pragma once
#include "pch.h"
#include "resource.h"
#include "CMyDialog.h"
#include <afxstr.h>

class CDivisaoTXT : public CMyDialog {
	DECLARE_DYNAMIC(CDivisaoTXT)
   public:
	CDivisaoTXT(CWnd *pParent = nullptr) : CMyDialog(IDD_DIVISAOTXT_DIALOG, pParent) {
		fileDivisaoTXTfullPath = L"GABRIEL";
	}

	void OnProcurarArquivoClick();
	virtual ~CDivisaoTXT();

   private:
	CString fileDivisaoTXTfullPath;
	CStatic m_staticFilePath;

   protected:
	virtual void DoDataExchange(CDataExchange *pDX) override;
	DECLARE_MESSAGE_MAP()
};
