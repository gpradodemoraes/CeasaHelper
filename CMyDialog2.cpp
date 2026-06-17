#include "pch.h"
#include "CMyDialog2.h"
#include "SomaProgressBar.hpp"
#include "resource.h"
#include "Util.hpp"
#include <CeasaDllHeader.h>
#include <vector>
#include <tchar.h>
#include <limits>
#include <string>

IMPLEMENT_DYNAMIC(CMyDialog2, CMyDialog) // ← must be here!

// CMyDialog2::CMyDialog2(CWnd *pParent) : CMyDialog(IDD_MY_DIALOG1, pParent) {}

CMyDialog2::~CMyDialog2() {}

void CMyDialog2::OnBnClickedD2Button() { this->PostMessageW(WM_KEYDOWN, VK_RETURN, 0); }

afx_msg LRESULT CMyDialog2::OnDialogClosed(WPARAM wParam, LPARAM lParam) {
	if (m_pDlg && IsWindow(m_pDlg->GetSafeHwnd())) {
		m_pDlg->DestroyWindow(); // PostNcDestroy will delete the object
		m_pDlg = nullptr;
	}
	return 0;
}

BOOL CMyDialog2::PreTranslateMessage(MSG *pMsg) {
	if (pMsg->message == WM_KEYDOWN) {
		// SetDlgItemInt(IDC_D2_NUMEROSBOX, LOWORD(pMsg->wParam));
		if (LOWORD(pMsg->wParam) == VK_RETURN) {
			// HWND hEdit = GetDlgItem(IDC_D2_NUMEROSBOX)->GetSafeHwnd();
			if (GetFocus() == GetDlgItem(IDC_D2_NUMEROSBOX)) {
				GetDlgItem(IDC_D2_NUMEROSBOX)->SendMessage(EM_SETSEL, (WPARAM)-1, (LPARAM)-1);
				char force_new_line[] = { 0x0D, 0x00, 0x0A, 0x00, 0x00, 0x00 };
				GetDlgItem(IDC_D2_NUMEROSBOX)->SendMessage(EM_REPLACESEL, FALSE, (LPARAM)force_new_line);
			} else if (GetFocus() == GetDlgItem(IDC_D2_BUTTON)) {
				/*
				DIALOG BAR TESTE
				*/
				CSomaProgressBarDlg m_Progress;
				INT_PTR retcode = m_Progress.DoModal();
				// CSomaProgressBarDlg* m_pProgressDlg = new CSomaProgressBarDlg();
				// m_pProgressDlg->Create(IDD_SOMA_DIALOGBAR, this);
				// m_pProgressDlg->ShowWindow(SW_SHOW);

				// CSomaProgressBarDlg *m_Progress = new CSomaProgressBarDlg();
				// m_Progress->Create(IDD_SOMA_DIALOGBAR, this);
				// m_Progress->ShowWindow(SW_SHOW);
				return TRUE;
				/*
				DIALOG BAR TESTE
				*/

				CString numerosText;
				GetDlgItemText(IDC_D2_NUMEROSBOX, numerosText);
				std::unique_ptr<std::vector<CString>> words = parse_words(&numerosText);
				std::vector<double> lista{};
				lista.reserve(words->size());

				for (auto &w : *words) {
					lista.push_back(convert_brazilian_number_format(&w));
				}

				CString minimoText{};
				CString maximoText{};
				GetDlgItemText(IDC_D2_MINIMOBOX, minimoText);
				GetDlgItemText(IDC_D2_MAXIMOBOX, maximoText);

				double minimo = convert_brazilian_number_format(&minimoText);
				double maximo = convert_brazilian_number_format(&maximoText);

				double progress{ 0.0 };
				double *result;
				if (!achar_soma_lista_numeros(&lista, minimo, maximo, &result, &progress)) {
					AfxMessageBox(_T("Erro ao calcular as combinações."));
					return TRUE;
				}

				m_pDlg = nullptr;
				TRACE("======>PONTEIRO CRIADO: %lld\n", this);
				m_pDlg = new CShowSomaResults(this);
				m_pDlg->Create(IDD_SHOW_SOMA_RESULTS, this);
				m_pDlg->ShowWindow(SW_SHOW);

				CString total_combinações{};
				m_pDlg->m_listOutput.AddString(total_combinações);

				double *doubles_array = result;
				for (double soma = *doubles_array;
					 soma > std::numeric_limits<double>::min() + std::numeric_limits<double>::epsilon();
					 soma = *doubles_array) {
					doubles_array++;
					for (int number_of_arrays = *reinterpret_cast<int *>(doubles_array++); number_of_arrays > 0;
						 number_of_arrays--) {
						std::wstring combination_str;
						wchar_t buf[64];
						swprintf_s(buf, L"%.2f", soma);
						combination_str.append(buf);
						combination_str.append(L": ");

						while (*doubles_array >
							   std::numeric_limits<double>::min() + std::numeric_limits<double>::epsilon()) {
							swprintf_s(buf, L" %.2f +", *doubles_array++);
							combination_str.append(buf);
						}
						if (combination_str.back() == L'+') {
							combination_str.pop_back();
						}
						m_pDlg->m_listOutput.AddString(combination_str.c_str());
						doubles_array++;
					}
					m_pDlg->m_listOutput.AddString(_T("=========================="));
				}

				achar_soma_free_pointer();
				return TRUE;
			}

		} else if ((LOWORD(pMsg->wParam) >= '0' && LOWORD(pMsg->wParam) <= '9') ||
				   LOWORD(pMsg->wParam) == VK_OEM_COMMA || LOWORD(pMsg->wParam) == VK_OEM_PERIOD ||
				   LOWORD(pMsg->wParam) == VK_BACK || LOWORD(pMsg->wParam) == VK_DELETE ||
				   LOWORD(pMsg->wParam) == VK_LEFT || LOWORD(pMsg->wParam) == VK_RIGHT ||
				   LOWORD(pMsg->wParam) == VK_TAB || LOWORD(pMsg->wParam) == VK_F1 ||
				   pMsg->wParam == 'V' && (GetKeyState(VK_CONTROL) & 0x8000) ||
				   pMsg->wParam == 'C' && (GetKeyState(VK_CONTROL) & 0x8000)) {
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
	TRACE("Listening for message value: %d\n", WM_SOMA_DIALOG_CLOSED);
	CDialog::OnShowWindow(bShow, nStatus);

	if (bShow) {
		PostMessage(WM_NEXTDLGCTL, (WPARAM)GetDlgItem(IDC_D2_MINIMOBOX)->GetSafeHwnd(), TRUE);
		SetDlgItemTextW(IDC_D2_MINIMOBOX, _T("1.230,45"));
		SetDlgItemTextW(IDC_D2_MAXIMOBOX, _T("10.200,99"));
		SetDlgItemTextW(IDC_D2_NUMEROSBOX, _T("1,00 10,00 100,00\r\n1.000,00\r\n10.000,00\r\n"
											  "2,00 20,00 200,00\r\n2.000,00\r\n20.000,00\r\n"));
	}
}

BEGIN_MESSAGE_MAP(CMyDialog2, CMyDialog)
ON_WM_SHOWWINDOW()
ON_WM_MOVE()
ON_MESSAGE(WM_SOMA_DIALOG_CLOSED, &CMyDialog2::OnDialogClosed)
ON_BN_CLICKED(IDC_D2_BUTTON, &CMyDialog2::OnBnClickedD2Button)
END_MESSAGE_MAP()
