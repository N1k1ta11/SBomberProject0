#include "CompositeHouseTree.h"

void CompositeHouseTree::Draw() const
{
	for (auto i : children)
	{
		i->Draw();
	}
}

uint16_t CompositeHouseTree::GetScore() const
{
	uint16_t total = 0;;
	for (auto i : children)
	{
		total+=i->GetScore();
	}
	return total;
}

void CompositeHouseTree::AddChild(CompositeHouse* child)
{
	children.push_back(child);
}

bool __fastcall CompositeHouseTree::isInside(double x1, double x2) const
{
	for (auto i : children)
	{
		if (i->isInside(x1, x2))
		{
			return true;
		}
	}
	return false;
}
