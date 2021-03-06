#ifndef _SCENEMANAGER_H_
#define _SCENEMANGER_H_

#include "sceneNode.h"
//#include "flock.h"
//#include "colony.h"

namespace QtGLWindow
{
class SceneObject;

class SceneManager
{
    public:
        SceneManager();
        ~SceneManager();

        void InitScene();
        void UpdateScene();
        SceneNode m_root;

    protected:
        SceneObject* test;
        //Flock* m_pFlock;
        //Colony* m_pColony;
        SceneObject* m_pEnv;
        SceneObject* m_pFood;
        SceneObject* m_pHome;
        //Pheromone* ptest;
};//end of class
}//end of namespace
#endif //end of define
