#include <iostream>
#include <raylib.h>
#include <vector>
#include "City/City.h"
#include "Intersections.h"
#include "Car.h"

int main()
{
	City Road;

	InitWindow(600, 500, "Traffic");
	Car Test = Car();
	Intersections intersections = Intersections();
	intersections.GetIntersections(Road.Grid);
	while (!WindowShouldClose())
	{
		BeginDrawing();
		ClearBackground(RAYWHITE);

		//Draw city grid
		Road.DrawCity();
		//check for change arrows
		intersections.ChangeArrows();
		//draw arrows
		intersections.DrawArrows();
		//draw car and get input
		Test.Draw();
		Test.GetInput();

		EndDrawing();
	}
}