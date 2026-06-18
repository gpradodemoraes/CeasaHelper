#include "pch.h"
#include "CDivisaoTXT.h"

IMPLEMENT_DYNAMIC(CDivisaoTXT, CMyDialog) // ← must be here!

// CDivisaoTXT::CDivisaoTXT(CWnd *pParent) : CMyDialog(IDD_MY_DIALOG1, pParent) {}

CDivisaoTXT::~CDivisaoTXT() {}

void CDivisaoTXT::DoDataExchange(CDataExchange *pDX) { CDialog::DoDataExchange(pDX); }

BEGIN_MESSAGE_MAP(CDivisaoTXT, CDialog) // ← must be here!
ON_WM_KEYDOWN()
END_MESSAGE_MAP()
