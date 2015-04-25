#include "Lemons.h"



Lemons::Lemons()
	: Sprite(Texture::ID::LMNS, point<int>(0, 0), point<int>(8, 7))
	, SPEED(1000.0f)
{
	
	Scale(2);
	isShot = false;
}

void Lemons::Init(const float shootPositionX, const float shootPositionY, const bool isReverse)
{
	currentX = shootPositionX;
	currentY = shootPositionY;
	currentTime = 0;
	this->isReverse = isReverse;
	isVisible = true;

	SetPosition(currentX, currentY);
}

Lemons::~Lemons()
{
}

void Lemons::Start()
{
	
}

void Lemons::Update()
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
	if (this->currentX >= 450)
	{
		pool->FreeInstance(this);
		isVisible = false;
	}
	
}

void Lemons::Stop()
{
}
