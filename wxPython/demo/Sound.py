
import  wx

from Main import opj

#----------------------------------------------------------------------

class TestPanel(wx.Panel):
    def __init__(self, parent):
        wx.Panel.__init__(self, parent, -1)

        b = wx.Button(self, -1, "Play Sound 1", (25, 25))
        self.Bind(wx.EVT_BUTTON, self.OnButton1, b)

        b = wx.Button(self, -1, "Play Sound 2", (25, 65))
        self.Bind(wx.EVT_BUTTON, self.OnButton2, b)


    def OnButton1(self, evt):
        try:
            sound = wx.Sound(opj('data/anykey.wav'))
            sound.Play()
        except NotImplementedError, v:
            wx.MessageBox(str(v), "Exception Message")


    def OnButton2(self, evt):
        try:
            sound = wx.Sound(opj('data/plan.wav'))
            sound.Play()
        except NotImplementedError, v:
            wx.MessageBox(str(v), "Exception Message")

#----------------------------------------------------------------------

def runTest(frame, nb, log):
    win = TestPanel(nb)
    return win

#----------------------------------------------------------------------


overview = """<html><body>
<h2>Sound</h2>
This class represents a short wave file, in Windows WAV format, that can 
be stored in memory and played. Currently this class is implemented on Windows 
and GTK (Linux) only.
<p>
This demo offers two examples, both driven by buttons, but obviously the event
that drives the playing of the sound can come from anywhere.

</body></html>
"""


if __name__ == '__main__':
    import sys,os
    import run
    run.main(['', os.path.basename(sys.argv[0])] + sys.argv[1:])
