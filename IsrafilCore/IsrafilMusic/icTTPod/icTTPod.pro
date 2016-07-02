TEMPLATE = lib
TARGET = icTTPod

CONFIG += C++11 warn_off
CONFIG -= Qt
DESTDIR = $$BUILD_TREE/bin

HEADERS += \
    ttpod.h \
    base.h

SOURCES += \
    ttpod.cpp

INCLUDEPATH += \
    $$SOURCE_TREE/IsrafilCore/IsrafilPrefix \
    $$SOURCE_TREE/IsrafilCore/IsrafilNetwork/include \
    $$SOURCE_TREE/IsrafilCore/IsrafilBase/include \
    $$SOURCE_TREE/IsrafilCore/ext/curlcpp/include \
    $$SOURCE_TREE/IsrafilCore/ext/rapidjson/include

LIBS += -L$$BUILD_TREE/bin -lcurl -lcurlcpp -lIsrafilNetwork -lIsrafilBase
