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
	, dir(1)
{
	BBs::pool = new Pool<BBs>(10);
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

void BBMan::Jump(const bool flipped, const float dt)
{
	changeState(JUMP);
	if (currentY == characterY)
	{
		isJumping = true;
	}
	verticalVelocity += gravity * dt;
	
	if (isJumping)
	{
		verticalVelocity -= jump * dt;
	}
	if (currentY + verticalVelocity >= characterY && verticalVelocity > 0)
	{
		verticalVelocity = 0;
		currentY = characterY;
	}
	if (currentY + verticalVelocity <= 200 && verticalVelocity < 0)
	{
		verticalVelocity = 0;
		currentY = 200;
		isJumping = false;
	}
	currentY += verticalVelocity;
}

void BBMan::Move(const bool flipped, const float dt)
{
	//does not work
	changeState(WALK);
	
	currentX -= dir * 500 * dt;

	
	
	if (currentX <= 25)
	{
		dir = -1;
		currentX += 500 * dt;
		Flip(1);
		this->flipped = true;
	}
	else if (currentX >= 425)
	{
		dir = 1;
		currentX -= 500 * dt;
		Flip(0);
		this->flipped = false;
	}
	
}

void BBMan::Shoot(const bool flipped)
{
	BBs* bb = nullptr;
	bb = bb->pool->NewInstance();
	bb->Init(currentX + 32, currentY + 24, false);
	bb->isShot = true;
	bb->flipped = flipped;
}

void BBMan::Pattern(bool flipped, const float dt, BBs* BB)
{
	//does not work
}

void BBMan::ReversePattern(bool flipped, const float dt, BBs* BB)
{
	//does not work
}

void BBMan::Update()
{
	Animation::Update();

	float dt = Engine::GetInstance()->GetTimer()->GetDeltaTime();
	currenTime += dt;
	
	Jump(flipped, dt);

	if (currenTime > 1.f)
	{
		Shoot(flipped); // works only once?? // Doesn't work anymore fuck that
		currenTime = 0;
	}

	Move(flipped, dt);

	SetPosition((int)currentX, (int)currentY);
}

BBMan::~BBMan()
{

}
