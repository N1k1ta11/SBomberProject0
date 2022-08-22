#pragma once
#include "AbstractLevelFactory.h"
#include "WinterGround.h"
#include "WinterHouse.h"
#include "WinterTank.h"

class WinterLevelFactory : public AbstractLevelFactory
{
	Tank* createTank();
	Ground* createGround();
	House* createHouse();
};

