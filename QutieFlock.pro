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
    src/sceneNode.cpp \
    src/sceneObject.cpp \
    src/vector.cpp \
    src/util.cpp \
    src/sceneManager.cpp \

HEADERS += \
    include/mainwindow.h \
    include/GLWindow.h \
    include/sceneNode.h \
    include/sceneObject.h \
    include/vector.h \
    include/util.h \
    include/sceneManager.h \

FORMS += \
    ui/mainwindow.ui
