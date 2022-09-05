#pragma once
#include "Bomb.h"
#include "Plane.h"
#include "MyTools.h"
#include <iostream>
#include <string>
#include "DynamicObject.h"
#include "MyTools.h"
using namespace std;
using namespace MyTools;

class Visitor
{
public:
	virtual void log(class Bomb b) = 0;
	virtual void log(class Plane p) = 0;
private:
};

class LogVisitor : public Visitor
{
public:
	void log(Bomb b) override;
	void log(Plane p) override;
};

