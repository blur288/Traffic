#pragma once
#include <vector>
#include "City/City.h"

class Intersections
{
private:
	struct Position
	{
		int x, y;
	};
	class Intersection
	{
	public:
		enum class IntersectionState
		{
			ForwardAndBack,
			ForwardAndLeft
		};
	public:

		IntersectionState CurrentState = IntersectionState::ForwardAndBack;
		Position Pos;
	};
	class Timer
	{
	private:
		//start time to compare length
		int StartTime = time(0);
		//every interval timer is true
		int Intervals = 5;
		int CurrentTime = time(0);
		//diffrence between start and current time 
		int DiffrenceInTime = 0;
	public:

		bool CheckTime();
	};

	Texture2D OppTrafficArrows;
	Texture2D LeftTurnArrows;
	Timer timer;
public:
	Intersections();

	std::vector<Intersection> IntersectionVector;

	void GetIntersections(std::vector<std::vector<City::Roads>> GridVector);

	void ChangeArrows();

	void DrawArrows();

	void PrintIntersections();
};

