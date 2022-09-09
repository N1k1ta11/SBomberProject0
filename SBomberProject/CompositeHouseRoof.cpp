#include "CompositeHouseRoof.h"
#include "MyTools.h"
#include <iostream>
using namespace MyTools;

void CompositeHouseRoof::Draw() const
{

	MyTools::SetColor(CC_LightGray);
	GotoXY(x, y - 5);
	std::cout << "  ########  ";
	GotoXY(x, y - 4);
	std::cout << "##        ##";
}
