#pragma once

#include <stdint.h>

#include "GameObject.h"

class DestroyableGroundObject : public GameObject
{
public:
    DestroyableGroundObject() {}
    DestroyableGroundObject(const DestroyableGroundObject& b) : GameObject(b) {}

    virtual DestroyableGroundObject* clone() = 0;

    virtual bool __fastcall isInside(double x1, double x2) const = 0;

    virtual inline uint16_t GetScore() const = 0;

protected:

};