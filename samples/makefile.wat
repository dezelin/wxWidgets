# =========================================================================
#     This makefile was generated by
#     Bakefile 0.1.3 (http://bakefile.sourceforge.net)
#     Do not modify, all changes will be overwritten!
# =========================================================================

!include ../build/msw/config.wat

# -------------------------------------------------------------------------
# Do not modify the rest of this file!
# -------------------------------------------------------------------------

# Speed up compilation a bit:
!ifdef __LOADDLL__
!  loaddll wcc      wccd
!  loaddll wccaxp   wccdaxp
!  loaddll wcc386   wccd386
!  loaddll wpp      wppdi86
!  loaddll wppaxp   wppdaxp
!  loaddll wpp386   wppd386
!  loaddll wlink    wlink
!  loaddll wlib     wlibd
!endif

# We need these variables in some bakefile-made rules:
WATCOM_CWD = $+ $(%cdrive):$(%cwd) $-

### Conditionally set variables: ###


### Variables: ###

MAKEARGS = CC="$(CC)" CXX="$(CXX)" CFLAGS="$(CFLAGS)" CXXFLAGS="$(CXXFLAGS)" &
	CPPFLAGS="$(CPPFLAGS)" LDFLAGS="$(LDFLAGS)" SHARED="$(SHARED)" &
	WXUNIV="$(WXUNIV)" UNICODE="$(UNICODE)" BUILD="$(BUILD)" &
	DEBUG_INFO="$(DEBUG_INFO)" DEBUG_FLAG="$(DEBUG_FLAG)" &
	MONOLITHIC="$(MONOLITHIC)" USE_GUI="$(USE_GUI)" USE_HTML="$(USE_HTML)" &
	USE_OPENGL="$(USE_OPENGL)" USE_ODBC="$(USE_ODBC)" &
	USE_EXCEPTIONS="$(USE_EXCEPTIONS)" OFFICIAL_BUILD="$(OFFICIAL_BUILD)" &
	VENDOR="$(VENDOR)" CFG="$(CFG)" RUNTIME_LIBS="$(RUNTIME_LIBS)"


### Targets: ###

all : .SYMBOLIC access artprov calendar caret checklst config console controls db dialogs dialup display dnd docview docvwmdi dragimag drawing dynamic erase event exec except font grid help htlbox html image internat ipc joytest keyboard layout listbox listctrl mdi memcheck menu mfc minifram minimal mobile multimon nativdlg notebook oleauto opengl ownerdrw png printing propsize regtest render richedit rotate sashtest scroll scrollsub shaped sockets sound splitter statbar tab taskbar text thread toolbar treectrl typetest validate vscroll widgets wizard wxtest

clean : .SYMBOLIC 
	-if exist .\*.obj del .\*.obj
	-if exist .\*.res del .\*.res
	-if exist .\*.lbc del .\*.lbc
	-if exist .\*.ilk del .\*.ilk

access : .SYMBOLIC 
	cd access
	wmake $(__MAKEOPTS__) -f makefile.wat $(MAKEARGS) all
	cd $(WATCOM_CWD)

artprov : .SYMBOLIC 
	cd artprov
	wmake $(__MAKEOPTS__) -f makefile.wat $(MAKEARGS) all
	cd $(WATCOM_CWD)

calendar : .SYMBOLIC 
	cd calendar
	wmake $(__MAKEOPTS__) -f makefile.wat $(MAKEARGS) all
	cd $(WATCOM_CWD)

caret : .SYMBOLIC 
	cd caret
	wmake $(__MAKEOPTS__) -f makefile.wat $(MAKEARGS) all
	cd $(WATCOM_CWD)

checklst : .SYMBOLIC 
	cd checklst
	wmake $(__MAKEOPTS__) -f makefile.wat $(MAKEARGS) all
	cd $(WATCOM_CWD)

config : .SYMBOLIC 
	cd config
	wmake $(__MAKEOPTS__) -f makefile.wat $(MAKEARGS) all
	cd $(WATCOM_CWD)

console : .SYMBOLIC 
	cd console
	wmake $(__MAKEOPTS__) -f makefile.wat $(MAKEARGS) all
	cd $(WATCOM_CWD)

controls : .SYMBOLIC 
	cd controls
	wmake $(__MAKEOPTS__) -f makefile.wat $(MAKEARGS) all
	cd $(WATCOM_CWD)

db : .SYMBOLIC 
	cd db
	wmake $(__MAKEOPTS__) -f makefile.wat $(MAKEARGS) all
	cd $(WATCOM_CWD)

dialogs : .SYMBOLIC 
	cd dialogs
	wmake $(__MAKEOPTS__) -f makefile.wat $(MAKEARGS) all
	cd $(WATCOM_CWD)

dialup : .SYMBOLIC 
	cd dialup
	wmake $(__MAKEOPTS__) -f makefile.wat $(MAKEARGS) all
	cd $(WATCOM_CWD)

display : .SYMBOLIC 
	cd display
	wmake $(__MAKEOPTS__) -f makefile.wat $(MAKEARGS) all
	cd $(WATCOM_CWD)

dnd : .SYMBOLIC 
	cd dnd
	wmake $(__MAKEOPTS__) -f makefile.wat $(MAKEARGS) all
	cd $(WATCOM_CWD)

docview : .SYMBOLIC 
	cd docview
	wmake $(__MAKEOPTS__) -f makefile.wat $(MAKEARGS) all
	cd $(WATCOM_CWD)

docvwmdi : .SYMBOLIC 
	cd docvwmdi
	wmake $(__MAKEOPTS__) -f makefile.wat $(MAKEARGS) all
	cd $(WATCOM_CWD)

dragimag : .SYMBOLIC 
	cd dragimag
	wmake $(__MAKEOPTS__) -f makefile.wat $(MAKEARGS) all
	cd $(WATCOM_CWD)

drawing : .SYMBOLIC 
	cd drawing
	wmake $(__MAKEOPTS__) -f makefile.wat $(MAKEARGS) all
	cd $(WATCOM_CWD)

dynamic : .SYMBOLIC 
	cd dynamic
	wmake $(__MAKEOPTS__) -f makefile.wat $(MAKEARGS) all
	cd $(WATCOM_CWD)

erase : .SYMBOLIC 
	cd erase
	wmake $(__MAKEOPTS__) -f makefile.wat $(MAKEARGS) all
	cd $(WATCOM_CWD)

event : .SYMBOLIC 
	cd event
	wmake $(__MAKEOPTS__) -f makefile.wat $(MAKEARGS) all
	cd $(WATCOM_CWD)

exec : .SYMBOLIC 
	cd exec
	wmake $(__MAKEOPTS__) -f makefile.wat $(MAKEARGS) all
	cd $(WATCOM_CWD)

except : .SYMBOLIC 
	cd except
	wmake $(__MAKEOPTS__) -f makefile.wat $(MAKEARGS) all
	cd $(WATCOM_CWD)

font : .SYMBOLIC 
	cd font
	wmake $(__MAKEOPTS__) -f makefile.wat $(MAKEARGS) all
	cd $(WATCOM_CWD)

grid : .SYMBOLIC 
	cd grid
	wmake $(__MAKEOPTS__) -f makefile.wat $(MAKEARGS) all
	cd $(WATCOM_CWD)

help : .SYMBOLIC 
	cd help
	wmake $(__MAKEOPTS__) -f makefile.wat $(MAKEARGS) all
	cd $(WATCOM_CWD)

htlbox : .SYMBOLIC 
	cd htlbox
	wmake $(__MAKEOPTS__) -f makefile.wat $(MAKEARGS) all
	cd $(WATCOM_CWD)

html : .SYMBOLIC 
	cd html
	wmake $(__MAKEOPTS__) -f makefile.wat $(MAKEARGS) all
	cd $(WATCOM_CWD)

image : .SYMBOLIC 
	cd image
	wmake $(__MAKEOPTS__) -f makefile.wat $(MAKEARGS) all
	cd $(WATCOM_CWD)

internat : .SYMBOLIC 
	cd internat
	wmake $(__MAKEOPTS__) -f makefile.wat $(MAKEARGS) all
	cd $(WATCOM_CWD)

ipc : .SYMBOLIC 
	cd ipc
	wmake $(__MAKEOPTS__) -f makefile.wat $(MAKEARGS) all
	cd $(WATCOM_CWD)

joytest : .SYMBOLIC 
	cd joytest
	wmake $(__MAKEOPTS__) -f makefile.wat $(MAKEARGS) all
	cd $(WATCOM_CWD)

keyboard : .SYMBOLIC 
	cd keyboard
	wmake $(__MAKEOPTS__) -f makefile.wat $(MAKEARGS) all
	cd $(WATCOM_CWD)

layout : .SYMBOLIC 
	cd layout
	wmake $(__MAKEOPTS__) -f makefile.wat $(MAKEARGS) all
	cd $(WATCOM_CWD)

listbox : .SYMBOLIC 
	cd listbox
	wmake $(__MAKEOPTS__) -f makefile.wat $(MAKEARGS) all
	cd $(WATCOM_CWD)

listctrl : .SYMBOLIC 
	cd listctrl
	wmake $(__MAKEOPTS__) -f makefile.wat $(MAKEARGS) all
	cd $(WATCOM_CWD)

mdi : .SYMBOLIC 
	cd mdi
	wmake $(__MAKEOPTS__) -f makefile.wat $(MAKEARGS) all
	cd $(WATCOM_CWD)

memcheck : .SYMBOLIC 
	cd memcheck
	wmake $(__MAKEOPTS__) -f makefile.wat $(MAKEARGS) all
	cd $(WATCOM_CWD)

menu : .SYMBOLIC 
	cd menu
	wmake $(__MAKEOPTS__) -f makefile.wat $(MAKEARGS) all
	cd $(WATCOM_CWD)

mfc : .SYMBOLIC 
	cd mfc
	wmake $(__MAKEOPTS__) -f makefile.wat $(MAKEARGS) all
	cd $(WATCOM_CWD)

minifram : .SYMBOLIC 
	cd minifram
	wmake $(__MAKEOPTS__) -f makefile.wat $(MAKEARGS) all
	cd $(WATCOM_CWD)

minimal : .SYMBOLIC 
	cd minimal
	wmake $(__MAKEOPTS__) -f makefile.wat $(MAKEARGS) all
	cd $(WATCOM_CWD)

mobile : .SYMBOLIC 
	cd mobile
	wmake $(__MAKEOPTS__) -f makefile.wat $(MAKEARGS) all
	cd $(WATCOM_CWD)

multimon : .SYMBOLIC 
	cd multimon
	wmake $(__MAKEOPTS__) -f makefile.wat $(MAKEARGS) all
	cd $(WATCOM_CWD)

nativdlg : .SYMBOLIC 
	cd nativdlg
	wmake $(__MAKEOPTS__) -f makefile.wat $(MAKEARGS) all
	cd $(WATCOM_CWD)

notebook : .SYMBOLIC 
	cd notebook
	wmake $(__MAKEOPTS__) -f makefile.wat $(MAKEARGS) all
	cd $(WATCOM_CWD)

oleauto : .SYMBOLIC 
	cd oleauto
	wmake $(__MAKEOPTS__) -f makefile.wat $(MAKEARGS) all
	cd $(WATCOM_CWD)

opengl : .SYMBOLIC 
	cd opengl
	wmake $(__MAKEOPTS__) -f makefile.wat $(MAKEARGS) all
	cd $(WATCOM_CWD)

ownerdrw : .SYMBOLIC 
	cd ownerdrw
	wmake $(__MAKEOPTS__) -f makefile.wat $(MAKEARGS) all
	cd $(WATCOM_CWD)

png : .SYMBOLIC 
	cd png
	wmake $(__MAKEOPTS__) -f makefile.wat $(MAKEARGS) all
	cd $(WATCOM_CWD)

printing : .SYMBOLIC 
	cd printing
	wmake $(__MAKEOPTS__) -f makefile.wat $(MAKEARGS) all
	cd $(WATCOM_CWD)

propsize : .SYMBOLIC 
	cd propsize
	wmake $(__MAKEOPTS__) -f makefile.wat $(MAKEARGS) all
	cd $(WATCOM_CWD)

regtest : .SYMBOLIC 
	cd regtest
	wmake $(__MAKEOPTS__) -f makefile.wat $(MAKEARGS) all
	cd $(WATCOM_CWD)

render : .SYMBOLIC 
	cd render
	wmake $(__MAKEOPTS__) -f makefile.wat $(MAKEARGS) all
	cd $(WATCOM_CWD)

richedit : .SYMBOLIC 
	cd richedit
	wmake $(__MAKEOPTS__) -f makefile.wat $(MAKEARGS) all
	cd $(WATCOM_CWD)

rotate : .SYMBOLIC 
	cd rotate
	wmake $(__MAKEOPTS__) -f makefile.wat $(MAKEARGS) all
	cd $(WATCOM_CWD)

sashtest : .SYMBOLIC 
	cd sashtest
	wmake $(__MAKEOPTS__) -f makefile.wat $(MAKEARGS) all
	cd $(WATCOM_CWD)

scroll : .SYMBOLIC 
	cd scroll
	wmake $(__MAKEOPTS__) -f makefile.wat $(MAKEARGS) all
	cd $(WATCOM_CWD)

scrollsub : .SYMBOLIC 
	cd scrollsub
	wmake $(__MAKEOPTS__) -f makefile.wat $(MAKEARGS) all
	cd $(WATCOM_CWD)

shaped : .SYMBOLIC 
	cd shaped
	wmake $(__MAKEOPTS__) -f makefile.wat $(MAKEARGS) all
	cd $(WATCOM_CWD)

sockets : .SYMBOLIC 
	cd sockets
	wmake $(__MAKEOPTS__) -f makefile.wat $(MAKEARGS) all
	cd $(WATCOM_CWD)

sound : .SYMBOLIC 
	cd sound
	wmake $(__MAKEOPTS__) -f makefile.wat $(MAKEARGS) all
	cd $(WATCOM_CWD)

splitter : .SYMBOLIC 
	cd splitter
	wmake $(__MAKEOPTS__) -f makefile.wat $(MAKEARGS) all
	cd $(WATCOM_CWD)

statbar : .SYMBOLIC 
	cd statbar
	wmake $(__MAKEOPTS__) -f makefile.wat $(MAKEARGS) all
	cd $(WATCOM_CWD)

tab : .SYMBOLIC 
	cd tab
	wmake $(__MAKEOPTS__) -f makefile.wat $(MAKEARGS) all
	cd $(WATCOM_CWD)

taskbar : .SYMBOLIC 
	cd taskbar
	wmake $(__MAKEOPTS__) -f makefile.wat $(MAKEARGS) all
	cd $(WATCOM_CWD)

text : .SYMBOLIC 
	cd text
	wmake $(__MAKEOPTS__) -f makefile.wat $(MAKEARGS) all
	cd $(WATCOM_CWD)

thread : .SYMBOLIC 
	cd thread
	wmake $(__MAKEOPTS__) -f makefile.wat $(MAKEARGS) all
	cd $(WATCOM_CWD)

toolbar : .SYMBOLIC 
	cd toolbar
	wmake $(__MAKEOPTS__) -f makefile.wat $(MAKEARGS) all
	cd $(WATCOM_CWD)

treectrl : .SYMBOLIC 
	cd treectrl
	wmake $(__MAKEOPTS__) -f makefile.wat $(MAKEARGS) all
	cd $(WATCOM_CWD)

typetest : .SYMBOLIC 
	cd typetest
	wmake $(__MAKEOPTS__) -f makefile.wat $(MAKEARGS) all
	cd $(WATCOM_CWD)

validate : .SYMBOLIC 
	cd validate
	wmake $(__MAKEOPTS__) -f makefile.wat $(MAKEARGS) all
	cd $(WATCOM_CWD)

vscroll : .SYMBOLIC 
	cd vscroll
	wmake $(__MAKEOPTS__) -f makefile.wat $(MAKEARGS) all
	cd $(WATCOM_CWD)

widgets : .SYMBOLIC 
	cd widgets
	wmake $(__MAKEOPTS__) -f makefile.wat $(MAKEARGS) all
	cd $(WATCOM_CWD)

wizard : .SYMBOLIC 
	cd wizard
	wmake $(__MAKEOPTS__) -f makefile.wat $(MAKEARGS) all
	cd $(WATCOM_CWD)

wxtest : .SYMBOLIC 
	cd wxtest
	wmake $(__MAKEOPTS__) -f makefile.wat $(MAKEARGS) all
	cd $(WATCOM_CWD)
