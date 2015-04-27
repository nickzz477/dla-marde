#pragma once

#include "Common.h"
#include "Sprite.h"
#include "ResourceIDs.h"

class Opening :
	public Sprite
{
public:
	Opening();
	~Opening();

	void Start();
	void Update();
	void Stop();

private:
	float currentX, currentY;
	float currentTime;

	static const float SPEED;
};

