#pragma once
#include "AbstractLevelFactory.h"
class SummerLevelFactory : public AbstractLevelFactory
{
public:
	Tank* createTank();
	Ground* createGround();
	House* createHouse();
};

