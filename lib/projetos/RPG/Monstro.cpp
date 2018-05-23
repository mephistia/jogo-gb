#include "Monstro.h"



Monstro::Monstro()
{
}


Monstro::~Monstro()
{
}


void Monstro::inicializarMonstro(string  sheet, int def, int vida)
{
	sprite.setSpriteSheet(sheet);
	sprite.setAnimacao(0, true);
	sprite.setVelocidadeAnimacao(5);

	name = sheet;
	gold = uniRandEntre(100, 800);
	hp = vida;
	atk = uniRandEntre(2, 12);
	this->def = def;
}

void Monstro::atualizarMonstro()
{
	sprite.avancarAnimacao();
	
}

void Monstro::setObj(ObjetoTileMap * objeto)
{
	this->obj = objeto;
	obj->setSprite(&sprite);
}

void Monstro::setPos(float x, float y)
{
	obj->setPos(x, y);
}

ObjetoTileMap Monstro::getObjeto()
{
	return *obj;
}


void Monstro::skill()
{
}

bool Monstro::isSelected()
{
	return false;
}

void Monstro::select()
{
}

void Monstro::unselect()
{
}

Sprite Monstro::getSprite()
{
	return sprite;
}

float Monstro::getX()
{
	return obj->getX();
}

float Monstro::getY()
{
	return obj->getY();
}
