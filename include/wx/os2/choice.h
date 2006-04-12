/////////////////////////////////////////////////////////////////////////////
// Name:        wx/os2/choice.h
// Purpose:     wxChoice class
// Author:      David Webster
// Modified by:
// Created:     10/13/99
// RCS-ID:      $Id$
// Copyright:   (c) David Webster
// Licence:     wxWindows licence
/////////////////////////////////////////////////////////////////////////////

#ifndef _WX_CHOICE_H_
#define _WX_CHOICE_H_

// ----------------------------------------------------------------------------
// Choice item
// ----------------------------------------------------------------------------

class WXDLLEXPORT wxChoice: public wxChoiceBase
{
  DECLARE_DYNAMIC_CLASS(wxChoice)

public:
    // ctors
    inline wxChoice() { Init(); }
    virtual ~wxChoice();

    inline wxChoice( wxWindow*          pParent
                    ,wxWindowID         vId
                    ,const wxPoint&     rPos = wxDefaultPosition
                    ,const wxSize&      rSize = wxDefaultSize
                    ,int                n = 0
                    ,const wxString     asChoices[] = NULL
                    ,long               lStyle = 0
                    ,const wxValidator& rValidator = wxDefaultValidator
                    ,const wxString&    rsName = wxChoiceNameStr
                   )
    {
        Init();
        Create( pParent
               ,vId
               ,rPos
               ,rSize
               ,n
               ,asChoices
               ,lStyle
               ,rValidator
               ,rsName
              );
    }

    inline wxChoice( wxWindow*            pParent
                    ,wxWindowID           vId
                    ,const wxPoint&       rPos
                    ,const wxSize&        rSize
                    ,const wxArrayString& asChoices
                    ,long                 lStyle = 0
                    ,const wxValidator&   rValidator = wxDefaultValidator
                    ,const wxString&      rsName = wxChoiceNameStr
                   )
    {
        Init();
        Create( pParent
               ,vId
               ,rPos
               ,rSize
               ,asChoices
               ,lStyle
               ,rValidator
               ,rsName
              );
    }

    bool Create( wxWindow*          pParent
                ,wxWindowID         vId
                ,const wxPoint&     rPos = wxDefaultPosition
                ,const wxSize&      rSize = wxDefaultSize
                ,int                n = 0
                ,const wxString     asChoices[] = NULL
                ,long               lStyle = 0
                ,const wxValidator& rValidator = wxDefaultValidator
                ,const wxString&    rsName = wxChoiceNameStr
               );

    bool Create( wxWindow*            pParent
                ,wxWindowID           vId
                ,const wxPoint&       rPos
                ,const wxSize&        rSize
                ,const wxArrayString& asChoices
                ,long                 lStyle = 0
                ,const wxValidator&   rValidator = wxDefaultValidator
                ,const wxString&      rsName = wxChoiceNameStr
               );

    //
    // Implement base class virtuals
    //
    virtual void     Delete(unsigned int n);
    virtual void     Clear(void);

    virtual unsigned int GetCount() const;
    virtual int      GetSelection(void) const;
    virtual int      GetCurrentSelection(void) const;
    virtual void     SetSelection(int n);

    virtual wxString GetString(unsigned int n) const;
    virtual void     SetString(unsigned int n, const wxString& rsStr);

    //
    // OS2 only
    //
    virtual bool     OS2Command( WXUINT uParam
                                ,WXWORD wId
                               );
    MRESULT          OS2WindowProc( WXUINT   uMsg
                                   ,WXWPARAM wParam
                                   ,WXLPARAM lParam
                                  );

protected:
    // common part of all ctors
    void Init() { m_lastAcceptedSelection = wxID_NONE; }

    virtual int           DoAppend(const wxString& rsItem);
    virtual int           DoInsert(const wxString& rsItem, unsigned int pos);
    virtual void          DoSetItemClientData(unsigned int n, void* pClientData);
    virtual void*         DoGetItemClientData(unsigned int n) const;
    virtual void          DoSetItemClientObject(unsigned int n, wxClientData* pClientData);
    virtual wxClientData* DoGetItemClientObject(unsigned int n) const;
    virtual wxSize        DoGetBestSize(void) const;
    virtual void          DoSetSize( int nX
                                    ,int nY
                                    ,int nWidth
                                    ,int nHeight
                                    ,int nsizeFlags = wxSIZE_AUTO
                                   );
    void                  Free(void);

    // last "completed" selection, i.e. not the transient one while the user is
    // browsing the popup list: this is only used when != wxID_NONE which is
    // the case while the drop down is opened
    int m_lastAcceptedSelection;
}; // end of CLASS wxChoice

#endif // _WX_CHOICE_H_
