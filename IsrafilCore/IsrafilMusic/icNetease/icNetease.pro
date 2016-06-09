TEMPLATE = lib
TARGET = icNetease

CONFIG += C++11 warn_off
CONFIG -= Qt
DESTDIR = $$BUILD_TREE/bin

INCLUDEPATH += \
    $$SOURCE_TREE/IsrafilCore/IsrafilPrefix \
    $$SOURCE_TREE/IsrafilCore/IsrafilNetwork/include \
    $$SOURCE_TREE/IsrafilCore/IsrafilBase/include \
    $$SOURCE_TREE/IsrafilCore/ext/curlcpp/include \
    $$SOURCE_TREE/IsrafilCore/ext/rapidjson/include

LIBS += -L$$BUILD_TREE/bin -lcurl -lcurlcpp -lIsrafilNetwork -lIsrafilBase

HEADERS += \
    base.h \
    netease.h

SOURCES += \
    netease.cpp

DISTFILES += cipher_boltzmann.py
