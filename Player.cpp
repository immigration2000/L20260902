#include "Player.h"
#include "Engine.h"
#include "InputDevice.h"
#include "World.h"

APlayer::APlayer()
{
	Shape = 'P';
	Layer = 100;
}

APlayer::~APlayer()
{
}

void APlayer::Tick()
{
	int KeyCode = GEngine->GetInputDevice()->GetKeyCode();
	if (KeyCode == 'w')
	{
		if (GEngine->GetWorld()->CheckCollision(FVector2D(Location.X, Location.Y - 1))) return;
		Location.Y--;
	}
	if (KeyCode == 's')
	{
		if (GEngine->GetWorld()->CheckCollision(FVector2D(Location.X, Location.Y + 1))) return;
		Location.Y++;
	}
	if (KeyCode == 'a')
	{
		if (GEngine->GetWorld()->CheckCollision(FVector2D(Location.X - 1, Location.Y))) return;
		Location.X--;
	}
	if (KeyCode == 'd')
	{
		if (GEngine->GetWorld()->CheckCollision(FVector2D(Location.X + 1, Location.Y))) return;
		Location.X++;
	}
}
