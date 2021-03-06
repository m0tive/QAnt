#include "GLWindow.h"

#include "sceneObject.h"

namespace QtGLWindow{

#ifndef M_PI
#   define M_PI 3.1415926;
#endif

//------------------------------------------------------------------------------
GLWindow::GLWindow( QWidget *_parent )
    : QGLWidget( _parent ),
      m_framerate(50),
      m_timer(this),
      m_wireframe(false),
      pSelected(0),
      m_spin(0.0)
{
    setFocus();
    resize(_parent->size());

    connect( &m_timer, SIGNAL(timeout()), this, SLOT(updateGL()));
    m_timer.start(m_framerate);
}
//------------------------------------------------------------------------------
GLWindow::~GLWindow()
{
}

//------------------------------------------------------------------------------
void GLWindow::initializeGL()
{
    glewInit();

    glClearColor(0,0,0,1);

    glEnable(GL_DEPTH_TEST);
    m_scene.InitScene();

    if (m_scene.m_root.m_pNext)
    {
        pSelected = m_scene.m_root.m_pNext->m_pObject;
    }
    m_obj.ParseFile("sphere.obj");
    m_obj.Load();
    m_obj.m_pMesh->CreateVBO();

    m_envObj.ParseFile("plane.obj");
    m_envObj.Load();
    m_envObj.m_pMesh->CreateVBO();
    //setModel(0);
    m_pCam.SetupCam();
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
    glPolygonMode(GL_FRONT_AND_BACK, m_wireframe ? GL_LINE : GL_FILL);

    m_scene.UpdateScene();
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
void GLWindow::Draw(SceneObject* _obj)
{
    glPushMatrix();
        glRotatef(m_spin, 0,1,0);
        if(_obj->GetType() == kObject)
        {
            glPushMatrix();
                glPushAttrib(GL_ENABLE_BIT | GL_POLYGON_BIT | GL_CURRENT_BIT);
                glColor3f(1,1,1);
                glScalef(60,1,60);
                glTranslatef(_obj->m_pos.GetX(),_obj->m_pos.GetY(),_obj->m_pos.GetZ());
                m_envObj.m_pMesh->DrawVBO();
                glPopAttrib();
            glPopMatrix();
        }
        else if ( _obj->GetType() == kAnt)
        {
            glPushMatrix();
                glPushAttrib(GL_ENABLE_BIT | GL_POLYGON_BIT | GL_CURRENT_BIT);
                glColor3f(1,0,0);
                glMultMatrixf( _obj->m_trans.m_transform.m_mat);
                m_obj.m_pMesh->DrawVBO();
                glPopAttrib();
            glPopMatrix();
        }
        else if( _obj->GetType() == kPhe)
        {
            glPushMatrix();
                glPushAttrib(GL_ENABLE_BIT | GL_POLYGON_BIT | GL_CURRENT_BIT);
#if 0
                if ( (static_cast<Pheromone*>(_obj))->m_phrmType == ToHome)
                {
                    glColor3f(0,0,1);
                }
                else
#endif
                {
                    glColor3f(0,1,0);
                }
                glTranslatef(_obj->m_pos.GetX(),_obj->m_pos.GetY(),_obj->m_pos.GetZ());
                glScalef(0.1,0.1,0.1);
                m_obj.m_pMesh->DrawVBO();
                glPopAttrib();
            glPopMatrix();
        }
        else if( _obj->GetType() == kHome)
        {
            glPushMatrix();
                glPushAttrib(GL_ENABLE_BIT | GL_POLYGON_BIT | GL_CURRENT_BIT);
                glColor3f(1,0,0);
                glTranslatef(_obj->m_pos.GetX(),_obj->m_pos.GetY(),_obj->m_pos.GetZ());
                m_obj.m_pMesh->DrawVBO();
                glPopAttrib();
            glPopMatrix();
        }
        else if( _obj->GetType() == kFood)
        {
            glPushMatrix();
                glPushAttrib(GL_ENABLE_BIT | GL_POLYGON_BIT | GL_CURRENT_BIT);
                glColor3f(0,1,0);
                glTranslatef(_obj->m_pos.GetX(),_obj->m_pos.GetY(),_obj->m_pos.GetZ());
                m_obj.m_pMesh->DrawVBO();
                glPopAttrib();
            glPopMatrix();
        }


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
    if (pSelected)
    {
        pSelected->Rotate(1.0f*M_PI/180.0f,'X');
        updateGL();
    }
}
//------------------------------------------------------------------------------
void GLWindow::setRotationY()
{
    if (pSelected)
    {
        pSelected->Rotate(1.0f*M_PI/180.0f,'Y');
        updateGL();
    }
}
//------------------------------------------------------------------------------
void GLWindow::setRotationZ()
{
    if (pSelected)
    {
        pSelected->Rotate(1.0f*M_PI/180.0f,'Z');
        updateGL();
    }
}
//------------------------------------------------------------------------------
void GLWindow::setTranslationX()
{
    if (pSelected)
    {
        pSelected->Translate('X');
        updateGL();
    }
}
//------------------------------------------------------------------------------
void GLWindow::setTranslationY()
{
    if (pSelected)
    {
        pSelected->Translate('Y');
        updateGL();
    }
}
//------------------------------------------------------------------------------
void GLWindow::setTranslationZ()
{
    if (pSelected)
    {
        pSelected->Translate('Z');
        updateGL();
    }
}
//------------------------------------------------------------------------------
void GLWindow::setCamPitch()
{
    this->m_pCam.Pitch();
    updateGL();
}
void GLWindow::setCamYaw()
{
    this->m_pCam.Yaw();
    updateGL();
}
//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
void GLWindow::setCamRoll()
{
    this->m_pCam.Roll();
    updateGL();
}
//------------------------------------------------------------------------------
void GLWindow::setZoom()
{
    m_pCam.Zoom();
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
            break;
        case 1:
            m_obj.ParseFile("arrow.obj");
            break;
        case 2:
            m_obj.ParseFile("fish.obj");
            break;
    }
    m_obj.Load();
    m_obj.m_pMesh->UpdateVBO();
    updateGL();
}

}//end of namespace
