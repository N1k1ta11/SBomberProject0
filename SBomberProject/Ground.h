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
	Crater(const Crater& a) : GameObject(a){}
	Crater* clone() override { return new Crater(*this); }
	bool __fastcall isInside(double xn) const;
	
	void Draw() const override;

private:

};

//=============================================================================================================

class Ground : public GameObject
{
public:

	Ground() { }
	Ground(const Ground& a) : GameObject(a), vecCrates(a.vecCrates){}
	Ground* clone() override { return new Ground(*this); }
	void Draw() const override;

	void __fastcall AddCrater(double xn);

private:

	bool __fastcall isInsideAnyCrater(double x) const;

	std::vector<Crater> vecCrates;
};

