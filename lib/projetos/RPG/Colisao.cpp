#include "Colisao.h"



Colisao::Colisao()
{
}


Colisao::~Colisao()
{
}

bool Colisao::testarColisaoPS(float & x, float & y, Sprite & sprite, float & xx, float & yy)
{
	return uniTestarColisaoPontoComSprite(x, y, sprite, xx, yy, 0);
}

bool Colisao::testarColisaoSS(Sprite & sprite, float x, float y, Sprite & sprite2, float xx, float yy)
{
	return uniTestarColisao(sprite, x, y, 0, sprite2, xx, yy, 0);
}
