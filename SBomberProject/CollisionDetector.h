#pragma once
#include "Plane.h"
#include "DestroyableGroundObject.h"
#include "LevelGUI.h"
#include "Bomb.h"
#include "DynamicObject.h"
#include "Ground.h"
#include <iostream>
#include <vector>
using namespace std;

class CollisionDetector
{
public:
	void CheckPlaneAndLvlGUI(Plane* pl, LevelGUI* lvl,bool &exit);
	vector<Bomb*> CheckBombsAndGround(vector<Bomb*>vecBomb,Ground* g, double y);
	vector<DestroyableGroundObject*> CheckDestoyableObjects(vector<DestroyableGroundObject*> destObj,Bomb* b,double size, double size_2, int16_t &score);

};