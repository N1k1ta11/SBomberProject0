
#include <conio.h>
#include <windows.h>

#include "MyTools.h"
#include "SBomber.h"
#include "Bomb.h"
#include "Ground.h"
#include "Tank.h"
#include "House.h"
#include "FileLogger.h"
using namespace std;
using namespace MyTools;

extern FileLogger logger;

SBomber::SBomber()
{
    m_sImpl->startTime = 0;
    m_sImpl->finishTime = 0;
    m_sImpl->deltaTime = 0;
    m_sImpl->passedTime = 0;
    m_sImpl->fps = 0;
    m_sImpl->bombsNumber = 10;
    m_sImpl->score = 0;
    m_sImpl->exitFlag = false;
    logger.WriteToLog(string(__FUNCTION__) + " was invoked");

    Plane* p = new Plane;
    p->SetDirection(1, 0.1);
    p->SetSpeed(4);
    p->SetPos(5, 10);
    m_sImpl->vecDynamicObj.push_back(p);

    LevelGUI* pGUI = new LevelGUI;
    pGUI->SetParam(m_sImpl->passedTime, m_sImpl->fps, m_sImpl->bombsNumber, m_sImpl->score);
    const uint16_t maxX = GetMaxX();
    const uint16_t maxY = GetMaxY(); 
    const uint16_t offset = 3;
    const uint16_t width = maxX - 7;
    pGUI->SetPos(offset, offset);
    pGUI->SetWidth(width);
    pGUI->SetHeight(maxY - 4);
    pGUI->SetFinishX(offset + width - 4);
    m_sImpl->vecStaticObj.push_back(pGUI);

    Ground* pGr = new Ground;
    const uint16_t groundY = maxY - 5;
    pGr->SetPos(offset + 1, groundY);
    pGr->SetWidth(width - 2);
    m_sImpl->vecStaticObj.push_back(pGr);

    Tank* pTank = new Tank;
    pTank->SetWidth(13);
    pTank->SetPos(30, groundY - 1);
    m_sImpl->vecStaticObj.push_back(pTank);

    pTank = new Tank;
    pTank->SetWidth(13);
    pTank->SetPos(50, groundY - 1);
    m_sImpl->vecStaticObj.push_back(pTank);

    House * pHouse = new House;
    pHouse->SetWidth(13);
    pHouse->SetPos(80, groundY - 1);
    m_sImpl->vecStaticObj.push_back(pHouse);

    /*
    Bomb* pBomb = new Bomb;
    pBomb->SetDirection(0.3, 1);
    pBomb->SetSpeed(2);
    pBomb->SetPos(51, 5);
    pBomb->SetSize(SMALL_CRATER_SIZE);
    vecDynamicObj.push_back(pBomb);
    */
}

SBomber::~SBomber()
{
    for (size_t i = 0; i < m_sImpl->vecDynamicObj.size(); i++)
    {
        if (m_sImpl->vecDynamicObj[i] != nullptr)
        {
            delete m_sImpl->vecDynamicObj[i];
        }
    }

    for (size_t i = 0; i < m_sImpl->vecStaticObj.size(); i++)
    {
        if (m_sImpl->vecStaticObj[i] != nullptr)
        {
            delete m_sImpl->vecStaticObj[i];
        }
    }
}

void SBomber::MoveObjects()
{
    logger.WriteToLog(string(__FUNCTION__) + " was invoked");

    for (size_t i = 0; i < m_sImpl->vecDynamicObj.size(); i++)
    {
        if (m_sImpl->vecDynamicObj[i] != nullptr)
        {
            m_sImpl->vecDynamicObj[i]->Move(m_sImpl->deltaTime);
        }
    }
};

void SBomber::CheckObjects()
{
    logger.WriteToLog(string(__FUNCTION__) + " was invoked");

    CheckPlaneAndLevelGUI();
    CheckBombsAndGround();
};

void SBomber::CheckPlaneAndLevelGUI()
{
    m_sImpl->CheckPlaneAndLevelGUI();
}

void SBomber::CheckBombsAndGround() 
{
    m_sImpl->CheckBombsAndGround();

}

void SBomber::CheckDestoyableObjects(Bomb * pBomb)
{
    m_sImpl->CheckDestoyableObjects(pBomb);
}

void SBomber::DeleteDynamicObj(DynamicObject* pObj)
{
    m_sImpl->DeleteDynamicObj(pObj);
}

void SBomber::DeleteStaticObj(GameObject* pObj)
{
    m_sImpl->DeleteStaticObj(pObj);
}

vector<DestroyableGroundObject*> SBomber::FindDestoyableGroundObjects() const
{
    return m_sImpl->FindDestoyableGroundObjects();
}

Ground* SBomber::FindGround() const
{
    return m_sImpl->FindGround();
}

vector<Bomb*> SBomber::FindAllBombs() const
{
    return m_sImpl->FindAllBombs();
}

Plane* SBomber::FindPlane() const
{
    return m_sImpl->FindPlane();
}

LevelGUI* SBomber::FindLevelGUI() const
{
    return m_sImpl->FindLevelGUI();
}

void SBomber::ProcessKBHit()
{
    int c = _getch();

    if (c == 224)
    {
        c = _getch();
    }

    logger.WriteToLog(string(__FUNCTION__) + " was invoked. key = ", c);

    switch (c) {

    case 27: // esc
        m_sImpl->exitFlag = true;
        break;

    case 72: // up
        FindPlane()->ChangePlaneY(-0.25);
        break;

    case 80: // down
        FindPlane()->ChangePlaneY(0.25);
        break;

    case 'b':
        DropBomb();
        break;

    case 'B':
        DropBomb();
        break;

    default:
        break;
    }
}

void SBomber::DrawFrame()
{
    logger.WriteToLog(string(__FUNCTION__) + " was invoked");

    for (size_t i = 0; i < m_sImpl->vecDynamicObj.size(); i++)
    {
        if (m_sImpl->vecDynamicObj[i] != nullptr)
        {
            m_sImpl->vecDynamicObj[i]->Draw();
        }
    }

    for (size_t i = 0; i < m_sImpl->vecStaticObj.size(); i++)
    {
        if (m_sImpl->vecStaticObj[i] != nullptr)
        {
            m_sImpl->vecStaticObj[i]->Draw();
        }
    }

    GotoXY(0, 0);
    m_sImpl->fps++;

    FindLevelGUI()->SetParam(m_sImpl->passedTime, m_sImpl->fps, m_sImpl->bombsNumber, m_sImpl->score);
}

void SBomber::TimeStart()
{
    logger.WriteToLog(string(__FUNCTION__) + " was invoked");
    m_sImpl->startTime = GetTickCount64();
}

void SBomber::TimeFinish()
{
    m_sImpl->finishTime = GetTickCount64();
    m_sImpl->deltaTime = uint16_t(m_sImpl->finishTime - m_sImpl->startTime);
    m_sImpl->passedTime += m_sImpl->deltaTime;

    logger.WriteToLog(string(__FUNCTION__) + " deltaTime = ", (int)m_sImpl->deltaTime);
}

void SBomber::DropBomb()
{
    m_sImpl->DropBomb();
}
