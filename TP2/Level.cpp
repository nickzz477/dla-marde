#include "Level.h"

Level::Level()
	: Sprite(Texture::ID::BKG, point<int>(0,0), point<int>( 522, 496))
	, currentX(0)
	, currentY(0)
	, currentTime(0)
{
}

Level::~Level()
{
}

void Level::Start()
{
	Sprite::SetPosition(currentX, currentY);
}

void Level::Update()
{

}

void Level::Stop()
{
}
