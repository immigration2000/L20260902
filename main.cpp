#include <iostream>
#include "Engine.h"

using namespace std;

int main()
{
	bool EnableEngine = true;
	UEngine* Engine = new UEngine;
	while (EnableEngine)
	{
		Engine->Tick();
		Engine->Render();
		
	}

	delete Engine;
	Engine = nullptr;
	return 0;
}