/////////////////////////////////////////////////////////////////////////////
// Name:        control.cpp
// Purpose:     wxControl class
// Author:      AUTHOR
// Modified by:
// Created:     ??/??/98
// RCS-ID:      $Id$
// Copyright:   (c) AUTHOR
// Licence:   	wxWindows licence
/////////////////////////////////////////////////////////////////////////////

#ifdef __GNUG__
#pragma implementation "control.h"
#endif

#include "wx/control.h"
#include "wx/notebook.h"
#include "wx/tabctrl.h"
#include "wx/spinbutt.h"

#if !USE_SHARED_LIBRARY
IMPLEMENT_ABSTRACT_CLASS(wxControl, wxWindow)

BEGIN_EVENT_TABLE(wxControl, wxWindow)
	EVT_MOUSE_EVENTS( wxControl::OnMouseEvent ) 
	EVT_CHAR( wxControl::OnKeyDown ) 
	EVT_PAINT( wxControl::OnPaint ) 
END_EVENT_TABLE()
#endif

#include <wx/mac/uma.h>

// Item members

ControlActionUPP wxMacLiveScrollbarActionUPP = NULL ;

pascal void wxMacLiveScrollbarActionProc( ControlHandle control , ControlPartCode partCode )
{
	if ( partCode != 0)
	{
		wxControl*	wx = (wxControl*) GetControlReference( control ) ;
		if ( wx )
		{
			wx->MacHandleControlClick( control , partCode ) ;
		}
	}
}

wxControl::wxControl()
{
		m_macControl = NULL ;
		m_macHorizontalBorder = 0 ; // additional pixels around the real control
		m_macVerticalBorder = 0 ;
    m_backgroundColour = *wxWHITE;
    m_foregroundColour = *wxBLACK;
    m_callback = 0;

	if ( wxMacLiveScrollbarActionUPP == NULL )
	{
		wxMacLiveScrollbarActionUPP = NewControlActionProc( wxMacLiveScrollbarActionProc ) ;
	}
}

wxControl::~wxControl()
{
    // If we delete an item, we should initialize the parent panel,
    // because it could now be invalid.
    wxWindow *parent = (wxWindow *)GetParent();
    if (parent)
    {
        if (parent->GetDefaultItem() == (wxButton*) this)
            parent->SetDefaultItem(NULL);
    }
    if ( m_macControl )
    {
    	UMADisposeControl( m_macControl ) ;
    	m_macControl = NULL ;
    }
}

void wxControl::SetLabel(const wxString& label)
{
	m_label = label ;

	if ( m_macControl )
	{
		Str255 maclabel ;
		
		strcpy( (char*) maclabel , label ) ;
		c2pstr( (char*) maclabel ) ;
	
		::SetControlTitle( m_macControl , maclabel ) ;
	}
}

wxString wxControl::GetLabel() const
{
    return m_label ;
}

void wxControl::ProcessCommand (wxCommandEvent & event)
{
  // Tries:
  // 1) A callback function (to become obsolete)
  // 2) OnCommand, starting at this window and working up parent hierarchy
  // 3) OnCommand then calls ProcessEvent to search the event tables.
  if (m_callback)
    {
      (void) (*(m_callback)) (*this, event);
    }
    else
    {
      GetEventHandler()->OnCommand(*this, event);
    }
}

void wxControl::Centre (int direction)
{
  int x, y, width, height, panel_width, panel_height, new_x, new_y;

  wxWindow *parent = (wxWindow *) GetParent ();
  if (!parent)
    return;

  parent->GetClientSize (&panel_width, &panel_height);
  GetSize (&width, &height);
  GetPosition (&x, &y);

  new_x = x;
  new_y = y;

  if (direction & wxHORIZONTAL)
    new_x = (int) ((panel_width - width) / 2);

  if (direction & wxVERTICAL)
    new_y = (int) ((panel_height - height) / 2);

  SetSize (new_x, new_y, width, height);
}

void wxControl::SetClientSize (int width, int height)
{
  SetSize (-1, -1, width, height);
}

// ------------------------
wxList *wxWinMacControlList = NULL;
wxControl *wxFindControlFromMacControl(ControlHandle inControl )
{
    wxNode *node = wxWinMacControlList->Find((long)inControl);
    if (!node)
        return NULL;
    return (wxControl *)node->Data();
}

void wxAssociateControlWithMacControl(ControlHandle inControl, wxControl *control)
{
    // adding NULL WindowRef is (first) surely a result of an error and
    // (secondly) breaks menu command processing
    wxCHECK_RET( inControl != (ControlHandle) NULL, "attempt to add a NULL WindowRef to window list" );

    if ( !wxWinMacControlList->Find((long)inControl) )
        wxWinMacControlList->Append((long)inControl, control);
}

void wxRemoveMacControlAssociation(wxControl *control)
{
    wxWinMacControlList->DeleteObject(control);
}

void wxControl::MacPreControlCreate( wxWindow *parent, wxWindowID id, wxString label , 
			 const wxPoint& pos,
			 const wxSize& size, long style,
			 const wxValidator& validator,
			 const wxString& name , Rect *outBounds , StringPtr maclabel ) 
{
	m_label = label ;
  SetName(name);
  if ( &validator )
  	SetValidator(validator);

  m_windowStyle = style;
  parent->AddChild((wxButton *)this);

  m_backgroundColour = parent->GetBackgroundColour() ;
  m_foregroundColour = parent->GetForegroundColour() ;

  if (id == -1)
      m_windowId = NewControlId();
  else
      m_windowId = id;

	m_width = size.x ;
	m_height = size.y ;
	int x = pos.x ;
	int y = pos.y ;
	AdjustForParentClientOrigin(x, y, wxSIZE_USE_EXISTING);
	m_x = x ;
	m_y = y ;
		

	Point localOrigin ;
	Rect	clipRect ;
	
	parent->MacClientToRootWindow( &x , &y ) ;
	outBounds->top = y + m_macVerticalBorder ;
	outBounds->left = x + m_macHorizontalBorder ;
	outBounds->bottom = outBounds->top + m_height - 2 * m_macVerticalBorder;
	outBounds->right = outBounds->left + m_width - 2 * m_macHorizontalBorder ;

	strcpy( (char*) maclabel , label ) ;
	if( wxApp::s_macDefaultEncodingIsPC )
	{
		wxMacConvertFromPCForControls( (char*) maclabel ) ;
	}

	c2pstr( (char*) maclabel ) ;
}

void wxControl::MacPostControlCreate()
{
	wxASSERT_MSG( m_macControl != NULL , "No valid mac control" ) ;
	
	if ( IsKindOf( CLASSINFO( wxScrollBar ) ) )
	{
		// no font
	}
	else if ( IsKindOf( CLASSINFO( wxStaticBox ) ) )
	{
		ControlFontStyleRec		controlstyle ;
		controlstyle.flags = kControlUseFontMask ;
		controlstyle.font = kControlFontSmallBoldSystemFont ;
		
		::UMASetControlFontStyle( m_macControl , &controlstyle ) ;
	}
	else
	{
		ControlFontStyleRec		controlstyle ;
		controlstyle.flags = kControlUseFontMask ;
		controlstyle.font = kControlFontSmallSystemFont ;
		
		::UMASetControlFontStyle( m_macControl , &controlstyle ) ;
	}
	ControlHandle container = GetParent()->MacGetContainerForEmbedding() ;
	wxASSERT_MSG( container != NULL , "No valid mac container control" ) ;
	::UMAEmbedControl( m_macControl , container ) ;
	MacAdjustControlRect() ;
	wxAssociateControlWithMacControl( m_macControl , this ) ;
}

void wxControl::MacAdjustControlRect() 
{
	wxASSERT_MSG( m_macControl != NULL , "No valid mac control" ) ;
	if ( m_width == -1 || m_height == -1 )
	{
		Rect 	bestsize = { 0 , 0 , 0 , 0 } ;
		short	baselineoffset ;
		
		UMAGetBestControlRect( m_macControl , &bestsize , &baselineoffset ) ;

		if ( EmptyRect( &bestsize ) )
		{
			baselineoffset = 0;
			bestsize.left = bestsize.top = 0 ;
			bestsize.right = 16 ;
			bestsize.bottom = 16 ;
			if ( IsKindOf( CLASSINFO( wxScrollBar ) ) )
			{
				bestsize.bottom = 16 ;
			}
			else if ( IsKindOf( CLASSINFO( wxSpinButton ) ) )
			{
				bestsize.bottom = 24 ; 
			}
		}

		if ( m_width == -1 )
		{
			if ( IsKindOf( CLASSINFO( wxButton ) ) )
			{
				m_width = m_label.Length() * 8 + 12 + 2 * m_macHorizontalBorder;
			}
			else if ( IsKindOf( CLASSINFO( wxStaticText ) ) )
			{
				m_width = m_label.Length() * 8 ;
			}
			else
				m_width = bestsize.right - bestsize.left + 2 * m_macHorizontalBorder;
		}
		if ( m_height == -1 )
		{
			m_height = bestsize.bottom - bestsize.top ;
			if ( m_height < 10 )
				m_height = 13 ;

			m_height += 2 * m_macVerticalBorder;
		}
		
		wxMacDrawingHelper helper ( wxFindWinFromMacWindow( GetMacRootWindow() ) ) ;
		if ( helper.Ok() )
		{
	    UMASizeControl( m_macControl , m_width - 2 * m_macHorizontalBorder, m_height -  2 * m_macVerticalBorder ) ;
  		}
	}
}
ControlHandle wxControl::MacGetContainerForEmbedding() 
{
	if ( m_macControl )
		return m_macControl ;

	return wxWindow::MacGetContainerForEmbedding() ;
}

void wxControl::MacSuperChangedPosition() 
{
	if ( m_macControl )
	{
		int former_mac_x = (**m_macControl).contrlRect.left ;
		int former_mac_y = (**m_macControl).contrlRect.top ;
		int mac_x = m_x ;
		int mac_y = m_y ;
		GetParent()->MacClientToRootWindow( & mac_x , & mac_y ) ;
		
		WindowRef rootwindow = GetMacRootWindow() ;
		wxWindow* wxrootwindow = wxFindWinFromMacWindow( rootwindow ) ;
		UMASetThemeWindowBackground( rootwindow , kThemeBrushDialogBackgroundActive , false ) ;
		wxMacDrawingHelper focus( wxrootwindow ) ;
	
		if ( mac_x != former_mac_x || mac_y != former_mac_y )
		{
			{
				Rect inval = { former_mac_y , former_mac_x , former_mac_y + m_height , former_mac_x + m_width } ;
				InvalRect( &inval ) ;
			}
	  	UMAMoveControl( m_macControl , mac_x + m_macHorizontalBorder , mac_y + m_macVerticalBorder ) ;
			{
				Rect inval = { mac_y , mac_x , mac_y + m_height , mac_x + m_width } ;
				InvalRect( &inval ) ;
			}
		}
		if ( wxrootwindow->IsKindOf( CLASSINFO( wxDialog ) ) )
		{
		}
		else
		{
			UMASetThemeWindowBackground( rootwindow , kThemeBrushDocumentWindowBackground , false ) ;
		}
	}

	wxWindow::MacSuperChangedPosition() ;
}

void wxControl::MacSuperEnabled( bool enabled ) 
{
	if ( m_macControl )
	{
		if ( UMAHasAppearance() )
		{
			if ( !enabled )
			{
				::DeactivateControl( m_macControl ) ; 
			}
			else
			{
				if ( m_macEnabled )
					::ActivateControl( m_macControl ) ;
			}
		}
		else
		{
			if ( !enabled )
			{
				::HiliteControl( m_macControl , 255 ) ;
			}
			else
			{
				if ( m_macEnabled )
					::HiliteControl( m_macControl , 0 ) ;
			}
		}
	}
	wxWindow::MacSuperEnabled( enabled ) ;
}

void  wxControl::MacSuperShown( bool show ) 
{
	if ( m_macControl )
	{
		if ( !show )
		{
			::UMAHideControl( m_macControl ) ;
		}
		else
		{
			if ( m_macShown )
				::UMAShowControl( m_macControl ) ;
		}
	}
		
	wxWindow::MacSuperShown( show ) ;
}

void  wxControl::DoSetSize(int x, int y,
            int width, int height,
            int sizeFlags )
{
	if ( m_macControl == NULL )
	{
		wxWindow::DoSetSize( x , y ,width , height ,sizeFlags ) ;
		return ;
	}

	WindowRef rootwindow = GetMacRootWindow() ;
	wxWindow* wxrootwindow = wxFindWinFromMacWindow( rootwindow ) ;
	UMASetThemeWindowBackground( rootwindow , kThemeBrushDialogBackgroundActive , false ) ;
		
	int former_x = m_x ;
	int former_y = m_y ;
	int former_w = m_width ;
	int former_h = m_height ;
	
	int former_mac_x = (**m_macControl).contrlRect.left ;
	int former_mac_y = (**m_macControl).contrlRect.top ;
	
  int currentX, currentY;
  GetPosition(&currentX, &currentY);
  int currentW,currentH;
  GetSize(&currentW, &currentH);

  int actualWidth = width;
  int actualHeight = height;
  int actualX = x;
  int actualY = y;
  if (x == -1 || (sizeFlags & wxSIZE_ALLOW_MINUS_ONE))
      actualX = currentX;
  if (y == -1 || (sizeFlags & wxSIZE_ALLOW_MINUS_ONE))
      actualY = currentY;
  if (width == -1)
      actualWidth = currentW ;
  if (height == -1)
      actualHeight = currentH ;

	if ( actualX == currentX && actualY == currentY && actualWidth == currentW && actualHeight == currentH)
		return ;
		
	AdjustForParentClientOrigin(actualX, actualY, sizeFlags);
	wxMacDrawingHelper focus( wxFindWinFromMacWindow( GetMacRootWindow() ) ) ;

	int mac_x = actualX ;
	int mac_y = actualY ;
	GetParent()->MacClientToRootWindow( & mac_x , & mac_y ) ;
	
	if ( mac_x != former_mac_x || mac_y != former_mac_y )
	{
		{
			Rect inval = { former_mac_y , former_mac_x , former_mac_y + m_height , former_mac_x + m_width } ;
			InvalRect( &inval ) ;
		}
  	UMAMoveControl( m_macControl , mac_x + m_macHorizontalBorder , mac_y  + m_macVerticalBorder ) ;
		{
			Rect inval = { mac_y , mac_x , mac_y + m_height , mac_x + m_width } ;
			InvalRect( &inval ) ;
		}
	}

	if ( actualX != former_x || actualY != former_y )
	{
		m_x = actualX ;
		m_y = actualY ;

		MacRepositionScrollBars() ;
		// To consider -> should the parameters be the effective or the virtual coordinates (AdjustForParent..)
    wxMoveEvent event(wxPoint(m_x, m_y), m_windowId);
    event.SetEventObject(this);
    GetEventHandler()->ProcessEvent(event);
	}		
	if ( actualWidth != former_w || actualHeight != former_h )
	{
		{
			Rect inval = { mac_y , mac_x , mac_y + former_h , mac_x + former_w } ;
			InvalRect( &inval ) ;
		}
		m_width = actualWidth ;
		m_height = actualHeight ;

   	UMASizeControl( m_macControl ,  m_width - 2 * m_macHorizontalBorder, m_height -  2 * m_macVerticalBorder ) ;
		{
			Rect inval = { mac_y , mac_x , mac_y + m_height , mac_x + m_width } ;
			InvalRect( &inval ) ;
		}

		MacRepositionScrollBars() ;
    wxSizeEvent event(wxSize(m_width, m_height), m_windowId);
    event.SetEventObject(this);
    GetEventHandler()->ProcessEvent(event);
	}
	if ( wxrootwindow->IsKindOf( CLASSINFO( wxDialog ) ) )
	{
	}
	else
	{
		UMASetThemeWindowBackground( rootwindow , kThemeBrushDocumentWindowBackground , false ) ;
	}
}

void  wxControl::DoSetClientSize(int width, int height)
{
	DoSetSize( -1 , -1 , width , height ) ;
}

bool  wxControl::Show(bool show) 
{
	if ( m_macControl == NULL )
		return wxWindow::Show( show ) ;
	
	if ( m_macShown == show )
		return TRUE ;

	if ( show )
		::UMAShowControl( m_macControl ) ;
	else
		::UMAHideControl( m_macControl ) ;

	return wxWindow::Show( show ) ;
}

void  wxControl::Enable(bool enable) 
{
	if ( m_macControl == NULL )
		return wxWindow::Enable( enable ) ;
	
	if ( m_macEnabled == enable )
		return ;

	if ( UMAHasAppearance() )
	{
		if ( enable )
			::ActivateControl( m_macControl ) ;
		else
			::DeactivateControl( m_macControl ) ;
	}
	else
	{
		if ( enable )
			::HiliteControl( m_macControl , 0 ) ;
		else
			::HiliteControl( m_macControl , 255 ) ;
	}

	return wxWindow::Enable( enable ) ;
}

void wxControl::Refresh(bool eraseBack, const wxRect *rect)
{
  if ( m_macControl )
  {
  	wxWindow::Refresh( eraseBack , rect ) ;
	}
  else
  {
  	wxWindow::Refresh( eraseBack , rect ) ;
  }
}

void wxControl::OnPaint(wxPaintEvent& event)
{
	if ( m_macControl )
	{
		WindowRef window = GetMacRootWindow() ;
		if ( window )
		{
			wxWindow* win = wxFindWinFromMacWindow( window ) ;
			if ( win )
			{
				wxMacDrawingHelper help( win ) ;
				SetOrigin( 0 , 0 ) ;
				
				bool			hasTabBehind = false ;
				wxWindow* parent = GetParent() ;
				while ( parent )
				{
					if( parent->m_macWindowData )
					{
						UMASetThemeWindowBackground( win->m_macWindowData->m_macWindow , kThemeBrushDialogBackgroundActive , false ) ;
						break ;
					}
					
					if( parent->IsKindOf( CLASSINFO( wxNotebook ) ) ||  parent->IsKindOf( CLASSINFO( wxTabCtrl ) ))
					{
						if ( ((wxControl*)parent)->m_macControl )
							SetUpControlBackground( ((wxControl*)parent)->m_macControl , -1 , true ) ;
						break ;
					}
					
					parent = parent->GetParent() ;
				} 
				
				UMADrawControl( m_macControl ) ;
				UMASetThemeWindowBackground( win->m_macWindowData->m_macWindow , win->m_macWindowData->m_macWindowBackgroundTheme , false ) ;
			}
		}
	}
	else
	{
		wxWindow::OnPaint( event ) ;
	}
}

void  wxControl::OnKeyDown( wxKeyEvent &event ) 
{
	if ( m_macControl == NULL )
		return ;
	
	EventRecord *ev = wxTheApp->MacGetCurrentEvent() ;
	short keycode ;
	short keychar ;
	keychar = short(ev->message & charCodeMask);
	keycode = short(ev->message & keyCodeMask) >> 8 ;

	UMAHandleControlKey( m_macControl , keycode , keychar , ev->modifiers ) ;
}

void  wxControl::OnMouseEvent( wxMouseEvent &event ) 
{
	if ( m_macControl == NULL )
	{
		event.Skip() ;
		return ;
	}
		
	if (event.GetEventType() == wxEVT_LEFT_DOWN )
	{
			
		int x = event.m_x ;
		int y = event.m_y ;
		
		MacClientToRootWindow( &x , &y ) ;
			
		ControlHandle	control ;
		Point		localwhere ;
		GrafPtr		port ;
		SInt16		controlpart ;
		WindowRef	window = GetMacRootWindow() ;
		
		localwhere.h = x ;
		localwhere.v = y ;
	
		short modifiers = 0;
		
		if ( !event.m_leftDown && !event.m_rightDown )
			modifiers  |= btnState ;
	
		if ( event.m_shiftDown )
			modifiers |= shiftKey ;
			
		if ( event.m_controlDown )
			modifiers |= controlKey ;
	
		if ( event.m_altDown )
			modifiers |= optionKey ;
	
		if ( event.m_metaDown )
			modifiers |= cmdKey ;
	
		controlpart = FindControl( localwhere , window , &control ) ;
		{
			if ( AcceptsFocus() && FindFocus() != this )
			{
				SetFocus() ;
			}
			if ( control && UMAIsControlActive( control ) )
			{
				{
					if ( controlpart == kControlIndicatorPart && !UMAHasAppearance() )
						controlpart = UMAHandleControlClick( control , localwhere , modifiers , (ControlActionUPP) NULL ) ;
					else
						controlpart = UMAHandleControlClick( control , localwhere , modifiers , (ControlActionUPP) -1 ) ;
					wxTheApp->s_lastMouseDown = 0 ;
					if ( controlpart && ! ( ( UMAHasAppearance() || (controlpart != kControlIndicatorPart) ) 
						&& (IsKindOf( CLASSINFO( wxScrollBar ) ) ) ) ) // otherwise we will get the event twice
					{
						MacHandleControlClick( control , controlpart ) ;
					}
				}
			}
		}
	}
}

bool wxControl::MacCanFocus() const
{
		{ if ( m_macControl == NULL ) 
				return true ; 
			else
			return false ; 
		}
}

void wxControl::MacHandleControlClick( ControlHandle control , SInt16 controlpart ) 
{
	wxASSERT_MSG( m_macControl != NULL , "No valid mac control" ) ;
}

