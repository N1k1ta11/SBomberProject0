#pragma once
#include<vector>
#include"Plane.h"
#include "Bomb.h"
#include "Ground.h"
#include "LevelGUI.h"
#include "Tank.h"
#include"House.h"
#include "MyTools.h"
#include "FieldMemento.h"

class GameField
{
public:
    GameField() : state(new TState()){}
    ~GameField();

    void MoveObjects();
    void DrawFrame();

    void __fastcall DeleteDynamicObj(DynamicObject* pObj);
    void __fastcall DeleteStaticObj(GameObject* pObj);

    Ground* FindGround() const;
    Plane* FindPlane() const;
    LevelGUI* FindLevelGUI() const;
    std::vector<DestroyableGroundObject*> FindDestoyableGroundObjects() const;
    std::vector<Bomb*> FindAllBombs() const;
    void SetTime(uint64_t _startTime, uint64_t _finishTime, uint64_t _passedTime, uint16_t _deltaTime);

    void DropBomb();
    void PushStatic(GameObject* pObj) { state->vecStaticObj.push_back(pObj); }
    void PushDynamic(DynamicObject* pObj) { state->vecDynamicObj.push_back(pObj); }
    void SetParam(uint64_t _passedTime, uint16_t _fps, uint16_t _bombsNumber, int16_t _score);

    FieldMemento* Save();
    void Load(FieldMemento* memento);

private:
    TState* state;
};

