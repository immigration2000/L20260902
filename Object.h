#pragma once
#include <iostream>
#include "Util.h"

using namespace std;

class UObject
{
public:
	virtual void Tick();
	virtual void Render();
};

