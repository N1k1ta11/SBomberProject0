#pragma once
#include "Tank.h"
#include "Ground.h"
#include "House.h"

class AbstractLevelFactory
{
public:
	virtual Tank* createTank() = 0;
	virtual Ground* createGround() = 0;
	virtual House* createHouse() = 0;
};

