#pragma once

#include <stdint.h>

#include "DestroyableGroundObject.h"

class House : public DestroyableGroundObject
{
public:

	bool __fastcall isInside(double x1, double x2) const override;

	inline uint16_t GetScore() const override { return score; }

	void Draw() const override;

private:
	const uint16_t score = 40;
};

class HouseBuilder
{
protected:
	House* h;
public:
	virtual void createHouse() {}
	virtual House* getHouse() { return h; }
};

class YellowHouse : public HouseBuilder
{
public:
	void createHouse() { h = new House; }
};

class BlueHouse : public HouseBuilder
{
	void createHouse() { h = new House; }
};

class Director
{
public:
	House* createHouse(HouseBuilder& builder)
	{
		builder.createHouse();
		return builder.getHouse();
	}
};