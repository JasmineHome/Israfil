TEMPLATE = app
TARGET = test-core

CONFIG += C++11 warn_off
CONFIG -= Qt
DESTDIR = $$BUILD_TREE/bin

#DISTFILES += run.sh
copyToDestdir($$SOURCE_TREE/tests/IsrafilCore/test-core/run.sh)
SOURCES += \
    main.cpp
INCLUDEPATH += \
    $$SOURCE_TREE/IsrafilCore/IsrafilBase/include \
    $$SOURCE_TREE/IsrafilCore/IsrafilNetwork/include \
    $$SOURCE_TREE/IsrafilCore/IsrafilCore/include \
    $$SOURCE_TREE/IsrafilCore/IsrafilMusic/icQQMusic \
    $$SOURCE_TREE/IsrafilCore/IsrafilMusic/icNetease \
    $$SOURCE_TREE/IsrafilCore/IsrafilPrefix \
    $$SOURCE_TREE/IsrafilCore/ext/rapidjson/include \
    $$SOURCE_TREE/IsrafilCore/ext/curlcpp/include

LIBS += -L$$BUILD_TREE/bin -lIsrafilBase -lcurl -lcurlcpp -lIsrafilNetwork -licQQMusic -licNetease -lIsrafilCore
