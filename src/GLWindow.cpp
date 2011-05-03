#include "GLWindow.h"
namespace QtGLWindow{
const static float PI  = 3.1415926;
//------------------------------------------------------------------------------
GLWindow::GLWindow(
                        QWidget *_parent
                  )
                   :QGLWidget( _parent )
{
    setFocus();
    resize(_parent->size());

    m_framerate = 1000;
    m_wireframe = false;
    m_timer = new QTimer(this);
    m_pCam = new Camera;
    m_spin = 0.0;
    //connect( m_timer, SIGNAL(timeout()), this, SLOT(updateGL()));
    //m_timer->start(m_framerate);
}
//------------------------------------------------------------------------------
GLWindow::~GLWindow()
{
    if( m_timer !=0 )
        delete m_timer;
}
//------------------------------------------------------------------------------
void GLWindow::initializeGL()
{
    glClearColor(0,0,0,1);

    m_scene.InitScene();
    pSelected = m_scene.m_root.m_pNext->m_pObject;

    m_obj.ParseFile("sphere.obj");
    m_obj.Load();
    m_obj.m_pMesh->CreateVBO();
    //setModel(0);
    m_pCam->SetupCam();
}
//------------------------------------------------------------------------------
void GLWindow::resizeGL(
                            const uint32_t _w,
                            const uint32_t _h
                        )
{
    glViewport(0,0,_w,_h);
}
//------------------------------------------------------------------------------
void GLWindow::paintGL()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    if( m_wireframe )
    {
        glPolygonMode(GL_FRONT_AND_BACK,GL_LINE);
    }
    else
    {
        glPolygonMode(GL_FRONT_AND_BACK,GL_FILL);
    }

   // m_scene.UpdateScene(m_pos,m_rot,m_axis);
    RenderScene(m_scene);
}
//------------------------------------------------------------------------------
void GLWindow::RenderScene(const SceneManager& _scene)
{
    const SceneNode* thisnode = &(_scene.m_root);

    while( thisnode->m_pNext !=NULL )
    {
        if( thisnode->m_pNext->m_pObject!= 0)
        {
            Draw(thisnode->m_pNext->m_pObject);
        }
        thisnode = thisnode->m_pNext;
    }
}
//------------------------------------------------------------------------------
void GLWindow::Draw(const SceneObject* _obj)
{
    glPushMatrix();
        glRotatef(m_spin, 0,1,0);
    glPushMatrix();
        glMultMatrixf( _obj->m_trans.m_transform.m_mat);
        //glMultMatrixf(m_trans.m_transform.m_mat);
        m_obj.m_pMesh->DrawVBO();
    glPopMatrix();
    glPopMatrix();
}
//------------------------------------------------------------------------------
void GLWindow::toggleWireframe(bool _mode)
{
    m_wireframe = _mode;
    updateGL();
}
//------------------------------------------------------------------------------
void GLWindow::setRotationX()
{
    pSelected->m_trans.SetRotation(1*PI/180, pSelected->m_axisX);
    pSelected->RotateAxis();
    pSelected->m_trans.ApplyTransform();
    updateGL();
}
//------------------------------------------------------------------------------
void GLWindow::setRotationY()
{
    pSelected->m_trans.SetRotation(1*PI/180, pSelected->m_axisY);
    pSelected->RotateAxis();
    pSelected->m_trans.ApplyTransform();
    updateGL();
}
//------------------------------------------------------------------------------
void GLWindow::setRotationZ()
{
    pSelected->m_trans.SetRotation(1*PI/180, pSelected->m_axisZ);
    pSelected->RotateAxis();
    pSelected->m_trans.ApplyTransform();
    updateGL();
}
//------------------------------------------------------------------------------
void GLWindow::setTranslationX()
{
    pSelected->m_trans.SetTranslate( pSelected->m_axisX * 0.1 );
    pSelected->m_trans.ApplyTransform();
    updateGL();
}
//------------------------------------------------------------------------------
void GLWindow::setTranslationY()
{
    pSelected->m_trans.SetTranslate( pSelected->m_axisY * 0.1 );
    pSelected->m_trans.ApplyTransform();
    updateGL();
}
//------------------------------------------------------------------------------
void GLWindow::setTranslationZ()
{
    pSelected->m_trans.SetTranslate( pSelected->m_axisZ * 0.1 );
    pSelected->m_trans.ApplyTransform();
    updateGL();
}
//------------------------------------------------------------------------------
void GLWindow::setZoom()
{
    m_pCam->Zoom();
    updateGL();
}
void GLWindow::setSpin()
{
    m_spin +=1;
    updateGL();
}
void GLWindow::setModel(int _index)
{
    switch(_index)
    {
        case 0:
            m_obj.ParseFile("sphere.obj");
        case 1:
            m_obj.ParseFile("arrow.obj");
        case 2:
            m_obj.ParseFile("fish.obj");
    }
    m_obj.Load();
    m_obj.m_pMesh->CreateVBO();
    updateGL();
}
}//end of namespace
