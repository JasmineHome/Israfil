TEMPLATE = subdirs
SUBDIRS += IsrafilCore doc tests IsrafilApp
CONFIG += C++11

OTHER_FILES += README.md \
    LICENSE.md \
    .appveyor.yml \
    .travis.yml \
    uncrustify.cfg
