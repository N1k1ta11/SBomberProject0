#pragma once

#include <vector>

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
	Crater(){}
	Crater(const Crater& b) : GameObject(b){}
	Crater* clone() { return new Crater(*this); }
	bool __fastcall isInside(double xn) const;
	
	void Draw() const override;

private:

};

//=============================================================================================================

class Ground : public GameObject
{
public:

	Ground() { }
	Ground(const Ground& b) : GameObject(b), vecCrates(b.vecCrates) {}
	Ground* clone() { return new Ground(*this); }
	void Draw() const override;

	void __fastcall AddCrater(double xn);

private:

	bool __fastcall isInsideAnyCrater(double x) const;

	std::vector<Crater> vecCrates;
};

