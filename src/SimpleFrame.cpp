#include "SimpleFrame.h"

#include "atlimage.h"
#include "gdiplus.h"

BEGIN_MESSAGE_MAP(SimpleFrame, CFrameWnd)
	ON_WM_CREATE()//
	ON_WM_SIZE()//
	ON_WM_SIZING()//
	ON_WM_ACTIVATE()//
	ON_WM_ACTIVATEAPP()//
	ON_WM_SHOWWINDOW()//
	ON_WM_PAINT()//
	ON_WM_SETFOCUS()//
	ON_WM_CLOSE()//
	ON_WM_LBUTTONDOWN()//
	ON_WM_RBUTTONDOWN()//
	ON_WM_WINDOWPOSCHANGED()
	//ON_WM_WINDOWPOSCHANGING()//
	//ON_WM_NCHITTEST()//
	ON_WM_GETMINMAXINFO()//
END_MESSAGE_MAP()

SimpleFrame::SimpleFrame() {
	Create(NULL, _T("Just a Simple Frame"), (WS_THICKFRAME | WS_SYSMENU | WS_MAXIMIZEBOX | WS_MINIMIZEBOX), CRect(0, 0, 16 * 80 + 20, 9 * 80 + 42), NULL);
}

int SimpleFrame::OnCreate(LPCREATESTRUCT lpCreateStruct) {
	TRACE("[LOG] SimpleFrame::OnCreate (+)\n");
	bool flag = false;
	if (CFrameWnd::OnCreate(lpCreateStruct) == 0) {
		//CMenu* pTopMenu = GetSystemMenu(FALSE);
		//if (pTopMenu != NULL)
		//{
		//	pTopMenu->RemoveMenu(SC_SIZE, MF_BYCOMMAND);      //Size
		//	pTopMenu->RemoveMenu(SC_MOVE, MF_BYCOMMAND);      //Move
		//	pTopMenu->RemoveMenu(SC_MAXIMIZE, MF_BYCOMMAND);  //Maximize
		//}
		//TRACE("[LOG] Window is created\n");
		flag = true;
	}
	if (!flag) TRACE("[LOG] Window creation failed!\n");
	TRACE("[LOG] SimpleFrame::OnCreate (+)\n");
	return flag ? 0 : -1;
}


void SimpleFrame::OnShowWindow(BOOL bShow, UINT nStatus) {
	CFrameWnd::OnShowWindow(SW_HIDE, nStatus);
	TRACE("[LOG] SimpleFrame::OnShowWindow (+)\n");
	TRACE("[LOG] Window is showed! %d\n", nStatus);
	TRACE("[LOG] SimpleFrame::OnShowWindow (-)\n");
}

void SimpleFrame::OnActivate(UINT nState, CWnd* pWndOther, BOOL bMinimized) {
	TRACE("[LOG] SimpleFrame::OnActivate (+)\n");

	CFrameWnd::OnActivate(nState, pWndOther, bMinimized);

	switch (nState) {
	case WA_ACTIVE:
		TRACE("[LOG] Window activated without mouse\n");
		break;
	case WA_INACTIVE:
		TRACE("[LOG] Window deactivated!\n");
		break;
	case WA_CLICKACTIVE:
		TRACE("[LOG] Window activated using mouse\n");
		break;
	}
	TRACE("[LOG] SimpleFrame::OnActivate (-)\n");
}

void SimpleFrame::OnPaint() {

	TRACE("[LOG] SimpleFrame::OnPaint (+)\n");

	CRect cRect, wRect;
	GetClientRect(cRect);
	TRACE("[LOG] [Client rect] left: %d top: %d right: %d bottom: %d\n", cRect.left, cRect.top, cRect.right, cRect.bottom);
	GetWindowRect(wRect);
	TRACE("[LOG] [Window rect] left: %d top: %d right: %d bottom: %d\n", wRect.left, wRect.top, wRect.right, wRect.bottom);

	CPaintDC dc(AfxGetMainWnd());
	int margin_cnt = 2;
	for (int i = 0; i < margin_cnt; i++) {
		dc.Draw3dRect(cRect, RGB(255, 0, 0), RGB(255, 0, 0));
		cRect.DeflateRect(1, 1);
	}

	//CImage ci;
	//ci.Load(_T("test.jpg"));

	//HDC hdc = *(AfxGetMainWnd()->GetDC());
	//ci.Draw(hdc, margin_cnt, margin_cnt, cRect.right - margin_cnt, cRect.bottom - margin_cnt);
	CFrameWnd::OnPaint();
	TRACE("[LOG] SimpleFrame::OnPaint (-)\n");
}

void SimpleFrame::OnLButtonDown(UINT nFlags, CPoint point) {
	TRACE("[LOG] Left Click at (%d, %d)\n", point.x, point.y);
}

void SimpleFrame::OnRButtonDown(UINT nFlags, CPoint point) {
	TRACE("[LOG] Right Click at (%d, %d)\n", point.x, point.y);
}

void SimpleFrame::OnSize(UINT nType, int cx, int cy) {
	CFrameWnd::OnSize(nType, cx, cy);
	TRACE("[LOG] SimpleFrame::OnSize (+)\n");

	TRACE("[LOG] [Size Changed] %d %d %d\n", nType, cx, cy);

	TRACE("[LOG] SimpleFrame::OnSize (-)\n");
}

void SimpleFrame::OnGetMinMaxInfo(MINMAXINFO* lpMMI) {
	CFrameWnd::OnGetMinMaxInfo(lpMMI);
	TRACE("[LOG] SimpleFrame::OnGetMinMaxInfo (+)\n");

	lpMMI->ptMinTrackSize.x = 16 * 40 + 20;
	lpMMI->ptMinTrackSize.y = 9 * 40 + 42;

	TRACE("[LOG] SimpleFrame::OnGetMinMaxInfo (-)\n");

}

//void SimpleFrame::OnWindowPosChanging(WINDOWPOS* lpwndpos){
//	TRACE("[LOG] SimpleFrame::OnWindowPosChanging (+)\n");
//	TRACE("[LOG] SimpleFrame::OnWindowPosChanging (-)\n");
//	//TRACE("[%s] %d %d %d %d\n", __FUNCTIONW__, lpwndpos->x, lpwndpos->y, lpwndpos->cx, lpwndpos->cy);
//	//LPWINDOWPOS   pwndpos;  
//
//	//pwndpos = (LPWINDOWPOS)lParam;  
//
//	//pwndpos |= (SWP_NOMOVE | SWP_NOSIZE);  
//	//return (CWnd::OnWindowPosChanging(wParam, lParam)); 
//}

void SimpleFrame::OnWindowPosChanged(WINDOWPOS* lpwndpos) {
	CFrameWnd::OnWindowPosChanged(lpwndpos);
	TRACE("[LOG] SimpleFrame::OnWindowPosChanged (+)\n");
	TRACE("[LOG] SimpleFrame::OnWindowPosChanged (-)\n");
}

LRESULT SimpleFrame::OnNcHitTest(CPoint point)
{
	TRACE("[LOG] SimpleFrame::OnNcHitTest (+)\n");
	TRACE("[LOG] SimpleFrame::OnNcHitTest (-)\n");

	// TODO: Add your message handler code here and/or call default
	LRESULT res = CFrameWnd::OnNcHitTest(point);
	//if( res == HTCAPTION)
	//	res = HTNOWHERE;
	return res;
}


void SimpleFrame::OnSizing(UINT nSide, LPRECT lpRect) {
	CFrameWnd::OnSizing(nSide, lpRect);
	TRACE("[LOG] SimpleFrame::OnSizing (+)\n");
	TRACE("[LOG] SimpleFrame::OnSizing (-)\n");
}

void SimpleFrame::OnActivateApp(BOOL bActive, DWORD dwThreadID) {
	CFrameWnd::OnActivateApp(bActive, dwThreadID);
	TRACE("[LOG] SimpleFrame::OnActivateApp (+)\n");
	TRACE("bActive: %d, dwThreadID: %d\n", bActive, dwThreadID);
	TRACE("[LOG] SimpleFrame::OnActivateApp (-)\n");
}

void SimpleFrame::OnSetFocus(CWnd* pOldWnd) {
	CFrameWnd::OnSetFocus(pOldWnd);
	TRACE("[LOG] SimpleFrame::OnSetFocus (+)\n");
	TRACE("[LOG] SimpleFrame::OnSetFocus (-)\n");
}

void SimpleFrame::OnClose() {
	CFrameWnd::OnClose();
	TRACE("[LOG] SimpleFrame::OnClose (+)\n");
	TRACE("[LOG] SimpleFrame::OnClose (-)\n");
}
