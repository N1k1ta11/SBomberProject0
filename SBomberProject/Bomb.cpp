
#include <iostream>

#include "Bomb.h"
#include "MyTools.h"
#include "Visitor.h"

using namespace std;
using namespace MyTools;

void Bomb::Draw() const
{
    MyTools::SetColor(CC_LightMagenta);
    GotoXY(x, y);
    cout << "*";
}

void __fastcall Bomb::Accept(Visitor& v)
{
    v.log(*this);
}

void Bomb::AddObserver(DestroyableGroundObject* o)
{
    Observer* pObs = dynamic_cast<Observer*>(o);
    vecObs.push_back(pObs); 
}

bool Observer::HandleInsideChacke(double x1, double x2)
{
    return this->isInside(x1, x2);
}
