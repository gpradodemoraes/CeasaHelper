// ChildView.cpp : implementation of the CChildView class
//

#include "pch.h"
#include "framework.h"
#include "CeasaHelper.h"
#include "ChildView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CChildView

CChildView::CChildView() {}

CChildView::~CChildView() {}

BEGIN_MESSAGE_MAP(CChildView, CWnd)
ON_WM_CREATE()
ON_WM_SYSKEYDOWN()
ON_WM_KEYDOWN()
ON_WM_SIZE()
END_MESSAGE_MAP()

// CChildView message handlers

void CChildView::ShowDialog(int n) {
	if (n == 9999) {
		m_aboutDlg.DoModal();
		return;
	}

	for (int i = 0; i < dialogList->size(); ++i) {
		if (i + 1 == n) {
			dialogList->at(i)->ShowWindow(SW_SHOW);
			dialogList->at(i)->EnableWindow(TRUE);
			GetParent()->SetFocus();
		} else {
			dialogList->at(i)->ShowWindow(SW_HIDE);
			dialogList->at(i)->EnableWindow(FALSE);
		}
	}
	if (n == 1)
		is_home_visible = TRUE;
	else
		is_home_visible = FALSE;
}

BOOL CChildView::PreCreateWindow(CREATESTRUCT &cs) {
	if (!CWnd::PreCreateWindow(cs)) return FALSE;

	cs.dwExStyle |= WS_EX_CLIENTEDGE;
	cs.style &= ~WS_BORDER;
	cs.lpszClass = AfxRegisterWndClass(CS_HREDRAW | CS_VREDRAW | CS_DBLCLKS, ::LoadCursor(nullptr, IDC_ARROW),
									   reinterpret_cast<HBRUSH>(COLOR_WINDOW + 1), nullptr);

	return TRUE;
}

// void CChildView::OnPaint() {
// 	CPaintDC dc(this); // device context for painting
//
// 	// TODO: Add your message handler code here
//
// 	// Do not call CWnd::OnPaint() for painting messages
// }

int CChildView::OnCreate(LPCREATESTRUCT lpCreateStruct) {
	if (CWnd::OnCreate(lpCreateStruct) == -1) return -1;

	m_dlg1.Create(IDD_MY_DIALOG1, this);
	m_dlg2.Create(IDD_MY_DIALOG2, this);
	m_dlg3.Create(IDD_MY_DIALOG3, this);
	// m_aboutDlg.Create(IDD_ABOUTBOX, this);

	dialogList = std::make_unique<std::vector<CMyDialog *>>();

	dialogList->push_back(static_cast<CMyDialog *>(&m_dlg1));
	dialogList->push_back(static_cast<CMyDialog *>(&m_dlg2));
	dialogList->push_back(static_cast<CMyDialog *>(&m_dlg3));

	ShowDialog(1);

	return 0;
}

void CChildView::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags) {
	if (nChar == VK_F1) {
		ShowDialog(1);
		CWnd::OnKeyDown(nChar, nRepCnt, nFlags);
		return;
	}
	if (is_home_visible) {
		if (nChar == 'S') ShowDialog(2);
		if (nChar == 'P') ShowDialog(3);
		if (nChar == 'A') ShowDialog(9999);
		return;
	}
	CWnd::OnKeyDown(nChar, nRepCnt, nFlags);
}

void CChildView::OnSize(UINT nType, int cx, int cy) {
	CWnd::OnSize(nType, cx, cy);

	CMyDialog *dialogList[] = { static_cast<CMyDialog *>(&m_dlg1), static_cast<CMyDialog *>(&m_dlg2),
								static_cast<CMyDialog *>(&m_dlg3) };
	for (CMyDialog *dlg : dialogList) {
		if (dlg && IsWindow(dlg->GetSafeHwnd())) {
			dlg->CenterWindow(this);
		}
	}
}
