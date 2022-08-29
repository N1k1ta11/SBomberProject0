#pragma once
#include "DestroyableGroundObject.h"
#include "TankAdaptee.h"
class TankAdapter : public DestroyableGroundObject
{
public:
	TankAdaptee tank;
	void SetPos(double nx, double ny);
	uint16_t GetWidth() const;
	void Draw();
	bool __fastcall isInside(double x1, double x2) const;
};

