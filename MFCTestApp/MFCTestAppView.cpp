
// MFCTestAppView.cpp : implementation of the CMFCTestAppView class
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "MFCTestApp.h"
#endif

#include "MFCTestAppDoc.h"
#include "MFCTestAppView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFCTestAppView

IMPLEMENT_DYNCREATE(CMFCTestAppView, CView)

BEGIN_MESSAGE_MAP(CMFCTestAppView, CView)
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CMFCTestAppView::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
END_MESSAGE_MAP()

// CMFCTestAppView construction/destruction

CMFCTestAppView::CMFCTestAppView() noexcept
{
	// TODO: add construction code here

}

CMFCTestAppView::~CMFCTestAppView()
{
}

BOOL CMFCTestAppView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// CMFCTestAppView drawing

void CMFCTestAppView::OnDraw(CDC* /*pDC*/)
{
	CMFCTestAppDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: add draw code for native data here
}


// CMFCTestAppView printing


void CMFCTestAppView::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CMFCTestAppView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CMFCTestAppView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CMFCTestAppView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

void CMFCTestAppView::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CMFCTestAppView::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CMFCTestAppView diagnostics

#ifdef _DEBUG
void CMFCTestAppView::AssertValid() const
{
	CView::AssertValid();
}

void CMFCTestAppView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFCTestAppDoc* CMFCTestAppView::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFCTestAppDoc)));
	return (CMFCTestAppDoc*)m_pDocument;
}
#endif //_DEBUG


// CMFCTestAppView message handlers
