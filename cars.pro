QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    Classes/Auto/auto.cpp \
    Classes/Karoseria/karoseria.cpp \
    Classes/Kola/kola.cpp \
    Classes/Naped/naped.cpp \
    Classes/Pracownik/Pracownik.cpp \
    Classes/Silnik/silnik.cpp \
    Funkcje_przemieszczjace.cpp \
    main.cpp \
    mainwindow.cpp

HEADERS += \
    Classes/Auto/auto.h \
    Classes/Karoseria/karoseria.h \
    Classes/Kola/kola.h \
    Classes/Naped/naped.h \
    Classes/Pracownik/pracownik.h \
    Classes/Silnik/silnik.h \
    Classes/auto.h \
    mainwindow.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    .gitignore \
    .idea/CarsFactor.iml \
    .idea/misc.xml \
    .idea/modules.xml \
    .idea/vcs.xml \
    .idea/workspace.xml

SUBDIRS += \
    Factory.pro \
    Factory.pro \
    Factory.pro \
    Factory.pro \
    Factory.pro \
    Factory.pro
