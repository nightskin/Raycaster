#pragma once
#include <vector>
#include "Util.hpp"

class Level
{
public:
	Level();
	~Level();
	void ProcGen();
	void DrawTopDown();
	void DrawPerspective(Vector3 pos, Vector3 rot);
	Vector3 GetPositionInMap();
private:
	bool map[50][50];
	int GetState(bool a, bool b, bool c, bool d);
	float stepSize = 600 / 50;
	int steps = 200;
	std::vector<Line> lines;
};
