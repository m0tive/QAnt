QT += \
    opengl \
    gui \
    core

LIBS += \
    -L"$$_PRO_FILE_PWD_/lib" \
    -lglew32

INCLUDEPATH += \
    include \
    ui

OBJECTS_DIR = obj

UI_HEADERS_DIR = ui

SOURCES += \
    src/main.cpp \
    src/mainwindow.cpp \
    src/GLWindow.cpp \
    src/sceneNode.cpp \
    src/sceneObject.cpp \
    src/vector.cpp \
    src/util.cpp \
    src/transform.cpp \
    src/matrix.cpp \
    src/sceneManager.cpp \
    src/objLoader.cpp \

HEADERS += \
    include/mainwindow.h \
    include/GLWindow.h \
    include/sceneNode.h \
    include/sceneObject.h \
    include/vector.h \
    include/util.h \
    include/transform.h \
    include/matrix.h \
    include/sceneManager.h \
    include/objLoader.h \

FORMS += \
    ui/mainwindow.ui
