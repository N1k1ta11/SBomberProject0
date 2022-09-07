#include "CollisionDetector.h"
using namespace std;

void CollisionDetector::newCheckPlaneAndLvlGUI(Plane* pl, LevelGUI* lvl, bool &exit)
{
    if (pl->GetX() > lvl->GetFinishX())
    {
        exit = true;
    }
}

vector<Bomb*> CollisionDetector::newCheckBombsAndGround(vector<Bomb*>vecBomb, vector<DestroyableGroundObject*> Obj, Ground* g, double y)
{
    vector<Bomb*>vec;
    m_Obj = Obj;
    for (int i = 0; i < vecBomb.size(); i++)
    {
        if (vecBomb[i]->GetY() >= y)
        {
            g->AddCrater(vecBomb[i]->GetX());
            //CollisionDetector::newCheckDestoyableObjects(vecBomb[i]);
            vec.push_back(vecBomb[i]);
        }
    }
}

void CollisionDetector::newCheckDestoyableObjects(Bomb* b, SBomber* s)
{
    vector<DestroyableGroundObject*> vecDestoyableObjects = m_Obj;
    const double size = b->GetWidth();
    const double size_2 = size / 2;
    for (size_t i = 0; i < vecDestoyableObjects.size(); i++)
    {
        const double x1 = b->GetX() - size_2;
        const double x2 = x1 + size;
        if (vecDestoyableObjects[i]->isInside(x1, x2))
        {
            (*m_score) += vecDestoyableObjects[i]->GetScore();
            s->DeleteStaticObj(vecDestoyableObjects[i]);
        }
    }
}
