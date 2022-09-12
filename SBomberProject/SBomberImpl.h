#pragma once
#include "Bomb.h"
#include "Ground.h"
#include "Plane.h"
#include "LevelGUI.h"
#include "Tank.h"
#include "House.h"
#include "DestroyableGroundObject.h"
#include "FileLogger.h"
#include <string>

class SBomberImpl
{
public:
    void CheckPlaneAndLevelGUI();
    void CheckBombsAndGround();
    void __fastcall CheckDestoyableObjects(Bomb* pBomb);

    void __fastcall DeleteDynamicObj(DynamicObject* pObj);
    void __fastcall DeleteStaticObj(GameObject* pObj);

    Ground* FindGround() const;
    Plane* FindPlane() const;
    LevelGUI* FindLevelGUI() const;
    std::vector<DestroyableGroundObject*> FindDestoyableGroundObjects() const;
    std::vector<Bomb*> FindAllBombs() const;

    void DropBomb();

    std::vector<DynamicObject*> vecDynamicObj;
    std::vector<GameObject*> vecStaticObj;

    bool exitFlag;

    uint64_t startTime, finishTime, passedTime,fps;
    uint16_t bombsNumber, deltaTime;
    int16_t score;
};

