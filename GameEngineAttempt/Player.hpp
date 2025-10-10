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

	Vector3 position;
	Vector2 rotation;
private:
	float moveSpd = 0.1f;
	float rotSpd = 0.001f;
};
