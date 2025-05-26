
// BarTsSegmentView.cpp: CBarTsSegmentView 类的实现
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "BarTsSegment.h"
#endif

#include "BarTsSegmentDoc.h"
#include "BarTsSegmentView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CBarTsSegmentView

IMPLEMENT_DYNCREATE(CBarTsSegmentView, CView)

BEGIN_MESSAGE_MAP(CBarTsSegmentView, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CBarTsSegmentView::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
END_MESSAGE_MAP()

// CBarTsSegmentView 构造/析构

CBarTsSegmentView::CBarTsSegmentView() noexcept
{
	// TODO: 在此处添加构造代码

}

CBarTsSegmentView::~CBarTsSegmentView()
{
}

BOOL CBarTsSegmentView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CBarTsSegmentView 绘图

void CBarTsSegmentView::OnDraw(CDC* /*pDC*/)
{
	CBarTsSegmentDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
}


// CBarTsSegmentView 打印


void CBarTsSegmentView::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CBarTsSegmentView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CBarTsSegmentView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void CBarTsSegmentView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}

void CBarTsSegmentView::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CBarTsSegmentView::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CBarTsSegmentView 诊断

#ifdef _DEBUG
void CBarTsSegmentView::AssertValid() const
{
	CView::AssertValid();
}

void CBarTsSegmentView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CBarTsSegmentDoc* CBarTsSegmentView::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CBarTsSegmentDoc)));
	return (CBarTsSegmentDoc*)m_pDocument;
}
#endif //_DEBUG


// CBarTsSegmentView 消息处理程序
