QT += testlib
QT -= gui

CONFIG += qt console warn_on depend_includepath testcase
CONFIG -= app_bundle

TEMPLATE = app

SOURCES +=  tst_monopolfunctionalities.cpp \
    ../../RS019-monopol/src/ActionSpace.cpp \
    ../../RS019-monopol/src/Bank.cpp \
    ../../RS019-monopol/src/Board.cpp \
    ../../RS019-monopol/src/Card.cpp \
    ../../RS019-monopol/src/Game.cpp \
    ../../RS019-monopol/src/Player.cpp \
    ../../RS019-monopol/src/Property.cpp \
    ../../RS019-monopol/src/Railroad.cpp \
    ../../RS019-monopol/src/Space.cpp \
    ../../RS019-monopol/src/Utility.cpp \
    utilityFunctionsTesting.cpp

HEADERS += \
    ../../RS019-monopol/src/ActionSpace.hpp \
    ../../RS019-monopol/src/Bank.hpp \
    ../../RS019-monopol/src/Board.hpp \
    ../../RS019-monopol/src/Card.hpp \
    ../../RS019-monopol/src/Game.hpp \
    ../../RS019-monopol/src/Player.hpp \
    ../../RS019-monopol/src/Property.hpp \
    ../../RS019-monopol/src/Railroad.hpp \
    ../../RS019-monopol/src/Space.hpp \
    ../../RS019-monopol/src/Utility.hpp \
    utilityFunctionsForTesting.h
