/////////////////////////////////////////////////////////////////////////////
// Name:        wx/cocoa/dcscreen.h
// Purpose:     wxScreenDC class
// Author:      David Elliott
// Modified by:
// Created:     2003/03/16
// RCS-ID:      $Id:
// Copyright:   (c) 2003 David Elliott
// Licence:   	wxWindows license
/////////////////////////////////////////////////////////////////////////////

#ifndef __WX_COCOA_DCSCREEN_H__
#define __WX_COCOA_DCSCREEN_H__

#include "wx/dcclient.h"

class WXDLLEXPORT wxScreenDC: public wxDC
{
    DECLARE_DYNAMIC_CLASS(wxScreenDC)
public:
    wxScreenDC(void);
    wxScreenDC( wxDC *dc ); // Create compatible DC
    ~wxScreenDC(void);
};

#endif // __WX_COCOA_DCSCREEN_H__
