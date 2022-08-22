#pragma once

#include <vector>
#include "MyTools.h"
#include "GameObject.h"

//=============================================================================================================

enum CraterSize 
{ 
	SMALL_CRATER_SIZE = 9 
};

//=============================================================================================================

class Crater : public GameObject
{
public:

	bool __fastcall isInside(double xn) const;
	
	void Draw() const override;

private:

};

//=============================================================================================================

class Ground : public GameObject
{
public:

	Ground() { }
	Ground(MyTools::ConsoleColor c) : color(c){}
	void Draw() const override;

	void __fastcall AddCrater(double xn);

private:

	bool __fastcall isInsideAnyCrater(double x) const;

	std::vector<Crater> vecCrates;
	MyTools::ConsoleColor color = MyTools::ConsoleColor::CC_Green;
};

