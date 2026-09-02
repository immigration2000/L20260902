#include "Engine.h"

UEngine::UEngine()
{
	cout << "Call UEngine Create" << endl;
}

UEngine::~UEngine()
{
	cout << "Call UEngine Delete" << endl;
	delete World;
	World = nullptr;
}


void UEngine::Tick()
{
	cout << "Call UEngine Tick" << endl;
	World->Tick();
}

void UEngine::Render()
{
	cout << "Call UEngine Render" << endl;
	World->Render();
}

int UEngine::Asyncinput()
{
	return 0;
}
