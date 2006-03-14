///////////////////////////////////////////////////////////////////////////////
// Name:        wx/univ/combobox.h
// Purpose:     the universal combobox
// Author:      Vadim Zeitlin
// Modified by:
// Created:     30.08.00
// RCS-ID:      $Id$
// Copyright:   (c) 2000 SciTech Software, Inc. (www.scitechsoft.com)
// Licence:     wxWindows licence
///////////////////////////////////////////////////////////////////////////////

/*
   A few words about all the classes defined in this file are probably in
   order: why do we need extra wxComboControl and wxComboPopup classes?

   This is because a traditional combobox is a combination of a text control
   (with a button allowing to open the pop down list) with a listbox and
   wxComboBox class is exactly such control, however we want to also have other
   combinations - in fact, we want to allow anything at all to be used as pop
   down list, not just a wxListBox.

   So we define a base wxComboControl which can use any control as pop down
   list and wxComboBox deriving from it which implements the standard wxWidgets
   combobox API. wxComboControl needs to be told somehow which control to use
   and this is done by SetPopupControl(). However, we need something more than
   just a wxControl in this method as, for example, we need to call
   SetSelection("initial text value") and wxControl doesn't have such method.
   So we also need a wxComboPopup which is just a very simple interface which
   must be implemented by a control to be usable as a popup.

   We couldn't derive wxComboPopup from wxControl as this would make it
   impossible to have a class deriving from both wxListBx and from it, so
   instead it is just a mix-in.
 */

#ifndef _WX_UNIV_COMBOBOX_H_
#define _WX_UNIV_COMBOBOX_H_

class WXDLLEXPORT wxComboControl;
class WXDLLEXPORT wxListBox;
class WXDLLEXPORT wxPopupComboWindow;
class WXDLLEXPORT wxTextCtrl;
class WXDLLEXPORT wxButton;

// ----------------------------------------------------------------------------
// the actions supported by this control
// ----------------------------------------------------------------------------

// all actions of single line text controls are supported

// popup/dismiss the choice window
#define wxACTION_COMBOBOX_POPUP     _T("popup")
#define wxACTION_COMBOBOX_DISMISS   _T("dismiss")

// choose the next/prev/specified (by numArg) item
#define wxACTION_COMBOBOX_SELECT_NEXT _T("next")
#define wxACTION_COMBOBOX_SELECT_PREV _T("prev")
#define wxACTION_COMBOBOX_SELECT      _T("select")

// ----------------------------------------------------------------------------
// wxComboPopup is the interface which must be implemented by a control to be
// used as a popup by wxComboControl
// ----------------------------------------------------------------------------

class WXDLLEXPORT wxComboPopup
{
public:
    wxComboPopup(wxComboControl *combo) { m_combo = combo; }
    virtual ~wxComboPopup() {}

    // we must have an associated control which is subclassed by the combobox
    virtual wxControl *GetControl() = 0;

    // called before showing the control to set the initial selection - notice
    // that the text passed to this method might not correspond to any valid
    // item (if the user edited it directly), in which case the method should
    // just return false but not emit any errors
    virtual bool SetSelection(const wxString& value) = 0;

    // called immediately after the control is shown
    virtual void OnShow() = 0;

    virtual wxCoord GetBestWidth() const {return 0; }

protected:
    wxComboControl *m_combo;
};

// ----------------------------------------------------------------------------
// wxComboControl: a combination of a (single line) text control with a button
// opening a popup window which contains the control from which the user can
// choose the value directly.
// ----------------------------------------------------------------------------

class WXDLLEXPORT wxComboControl : public wxControl
{
public:
    // construction
    wxComboControl()
    {
        Init();
    }

    wxComboControl(wxWindow *parent,
                   wxWindowID id,
                   const wxString& value = wxEmptyString,
                   const wxPoint& pos = wxDefaultPosition,
                   const wxSize& size = wxDefaultSize,
                   long style = 0,
                   const wxValidator& validator = wxDefaultValidator,
                   const wxString& name = wxComboBoxNameStr)
    {
        Init();

        (void)Create(parent, id, value, pos, size, style, validator, name);
    }

    bool Create(wxWindow *parent,
                wxWindowID id,
                const wxString& value = wxEmptyString,
                const wxPoint& pos = wxDefaultPosition,
                const wxSize& size = wxDefaultSize,
                long style = 0,
                const wxValidator& validator = wxDefaultValidator,
                const wxString& name = wxComboBoxNameStr);

    virtual ~wxComboControl();

    // a combo control needs a control for popup window it displays
    void SetPopupControl(wxComboPopup *popup);
    wxComboPopup *GetPopupControl() const { return m_popup; }

    // show/hide popup window
    void ShowPopup();
    void HidePopup();

    // return true if the popup is currently shown
    bool IsPopupShown() const { return m_isPopupShown; }

    // get the popup window containing the popup control
    wxPopupComboWindow *GetPopupWindow() const { return m_winPopup; }

    // get the text control which is part of the combobox
    wxTextCtrl *GetText() const { return m_text; }

    // implementation only from now on
    // -------------------------------

    // notifications from wxComboPopup (shouldn't be called by anybody else)

    // called when the user selects something in the popup: this normally hides
    // the popup and sets the text to the new value
    virtual void OnSelect(const wxString& value);

    // called when the user dismisses the popup
    virtual void OnDismiss();

    // forward these functions to all subcontrols
    virtual bool Enable(bool enable = true);
    virtual bool Show(bool show = true);

#if wxUSE_TOOLTIPS
    virtual void DoSetToolTip( wxToolTip *tip );
#endif // wxUSE_TOOLTIPS

    // we have our own input handler and our own actions
    virtual bool PerformAction(const wxControlAction& action,
                               long numArg = 0l,
                               const wxString& strArg = wxEmptyString);

protected:
    // override the base class virtuals involved into geometry calculations
    virtual wxSize DoGetBestClientSize() const;
    virtual void DoMoveWindow(int x, int y, int width, int height);
    virtual void DoSetSize(int x, int y,
                           int width, int height,
                           int sizeFlags = wxSIZE_AUTO);

    // event handlers
    void OnKey(wxKeyEvent& event);

    // common part of all ctors
    void Init();

private:
    // the text control and button we show all the time
    wxTextCtrl *m_text;
    wxButton *m_btn;

    // the popup control
    wxComboPopup *m_popup;

    // and the popup window containing it
    wxPopupComboWindow *m_winPopup;

    // the height of the combobox popup as calculated in Create()
    wxCoord m_heightPopup;

    // is the popup window currenty shown?
    bool m_isPopupShown;

    DECLARE_EVENT_TABLE()
};

// ----------------------------------------------------------------------------
// wxComboBox: a combination of text control and a listbox
// ----------------------------------------------------------------------------

class WXDLLEXPORT wxComboBox : public wxComboControl, public wxComboBoxBase
{
public:
    // ctors and such
    wxComboBox() { Init(); }

    wxComboBox(wxWindow *parent,
               wxWindowID id,
               const wxString& value = wxEmptyString,
               const wxPoint& pos = wxDefaultPosition,
               const wxSize& size = wxDefaultSize,
               int n = 0,
               const wxString choices[] = (const wxString *) NULL,
               long style = 0,
               const wxValidator& validator = wxDefaultValidator,
               const wxString& name = wxComboBoxNameStr)
    {
        Init();

        (void)Create(parent, id, value, pos, size, n, choices,
                     style, validator, name);
    }
    wxComboBox(wxWindow *parent,
               wxWindowID id,
               const wxString& value,
               const wxPoint& pos,
               const wxSize& size,
               const wxArrayString& choices,
               long style = 0,
               const wxValidator& validator = wxDefaultValidator,
               const wxString& name = wxComboBoxNameStr);

    bool Create(wxWindow *parent,
                wxWindowID id,
                const wxString& value = wxEmptyString,
                const wxPoint& pos = wxDefaultPosition,
                const wxSize& size = wxDefaultSize,
                int n = 0,
                const wxString choices[] = (const wxString *) NULL,
                long style = 0,
                const wxValidator& validator = wxDefaultValidator,
                const wxString& name = wxComboBoxNameStr);
    bool Create(wxWindow *parent,
                wxWindowID id,
                const wxString& value,
                const wxPoint& pos,
                const wxSize& size,
                const wxArrayString& choices,
                long style = 0,
                const wxValidator& validator = wxDefaultValidator,
                const wxString& name = wxComboBoxNameStr);

    virtual ~wxComboBox();

    // the wxUniversal-specific methods
    // --------------------------------

    // implement the combobox interface

    // wxTextCtrl methods
    virtual wxString GetValue() const;
    virtual void SetValue(const wxString& value);
    virtual void Copy();
    virtual void Cut();
    virtual void Paste();
    virtual void SetInsertionPoint(long pos);
    virtual void SetInsertionPointEnd();
    virtual long GetInsertionPoint() const;
    virtual wxTextPos GetLastPosition() const;
    virtual void Replace(long from, long to, const wxString& value);
    virtual void Remove(long from, long to);
    virtual void SetSelection(long from, long to);
    virtual void SetEditable(bool editable);
    virtual bool IsEditable() const;

    virtual void Undo();
    virtual void Redo();
    virtual void SelectAll();

    virtual bool CanCopy() const;
    virtual bool CanCut() const;
    virtual bool CanPaste() const;
    virtual bool CanUndo() const;
    virtual bool CanRedo() const;

    // wxControlWithItems methods
    virtual void Clear();
    virtual void Delete(int n);
    virtual size_t GetCount() const;
    virtual wxString GetString(int n) const;
    virtual void SetString(int n, const wxString& s);
    virtual int FindString(const wxString& s, bool bCase = false) const;
    virtual void SetSelection(int n);
    virtual int GetSelection() const;

    wxCONTROL_ITEMCONTAINER_CLIENTDATAOBJECT_RECAST

protected:
    virtual int DoAppend(const wxString& item);
    virtual int DoInsert(const wxString& item, int pos);
    virtual void DoSetItemClientData(int n, void* clientData);
    virtual void* DoGetItemClientData(int n) const;
    virtual void DoSetItemClientObject(int n, wxClientData* clientData);
    virtual wxClientData* DoGetItemClientObject(int n) const;

    // common part of all ctors
    void Init();

    // get the associated listbox
    wxListBox *GetLBox() const { return m_lbox; }

private:
    // the popup listbox
    wxListBox *m_lbox;

    //DECLARE_EVENT_TABLE()
    DECLARE_DYNAMIC_CLASS(wxComboBox)
};

// ----------------------------------------------------------------------------
// wxStdComboBoxInputHandler: allows the user to open/close the combo from kbd
// ----------------------------------------------------------------------------

class WXDLLEXPORT wxStdComboBoxInputHandler : public wxStdInputHandler
{
public:
    wxStdComboBoxInputHandler(wxInputHandler *inphand);

    virtual bool HandleKey(wxInputConsumer *consumer,
                           const wxKeyEvent& event,
                           bool pressed);
};

#endif // _WX_UNIV_COMBOBOX_H_
