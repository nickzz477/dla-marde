#include "Opening.h"

Opening::Opening()
	: Sprite(Texture::ID::OPN, point<int>(0, 0), point<int>(1024, 768))
	, currentX(0)
	, currentY(0)
	, currentTime(0)
{
	ResizeTo(522, 496);
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
	if (Engine::GetInstance()->GetInput()->IsKeyPressed(SDL_SCANCODE_RETURN))
	{
		isVisible = false;
	}
}

void Opening::Stop()
{
}
