#include "MFCApplication.h"
#include "SimpleFrame.h"

MFCApplication theApp;

BOOL MFCApplication::InitInstance() {
	m_pMainWnd = new SimpleFrame();
	m_pMainWnd->ShowWindow(SW_SHOW);
	m_pMainWnd->UpdateWindow();
	return TRUE;
}