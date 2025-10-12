#include <iostream>
#include "Level.hpp"
#include "Graphics.hpp"



Level::Level()
{

}

Level::~Level()
{

}

void Level::ProcGen()
{
	// Init Map
	srand(time(NULL));
	for (int x = 0; x < 50; x++)
	{
		for (int z = 0; z < 50; z++)
		{
			map[x][z] = false;
		}
	}
	int px = 25;
	int pz = 25;

	// Random Walker
	for (int i = 0; i < steps; i++)
	{
		map[px][pz] = true;
		int d = rand() % 4;
		if (d == 0)
		{
			if (px > 0)
			{
				px--;
			}
		}
		else if(d == 1)
		{
			if (px < 50 - 1)
			{
				px++;
			}
		}
		else if(d == 2)
		{
			if (pz > 0)
			{
				pz--;
			}
		}
		else
		{
			if (pz < 50 - 1)
			{
				pz++;
			}
		}

	}
	
	// Marching Squares
	for (int x = 0; x < 50 - 1; x++)
	{
		for (int y = 0; y < 50 - 1; y++)
		{
			Vector2 p = Vector2(x, y) * stepSize;
			
			Vector2 a = Vector2(p.x + (stepSize / 2), p.y);
			Vector2 b = Vector2(p.x + stepSize, p.y + (stepSize / 2));
			Vector2 c = Vector2(p.x + (stepSize / 2), p.y + stepSize);
			Vector2 d = Vector2(p.x, p.y + (stepSize / 2));
			
			int state = GetState(map[x][y], map[x + 1][y], map[x + 1][y + 1], map[x][y + 1]);
			if(state == 1)
			{
				lines.push_back(Line(c,d));
			}
			else if (state == 2)
			{
				lines.push_back(Line(b, c));
			}
			else if (state == 3)
			{
				lines.push_back(Line(b, d));
			}
			else if (state == 4)
			{
				lines.push_back(Line(a, b));
			}
			else if (state == 5)
			{
				lines.push_back(Line(d, a));
				lines.push_back(Line(c, b));
			}
			else if (state == 6)
			{
				lines.push_back(Line(a, c));
			}
			else if (state == 7)
			{
				lines.push_back(Line(d, a));
			}
			else if (state == 8)
			{
				lines.push_back(Line(d, a));
			}
			else if (state == 9)
			{
				lines.push_back(Line(a, c));
			}
			else if (state == 10)
			{
				lines.push_back(Line(d, a));
				lines.push_back(Line(a, b));
				lines.push_back(Line(d, c));
			}
			else if (state == 11)
			{
				lines.push_back(Line(a, b));
			}
			else if (state == 12)
			{
				lines.push_back(Line(d, b));
			}
			else if (state == 13)
			{
				lines.push_back(Line(c, b));
			}
			else if (state == 14)
			{
				lines.push_back(Line(d, c));
			}
		}
	}
}

void Level::DrawTopDown()
{
	for (int i = 0; i < lines.size(); i++)
	{
		Graphics::Get().DrawLine(lines[i]);
	}
}

Vector2 Level::GetPositionInMap()
{
	return Vector2(25, 25) * stepSize;
}

int Level::GetState(bool a, bool b, bool c, bool d)
{
	int state = 0;
	if (a)
	{
		state += 8;
	}
	if (b)
	{
		state += 4;
	}
	if (c)
	{
		state += 2;
	}
	if (d)
	{
		state += 1;
	}
	return state;
}
