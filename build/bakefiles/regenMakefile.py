#!/usr/bin/env python

#
# Generates Makefile that is used to regenerate native makefiles from
# bakefiles.
#
# $Id$
#

import string, os.path, copy

file = open('Makefile', 'wt')
file.write("""
# Generated by regenMakefile.py

BAKEFILE = bakefile -v


CDEPS = config.bkl common.bkl common_contrib.bkl
SDEPS = config.bkl common.bkl common_samples.bkl
MDEPS = common.bkl config.bkl files.bkl monolithic.bkl multilib.bkl opengl.bkl wxwin.py

DSWFLAGS = -DRUNTIME_LIBS=dynamic -DOFFICIAL_BUILD=0 -DUSE_HTML=1 \\
           -DUSE_OPENGL=1 -DUSE_ODBC=1 -DMONOLITHIC=0 -DUSE_GUI=1 \\
           -DDEBUG_INFO=default -DDEBUG_FLAG=default

COMPAT_TARGETS = ../../src/wxWindows.dsp

""")

lines = {}
all = {}
all['autoconf'] = []

linesCur = None

def addMakefile(bake, makedirs, deps=[], args={}):
    """Adds rules to regenerate native makefile in directory 'makedir' from
       bakefiles 'bake'. 'deps' contains additional dependencies (bakefiles
       other than 'bake'."""
    print 'adding %s...' % bake
    global linesCur
    linesCur = ['\n']

    def add(bake, makedirs, make, dep, format, args={}):
        global linesCur
        a = ''
        if 'all' in args: a += ' %s' % args['all']
        if format in args: a += ' %s' % args[format]
        if format != 'autoconf' and 'not_autoconf' in args:
            a += ' %s' % args['not_autoconf']
        if format in makedirs:
            makedir = makedirs[format]
        else:
            makedir = makedirs['all']
        tfile = '%s/%s' % (makedir, make)
        linesCur.append('%s: %s' % (tfile, dep))
        linesCur.append('\t$(BAKEFILE) -f%s -o$@ %s %s' % (format, a, bake))
        linesCur.append('\ttouch $@')
        if format not in all: all[format] = []
        all[format].append(tfile)

    dep = string.join(deps + [bake], ' ')

    add(bake, makedirs, 'Makefile.in', dep, 'autoconf', args)
    add(bake, makedirs, 'makefile.bcc', dep, 'borland', args)
    add(bake, makedirs, 'makefile.vc', dep, 'msvc', args)
    add(bake, makedirs, 'makefile.gcc', dep, 'mingw', args)
    add(bake, makedirs, 'makefile.wat', dep, 'watcom', args)

    if 'msvc6prj' in args and args['msvc6prj'] != None:
        add(bake, makedirs,
            (bake[1+bake.rfind('/'):]).replace('.bkl','.dsw'),
            dep, 'msvc6prj', args)
    
    lines[bake] = linesCur



# -----------------------------------------------
#    Add the makefiles:
# -----------------------------------------------

# main makefile:
addMakefile('wx.bkl', {'all':'..','autoconf':'../..'}, [ '$(MDEPS)' ],
            args={
                'borland':'-DOPTIONS_FILE=config.bcc',
                'msvc':'-DOPTIONS_FILE=config.vc',
                'mingw':'-DOPTIONS_FILE=config.gcc',
                'watcom':'-DOPTIONS_FILE=config.wat',
                'msvc6prj':'$(DSWFLAGS)',
            })

# samples main makefile:
addMakefile('../../samples/samples.bkl', {'all':'../../samples'},
            args={
            'autoconf':'-DAUTOCONF_MACROS_FILE=../../autoconf_inc.m4',
            'borland':'-DOPTIONS_FILE=../build/config.bcc -DWRITE_OPTIONS_FILE=0',
            'msvc':'-DOPTIONS_FILE=../build/config.vc -DWRITE_OPTIONS_FILE=0',
            'mingw':'-DOPTIONS_FILE=../build/config.gcc -DWRITE_OPTIONS_FILE=0',
            'watcom':'-DOPTIONS_FILE=../build/config.wat -DWRITE_OPTIONS_FILE=0',
            'msvc6prj':None,
            })


CONTRIB_DIR = 1
SAMPLES_DIR = 2

def onSubmakefile(type, dirname, names):
    bakes = [x for x in names if x.endswith('.bkl')]
    if len(bakes) == 0: return
    bakes.sort()
    dirname = dirname.replace(os.sep, '/')
    depth = dirname.count('/') - 2
    if depth <= 0: return
    
    if type==SAMPLES_DIR:
        prefix = ''.join(['../' for i in range(0,depth)])
        dirflags = '-DWXTOPDIR=%s../' % prefix
        cfgbase = '%s../build/config.' % prefix
    elif type==CONTRIB_DIR:
        dirflags = '-DSRCDIR=../../src/%s' % dirname.split('/')[-1]
        dirflags += ' -DWXTOPDIR=../../../'
        cfgbase = '../../../build/config.'

    args = {
        'not_autoconf':dirflags,
        'autoconf':'-DAUTOCONF_MACROS_FILE=../../autoconf_inc.m4',
        'msvc':'-DOPTIONS_FILE='+cfgbase+'vc -DWRITE_OPTIONS_FILE=0',
        'mingw':'-DOPTIONS_FILE='+cfgbase+'gcc -DWRITE_OPTIONS_FILE=0',
        'borland':'-DOPTIONS_FILE='+cfgbase+'bcc -DWRITE_OPTIONS_FILE=0',
        'watcom':'-DOPTIONS_FILE='+cfgbase+'wat -DWRITE_OPTIONS_FILE=0',
        'msvc6prj':'$(DSWFLAGS)',
    }

    for bake in bakes:
        if bake.endswith('_samples.bkl'):
            args['msvc6prj'] = None
        if type==CONTRIB_DIR:
            acdir = '../../contrib/src/%s' % dirname.split('/')[-1]
            ruledep = '$(CDEPS)'
        else:
            acdir = dirname
            ruledep = '$(SDEPS)'
        addMakefile('%s/%s' % (dirname, bake),
                    {'all':dirname,'autoconf':acdir}, deps=[ruledep],
                    args=args)

os.path.walk(os.path.join('..','..','samples'),
             onSubmakefile, SAMPLES_DIR)
os.path.walk(os.path.join('..','..','demos'),
             onSubmakefile, SAMPLES_DIR)
os.path.walk(os.path.join('..','..','contrib','build'),
             onSubmakefile, CONTRIB_DIR)
os.path.walk(os.path.join('..','..','contrib','samples'),
             onSubmakefile, SAMPLES_DIR)
os.path.walk(os.path.join('..','..','contrib','utils'),
             onSubmakefile, SAMPLES_DIR)


cleanCmds = ''
allK = all.keys()
allK.sort()
cleanList = []

for f in allK:
    all[f].sort()

for f in allK:
    for i in all[f]:
        cleanList.append('\trm -f %s\n' % i)
    cleanCmds = ''.join(cleanList)

for f in allK:
    var = '%s_ALL' % f.upper()
    file.write('%s = \\\n\t%s\n' % (var,' \\\n\t'.join(all[f])))

file.write('\nall: $(COMPAT_TARGETS)')
for f in allK:
    file.write(' %s' % f)
file.write('\n\n')
for f in allK:
    file.write('%s: $(%s_ALL)\n' % (f, f.upper()))

file.write("""
clean:
\trm -f ../../autoconf_inc.m4
\trm -f $(COMPAT_TARGETS)
%s

library: ../../Makefile.in ../makefile.bcc ../makefile.vc ../makefile.wat ../makefile.gcc

../../autoconf_inc.m4: ../../Makefile.in

../../src/wxWindows.dsp: monolithic.bkl files.bkl
\t$(BAKEFILE) -Icompat -fwx24dsp -DUSE_GUI=1 -DWXUNIV=0 -o$@ wx.bkl
\ttouch $@

Makefile: regenMakefile.py
\t./regenMakefile.py
\t@echo
\t@echo -------------------------------------------
\t@echo Please rerun make, Makefile was regenerated
\t@echo -------------------------------------------
\t@echo
\t@exit 1
""" % cleanCmds)
linesK = lines.keys()
linesK.sort()
for lk in linesK:
    for l in lines[lk]:
        file.write('%s\n' % l)
file.close()
