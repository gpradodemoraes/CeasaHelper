#include "pch.h"
#include "CMyDialog2.h"
#include "resource.h"
#include "ShowSomaResults.h"
#include "Util.hpp"
#include <CeasaDllHeader.h>
#include <vector>
#include <tchar.h>
#include <limits>

IMPLEMENT_DYNAMIC(CMyDialog2, CMyDialog) // ← must be here!

// CMyDialog2::CMyDialog2(CWnd *pParent) : CMyDialog(IDD_MY_DIALOG1, pParent) {}

CMyDialog2::~CMyDialog2() {}

void CMyDialog2::OnBnClickedD2Button() { this->PostMessageW(WM_KEYDOWN, VK_RETURN, 0); }

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

				CShowSomaResults *m_pDlg = nullptr;
				m_pDlg = new CShowSomaResults(this);
				m_pDlg->Create(IDD_SHOW_SOMA_RESULTS, this);
				m_pDlg->ShowWindow(SW_SHOW);

				CString total_combinações{};
				total_combinações.Format(_T("010-Total de combinações: %d"), static_cast<int>(result[0]));
				m_pDlg->m_listOutput.AddString(total_combinações);
				m_pDlg->m_listOutput.AddString(_T("020-Progresso: 0%"));
				m_pDlg->m_listOutput.AddString(_T("030-Último a entrar!"));

				double *doubles_array = result;
				for (double soma = *doubles_array;
					 soma > std::numeric_limits<double>::min() + std::numeric_limits<double>::epsilon();
					 soma = *doubles_array) {
					doubles_array++;
					for (int number_of_arrays = *reinterpret_cast<int *>(doubles_array++); number_of_arrays > 0;
						 number_of_arrays--) {
						std::wstring combination_str;
						combination_str.append(std::to_wstring(soma));
						combination_str.append(L": ");

						while (*doubles_array >
							   std::numeric_limits<double>::min() + std::numeric_limits<double>::epsilon()) {
							combination_str.append(L" ");
							combination_str.append(std::to_wstring(*doubles_array++));
							combination_str.append(L" +");
						}
						m_pDlg->m_listOutput.AddString(combination_str.c_str());
						doubles_array++;
					}
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
	CDialog::OnShowWindow(bShow, nStatus);

	if (bShow) {
		PostMessage(WM_NEXTDLGCTL, (WPARAM)GetDlgItem(IDC_D2_MINIMOBOX)->GetSafeHwnd(), TRUE);
		SetDlgItemTextW(IDC_D2_MINIMOBOX, _T("1.230,45"));
		SetDlgItemTextW(IDC_D2_MAXIMOBOX, _T("10.200,99"));
		SetDlgItemTextW(IDC_D2_NUMEROSBOX, _T("1,00 10,00 100,00\r\n1.000,00\r\n10.000,00\r\n"
											  "2,00 20,00 200,00\r\n2.000,00\r\n20.000,00\r\n"));
	}
}

BEGIN_MESSAGE_MAP(CMyDialog2, CDialog) // ← must be here!
ON_WM_KEYDOWN()
ON_WM_SHOWWINDOW()
ON_BN_CLICKED(IDC_D2_BUTTON, &CMyDialog2::OnBnClickedD2Button)
END_MESSAGE_MAP()
