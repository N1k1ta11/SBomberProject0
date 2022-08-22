#pragma once

#include <stdint.h>
#include "MyTools.h"
#include "DestroyableGroundObject.h"

class Tank : public DestroyableGroundObject
{
public:
	Tank() {}
	Tank(MyTools::ConsoleColor c) : color(c){}

	bool __fastcall isInside(double x1, double x2) const override;

	inline uint16_t GetScore() const override { return score; }

	void Draw() const override;

private:

	const uint16_t score = 30;
	MyTools::ConsoleColor color = MyTools::ConsoleColor::CC_Brown;
};

