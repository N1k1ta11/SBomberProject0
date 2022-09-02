
#include <iostream>

#include "House.h"
#include "MyTools.h"

using namespace std;
using namespace MyTools;

bool House::isInside(double x1, double x2) const
{
	const double XBeg = x + 2;
	const double XEnd = x + width - 1;

	if (x1 < XBeg && x2 > XEnd)
	{
		return true;
	}

	if (x1 > XBeg && x1 < XEnd)
	{
		return true;
	}

	if (x2 > XBeg && x2 < XEnd)
	{
		return true;
	}

	return false;
}

void House::Draw() const
{
	MyTools::SetColor(color);
	int k=5;
	for (int i = 0; i < 6; i++)
	{
		GotoXY(x, y - k);
		for (int j = 0; j < 12; j++)
		{
			cout << look[i][j];
		}
		k--;
	}
}

void HouseBuilderA::buildRoof()
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 12; j++)
		{
			if (i == 0 && (j == 0 || j == 1 || j == 10 || j == 11))
			{
				h->look[i][j] = ' ';
				continue;
			}
			if (i == 1 && (j != 0 && j != 1 && j != 10 && j != 11))
			{
				h->look[i][j] = ' ';
				continue;
			}
			h->look[i][j] = '#';
		}
	}
}

void HouseBuilderA::buildWalls()
{
	for (int i = 3; i < 6; i++)
	{
		for (int j = 0; j < 12; j++)
		{
			if ((i == 3 || i == 4) && (j != 0 && j != 11))
			{
				h->look[i][j] = ' ';
				continue;
			}
			h->look[i][j] = '#';

		}
	}
}

void HouseBuilderB::buildRoof()
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 12; j++)
		{
			if (i == 0 && (j == 0 || j == 1 || j == 10 || j == 11))
			{
				h->look[i][j] = ' ';
				continue;
			}
			if (i == 1 && (j != 0 && j != 1 && j != 10 && j != 11))
			{
				h->look[i][j] = ' ';
				continue;
			}
			h->look[i][j] = '+';
		}
	}
}

void HouseBuilderB::buildWalls()
{
	for (int i = 3; i < 6; i++)
	{
		for (int j = 0; j < 12; j++)
		{
			if ((i == 3 || i == 4) && (j != 0 && j!=1 && j!=2 && j!=9 && j!=10 && j != 11))
			{
				h->look[i][j] = ' ';
				continue;
			}
			h->look[i][j] = '+';
		}
	}
}


