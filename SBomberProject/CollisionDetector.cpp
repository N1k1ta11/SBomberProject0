#include "CollisionDetector.h"
using namespace std;

void CollisionDetector::CheckPlaneAndLvlGUI(Plane* pl, LevelGUI* lvl, bool &exit)
{
    if (pl->GetX() > lvl->GetFinishX())
    {
        exit = true;
    }
}

vector<Bomb*> CollisionDetector::CheckBombsAndGround(vector<Bomb*>vecBomb,Ground* g, double y)
{
    vector<Bomb*>vec;
    for (int i = 0; i < vecBomb.size(); i++)
    {
        if (vecBomb[i]->GetY() >= y)
        {
            g->AddCrater(vecBomb[i]->GetX());
            vec.push_back(vecBomb[i]);
        }
    }
    return vec;
}

vector<DestroyableGroundObject*> CollisionDetector::CheckDestoyableObjects(vector<DestroyableGroundObject*> destObj,Bomb* b, double size, double size_2, int16_t& score)
{
    vector<DestroyableGroundObject*>destObjDel;
    for (size_t i = 0; i < destObj.size(); i++)
    {
        const double x1 = b->GetX() - size_2;
        const double x2 = x1 + size;
        if (destObj[i]->isInside(x1, x2))
        {
            score += destObj[i]->GetScore();
            destObjDel.push_back(destObj[i]);
        }
    }
    return destObjDel;
}
