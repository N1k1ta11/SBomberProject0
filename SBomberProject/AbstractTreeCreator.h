#pragma once
#include "DestroyableGroundObject.h"
class AbstractTreeCreator
{
public:
	virtual DestroyableGroundObject* createTree() = 0;
};

