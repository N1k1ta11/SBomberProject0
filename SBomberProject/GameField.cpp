#include "GameField.h"

GameField::~GameField()
{
    for (size_t i = 0; i <state->vecDynamicObj.size(); i++)
    {
        if (state->vecDynamicObj[i] != nullptr)
        {
            delete state->vecDynamicObj[i];
        }
    }

    for (size_t i = 0; i < state->vecStaticObj.size(); i++)
    {
        if (state->vecStaticObj[i] != nullptr)
        {
            delete state->vecStaticObj[i];
        }
    }
}

void GameField::MoveObjects()
{
    MyTools::WriteToLog(std::string(__FUNCTION__) + " was invoked");

    for (size_t i = 0; i < state->vecDynamicObj.size(); i++)
    {
        if (state->vecDynamicObj[i] != nullptr)
        {
            state->vecDynamicObj[i]->Move(state->deltaTime);
        }
    }
}

void GameField::DrawFrame()
{
    MyTools::WriteToLog(std::string(__FUNCTION__) + " was invoked");

    for (size_t i = 0; i < state->vecDynamicObj.size(); i++)
    {
        if (state->vecDynamicObj[i] != nullptr)
        {
            state->vecDynamicObj[i]->Draw();
        }
    }

    for (size_t i = 0; i < state->vecStaticObj.size(); i++)
    {
        if (state->vecStaticObj[i] != nullptr)
        {
            state->vecStaticObj[i]->Draw();
        }
    }

    MyTools::GotoXY(0, 0);
    state->fps++;

    FindLevelGUI()->SetParam(state->passedTime, state->fps, state->bombsNumber, state->score);
}

void __fastcall GameField::DeleteDynamicObj(DynamicObject* pObj)
{
    auto it = state->vecDynamicObj.begin();
    for (; it != state->vecDynamicObj.end(); it++)
    {
        if (*it == pObj)
        {
            state->vecDynamicObj.erase(it);
            break;
        }
    }
}

void __fastcall GameField::DeleteStaticObj(GameObject* pObj)
{
    auto it = state->vecStaticObj.begin();
    for (; it != state->vecStaticObj.end(); it++)
    {
        if (*it == pObj)
        {
            state->vecStaticObj.erase(it);
            break;
        }
    }
}

Ground* GameField::FindGround() const
{
    Ground* pGround;

    for (size_t i = 0; i < state->vecStaticObj.size(); i++)
    {
        pGround = dynamic_cast<Ground*>(state->vecStaticObj[i]);
        if (pGround != nullptr)
        {
            return pGround;
        }
    }

    return nullptr;
}

Plane* GameField::FindPlane() const
{
    for (size_t i = 0; i < state->vecDynamicObj.size(); i++)
    {
        Plane* p = dynamic_cast<Plane*>(state->vecDynamicObj[i]);
        if (p != nullptr)
        {
            return p;
        }
    }

    return nullptr;
}

LevelGUI* GameField::FindLevelGUI() const
{
    for (size_t i = 0; i < state->vecStaticObj.size(); i++)
    {
        LevelGUI* p = dynamic_cast<LevelGUI*>(state->vecStaticObj[i]);
        if (p != nullptr)
        {
            return p;
        }
    }

    return nullptr;
}

std::vector<DestroyableGroundObject*> GameField::FindDestoyableGroundObjects() const
{
    std::vector<DestroyableGroundObject*> vec;
    Tank* pTank;
    House* pHouse;
    for (size_t i = 0; i < state->vecStaticObj.size(); i++)
    {
        pTank = dynamic_cast<Tank*>(state->vecStaticObj[i]);
        if (pTank != nullptr)
        {
            vec.push_back(pTank);
            continue;
        }

        pHouse = dynamic_cast<House*>(state->vecStaticObj[i]);
        if (pHouse != nullptr)
        {
            vec.push_back(pHouse);
            continue;
        }
    }

    return vec;
}

std::vector<Bomb*> GameField::FindAllBombs() const
{
    std::vector<Bomb*> vecBombs;

    for (size_t i = 0; i < state->vecDynamicObj.size(); i++)
    {
        Bomb* pBomb = dynamic_cast<Bomb*>(state->vecDynamicObj[i]);
        if (pBomb != nullptr)
        {
            vecBombs.push_back(pBomb);
        }
    }

    return vecBombs;
}

void GameField::SetTime(uint64_t _startTime, uint64_t _finishTime, uint64_t _passedTime, uint16_t _deltaTime)
{
    state->startTime = _startTime;
    state->finishTime = _finishTime;
    state->passedTime = _passedTime;
    state->deltaTime = _deltaTime;
}


void GameField::DropBomb()
{
    if (state->bombsNumber > 0)
    {
        MyTools::WriteToLog(std::string(__FUNCTION__) + " was invoked");

        Plane* pPlane = FindPlane();
        double x = pPlane->GetX() + 4;
        double y = pPlane->GetY() + 2;

        Bomb* pBomb = new Bomb;
        pBomb->SetDirection(0.3, 1);
        pBomb->SetSpeed(2);
        pBomb->SetPos(x, y);
        pBomb->SetWidth(SMALL_CRATER_SIZE);

        state->vecDynamicObj.push_back(pBomb);
        state->bombsNumber--;
        state->score -= Bomb::BombCost;
    }
}

void GameField::SetParam(uint64_t _passedTime, uint16_t _fps, uint16_t _bombsNumber, int16_t _score)
{
    state->passedTime = _passedTime;
    state->fps = _fps;
    state->bombsNumber = _bombsNumber;
    state->score = _score;
}

FieldMemento* GameField::Save()
{
    return new FieldMemento(state);
}

void GameField::Load(FieldMemento* memento)
{
    delete state;
    state = memento->GetState()->clone();
}
