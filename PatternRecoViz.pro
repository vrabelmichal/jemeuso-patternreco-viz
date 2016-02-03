#-------------------------------------------------
#
# Project created by QtCreator 2016-01-31T20:56:46
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = PatternRecoViz
TEMPLATE = app

CONFIG += c++14

#ROOTGLIBS = $$system(${ROOTSYS}/bin/root-config --glibs --ldflags)
#QMAKE_LFLAGS += $${ROOTGLIBS}

#ROOTCFLAGS = $$system(${ROOTSYS}/bin/root-config --cflags)
#QMAKE_CFLAGS += $${ROOTCFLAGS}

#INCLUDEPATH += $$(ROOTSYS)/include
##INCLUDEPATH += $$PWD/root/include

#message(${ROOTCFLAGS})
#message($${ROOTCFLAGS})


#message("before")
#message($${INCLUDEPATH})
#message($ROOTSYS)
#message($$ROOTSYS)
#message(${ROOTSYS})
#message($${ROOTSYS})
#message($(ROOTSYS))
#message($$(ROOTSYS))
#message($PWD)
#message($$PWD)
#message($(PWD))
#message($$(PWD))
#message($PATH)
#message($(PATH))
#message($$(PATH))
#message("after")

SOURCES += main.cpp\
        mainwindow.cpp \
    ui/mainwindowhandwritten.cpp
#    root/src/EAFee.cc \
#    root/src/EAnglePixelMap.cc \
#    root/src/EAtmosphere.cc \
#    root/src/EBunchPhotons.cc \
#    root/src/ECCB_LTTTrigger.cc \
#    root/src/ECCB_LTTTriggerSegment.cc \
#    root/src/EChipTrackSegment.cc \
#    root/src/EChipTrackTrigger.cc \
#    root/src/EChipTriggPars.cc \
#    root/src/EDetector.cc \
#    root/src/EDetPhoton.cc \
#    root/src/EDetStatus.cc \
#    root/src/EElectronics.cc \
#    root/src/EEvent.cc \
#    root/src/EFee.cc \
#    root/src/EFillable.cc \
#    root/src/EFiller.cc \
#    root/src/EGeometry.cc \
#    root/src/EHeader.cc \
#    root/src/ELblTrackSegment.cc \
#    root/src/ELblTrackTrigger.cc \
#    root/src/ELTTTrigger.cc \
#    root/src/ELTTTriggerSegment.cc \
#    root/src/EMacroCell.cc \
#    root/src/EMacroCellHit.cc \
#    root/src/EOpticsResponse.cc \
#    root/src/EORHeader.cc \
#    root/src/EORSample.cc \
#    root/src/EPhotoElectron.cc \
#    root/src/EPhoton.cc \
#    root/src/EPmtData.cc \
#    root/src/EPmtGeo.cc \
#    root/src/EPTTTrigger.cc \
#    root/src/EPTTTriggerSegment.cc \
#    root/src/EReader.cc \
#    root/src/ERunParameters.cc \
#    root/src/ERunParsFiller.cc \
#    root/src/EShower.cc \
#    root/src/EShowerStep.cc \
#    root/src/ESimpDetPhoton.cc \
#    root/src/ESimpleDetector.cc \
#    root/src/ESinglePhoton.cc \
#    root/src/ETriggPars.cc \
#    root/src/ETruth.cc

HEADERS  += mainwindow.h \
    ui/mainwindowhandwritten.h
#    root/include/EAFee.hh \
#    root/include/EAnglePixelMap.hh \
#    root/include/EAtmosphere.hh \
#    root/include/EBunchPhotons.hh \
#    root/include/ECCB_LTTTrigger.hh \
#    root/include/ECCB_LTTTriggerSegment.hh \
#    root/include/EChipTrackSegment.hh \
#    root/include/EChipTrackTrigger.hh \
#    root/include/EChipTriggPars.hh \
#    root/include/EDetector.hh \
#    root/include/EDetPhoton.hh \
#    root/include/EDetStatus.hh \
#    root/include/EElectronics.hh \
#    root/include/EEvent.hh \
#    root/include/EFee.hh \
#    root/include/EFillable.hh \
#    root/include/EFiller.hh \
#    root/include/EGeometry.hh \
#    root/include/EHeader.hh \
#    root/include/ELblTrackSegment.hh \
#    root/include/ELblTrackTrigger.hh \
#    root/include/ELTTTrigger.hh \
#    root/include/ELTTTriggerSegment.hh \
#    root/include/EMacroCell.hh \
#    root/include/EMacroCellHit.hh \
#    root/include/EOpticsResponse.hh \
#    root/include/EORHeader.hh \
#    root/include/EORSample.hh \
#    root/include/EPhotoElectron.hh \
#    root/include/EPhoton.hh \
#    root/include/EPmtData.hh \
#    root/include/EPmtGeo.hh \
#    root/include/EPTTTrigger.hh \
#    root/include/EPTTTriggerSegment.hh \
#    root/include/EReader.hh \
#    root/include/ERunParameters.hh \
#    root/include/ERunParsFiller.hh \
#    root/include/EShower.hh \
#    root/include/EShowerStep.hh \
#    root/include/ESimpDetPhoton.hh \
#    root/include/ESimpleDetector.hh \
#    root/include/ESinglePhoton.hh \
#    root/include/ESystemOfUnits.hh \
#    root/include/ETriggPars.hh \
#    root/include/ETruth.hh \
#    root/include/Etypes.hh \
#    root/include/LinkDef.hh

#FORMS    += mainwindow.ui

FORMS += \
    select_event_dialog.ui
