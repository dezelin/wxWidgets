/////////////////////////////////////////////////////////////////////////////
// Name:        tbtest.cpp
// Purpose:     wxTaskBarIcon demo
// Author:      Julian Smart
// Modified by: Ryan Norton (Drawer)
// Created:     01/02/97
// RCS-ID:      $Id$
// Copyright:   (c)
// Licence:     wxWindows licence
/////////////////////////////////////////////////////////////////////////////

// For compilers that support precompilation, includes "wx.h".
#include "wx/wxprec.h"

#ifdef __BORLANDC__
#pragma hdrstop
#endif

#ifndef WX_PRECOMP
#include "wx/wx.h"
#endif

// the application icon (under Windows and OS/2 it is in resources)
#if defined(__WXGTK__) || defined(__WXMOTIF__) || defined(__WXMAC__) || defined(__WXMGL__) || defined(__WXX11__)
    #include "../sample.xpm"
#endif

#include "smile.xpm"

#include "wx/taskbar.h"

#if defined(__WXMAC__)
#include "wx/mac/private.h"
#endif

//include this sample's header
#include "drawertest.h"


#if USE_DRAWER_CODE

//drawer
#include "wx/dcclient.h"
#include "wx/mac/carbon/drawer.h"

class MyDrawer : public wxDrawerWindow
{
    public:
    MyDrawer(wxWindow* p) : wxDrawerWindow(p, wxID_ANY, wxT(""), wxSize(200,200))
    { }

    void OnPaint(wxPaintEvent&)
    {
        wxPaintDC dc(this);
        dc.DrawRectangle(30,30,60,60);
    }

    DECLARE_EVENT_TABLE()
};

BEGIN_EVENT_TABLE(MyDrawer, wxDrawerWindow)
    EVT_PAINT(MyDrawer::OnPaint)
END_EVENT_TABLE()

#endif // USE_DRAWER_CODE

MyDialog   *dialog = NULL;

IMPLEMENT_APP(MyApp)

bool MyApp::OnInit(void)
{
    // Create the main frame window
    dialog = new MyDialog(NULL, wxID_ANY, wxT("wxTaskBarIcon Test Dialog"), wxDefaultPosition, wxSize(365, 290));

    dialog->Show(true);

    return true;
}


BEGIN_EVENT_TABLE(MyDialog, wxDialog)
    EVT_BUTTON(wxID_OK, MyDialog::OnOK)
    EVT_BUTTON(wxID_EXIT, MyDialog::OnExit)
    EVT_CLOSE(MyDialog::OnCloseWindow)
END_EVENT_TABLE()



MyDialog::MyDialog(wxWindow* parent, const wxWindowID id, const wxString& title,
    const wxPoint& pos, const wxSize& size, const long windowStyle):
  wxDialog(parent, id, title, pos, size, windowStyle)
{
    Init();
}

MyDialog::~MyDialog()
{
    delete m_taskBarIcon;
}

void MyDialog::OnOK(wxCommandEvent& WXUNUSED(event))
{
    Show(false);
}

void MyDialog::OnExit(wxCommandEvent& WXUNUSED(event))
{
    Close(true);
}

void MyDialog::OnCloseWindow(wxCloseEvent& WXUNUSED(event))
{
    Destroy();
}

void MyDialog::Init(void)
{
    wxBoxSizer *sizer = new wxBoxSizer(wxVERTICAL);

    const int margin = 10;
    sizer->Add( new wxStaticText(this,
                                 wxID_ANY,
                                 _T("Press 'Hide me' to hide me, Exit to quit.")
                                ),
                0,
                wxALL | wxALIGN_LEFT ,
                margin
              );

    sizer->Add( new wxStaticText(this,
                                 wxID_ANY,
                                 _T("Double-click on the taskbar icon to show me again.")
                                ),
                0,
                wxALL | wxALIGN_LEFT ,
                margin
              );

    wxBoxSizer *sizer_bottom = new wxBoxSizer(wxHORIZONTAL);

    sizer_bottom->Add( new wxButton(this,
                                    wxID_EXIT,
                                    _T("Exit")
                                   ),
                       0,
                       wxALL | wxALIGN_RIGHT ,
                       margin
                     );

    wxButton *ok = new wxButton(this, wxID_OK, _T("Hide me"));

    sizer_bottom->Add( ok,
                       0,
                       wxALL | wxALIGN_LEFT ,
                       margin
                     );

    sizer->Add( sizer_bottom, 0, wxALIGN_CENTER );

    ok->SetDefault();

    SetSizerAndFit(sizer);

    Centre(wxBOTH);

#if USE_DRAWER_CODE

    MacSetMetalAppearance(true);
    Show(TRUE);

    MyDrawer* pMyDrawer = new MyDrawer(this);
    pMyDrawer->Open(true);

    m_taskBarIcon = new MyTaskBarIcon(pMyDrawer);

#else

    m_taskBarIcon = new MyTaskBarIcon();

#endif // USE_DRAWER_CODE/!USE_DRAWER_CODE

    if (!m_taskBarIcon->SetIcon(wxICON(sample), wxT("wxTaskBarIcon Sample")))
        wxMessageBox(wxT("Could not set icon."));
}


enum {
    PU_RESTORE = 10001,

    PU_NEW_ICON,
    PU_OLD_ICON,

    PU_OPEN_DRAWER,
    PU_CLOSE_DRAWER,

    PU_LEFT_DRAWER,
    PU_RIGHT_DRAWER,
    PU_TOP_DRAWER,
    PU_BOTTOM_DRAWER,

    PU_EXIT,
};


BEGIN_EVENT_TABLE(MyTaskBarIcon, wxTaskBarIcon)
    EVT_MENU(PU_RESTORE, MyTaskBarIcon::OnMenuRestore)
    EVT_MENU(PU_EXIT,    MyTaskBarIcon::OnMenuExit)
    EVT_MENU(PU_NEW_ICON,MyTaskBarIcon::OnMenuSetNewIcon)
    EVT_MENU(PU_OLD_ICON,MyTaskBarIcon::OnMenuSetOldIcon)
#if USE_DRAWER_CODE
    EVT_MENU(PU_OPEN_DRAWER,MyTaskBarIcon::OnMenuOpenDrawer)
    EVT_MENU(PU_CLOSE_DRAWER,MyTaskBarIcon::OnMenuCloseDrawer)
    EVT_MENU(PU_TOP_DRAWER,MyTaskBarIcon::OnMenuTopDrawer)
    EVT_MENU(PU_BOTTOM_DRAWER,MyTaskBarIcon::OnMenuBottomDrawer)
    EVT_MENU(PU_LEFT_DRAWER,MyTaskBarIcon::OnMenuLeftDrawer)
    EVT_MENU(PU_RIGHT_DRAWER,MyTaskBarIcon::OnMenuRightDrawer)
#endif // USE_DRAWER_CODE
    EVT_TASKBAR_LEFT_DCLICK  (MyTaskBarIcon::OnLeftButtonDClick)
END_EVENT_TABLE()

void MyTaskBarIcon::OnMenuRestore(wxCommandEvent& )
{
    dialog->Show(true);
}

void MyTaskBarIcon::OnMenuExit(wxCommandEvent& )
{
    dialog->Close(true);
}

void MyTaskBarIcon::OnMenuSetNewIcon(wxCommandEvent&)
{
    wxIcon icon(smile_xpm);

    if (!SetIcon(icon, wxT("wxTaskBarIcon Sample - a different icon")))
        wxMessageBox(wxT("Could not set new icon."));
}

void MyTaskBarIcon::OnMenuSetOldIcon(wxCommandEvent&)
{
    wxIcon icon(wxT("wxDEFAULT_FRAME"));

    if (!RemoveIcon())
        wxMessageBox(wxT("Could not restore old icon."));
}

#if USE_DRAWER_CODE

void MyTaskBarIcon::OnMenuOpenDrawer(wxCommandEvent&)
{
    m_pMyDrawer->Open(true);
}

void MyTaskBarIcon::OnMenuCloseDrawer(wxCommandEvent&)
{
    m_pMyDrawer->Close();
}

void MyTaskBarIcon::OnMenuLeftDrawer(wxCommandEvent&)
{
    m_pMyDrawer->SetPreferredEdge(wxLEFT);
}

void MyTaskBarIcon::OnMenuRightDrawer(wxCommandEvent&)
{
    m_pMyDrawer->SetPreferredEdge(wxRIGHT);
}

void MyTaskBarIcon::OnMenuTopDrawer(wxCommandEvent&)
{
    m_pMyDrawer->SetPreferredEdge(wxTOP);
}

void MyTaskBarIcon::OnMenuBottomDrawer(wxCommandEvent&)
{
    m_pMyDrawer->SetPreferredEdge(wxBOTTOM);
}

#endif // USE_DRAWER_CODE

// Overridables
wxMenu *MyTaskBarIcon::CreatePopupMenu()
{
    wxMenu *menu = new wxMenu;

    menu->Append(PU_RESTORE, _T("&Restore TBTest"));
    menu->Append(PU_NEW_ICON,_T("&Set New Icon"));
    menu->Append(PU_OLD_ICON,_T("&Restore Old Icon"));
#if USE_DRAWER_CODE
    menu->AppendSeparator();
    menu->Append(PU_OPEN_DRAWER,_T("Open Drawer"));
    menu->Append(PU_CLOSE_DRAWER,_T("Close Drawer"));
    menu->AppendSeparator();
    menu->Append(PU_LEFT_DRAWER,_T("Set Drawer to come out on the LEFT side"));
    menu->Append(PU_RIGHT_DRAWER,_T("Set Drawer to come out on the RIGHT side"));
    menu->Append(PU_TOP_DRAWER,_T("Set Drawer to come out on the TOP side"));
    menu->Append(PU_BOTTOM_DRAWER,_T("Set Drawer to come out on the BOTTOM side"));
#else
    menu->AppendSeparator();
    menu->Append(PU_EXIT,    _T("E&xit"));
#endif // USE_DRAWER_CODE / !USE_DRAWER_CODE
    return menu;
}

void MyTaskBarIcon::OnLeftButtonDClick(wxTaskBarIconEvent&)
{
    dialog->Show(true);
}
