#pragma once
class Vector2D
{
	int X = 0;
	int Y = 0;
public:
	Vector2D(int inputX, int inputY) { X = inputX; Y = inputY; };
	virtual ~Vector2D() {};

	

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

struct FVector2D
{
public:
	FVector2D();
	FVector2D(int inX, int inY);
	FVector2D(FVector2D* RHS);
	virtual ~FVector2D();

	FVector2D operator+(const FVector2D& RHS) const;

	int X;
	int Y;
};