#include "pch.h"
#include "CMyDialog1.h"

IMPLEMENT_DYNAMIC(CMyDialog1, CMyDialog) // ← must be here!

// CMyDialog1::CMyDialog1(CWnd *pParent) : CMyDialog(IDD_MY_DIALOG1, pParent) {}

CMyDialog1::~CMyDialog1() {}

void CMyDialog1::DoDataExchange(CDataExchange *pDX) { CDialog::DoDataExchange(pDX); }

BEGIN_MESSAGE_MAP(CMyDialog1, CDialog) // ← must be here!
ON_WM_KEYDOWN()
END_MESSAGE_MAP()
