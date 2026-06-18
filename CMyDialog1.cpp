#include "pch.h"
#include "CMyDialog1.h"

IMPLEMENT_DYNAMIC(CMyDialog1, CMyDialog) // ← must be here!

// CMyDialog1::CMyDialog1(CWnd *pParent) : CMyDialog(IDD_MY_DIALOG1, pParent) {}

CMyDialog1::~CMyDialog1() {}

void CMyDialog1::DoDataExchange(CDataExchange *pDX) { CDialog::DoDataExchange(pDX); }

BOOL CMyDialog1::OnInitDialog() {
	CWnd *pStatic = GetDlgItem(IDC_HOME_KEYS);
	pStatic->SetWindowText(
		_T("F1: Mostrar essa tela\r\n\r\n"
		   "S : Combinações de somas de lista de números\r\n\r\n"
		   "D : Divisão do arquivo TXT de Folha\r\n\r\n"
		   "P : Provisões de Férias e 13º\r\n\r\n"
		   "A : Sobre este programa"));
	return TRUE;
}

BEGIN_MESSAGE_MAP(CMyDialog1, CDialog) // ← must be here!
ON_WM_KEYDOWN()
// ON_WM_CREATE()
END_MESSAGE_MAP()
