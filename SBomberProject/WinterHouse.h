#pragma once
#include "House.h"
#include "MyTools.h"
class WinterHouse : public House
{
public:
	WinterHouse() : House(MyTools::ConsoleColor::CC_White) {}
};

