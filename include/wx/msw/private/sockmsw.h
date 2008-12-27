/////////////////////////////////////////////////////////////////////////////
// Name:       wx/msw/gsockmsw.h
// Purpose:    MSW-specific socket implementation
// Authors:    Guilhem Lavaux, Guillermo Rodriguez Garcia, Vadim Zeitlin
// Created:    April 1997
// Copyright:  (C) 1999-1997, Guilhem Lavaux
//             (C) 1999-2000, Guillermo Rodriguez Garcia
//             (C) 2008 Vadim Zeitlin
// RCS_ID:     $Id$
// License:    wxWindows licence
/////////////////////////////////////////////////////////////////////////////


#ifndef _WX_MSW_GSOCKMSW_H_
#define _WX_MSW_GSOCKMSW_H_

#include "wx/msw/wrapwin.h"

#if defined(__CYGWIN__)
    //CYGWIN gives annoying warning about runtime stuff if we don't do this
#   define USE_SYS_TYPES_FD_SET
#   include <sys/types.h>
#endif

#if defined(__WXWINCE__) || defined(__CYGWIN__)
    #include <winsock.h>
#endif

// ----------------------------------------------------------------------------
// MSW-specific socket implementation
// ----------------------------------------------------------------------------

class wxSocketImplMSW : public wxSocketImpl
{
public:
    wxSocketImplMSW(wxSocketBase& wxsocket);

    virtual ~wxSocketImplMSW();

    virtual wxSocketError GetLastError() const;

private:
    virtual void DoClose();

    virtual void UnblockAndRegisterWithEventLoop()
    {
        // no need to make the socket non-blocking, Install_Callback() will do
        // it
        wxSocketManager::Get()->Install_Callback(this);
    }

    int m_msgnumber;

    friend class wxSocketMSWManager;

    DECLARE_NO_COPY_CLASS(wxSocketImplMSW)
};

#endif  /* _WX_MSW_GSOCKMSW_H_ */
