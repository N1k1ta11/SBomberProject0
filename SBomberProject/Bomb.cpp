
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
    m_bomb->Move(time * 1.5);
}

void BombDecorator::Draw() const
{
    /*MyTools::SetColor(CC_Red);
    GotoXY(x, y);
    cout << "@";*/
    m_bomb->Draw();
    /*GotoXY(m_bomb->GetX(), m_bomb->GetY() - 1);
    std::cout << "|";*/
}