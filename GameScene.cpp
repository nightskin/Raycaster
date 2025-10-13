#include "GameScene.hpp"
#include "Input.hpp"
#include "Graphics.hpp"

GameScene::GameScene()
{
	name = "Game";
	paused = false;
	lvl = Level();
	player = Player();
}

GameScene::~GameScene()
{

}

void GameScene::Load()
{
	lvl.ProcGen();
	player.Load();
	player.position = lvl.GetPositionInMap();
}

void GameScene::Update()
{
	if (Input::Get().keyboard[SDL_SCANCODE_P])
	{
		paused = true;
	}
	else
	{
		paused = false;
	}

	player.Update();
}

void GameScene::Draw()
{
	if (paused)
	{
		player.Draw();
		lvl.DrawTopDown();
	}
	else
	{
		for (int i = -30; i <= 30; i++)
		{
			Vector2 dir = player.GetForward().Rotated(MathHelper::Deg2Rad(-i));
			Line ray = Line(player.position, player.position + dir.Normalized() * 500);

			//Get All hits
			std::vector<Hit2D> hits;
			for (int i = 0; i < lvl.lines.size(); i++)
			{
				Hit2D hit = ray.Intersection(lvl.lines[i]);
				if (hit.exists)
				{
					hits.push_back(hit);
				}
			}

			if (hits.size() > 0)
			{
				Hit2D closest = hits[0];
				// Get The Closest Hit
				for (int i = 1; i < hits.size(); i++)
				{
					float current = closest.hitPoint.Distance(player.position);
					float next = hits[i].hitPoint.Distance(player.position);
					if (current > next) closest = hits[i];
				}
				
				// Draw Walls
				float dist = closest.hitPoint.Distance(player.position);
				//Fix fish eye
				float ra = MathHelper::Rad2Deg(atan2f(dir.y, dir.x));
				float ca = player.rotation - ra;
				if (ca > 360) ca -= 360;
				if (ca < 0) ca += 360;

				dist = dist * cosf(MathHelper::Deg2Rad(ca));

				float height = (600 / dist);
				float width = 800 / 60;

				float shading = 1.0f / dist + 0.25f;
				if (shading > 1) shading = 1;

				Graphics::Get().DrawRect(Vector2((i + 30) * width, 300 - height / 2), Vector2(width, height * 8), Color(shading));
			}
			else
			{
				continue;
			}

		}
	}
}

void GameScene::Unload()
{
	
}
