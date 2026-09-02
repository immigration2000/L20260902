#include "World.h"

UWorld::UWorld()
{
	cout << "Call UWorld Create" << endl;
}

UWorld::~UWorld()
{
	cout << "Call UWorld Delete" << endl;
	delete Actor;
	Actor = nullptr;
}

void UWorld::Tick()
{
	cout << "Call UWorld Tick" << endl;
	Actor->Tick();
}

void UWorld::Render()
{
	cout << "Call UWorld Render" << endl;
	Actor->Render();
}


