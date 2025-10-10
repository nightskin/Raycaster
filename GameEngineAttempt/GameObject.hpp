#pragma once
class GameObject
{
public:
	GameObject();
	~GameObject();

	virtual void Load();
	virtual void Update();
	virtual void Draw();
};
