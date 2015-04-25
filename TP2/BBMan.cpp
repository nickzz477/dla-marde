#include "BBMan.h"
// TO DO
BBMan::BBMan()
: Animation(Texture::ID::BBMan, IDLE_NB_FRAME(), ANIM_DEFAULT_SPEED, FRAME_SIZE(), IDLE_START_SRC())
, currentState(IDLE)
{
	//Start the animation on creation
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
		case DIZZY:
			this->SetSrcPos(DIZZY_START_SRC());
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

void BBMan::Update()
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
	//Press 2 for Walk
	if (Engine::GetInstance()->GetInput()->IsKeyPressed(SDL_SCANCODE_2)){
		changeState(WALK);
	}
	//Press 3 for Dizzy
	if (Engine::GetInstance()->GetInput()->IsKeyPressed(SDL_SCANCODE_3)){
		changeState(DIZZY);
	}

}

BBMan::~BBMan()
{

}
