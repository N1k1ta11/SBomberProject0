#include "Mediator.h"

void Mediator::Add(GameObject* obj)
{
	vecObj.push_back(obj);
}

void Mediator::Notify(std::vector<std::string>vec)
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