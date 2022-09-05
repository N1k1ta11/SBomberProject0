#include "CollisionDetector.h"
#include <vector>
#include "SBomber.h"
using namespace std;
void CollisionDetector::CheckPlaneAndLvl(Plane* fPlane, LevelGUI* fGUI, bool& exit)
{
    if (fPlane->GetX() > fGUI->GetFinishX())
    {
        exit = true;
    }
}

void CollisionDetector::CheckBombsAndGround(vector<Bomb*>vecBombs, Ground* pGround, void (SBomber::*DelObj)(DynamicObject*), vector<DestroyableGroundObject*>(SBomber::*FindDestoyableGroundObjects)())
{
    const double y = pGround->GetY();
    for (size_t i = 0; i < vecBombs.size(); i++)
    {
        if (vecBombs[i]->GetY() >= y) // Пересечение бомбы с землей
        {
            pGround->AddCrater(vecBombs[i]->GetX());
            CheckDestoyableObjects(vecBombs[i], FindDestoyableGroundObjects);
            DelObj(vecBombs[i]);
        }
    }
}

void CollisionDetector::CheckDestoyableObjects(Bomb* pBomb, vector<DestroyableGroundObject*> (SBomber::*FindDestoyableGroundObjects)())
{
    vector<DestroyableGroundObject*> vecDestoyableObjects = FindDestoyableGroundObjects;
    const double size = pBomb->GetWidth();
    const double size_2 = size / 2;
    for (size_t i = 0; i < vecDestoyableObjects.size(); i++)
    {
        const double size = pBomb->GetWidth();
        const double x1 = pBomb->GetX() - size_2;
        const double x2 = x1 + size;
        if (vecDestoyableObjects[i]->isInside(x1, x2))
        {
            score += vecDestoyableObjects[i]->GetScore();
            DeleteStaticObj(vecDestoyableObjects[i]);
        }
    }
}
