#pragma once

#include "Common.h"
#include "Sprite.h"
#include "ResourceIDs.h"
#include "Pool.h"

class Lemons :
	public Sprite
{
public:
	Lemons();
	~Lemons();

	void Start();
	void Update();
	void Stop();

	void Init(const float shootPositionX, const float shootPositionY, const bool isReverse);

	

protected:

	//float currentX, currentY;
	//bool isShot;

private:
	
	float currentTime;
	float isReverse;
	

	const float SPEED;
};

