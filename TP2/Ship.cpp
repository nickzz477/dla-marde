#include "Ship.h"

Ship::Ship()
	: Sprite("Background.png")
	, currentX(0)
	, currentY(0)
	, currentTime(0)
{
}

Ship::~Ship()
{
}

void Ship::Start()
{
	Sprite::SetPosition(currentX, currentY);
}

void Ship::Update()
{

}

void Ship::Stop()
{
}
