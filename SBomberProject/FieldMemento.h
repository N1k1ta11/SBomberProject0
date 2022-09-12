#pragma once
#include<vector>
#include"Plane.h"
#include "Bomb.h"
#include "Ground.h"
#include "LevelGUI.h"
#include "Tank.h"
#include"House.h"
#include "MyTools.h"

struct TState
{
    std::vector<DynamicObject*> vecDynamicObj;
    std::vector<GameObject*> vecStaticObj;

    uint64_t startTime, finishTime, passedTime;
    uint16_t bombsNumber, deltaTime, fps;
    int16_t score;

    TState* clone()
    {
        TState* n = new TState();
        for (auto i : this->vecStaticObj)
        {
            n->vecStaticObj.push_back(i->clone());
        }
        for (auto i : this->vecDynamicObj)
        {
            n->vecDynamicObj.push_back(i->clone());
        }
        n->startTime = this->startTime;
        n->finishTime = this->finishTime;
        n->passedTime = this->passedTime;
        n->bombsNumber = this->bombsNumber;
        n->deltaTime = this->deltaTime;
        n->fps = this->fps;
        n->score = this->score;
        return n;
    }

    ~TState();
};

class FieldMemento
{
public:
    FieldMemento( TState* pState) : state(pState->clone()){}
    ~FieldMemento();
    TState* GetState() { return state; }
private:
    TState* state;
};

