#include "Car.h"
void Car::Draw()
{
	if (Direction == FORWARD)
	{
		DrawTextureEx(CarSprite, { (float)Pos.x, (float)Pos.y }, 0, 0.05, WHITE);
	}
	if (Direction == BACKWARD)
	{
		DrawTextureEx(CarSprite, { (float)Pos.x, (float)Pos.y }, 0, 0.05, WHITE);
	}
	if (Direction == RIGHT)
	{
		DrawTextureEx(CarSprite, { (float)Pos.x, (float)Pos.y }, 0, 0.05, WHITE);
	}
	if (Direction == LEFT)
	{
		DrawTextureEx(CarSprite, { (float)Pos.x, (float)Pos.y }, 0, 0.05, WHITE);
	}
}

void Car::GetInput()
{
	if (IsKeyDown(KEY_W))
	{
		Pos.y -= 100 * GetFrameTime();
		CarSprite = ForwardCarSprite;
		Direction = FORWARD;
	}
	if (IsKeyDown(KEY_A))
	{
		Pos.x -= 100 * GetFrameTime();
		CarSprite = LeftSideCarSprite;
		Direction = LEFT;
	}
	if (IsKeyDown(KEY_S))
	{
		Pos.y += 100 * GetFrameTime();
		CarSprite = BackwardCarSprite;
		Direction = BACKWARD;
	}
	if (IsKeyDown(KEY_D))
	{
		Pos.x += 100 * GetFrameTime();
		CarSprite = RightSideCarSprite;
		Direction = RIGHT;
	}
}

Car::Car()
{
	ForwardCarSprite = LoadTexture("img\\car.png");
	BackwardCarSprite = LoadTexture("img\\car2.png");
	LeftSideCarSprite = LoadTexture("img\\car4.png");
	RightSideCarSprite = LoadTexture("img\\car3.png");

	CarSprite = BackwardCarSprite;

	Pos.x = 100;
	Pos.y = 0;
}