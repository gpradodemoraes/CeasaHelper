// ChildView.h : interface of the CChildView class
//

#pragma once
#include "CMyDialog1.h"
#include "CMyDialog2.h"
#include "CMyDialog3.h"

// CChildView window

class CChildView : public CWnd {
	// Construction
   public:
	CChildView();
	// Attributes
   public:
	CMyDialog1 m_dlg1;
	CMyDialog2 m_dlg2;
	CMyDialog3 m_dlg3;

	// Operations
   public:
	void ShowDialog(int n);
	// Overrides
   protected:
	virtual BOOL PreCreateWindow(CREATESTRUCT &cs);

	// Implementation
   public:
	virtual ~CChildView();

	// Generated message map functions
   protected:
	// afx_msg void OnPaint();
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
	afx_msg void OnSize(UINT nType, int cx, int cy);
	DECLARE_MESSAGE_MAP()
};
