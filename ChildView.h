// ChildView.h : interface of the CChildView class
//

#pragma once
#include "CMyDialog1.h"
#include "CMyDialog2.h"
#include "CMyDialog3.h"
#include "CDivisaoTXT.h"
#include "CAboutDlg.h"
#include <vector>
#include <memory>

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
	CDivisaoTXT m_divisaoTXT;
	CAboutDlg m_aboutDlg;

	// Operations
   public:
	void ShowDialog(int n);
	// Overrides
   protected:
	virtual BOOL PreCreateWindow(CREATESTRUCT &cs);

	// Implementation
   public:
	virtual ~CChildView();

   private:
	BOOL is_home_visible = false;
	std::unique_ptr<std::vector<CMyDialog *>> dialogList;
	// Generated message map functions
   protected:
	// afx_msg void OnPaint();
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
	afx_msg void OnSize(UINT nType, int cx, int cy);
	DECLARE_MESSAGE_MAP()
};
