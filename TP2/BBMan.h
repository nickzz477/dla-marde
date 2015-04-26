#pragma once
//Second & slightly more complex iteration.
//There's a billion way to handle this but with only 3 animations this works just fine for our current purpose.
//Might want to consider another way to stock animations if you end up with 6-7 animations per actors.

#include "Common.h"
#include "Animation.h"
#include "ResourceIDs.h"
#include "BBs.h"
#define FRAME_RATE 8

class BBMan :
	public Animation
{
public:
	BBMan();
	~BBMan();

	void Update();
	void Jump(const bool flipped, const float dt);
	void Move(const bool flipped, const float dt);
	void Shoot(bool flipped, const float dt, BBs* BB);
	void Pattern(bool flipped, const float dt, BBs* BB);
	void ReversePattern(bool flipped, const float dt, BBs* BB);
private:
	int characterX, characterY;

	//States used to determine which animation will take place 
	enum state { IDLE, WALK, JUMP, SHOT };
	state currentState;
	float currentX, currentY, gravity, jump, verticalVelocity;
	float currenTime;
	bool flipped, isJumping;

	//State Setter
	void changeState(state newState);

	//This part is ugly, but at least we can use those "fake consts" in our constructor...
	const int IDLE_NB_FRAME() { return 1; }
	const int WALK_NB_FRAME() { return 1; }
	const int JUMP_NB_FRAME() { return 1; }
	const int SHOT_NB_FRAME() { return 1; }
	const point<int> FRAME_SIZE() { return{ 32, 32 }; };
	const point<int> IDLE_START_SRC() { return{ 0, 0 }; };
	const point<int> WALK_START_SRC() { return{ 64, 0 }; };
	const point<int> JUMP_START_SRC() { return{ 96, 0 }; };
	const point<int> SHOT_START_SRC() { return{ 32, 0 }; };
};