TEMPLATE = subdirs
SUBDIRS += \
    ext/curlcpp \
    IsrafilBase \
    IsrafilNetwork \
    IsrafilMusic \
    IsrafilCore \

IsrafilNetwork.depends = curlcpp
IsrafilNetwork.depends = IsrafilBase

IsrafilCore.depends = icQQMusic
IsrafilCore.depends = IsrafilBase
IsrafilCore.depends = IsrafilNetwork

IsrafilMusic.depends = IsrafilCore
IsrafilMusic.depends = IsrafilNetwork
IsrafilMusic.depends = IsrafilBase

