#pragma once
#include "Object.h"
#include "Actor.h"

class UWorld : public UObject
{
public:
	AActor* Actor = new AActor();

	void Tick() override;
	void Render() override;

	UWorld();
	~UWorld();
};

