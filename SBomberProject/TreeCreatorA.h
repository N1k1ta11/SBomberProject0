#pragma once
#include "AbstractTreeCreator.h"
#include "TreeA.h"
class TreeCreatorA :
    public AbstractTreeCreator
{
public:
    DestroyableGroundObject* createTree() { return new TreeA(); }
};

