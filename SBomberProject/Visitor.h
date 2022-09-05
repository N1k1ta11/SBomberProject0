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
	virtual void log(Bomb b) = 0;
	virtual void log(Plane p) = 0;
private:
};

class LogVisitor : public Visitor
{
public:
	void log(Bomb b)
	{
		WriteToLog(string(__FUNCTION__) + " was invoked", b.GetSpeed());
		WriteToLog(string(__FUNCTION__) + " was invoked", b.GetxDirection());
		WriteToLog(string(__FUNCTION__) + " was invoked", b.GetyDirection());
	}
	void log(Plane p)
	{
		WriteToLog(string(__FUNCTION__) + " was invoked", p.GetSpeed());
		WriteToLog(string(__FUNCTION__) + " was invoked", p.GetxDirection());
		WriteToLog(string(__FUNCTION__) + " was invoked", p.GetyDirection());
	}
};

