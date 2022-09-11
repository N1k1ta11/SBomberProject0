#pragma once
#include"LevelGUI.h"
#include<time.h>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

class Mediator
{
public:
	void Add(GameObject* obj)
	{
		vecObj.push_back(obj);
	}

	void Notify(std::vector<std::string>vec)
	{
		srand(time(0));
		std::random_shuffle(vec.begin(), vec.end());
		for (auto i : vecObj)
		{
			LevelGUI* lvl = dynamic_cast<LevelGUI*>(i);
			if (lvl != nullptr)
			{
				lvl->SetVecMessage(vec[0]);
			}
		}
	}

private:
	std::vector<GameObject*>vecObj;
};

