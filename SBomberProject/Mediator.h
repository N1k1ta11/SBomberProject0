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
	void Add(GameObject* obj);

	void Notify(std::vector<std::string>vec);

private:
	std::vector<GameObject*>vecObj;
};

