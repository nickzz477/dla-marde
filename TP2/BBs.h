#pragma once

#include "Common.h"
#include "Sprite.h"
#include "ResourceIDs.h"
#include "PoolObject.h"


class BBs :
	public Sprite, public PoolObject<BBs>
{
public:
	BBs();
	~BBs();

	void Start();
	void Update();
	void Stop();

	void Init(const float shootPositionX, const float shootPositionY, const bool isReverse);
	float currentX, currentY;
	bool isShot;
	bool flipped;


protected:



private:

	float currentTime;
	float isReverse;


	const float SPEED;
};

