#pragma once

#include <stdint.h>

#include "GameObject.h"

class DestroyableGroundObject : public GameObject
{
public:
    DestroyableGroundObject(){}
    DestroyableGroundObject(const DestroyableGroundObject& a) : GameObject(a){}
    virtual DestroyableGroundObject* clone() = 0;
    virtual ~DestroyableGroundObject() {}

    virtual bool __fastcall isInside(double x1, double x2) const = 0;

    virtual inline uint16_t GetScore() const = 0;

protected:

};