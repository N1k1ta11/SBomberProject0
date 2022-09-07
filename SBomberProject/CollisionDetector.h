#pragma once
#include "SBomber.h"
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
	void newCheckPlaneAndLvlGUI(Plane* pl, LevelGUI* lvl,bool &exit);
	vector<Bomb*> newCheckBombsAndGround(vector<Bomb*>vecBomb, vector<DestroyableGroundObject*> Obj, Ground* g, double y);
	void newCheckDestoyableObjects(Bomb* b, SBomber* s);

private:
	vector<DestroyableGroundObject*> m_Obj;
	int16_t* m_score;
};