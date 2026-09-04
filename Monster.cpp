#include "Monster.h"
#include "SystemLibrary.h"

AMonster::AMonster()
{
	Shape = 'M';
	Layer = 120;
	bIsCollisionEnable = false;
	srand((unsigned int)time(NULL));
}

AMonster::~AMonster()
{

}

void AMonster::Tick()
{
	bool Moveing = rand() % 10;
	if (!Moveing)
	{
		Move();
	}

}

void AMonster::Move()
{
	int rot = rand() % 4;
	std::vector<AActor*> CollideActors;
	if (rot == 0)
	{
		Location.X++;
		if (USystemLibrary::CheckCollide(GetWorld(), this, CollideActors))
		{
			Location.X--;
		}
	}
	if (rot == 1)
	{
		Location.X--;
		if (USystemLibrary::CheckCollide(GetWorld(), this, CollideActors))
		{
			Location.X++;
		}
	}
	if (rot == 2)
	{
		Location.Y++;
		if (USystemLibrary::CheckCollide(GetWorld(), this, CollideActors))
		{
			Location.Y--;
		}
	}
	if (rot == 3)
	{
		Location.Y--;
		if (USystemLibrary::CheckCollide(GetWorld(), this, CollideActors))
		{
			Location.Y++;
		}
	}
}
