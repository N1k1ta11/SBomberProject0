#include "SummerLevelFactory.h"
Tank* SummerLevelFactory::createTank()
{
	return new Tank();
}

House* SummerLevelFactory::createHouse()
{
	return new House();
}

Ground* SummerLevelFactory::createGround()
{
	return new Ground();
}