QT += \
    opengl \
    gui \
    core

LIBS += \
    -L"$$_PRO_FILE_PWD_/lib" \
    -lglew32

OBJECTS_DIR = obj

INCLUDEPATH += \
    include \
    ui

UI_HEADERS_DIR = ui

SOURCES += \
    src/main.cpp \
    src/mainwindow.cpp \
    src/GLWindow.cpp \

HEADERS += \
    include/mainwindow.h \
    ui/ui_mainwindow.h \
    include/GLWindow.h \

FORMS += \
    ui/mainwindow.ui
