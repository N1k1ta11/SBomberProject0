#pragma once
#include "CompositeHouse.h"
#include <vector>

class CompositeHouseTree :
    public CompositeHouse
{
public:
    void Draw() const override;
    bool __fastcall isInside(double x1, double x2) const override;

    uint16_t GetScore() const override;

    void AddChild(CompositeHouse* child);
private:
    std::vector<CompositeHouse*> children;
};

