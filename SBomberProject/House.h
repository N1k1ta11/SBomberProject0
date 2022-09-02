#pragma once

#include <stdint.h>
#include "MyTools.h"
#include "DestroyableGroundObject.h"
using namespace MyTools;

class House : public DestroyableGroundObject
{
public:
	bool __fastcall isInside(double x1, double x2) const override;

	inline uint16_t GetScore() const override { return score; }

	void Draw() const override;
	char look[6][12];
	ConsoleColor color;
private:
	const uint16_t score = 40;
};

class HouseBuilder
{
protected:
	House* h;
public:
	HouseBuilder() : h(0){}
	virtual void createHouse(){}
	virtual void buildColor(){}
	virtual void buildRoof(){}
	virtual void buildWalls(){}
	virtual House* GetHouse() { return h; }
};

class HouseBuilderA : public HouseBuilder
{
	friend House;
public:
	void createHouse() override  { h = new House; }
	void buildColor() override { h->color = CC_Magenta; };
	void buildRoof() override;
	void buildWalls() override;

};

class HouseBuilderB : public HouseBuilder
{
	friend House;
public:
	void createHouse() { h = new House; }
	void buildColor() override  { h->color = CC_LightRed; };
	void buildRoof() override;
	void buildWalls() override;

};

class HouseDirector
{
public:
	House* createHouse(HouseBuilder& builder)
	{
		builder.createHouse();
		builder.buildColor();
		builder.buildRoof();
		builder.buildWalls();
		return builder.GetHouse();
	}
};