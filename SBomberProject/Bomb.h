#pragma once

#include "DynamicObject.h"

class Bomb : public DynamicObject
{
public:

	static const uint16_t BombCost = 10; // стоимость бомбы в очках

	void Draw() const override;

private:

};

class BombDecorator : public DynamicObject
{
public:
	BombDecorator(DynamicObject* bomb) : m_bomb(bomb) {}
	void Draw() const override;
	void Move(uint16_t time) override;
	void SetPos(double nx, double ny);
	uint16_t GetWidth() const;
	DynamicObject* m_bomb;

};

