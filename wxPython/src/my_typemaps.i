/////////////////////////////////////////////////////////////////////////////
// Name:        my_typemaps.i
// Purpose:     Special typemaps specifically for wxPython.
//
// Author:      Robin Dunn
//
// Created:     7/3/97
// RCS-ID:      $Id$
// Copyright:   (c) 1998 by Total Control Software
// Licence:     wxWindows license
/////////////////////////////////////////////////////////////////////////////


//---------------------------------------------------------------------------
// Tell SWIG to wrap all the wrappers with Python's thread macros

%except(python) {
    wxPy_BEGIN_ALLOW_THREADS;
    $function
    wxPy_END_ALLOW_THREADS;
    if (PyErr_Occurred()) return NULL;
}

//----------------------------------------------------------------------
// LCOUNT and choices go together.  They allow a single Python list to be
// converted to an integer count and an array count items long.

%typemap(python,build) int LCOUNT {
    if (_in_choices) {
        $target = PyList_Size(_in_choices);
    }
    else {
        $target = 0;
    }
}



%typemap(python,in) byte* choices  {
    $target = byte_LIST_helper($source);
    if ($target == NULL) {
        return NULL;
    }
}
%typemap(python,freearg) byte* choices {
    delete [] $source;
}

// wxDash is a signed char
%typemap(python,in) wxDash* choices  {
    $target = (wxDash*)byte_LIST_helper($source);
    if ($target == NULL) {
        return NULL;
    }
}
%typemap(python,freearg) wxDash* choices {
    delete [] $source;
}


%typemap(python,in) int* choices  {
    $target = int_LIST_helper($source);
    if ($target == NULL) {
        return NULL;
    }
}
%typemap(python,freearg) int* choices {
    delete [] $source;
}


%typemap(python,in) long* choices {
    $target = long_LIST_helper($source);
    if ($target == NULL) {
        return NULL;
    }
}
%typemap(python,freearg) long* choices {
    delete [] $source;
}


%typemap(python,in) unsigned long* choices {
    $target = (unsigned long*)long_LIST_helper($source);
    if ($target == NULL) {
        return NULL;
    }
}
%typemap(python,freearg) unsigned long* choices {
    delete [] $source;
}


%typemap(python,in) char** choices {
    $target = string_LIST_helper($source);
    if ($target == NULL) {
        return NULL;
    }
}
%typemap(python,freearg) char** choices {
    delete [] $source;
}


%typemap(python,in) wxBitmap** choices  {
    $target = wxBitmap_LIST_helper($source);
    if ($target == NULL) {
        return NULL;
    }
}
%typemap(python,freearg) wxBitmap** choices {
    delete [] $source;
}

%typemap(python,in) wxString* choices  {
    $target = wxString_LIST_helper($source);
    if ($target == NULL) {
        return NULL;
    }
}
%typemap(python,freearg) wxString* choices {
    delete [] $source;
}

%typemap(python,in) wxAcceleratorEntry* choices  {
    $target = wxAcceleratorEntry_LIST_helper($source);
    if ($target == NULL) {
        return NULL;
    }
}
%typemap(python,freearg) wxAcceleratorEntry* choices {
    delete [] $source;
}

%typemap(python,build) int PCOUNT {
	$target = NPOINTS;
}

%typemap(python,in) wxPoint* points (int NPOINTS) {
    $target = wxPoint_LIST_helper($source, &NPOINTS);
	if ($target == NULL) {
		return NULL;
	}
}
%typemap(python,freearg) wxPoint* points {
    delete [] $source;
}




//---------------------------------------------------------------------------

%{
#if PYTHON_API_VERSION >= 1009
    static char* wxStringErrorMsg = "String or Unicode type required";
#else
    static char* wxStringErrorMsg = "String type required";
#endif
%}

// TODO:  Which works best???

// Implementation #1
//  %typemap(python, in) wxString& (PyObject* temp, int tmpDoDecRef) {
//      temp = $source;
//      tmpDoDecRef = 0;
//  #if PYTHON_API_VERSION >= 1009
//      if (PyUnicode_Check(temp) {
//          temp = PyUnicode_AsUTF8String(temp);
//          if (! temp) {
//              PyErr_SetString(PyExc_TypeError, "Unicode encoding to UTF8 failed.");
//              return NULL;
//          }
//          tmpDoDecRef = 1;
//  #endif
//      if (!PyString_Check(temp)) {
//          PyErr_SetString(PyExc_TypeError, wxStringErrorMsg);
//          return NULL;
//      }
//      $target = new wxString(PyString_AsString(temp), PyString_Size(temp));
//  #if PYTHON_API_VERESION >= 1009
//      if (tmpDoDecRef) Py_DECREF(temp);
//  #endif
//  }


// Implementation #2
%typemap(python, in) wxString& {
#if PYTHON_API_VERSION >= 1009
    char* tmpPtr; int tmpSize;
    if (!PyString_Check($source) && !PyUnicode_Check($source)) {
        PyErr_SetString(PyExc_TypeError, wxStringErrorMsg);
        return NULL;
    }
    if (PyString_AsStringAndSize($source, &tmpPtr, &tmpSize) == -1)
        return NULL;
    $target = new wxString(tmpPtr, tmpSize);
#else
    if (!PyString_Check($source)) {
        PyErr_SetString(PyExc_TypeError, wxStringErrorMsg);
        return NULL;
    }
    $target = new wxString(PyString_AS_STRING($source), PyString_GET_SIZE($source));
#endif
}




%typemap(python, freearg) wxString& {
    if ($target)
        delete $source;
}



%typemap(python, out) wxString {
    $target = PyString_FromStringAndSize($source->c_str(), $source->Len());
}
%typemap(python, ret) wxString {
    delete $source;
}


%typemap(python, out) wxString* {
    $target = PyString_FromStringAndSize($source->c_str(), $source->Len());
}





//---------------------------------------------------------------------------
// Typemaps to convert Python sequence objects (tuples, etc.) to
// wxSize, wxPoint, wxRealPoint, and wxRect.

%typemap(python,in) wxSize& (wxSize temp) {
    $target = &temp;
    if (! wxSize_helper($source, &$target))
        return NULL;
}

%typemap(python,in) wxPoint& (wxPoint temp) {
    $target = &temp;
    if (! wxPoint_helper($source, &$target))
        return NULL;
}

%typemap(python,in) wxRealPoint& (wxRealPoint temp) {
    $target = &temp;
    if (! wxRealPoint_helper($source, &$target))
        return NULL;
}

%typemap(python,in) wxRect& (wxRect temp) {
    $target = &temp;
    if (! wxRect_helper($source, &$target))
        return NULL;
}

//---------------------------------------------------------------------------
// Typemap to convert strings to wxColour.  Two string formats are accepted,
// either a colour name, or a hex colour spec like "#RRGGBB"

%typemap(python,in) wxColour& (wxColour temp) {
    $target = &temp;
    if (! wxColour_helper($source, &$target))
        return NULL;
}

//---------------------------------------------------------------------------
// Typemap for wxArrayString from Python sequence objects

%typemap(python,in) wxArrayString& {
    if (! PySequence_Check($source)) {
        PyErr_SetString(PyExc_TypeError, "Sequence of strings expected.");
        return NULL;
    }
    $target = new wxArrayString;
    int i, len=PySequence_Length($source);
    for (i=0; i<len; i++) {
        PyObject* item = PySequence_GetItem($source, i);
        PyObject* str  = PyObject_Str(item);
        $target->Add(PyString_AsString(item));
        Py_DECREF(item);
        Py_DECREF(str);
    }
}

%typemap(python, freearg) wxArrayString& {
    if ($target)
        delete $source;
}

//---------------------------------------------------------------------------
// Map T_OUTPUTs for floats to return ints.


%typemap(python,ignore) float          *T_OUTPUT_TOINT(float temp),
                        double         *T_OUTPUT_TOINT(double temp)
{
  $target = &temp;
}


%typemap(python,argout) float          *T_OUTPUT_TOINT,
                        double         *T_OUTPUT_TOINT
{
    PyObject *o;
    o = PyInt_FromLong((long) (*$source));
    $target = t_output_helper($target, o);
}

//---------------------------------------------------------------------------
// Typemaps to convert return values that are base class pointers
// to the real derived type, if possible.  See wxPyMake_wxObject in
// helpers.cpp

%typemap(python, out) wxEvtHandler*             { $target = wxPyMake_wxObject($source); }
%typemap(python, out) wxMenu*                   { $target = wxPyMake_wxObject($source); }
%typemap(python, out) wxValidator*              { $target = wxPyMake_wxObject($source); }

%typemap(python, out) wxDC*                     { $target = wxPyMake_wxObject($source); }
%typemap(python, out) wxFSFile*                 { $target = wxPyMake_wxObject($source); }
%typemap(python, out) wxFileSystem*             { $target = wxPyMake_wxObject($source); }
%typemap(python, out) wxGridTableBase*          { $target = wxPyMake_wxObject($source); }
%typemap(python, out) wxImageList*              { $target = wxPyMake_wxObject($source); }
%typemap(python, out) wxListItem*               { $target = wxPyMake_wxObject($source); }
%typemap(python, out) wxMenuItem*               { $target = wxPyMake_wxObject($source); }
%typemap(python, out) wxMouseEvent*             { $target = wxPyMake_wxObject($source); }
%typemap(python, out) wxObject*                 { $target = wxPyMake_wxObject($source); }
%typemap(python, out) wxPyPrintout*             { $target = wxPyMake_wxObject($source); }
%typemap(python, out) wxSizer*                  { $target = wxPyMake_wxObject($source); }
%typemap(python, out) wxToolBarToolBase*        { $target = wxPyMake_wxObject($source); }
%typemap(python, out) wxToolTip*                { $target = wxPyMake_wxObject($source); }


%typemap(python, out) wxButton*                 { $target = wxPyMake_wxObject($source); }
%typemap(python, out) wxControl*                { $target = wxPyMake_wxObject($source); }
%typemap(python, out) wxFrame*                  { $target = wxPyMake_wxObject($source); }
%typemap(python, out) wxGrid*                   { $target = wxPyMake_wxObject($source); }
%typemap(python, out) wxMDIChildFrame*          { $target = wxPyMake_wxObject($source); }
%typemap(python, out) wxMDIClientWindow*        { $target = wxPyMake_wxObject($source); }
%typemap(python, out) wxMenuBar*                { $target = wxPyMake_wxObject($source); }
%typemap(python, out) wxNotebook*               { $target = wxPyMake_wxObject($source); }
%typemap(python, out) wxStaticBox*              { $target = wxPyMake_wxObject($source); }
%typemap(python, out) wxStatusBar*              { $target = wxPyMake_wxObject($source); }
%typemap(python, out) wxTextCtrl*               { $target = wxPyMake_wxObject($source); }
%typemap(python, out) wxToolBar*                { $target = wxPyMake_wxObject($source); }
%typemap(python, out) wxToolBarBase*            { $target = wxPyMake_wxObject($source); }
%typemap(python, out) wxWindow*                 { $target = wxPyMake_wxObject($source); }


//%typemap(python, out) wxHtmlCell*               { $target = wxPyMake_wxObject($source); }
//%typemap(python, out) wxHtmlContainerCell*      { $target = wxPyMake_wxObject($source); }
//%typemap(python, out) wxHtmlParser*             { $target = wxPyMake_wxObject($source); }
//%typemap(python, out) wxHtmlWinParser*          { $target = wxPyMake_wxObject($source); }

//---------------------------------------------------------------------------
//---------------------------------------------------------------------------






