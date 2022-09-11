#pragma once

#include <stdint.h>
#include <vector>
#include <string>

#include "DestroyableGroundObject.h"
#include "Mediator.h"
using namespace std;
class Tank : public DestroyableGroundObject
{
public:
	Tank(Mediator* med) : pMediator(med){}
	bool __fastcall isInside(double x1, double x2) const override;

	inline uint16_t GetScore() const override { return score; }

	void Draw() const override;
	vector<string>vecMes{ "Tank> Hi, Plane", "Tank> I kill you","Tank> I give up" };

private:
	
	Mediator* pMediator;

	const uint16_t score = 30;
};

