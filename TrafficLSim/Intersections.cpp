#include "Intersections.h"

bool Intersections::Timer::CheckTime()
{
	CurrentTime = time(0);
	DiffrenceInTime = CurrentTime - StartTime;

	if (DiffrenceInTime >= Intervals)
	{
		StartTime = time(0);
		return true;
	}
	return false;
}

Intersections::Intersections()
{
	std::cout << "TEST\nTEST";
	LeftTurnArrows = LoadTexture("img\\TrafficSymbols\\LeftTurn.png");
	OppTrafficArrows = LoadTexture("img\\TrafficSymbols\\OppDirections.png");
}

void Intersections::ChangeArrows()
{
	if (timer.CheckTime())
	{
		for (int i = 0; i < IntersectionVector.size(); i++)
		{
			if (IntersectionVector[i].CurrentState == Intersection::IntersectionState::ForwardAndBack)
			{
				IntersectionVector[i].CurrentState = Intersection::IntersectionState::ForwardAndLeft;
			}
			else
			{
				IntersectionVector[i].CurrentState = Intersection::IntersectionState::ForwardAndBack;
			}
		}
	}
}

void Intersections::DrawArrows()
{
	for (int i = 0; i < IntersectionVector.size(); i++)
	{
		if (IntersectionVector[i].CurrentState == Intersection::IntersectionState::ForwardAndBack)
		{
			DrawTexture(OppTrafficArrows, IntersectionVector[i].Pos.x * 100, IntersectionVector[i].Pos.y * 100, WHITE);
		}
		else
		{
			DrawTexture(LeftTurnArrows, IntersectionVector[i].Pos.x * 100, IntersectionVector[i].Pos.y * 100, WHITE);
		}
	}
}

void Intersections::GetIntersections(std::vector<std::vector<City::Roads>> GridVector)
{
	for (int i = 0; i < 6; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			if (GridVector[j][i] == City::INTERSECTION)
			{
				Intersection Temp;
				Temp.Pos = { i,j };
				IntersectionVector.push_back(Temp);
			}
		}
	}
}

void Intersections::PrintIntersections()
{
	for (int i = 0; i < IntersectionVector.size(); i++)
	{
		std::cout << IntersectionVector[i].Pos.x << " " << IntersectionVector[i].Pos.y << "\n";
	}
}