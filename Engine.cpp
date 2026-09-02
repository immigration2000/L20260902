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

char UEngine::Asyncinput(char input)
{
	switch (input)
	{
	case InputType::keyboard :
		return input;
		break;
	case InputType::Mouse :
		return input;
		break;

	default:
		break;
	}
	return 0;
}
