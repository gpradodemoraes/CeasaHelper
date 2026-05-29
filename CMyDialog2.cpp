#include "pch.h"
#include "CMyDialog2.h"
#include "resource.h"

IMPLEMENT_DYNAMIC(CMyDialog2, CMyDialog) // ← must be here!

// CMyDialog2::CMyDialog2(CWnd *pParent) : CMyDialog(IDD_MY_DIALOG1, pParent) {}

CMyDialog2::~CMyDialog2() {}

void CMyDialog2::DoDataExchange(CDataExchange *pDX) { CDialog::DoDataExchange(pDX); }

void CMyDialog2::OnShowWindow(BOOL bShow, UINT nStatus) {
	CDialog::OnShowWindow(bShow, nStatus);

	if (bShow) {
		PostMessage(WM_NEXTDLGCTL, (WPARAM)GetDlgItem(IDC_D2_MINIMOBOX)->GetSafeHwnd(), TRUE);
	}
}

BEGIN_MESSAGE_MAP(CMyDialog2, CDialog) // ← must be here!
ON_WM_KEYDOWN()
ON_WM_SHOWWINDOW()
END_MESSAGE_MAP()
