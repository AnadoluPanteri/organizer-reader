
TEMPLATE = app
DEPENDPATH += .
INCLUDEPATH += .

CONFIG += mobility
MOBILITY += organizer

SOURCES += reader.cpp

target.path = /opt/organizer-reader/bin
INSTALLS += target

