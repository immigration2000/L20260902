#pragma once
#include "Object.h"
#include "World.h"


class UEngine : public UObject
{
public:
	UWorld* World = new UWorld();

	void Tick() override;
	void Render() override;
	int Asyncinput();

	UEngine();
	~UEngine();
};

