#pragma once

#include "DynamicObject.h"

class Plane : public DynamicObject {
public:

    Plane() {}
    Plane(const Plane& a) : DynamicObject(a) {}
    Plane* clone() { return new Plane(*this); }

    void Draw() const override;

    inline void ChangePlaneY(double dy) { yDirection += dy; }

private:

};

