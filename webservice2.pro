#-------------------------------------------------
#
# Project created by QtCreator 2018-07-20T23:58:19
#
#-------------------------------------------------

QT       += core gui widgets network charts

#LIBS += -LC:/OpenSSL-Win32/lib/MinGW -llibeay32
#LIBS += -LC:/OpenSSL-Win32/lib/MinGW -lssleay32
#INCLUDEPATH += C:/OpenSSL-Win32/include

#LIBS += -LC:/OpenSSL-Win32/lib -lubsec
#INCLUDEPATH += C:/OpenSSL-Win32/include

#LIBS += -LC:/OpenSSL-Win32/lib -lubsec -lws2_32 -llibeay32 -lgdi32

TARGET = webservice2
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

CONFIG += c++11

SOURCES += \
        main.cpp \
        mainwindow.cpp

HEADERS += \
        mainwindow.h

FORMS += \
        mainwindow.ui


# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

STATECHARTS += \
    Chart.scxml
