#include "Common.h"
#include "Level.h"
#include "MMan.h"
#include "BBMan.h"
#include "ResourceIDs.h"


int main(int argc, char* args[])
{
	Engine::GetInstance()->Init(800, 600);

	Textures->LoadTexture(Texture::ID::BKG, "Background.png");
	Textures->LoadTexture(Texture::ID::BBMan, "BBManSprite.png");
	Textures->LoadTexture(Texture::ID::MMan, "MMAN.png");
	Textures->LoadTexture(Texture::ID::LMNS, "Lemons.png");

	Level* level = new Level();
	BBMan* bubbleman = new BBMan;
	MMan* megaman = new MMan();

	// L'engin vire
	Engine::GetInstance()->Run();

	
	delete level;
	delete bubbleman;
	delete megaman;

	return 0;
}