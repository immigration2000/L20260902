#pragma once
#include "Actor.h"
class AMonster : public AActor
{
public:
	AMonster();

	virtual ~AMonster();

	void Tick() override;
	void Move();
};

