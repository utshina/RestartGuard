CFLAGS=-nologo /GS- /GF /Ot
LFLAGS=/link /section:.text,RE /merge:.rdata=.text /merge:.pdata=.text /subsystem:windows /incremental:no /nodefaultlib /out:$@ /entry:"WinMainCRT" kernel32.lib advapi32.lib
STRIP=
RM=del /f

!include Makefile.common
