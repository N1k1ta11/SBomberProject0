#pragma once
#include "CompositeHouseLeaf.h"
#include "MyTools.h"
#include <iostream>

class CompositeHouseWalls :
    public CompositeHouseLeaf
{
public:
	inline uint16_t GetScore() const override { return score; }

	void Draw() const override;

private:
	const uint16_t score = 30;
};

