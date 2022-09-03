#include "CollisionDetector.h"
#include <vector>
using namespace std;
void CollisionDetector::CheckPlaneAndLvl(Plane* fPlane, LevelGUI* fGUI, bool& exit)
{
    if (fPlane->GetX() > fGUI->GetFinishX())
    {
        exit = true;
    }
}

void CollisionDetector::CheckBombsAndGround(vector<Bomb*>vecBombs, Ground* pGround, void (SBomber::*DelObj)(DynamicObject* pObj))
{
    const double y = pGround->GetY();
    for (size_t i = 0; i < vecBombs.size(); i++)
    {
        if (vecBombs[i]->GetY() >= y) // Пересечение бомбы с землей
        {
            pGround->AddCrater(vecBombs[i]->GetX());
            CheckDestoyableObjects(vecBombs[i]);
            DelObj(vecBombs[i]);
        }
    }
}

void CollisionDetector::CheckDestoyableObjects(Bomb* b)
{
}
