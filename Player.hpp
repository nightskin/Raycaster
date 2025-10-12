#pragma once
#include "Util.hpp"
#include "GameObject.hpp"

class Player : public GameObject
{
public:
	Player();
	~Player();
	void Load() override;
	void Update() override;
	void Draw() override;
	Vector2 GetForward();
	Vector2 GetRight();


	Vector2 position;
	float rotation = 0;
	int fov = 60;
private:
	float moveSpd = 0.01f;
	float rotSpd = 0.1f;
};
