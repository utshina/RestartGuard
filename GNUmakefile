MINGW1=$(shell which amd64-mingw32msvc-cc 2> /dev/null)
MINGW2=$(shell which x86_64-w64-mingw32-gcc 2> /dev/null)
ifneq ("$(MINGW1)","")
	CC=$(MINGW1)
else ifneq ("$(MINGW2)","")
	CC=$(MINGW2)
else
$(error MinGW gcc not found)
endif

CFLAGS=-O6
LFLAGS=-mwindows -o $@ -lkernel32 -ladvapi32
STRIP=strip $@
RM=rm -f

include Makefile.common

.PHONY: zip clean
