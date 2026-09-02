#pragma once
class Vector2D
{
	int X = 0;
	int Y = 0;
public:
	Vector2D(int inputX, int inputY) { X = inputX; Y = inputY; };
	~Vector2D() {};

private:

};

enum keyboard
{
	Q,
	W,
	E,
	R,
	T
};

enum Mouse
{
	left,
	Right,
	Wheel
};

enum InputType
{
	Mouse,
	keyboard
};

