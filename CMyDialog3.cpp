#include "pch.h"
#include "CMyDialog3.h"

IMPLEMENT_DYNAMIC(CMyDialog3, CMyDialog) // ← must be here!

// CMyDialog3::CMyDialog3(CWnd *pParent) : CMyDialog(IDD_MY_DIALOG1, pParent) {}

CMyDialog3::~CMyDialog3() {}

void CMyDialog3::DoDataExchange(CDataExchange *pDX) { CDialog::DoDataExchange(pDX); }

BEGIN_MESSAGE_MAP(CMyDialog3, CDialog) // ← must be here!
ON_WM_KEYDOWN()
END_MESSAGE_MAP()
