
// MFCTestAppDoc.cpp : implementation of the CMFCTestAppDoc class
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "MFCTestApp.h"
#endif

#include "MFCTestAppDoc.h"

#include <propkey.h>
#include "Add.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CMFCTestAppDoc

IMPLEMENT_DYNCREATE(CMFCTestAppDoc, CDocument)

BEGIN_MESSAGE_MAP(CMFCTestAppDoc, CDocument)
	ON_COMMAND(ID_TEST_ADD, &CMFCTestAppDoc::OnTestAdd)
END_MESSAGE_MAP()


// CMFCTestAppDoc construction/destruction

CMFCTestAppDoc::CMFCTestAppDoc() noexcept
{
	// TODO: add one-time construction code here

}

CMFCTestAppDoc::~CMFCTestAppDoc()
{
}

BOOL CMFCTestAppDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}




// CMFCTestAppDoc serialization

void CMFCTestAppDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: add storing code here
	}
	else
	{
		// TODO: add loading code here
	}
}

#ifdef SHARED_HANDLERS

// Support for thumbnails
void CMFCTestAppDoc::OnDrawThumbnail(CDC& dc, LPRECT lprcBounds)
{
	// Modify this code to draw the document's data
	dc.FillSolidRect(lprcBounds, RGB(255, 255, 255));

	CString strText = _T("TODO: implement thumbnail drawing here");
	LOGFONT lf;

	CFont* pDefaultGUIFont = CFont::FromHandle((HFONT) GetStockObject(DEFAULT_GUI_FONT));
	pDefaultGUIFont->GetLogFont(&lf);
	lf.lfHeight = 36;

	CFont fontDraw;
	fontDraw.CreateFontIndirect(&lf);

	CFont* pOldFont = dc.SelectObject(&fontDraw);
	dc.DrawText(strText, lprcBounds, DT_CENTER | DT_WORDBREAK);
	dc.SelectObject(pOldFont);
}

// Support for Search Handlers
void CMFCTestAppDoc::InitializeSearchContent()
{
	CString strSearchContent;
	// Set search contents from document's data.
	// The content parts should be separated by ";"

	// For example:  strSearchContent = _T("point;rectangle;circle;ole object;");
	SetSearchContent(strSearchContent);
}

void CMFCTestAppDoc::SetSearchContent(const CString& value)
{
	if (value.IsEmpty())
	{
		RemoveChunk(PKEY_Search_Contents.fmtid, PKEY_Search_Contents.pid);
	}
	else
	{
		CMFCFilterChunkValueImpl *pChunk = nullptr;
		ATLTRY(pChunk = new CMFCFilterChunkValueImpl);
		if (pChunk != nullptr)
		{
			pChunk->SetTextValue(PKEY_Search_Contents, value, CHUNK_TEXT);
			SetChunkValue(pChunk);
		}
	}
}

#endif // SHARED_HANDLERS

// CMFCTestAppDoc diagnostics

#ifdef _DEBUG
void CMFCTestAppDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CMFCTestAppDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CMFCTestAppDoc commands


void CMFCTestAppDoc::OnTestAdd()
{
	// TODO: Add your command handler code here
	Add dlg;
	dlg.DoModal();
}
