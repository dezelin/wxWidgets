# Microsoft Developer Studio Project File - Name="test_printfbench" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Console Application" 0x0103

CFG=printfbench - Win32 Debug
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "test_printfbench.mak".
!MESSAGE 
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "test_printfbench.mak" CFG="printfbench - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "printfbench - Win32 DLL Universal Release" (based on "Win32 (x86) Console Application")
!MESSAGE "printfbench - Win32 DLL Universal Debug" (based on "Win32 (x86) Console Application")
!MESSAGE "printfbench - Win32 DLL Release" (based on "Win32 (x86) Console Application")
!MESSAGE "printfbench - Win32 DLL Debug" (based on "Win32 (x86) Console Application")
!MESSAGE "printfbench - Win32 Universal Release" (based on "Win32 (x86) Console Application")
!MESSAGE "printfbench - Win32 Universal Debug" (based on "Win32 (x86) Console Application")
!MESSAGE "printfbench - Win32 Release" (based on "Win32 (x86) Console Application")
!MESSAGE "printfbench - Win32 Debug" (based on "Win32 (x86) Console Application")
!MESSAGE 

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName ""
# PROP Scc_LocalPath ""
CPP=cl.exe
RSC=rc.exe

!IF  "$(CFG)" == "printfbench - Win32 DLL Universal Release"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "vc6_mswunivudll"
# PROP BASE Intermediate_Dir "vc6_mswunivudll\printfbench"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "vc6_mswunivudll"
# PROP Intermediate_Dir "vc6_mswunivudll\printfbench"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /FD /MD /Zi /Fdvc6_mswunivudll\printfbench.pdb /O2 /GR /EHsc /I ".\..\lib\vc6_dll\mswunivu" /I ".\..\include" /W4 /I "." /Yu"testprec.h" /Fp"vc6_mswunivudll\testprec_printfbench.pch" /D "WIN32" /D "__WXMSW__" /D "__WXUNIVERSAL__" /D "_UNICODE" /D "WXUSINGDLL" /D "_CONSOLE" /D wxUSE_GUI=0 /c
# ADD CPP /nologo /FD /MD /Zi /Fdvc6_mswunivudll\printfbench.pdb /O2 /GR /EHsc /I ".\..\lib\vc6_dll\mswunivu" /I ".\..\include" /W4 /I "." /Yu"testprec.h" /Fp"vc6_mswunivudll\testprec_printfbench.pch" /D "WIN32" /D "__WXMSW__" /D "__WXUNIVERSAL__" /D "_UNICODE" /D "WXUSINGDLL" /D "_CONSOLE" /D wxUSE_GUI=0 /c
# ADD BASE RSC /l 0x409 /d "__WXMSW__" /d "__WXUNIVERSAL__" /d "_UNICODE" /i ".\..\lib\vc6_dll\mswunivu" /i ".\..\include" /i "." /d "WXUSINGDLL" /d "_CONSOLE" /d wxUSE_GUI=0
# ADD RSC /l 0x409 /d "__WXMSW__" /d "__WXUNIVERSAL__" /d "_UNICODE" /i ".\..\lib\vc6_dll\mswunivu" /i ".\..\include" /i "." /d "WXUSINGDLL" /d "_CONSOLE" /d wxUSE_GUI=0
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 wxbase29u.lib wxzlib.lib wxregexu.lib wxexpat.lib kernel32.lib user32.lib gdi32.lib comdlg32.lib winspool.lib winmm.lib shell32.lib comctl32.lib ole32.lib oleaut32.lib uuid.lib rpcrt4.lib advapi32.lib wsock32.lib /nologo /machine:i386 /out:"vc6_mswunivudll\printfbench.exe" /debug /pdb:"vc6_mswunivudll\printfbench.pdb" /libpath:".\..\lib\vc6_dll" /subsystem:console
# ADD LINK32 wxbase29u.lib wxzlib.lib wxregexu.lib wxexpat.lib kernel32.lib user32.lib gdi32.lib comdlg32.lib winspool.lib winmm.lib shell32.lib comctl32.lib ole32.lib oleaut32.lib uuid.lib rpcrt4.lib advapi32.lib wsock32.lib /nologo /machine:i386 /out:"vc6_mswunivudll\printfbench.exe" /debug /pdb:"vc6_mswunivudll\printfbench.pdb" /libpath:".\..\lib\vc6_dll" /subsystem:console

!ELSEIF  "$(CFG)" == "printfbench - Win32 DLL Universal Debug"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "vc6_mswunivuddll"
# PROP BASE Intermediate_Dir "vc6_mswunivuddll\printfbench"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "vc6_mswunivuddll"
# PROP Intermediate_Dir "vc6_mswunivuddll\printfbench"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /FD /MDd /Zi /Fdvc6_mswunivuddll\printfbench.pdb /Od /Gm /GR /EHsc /I ".\..\lib\vc6_dll\mswunivud" /I ".\..\include" /W4 /I "." /Yu"testprec.h" /Fp"vc6_mswunivuddll\testprec_printfbench.pch" /D "WIN32" /D "_DEBUG" /D "__WXMSW__" /D "__WXUNIVERSAL__" /D "__WXDEBUG__" /D "_UNICODE" /D "WXUSINGDLL" /D "_CONSOLE" /D wxUSE_GUI=0 /c
# ADD CPP /nologo /FD /MDd /Zi /Fdvc6_mswunivuddll\printfbench.pdb /Od /Gm /GR /EHsc /I ".\..\lib\vc6_dll\mswunivud" /I ".\..\include" /W4 /I "." /Yu"testprec.h" /Fp"vc6_mswunivuddll\testprec_printfbench.pch" /D "WIN32" /D "_DEBUG" /D "__WXMSW__" /D "__WXUNIVERSAL__" /D "__WXDEBUG__" /D "_UNICODE" /D "WXUSINGDLL" /D "_CONSOLE" /D wxUSE_GUI=0 /c
# ADD BASE RSC /l 0x409 /d "_DEBUG" /d "__WXMSW__" /d "__WXUNIVERSAL__" /d "__WXDEBUG__" /d "_UNICODE" /i ".\..\lib\vc6_dll\mswunivud" /i ".\..\include" /i "." /d "WXUSINGDLL" /d "_CONSOLE" /d wxUSE_GUI=0
# ADD RSC /l 0x409 /d "_DEBUG" /d "__WXMSW__" /d "__WXUNIVERSAL__" /d "__WXDEBUG__" /d "_UNICODE" /i ".\..\lib\vc6_dll\mswunivud" /i ".\..\include" /i "." /d "WXUSINGDLL" /d "_CONSOLE" /d wxUSE_GUI=0
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 wxbase29ud.lib wxzlibd.lib wxregexud.lib wxexpatd.lib kernel32.lib user32.lib gdi32.lib comdlg32.lib winspool.lib winmm.lib shell32.lib comctl32.lib ole32.lib oleaut32.lib uuid.lib rpcrt4.lib advapi32.lib wsock32.lib /nologo /machine:i386 /out:"vc6_mswunivuddll\printfbench.exe" /debug /pdb:"vc6_mswunivuddll\printfbench.pdb" /libpath:".\..\lib\vc6_dll" /subsystem:console
# ADD LINK32 wxbase29ud.lib wxzlibd.lib wxregexud.lib wxexpatd.lib kernel32.lib user32.lib gdi32.lib comdlg32.lib winspool.lib winmm.lib shell32.lib comctl32.lib ole32.lib oleaut32.lib uuid.lib rpcrt4.lib advapi32.lib wsock32.lib /nologo /machine:i386 /out:"vc6_mswunivuddll\printfbench.exe" /debug /pdb:"vc6_mswunivuddll\printfbench.pdb" /libpath:".\..\lib\vc6_dll" /subsystem:console

!ELSEIF  "$(CFG)" == "printfbench - Win32 DLL Release"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "vc6_mswudll"
# PROP BASE Intermediate_Dir "vc6_mswudll\printfbench"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "vc6_mswudll"
# PROP Intermediate_Dir "vc6_mswudll\printfbench"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /FD /MD /Zi /Fdvc6_mswudll\printfbench.pdb /O2 /GR /EHsc /I ".\..\lib\vc6_dll\mswu" /I ".\..\include" /W4 /I "." /Yu"testprec.h" /Fp"vc6_mswudll\testprec_printfbench.pch" /D "WIN32" /D "__WXMSW__" /D "_UNICODE" /D "WXUSINGDLL" /D "_CONSOLE" /D wxUSE_GUI=0 /c
# ADD CPP /nologo /FD /MD /Zi /Fdvc6_mswudll\printfbench.pdb /O2 /GR /EHsc /I ".\..\lib\vc6_dll\mswu" /I ".\..\include" /W4 /I "." /Yu"testprec.h" /Fp"vc6_mswudll\testprec_printfbench.pch" /D "WIN32" /D "__WXMSW__" /D "_UNICODE" /D "WXUSINGDLL" /D "_CONSOLE" /D wxUSE_GUI=0 /c
# ADD BASE RSC /l 0x409 /d "__WXMSW__" /d "_UNICODE" /i ".\..\lib\vc6_dll\mswu" /i ".\..\include" /i "." /d "WXUSINGDLL" /d "_CONSOLE" /d wxUSE_GUI=0
# ADD RSC /l 0x409 /d "__WXMSW__" /d "_UNICODE" /i ".\..\lib\vc6_dll\mswu" /i ".\..\include" /i "." /d "WXUSINGDLL" /d "_CONSOLE" /d wxUSE_GUI=0
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 wxbase29u.lib wxzlib.lib wxregexu.lib wxexpat.lib kernel32.lib user32.lib gdi32.lib comdlg32.lib winspool.lib winmm.lib shell32.lib comctl32.lib ole32.lib oleaut32.lib uuid.lib rpcrt4.lib advapi32.lib wsock32.lib /nologo /machine:i386 /out:"vc6_mswudll\printfbench.exe" /debug /pdb:"vc6_mswudll\printfbench.pdb" /libpath:".\..\lib\vc6_dll" /subsystem:console
# ADD LINK32 wxbase29u.lib wxzlib.lib wxregexu.lib wxexpat.lib kernel32.lib user32.lib gdi32.lib comdlg32.lib winspool.lib winmm.lib shell32.lib comctl32.lib ole32.lib oleaut32.lib uuid.lib rpcrt4.lib advapi32.lib wsock32.lib /nologo /machine:i386 /out:"vc6_mswudll\printfbench.exe" /debug /pdb:"vc6_mswudll\printfbench.pdb" /libpath:".\..\lib\vc6_dll" /subsystem:console

!ELSEIF  "$(CFG)" == "printfbench - Win32 DLL Debug"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "vc6_mswuddll"
# PROP BASE Intermediate_Dir "vc6_mswuddll\printfbench"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "vc6_mswuddll"
# PROP Intermediate_Dir "vc6_mswuddll\printfbench"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /FD /MDd /Zi /Fdvc6_mswuddll\printfbench.pdb /Od /Gm /GR /EHsc /I ".\..\lib\vc6_dll\mswud" /I ".\..\include" /W4 /I "." /Yu"testprec.h" /Fp"vc6_mswuddll\testprec_printfbench.pch" /D "WIN32" /D "_DEBUG" /D "__WXMSW__" /D "__WXDEBUG__" /D "_UNICODE" /D "WXUSINGDLL" /D "_CONSOLE" /D wxUSE_GUI=0 /c
# ADD CPP /nologo /FD /MDd /Zi /Fdvc6_mswuddll\printfbench.pdb /Od /Gm /GR /EHsc /I ".\..\lib\vc6_dll\mswud" /I ".\..\include" /W4 /I "." /Yu"testprec.h" /Fp"vc6_mswuddll\testprec_printfbench.pch" /D "WIN32" /D "_DEBUG" /D "__WXMSW__" /D "__WXDEBUG__" /D "_UNICODE" /D "WXUSINGDLL" /D "_CONSOLE" /D wxUSE_GUI=0 /c
# ADD BASE RSC /l 0x409 /d "_DEBUG" /d "__WXMSW__" /d "__WXDEBUG__" /d "_UNICODE" /i ".\..\lib\vc6_dll\mswud" /i ".\..\include" /i "." /d "WXUSINGDLL" /d "_CONSOLE" /d wxUSE_GUI=0
# ADD RSC /l 0x409 /d "_DEBUG" /d "__WXMSW__" /d "__WXDEBUG__" /d "_UNICODE" /i ".\..\lib\vc6_dll\mswud" /i ".\..\include" /i "." /d "WXUSINGDLL" /d "_CONSOLE" /d wxUSE_GUI=0
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 wxbase29ud.lib wxzlibd.lib wxregexud.lib wxexpatd.lib kernel32.lib user32.lib gdi32.lib comdlg32.lib winspool.lib winmm.lib shell32.lib comctl32.lib ole32.lib oleaut32.lib uuid.lib rpcrt4.lib advapi32.lib wsock32.lib /nologo /machine:i386 /out:"vc6_mswuddll\printfbench.exe" /debug /pdb:"vc6_mswuddll\printfbench.pdb" /libpath:".\..\lib\vc6_dll" /subsystem:console
# ADD LINK32 wxbase29ud.lib wxzlibd.lib wxregexud.lib wxexpatd.lib kernel32.lib user32.lib gdi32.lib comdlg32.lib winspool.lib winmm.lib shell32.lib comctl32.lib ole32.lib oleaut32.lib uuid.lib rpcrt4.lib advapi32.lib wsock32.lib /nologo /machine:i386 /out:"vc6_mswuddll\printfbench.exe" /debug /pdb:"vc6_mswuddll\printfbench.pdb" /libpath:".\..\lib\vc6_dll" /subsystem:console

!ELSEIF  "$(CFG)" == "printfbench - Win32 Universal Release"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "vc6_mswunivu"
# PROP BASE Intermediate_Dir "vc6_mswunivu\printfbench"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "vc6_mswunivu"
# PROP Intermediate_Dir "vc6_mswunivu\printfbench"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /FD /MD /Zi /Fdvc6_mswunivu\printfbench.pdb /O2 /GR /EHsc /I ".\..\lib\vc6_lib\mswunivu" /I ".\..\include" /W4 /I "." /Yu"testprec.h" /Fp"vc6_mswunivu\testprec_printfbench.pch" /D "WIN32" /D "__WXMSW__" /D "__WXUNIVERSAL__" /D "_UNICODE" /D "_CONSOLE" /D wxUSE_GUI=0 /c
# ADD CPP /nologo /FD /MD /Zi /Fdvc6_mswunivu\printfbench.pdb /O2 /GR /EHsc /I ".\..\lib\vc6_lib\mswunivu" /I ".\..\include" /W4 /I "." /Yu"testprec.h" /Fp"vc6_mswunivu\testprec_printfbench.pch" /D "WIN32" /D "__WXMSW__" /D "__WXUNIVERSAL__" /D "_UNICODE" /D "_CONSOLE" /D wxUSE_GUI=0 /c
# ADD BASE RSC /l 0x409 /d "__WXMSW__" /d "__WXUNIVERSAL__" /d "_UNICODE" /i ".\..\lib\vc6_lib\mswunivu" /i ".\..\include" /i "." /d "_CONSOLE" /d wxUSE_GUI=0
# ADD RSC /l 0x409 /d "__WXMSW__" /d "__WXUNIVERSAL__" /d "_UNICODE" /i ".\..\lib\vc6_lib\mswunivu" /i ".\..\include" /i "." /d "_CONSOLE" /d wxUSE_GUI=0
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 wxbase29u.lib wxzlib.lib wxregexu.lib wxexpat.lib kernel32.lib user32.lib gdi32.lib comdlg32.lib winspool.lib winmm.lib shell32.lib comctl32.lib ole32.lib oleaut32.lib uuid.lib rpcrt4.lib advapi32.lib wsock32.lib /nologo /machine:i386 /out:"vc6_mswunivu\printfbench.exe" /debug /pdb:"vc6_mswunivu\printfbench.pdb" /libpath:".\..\lib\vc6_lib" /subsystem:console
# ADD LINK32 wxbase29u.lib wxzlib.lib wxregexu.lib wxexpat.lib kernel32.lib user32.lib gdi32.lib comdlg32.lib winspool.lib winmm.lib shell32.lib comctl32.lib ole32.lib oleaut32.lib uuid.lib rpcrt4.lib advapi32.lib wsock32.lib /nologo /machine:i386 /out:"vc6_mswunivu\printfbench.exe" /debug /pdb:"vc6_mswunivu\printfbench.pdb" /libpath:".\..\lib\vc6_lib" /subsystem:console

!ELSEIF  "$(CFG)" == "printfbench - Win32 Universal Debug"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "vc6_mswunivud"
# PROP BASE Intermediate_Dir "vc6_mswunivud\printfbench"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "vc6_mswunivud"
# PROP Intermediate_Dir "vc6_mswunivud\printfbench"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /FD /MDd /Zi /Fdvc6_mswunivud\printfbench.pdb /Od /Gm /GR /EHsc /I ".\..\lib\vc6_lib\mswunivud" /I ".\..\include" /W4 /I "." /Yu"testprec.h" /Fp"vc6_mswunivud\testprec_printfbench.pch" /D "WIN32" /D "_DEBUG" /D "__WXMSW__" /D "__WXUNIVERSAL__" /D "__WXDEBUG__" /D "_UNICODE" /D "_CONSOLE" /D wxUSE_GUI=0 /c
# ADD CPP /nologo /FD /MDd /Zi /Fdvc6_mswunivud\printfbench.pdb /Od /Gm /GR /EHsc /I ".\..\lib\vc6_lib\mswunivud" /I ".\..\include" /W4 /I "." /Yu"testprec.h" /Fp"vc6_mswunivud\testprec_printfbench.pch" /D "WIN32" /D "_DEBUG" /D "__WXMSW__" /D "__WXUNIVERSAL__" /D "__WXDEBUG__" /D "_UNICODE" /D "_CONSOLE" /D wxUSE_GUI=0 /c
# ADD BASE RSC /l 0x409 /d "_DEBUG" /d "__WXMSW__" /d "__WXUNIVERSAL__" /d "__WXDEBUG__" /d "_UNICODE" /i ".\..\lib\vc6_lib\mswunivud" /i ".\..\include" /i "." /d "_CONSOLE" /d wxUSE_GUI=0
# ADD RSC /l 0x409 /d "_DEBUG" /d "__WXMSW__" /d "__WXUNIVERSAL__" /d "__WXDEBUG__" /d "_UNICODE" /i ".\..\lib\vc6_lib\mswunivud" /i ".\..\include" /i "." /d "_CONSOLE" /d wxUSE_GUI=0
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 wxbase29ud.lib wxzlibd.lib wxregexud.lib wxexpatd.lib kernel32.lib user32.lib gdi32.lib comdlg32.lib winspool.lib winmm.lib shell32.lib comctl32.lib ole32.lib oleaut32.lib uuid.lib rpcrt4.lib advapi32.lib wsock32.lib /nologo /machine:i386 /out:"vc6_mswunivud\printfbench.exe" /debug /pdb:"vc6_mswunivud\printfbench.pdb" /libpath:".\..\lib\vc6_lib" /subsystem:console
# ADD LINK32 wxbase29ud.lib wxzlibd.lib wxregexud.lib wxexpatd.lib kernel32.lib user32.lib gdi32.lib comdlg32.lib winspool.lib winmm.lib shell32.lib comctl32.lib ole32.lib oleaut32.lib uuid.lib rpcrt4.lib advapi32.lib wsock32.lib /nologo /machine:i386 /out:"vc6_mswunivud\printfbench.exe" /debug /pdb:"vc6_mswunivud\printfbench.pdb" /libpath:".\..\lib\vc6_lib" /subsystem:console

!ELSEIF  "$(CFG)" == "printfbench - Win32 Release"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "vc6_mswu"
# PROP BASE Intermediate_Dir "vc6_mswu\printfbench"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "vc6_mswu"
# PROP Intermediate_Dir "vc6_mswu\printfbench"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /FD /MD /Zi /Fdvc6_mswu\printfbench.pdb /O2 /GR /EHsc /I ".\..\lib\vc6_lib\mswu" /I ".\..\include" /W4 /I "." /Yu"testprec.h" /Fp"vc6_mswu\testprec_printfbench.pch" /D "WIN32" /D "__WXMSW__" /D "_UNICODE" /D "_CONSOLE" /D wxUSE_GUI=0 /c
# ADD CPP /nologo /FD /MD /Zi /Fdvc6_mswu\printfbench.pdb /O2 /GR /EHsc /I ".\..\lib\vc6_lib\mswu" /I ".\..\include" /W4 /I "." /Yu"testprec.h" /Fp"vc6_mswu\testprec_printfbench.pch" /D "WIN32" /D "__WXMSW__" /D "_UNICODE" /D "_CONSOLE" /D wxUSE_GUI=0 /c
# ADD BASE RSC /l 0x409 /d "__WXMSW__" /d "_UNICODE" /i ".\..\lib\vc6_lib\mswu" /i ".\..\include" /i "." /d "_CONSOLE" /d wxUSE_GUI=0
# ADD RSC /l 0x409 /d "__WXMSW__" /d "_UNICODE" /i ".\..\lib\vc6_lib\mswu" /i ".\..\include" /i "." /d "_CONSOLE" /d wxUSE_GUI=0
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 wxbase29u.lib wxzlib.lib wxregexu.lib wxexpat.lib kernel32.lib user32.lib gdi32.lib comdlg32.lib winspool.lib winmm.lib shell32.lib comctl32.lib ole32.lib oleaut32.lib uuid.lib rpcrt4.lib advapi32.lib wsock32.lib /nologo /machine:i386 /out:"vc6_mswu\printfbench.exe" /debug /pdb:"vc6_mswu\printfbench.pdb" /libpath:".\..\lib\vc6_lib" /subsystem:console
# ADD LINK32 wxbase29u.lib wxzlib.lib wxregexu.lib wxexpat.lib kernel32.lib user32.lib gdi32.lib comdlg32.lib winspool.lib winmm.lib shell32.lib comctl32.lib ole32.lib oleaut32.lib uuid.lib rpcrt4.lib advapi32.lib wsock32.lib /nologo /machine:i386 /out:"vc6_mswu\printfbench.exe" /debug /pdb:"vc6_mswu\printfbench.pdb" /libpath:".\..\lib\vc6_lib" /subsystem:console

!ELSEIF  "$(CFG)" == "printfbench - Win32 Debug"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "vc6_mswud"
# PROP BASE Intermediate_Dir "vc6_mswud\printfbench"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "vc6_mswud"
# PROP Intermediate_Dir "vc6_mswud\printfbench"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /FD /MDd /Zi /Fdvc6_mswud\printfbench.pdb /Od /Gm /GR /EHsc /I ".\..\lib\vc6_lib\mswud" /I ".\..\include" /W4 /I "." /Yu"testprec.h" /Fp"vc6_mswud\testprec_printfbench.pch" /D "WIN32" /D "_DEBUG" /D "__WXMSW__" /D "__WXDEBUG__" /D "_UNICODE" /D "_CONSOLE" /D wxUSE_GUI=0 /c
# ADD CPP /nologo /FD /MDd /Zi /Fdvc6_mswud\printfbench.pdb /Od /Gm /GR /EHsc /I ".\..\lib\vc6_lib\mswud" /I ".\..\include" /W4 /I "." /Yu"testprec.h" /Fp"vc6_mswud\testprec_printfbench.pch" /D "WIN32" /D "_DEBUG" /D "__WXMSW__" /D "__WXDEBUG__" /D "_UNICODE" /D "_CONSOLE" /D wxUSE_GUI=0 /c
# ADD BASE RSC /l 0x409 /d "_DEBUG" /d "__WXMSW__" /d "__WXDEBUG__" /d "_UNICODE" /i ".\..\lib\vc6_lib\mswud" /i ".\..\include" /i "." /d "_CONSOLE" /d wxUSE_GUI=0
# ADD RSC /l 0x409 /d "_DEBUG" /d "__WXMSW__" /d "__WXDEBUG__" /d "_UNICODE" /i ".\..\lib\vc6_lib\mswud" /i ".\..\include" /i "." /d "_CONSOLE" /d wxUSE_GUI=0
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 wxbase29ud.lib wxzlibd.lib wxregexud.lib wxexpatd.lib kernel32.lib user32.lib gdi32.lib comdlg32.lib winspool.lib winmm.lib shell32.lib comctl32.lib ole32.lib oleaut32.lib uuid.lib rpcrt4.lib advapi32.lib wsock32.lib /nologo /machine:i386 /out:"vc6_mswud\printfbench.exe" /debug /pdb:"vc6_mswud\printfbench.pdb" /libpath:".\..\lib\vc6_lib" /subsystem:console
# ADD LINK32 wxbase29ud.lib wxzlibd.lib wxregexud.lib wxexpatd.lib kernel32.lib user32.lib gdi32.lib comdlg32.lib winspool.lib winmm.lib shell32.lib comctl32.lib ole32.lib oleaut32.lib uuid.lib rpcrt4.lib advapi32.lib wsock32.lib /nologo /machine:i386 /out:"vc6_mswud\printfbench.exe" /debug /pdb:"vc6_mswud\printfbench.pdb" /libpath:".\..\lib\vc6_lib" /subsystem:console

!ENDIF

# Begin Target

# Name "printfbench - Win32 DLL Universal Release"
# Name "printfbench - Win32 DLL Universal Debug"
# Name "printfbench - Win32 DLL Release"
# Name "printfbench - Win32 DLL Debug"
# Name "printfbench - Win32 Universal Release"
# Name "printfbench - Win32 Universal Debug"
# Name "printfbench - Win32 Release"
# Name "printfbench - Win32 Debug"
# Begin Group "Source Files"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\dummy.cpp
# ADD BASE CPP /Yc"testprec.h"
# ADD CPP /Yc"testprec.h"
# End Source File
# Begin Source File

SOURCE=.\benchmarks\printfbench.cpp
# End Source File
# End Group
# End Target
# End Project

