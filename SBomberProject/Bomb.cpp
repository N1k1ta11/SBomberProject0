
#include <iostream>

#include "Bomb.h"
#include "MyTools.h"

using namespace std;
using namespace MyTools;

void Bomb::Draw() const
{
    MyTools::SetColor(CC_LightMagenta);
    GotoXY(x, y);
    cout << "*";
}

void BombDecorator::Move(uint16_t time)
{
    uint16_t newT = time * 1.5;
    m_bomb->Move(newT);
}

void BombDecorator::SetPos(double nx, double ny)
{
    m_bomb->SetPos(nx, ny);
}

uint16_t BombDecorator::GetWidth() const
{
    return m_bomb->GetWidth();
}

void BombDecorator::Draw() const
{
    m_bomb->Draw();
}