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

}

void Player::Update()
{
	//Moving
	if (Input::Get().keyboard[SDL_SCANCODE_W])
	{
		position.z -= moveSpd * Time::Get().DeltaTime();
	}
	else if (Input::Get().keyboard[SDL_SCANCODE_S])
	{
		position.z += moveSpd * Time::Get().DeltaTime();
	}

	if (Input::Get().keyboard[SDL_SCANCODE_A])
	{
		position.x -= moveSpd * Time::Get().DeltaTime();
	}
	else if (Input::Get().keyboard[SDL_SCANCODE_D])
	{
		position.x += moveSpd * Time::Get().DeltaTime();
	}

	//looking
	if (Input::Get().keyboard[SDL_SCANCODE_UP])
	{
		rotation.x -= rotSpd * Time::Get().DeltaTime();
	}
	else if (Input::Get().keyboard[SDL_SCANCODE_DOWN])
	{
		rotation.x += rotSpd * Time::Get().DeltaTime();
	}

	if (Input::Get().keyboard[SDL_SCANCODE_LEFT])
	{
		rotation.y -= rotSpd * Time::Get().DeltaTime();
	}
	else if (Input::Get().keyboard[SDL_SCANCODE_RIGHT])
	{
		rotation.y += rotSpd * Time::Get().DeltaTime();
	}
}

void Player::Draw()
{
	//Top down view
	Vector2 p2d = Vector2(position.x, position.z);
	Vector2 forward = Vector2(rotation.y);

	Graphics::Get().DrawLine(p2d, p2d + (forward * 15), Color(1, 0, 0));
}
