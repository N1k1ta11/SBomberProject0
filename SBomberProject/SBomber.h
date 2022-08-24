#pragma once

#include <vector>

#include "LevelGUI.h"
#include "Plane.h"
#include "Bomb.h"
#include "Ground.h"
#include "Tank.h"
using namespace std;
class Command
{
public:
    virtual void Execute()=0;
};

template <class Object>
class CommandDel : public Command
{
public:
    CommandDel(std::vector<Object*>& vecObj) : m_vecObj(vecObj), m_pObj(nullptr) {}
    void setObj(Object* pObj)
    {
        m_pObj = pObj;
    }
    void Execute()override
    {
        if (!m_pObj)
        {
            return;
        }

        auto it = m_vecObj.begin();
        for (; it != m_vecObj.end(); it++)
        {
            if (*it == m_pObj)
            {
                m_vecObj.erase(it);
                break;
            }
        }
    }
private:
    std::vector<Object*>& m_vecObj;
    Object* m_pObj;
};

class CommandDropBomb : public Command
{
public:
    CommandDropBomb(std::vector<DynamicObject*>& vecDynamic) : m_vecDynamic(vecDynamic){}
    void setParams(Plane* plane, uint16_t *countBomb,int16_t *score);
    void Execute() override;


private:
    std::vector<DynamicObject*>& m_vecDynamic;
    Plane* m_plane;
    uint16_t *m_countBomb;
    int16_t *m_score;
};

class SBomber
{
public:

    SBomber();
    ~SBomber();
    
    inline bool GetExitFlag() const { return exitFlag; }

    void ProcessKBHit();
    void TimeStart();
    void TimeFinish();
    void CommandExecuter(Command* pCommand);
    void DrawFrame();
    void MoveObjects();
    void CheckObjects();

private:

    void CheckPlaneAndLevelGUI();
    void CheckBombsAndGround();
    void __fastcall CheckDestoyableObjects(DynamicObject* pBomb);

    //void __fastcall DeleteDynamicObj(DynamicObject * pBomb);
    //void __fastcall DeleteStaticObj(GameObject* pObj);

    Ground * FindGround() const;
    Plane * FindPlane() const;
    LevelGUI * FindLevelGUI() const;
    std::vector<DestroyableGroundObject*> FindDestoyableGroundObjects() const;
    std::vector<Bomb*> FindAllBombs() const;

    //void DropBomb(const Plane* p, vector<DynamicObject*>dO, const uint64_t & numberOfBombs);
    //void DropBomb();
    std::vector<DynamicObject*> vecDynamicObj;
    std::vector<GameObject*> vecStaticObj;
    
    bool exitFlag;

    uint64_t startTime, finishTime, passedTime;
    uint16_t bombsNumber, deltaTime, fps;
    int16_t score;
};