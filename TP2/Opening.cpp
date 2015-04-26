#include "Opening.h"

Opening::Opening()
	: Sprite(Texture::ID::OPN, point<int>(0, 0), point<int>(522, 496))
	, currentX(0)
	, currentY(0)
	, currentTime(0)
{
}

Opening::~Opening()
{
}

void Opening::Start()
{
	Sprite::SetPosition(currentX, currentY);
}

void Opening::Update()
{

}

void Opening::Stop()
{
}
