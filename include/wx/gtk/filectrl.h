///////////////////////////////////////////////////////////////////////////////
// Name:        wx/gtk/filectrl.h
// Purpose:     wxGtkFileCtrl Header
// Author:      Diaa M. Sami
// Modified by:
// Created:     Aug-10-2007
// RCS-ID:      $Id$
// Copyright:   (c) Diaa M. Sami
// Licence:     wxWindows licence
///////////////////////////////////////////////////////////////////////////////

#ifndef FILECTRL_H
#define FILECTRL_H

typedef struct _GtkFileChooser GtkFileChooser;

// [GTK] current problems:
// All methods(e.g. SetFilename(), SetPath(), etc) which change the state of
// the control result in events fired, such events should be suppressed.
// ------
// Sometimes a selection event(with 0 files) is fired before
// wxEVT_FILECTRL_FOLDERCHANGED, unfortunately this can hardly be detected!

// A wx wrapper for any Gtk object implementing the interface GtkFileChooser

class WXDLLIMPEXP_CORE wxGtkFileChooser
{
public:
    wxGtkFileChooser() {}

    void SetWidget(GtkFileChooser *w);

    wxString GetPath() const;
    void GetPaths( wxArrayString& paths ) const;
    wxString GetDirectory() const;
    wxString GetFilename() const;
    void GetFilenames( wxArrayString& files ) const;
    int GetFilterIndex() const;

    bool SetPath( const wxString& path );
    bool SetDirectory( const wxString& dir );
    void SetWildcard( const wxString& wildCard );
    void SetFilterIndex( int filterIndex );

private:
    GtkFileChooser *m_widget;
};

#if wxUSE_FILECTRL

class WXDLLIMPEXP_CORE wxGtkFileCtrl: public wxControl,
            public wxFileCtrlBase
{
public:
    wxGtkFileCtrl () { Init(); }

    wxGtkFileCtrl ( wxWindow *parent,
                    wxWindowID id,
                    const wxString& defaultDirectory = wxEmptyString,
                    const wxString& defaultFilename = wxEmptyString,
                    const wxString& wildCard = wxFileSelectorDefaultWildcardStr,
                    long style = wxFC_DEFAULT_STYLE,
                    const wxPoint& pos = wxDefaultPosition,
                    const wxSize& size = wxDefaultSize,
                    const wxString& name = wxFileCtrlNameStr )
    {
        Init();
        Create( parent, id, defaultDirectory, defaultFilename, wildCard, style, pos, size, name );
    }

    virtual ~wxGtkFileCtrl() {};

    void Init();
    bool Create( wxWindow *parent,
                 wxWindowID id,
                 const wxString& defaultDirectory = wxEmptyString,
                 const wxString& defaultFileName = wxEmptyString,
                 const wxString& wildCard = wxFileSelectorDefaultWildcardStr,
                 long style = wxFC_DEFAULT_STYLE,
                 const wxPoint& pos = wxDefaultPosition,
                 const wxSize& size = wxDefaultSize,
                 const wxString& name = wxFileCtrlNameStr );

    virtual void SetWildcard( const wxString& wildCard );
    virtual void SetFilterIndex( int filterIndex );
    virtual bool SetDirectory( const wxString& dir );
    virtual bool SetFilename( const wxString& name );
    virtual bool SetPath( const wxString& path );

    virtual wxString GetFilename() const;
    virtual wxString GetDirectory() const;
    virtual wxString GetWildcard() const { return this->m_wildCard; }
    virtual wxString GetPath() const;
    virtual void GetPaths( wxArrayString& paths ) const;
    virtual void GetFilenames( wxArrayString& files ) const;
    virtual int GetFilterIndex() const { return m_fc.GetFilterIndex(); }

    virtual bool HasMultipleFileSelection() const { return HasFlag( wxFC_MULTIPLE ); }
    virtual void ShowHidden(const bool show);

    bool    m_checkNextSelEvent;
    bool    m_ignoreNextFolderChangeEvent;

protected:
    GtkFileChooser     *m_fcWidget;
    wxGtkFileChooser    m_fc;
    wxString            m_wildCard;

    DECLARE_DYNAMIC_CLASS( wxGtkFileCtrl )
};

#endif // wxUSE_FILECTRL

#endif    // FILECTRL_H

