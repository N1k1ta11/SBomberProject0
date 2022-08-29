#include "TankAdapter.h"
void TankAdapter::SetPos(double nx, double ny)
{
    tank.SetPos(nx, ny);
}


uint16_t TankAdapter::GetWidth() const
{
    return tank.GetWidth();
}


void TankAdapter::Draw()
{
    tank.Paint();
};


bool __fastcall TankAdapter::isInside(double x1, double x2) const
{
    tank.isInRange(x1, x2);
};