### Makefile.am

AM_CPPFLAGS = -D_POSIX_C_SOURCE=200112L -D_XOPEN_SOURCE=600 -D_BSD_SOURCE
AM_LDFLAGS =

headerdir = $(includedir)/dateutils

noinst_PROGRAMS =
noinst_HEADERS =
BUILT_SOURCES =
CLEANFILES =
EXTRA_DIST = $(BUILT_SOURCES)

header_HEADERS =
header_HEADERS += date-core.h date-core.c
header_HEADERS += time-core.h time-core.c
header_HEADERS += dt-core.h dt-core.c
header_HEADERS += strops.h strops.c
header_HEADERS += token.h token.c
header_HEADERS += tzraw.h tzraw.c
header_HEADERS += boobs.h
header_HEADERS += generics.h
header_HEADERS += dt-core-tz-glue.h dt-core-tz-glue.c


# 
# Help the developers get nice post-processed source files

## Create preprocessor output (debugging purposes only)
.c.i:
	$(COMPILE) -E -o $@ $<

## Create assembler output (debugging purposes only)
.c.s:
	$(COMPILE) -S -c $(AM_CFLAGS) $<
