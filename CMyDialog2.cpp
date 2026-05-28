#include "pch.h"
#include "CMyDialog2.h"

IMPLEMENT_DYNAMIC(CMyDialog2, CMyDialog) // ← must be here!

// CMyDialog2::CMyDialog2(CWnd *pParent) : CMyDialog(IDD_MY_DIALOG1, pParent) {}

CMyDialog2::~CMyDialog2() {}

void CMyDialog2::DoDataExchange(CDataExchange *pDX) { CDialog::DoDataExchange(pDX); }

BEGIN_MESSAGE_MAP(CMyDialog2, CDialog) // ← must be here!
ON_WM_KEYDOWN()
END_MESSAGE_MAP()
