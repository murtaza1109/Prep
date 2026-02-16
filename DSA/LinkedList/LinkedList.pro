TEMPLATE = app
CONFIG += console c++17
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        list_test.cpp \
        List.cpp

HEADERS += \
        List.h

# Google Test configuration
INCLUDEPATH += /opt/homebrew/include
LIBS += -L/opt/homebrew/lib -lgtest -lgtest_main -pthread
