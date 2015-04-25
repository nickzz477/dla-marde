#include "Ship.h"

Ship::Ship()
	: Sprite(Texture::ID::BKG, point<int>(0,0), point<int>( 522, 496))
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
