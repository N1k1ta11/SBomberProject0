#pragma once

#include "DynamicObject.h"
#include "DestroyableGroundObject.h"
#include "Visitor.h"
#include <vector>

class Bomb;

class Observer : public DestroyableGroundObject
{
public:
	bool HandleInsideChacke(double x1, double x2);
};



class Bomb : public DynamicObject
{
public:

	static const uint16_t BombCost = 10; // ��������� ����� � �����

	void Draw() const override;

	void __fastcall Accept(class Visitor& v);

	void AddObserver(DestroyableGroundObject* o);

	DestroyableGroundObject* CheckDestroyableObject()
	{

		const double size = this->GetWidth();
		const double size_2 = size / 2;
		for (auto i : vecObs)
		{
			const double x1 = this->GetX() - size_2;
			const double x2 = x1 + size;

			if (i->HandleInsideChacke(x1, x2))
			{

			}
		}
		
	}
private:
	std::vector<Observer*>vecObs;
};

