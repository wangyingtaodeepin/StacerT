#-------------------------------------------------
#
# Project created by QtCreator 2017-09-22T14:12:30
#
#-------------------------------------------------

QT       -= gui

TARGET = stacer-core
TEMPLATE = lib

DEFINES += STACERCORE_LIBRARY

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    Utils/command_util.cpp \
    Utils/file_util.cpp \
    Utils/format_util.cpp \
    Info/cpu_info.cpp \
    Info/disk_info.cpp \
    Info/memory_info.cpp \
    Info/network_info.cpp \
    Info/process.cpp \
    Info/process_info.cpp

HEADERS += \
        stacer-core_global.h \ 
    Utils/command_util.h \
    Utils/file_util.h \
    Utils/format_util.h \
    Info/cpu_info.h \
    Info/disk_info.h \
    Info/memory_info.h \
    Info/network_info.h \
    Info/process.h \
    Info/process_info.h

unix {
    target.path = /usr/lib
    INSTALLS += target
}
