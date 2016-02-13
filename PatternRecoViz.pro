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

ROOTGLIBS = $$system(${ROOTSYS}/bin/root-config --glibs --ldflags) -lGeom
#QMAKE_LFLAGS += $${ROOTGLIBS}
LIBS += $${ROOTGLIBS}

ROOTCFLAGS = $$system(${ROOTSYS}/bin/root-config --cflags)
QMAKE_CFLAGS += -fPIC -Wall $${ROOTCFLAGS}

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

RELATIVE_ROOT_INCLUDES = ""

ROOT_INCLUDES += \
    root/include/Etypes.hh \
    root/include/ESystemOfUnits.hh \
    root/include/ERunParsFiller.hh \
    root/include/EAnglePixelMap.hh \
    root/include/EFiller.hh \
    root/include/EFillable.hh \
    root/include/EAFee.hh \
    root/include/EPmtData.hh \
    root/include/EPhoton.hh \
    root/include/EFee.hh \
    root/include/ESinglePhoton.hh \
    root/include/EBunchPhotons.hh \
    root/include/EAtmosphere.hh \
    root/include/ECCB_LTTTrigger.hh \
    root/include/ECCB_LTTTriggerSegment.hh \
    root/include/EChipTrackSegment.hh \
    root/include/EChipTrackTrigger.hh \
    root/include/ETriggPars.hh \
    root/include/EGeometry.hh \
    root/include/EHeader.hh \
    root/include/EDetPhoton.hh \
    root/include/EDetStatus.hh \
    root/include/EElectronics.hh \
    root/include/EMacroCell.hh \
    root/include/EMacroCellHit.hh \
    root/include/EORHeader.hh \
    root/include/EORSample.hh \
    root/include/EOpticsResponse.hh \
    root/include/EPhotoElectron.hh \
    root/include/EPmtGeo.hh \
    root/include/EShower.hh \
    root/include/EShowerStep.hh \
    root/include/ESimpDetPhoton.hh \
    root/include/ERunParameters.hh \
    root/include/ESimpleDetector.hh \
    root/include/EDetector.hh \
    root/include/EChipTriggPars.hh \
    root/include/ETruth.hh \
    root/include/EEvent.hh \
    root/include/ELblTrackSegment.hh \
    root/include/ELblTrackTrigger.hh \
    root/include/ELTTTrigger.hh \
    root/include/ELTTTriggerSegment.hh \
    root/include/EPTTTrigger.hh \
    root/include/EPTTTriggerSegment.hh \
    root/include/EReader.hh \
    root/include/LinkDef.hh

ROOT_SOURCES = \
    root/src/ERunParsFiller.cc \
    root/src/EAnglePixelMap.cc \
    root/src/EFiller.cc \
    root/src/EFillable.cc \
    root/src/EAFee.cc \
    root/src/EPmtData.cc \
    root/src/EFee.cc \
    root/src/EPhoton.cc \
    root/src/ESinglePhoton.cc \
    root/src/EBunchPhotons.cc \
    root/src/EAtmosphere.cc \
    root/src/ECCB_LTTTrigger.cc \
    root/src/ECCB_LTTTriggerSegment.cc \
    root/src/EChipTrackSegment.cc \
    root/src/EChipTrackTrigger.cc \
    root/src/ETriggPars.cc \
    root/src/EGeometry.cc \
    root/src/EHeader.cc \
    root/src/EDetPhoton.cc \
    root/src/EDetStatus.cc \
    root/src/EElectronics.cc \
    root/src/EMacroCell.cc \
    root/src/EMacroCellHit.cc \
    root/src/EORHeader.cc \
    root/src/EORSample.cc \
    root/src/EOpticsResponse.cc \
    root/src/EPhotoElectron.cc \
    root/src/EPmtGeo.cc \
    root/src/EShower.cc \
    root/src/EShowerStep.cc \
    root/src/ESimpDetPhoton.cc \
    root/src/ERunParameters.cc \
    root/src/ESimpleDetector.cc \
    root/src/EDetector.cc \
    root/src/EChipTriggPars.cc \
    root/src/ETruth.cc \
    root/src/EEvent.cc \
    root/src/ELblTrackSegment.cc \
    root/src/ELblTrackTrigger.cc \
    root/src/ELTTTrigger.cc \
    root/src/ELTTTriggerSegment.cc \
    root/src/EPTTTrigger.cc \
    root/src/EPTTTriggerSegment.cc \
    root/src/EReader.cc

#$${OUT_PWD}/


for(root_include_file_path, $$list($$ROOT_INCLUDES)) {
    RELATIVE_ROOT_INCLUDES += $$absolute_path($$root_include_file_path,$${PWD})
}

message($$RELATIVE_ROOT_INCLUDES)



ROOT_DICT_CPP_FILE = G___RootDict.cpp
ABI_FIX=$${LITERAL_HASH}define _GLIBCXX_USE_CXX11_ABI 0

CINT_FLAGS = -Doff64_t=int64_t

rootcint.target = $${ROOT_DICT_CPP_FILE}
rootcint.commands = rootcint -v4 -f $${rootcint.target} $${CINT_FLAGS} -I$${PWD} $${RELATIVE_ROOT_INCLUDES} && echo \"$${ABI_FIX}\" > $${rootcint.target}.tmp && cat $${rootcint.target} >> $${rootcint.target}.tmp && rm $${rootcint.target} && mv $${rootcint.target}.tmp $${rootcint.target}

#&& (exec 3<> $${ROOT_DICT_CPP_FILE} && awk -v TEXT=\"$${ABI_FIX}\" \'BEGIN {print TEXT}{print}\' $${ROOT_DICT_CPP_FILE} >&3)
rootcint.depends = $${RELATIVE_ROOT_INCLUDES}

QMAKE_EXTRA_TARGETS += rootcint

PRE_TARGETDEPS += $${rootcint.target}


#rootcint_abi_fix.target = $${ROOT_DICT_CPP_FILE}_abi_fix # TODO
#rootcint_abi_fix.commands = exec 3<> $${ROOT_DICT_CPP_FILE} && awk -v TEXT="$${ABI_FIX}" 'BEGIN {print TEXT}{print}' $${ROOT_DICT_CPP_FILE} >&3
#rootcint_abi_fix.depends = $${rootcint.target}

#QMAKE_EXTRA_TARGETS += rootcint_abi_fix



message("----------------")
message(${PWD})
message($${PWD})
message($(PWD))
message(${OUT_PWD})
message($${OUT_PWD})
message($(OUT_PWD))
message($${rootcint.commands})
message($${rootcint.target})
message($${QMAKE_TARGET})
#message($$absolute_path($${ROOT_INCLUDES}))
message("----------------")


HEADERS  += \
    main_window.h \
    select_event_dialog.h \
    ui/main_window_handwritten.h \
    run_reco_window.h \
    pattern_reco_algorithm.h \
    $${ROOT_INCLUDES}

SOURCES += main.cpp\
    select_event_dialog.cpp \
    main_window.cpp \
    ui/main_window_handwritten.cpp \
    run_reco_window.cpp \
    pattern_reco_algorithm.cpp \
    $${ROOT_DICT_CPP_FILE} \
    $${ROOT_SOURCES}


#FORMS    += mainwindow.ui

FORMS += \
    select_event_dialog.ui \
    reco_output_window.ui \
    run_reco_window.ui \
    test.ui
