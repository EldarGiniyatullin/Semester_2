TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

QMAKE_CXXFLAGS += -std=c++0x

SOURCES += \
    Hometask_2.cpp \
    linkedstack.cpp \
    stackcalculator.cpp

HEADERS += \
    stack.h \
    linkedstack.h \
    stackcalculator.h


OTHER_FILES += \
    temp.txt

