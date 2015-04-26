	//this is the boss
	//normally, i want him to shoot three times,
	//jump once and then move the to other corner of the room,
	//reverse and start again

	//first, create a pool for his bullets

#include "BBMan.h"

BBMan::BBMan()
	: Animation(Texture::ID::BBMan, IDLE_NB_FRAME(), FRAME_RATE, IDLE_START_SRC(), FRAME_SIZE())
	, currentState(IDLE)
	, currentX(0)
	, currentY(characterY)
	, currenTime(0)
	, characterX(425)
	, characterY(334)
	, flipped(false)
	, isJumping(true)
	, gravity(1.0f)
	, jump(1.7f)
	, verticalVelocity(0)
{
	BBs::pool = new Pool<BBs>(30);
	Scale(2);
	SetDstFrame(characterX, characterY, 64, 64);
	currentX = characterX;
	currentY = characterY;
	////Start the animation on creation
	this->Play();
	//Make it loop
	this->SetIsLooping(true);
}

//Really basic animation state change
void BBMan::changeState(state newState)
{
	if (this->currentState != newState)
	{
		switch (newState)
		{
		case IDLE:
			this->SetSrcPos(IDLE_START_SRC());
			this->SetNbFrame(IDLE_NB_FRAME());
			break;
		case WALK:
			this->SetSrcPos(WALK_START_SRC());
			this->SetNbFrame(WALK_NB_FRAME());
			break;
		case JUMP:
			this->SetSrcPos(JUMP_START_SRC());
			this->SetNbFrame(JUMP_NB_FRAME());
			break;
		default:
			break;
		}
		//It's important to reset back to the first frame on change
		this->currentState = newState;
		this->ResetCurrentFrame();
	}
}

void BBMan::Update()
{
	float dt = Engine::GetInstance()->GetTimer()->GetDeltaTime();

	//Very important, otherwise our animation won't update itself
	Animation::Update();

#pragma region JUMP
//	verticalVelocity += gravity * dt;
//
//	if (isJumping)
//	{
//		verticalVelocity -= jump * dt;
//	}
//	if (currentY + verticalVelocity >= characterY && verticalVelocity > 0)
//	{
//		verticalVelocity = 0;
//		currentY = characterY;
//	}
//	if (currentY + verticalVelocity <= 200 && verticalVelocity < 0)
//	{
//		verticalVelocity = 0;
//		currentY = 200;
//		isJumping = false;
//	}
//	currentY += verticalVelocity;
#pragma endregion

//	BBs* BB = nullptr;
//	//press N to shoot
//	if (Engine::GetInstance()->GetInput()->IsKeyPressed(SDL_SCANCODE_N))
//	{
//		BB = BB->pool->NewInstance();
//		BB->Init(currentX + 32, currentY + 24, false);
//		BB->isShot = true;
//		BB->flipped = flipped;
//
//	}
//
//	//press space to jump
//	if (Engine::GetInstance()->GetInput()->IsKeyPressed(SDL_SCANCODE_SPACE))
//	{
//		changeState(JUMP);
//		if (currentY == characterY)
//		{
//			isJumping = true;
//		}
//	}
//	//Jump released
//	if (Engine::GetInstance()->GetInput()->IsKeyReleased(SDL_SCANCODE_SPACE))
//	{
//		isJumping = false;
//	}
//	//Press D for right
//	if (Engine::GetInstance()->GetInput()->IsKeyHeld(SDL_SCANCODE_D))
//	{
//		changeState(WALK);
//		if (!flipped)
//		{
//			Flip(1);
//			flipped = true;
//		}
//
//		currentX += 250 * dt;
//	}
//	if (Engine::GetInstance()->GetInput()->IsKeyReleased(SDL_SCANCODE_D))
//	{
//		changeState(IDLE);
//	}
//	//Press A for left
//	if (Engine::GetInstance()->GetInput()->IsKeyHeld(SDL_SCANCODE_A))
//	{
//		changeState(WALK);
//		if (flipped)
//		{
//			Flip(0);
//			flipped = false;
//		}
//		currentX -= 250 * dt;
//
//	}
//	if (Engine::GetInstance()->GetInput()->IsKeyReleased(SDL_SCANCODE_A))
//	{
//		changeState(IDLE);
//	}
//
	SetPosition((int)currentX, (int)currentY);
}

BBMan::~BBMan()
{

}
