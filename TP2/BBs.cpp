#include "BBs.h"



BBs::BBs()
	: Sprite(Texture::ID::BBS, point<int>(0, 0), point<int>(14, 14))
	, SPEED(1000.0f)
	, flipped(false)
{

	Scale(2);
	isShot = false;
}

void BBs::Init(const float shootPositionX, const float shootPositionY, const bool isReverse)
{
	currentX = shootPositionX;
	currentY = shootPositionY;
	currentTime = 0;
	this->isReverse = isReverse;
	isVisible = true;

	SetPosition(currentX, currentY);
}

BBs::~BBs()
{
}

void BBs::Start()
{

}

void BBs::Update()
{
	float dt = Engine::GetInstance()->GetTimer()->GetDeltaTime();


	if (isShot && flipped)
	{
		currentX += SPEED*dt;
		SetPosition(currentX, currentY);
	}
	else if (isShot && !flipped)
	{
		currentX -= SPEED*dt;
		SetPosition(currentX, currentY);
	}
	if (this->currentX >= 450 || this->currentX <= 25)
	{
		pool->FreeInstance(this);
		isVisible = false;
	}

}

void BBs::Stop()
{
}
