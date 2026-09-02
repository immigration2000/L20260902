#pragma once
#include "Object.h"

class AActor : public UObject
{
public:
	Vector2D Location = Vector2D(0, 0);

	virtual void Tick() override;
	virtual void Render() override;

	AActor();
	~AActor();
};

