#pragma once

#include "Common.h"
#include "Sprite.h"
#include "ResourceIDs.h"

class Level :
	public Sprite
{
public:
	Level();
	~Level();

	void Start();
	void Update();
	void Stop();

private:
	float currentX, currentY;
	float currentTime;

	static const float SPEED;
};

