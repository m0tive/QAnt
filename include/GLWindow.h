#ifndef _GLWINDOW_H_
#define _GLWINDOW_H_

#include <gl/glew.h>
#include <QtOpenGL>
#include <QTimer>
#include <stdint.h>

#include "sceneManager.h"
#include "transform.h"
#if 0
#include "objLoader.h"
#include "camera.h"
#endif

namespace QtGLWindow
{

class GLWindow : public QGLWidget
{
    Q_OBJECT
    public:
        explicit GLWindow(QWidget *_parent);
        ~GLWindow();

    public slots:
        void toggleWireframe(bool _mode);
        void setRotationX();
        void setRotationY();
        void setRotationZ();
        void setTranslationX();
        void setTranslationY();
        void setTranslationZ();
#if 0
        void setZoom();
        void setSpin();
        void setCamPitch();
        void setCamYaw();
        void setCamRoll();
        void setModel(int _index);
#endif
    protected:
        void initializeGL();
        void resizeGL( const uint32_t _w, const uint32_t _h );
        void paintGL();
    private:
        void RenderScene(const SceneManager& _scene);
        void Draw(SceneObject* _obj);
        SceneManager m_scene;
#if 0
        ObjLoader m_obj;
        ObjLoader m_envObj;
        Camera* m_pCam;
#endif
        uint32_t m_framerate;
        QTimer m_timer;
        bool m_wireframe;
        Transform m_trans;
        SceneObject* pSelected;
        float m_spin;
};//end of class
}//end of namespace
#endif //end of define
