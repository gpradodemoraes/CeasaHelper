#include "pch.h"
#include "CMyDialog.h"

IMPLEMENT_DYNAMIC(CMyDialog, CDialog)
BEGIN_MESSAGE_MAP(CMyDialog, CDialog)
END_MESSAGE_MAP()

CMyDialog::~CMyDialog() {}

BOOL CMyDialog::PreTranslateMessage(MSG *pMsg) {
	if (pMsg->message == WM_KEYDOWN) {
		switch (pMsg->wParam) {
			case VK_F1:
				GetParent()->SendMessage(WM_KEYDOWN, VK_F1, 0);
				return TRUE; // message handled, don't process further

			case VK_F2: GetParent()->SendMessage(WM_KEYDOWN, VK_F2, 0); return TRUE;

			case VK_F3: GetParent()->SendMessage(WM_KEYDOWN, VK_F3, 0); return TRUE;
		}
	}
	return CDialog::PreTranslateMessage(pMsg); // let MFC handle the rest
}
