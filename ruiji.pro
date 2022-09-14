QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    delete.cpp \
    main.cpp \
    mainwindow.cpp \
    picturebox.cpp \
    uploadconfirm.cpp \
    uploadmenu.cpp \
    uploadwidget.cpp

HEADERS += \
    delete.h \
    loadfileqss.h \
    mainwindow.h \
    picturebox.h \
    uploadconfirm.h \
    uploadmenu.h \
    uploadwidget.h

FORMS += \
    delete.ui \
    mainwindow.ui \
    uploadconfirm.ui \
    uploadmenu.ui \
    uploadwidget.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    Res.qrc

