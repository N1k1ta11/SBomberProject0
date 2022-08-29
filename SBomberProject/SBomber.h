#pragma once

#include <vector>

#include "LevelGUI.h"
#include "Plane.h"
#include "Bomb.h"
#include "Ground.h"
#include "Tank.h"

using namespace std;

class SBomber
{
public:

    SBomber();
    ~SBomber();
    
    inline bool GetExitFlag() const { return exitFlag; }

    void ProcessKBHit();
    void TimeStart();
    void TimeFinish();

    void DrawFrame();
    void MoveObjects();
    void CheckObjects();

private:

    void CheckPlaneAndLevelGUI();
    void CheckBombsAndGround();
    void __fastcall CheckDestoyableObjects(Bomb* pBomb);

    void __fastcall DeleteDynamicObj(DynamicObject * pBomb);
    void __fastcall DeleteStaticObj(GameObject* pObj);

    Ground * FindGround() const;
    Plane * FindPlane() const;
    LevelGUI * FindLevelGUI() const;
    std::vector<DestroyableGroundObject*> FindDestoyableGroundObjects() const;
    std::vector<Bomb*> FindAllBombs() const;

    void DropBomb();

    std::vector<DynamicObject*> vecDynamicObj;
    std::vector<GameObject*> vecStaticObj;
    
    bool exitFlag;

    uint64_t startTime, finishTime, passedTime;
    uint16_t bombsNumber, deltaTime, fps;
    int16_t score;
};


class DynamicaArr
{
private:
	vector<DynamicObject*>bombs;
public:
	DynamicaArr(vector<DynamicObject*>v);

	void push_back(DynamicObject* n);
	class BombIterator
	{
	private:
		vector<DynamicObject*>& refBombs;
		int index;
		DynamicObject* ptr;
	public:
		BombIterator(vector<DynamicObject*>& b) :refBombs(b), index(-1), ptr(nullptr) { ++(*this); }
		void reset();
		BombIterator& operator++()
		{
			index++;
			if (index == -1)
			{
				index = 0;
			}
			for (; index < refBombs.size(); index++)
			{
				Bomb* pBomb = dynamic_cast<Bomb*>(refBombs[index]);
				if (pBomb!=nullptr)
				{
					ptr = refBombs[index];
					break;
				}
			}
			if (index == refBombs.size())
			{
				index = -1;
				ptr = nullptr;
			}
			return *this;
		}

		BombIterator& operator--()
		{
			if (index == -1)
			{
				index = refBombs.size() - 1;
			}
			for (; index >= 0; index--)
			{
				Bomb* pBomb = dynamic_cast<Bomb*>(refBombs[index]);
				if (pBomb != nullptr)
				{
					ptr = refBombs[index];
					break;
				}
			}
			if (index == -1)
			{
				ptr = nullptr;
			}
			return *this;
		}

		DynamicObject* operator*() // операция разыменования итератора
		{
			return refBombs.at(index);
		}

		bool operator==(BombIterator it) // проверка на лог. равенство итераторов
		{
			if (index == it.index &&
				ptr == it.ptr &&
				refBombs == it.refBombs)
			{
				return true;
			}
			return false;
		}

		bool operator!=(BombIterator it) // проверка на лог. неравенство
		{
			return !(*this == it);
		}
	};

	BombIterator begin() { BombIterator it(bombs); return it; };
	BombIterator end() { BombIterator it(bombs); it.reset(); return it; }
};