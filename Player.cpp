#include "Player.hpp"
#include "Graphics.hpp"
#include "Input.hpp"
#include "Time.hpp"

Player::Player()
{
	
}

Player::~Player()
{

}

void Player::Load()
{
	rotation = 0;
}

void Player::Update()
{
	//Moving
	if (Input::Get().keyboard[SDL_SCANCODE_W])
	{
		position += GetForward() * moveSpd * Time::Get().DeltaTime();
	}
	else if (Input::Get().keyboard[SDL_SCANCODE_S])
	{
		position -= GetForward() * moveSpd * Time::Get().DeltaTime();
	}

	//Looking
	if (Input::Get().keyboard[SDL_SCANCODE_A])
	{
		rotation += rotSpd * Time::Get().DeltaTime();
		if (rotation > 360) rotation -= 360;
	}
	else if (Input::Get().keyboard[SDL_SCANCODE_D])
	{
		rotation -= rotSpd * Time::Get().DeltaTime();
		if (rotation < 0) rotation += 360;
	}

}

void Player::Draw()
{
	//Top down view
	Vector2 p2d = Vector2(position.x, position.y);
	Graphics::Get().DrawRect(p2d, Vector2(10, 10), Color(1, 0, 0));
	Graphics::Get().DrawLine(p2d, p2d + (GetForward() * 10));
}

Vector2 Player::GetForward()
{
	return Vector2(MathHelper::Deg2Rad(rotation));
}

Vector2 Player::GetRight()
{
	return Vector2(MathHelper::Deg2Rad(rotation + 90));
}

