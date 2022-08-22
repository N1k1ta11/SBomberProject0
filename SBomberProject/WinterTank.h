#pragma once
#include "Tank.h"
#include "MyTools.h"
class WinterTank : public Tank
{
public:
	WinterTank() : Tank(MyTools::ConsoleColor::CC_LightGray){}
};

