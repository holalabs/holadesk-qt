#-------------------------------------------------
#
# Project created by QtCreator 2012-04-19T21:24:57
#
#-------------------------------------------------

QT       += core gui webkit script network

TARGET = holadesk
TEMPLATE = app

SOURCES += main.cpp\
        holadesk.cpp \
        WebView.cpp \
        cookiejar.cpp \
        autosaver.cpp \
        WebPage.cpp \
        Native.cpp

HEADERS  += holadesk.h \
        WebView.h \
        cookiejar.h \
        autosaver.h \
        WebPage.h \
        Native.h

FORMS    += holadesk.ui

unix:!mac:!embedded {
    CONFIG += link_pkgconfig
    PKGCONFIG += libnotify
    TARGET = holadesk
    target.path = /usr/share/holadesk/bin
    data.path = /usr/share/holadesk
    data.files = ../desk ../web
    desktop.path = /usr/share/applications
    desktop.files = holadesk.desktop
    icon.path = /usr/share/pixmaps
    icon.files = holadesk.png
    INSTALLS += target data desktop icon
}

win32 {
    CONFIG += static
}

macx {
}

CCFLAG += -fpermissive

Debug:DEFINES+=DEBUG

RESOURCES += \
    resources.qrc
