#pragma once
#include "AbstractTreeCreator.h"
#include "TreeB.h"
class TreeCreatorB :
    public AbstractTreeCreator
{
public:
    DestroyableGroundObject* createTree() { return new TreeB(); }
};

