QT       += core gui sql
QT       += core network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    databaserequesthandler.cpp \
    main.cpp \
    mainwindow.cpp \
    request.cpp \
    serverModel.cpp \
    serverthread.cpp \
    sqlrequestcreator.cpp \
    sqlrequestfactory.cpp

HEADERS += \
    databaserequesthandler.h \
    mainwindow.h \
    request.h \
    serverModel.h \
    serverthread.h \
    sqlrequestcreator \
    sqlrequestfactory.h

FORMS += \
    mainwindow.ui

include ($$PWD/Qt-Secret/src/Qt-Secret.pri)

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
