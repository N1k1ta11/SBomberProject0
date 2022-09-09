#include "CompositeHouseWalls.h"
using namespace MyTools;

void CompositeHouseWalls::Draw() const
{
	MyTools::SetColor(CC_Green);
	GotoXY(x, y - 3);
	std::cout << "############";
	GotoXY(x, y - 2);
	std::cout << "#          #";
	GotoXY(x, y - 1);
	std::cout << "#          #";
	GotoXY(x, y);
	std::cout << "############";
}