QT       += core gui
QT       += network
QT       += sql
QT       += webenginewidgets
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    chatbubble.cpp \
    chatclient.cpp \
    chatroom.cpp \
    chatserver.cpp \
    database.cpp \
    main.cpp \
    mainwindow.cpp \
    register.cpp \
    utils.cpp

HEADERS += \
    ../include/chatbubble.h \
    ../include/chatclient.h \
    ../include/chatroom.h \
    ../include/chatserver.h \
    ../include/database.h \
    ../include/mainwindow.h \
    ../include/register.h \
    ../include/utils.h \

FORMS += \
    chatbubble.ui \
    chatclient.ui \
    chatroom.ui \
    chatserver.ui \
    mainwindow.ui \
    register.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    resources.qrc
