QT += opengl \
       gui \
       core
QMAKE_CXX_FLAGS_WARN_ON += -Wextra
INCLUDEPATH += include/
        += ui
OBJECTS_DIR = obj/
MOC_DIR = moc/
UI_HEADERS_DIR = ui/
TARGET = bin/test
CONFIG += console
CONFIG -= app_bundle
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
    src/mesh.cpp \
    src/objLoader.cpp \
    src/camera.cpp \
    src/flock.cpp \
    src/boid.cpp \
    src/ant.cpp \
    src/pheromone.cpp \
    src/trail.cpp \
    src/colony.cpp

HEADERS += \
    include/mainwindow.h \
    ui/ui_mainwindow.h \
    include/GLWindow.h \
    include/sceneNode.h \
    include/sceneObject.h \
    include/vector.h \
    include/util.h \
    include/transform.h \
    include/matrix.h \
    include/sceneManager.h \
    include/mesh.h \
    include/objLoader.h \
    include/camera.h \
    include/flock.h \
    include/boid.h \
    include/ant.h \
    include/pheromone.h \
    include/trail.h \
    include/colony.h

FORMS += \
    ui/mainwindow.ui