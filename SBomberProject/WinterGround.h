#pragma once
#include "Ground.h"
#include "MyTools.h"
class WinterGround : public Ground
{
public:
	WinterGround() : Ground(MyTools::ConsoleColor::CC_White){}
};

