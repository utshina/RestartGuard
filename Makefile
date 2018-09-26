CFLAGS=-nologo /GS- /GF /Ot
LFLAGS=/link /subsystem:windows /entry:main /out:$@ kernel32.lib advapi32.lib
STRIP=
RM=del /f

!include Makefile.common
