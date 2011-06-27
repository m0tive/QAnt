#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent),
      m_gl(this)
{
    m_ui.setupUi(this);

    m_ui.s_mainLayout->addWidget(&m_gl,0,0,3,1);

    connect( m_ui.m_wireframeCheck,SIGNAL(toggled(bool)), &m_gl,SLOT(toggleWireframe(bool)) );
    connect( m_ui.m_rotX,SIGNAL(pressed()),&m_gl, SLOT(setRotationX()) );
    connect( m_ui.m_rotY,SIGNAL(pressed()),&m_gl, SLOT(setRotationY()) );
    connect( m_ui.m_rotZ,SIGNAL(pressed()),&m_gl, SLOT(setRotationZ()) );
    connect( m_ui.m_transX,SIGNAL(pressed()),&m_gl,SLOT(setTranslationX()) );
    connect( m_ui.m_transY,SIGNAL(pressed()),&m_gl,SLOT(setTranslationY()) );
    connect( m_ui.m_transZ,SIGNAL(pressed()),&m_gl,SLOT(setTranslationZ()) );
#if 0
    connect( m_ui.m_zoom,SIGNAL(pressed()),&m_gl, SLOT(setZoom()) );
    connect( m_ui.m_spin,SIGNAL(pressed()),&m_gl, SLOT(setSpin()) );
    connect( m_ui.m_model,SIGNAL(currentIndexChanged(int)),&m_gl,SLOT(setModel(int)));
    connect( m_ui.m_pitch,SIGNAL(pressed()),&m_gl,SLOT(setCamPitch()));
    connect( m_ui.m_yaw,SIGNAL(pressed()),&m_gl,SLOT(setCamYaw()));
    connect( m_ui.m_roll,SIGNAL(pressed()),&m_gl,SLOT(setCamRoll()));
#endif
}

MainWindow::~MainWindow()
{
}
