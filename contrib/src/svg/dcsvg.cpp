/////////////////////////////////////////////////////////////////////////////
// Name:        svg.cpp
// Purpose:     SVG sample
// Author:      Chris Elliott
// Modified by:
// RCS-ID:      $Id$
// Licence:     wxWindows license
/////////////////////////////////////////////////////////////////////////////


// For compilers that support precompilation, includes "wx/wx.h".
#include "wx/wxprec.h"

#ifdef __BORLANDC__
#pragma hdrstop
#endif

#ifndef WX_PRECOMP
#include "wx/wx.h"
#endif
 
#include "wx/svg/dcsvg.h"

#include <math.h>
#include "wx/image.h"

#define wxSVG_DEBUG FALSE
// or TRUE to see the calls being executed
#define newline    wxString(wxT("\n"))
#define space      wxString(wxT(" "))
#define semicolon  wxString(wxT(";"))
#define     wx_round(a)    (int)((a)+.5)

#ifdef __BORLANDC__
#pragma warn -rch
#pragma warn -ccc
#endif

static inline double DegToRad(double deg) { return (deg * 3.14) / 180.0; } ;

wxString wxColStr ( wxColour c )
{
    unsigned char r, g, b ;
    r = c.Red ();
    g = c.Green ();
    b = c. Blue ();

    // possible Unicode bug here
    wxString s = wxDecToHex(r) + wxDecToHex(g) + wxDecToHex(b) ;
    return s ;
}


wxString wxBrushString ( wxColour c, int style )
{
    wxString s = wxT("fill:#") + wxColStr (c)  + semicolon + space ;
    switch ( style )
    {
        case wxSOLID :
            s = s + wxT("fill-opacity:1.0; ");
            break ;
        case wxTRANSPARENT:
            s = s + wxT("fill-opacity:0.0; ");
            break ;

        default :
            wxASSERT_MSG(FALSE, wxT("wxSVGFileDC::Requested Brush Style not available")) ;

    }
    s = s + newline ;
    return s ;
}


void wxSVGFileDC::Init (wxString f, int Width, int Height, float dpi)

{
    //set up things first  wxDCBase does all this?
    m_width = Width ;
    m_height = Height ;

    m_clipping = FALSE;
    m_OK = TRUE;

    m_mm_to_pix_x = dpi/25.4;
    m_mm_to_pix_y = dpi/25.4;

    m_signX = m_signY = 1;

    m_userScaleX = m_userScaleY =
        m_deviceOriginX = m_deviceOriginY = 0;

    m_OriginX = m_OriginY = 0;
    m_logicalOriginX = m_logicalOriginY = 0;
    m_logicalScaleX = m_logicalScaleY = 0 ;
    m_scaleX = m_scaleY = 1.0 ;

    m_logicalFunction = wxCOPY;
    m_backgroundMode = wxTRANSPARENT;
    m_mappingMode = wxMM_TEXT;

    m_backgroundBrush = *wxTRANSPARENT_BRUSH;
    m_textForegroundColour = *wxBLACK;
    m_textBackgroundColour = *wxWHITE;
    m_colour = wxColourDisplay();

    m_pen   = *wxBLACK_PEN;
    m_font  = *wxNORMAL_FONT;
    m_brush = *wxWHITE_BRUSH;

    m_graphics_changed = TRUE ;

    ////////////////////code here

    m_outfile = new wxFileOutputStream(f) ;
    m_OK = m_outfile->Ok ();
    if (m_OK)
    {
        m_filename = f ;
        m_sub_images = 0 ;
        wxString s ;
        s = wxT("<?xml version=\"1.0\" standalone=\"no\"?>") ; s = s + newline ;
        write(s);
        s = wxT("<!DOCTYPE svg PUBLIC \"-//W3C//DTD SVG 20010904//EN\" ") + newline ;
        write(s);
        s = wxT("\"http://www.w3.org/TR/2001/REC-SVG-20010904/DTD/svg10.dtd\"> ")+ newline ;
        write(s);
        s.Printf ( wxT("<svg width=\"%.2gcm\" height=\"%.2gcm\" viewBox=\"0 0 %d %d \"> \n"), float(Width)/dpi*2.54, float(Height)/dpi*2.54, Width, Height );
        write(s);
        s = wxT("<title>SVG Picture created as ") + wxFileNameFromPath(f) + wxT(" </title>") + newline ;
        write(s);
        s = wxString (wxT("<desc>Picture generated by wxSVG ")) + wxSVGVersion + wxT(" </desc>")+ newline ;
        write(s);
        s =  wxT("<g style=\"fill:black; stroke:black; stroke-width:1\">") + newline ;
        write(s);

    }
}


// constructors
wxSVGFileDC::wxSVGFileDC (wxString f)
{                                
    // quarter 640x480 screen display at 72 dpi
    Init (f,320,240,72.0);
};

wxSVGFileDC::wxSVGFileDC (wxString f, int Width, int Height)
{
    Init (f,Width,Height,72.0);
};

wxSVGFileDC::wxSVGFileDC (wxString f, int Width, int Height, float dpi)
{
    Init (f,Width,Height,dpi);
};

wxSVGFileDC::~wxSVGFileDC()
{
    wxString s = wxT("</g> \n</svg> \n") ;
    write(s);
    delete m_outfile ;
}


//////////////////////////////////////////////////////////////////////////////////////////

void wxSVGFileDC::DoDrawLine (wxCoord x1, wxCoord y1, wxCoord x2, wxCoord y2)
{
    if (m_graphics_changed) NewGraphics ();
    wxString s ;
    s.Printf ( wxT("<path d=\"M%d %d L%d %d\" /> \n"), x1,y1,x2,y2 );
    if (m_OK)
    {
        write(s);
    }
    wxASSERT_MSG(!wxSVG_DEBUG, wxT("wxSVGFileDC::DrawLine Call executed")) ;
    CalcBoundingBox(x1, y1) ;
    CalcBoundingBox(x2, y2) ;
    return;
};

void wxSVGFileDC::DoDrawLines(int n, wxPoint points[], wxCoord xoffset , wxCoord yoffset )
{
    for ( int i = 1; i < n ; i++ )
    {
        DoDrawLine ( points [i-1].x + xoffset, points [i-1].y + yoffset,
            points [ i ].x + xoffset, points [ i ].y + yoffset ) ;
    }
}


void wxSVGFileDC::DoDrawPoint (wxCoord x1, wxCoord y1)
{
    wxString s;
    if (m_graphics_changed) NewGraphics ();
    s = wxT("<g style = \"stroke-linecap:round;\" > ") + newline ;
    write(s);
    DrawLine ( x1,y1,x1,y1 );
    s = wxT("</g>");
    write(s);
}


void wxSVGFileDC::DoDrawCheckMark(wxCoord x1, wxCoord y1, wxCoord width, wxCoord height)
{
    wxDCBase::DoDrawCheckMark (x1,y1,width,height) ;
}


void wxSVGFileDC::DoDrawText(const wxString& text, wxCoord x1, wxCoord y1)
{
    DoDrawRotatedText(text, x1,y1,0.0);
    wxASSERT_MSG(!wxSVG_DEBUG, wxT("wxSVGFileDC::DrawText Call executed")) ;
}


void wxSVGFileDC::DoDrawRotatedText(const wxString& sText, wxCoord x, wxCoord y, double angle)
{
    //known bug; if the font is drawn in a scaled DC, it will not behave exactly as wxMSW
    if (m_graphics_changed) NewGraphics ();
    wxString s, sTmp;

    // calculate bounding box
    wxCoord w, h, desc ;
    DoGetTextExtent(sText, &w, &h, &desc);

    double rad = DegToRad(angle);

    // wxT("upper left") and wxT("upper right")
    CalcBoundingBox(x, y);
    CalcBoundingBox(x + w*cos(rad), y - h*sin(rad));

    // wxT("bottom left") and wxT("bottom right")
    x += (wxCoord)(h*sin(rad));
    y += (wxCoord)(h*cos(rad));
    CalcBoundingBox(x, y);
    CalcBoundingBox(x + h*sin(rad), y + h*cos(rad));

    if (m_backgroundMode == wxSOLID)
    {
        // draw background first
        // just like DoDrawRectangle except we pass the text color to it and set the border to a 1 pixel wide text background

        wxASSERT_MSG(!wxSVG_DEBUG, wxT("wxSVGFileDC::Draw Rotated Text Call plotting text background")) ;
        sTmp.Printf ( wxT(" <rect x=\"%d\" y=\"%d\" width=\"%d\" height=\"%d\"  "), x,y+desc-h, w, h );
        s = sTmp + wxT("style=\"fill:#") + wxColStr (m_textBackgroundColour) + wxT("; ") ;
        s = s + wxT("stroke-width:1; stroke:#") + wxColStr (m_textBackgroundColour) + wxT("; ") ;
        sTmp.Printf ( wxT("\" transform=\"rotate( %.2g %d %d )  \">"), -angle, x,y ) ;
        s = s + sTmp + newline ;
        write(s);
    }
    //now do the text itself
    s.Printf (wxT(" <text x=\"%d\" y=\"%d\" "),x,y );
   
    sTmp = m_font.GetFaceName () ;
    if (sTmp.Len () > 0)  s = s + wxT("style=\"font-family:") + sTmp + wxT("; ");
    else s = s + wxT("style=\" ") ;

    wxString fontweights [3] = { wxT("normal"), wxT("lighter"), wxT("bold") };
    s = s + wxT("font-weight:") + fontweights[m_font.GetWeight() - wxNORMAL] + semicolon + space;
    
    wxString fontstyles [5] = { wxT("normal"), wxT("style error"), wxT("style error"), wxT("italic"), wxT("oblique") };
    s = s + wxT("font-style:") + fontstyles[m_font.GetStyle() - wxNORMAL] + semicolon  + space;
    
    sTmp.Printf (wxT("font-size:%dpt; fill:#"), m_font.GetPointSize () );
    s = s + sTmp ;
    s = s + wxColStr (m_textForegroundColour) + wxT("; stroke:#") + wxColStr (m_textForegroundColour) + wxT("; ") ;
    sTmp.Printf ( wxT("stroke-width:0;\"  transform=\"rotate( %.2g %d %d )  \" >"),  -angle, x,y ) ;
    s = s + sTmp + sText + wxT("</text> ") + newline ;
    if (m_OK)
    {
        write(s);
    }
    wxASSERT_MSG(!wxSVG_DEBUG, wxT("wxSVGFileDC::DrawRotatedText Call executed")) ;

}


void wxSVGFileDC::DoDrawRectangle(wxCoord x, wxCoord y, wxCoord width, wxCoord height)
{
    DoDrawRoundedRectangle(x, y, width, height, 0)  ;
}


void wxSVGFileDC::DoDrawRoundedRectangle(wxCoord x, wxCoord y, wxCoord width, wxCoord height, double radius )

{
    if (m_graphics_changed) NewGraphics ();
    wxString s ;

    s.Printf ( wxT(" <rect x=\"%d\" y=\"%d\" width=\"%d\" height=\"%d\" rx=\"%.2g\" "), 
               x, y, width, height, radius );

    s = s + wxT(" /> ") + newline ;
    write(s);

    wxASSERT_MSG(!wxSVG_DEBUG, wxT("wxSVGFileDC::DoDrawRoundedRectangle Call executed")) ;
    CalcBoundingBox(x, y) ;
    CalcBoundingBox(x + width, y + height) ;

}


void wxSVGFileDC::DoDrawPolygon(int n, wxPoint points[], wxCoord xoffset, wxCoord yoffset,int fillStyle)
{
    if (m_graphics_changed) NewGraphics ();
    wxString s, sTmp ;
    s = wxT("<polygon style=\"") ;
    if ( fillStyle == wxODDEVEN_RULE )
        s = s + wxT("fill-rule:evenodd; ");
    else
        s = s + wxT("fill-rule:nonzero; ");

    s = s  + wxT("\" \npoints=\"") ;

    for (int i = 0; i < n;  i++)
    {
        sTmp.Printf ( wxT("%d,%d"), points [i].x+xoffset, points[i].y+yoffset );
        s = s + sTmp + newline ;
        CalcBoundingBox ( points [i].x+xoffset, points[i].y+yoffset);
    }
    s = s + wxT("\" /> ") ;
    s = s + newline ;
    write(s);

    wxASSERT_MSG(!wxSVG_DEBUG, wxT("wxSVGFileDC::DoDrawPolygon Call executed")) ;
}


void wxSVGFileDC::DoDrawEllipse (wxCoord x, wxCoord y, wxCoord width, wxCoord height)

{
    if (m_graphics_changed) NewGraphics ();

    int rh = height /2 ;
    int rw = width  /2 ;

    wxString s;
    s.Printf ( wxT("<ellipse cx=\"%d\" cy=\"%d\" rx=\"%d\" ry=\"%d\" "), x+rw,y+rh, rw, rh );
    s = s + wxT(" /> ") + newline ;

    write(s);

    wxASSERT_MSG(!wxSVG_DEBUG, wxT("wxSVGFileDC::DoDrawEllipse Call executed")) ;
    CalcBoundingBox(x, y) ;
    CalcBoundingBox(x + width, y + height) ;
}


void wxSVGFileDC::DoDrawArc(wxCoord x1, wxCoord y1, wxCoord x2, wxCoord y2, wxCoord xc, wxCoord yc)
{
    /* Draws an arc of a circle, centred on (xc, yc), with starting point
    (x1, y1) and ending at (x2, y2). The current pen is used for the outline
    and the current brush for filling the shape.

    The arc is drawn in an anticlockwise direction from the start point to
    the end point.

    Might be better described as Pie drawing */

    if (m_graphics_changed) NewGraphics ();
    wxString s ;

    // we need the radius of the circle which has two estimates
    double r1 = sqrt ( double( (x1-xc)*(x1-xc) ) + double( (y1-yc)*(y1-yc) ) );
    double r2 = sqrt ( double( (x2-xc)*(x2-xc) ) + double( (y2-yc)*(y2-yc) ) );

    wxASSERT_MSG( (fabs ( r2-r1 ) <= 3), wxT("wxSVGFileDC::DoDrawArc Error in getting radii of circle")) ;
    if ( fabs ( r2-r1 ) > 3 )    //pixels
    {
        s = wxT("<!--- wxSVGFileDC::DoDrawArc Error in getting radii of circle --> \n") ;
        write(s);
    }

    double theta1 = atan2(yc-y1,x1-xc);
    if ( theta1 < 0 ) theta1 = theta1 + 3.14 * 2;
    double theta2 = atan2(yc-y2, x2-xc);
    if ( theta2 < 0 ) theta2 = theta2 + 3.14 * 2;
    if ( theta2 < theta1 ) theta2 = theta2 + 3.14 *2 ;

    int fArc  ;                  // flag for large or small arc 0 means less than 180 degrees
    if (  fabs((theta2 - theta1) > 3.14 )) fArc = 1; else fArc = 0 ;

    int fSweep = 0 ;             // flag for sweep always 0

    s.Printf ( wxT("<path d=\"M%d %d A%.2g %.2g 0.0 %d %d %d %d L%d %d z "),
        x1,y1, r1, r2, fArc, fSweep, x2, y2, xc, yc );

    // the z means close the path and fill
    s = s + wxT(" \" /> ") + newline ;


    if (m_OK)
    {
        write(s);
    }

    wxASSERT_MSG(!wxSVG_DEBUG, wxT("wxSVGFileDC::DoDrawArc Call executed")) ;
}


void wxSVGFileDC::DoDrawEllipticArc(wxCoord x,wxCoord y,wxCoord w,wxCoord h,double sa,double ea)
{
    /*
    Draws an arc of an ellipse. The current pen is used for drawing the arc
    and the current brush is used for drawing the pie. This function is
    currently only available for X window and PostScript device contexts.

    x and y specify the x and y coordinates of the upper-left corner of the
    rectangle that contains the ellipse.

    width and height specify the width and height of the rectangle that
    contains the ellipse.

    start and end specify the start and end of the arc relative to the
    three-o'clock position from the center of the rectangle. Angles are
    specified in degrees (360 is a complete circle). Positive values mean
    counter-clockwise motion. If start is equal to end, a complete ellipse
    will be drawn. */

    //known bug: SVG draws with the current pen along the radii, but this does not happen in wxMSW

    if (m_graphics_changed) NewGraphics ();

    wxString s ;
    //radius
    double rx = w / 2 ;
    double ry = h / 2 ;
    // center
    double xc = x + rx ;
    double yc = y + ry ;

    double xs, ys, xe, ye ;
    xs = xc + rx * cos (DegToRad(sa)) ;
    xe = xc + rx * cos (DegToRad(ea)) ;
    ys = yc - ry * sin (DegToRad(sa)) ;
    ye = yc - ry * sin (DegToRad(ea)) ;

    ///now same as circle arc...

    double theta1 = atan2(ys-yc, xs-xc);
    double theta2 = atan2(ye-yc, xe-xc);

    int fArc  ;                  // flag for large or small arc 0 means less than 180 degrees
    if ( (theta2 - theta1) > 0 ) fArc = 1; else fArc = 0 ;

    int fSweep ;
    if ( fabs( (theta2 - theta1) > 3.14)) fSweep = 1; else fSweep = 0 ;

    s.Printf ( wxT("<path d=\"M%d %d A%d %d 0.0 %d %d  %d %d L %d %d z "),
        int(xs), int(ys), int(rx), int(ry),
        fArc, fSweep, int(xe), int(ye), int(xc), int(yc)  );


    s = s + wxT(" \" /> ") + newline ;

    if (m_OK)
    {
        write(s);
    }

    wxASSERT_MSG(!wxSVG_DEBUG, wxT("wxSVGFileDC::DoDrawEllipticArc Call executed")) ;
}


void wxSVGFileDC::DoGetTextExtent(const wxString& string, wxCoord *w, wxCoord *h, wxCoord *descent , wxCoord *externalLeading , wxFont *font) const

{
    wxScreenDC sDC ;

    sDC.SetFont (m_font);
    if ( font != NULL ) sDC.SetFont ( *font );
    sDC.GetTextExtent(string, w,  h, descent, externalLeading );
    wxASSERT_MSG(!wxSVG_DEBUG, wxT("wxSVGFileDC::GetTextExtent Call executed")) ;
}


wxCoord wxSVGFileDC::GetCharHeight() const

{
    wxScreenDC sDC ;
    sDC.SetFont (m_font);

    wxASSERT_MSG(!wxSVG_DEBUG, wxT("wxSVGFileDC::GetCharHeight Call executing")) ;
    return ( sDC.GetCharHeight() );

}


wxCoord wxSVGFileDC::GetCharWidth() const
{
    wxScreenDC sDC ;
    sDC.SetFont (m_font);

    wxASSERT_MSG(!wxSVG_DEBUG, wxT("wxSVGFileDC::GetCharWidth Call executing")) ;
    return ( sDC.GetCharWidth() ) ;

}


/// Set Functions /////////////////////////////////////////////////////////////////
void wxSVGFileDC::SetBackground( const wxBrush &brush )
{

    m_backgroundBrush = brush;
    return;
}


void wxSVGFileDC::SetBackgroundMode( int mode )
{
    m_backgroundMode = mode;
    return;
}


void wxSVGFileDC::SetBrush(const wxBrush& brush)

{
    m_brush = brush ;

    m_graphics_changed = TRUE ;
    wxASSERT_MSG(!wxSVG_DEBUG, wxT("wxSVGFileDC::SetBrush Call executed")) ;
}


void wxSVGFileDC::SetPen(const wxPen& pen)
{
    // width, color, ends, joins : currently implemented
    // dashes, stipple :  not implemented
    m_pen = pen ;
  
    m_graphics_changed = TRUE ;
    wxASSERT_MSG(!wxSVG_DEBUG, wxT("wxSVGFileDC::SetPen Call executed")) ;
}

void wxSVGFileDC::NewGraphics ()
{

    int w = m_pen.GetWidth ();
    wxColour c = m_pen.GetColour () ;

    wxString s, sBrush, sPenCap, sPenJoin, sPenStyle, sLast, sWarn;
	
    sBrush = wxT("</g>\n<g style=\"") + wxBrushString ( m_brush.GetColour (), m_brush.GetStyle () ) 
	+ wxT("  stroke:#") + wxColStr (c) + wxT("; ") ;
	
    switch ( m_pen.GetCap () )
    {
        case  wxCAP_PROJECTING :
            sPenCap = wxT("stroke-linecap:square; ") ;
            break ;
        case  wxCAP_BUTT :
            sPenCap = wxT("stroke-linecap:butt; ") ;
            break ;
        case    wxCAP_ROUND :
        default :
            sPenCap = wxT("stroke-linecap:round; ") ;
    };
    switch ( m_pen.GetJoin () )
    {
        case  wxJOIN_BEVEL :
            sPenJoin = wxT("stroke-linejoin:bevel; ") ;
            break ;
        case  wxJOIN_MITER :
            sPenJoin = wxT("stroke-linejoin:miter; ") ;
            break ;
        case    wxJOIN_ROUND :
        default :
            sPenJoin = wxT("stroke-linejoin:round; ") ;
    };

    switch ( m_pen.GetStyle () )
    {
        case  wxSOLID :
            sPenStyle = wxT("stroke-opacity:1.0; stroke-opacity:1.0; ") ;
            break ;
        case  wxTRANSPARENT :
            sPenStyle = wxT("stroke-opacity:0.0; stroke-opacity:0.0; ") ;
            break ;
        default :
            wxASSERT_MSG(FALSE, wxT("wxSVGFileDC::SetPen Call called to set a Style which is not available")) ;
            sWarn = sWarn + wxT("<!--- wxSVGFileDC::SetPen Call called to set a Style which is not available --> \n") ;
    }

    sLast.Printf (   wxT("stroke-width:%d\" \n   transform=\"translate(%.2g %.2g) scale(%.2g %.2g)\">"),  
                  w, m_OriginX, m_OriginY, m_scaleX, m_scaleY  );

    s = sBrush + sPenCap + sPenJoin + sPenStyle + sLast + newline + sWarn;
    write(s);
    m_graphics_changed = FALSE ;
    wxASSERT_MSG(!wxSVG_DEBUG, wxT("wxSVGFileDC::NewGraphics Call executed")) ;
}


void wxSVGFileDC::SetFont(const wxFont& font)

{
    m_font = font ;
    
    wxASSERT_MSG(!wxSVG_DEBUG, wxT("wxSVGFileDC::SetFont Call executed")) ;
}


void wxSVGFileDC::ComputeScaleAndOrigin()
{
    m_scaleX = m_logicalScaleX * m_userScaleX;
    m_scaleY = m_logicalScaleY * m_userScaleY;
    m_OriginX = m_logicalOriginX * m_logicalScaleX + m_deviceOriginX ;
    m_OriginY = m_logicalOriginY * m_logicalScaleY + m_deviceOriginY ;
    m_graphics_changed = TRUE;
}


int wxSVGFileDC::GetMapMode()
{
    return m_mappingMode ;
}


void wxSVGFileDC::SetMapMode( int mode )
{
    switch (mode)
    {
        case wxMM_TWIPS:
            SetLogicalScale( twips2mm*m_mm_to_pix_x, twips2mm*m_mm_to_pix_y );
            break;
        case wxMM_POINTS:
            SetLogicalScale( pt2mm*m_mm_to_pix_x, pt2mm*m_mm_to_pix_y );
            break;
        case wxMM_METRIC:
            SetLogicalScale( m_mm_to_pix_x, m_mm_to_pix_y );
            break;
        case wxMM_LOMETRIC:
            SetLogicalScale( m_mm_to_pix_x/10.0, m_mm_to_pix_y/10.0 );
            break;
        default:
        case wxMM_TEXT:
            SetLogicalScale( 1.0, 1.0 );
            break;
    }
    m_mappingMode = mode;

    /*  we don't do this mega optimisation
        if (mode != wxMM_TEXT)
        {
            m_needComputeScaleX = TRUE;
            m_needComputeScaleY = TRUE;
        }
    */
}


void wxSVGFileDC::GetUserScale(double *x, double *y) const
{
    *x = m_userScaleX ;
    *y = m_userScaleY ;
}


void wxSVGFileDC::SetUserScale( double x, double y )
{
    // allow negative ? -> no
    m_userScaleX = x;
    m_userScaleY = y;
    ComputeScaleAndOrigin();
}


void wxSVGFileDC::SetLogicalScale( double x, double y )
{
    // allow negative ?
    m_logicalScaleX = x;
    m_logicalScaleY = y;
    ComputeScaleAndOrigin();
}


void wxSVGFileDC::SetLogicalOrigin( wxCoord x, wxCoord y )
{
    // is this still correct ?
    m_logicalOriginX = x * m_signX;
    m_logicalOriginY = y * m_signY;
    ComputeScaleAndOrigin();
}


void wxSVGFileDC::SetDeviceOrigin( wxCoord x, wxCoord y )
{
    // only wxPostScripDC has m_signX = -1, 
    m_deviceOriginX = x;
    m_deviceOriginY = y;
    ComputeScaleAndOrigin();
}


void wxSVGFileDC::SetAxisOrientation( bool xLeftRight, bool yBottomUp )
{
    // only wxPostScripDC has m_signX = -1, 
    m_signX = (xLeftRight ?  1 : -1);
    m_signY = (yBottomUp  ? -1 :  1);
    ComputeScaleAndOrigin();
}


// export a bitmap as a raster image in png
bool wxSVGFileDC::DoBlit(wxCoord xdest, wxCoord ydest, wxCoord width, wxCoord height,
                         wxDC* source, wxCoord xsrc, wxCoord ysrc, 
			 int logicalFunc /*= wxCOPY*/, bool useMask /*= FALSE*/,
			 wxCoord /*xsrcMask = -1*/, wxCoord /*ysrcMask = -1*/)
{
    
    if (logicalFunc != wxCOPY)
    {
        wxASSERT_MSG(FALSE, wxT("wxSVGFileDC::DoBlit Call requested nonCopy mode; this is not possible")) ;
        return FALSE ;
    }
    if (useMask != FALSE)
    {
        wxASSERT_MSG(FALSE, wxT("wxSVGFileDC::DoBlit Call requested False mask ; this is not possible")) ;
        return FALSE ;
    }
    wxBitmap myBitmap (width, height) ;
    wxMemoryDC memDC;
    memDC.SelectObject( myBitmap );
    memDC.Blit(0, 0, width, height, source, xsrc, ysrc);
    memDC.SelectObject( wxNullBitmap );
    DoDrawBitmap(myBitmap, xdest, ydest);
    wxASSERT_MSG(!wxSVG_DEBUG, wxT("wxSVGFileDC::DoBlit Call executed")) ;
    return FALSE ;
}


void wxSVGFileDC::DoDrawIcon(const class wxIcon & myIcon, wxCoord x, wxCoord y)
{
    wxBitmap myBitmap (myIcon.GetWidth(), myIcon.GetHeight() ) ;
    wxMemoryDC memDC;
    memDC.SelectObject( myBitmap );
    memDC.DrawIcon(myIcon,0,0);
    memDC.SelectObject( wxNullBitmap );
    DoDrawBitmap(myBitmap, x, y);
    wxASSERT_MSG(!wxSVG_DEBUG, wxT("wxSVGFileDC::DoDrawIcon Call executed")) ;
    return ;
}


                                 
void wxSVGFileDC::DoDrawBitmap(const class wxBitmap & bmp, wxCoord x, wxCoord y , bool  WXUNUSED(bTransparent) /*=0*/ )
{
    if (m_graphics_changed) NewGraphics ();

    wxString sTmp, s, sPNG ; 
    wxImage::AddHandler(new wxPNGHandler);

// create suitable file name   
    sTmp.Printf ( wxT("_image%d.png"), m_sub_images);
    sPNG = m_filename.BeforeLast(wxT('.')) + sTmp;
    while (wxFile::Exists(sPNG) )
    {
        m_sub_images ++ ;
        sTmp.Printf ( wxT("_image%d.png"), m_sub_images);
        sPNG = m_filename.BeforeLast(wxT('.')) + sTmp;
    }
    
//create copy of bitmap (wxGTK doesn't like saving a constant bitmap)
    wxBitmap myBitmap = bmp ;
//save it
    bool bPNG_OK = myBitmap.SaveFile(sPNG,wxBITMAP_TYPE_PNG);

// refrence the bitmap from the SVG doc
    int w = myBitmap.GetWidth();
    int h = myBitmap.GetHeight();
    sTmp.Printf ( wxT(" <image x=\"%d\" y=\"%d\" width=\"%dpx\" height=\"%dpx\" "), x,y,w,h );
    s = s + sTmp ;
    sTmp.Printf ( wxT(" xlink:href=\"%s\"> \n"), sPNG.c_str() );
    s = s + sTmp + wxT("<title>Image from wxSVG</title>  </image>") + newline;
    
    if (m_OK && bPNG_OK)
    {
        write(s);
    }
    m_OK = m_outfile->Ok () && bPNG_OK;
    wxASSERT_MSG(!wxSVG_DEBUG, wxT("wxSVGFileDC::DoDrawBitmap Call executed")) ;

    return  ;
}


// ---------------------------------------------------------------------------
// coordinates transformations
// ---------------------------------------------------------------------------

wxCoord wxSVGFileDC::DeviceToLogicalX(wxCoord x) const
{
    return XDEV2LOG(x);
}


wxCoord wxSVGFileDC::DeviceToLogicalY(wxCoord y) const
{
    return YDEV2LOG(y);
}


wxCoord wxSVGFileDC::DeviceToLogicalXRel(wxCoord x) const
{
    return XDEV2LOGREL(x);
}


wxCoord wxSVGFileDC::DeviceToLogicalYRel(wxCoord y) const
{
    return YDEV2LOGREL(y);
}


wxCoord wxSVGFileDC::LogicalToDeviceX(wxCoord x) const
{
    return XLOG2DEV(x);
}


wxCoord wxSVGFileDC::LogicalToDeviceY(wxCoord y) const
{
    return YLOG2DEV(y);
}


wxCoord wxSVGFileDC::LogicalToDeviceXRel(wxCoord x) const
{
    return XLOG2DEVREL(x);
}


wxCoord wxSVGFileDC::LogicalToDeviceYRel(wxCoord y) const
{
    return YLOG2DEVREL(y);
}

void wxSVGFileDC::write(const wxString &s)
{
	wxWX2MBbuf buf = s.mb_str(wxConvUTF8);
	m_outfile->Write(buf, strlen((const char *)buf));
	m_OK = m_outfile->Ok();
}

#ifdef __BORLANDC__
#pragma warn .rch
#pragma warn .ccc
#endif
