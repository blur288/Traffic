#pragma once
#include <raylib.h>

class Car
{
public:
	struct Position
	{
		float x = 0, y = 0;
	};
	enum Facing
	{
		FORWARD,
		BACKWARD,
		RIGHT,
		LEFT
	};
	enum ExpectedMovement
	{
		TURN_FORWARD,
		TURN_RIGHT,
		TURN_LEFT
	};

	Position Pos;

	//Car Sprites preloaded so we can hotswap on movement
	Texture2D ForwardCarSprite;
	Texture2D BackwardCarSprite;
	Texture2D LeftSideCarSprite;
	Texture2D RightSideCarSprite;

	//Currently loaded car sprite
	Texture2D CarSprite;

	//Movement that we want the car to preform
	ExpectedMovement WantedMovement = ExpectedMovement::TURN_FORWARD;

	//Where car is facing
	Facing Direction = BACKWARD;

	Car();

	void Draw();
	
	void GetInput();
};

