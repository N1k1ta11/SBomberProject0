#pragma once

#include "DynamicObject.h"
#include "DestroyableGroundObject.h"
#include "Visitor.h"
#include <vector>


class Bomb : public DynamicObject
{
public:
	std::vector<DestroyableGroundObject*>vecObs;

	static const uint16_t BombCost = 10; // стоимость бомбы в очках

	void Draw() const override;

	void __fastcall Accept(class Visitor& v);

	void AddObserver(DestroyableGroundObject* o);

	void RemoveObserver(std::vector<DestroyableGroundObject*>::iterator it);

	DestroyableGroundObject* CheckDestroyableObject()
	{

		const double size = this->GetWidth();
		const double size_2 = size / 2;
		for (auto i : vecObs)
		{
			const double x1 = this->GetX() - size_2;
			const double x2 = x1 + size;

			if (i->isInside(x1, x2))
			{
				return i;
			}
		}
		
	}
private:
};

