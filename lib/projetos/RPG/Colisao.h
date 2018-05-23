#pragma once
#include "libUnicornio.h"
#include <string>

using namespace std;

class Colisao
{
public:
	Colisao();
	~Colisao();

	bool testarColisaoPS(float &x, float &y, Sprite &sprite, float &xx, float &yy);
	bool testarColisaoSS(Sprite &sprite, float x, float y, Sprite &sprite2, float xx, float yy);


};

