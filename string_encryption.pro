QT       += core gui
QT       += network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    base.cpp \
    composite_encoder.cpp \
    encoder.cpp \
    flip.cpp \
    invert.cpp \
    main.cpp \
    mainwindow.cpp \
    network_helper.cpp \
    otp.cpp \
    pad_key.cpp

HEADERS += \
    base.h \
    composite_encoder.h \
    encoder.h \
    flip.h \
    invert.h \
    mainwindow.h \
    network_helper.h \
    otp.h \
    pad_key.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
