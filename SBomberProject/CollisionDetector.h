#pragma once
#include "SBomber.h"
#include <iostream>
#include <vector>
using namespace std;

class CollisionDetector
{
public:
	void CheckPlaneAndLvl(Plane* fPlane, LevelGUI* fGUI, bool& exit);
	void CheckBombsAndGround(vector<Bomb*>vecBombs, Ground* pGround, void (SBomber::* DelObj)(DynamicObject*), vector<DestroyableGroundObject*>(SBomber::* FindDestoyableGroundObjects)());
	void CheckDestoyableObjects(Bomb* pBomb, vector<DestroyableGroundObject*>(SBomber::*FindDestoyableGroundObjects)());
};

