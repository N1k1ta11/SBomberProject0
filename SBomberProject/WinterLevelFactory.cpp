#include "WinterLevelFactory.h"

Tank* WinterLevelFactory::createTank()
{
	return new WinterTank();
}

House* WinterLevelFactory::createHouse()
{
	return new WinterHouse();
}

Ground* WinterLevelFactory::createGround()
{
	return new WinterGround();
}