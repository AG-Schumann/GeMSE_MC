# --------------------------------
# GNUmakefile - Diego Ramírez
# Last updated: Mon Feb 11 2018
# --------------------------------

name := GeMSE_efficiency

#GEANTVERSION = $(shell geant4-config --version | cut -d'.' -f1)

#ifneq ($(GEANTVERSION), 9)
#name := $(shell ln -sf GeMSE_efficiency.cc GeMSE_efficiency_p$(GEANTVERSION).cc && echo GeMSE_efficiency_p$(GEANTVERSION))
#endif

G4TARGET := $(name)
G4EXLIB := true
MYEXEPATH :=$(G4WORKDIR)/bin/$(G4SYSTEM)
#CPPVERBOSE := true

G4DEBUG := 0

GEANTLIBS       = $(shell geant4-config --libs)
ROOTCFLAGS      = $(shell root-config --cflags)
ROOTGLIBS       = $(shell root-config --glibs)

EXTRALIBS +=$(ROOTGLIBS) $(GEANTLIBS)

#DR 20180208
EXTRALIBS +=/scratch/dr1036/Software/assimp/lib/libassimp.so
EXTRALIBS +=/scratch/dr1036/Software/tetgen/tetlib.so

CPPFLAGS += $(ROOTCFLAGS)

.PHONY: all

all: lib bin

include config/binmake.gmk
