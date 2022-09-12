#pragma once

#include "DynamicObject.h"

class Bomb : public DynamicObject
{
public:
	Bomb(){}
	Bomb(const Bomb& b) : DynamicObject(b){}

	Bomb* clone() { return new Bomb(*this); }

	static const uint16_t BombCost = 10; // стоимость бомбы в очках

	void Draw() const override;

private:

};

