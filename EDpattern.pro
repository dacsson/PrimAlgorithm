QT       += \
    core gui \
    sql
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    demonstrationwindow.cpp \
    filemanager.cpp \
    main.cpp \
    mainwindow.cpp \
    testingwindow.cpp \
    theorywindow.cpp

HEADERS += \
    demonstrationwindow.h \
    filemanager.h \
    mainwindow.h \
    testingwindow.h \
    theorywindow.h

FORMS += \
    demonstrationwindow.ui \
    mainwindow.ui \
    testingwindow.ui \
    theorywindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    Theory.html \
    config.json \
    resources/index.html
