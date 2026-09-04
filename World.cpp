#include "World.h"
#include "Actor.h"
#include "Vector2D.h"

UWorld::UWorld()
{
}

UWorld::~UWorld()
{
}

void UWorld::Tick()
{
	for (auto Actor : Actors)
	{
		Actor->Tick();
	}

}

void UWorld::Render()
{
	for (auto Actor : Actors)
	{
		Actor->Render();
	}

}

bool UWorld::CheckCollision(FVector2D pos)
{
	for (auto actor : Actors)
	{
		if (actor->Location == pos && actor->bIsCollisionEnable)
		{
			return true;
		}
	}
	return false;
}



