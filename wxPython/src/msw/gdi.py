# This file was created automatically by SWIG.
import gdic

from misc import *

from fonts import *
import wx
class wxGDIObjectPtr(wxObjectPtr):
    def __init__(self,this):
        self.this = this
        self.thisown = 0
    def __del__(self, delfunc=gdic.delete_wxGDIObject):
        if self.thisown == 1:
            try:
                delfunc(self)
            except:
                pass
    def GetVisible(self, *_args, **_kwargs):
        val = gdic.wxGDIObject_GetVisible(self, *_args, **_kwargs)
        return val
    def SetVisible(self, *_args, **_kwargs):
        val = gdic.wxGDIObject_SetVisible(self, *_args, **_kwargs)
        return val
    def IsNull(self, *_args, **_kwargs):
        val = gdic.wxGDIObject_IsNull(self, *_args, **_kwargs)
        return val
    def __repr__(self):
        return "<%s.%s instance; proxy of C++ wxGDIObject instance at %s>" % (self.__class__.__module__, self.__class__.__name__, self.this)
class wxGDIObject(wxGDIObjectPtr):
    def __init__(self,*_args,**_kwargs):
        self.this = gdic.new_wxGDIObject(*_args,**_kwargs)
        self.thisown = 1




class wxBitmapPtr(wxGDIObjectPtr):
    def __init__(self,this):
        self.this = this
        self.thisown = 0
    def __del__(self, delfunc=gdic.delete_wxBitmap):
        if self.thisown == 1:
            try:
                delfunc(self)
            except:
                pass
    def GetPalette(self, *_args, **_kwargs):
        val = gdic.wxBitmap_GetPalette(self, *_args, **_kwargs)
        if val: val = wxPalettePtr(val) 
        return val
    def GetMask(self, *_args, **_kwargs):
        val = gdic.wxBitmap_GetMask(self, *_args, **_kwargs)
        if val: val = wxMaskPtr(val) 
        return val
    def LoadFile(self, *_args, **_kwargs):
        val = gdic.wxBitmap_LoadFile(self, *_args, **_kwargs)
        return val
    def SaveFile(self, *_args, **_kwargs):
        val = gdic.wxBitmap_SaveFile(self, *_args, **_kwargs)
        return val
    def SetMask(self, *_args, **_kwargs):
        val = gdic.wxBitmap_SetMask(self, *_args, **_kwargs)
        return val
    def SetPalette(self, *_args, **_kwargs):
        val = gdic.wxBitmap_SetPalette(self, *_args, **_kwargs)
        return val
    def GetHandle(self, *_args, **_kwargs):
        val = gdic.wxBitmap_GetHandle(self, *_args, **_kwargs)
        return val
    def SetHandle(self, *_args, **_kwargs):
        val = gdic.wxBitmap_SetHandle(self, *_args, **_kwargs)
        return val
    def Ok(self, *_args, **_kwargs):
        val = gdic.wxBitmap_Ok(self, *_args, **_kwargs)
        return val
    def GetWidth(self, *_args, **_kwargs):
        val = gdic.wxBitmap_GetWidth(self, *_args, **_kwargs)
        return val
    def GetHeight(self, *_args, **_kwargs):
        val = gdic.wxBitmap_GetHeight(self, *_args, **_kwargs)
        return val
    def GetDepth(self, *_args, **_kwargs):
        val = gdic.wxBitmap_GetDepth(self, *_args, **_kwargs)
        return val
    def SetWidth(self, *_args, **_kwargs):
        val = gdic.wxBitmap_SetWidth(self, *_args, **_kwargs)
        return val
    def SetHeight(self, *_args, **_kwargs):
        val = gdic.wxBitmap_SetHeight(self, *_args, **_kwargs)
        return val
    def SetDepth(self, *_args, **_kwargs):
        val = gdic.wxBitmap_SetDepth(self, *_args, **_kwargs)
        return val
    def SetSize(self, *_args, **_kwargs):
        val = gdic.wxBitmap_SetSize(self, *_args, **_kwargs)
        return val
    def GetSubBitmap(self, *_args, **_kwargs):
        val = gdic.wxBitmap_GetSubBitmap(self, *_args, **_kwargs)
        if val: val = wxBitmapPtr(val) ; val.thisown = 1
        return val
    def CopyFromIcon(self, *_args, **_kwargs):
        val = gdic.wxBitmap_CopyFromIcon(self, *_args, **_kwargs)
        return val
    def CopyFromCursor(self, *_args, **_kwargs):
        val = gdic.wxBitmap_CopyFromCursor(self, *_args, **_kwargs)
        return val
    def GetQuality(self, *_args, **_kwargs):
        val = gdic.wxBitmap_GetQuality(self, *_args, **_kwargs)
        return val
    def SetQuality(self, *_args, **_kwargs):
        val = gdic.wxBitmap_SetQuality(self, *_args, **_kwargs)
        return val
    def __repr__(self):
        return "<%s.%s instance; proxy of C++ wxBitmap instance at %s>" % (self.__class__.__module__, self.__class__.__name__, self.this)
    
    def SetMaskColour(self, colour):
        mask = wxMaskColour(self, colour)
        self.SetMask(mask)
    
    def __nonzero__(self): return self.Ok()
class wxBitmap(wxBitmapPtr):
    def __init__(self,*_args,**_kwargs):
        self.this = gdic.new_wxBitmap(*_args,**_kwargs)
        self.thisown = 1




class wxMaskPtr(wxObjectPtr):
    def __init__(self,this):
        self.this = this
        self.thisown = 0
    def Destroy(self, *_args, **_kwargs):
        val = gdic.wxMask_Destroy(self, *_args, **_kwargs)
        return val
    def __repr__(self):
        return "<%s.%s instance; proxy of C++ wxMask instance at %s>" % (self.__class__.__module__, self.__class__.__name__, self.this)
class wxMask(wxMaskPtr):
    def __init__(self,*_args,**_kwargs):
        self.this = gdic.new_wxMask(*_args,**_kwargs)
        self.thisown = 1




class wxIconPtr(wxGDIObjectPtr):
    def __init__(self,this):
        self.this = this
        self.thisown = 0
    def __del__(self, delfunc=gdic.delete_wxIcon):
        if self.thisown == 1:
            try:
                delfunc(self)
            except:
                pass
    def LoadFile(self, *_args, **_kwargs):
        val = gdic.wxIcon_LoadFile(self, *_args, **_kwargs)
        return val
    def GetHandle(self, *_args, **_kwargs):
        val = gdic.wxIcon_GetHandle(self, *_args, **_kwargs)
        return val
    def SetHandle(self, *_args, **_kwargs):
        val = gdic.wxIcon_SetHandle(self, *_args, **_kwargs)
        return val
    def Ok(self, *_args, **_kwargs):
        val = gdic.wxIcon_Ok(self, *_args, **_kwargs)
        return val
    def GetWidth(self, *_args, **_kwargs):
        val = gdic.wxIcon_GetWidth(self, *_args, **_kwargs)
        return val
    def GetHeight(self, *_args, **_kwargs):
        val = gdic.wxIcon_GetHeight(self, *_args, **_kwargs)
        return val
    def GetDepth(self, *_args, **_kwargs):
        val = gdic.wxIcon_GetDepth(self, *_args, **_kwargs)
        return val
    def SetWidth(self, *_args, **_kwargs):
        val = gdic.wxIcon_SetWidth(self, *_args, **_kwargs)
        return val
    def SetHeight(self, *_args, **_kwargs):
        val = gdic.wxIcon_SetHeight(self, *_args, **_kwargs)
        return val
    def SetDepth(self, *_args, **_kwargs):
        val = gdic.wxIcon_SetDepth(self, *_args, **_kwargs)
        return val
    def SetSize(self, *_args, **_kwargs):
        val = gdic.wxIcon_SetSize(self, *_args, **_kwargs)
        return val
    def CopyFromBitmap(self, *_args, **_kwargs):
        val = gdic.wxIcon_CopyFromBitmap(self, *_args, **_kwargs)
        return val
    def __repr__(self):
        return "<%s.%s instance; proxy of C++ wxIcon instance at %s>" % (self.__class__.__module__, self.__class__.__name__, self.this)
    def __nonzero__(self): return self.Ok()
class wxIcon(wxIconPtr):
    def __init__(self,*_args,**_kwargs):
        self.this = gdic.new_wxIcon(*_args,**_kwargs)
        self.thisown = 1




class wxIconLocationPtr :
    def __init__(self,this):
        self.this = this
        self.thisown = 0
    def __del__(self, delfunc=gdic.delete_wxIconLocation):
        if self.thisown == 1:
            try:
                delfunc(self)
            except:
                pass
    def IsOk(self, *_args, **_kwargs):
        val = gdic.wxIconLocation_IsOk(self, *_args, **_kwargs)
        return val
    def SetFileName(self, *_args, **_kwargs):
        val = gdic.wxIconLocation_SetFileName(self, *_args, **_kwargs)
        return val
    def GetFileName(self, *_args, **_kwargs):
        val = gdic.wxIconLocation_GetFileName(self, *_args, **_kwargs)
        return val
    def SetIndex(self, *_args, **_kwargs):
        val = gdic.wxIconLocation_SetIndex(self, *_args, **_kwargs)
        return val
    def GetIndex(self, *_args, **_kwargs):
        val = gdic.wxIconLocation_GetIndex(self, *_args, **_kwargs)
        return val
    def __repr__(self):
        return "<%s.%s instance; proxy of C++ wxIconLocation instance at %s>" % (self.__class__.__module__, self.__class__.__name__, self.this)
class wxIconLocation(wxIconLocationPtr):
    def __init__(self,*_args,**_kwargs):
        self.this = gdic.new_wxIconLocation(*_args,**_kwargs)
        self.thisown = 1




class wxIconBundlePtr :
    def __init__(self,this):
        self.this = this
        self.thisown = 0
    def __del__(self, delfunc=gdic.delete_wxIconBundle):
        if self.thisown == 1:
            try:
                delfunc(self)
            except:
                pass
    def AddIcon(self, *_args, **_kwargs):
        val = gdic.wxIconBundle_AddIcon(self, *_args, **_kwargs)
        return val
    def AddIconFromFile(self, *_args, **_kwargs):
        val = gdic.wxIconBundle_AddIconFromFile(self, *_args, **_kwargs)
        return val
    def GetIcon(self, *_args, **_kwargs):
        val = gdic.wxIconBundle_GetIcon(self, *_args, **_kwargs)
        if val: val = wxIconPtr(val) 
        return val
    def __repr__(self):
        return "<%s.%s instance; proxy of C++ wxIconBundle instance at %s>" % (self.__class__.__module__, self.__class__.__name__, self.this)
class wxIconBundle(wxIconBundlePtr):
    def __init__(self,*_args,**_kwargs):
        self.this = gdic.new_wxIconBundle(*_args,**_kwargs)
        self.thisown = 1



def wxIconBundleFromFile(*_args,**_kwargs):
    val = wxIconBundlePtr(gdic.new_wxIconBundleFromFile(*_args,**_kwargs))
    val.thisown = 1
    return val

def wxIconBundleFromIcon(*_args,**_kwargs):
    val = wxIconBundlePtr(gdic.new_wxIconBundleFromIcon(*_args,**_kwargs))
    val.thisown = 1
    return val


class wxCursorPtr(wxGDIObjectPtr):
    def __init__(self,this):
        self.this = this
        self.thisown = 0
    def __del__(self, delfunc=gdic.delete_wxCursor):
        if self.thisown == 1:
            try:
                delfunc(self)
            except:
                pass
    def GetHandle(self, *_args, **_kwargs):
        val = gdic.wxCursor_GetHandle(self, *_args, **_kwargs)
        return val
    def SetHandle(self, *_args, **_kwargs):
        val = gdic.wxCursor_SetHandle(self, *_args, **_kwargs)
        return val
    def Ok(self, *_args, **_kwargs):
        val = gdic.wxCursor_Ok(self, *_args, **_kwargs)
        return val
    def GetWidth(self, *_args, **_kwargs):
        val = gdic.wxCursor_GetWidth(self, *_args, **_kwargs)
        return val
    def GetHeight(self, *_args, **_kwargs):
        val = gdic.wxCursor_GetHeight(self, *_args, **_kwargs)
        return val
    def GetDepth(self, *_args, **_kwargs):
        val = gdic.wxCursor_GetDepth(self, *_args, **_kwargs)
        return val
    def SetWidth(self, *_args, **_kwargs):
        val = gdic.wxCursor_SetWidth(self, *_args, **_kwargs)
        return val
    def SetHeight(self, *_args, **_kwargs):
        val = gdic.wxCursor_SetHeight(self, *_args, **_kwargs)
        return val
    def SetDepth(self, *_args, **_kwargs):
        val = gdic.wxCursor_SetDepth(self, *_args, **_kwargs)
        return val
    def SetSize(self, *_args, **_kwargs):
        val = gdic.wxCursor_SetSize(self, *_args, **_kwargs)
        return val
    def __repr__(self):
        return "<%s.%s instance; proxy of C++ wxCursor instance at %s>" % (self.__class__.__module__, self.__class__.__name__, self.this)
    def __nonzero__(self): return self.Ok()
class wxCursor(wxCursorPtr):
    def __init__(self,*_args,**_kwargs):
        self.this = gdic.new_wxCursor(*_args,**_kwargs)
        self.thisown = 1




class wxColourPtr(wxObjectPtr):
    def __init__(self,this):
        self.this = this
        self.thisown = 0
    def __del__(self, delfunc=gdic.delete_wxColour):
        if self.thisown == 1:
            try:
                delfunc(self)
            except:
                pass
    def Red(self, *_args, **_kwargs):
        val = gdic.wxColour_Red(self, *_args, **_kwargs)
        return val
    def Green(self, *_args, **_kwargs):
        val = gdic.wxColour_Green(self, *_args, **_kwargs)
        return val
    def Blue(self, *_args, **_kwargs):
        val = gdic.wxColour_Blue(self, *_args, **_kwargs)
        return val
    def Ok(self, *_args, **_kwargs):
        val = gdic.wxColour_Ok(self, *_args, **_kwargs)
        return val
    def Set(self, *_args, **_kwargs):
        val = gdic.wxColour_Set(self, *_args, **_kwargs)
        return val
    def Get(self, *_args, **_kwargs):
        val = gdic.wxColour_Get(self, *_args, **_kwargs)
        return val
    def __eq__(self, *_args, **_kwargs):
        val = gdic.wxColour___eq__(self, *_args, **_kwargs)
        return val
    def __ne__(self, *_args, **_kwargs):
        val = gdic.wxColour___ne__(self, *_args, **_kwargs)
        return val
    def __repr__(self):
        return "<%s.%s instance; proxy of C++ wxColour instance at %s>" % (self.__class__.__module__, self.__class__.__name__, self.this)
    asTuple = Get
    def __str__(self):                  return str(self.asTuple())
    def __repr__(self):                 return 'wxColour:' + str(self.asTuple())
    def __nonzero__(self):              return self.Ok()
    def __getinitargs__(self):          return ()
    def __getstate__(self):             return self.asTuple()
    def __setstate__(self, state):      self.Set(*state)

class wxColour(wxColourPtr):
    def __init__(self,*_args,**_kwargs):
        self.this = gdic.new_wxColour(*_args,**_kwargs)
        self.thisown = 1




class wxColourDatabasePtr(wxObjectPtr):
    def __init__(self,this):
        self.this = this
        self.thisown = 0
    def FindColour(self, *_args, **_kwargs):
        val = gdic.wxColourDatabase_FindColour(self, *_args, **_kwargs)
        if val: val = wxColourPtr(val) 
        return val
    def FindColourNoAdd(self, *_args, **_kwargs):
        val = gdic.wxColourDatabase_FindColourNoAdd(self, *_args, **_kwargs)
        if val: val = wxColourPtr(val) 
        return val
    def FindName(self, *_args, **_kwargs):
        val = gdic.wxColourDatabase_FindName(self, *_args, **_kwargs)
        return val
    def AddColour(self, *_args, **_kwargs):
        val = gdic.wxColourDatabase_AddColour(self, *_args, **_kwargs)
        return val
    def Append(self, *_args, **_kwargs):
        val = gdic.wxColourDatabase_Append(self, *_args, **_kwargs)
        return val
    def __repr__(self):
        return "<%s.%s instance; proxy of C++ wxColourDatabase instance at %s>" % (self.__class__.__module__, self.__class__.__name__, self.this)
class wxColourDatabase(wxColourDatabasePtr):
    def __init__(self,this):
        self.this = this




class wxPenPtr(wxGDIObjectPtr):
    def __init__(self,this):
        self.this = this
        self.thisown = 0
    def __del__(self, delfunc=gdic.delete_wxPen):
        if self.thisown == 1:
            try:
                delfunc(self)
            except:
                pass
    def GetCap(self, *_args, **_kwargs):
        val = gdic.wxPen_GetCap(self, *_args, **_kwargs)
        return val
    def GetColour(self, *_args, **_kwargs):
        val = gdic.wxPen_GetColour(self, *_args, **_kwargs)
        if val: val = wxColourPtr(val) ; val.thisown = 1
        return val
    def GetJoin(self, *_args, **_kwargs):
        val = gdic.wxPen_GetJoin(self, *_args, **_kwargs)
        return val
    def GetStyle(self, *_args, **_kwargs):
        val = gdic.wxPen_GetStyle(self, *_args, **_kwargs)
        return val
    def GetWidth(self, *_args, **_kwargs):
        val = gdic.wxPen_GetWidth(self, *_args, **_kwargs)
        return val
    def Ok(self, *_args, **_kwargs):
        val = gdic.wxPen_Ok(self, *_args, **_kwargs)
        return val
    def SetCap(self, *_args, **_kwargs):
        val = gdic.wxPen_SetCap(self, *_args, **_kwargs)
        return val
    def SetColour(self, *_args, **_kwargs):
        val = gdic.wxPen_SetColour(self, *_args, **_kwargs)
        return val
    def SetJoin(self, *_args, **_kwargs):
        val = gdic.wxPen_SetJoin(self, *_args, **_kwargs)
        return val
    def SetStyle(self, *_args, **_kwargs):
        val = gdic.wxPen_SetStyle(self, *_args, **_kwargs)
        return val
    def SetWidth(self, *_args, **_kwargs):
        val = gdic.wxPen_SetWidth(self, *_args, **_kwargs)
        return val
    def SetDashes(self, *_args, **_kwargs):
        val = gdic.wxPen_SetDashes(self, *_args, **_kwargs)
        return val
    def GetDashes(self, *_args, **_kwargs):
        val = gdic.wxPen_GetDashes(self, *_args, **_kwargs)
        return val
    def GetStipple(self, *_args, **_kwargs):
        val = gdic.wxPen_GetStipple(self, *_args, **_kwargs)
        if val: val = wxBitmapPtr(val) 
        return val
    def SetStipple(self, *_args, **_kwargs):
        val = gdic.wxPen_SetStipple(self, *_args, **_kwargs)
        return val
    def __repr__(self):
        return "<%s.%s instance; proxy of C++ wxPen instance at %s>" % (self.__class__.__module__, self.__class__.__name__, self.this)
    def __nonzero__(self): return self.Ok()
class wxPen(wxPenPtr):
    def __init__(self,*_args,**_kwargs):
        self.this = gdic.new_wxPen(*_args,**_kwargs)
        self.thisown = 1




class wxPyPenPtr(wxPenPtr):
    def __init__(self,this):
        self.this = this
        self.thisown = 0
    def __del__(self, delfunc=gdic.delete_wxPyPen):
        if self.thisown == 1:
            try:
                delfunc(self)
            except:
                pass
    def SetDashes(self, *_args, **_kwargs):
        val = gdic.wxPyPen_SetDashes(self, *_args, **_kwargs)
        return val
    def __repr__(self):
        return "<%s.%s instance; proxy of C++ wxPyPen instance at %s>" % (self.__class__.__module__, self.__class__.__name__, self.this)
class wxPyPen(wxPyPenPtr):
    def __init__(self,*_args,**_kwargs):
        self.this = gdic.new_wxPyPen(*_args,**_kwargs)
        self.thisown = 1




class wxPenListPtr(wxObjectPtr):
    def __init__(self,this):
        self.this = this
        self.thisown = 0
    def AddPen(self, *_args, **_kwargs):
        val = gdic.wxPenList_AddPen(self, *_args, **_kwargs)
        return val
    def FindOrCreatePen(self, *_args, **_kwargs):
        val = gdic.wxPenList_FindOrCreatePen(self, *_args, **_kwargs)
        if val: val = wxPenPtr(val) 
        return val
    def RemovePen(self, *_args, **_kwargs):
        val = gdic.wxPenList_RemovePen(self, *_args, **_kwargs)
        return val
    def GetCount(self, *_args, **_kwargs):
        val = gdic.wxPenList_GetCount(self, *_args, **_kwargs)
        return val
    def __repr__(self):
        return "<%s.%s instance; proxy of C++ wxPenList instance at %s>" % (self.__class__.__module__, self.__class__.__name__, self.this)
class wxPenList(wxPenListPtr):
    def __init__(self,this):
        self.this = this




class wxBrushPtr(wxGDIObjectPtr):
    def __init__(self,this):
        self.this = this
        self.thisown = 0
    def __del__(self, delfunc=gdic.delete_wxBrush):
        if self.thisown == 1:
            try:
                delfunc(self)
            except:
                pass
    def GetColour(self, *_args, **_kwargs):
        val = gdic.wxBrush_GetColour(self, *_args, **_kwargs)
        if val: val = wxColourPtr(val) ; val.thisown = 1
        return val
    def GetStipple(self, *_args, **_kwargs):
        val = gdic.wxBrush_GetStipple(self, *_args, **_kwargs)
        if val: val = wxBitmapPtr(val) 
        return val
    def GetStyle(self, *_args, **_kwargs):
        val = gdic.wxBrush_GetStyle(self, *_args, **_kwargs)
        return val
    def Ok(self, *_args, **_kwargs):
        val = gdic.wxBrush_Ok(self, *_args, **_kwargs)
        return val
    def SetColour(self, *_args, **_kwargs):
        val = gdic.wxBrush_SetColour(self, *_args, **_kwargs)
        return val
    def SetStipple(self, *_args, **_kwargs):
        val = gdic.wxBrush_SetStipple(self, *_args, **_kwargs)
        return val
    def SetStyle(self, *_args, **_kwargs):
        val = gdic.wxBrush_SetStyle(self, *_args, **_kwargs)
        return val
    def __repr__(self):
        return "<%s.%s instance; proxy of C++ wxBrush instance at %s>" % (self.__class__.__module__, self.__class__.__name__, self.this)
    def __nonzero__(self): return self.Ok()
class wxBrush(wxBrushPtr):
    def __init__(self,*_args,**_kwargs):
        self.this = gdic.new_wxBrush(*_args,**_kwargs)
        self.thisown = 1




class wxBrushListPtr(wxObjectPtr):
    def __init__(self,this):
        self.this = this
        self.thisown = 0
    def AddBrush(self, *_args, **_kwargs):
        val = gdic.wxBrushList_AddBrush(self, *_args, **_kwargs)
        return val
    def FindOrCreateBrush(self, *_args, **_kwargs):
        val = gdic.wxBrushList_FindOrCreateBrush(self, *_args, **_kwargs)
        if val: val = wxBrushPtr(val) 
        return val
    def RemoveBrush(self, *_args, **_kwargs):
        val = gdic.wxBrushList_RemoveBrush(self, *_args, **_kwargs)
        return val
    def GetCount(self, *_args, **_kwargs):
        val = gdic.wxBrushList_GetCount(self, *_args, **_kwargs)
        return val
    def __repr__(self):
        return "<%s.%s instance; proxy of C++ wxBrushList instance at %s>" % (self.__class__.__module__, self.__class__.__name__, self.this)
class wxBrushList(wxBrushListPtr):
    def __init__(self,this):
        self.this = this




class wxDCPtr(wxObjectPtr):
    def __init__(self,this):
        self.this = this
        self.thisown = 0
    def __del__(self, delfunc=gdic.delete_wxDC):
        if self.thisown == 1:
            try:
                delfunc(self)
            except:
                pass
    def BeginDrawing(self, *_args, **_kwargs):
        val = gdic.wxDC_BeginDrawing(self, *_args, **_kwargs)
        return val
    def Blit(self, *_args, **_kwargs):
        val = gdic.wxDC_Blit(self, *_args, **_kwargs)
        return val
    def Clear(self, *_args, **_kwargs):
        val = gdic.wxDC_Clear(self, *_args, **_kwargs)
        return val
    def CrossHair(self, *_args, **_kwargs):
        val = gdic.wxDC_CrossHair(self, *_args, **_kwargs)
        return val
    def DestroyClippingRegion(self, *_args, **_kwargs):
        val = gdic.wxDC_DestroyClippingRegion(self, *_args, **_kwargs)
        return val
    def DeviceToLogicalX(self, *_args, **_kwargs):
        val = gdic.wxDC_DeviceToLogicalX(self, *_args, **_kwargs)
        return val
    def DeviceToLogicalXRel(self, *_args, **_kwargs):
        val = gdic.wxDC_DeviceToLogicalXRel(self, *_args, **_kwargs)
        return val
    def DeviceToLogicalY(self, *_args, **_kwargs):
        val = gdic.wxDC_DeviceToLogicalY(self, *_args, **_kwargs)
        return val
    def DeviceToLogicalYRel(self, *_args, **_kwargs):
        val = gdic.wxDC_DeviceToLogicalYRel(self, *_args, **_kwargs)
        return val
    def DrawArc(self, *_args, **_kwargs):
        val = gdic.wxDC_DrawArc(self, *_args, **_kwargs)
        return val
    def DrawCircle(self, *_args, **_kwargs):
        val = gdic.wxDC_DrawCircle(self, *_args, **_kwargs)
        return val
    def DrawEllipse(self, *_args, **_kwargs):
        val = gdic.wxDC_DrawEllipse(self, *_args, **_kwargs)
        return val
    def DrawEllipticArc(self, *_args, **_kwargs):
        val = gdic.wxDC_DrawEllipticArc(self, *_args, **_kwargs)
        return val
    def DrawIcon(self, *_args, **_kwargs):
        val = gdic.wxDC_DrawIcon(self, *_args, **_kwargs)
        return val
    def DrawLabel(self, *_args, **_kwargs):
        val = gdic.wxDC_DrawLabel(self, *_args, **_kwargs)
        return val
    def DrawImageLabel(self, *_args, **_kwargs):
        val = gdic.wxDC_DrawImageLabel(self, *_args, **_kwargs)
        if val: val = wxRectPtr(val) ; val.thisown = 1
        return val
    def DrawLine(self, *_args, **_kwargs):
        val = gdic.wxDC_DrawLine(self, *_args, **_kwargs)
        return val
    def DrawLines(self, *_args, **_kwargs):
        val = gdic.wxDC_DrawLines(self, *_args, **_kwargs)
        return val
    def DrawPolygon(self, *_args, **_kwargs):
        val = gdic.wxDC_DrawPolygon(self, *_args, **_kwargs)
        return val
    def DrawPoint(self, *_args, **_kwargs):
        val = gdic.wxDC_DrawPoint(self, *_args, **_kwargs)
        return val
    def DrawRectangle(self, *_args, **_kwargs):
        val = gdic.wxDC_DrawRectangle(self, *_args, **_kwargs)
        return val
    def DrawRectangleRect(self, *_args, **_kwargs):
        val = gdic.wxDC_DrawRectangleRect(self, *_args, **_kwargs)
        return val
    def DrawRotatedText(self, *_args, **_kwargs):
        val = gdic.wxDC_DrawRotatedText(self, *_args, **_kwargs)
        return val
    def DrawRoundedRectangle(self, *_args, **_kwargs):
        val = gdic.wxDC_DrawRoundedRectangle(self, *_args, **_kwargs)
        return val
    def DrawSpline(self, *_args, **_kwargs):
        val = gdic.wxDC_DrawSpline(self, *_args, **_kwargs)
        return val
    def DrawText(self, *_args, **_kwargs):
        val = gdic.wxDC_DrawText(self, *_args, **_kwargs)
        return val
    def EndDoc(self, *_args, **_kwargs):
        val = gdic.wxDC_EndDoc(self, *_args, **_kwargs)
        return val
    def EndDrawing(self, *_args, **_kwargs):
        val = gdic.wxDC_EndDrawing(self, *_args, **_kwargs)
        return val
    def EndPage(self, *_args, **_kwargs):
        val = gdic.wxDC_EndPage(self, *_args, **_kwargs)
        return val
    def FloodFill(self, *_args, **_kwargs):
        val = gdic.wxDC_FloodFill(self, *_args, **_kwargs)
        return val
    def GetBackground(self, *_args, **_kwargs):
        val = gdic.wxDC_GetBackground(self, *_args, **_kwargs)
        if val: val = wxBrushPtr(val) ; val.thisown = 1
        return val
    def GetBrush(self, *_args, **_kwargs):
        val = gdic.wxDC_GetBrush(self, *_args, **_kwargs)
        if val: val = wxBrushPtr(val) ; val.thisown = 1
        return val
    def GetCharHeight(self, *_args, **_kwargs):
        val = gdic.wxDC_GetCharHeight(self, *_args, **_kwargs)
        return val
    def GetCharWidth(self, *_args, **_kwargs):
        val = gdic.wxDC_GetCharWidth(self, *_args, **_kwargs)
        return val
    def GetClippingBox(self, *_args, **_kwargs):
        val = gdic.wxDC_GetClippingBox(self, *_args, **_kwargs)
        return val
    def GetFont(self, *_args, **_kwargs):
        val = gdic.wxDC_GetFont(self, *_args, **_kwargs)
        if val: val = wxFontPtr(val) ; val.thisown = 1
        return val
    def GetLogicalFunction(self, *_args, **_kwargs):
        val = gdic.wxDC_GetLogicalFunction(self, *_args, **_kwargs)
        return val
    def GetLogicalScale(self, *_args, **_kwargs):
        val = gdic.wxDC_GetLogicalScale(self, *_args, **_kwargs)
        return val
    def GetMapMode(self, *_args, **_kwargs):
        val = gdic.wxDC_GetMapMode(self, *_args, **_kwargs)
        return val
    def GetOptimization(self, *_args, **_kwargs):
        val = gdic.wxDC_GetOptimization(self, *_args, **_kwargs)
        return val
    def GetPen(self, *_args, **_kwargs):
        val = gdic.wxDC_GetPen(self, *_args, **_kwargs)
        if val: val = wxPenPtr(val) ; val.thisown = 1
        return val
    def GetPixel(self, *_args, **_kwargs):
        val = gdic.wxDC_GetPixel(self, *_args, **_kwargs)
        if val: val = wxColourPtr(val) ; val.thisown = 1
        return val
    def GetSizeTuple(self, *_args, **_kwargs):
        val = gdic.wxDC_GetSizeTuple(self, *_args, **_kwargs)
        return val
    def GetSize(self, *_args, **_kwargs):
        val = gdic.wxDC_GetSize(self, *_args, **_kwargs)
        if val: val = wxSizePtr(val) ; val.thisown = 1
        return val
    def GetSizeMM(self, *_args, **_kwargs):
        val = gdic.wxDC_GetSizeMM(self, *_args, **_kwargs)
        if val: val = wxSizePtr(val) ; val.thisown = 1
        return val
    def GetTextBackground(self, *_args, **_kwargs):
        val = gdic.wxDC_GetTextBackground(self, *_args, **_kwargs)
        if val: val = wxColourPtr(val) ; val.thisown = 1
        return val
    def GetTextExtent(self, *_args, **_kwargs):
        val = gdic.wxDC_GetTextExtent(self, *_args, **_kwargs)
        return val
    def GetFullTextExtent(self, *_args, **_kwargs):
        val = gdic.wxDC_GetFullTextExtent(self, *_args, **_kwargs)
        return val
    def GetMultiLineTextExtent(self, *_args, **_kwargs):
        val = gdic.wxDC_GetMultiLineTextExtent(self, *_args, **_kwargs)
        return val
    def GetTextForeground(self, *_args, **_kwargs):
        val = gdic.wxDC_GetTextForeground(self, *_args, **_kwargs)
        if val: val = wxColourPtr(val) ; val.thisown = 1
        return val
    def GetUserScale(self, *_args, **_kwargs):
        val = gdic.wxDC_GetUserScale(self, *_args, **_kwargs)
        return val
    def LogicalToDeviceX(self, *_args, **_kwargs):
        val = gdic.wxDC_LogicalToDeviceX(self, *_args, **_kwargs)
        return val
    def LogicalToDeviceXRel(self, *_args, **_kwargs):
        val = gdic.wxDC_LogicalToDeviceXRel(self, *_args, **_kwargs)
        return val
    def LogicalToDeviceY(self, *_args, **_kwargs):
        val = gdic.wxDC_LogicalToDeviceY(self, *_args, **_kwargs)
        return val
    def LogicalToDeviceYRel(self, *_args, **_kwargs):
        val = gdic.wxDC_LogicalToDeviceYRel(self, *_args, **_kwargs)
        return val
    def MaxX(self, *_args, **_kwargs):
        val = gdic.wxDC_MaxX(self, *_args, **_kwargs)
        return val
    def MaxY(self, *_args, **_kwargs):
        val = gdic.wxDC_MaxY(self, *_args, **_kwargs)
        return val
    def MinX(self, *_args, **_kwargs):
        val = gdic.wxDC_MinX(self, *_args, **_kwargs)
        return val
    def MinY(self, *_args, **_kwargs):
        val = gdic.wxDC_MinY(self, *_args, **_kwargs)
        return val
    def Ok(self, *_args, **_kwargs):
        val = gdic.wxDC_Ok(self, *_args, **_kwargs)
        return val
    def SetDeviceOrigin(self, *_args, **_kwargs):
        val = gdic.wxDC_SetDeviceOrigin(self, *_args, **_kwargs)
        return val
    def SetBackground(self, *_args, **_kwargs):
        val = gdic.wxDC_SetBackground(self, *_args, **_kwargs)
        return val
    def SetBackgroundMode(self, *_args, **_kwargs):
        val = gdic.wxDC_SetBackgroundMode(self, *_args, **_kwargs)
        return val
    def SetClippingRegion(self, *_args, **_kwargs):
        val = gdic.wxDC_SetClippingRegion(self, *_args, **_kwargs)
        return val
    def SetClippingRegionAsRegion(self, *_args, **_kwargs):
        val = gdic.wxDC_SetClippingRegionAsRegion(self, *_args, **_kwargs)
        return val
    def SetClippingRect(self, *_args, **_kwargs):
        val = gdic.wxDC_SetClippingRect(self, *_args, **_kwargs)
        return val
    def SetPalette(self, *_args, **_kwargs):
        val = gdic.wxDC_SetPalette(self, *_args, **_kwargs)
        return val
    def SetBrush(self, *_args, **_kwargs):
        val = gdic.wxDC_SetBrush(self, *_args, **_kwargs)
        return val
    def SetFont(self, *_args, **_kwargs):
        val = gdic.wxDC_SetFont(self, *_args, **_kwargs)
        return val
    def SetLogicalFunction(self, *_args, **_kwargs):
        val = gdic.wxDC_SetLogicalFunction(self, *_args, **_kwargs)
        return val
    def SetLogicalScale(self, *_args, **_kwargs):
        val = gdic.wxDC_SetLogicalScale(self, *_args, **_kwargs)
        return val
    def SetMapMode(self, *_args, **_kwargs):
        val = gdic.wxDC_SetMapMode(self, *_args, **_kwargs)
        return val
    def SetOptimization(self, *_args, **_kwargs):
        val = gdic.wxDC_SetOptimization(self, *_args, **_kwargs)
        return val
    def SetPen(self, *_args, **_kwargs):
        val = gdic.wxDC_SetPen(self, *_args, **_kwargs)
        return val
    def SetTextBackground(self, *_args, **_kwargs):
        val = gdic.wxDC_SetTextBackground(self, *_args, **_kwargs)
        return val
    def SetTextForeground(self, *_args, **_kwargs):
        val = gdic.wxDC_SetTextForeground(self, *_args, **_kwargs)
        return val
    def SetUserScale(self, *_args, **_kwargs):
        val = gdic.wxDC_SetUserScale(self, *_args, **_kwargs)
        return val
    def StartDoc(self, *_args, **_kwargs):
        val = gdic.wxDC_StartDoc(self, *_args, **_kwargs)
        return val
    def StartPage(self, *_args, **_kwargs):
        val = gdic.wxDC_StartPage(self, *_args, **_kwargs)
        return val
    def DrawBitmap(self, *_args, **_kwargs):
        val = gdic.wxDC_DrawBitmap(self, *_args, **_kwargs)
        return val
    def CanDrawBitmap(self, *_args, **_kwargs):
        val = gdic.wxDC_CanDrawBitmap(self, *_args, **_kwargs)
        return val
    def CanGetTextExtent(self, *_args, **_kwargs):
        val = gdic.wxDC_CanGetTextExtent(self, *_args, **_kwargs)
        return val
    def GetDepth(self, *_args, **_kwargs):
        val = gdic.wxDC_GetDepth(self, *_args, **_kwargs)
        return val
    def GetPPI(self, *_args, **_kwargs):
        val = gdic.wxDC_GetPPI(self, *_args, **_kwargs)
        if val: val = wxSizePtr(val) ; val.thisown = 1
        return val
    def GetLogicalOrigin(self, *_args, **_kwargs):
        val = gdic.wxDC_GetLogicalOrigin(self, *_args, **_kwargs)
        return val
    def SetLogicalOrigin(self, *_args, **_kwargs):
        val = gdic.wxDC_SetLogicalOrigin(self, *_args, **_kwargs)
        return val
    def GetDeviceOrigin(self, *_args, **_kwargs):
        val = gdic.wxDC_GetDeviceOrigin(self, *_args, **_kwargs)
        return val
    def SetAxisOrientation(self, *_args, **_kwargs):
        val = gdic.wxDC_SetAxisOrientation(self, *_args, **_kwargs)
        return val
    def CalcBoundingBox(self, *_args, **_kwargs):
        val = gdic.wxDC_CalcBoundingBox(self, *_args, **_kwargs)
        return val
    def ResetBoundingBox(self, *_args, **_kwargs):
        val = gdic.wxDC_ResetBoundingBox(self, *_args, **_kwargs)
        return val
    def GetBoundingBox(self, *_args, **_kwargs):
        val = gdic.wxDC_GetBoundingBox(self, *_args, **_kwargs)
        return val
    def GetHDC(self, *_args, **_kwargs):
        val = gdic.wxDC_GetHDC(self, *_args, **_kwargs)
        return val
    def _DrawPointList(self, *_args, **_kwargs):
        val = gdic.wxDC__DrawPointList(self, *_args, **_kwargs)
        return val
    def _DrawLineList(self, *_args, **_kwargs):
        val = gdic.wxDC__DrawLineList(self, *_args, **_kwargs)
        return val
    def _DrawRectangleList(self, *_args, **_kwargs):
        val = gdic.wxDC__DrawRectangleList(self, *_args, **_kwargs)
        return val
    def _DrawEllipseList(self, *_args, **_kwargs):
        val = gdic.wxDC__DrawEllipseList(self, *_args, **_kwargs)
        return val
    def _DrawPolygonList(self, *_args, **_kwargs):
        val = gdic.wxDC__DrawPolygonList(self, *_args, **_kwargs)
        return val
    def _DrawTextList(self, *_args, **_kwargs):
        val = gdic.wxDC__DrawTextList(self, *_args, **_kwargs)
        return val
    def __repr__(self):
        return "<%s.%s instance; proxy of C++ wxDC instance at %s>" % (self.__class__.__module__, self.__class__.__name__, self.this)
    def __nonzero__(self): return self.Ok()
    
    def DrawPointList(self, points, pens=None):
        if pens is None:
           pens = []
        elif isinstance(pens, wxPenPtr):
           pens = [pens]
        elif len(pens) != len(points):
           raise ValueError('points and pens must have same length')
        return self._DrawPointList(points, pens, [])


    def DrawLineList(self, lines, pens=None):
        if pens is None:
           pens = []
        elif isinstance(pens, wxPenPtr):
           pens = [pens]
        elif len(pens) != len(lines):
           raise ValueError('lines and pens must have same length')
        return self._DrawLineList(lines, pens, [])


    def DrawRectangleList(self, rectangles, pens=None, brushes=None):
        if pens is None:
           pens = []
        elif isinstance(pens, wxPenPtr):
           pens = [pens]
        elif len(pens) != len(rectangles):
           raise ValueError('rectangles and pens must have same length')
        if brushes is None:
           brushes = []
        elif isinstance(brushes, wxBrushPtr):
           brushes = [brushes]
        elif len(brushes) != len(rectangles):
           raise ValueError('rectangles and brushes must have same length')
        return self._DrawRectangleList(rectangles, pens, brushes)


    def DrawEllipseList(self, ellipses, pens=None, brushes=None):
        if pens is None:
           pens = []
        elif isinstance(pens, wxPenPtr):
           pens = [pens]
        elif len(pens) != len(ellipses):
           raise ValueError('ellipses and pens must have same length')
        if brushes is None:
           brushes = []
        elif isinstance(brushes, wxBrushPtr):
           brushes = [brushes]
        elif len(brushes) != len(ellipses):
           raise ValueError('ellipses and brushes must have same length')
        return self._DrawEllipseList(ellipses, pens, brushes)


    def DrawPolygonList(self, polygons, pens=None, brushes=None):
        ## Note: This does not currently support fill style or offset
        ## you can always use the non-List version if need be.
        ## I really would like to support fill-style, however,
        ## but wxODDEVEN_RULE does not appear to be defined at the Python level
        ## [It's in wx.py... --Robin]
        if pens is None:
           pens = []
        elif isinstance(pens, wxPenPtr):
           pens = [pens]
        elif len(pens) != len(polygons):
           raise ValueError('polygons and pens must have same length')
        if brushes is None:
           brushes = []
        elif isinstance(brushes, wxBrushPtr):
           brushes = [brushes]
        elif len(brushes) != len(polygons):
           raise ValueError('polygons and brushes must have same length')
        return self._DrawPolygonList(polygons, pens, brushes)


    def DrawTextList(self, textList, coords, foregrounds = None, backgrounds = None, fonts = None):
        ## NOTE: this does not currently support changing the font
        ##       Make sure you set Background mode to wxSolid (DC.SetBackgroundMode)
        ##       If you want backgounds to do anything.
        if type(textList) == type(''):
           textList = [textList]
        elif len(textList) != len(coords):
           raise ValueError('textlist and coords must have same length')
        if foregrounds is None:
           foregrounds = []
        elif isinstance(foregrounds, wxColourPtr):
           foregrounds = [foregrounds]
        elif len(foregrounds) != len(coords):
           raise ValueError('foregrounds and coords must have same length')
        if backgrounds is None:
           backgrounds = []
        elif isinstance(backgrounds, wxColourPtr):
           backgrounds = [backgrounds]
        elif len(backgrounds) != len(coords):
           raise ValueError('backgrounds and coords must have same length')
        return  self._DrawTextList(textList, coords, foregrounds, backgrounds)

class wxDC(wxDCPtr):
    def __init__(self,this):
        self.this = this




class wxMemoryDCPtr(wxDCPtr):
    def __init__(self,this):
        self.this = this
        self.thisown = 0
    def SelectObject(self, *_args, **_kwargs):
        val = gdic.wxMemoryDC_SelectObject(self, *_args, **_kwargs)
        return val
    def __repr__(self):
        return "<%s.%s instance; proxy of C++ wxMemoryDC instance at %s>" % (self.__class__.__module__, self.__class__.__name__, self.this)
class wxMemoryDC(wxMemoryDCPtr):
    def __init__(self,*_args,**_kwargs):
        self.this = gdic.new_wxMemoryDC(*_args,**_kwargs)
        self.thisown = 1




class wxBufferedDCPtr(wxMemoryDCPtr):
    def __init__(self,this):
        self.this = this
        self.thisown = 0
    def UnMask(self, *_args, **_kwargs):
        val = gdic.wxBufferedDC_UnMask(self, *_args, **_kwargs)
        return val
    def __repr__(self):
        return "<%s.%s instance; proxy of C++ wxBufferedDC instance at %s>" % (self.__class__.__module__, self.__class__.__name__, self.this)
class wxBufferedDC(wxBufferedDCPtr):
    def __init__(self,*_args,**_kwargs):
        self.this = gdic.new_wxBufferedDC(*_args,**_kwargs)
        self.thisown = 1
        self._dc = _args[0] # save a ref so the other dc won't be deleted before self



def wxBufferedDCInternalBuffer(*_args,**_kwargs):
    val = wxBufferedDCPtr(gdic.new_wxBufferedDCInternalBuffer(*_args,**_kwargs))
    val.thisown = 1
    val._dc = _args[0] # save a ref so the other dc won't be deleted before self
    return val


class wxBufferedPaintDCPtr(wxBufferedDCPtr):
    def __init__(self,this):
        self.this = this
        self.thisown = 0
    def __repr__(self):
        return "<%s.%s instance; proxy of C++ wxBufferedPaintDC instance at %s>" % (self.__class__.__module__, self.__class__.__name__, self.this)
class wxBufferedPaintDC(wxBufferedPaintDCPtr):
    def __init__(self,*_args,**_kwargs):
        self.this = gdic.new_wxBufferedPaintDC(*_args,**_kwargs)
        self.thisown = 1




class wxScreenDCPtr(wxDCPtr):
    def __init__(self,this):
        self.this = this
        self.thisown = 0
    def StartDrawingOnTopWin(self, *_args, **_kwargs):
        val = gdic.wxScreenDC_StartDrawingOnTopWin(self, *_args, **_kwargs)
        return val
    def StartDrawingOnTop(self, *_args, **_kwargs):
        val = gdic.wxScreenDC_StartDrawingOnTop(self, *_args, **_kwargs)
        return val
    def EndDrawingOnTop(self, *_args, **_kwargs):
        val = gdic.wxScreenDC_EndDrawingOnTop(self, *_args, **_kwargs)
        return val
    def __repr__(self):
        return "<%s.%s instance; proxy of C++ wxScreenDC instance at %s>" % (self.__class__.__module__, self.__class__.__name__, self.this)
class wxScreenDC(wxScreenDCPtr):
    def __init__(self,*_args,**_kwargs):
        self.this = gdic.new_wxScreenDC(*_args,**_kwargs)
        self.thisown = 1




class wxClientDCPtr(wxDCPtr):
    def __init__(self,this):
        self.this = this
        self.thisown = 0
    def __repr__(self):
        return "<%s.%s instance; proxy of C++ wxClientDC instance at %s>" % (self.__class__.__module__, self.__class__.__name__, self.this)
class wxClientDC(wxClientDCPtr):
    def __init__(self,*_args,**_kwargs):
        self.this = gdic.new_wxClientDC(*_args,**_kwargs)
        self.thisown = 1




class wxPaintDCPtr(wxDCPtr):
    def __init__(self,this):
        self.this = this
        self.thisown = 0
    def __repr__(self):
        return "<%s.%s instance; proxy of C++ wxPaintDC instance at %s>" % (self.__class__.__module__, self.__class__.__name__, self.this)
class wxPaintDC(wxPaintDCPtr):
    def __init__(self,*_args,**_kwargs):
        self.this = gdic.new_wxPaintDC(*_args,**_kwargs)
        self.thisown = 1




class wxWindowDCPtr(wxDCPtr):
    def __init__(self,this):
        self.this = this
        self.thisown = 0
    def __repr__(self):
        return "<%s.%s instance; proxy of C++ wxWindowDC instance at %s>" % (self.__class__.__module__, self.__class__.__name__, self.this)
class wxWindowDC(wxWindowDCPtr):
    def __init__(self,*_args,**_kwargs):
        self.this = gdic.new_wxWindowDC(*_args,**_kwargs)
        self.thisown = 1




class wxMirrorDCPtr(wxDCPtr):
    def __init__(self,this):
        self.this = this
        self.thisown = 0
    def __repr__(self):
        return "<%s.%s instance; proxy of C++ wxMirrorDC instance at %s>" % (self.__class__.__module__, self.__class__.__name__, self.this)
class wxMirrorDC(wxMirrorDCPtr):
    def __init__(self,*_args,**_kwargs):
        self.this = gdic.new_wxMirrorDC(*_args,**_kwargs)
        self.thisown = 1




class wxMetaFilePtr(wxObjectPtr):
    def __init__(self,this):
        self.this = this
        self.thisown = 0
    def __del__(self, delfunc=gdic.delete_wxMetaFile):
        if self.thisown == 1:
            try:
                delfunc(self)
            except:
                pass
    def Ok(self, *_args, **_kwargs):
        val = gdic.wxMetaFile_Ok(self, *_args, **_kwargs)
        return val
    def SetClipboard(self, *_args, **_kwargs):
        val = gdic.wxMetaFile_SetClipboard(self, *_args, **_kwargs)
        return val
    def GetSize(self, *_args, **_kwargs):
        val = gdic.wxMetaFile_GetSize(self, *_args, **_kwargs)
        if val: val = wxSizePtr(val) ; val.thisown = 1
        return val
    def GetWidth(self, *_args, **_kwargs):
        val = gdic.wxMetaFile_GetWidth(self, *_args, **_kwargs)
        return val
    def GetHeight(self, *_args, **_kwargs):
        val = gdic.wxMetaFile_GetHeight(self, *_args, **_kwargs)
        return val
    def GetFileName(self, *_args, **_kwargs):
        val = gdic.wxMetaFile_GetFileName(self, *_args, **_kwargs)
        return val
    def __repr__(self):
        return "<%s.%s instance; proxy of C++ wxMetaFile instance at %s>" % (self.__class__.__module__, self.__class__.__name__, self.this)
    def __nonzero__(self): return self.Ok()
class wxMetaFile(wxMetaFilePtr):
    def __init__(self,*_args,**_kwargs):
        self.this = gdic.new_wxMetaFile(*_args,**_kwargs)
        self.thisown = 1




class wxMetaFileDCPtr(wxDCPtr):
    def __init__(self,this):
        self.this = this
        self.thisown = 0
    def Close(self, *_args, **_kwargs):
        val = gdic.wxMetaFileDC_Close(self, *_args, **_kwargs)
        if val: val = wxMetaFilePtr(val) 
        return val
    def __repr__(self):
        return "<%s.%s instance; proxy of C++ wxMetaFileDC instance at %s>" % (self.__class__.__module__, self.__class__.__name__, self.this)
class wxMetaFileDC(wxMetaFileDCPtr):
    def __init__(self,*_args,**_kwargs):
        self.this = gdic.new_wxMetaFileDC(*_args,**_kwargs)
        self.thisown = 1




class wxPalettePtr(wxGDIObjectPtr):
    def __init__(self,this):
        self.this = this
        self.thisown = 0
    def __del__(self, delfunc=gdic.delete_wxPalette):
        if self.thisown == 1:
            try:
                delfunc(self)
            except:
                pass
    def GetPixel(self, *_args, **_kwargs):
        val = gdic.wxPalette_GetPixel(self, *_args, **_kwargs)
        return val
    def GetRGB(self, *_args, **_kwargs):
        val = gdic.wxPalette_GetRGB(self, *_args, **_kwargs)
        return val
    def Ok(self, *_args, **_kwargs):
        val = gdic.wxPalette_Ok(self, *_args, **_kwargs)
        return val
    def __repr__(self):
        return "<%s.%s instance; proxy of C++ wxPalette instance at %s>" % (self.__class__.__module__, self.__class__.__name__, self.this)
    def __nonzero__(self): return self.Ok()
class wxPalette(wxPalettePtr):
    def __init__(self,*_args,**_kwargs):
        self.this = gdic.new_wxPalette(*_args,**_kwargs)
        self.thisown = 1




class wxImageListPtr(wxObjectPtr):
    def __init__(self,this):
        self.this = this
        self.thisown = 0
    def __del__(self, delfunc=gdic.delete_wxImageList):
        if self.thisown == 1:
            try:
                delfunc(self)
            except:
                pass
    def Add(self, *_args, **_kwargs):
        val = gdic.wxImageList_Add(self, *_args, **_kwargs)
        return val
    def AddWithColourMask(self, *_args, **_kwargs):
        val = gdic.wxImageList_AddWithColourMask(self, *_args, **_kwargs)
        return val
    def AddIcon(self, *_args, **_kwargs):
        val = gdic.wxImageList_AddIcon(self, *_args, **_kwargs)
        return val
    def Replace(self, *_args, **_kwargs):
        val = gdic.wxImageList_Replace(self, *_args, **_kwargs)
        return val
    def Draw(self, *_args, **_kwargs):
        val = gdic.wxImageList_Draw(self, *_args, **_kwargs)
        return val
    def GetImageCount(self, *_args, **_kwargs):
        val = gdic.wxImageList_GetImageCount(self, *_args, **_kwargs)
        return val
    def Remove(self, *_args, **_kwargs):
        val = gdic.wxImageList_Remove(self, *_args, **_kwargs)
        return val
    def RemoveAll(self, *_args, **_kwargs):
        val = gdic.wxImageList_RemoveAll(self, *_args, **_kwargs)
        return val
    def GetSize(self, *_args, **_kwargs):
        val = gdic.wxImageList_GetSize(self, *_args, **_kwargs)
        return val
    def __repr__(self):
        return "<%s.%s instance; proxy of C++ wxImageList instance at %s>" % (self.__class__.__module__, self.__class__.__name__, self.this)
class wxImageList(wxImageListPtr):
    def __init__(self,*_args,**_kwargs):
        self.this = gdic.new_wxImageList(*_args,**_kwargs)
        self.thisown = 1




class wxRegionPtr(wxGDIObjectPtr):
    def __init__(self,this):
        self.this = this
        self.thisown = 0
    def __del__(self, delfunc=gdic.delete_wxRegion):
        if self.thisown == 1:
            try:
                delfunc(self)
            except:
                pass
    def Clear(self, *_args, **_kwargs):
        val = gdic.wxRegion_Clear(self, *_args, **_kwargs)
        return val
    def Offset(self, *_args, **_kwargs):
        val = gdic.wxRegion_Offset(self, *_args, **_kwargs)
        return val
    def Contains(self, *_args, **_kwargs):
        val = gdic.wxRegion_Contains(self, *_args, **_kwargs)
        return val
    def ContainsPoint(self, *_args, **_kwargs):
        val = gdic.wxRegion_ContainsPoint(self, *_args, **_kwargs)
        return val
    def ContainsRect(self, *_args, **_kwargs):
        val = gdic.wxRegion_ContainsRect(self, *_args, **_kwargs)
        return val
    def ContainsRectDim(self, *_args, **_kwargs):
        val = gdic.wxRegion_ContainsRectDim(self, *_args, **_kwargs)
        return val
    def GetBox(self, *_args, **_kwargs):
        val = gdic.wxRegion_GetBox(self, *_args, **_kwargs)
        if val: val = wxRectPtr(val) ; val.thisown = 1
        return val
    def Intersect(self, *_args, **_kwargs):
        val = gdic.wxRegion_Intersect(self, *_args, **_kwargs)
        return val
    def IntersectRect(self, *_args, **_kwargs):
        val = gdic.wxRegion_IntersectRect(self, *_args, **_kwargs)
        return val
    def IntersectRegion(self, *_args, **_kwargs):
        val = gdic.wxRegion_IntersectRegion(self, *_args, **_kwargs)
        return val
    def IsEmpty(self, *_args, **_kwargs):
        val = gdic.wxRegion_IsEmpty(self, *_args, **_kwargs)
        return val
    def Union(self, *_args, **_kwargs):
        val = gdic.wxRegion_Union(self, *_args, **_kwargs)
        return val
    def UnionRect(self, *_args, **_kwargs):
        val = gdic.wxRegion_UnionRect(self, *_args, **_kwargs)
        return val
    def UnionRegion(self, *_args, **_kwargs):
        val = gdic.wxRegion_UnionRegion(self, *_args, **_kwargs)
        return val
    def Subtract(self, *_args, **_kwargs):
        val = gdic.wxRegion_Subtract(self, *_args, **_kwargs)
        return val
    def SubtractRect(self, *_args, **_kwargs):
        val = gdic.wxRegion_SubtractRect(self, *_args, **_kwargs)
        return val
    def SubtractRegion(self, *_args, **_kwargs):
        val = gdic.wxRegion_SubtractRegion(self, *_args, **_kwargs)
        return val
    def Xor(self, *_args, **_kwargs):
        val = gdic.wxRegion_Xor(self, *_args, **_kwargs)
        return val
    def XorRect(self, *_args, **_kwargs):
        val = gdic.wxRegion_XorRect(self, *_args, **_kwargs)
        return val
    def XorRegion(self, *_args, **_kwargs):
        val = gdic.wxRegion_XorRegion(self, *_args, **_kwargs)
        return val
    def ConvertToBitmap(self, *_args, **_kwargs):
        val = gdic.wxRegion_ConvertToBitmap(self, *_args, **_kwargs)
        if val: val = wxBitmapPtr(val) ; val.thisown = 1
        return val
    def UnionBitmap(self, *_args, **_kwargs):
        val = gdic.wxRegion_UnionBitmap(self, *_args, **_kwargs)
        return val
    def __repr__(self):
        return "<%s.%s instance; proxy of C++ wxRegion instance at %s>" % (self.__class__.__module__, self.__class__.__name__, self.this)
class wxRegion(wxRegionPtr):
    def __init__(self,*_args,**_kwargs):
        self.this = gdic.new_wxRegion(*_args,**_kwargs)
        self.thisown = 1



def wxRegionFromPoints(*_args,**_kwargs):
    val = wxRegionPtr(gdic.new_wxRegionFromPoints(*_args,**_kwargs))
    val.thisown = 1
    return val

def wxRegionFromBitmap(*_args,**_kwargs):
    val = wxRegionPtr(gdic.new_wxRegionFromBitmap(*_args,**_kwargs))
    val.thisown = 1
    return val


class wxRegionIteratorPtr(wxObjectPtr):
    def __init__(self,this):
        self.this = this
        self.thisown = 0
    def __del__(self, delfunc=gdic.delete_wxRegionIterator):
        if self.thisown == 1:
            try:
                delfunc(self)
            except:
                pass
    def GetX(self, *_args, **_kwargs):
        val = gdic.wxRegionIterator_GetX(self, *_args, **_kwargs)
        return val
    def GetY(self, *_args, **_kwargs):
        val = gdic.wxRegionIterator_GetY(self, *_args, **_kwargs)
        return val
    def GetW(self, *_args, **_kwargs):
        val = gdic.wxRegionIterator_GetW(self, *_args, **_kwargs)
        return val
    def GetWidth(self, *_args, **_kwargs):
        val = gdic.wxRegionIterator_GetWidth(self, *_args, **_kwargs)
        return val
    def GetH(self, *_args, **_kwargs):
        val = gdic.wxRegionIterator_GetH(self, *_args, **_kwargs)
        return val
    def GetHeight(self, *_args, **_kwargs):
        val = gdic.wxRegionIterator_GetHeight(self, *_args, **_kwargs)
        return val
    def GetRect(self, *_args, **_kwargs):
        val = gdic.wxRegionIterator_GetRect(self, *_args, **_kwargs)
        if val: val = wxRectPtr(val) ; val.thisown = 1
        return val
    def HaveRects(self, *_args, **_kwargs):
        val = gdic.wxRegionIterator_HaveRects(self, *_args, **_kwargs)
        return val
    def Reset(self, *_args, **_kwargs):
        val = gdic.wxRegionIterator_Reset(self, *_args, **_kwargs)
        return val
    def Next(self, *_args, **_kwargs):
        val = gdic.wxRegionIterator_Next(self, *_args, **_kwargs)
        return val
    def __repr__(self):
        return "<%s.%s instance; proxy of C++ wxRegionIterator instance at %s>" % (self.__class__.__module__, self.__class__.__name__, self.this)
class wxRegionIterator(wxRegionIteratorPtr):
    def __init__(self,*_args,**_kwargs):
        self.this = gdic.new_wxRegionIterator(*_args,**_kwargs)
        self.thisown = 1






#-------------- FUNCTION WRAPPERS ------------------

def wxEmptyBitmap(*_args, **_kwargs):
    val = gdic.wxEmptyBitmap(*_args,**_kwargs)
    if val: val = wxBitmapPtr(val); val.thisown = 1
    return val

def wxBitmapFromXPMData(*_args, **_kwargs):
    val = gdic.wxBitmapFromXPMData(*_args,**_kwargs)
    if val: val = wxBitmapPtr(val); val.thisown = 1
    return val

def wxBitmapFromIcon(*_args, **_kwargs):
    val = gdic.wxBitmapFromIcon(*_args,**_kwargs)
    if val: val = wxBitmapPtr(val); val.thisown = 1
    return val

def wxBitmapFromBits(*_args, **_kwargs):
    val = gdic.wxBitmapFromBits(*_args,**_kwargs)
    if val: val = wxBitmapPtr(val); val.thisown = 1
    return val

def wxMaskColour(*_args, **_kwargs):
    val = gdic.wxMaskColour(*_args,**_kwargs)
    if val: val = wxMaskPtr(val); val.thisown = 1
    return val

def wxEmptyIcon(*_args, **_kwargs):
    val = gdic.wxEmptyIcon(*_args,**_kwargs)
    if val: val = wxIconPtr(val); val.thisown = 1
    return val

def wxIconFromXPMData(*_args, **_kwargs):
    val = gdic.wxIconFromXPMData(*_args,**_kwargs)
    if val: val = wxIconPtr(val); val.thisown = 1
    return val

def wxIconFromBitmap(*_args, **_kwargs):
    val = gdic.wxIconFromBitmap(*_args,**_kwargs)
    if val: val = wxIconPtr(val); val.thisown = 1
    return val

def wxIconFromLocation(*_args, **_kwargs):
    val = gdic.wxIconFromLocation(*_args,**_kwargs)
    if val: val = wxIconPtr(val); val.thisown = 1
    return val

def wxStockCursor(*_args, **_kwargs):
    val = gdic.wxStockCursor(*_args,**_kwargs)
    if val: val = wxCursorPtr(val); val.thisown = 1
    return val

def wxCursorFromImage(*_args, **_kwargs):
    val = gdic.wxCursorFromImage(*_args,**_kwargs)
    if val: val = wxCursorPtr(val); val.thisown = 1
    return val

def wxCursorFromBits(*_args, **_kwargs):
    val = gdic.wxCursorFromBits(*_args,**_kwargs)
    if val: val = wxCursorPtr(val); val.thisown = 1
    return val

def wxNamedColour(*_args, **_kwargs):
    val = gdic.wxNamedColour(*_args,**_kwargs)
    if val: val = wxColourPtr(val); val.thisown = 1
    return val

def wxMemoryDCFromDC(*_args, **_kwargs):
    val = gdic.wxMemoryDCFromDC(*_args,**_kwargs)
    if val: val = wxMemoryDCPtr(val); val.thisown = 1
    return val



#-------------- VARIABLE WRAPPERS ------------------

wxIMAGELIST_DRAW_NORMAL = gdic.wxIMAGELIST_DRAW_NORMAL
wxIMAGELIST_DRAW_TRANSPARENT = gdic.wxIMAGELIST_DRAW_TRANSPARENT
wxIMAGELIST_DRAW_SELECTED = gdic.wxIMAGELIST_DRAW_SELECTED
wxIMAGELIST_DRAW_FOCUSED = gdic.wxIMAGELIST_DRAW_FOCUSED
wxIMAGE_LIST_NORMAL = gdic.wxIMAGE_LIST_NORMAL
wxIMAGE_LIST_SMALL = gdic.wxIMAGE_LIST_SMALL
wxIMAGE_LIST_STATE = gdic.wxIMAGE_LIST_STATE
wxOutRegion = gdic.wxOutRegion
wxPartRegion = gdic.wxPartRegion
wxInRegion = gdic.wxInRegion
cvar = gdic.cvar
wxNORMAL_FONT = wxFontPtr(gdic.cvar.wxNORMAL_FONT)
wxSMALL_FONT = wxFontPtr(gdic.cvar.wxSMALL_FONT)
wxITALIC_FONT = wxFontPtr(gdic.cvar.wxITALIC_FONT)
wxSWISS_FONT = wxFontPtr(gdic.cvar.wxSWISS_FONT)
wxRED_PEN = wxPenPtr(gdic.cvar.wxRED_PEN)
wxCYAN_PEN = wxPenPtr(gdic.cvar.wxCYAN_PEN)
wxGREEN_PEN = wxPenPtr(gdic.cvar.wxGREEN_PEN)
wxBLACK_PEN = wxPenPtr(gdic.cvar.wxBLACK_PEN)
wxWHITE_PEN = wxPenPtr(gdic.cvar.wxWHITE_PEN)
wxTRANSPARENT_PEN = wxPenPtr(gdic.cvar.wxTRANSPARENT_PEN)
wxBLACK_DASHED_PEN = wxPenPtr(gdic.cvar.wxBLACK_DASHED_PEN)
wxGREY_PEN = wxPenPtr(gdic.cvar.wxGREY_PEN)
wxMEDIUM_GREY_PEN = wxPenPtr(gdic.cvar.wxMEDIUM_GREY_PEN)
wxLIGHT_GREY_PEN = wxPenPtr(gdic.cvar.wxLIGHT_GREY_PEN)
wxBLUE_BRUSH = wxBrushPtr(gdic.cvar.wxBLUE_BRUSH)
wxGREEN_BRUSH = wxBrushPtr(gdic.cvar.wxGREEN_BRUSH)
wxWHITE_BRUSH = wxBrushPtr(gdic.cvar.wxWHITE_BRUSH)
wxBLACK_BRUSH = wxBrushPtr(gdic.cvar.wxBLACK_BRUSH)
wxTRANSPARENT_BRUSH = wxBrushPtr(gdic.cvar.wxTRANSPARENT_BRUSH)
wxCYAN_BRUSH = wxBrushPtr(gdic.cvar.wxCYAN_BRUSH)
wxRED_BRUSH = wxBrushPtr(gdic.cvar.wxRED_BRUSH)
wxGREY_BRUSH = wxBrushPtr(gdic.cvar.wxGREY_BRUSH)
wxMEDIUM_GREY_BRUSH = wxBrushPtr(gdic.cvar.wxMEDIUM_GREY_BRUSH)
wxLIGHT_GREY_BRUSH = wxBrushPtr(gdic.cvar.wxLIGHT_GREY_BRUSH)
wxBLACK = wxColourPtr(gdic.cvar.wxBLACK)
wxWHITE = wxColourPtr(gdic.cvar.wxWHITE)
wxRED = wxColourPtr(gdic.cvar.wxRED)
wxBLUE = wxColourPtr(gdic.cvar.wxBLUE)
wxGREEN = wxColourPtr(gdic.cvar.wxGREEN)
wxCYAN = wxColourPtr(gdic.cvar.wxCYAN)
wxLIGHT_GREY = wxColourPtr(gdic.cvar.wxLIGHT_GREY)
wxSTANDARD_CURSOR = wxCursorPtr(gdic.cvar.wxSTANDARD_CURSOR)
wxHOURGLASS_CURSOR = wxCursorPtr(gdic.cvar.wxHOURGLASS_CURSOR)
wxCROSS_CURSOR = wxCursorPtr(gdic.cvar.wxCROSS_CURSOR)
wxNullBitmap = wxBitmapPtr(gdic.cvar.wxNullBitmap)
wxNullIcon = wxIconPtr(gdic.cvar.wxNullIcon)
wxNullCursor = wxCursorPtr(gdic.cvar.wxNullCursor)
wxNullPen = wxPenPtr(gdic.cvar.wxNullPen)
wxNullBrush = wxBrushPtr(gdic.cvar.wxNullBrush)
wxNullPalette = wxPalettePtr(gdic.cvar.wxNullPalette)
wxNullFont = wxFontPtr(gdic.cvar.wxNullFont)
wxNullColour = wxColourPtr(gdic.cvar.wxNullColour)
wxTheFontList = wxFontListPtr(gdic.cvar.wxTheFontList)
wxThePenList = wxPenListPtr(gdic.cvar.wxThePenList)
wxTheBrushList = wxBrushListPtr(gdic.cvar.wxTheBrushList)
wxTheColourDatabase = wxColourDatabasePtr(gdic.cvar.wxTheColourDatabase)
