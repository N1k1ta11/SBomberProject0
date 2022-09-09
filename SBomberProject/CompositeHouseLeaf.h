#pragma once
#include "CompositeHouse.h"
class CompositeHouseLeaf :
    public CompositeHouse
{
public:
    bool __fastcall isInside(double x1, double x2) const override;

};

