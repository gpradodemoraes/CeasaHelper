#include "pch.h"
#include "CMyDialog2.h"
#include "resource.h"

IMPLEMENT_DYNAMIC(CMyDialog2, CMyDialog) // ← must be here!

// CMyDialog2::CMyDialog2(CWnd *pParent) : CMyDialog(IDD_MY_DIALOG1, pParent) {}

CMyDialog2::~CMyDialog2() {}

BOOL CMyDialog2::PreTranslateMessage(MSG *pMsg) {
	if (pMsg->message == WM_KEYDOWN) {
		// SetDlgItemInt(IDC_D2_NUMEROSBOX, LOWORD(pMsg->wParam));
		if (LOWORD(pMsg->wParam) == VK_RETURN) {
			// HWND hEdit = GetDlgItem(IDC_D2_NUMEROSBOX)->GetSafeHwnd();
			GetDlgItem(IDC_D2_NUMEROSBOX)->SendMessage(EM_SETSEL, (WPARAM)-1, (LPARAM)-1);
			// SendMessage( EM_SETSEL, (WPARAM)-1, (LPARAM)-1);

			// Append the text
			char force_new_line[] = { 0x0D, 0x00, 0x0A, 0x00, 0x00, 0x00 };
			GetDlgItem(IDC_D2_NUMEROSBOX)->SendMessage(EM_REPLACESEL, FALSE, (LPARAM)force_new_line);

		} else if ((LOWORD(pMsg->wParam) >= '0' && LOWORD(pMsg->wParam) <= '9') ||
				   LOWORD(pMsg->wParam) == VK_OEM_COMMA || LOWORD(pMsg->wParam) == VK_OEM_PERIOD ||
				   LOWORD(pMsg->wParam) == VK_BACK || LOWORD(pMsg->wParam) == VK_DELETE ||
				   LOWORD(pMsg->wParam) == VK_LEFT || LOWORD(pMsg->wParam) == VK_RIGHT ||
				   LOWORD(pMsg->wParam) == VK_TAB) {
			TRACE("GOOD Key pressed: %c\n", LOWORD(pMsg->wParam));

			return CMyDialog::PreTranslateMessage(pMsg);

		} else {
			TRACE("BAD Key pressed: %c\n", LOWORD(pMsg->wParam));
			return TRUE;
		}
		// SetDlgItemText(IDC_D2_NUMEROSBOX,  dynamic_cast<LPCTSTR>( pMsg->message ));
	}

	return CMyDialog::PreTranslateMessage(pMsg);
}

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
