#pragma once
#include "SBomber.h"
#include <iostream>
class CollisionDetector
{
public:
	void CheckPlaneAndLvl(Plane* fPlane, LevelGUI* fGUI, bool& exit);
	void CheckBombsAndGround(vector<Bomb*>bombs, Ground* ground, void (*DelObj)(DynamicObject* pObj));
	void CheckDestoyableObjects(Bomb* b);
};

