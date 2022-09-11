#pragma once
#include "Plane.h"
#include "MyTools.h"
class ColorPlane : public Plane
{
public:
	void DrawBody() const override;
	void DrawTail() const override;
	void DrawWings() const override;
};