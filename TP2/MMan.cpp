#include "MMan.h"

MMan::MMan()
	: Animation(GIMMICKV2_PATH, IDLE_NB_FRAME(), ANIM_DEFAULT_SPEED, FRAME_SIZE(), IDLE_START_SRC())
	, currentState(IDLE)
	, characterX(20)
	, characterY(167)
{
	SetDstFrame(characterX, characterY, 32, 32);
	//Start the animation on creation
	this->Play();
	//Make it loop
	this->SetIsLooping(true);
}

//Really basic animation state change
void MMan::changeState(state newState)
{
	if (this->currentState != newState)
	{
		switch (newState)
		{
		case IDLE:
			this->SetStartSrcPos(IDLE_START_SRC());
			this->SetNbFrame(IDLE_NB_FRAME());
			break;
		case WALK:
			this->SetStartSrcPos(WALK_START_SRC());
			this->SetNbFrame(WALK_NB_FRAME());
			break;
		case DIZZY:
			this->SetStartSrcPos(DIZZY_START_SRC());
			this->SetNbFrame(DIZZY_NB_FRAME());
			break;
		default:
			break;
		}
		//It's important to reset back to the first frame on change
		this->currentState = newState;
		this->ResetCurrentFrame();
	}
}

void MMan::Update()
{
	//Very important, otherwise our animation won't update itself
	Animation::Update();

	//Don't mind the brackets. Simply tried to save some screen space.
	//Press Space to Pause & Resume
	if (Engine::GetInstance()->GetInput()->IsKeyPressed(SDL_SCANCODE_SPACE)){
		if (this->GetIsPlaying()){
			this->Stop(); }
		else {
			this->Play();}
	}
	//Press 1 for Idle
	if (Engine::GetInstance()->GetInput()->IsKeyPressed(SDL_SCANCODE_1)){
		changeState(IDLE);
	}
	//Press 2 for right
	if (Engine::GetInstance()->GetInput()->IsKeyHeld(SDL_SCANCODE_D)){
		changeState(WALK);
		SetDstFrame((characterX += 1), characterY, 32, 32);
	}
	if (Engine::GetInstance()->GetInput()->IsKeyReleased(SDL_SCANCODE_D)){
		changeState(IDLE);
		SetDstFrame(characterX, characterY, 32, 32);
	}
	//Press A for left
	if (Engine::GetInstance()->GetInput()->IsKeyHeld(SDL_SCANCODE_A)){
		changeState(WALK);
		SetDstFrame((characterX -= 1), characterY, 32, 32);
	}
	if (Engine::GetInstance()->GetInput()->IsKeyReleased(SDL_SCANCODE_A)){
		changeState(IDLE);
		SetDstFrame(characterX, characterY, 32, 32);
	}
	//Press 3 for Dizzy
	if (Engine::GetInstance()->GetInput()->IsKeyPressed(SDL_SCANCODE_3)){
		changeState(DIZZY);
	}

}

MMan::~MMan()
{

}
