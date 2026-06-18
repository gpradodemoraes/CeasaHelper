#include "pch.h"
#include "CMyDialog.h"

IMPLEMENT_DYNAMIC(CMyDialog, CDialog)
BEGIN_MESSAGE_MAP(CMyDialog, CDialog)
END_MESSAGE_MAP()

CMyDialog::~CMyDialog() {}

BOOL CMyDialog::PreTranslateMessage(MSG *pMsg) {
	if (pMsg->message == WM_KEYDOWN) {
		switch (pMsg->wParam) {
			case VK_F1: GetParent()->SendMessage(WM_KEYDOWN, VK_F1, 0); return TRUE;
			case 'S': GetParent()->SendMessage(WM_KEYDOWN, 'S', 0); break;
			case 'D': GetParent()->SendMessage(WM_KEYDOWN, 'D', 0); break;
			case 'P': GetParent()->SendMessage(WM_KEYDOWN, 'P', 0); break;
			case 'A': GetParent()->SendMessage(WM_KEYDOWN, 'A', 0); break;
		}
	}
	return CDialog::PreTranslateMessage(pMsg); // let MFC handle the rest
}
