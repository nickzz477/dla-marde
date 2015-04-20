#include "Common.h"
#include "Ship.h"
#include "MMan.h"
#include "ResourceIDs.h"


int main(int argc, char* args[])
{
	Engine::GetInstance()->Init(800, 600);

	Textures->LoadTexture(Texture::ID::BKG, "Background.png");
	Textures->LoadTexture(Texture::ID::MMan, "MMAN.png");

	Ship* ship = new Ship();
	MMan* megaman = new MMan();

	// L'engin vire
	Engine::GetInstance()->Run();

	delete ship;
	delete megaman;

	return 0;
}