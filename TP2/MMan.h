#pragma once
//Second & slightly more complex iteration.
//There's a billion way to handle this but with only 3 animations this works just fine for our current purpose.
//Might want to consider another way to stock animations if you end up with 6-7 animations per actors.

#define GIMMICKV2_PATH "MMAN.png" //2x Original size

#include "Common.h"
#include "Animation.h"

class MMan:
	public Animation
{
public:
	MMan();
	~MMan();

	void Update();

private:
	int characterX, characterY;

	//States used to determine which animation will take place 
	enum state { IDLE, WALK, DIZZY };
	state currentState;

	//State Setter
	void changeState(state newState);

	//This part is ugly, but at least we can use those "fake consts" in our constructor...
	const int IDLE_NB_FRAME() { return 2; }
	const int WALK_NB_FRAME() { return 3; }
	const int DIZZY_NB_FRAME() { return 2; }
	const point<int> FRAME_SIZE() { return{ 32, 32 }; };
	const point<int> IDLE_START_SRC() { return{0, 0 }; };
	const point<int> WALK_START_SRC() { return{ 64, 0 }; };
	const point<int> DIZZY_START_SRC() { return{ 2, 202 }; };
};

