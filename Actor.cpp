#include "Actor.h"

AActor::AActor()
{
	cout << "Call AActor Create" << endl;
}

AActor::~AActor()
{
	cout << "Call AActor Delete" << endl;
}

void AActor::Tick()
{
	cout << "Call AActor Tick" << endl;
}

void AActor::Render()
{
	cout << "Call AActor Render" << endl;
}


