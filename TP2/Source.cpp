#include "Common.h"
#include "Level.h"
#include "MMan.h"
#include "BBMan.h"
#include "ResourceIDs.h"
#include "Opening.h"


int main(int argc, char* args[])
{
	bool gamemode = false;
	Engine::GetInstance()->Init(522, 496);

	Textures->LoadTexture(Texture::ID::BKG, "Background.png");
	Textures->LoadTexture(Texture::ID::OPN, "titlescreen.jpg");
	Textures->LoadTexture(Texture::ID::BBMan, "BBManSprite.png");
	Textures->LoadTexture(Texture::ID::MMan, "MMAN.png");
	Textures->LoadTexture(Texture::ID::LMNS, "Lemons.png");
	Textures->LoadTexture(Texture::ID::BBS, "Bubble.png");


	Level* level = new Level();
	BBMan* bubbleman = new BBMan;
	MMan* megaman = new MMan();
	Opening* opening = new Opening();
	// L'engin vire
	Engine::GetInstance()->Run();
	
	delete level;
	delete bubbleman;
	delete megaman;
	delete opening;

	return 0;
}