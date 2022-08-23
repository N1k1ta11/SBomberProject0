
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
    m_bomb->Move(time * 1.1);
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