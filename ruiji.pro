QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    delete.cpp \
    deletedialog.cpp \
    detail.cpp \
    homepage.cpp \
    homepagelistitem.cpp \
    listitem.cpp \
    main.cpp \
    mainwindow.cpp \
    mycontent.cpp \
    picturebox.cpp \
    qclickwidget.cpp \
    recyclebin.cpp \
    setfontutil.cpp \
    uploadconfirm.cpp \
    uploadmenu.cpp \
    uploadwidget.cpp \
    widget_bin.cpp \
    widget_my.cpp \
    widget_mycontent.cpp

HEADERS += \
    delete.h \
    deletedialog.h \
    detail.h \
    homepage.h \
    homepagelistitem.h \
    listitem.h \
    loadfileqss.h \
    mainwindow.h \
    mycontent.h \
    picturebox.h \
    qclickwidget.h \
    recyclebin.h \
    setfontutil.h \
    uploadconfirm.h \
    uploadmenu.h \
    uploadwidget.h \
    widget_bin.h \
    widget_my.h \
    widget_mycontent.h

FORMS += \
    delete.ui \
    deletedialog.ui \
    detail.ui \
    homepage.ui \
    homepagelistitem.ui \
    listitem.ui \
    mainwindow.ui \
    mycontent.ui \
    recyclebin.ui \
    uploadconfirm.ui \
    uploadmenu.ui \
    uploadwidget.ui \
    widget_bin.ui \
    widget_my.ui \
    widget_mycontent.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    Res.qrc

