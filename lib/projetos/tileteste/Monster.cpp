#include "Monster.h"



Monster::Monster()
{
}


Monster::~Monster()
{
}

void Monster::mInicializar(int id, std::string nome, int def, int hp, std::string caminho)
{
	this->id = id;
	this->nome = nome;
	this->def = def;
	this->hp = hp;
	maxHP = hp;
	sprite.setSpriteSheet(caminho);
}

void Monster::skill()
{
}

bool Monster::isSelected()
{
	return false;
}

void Monster::select()
{
}

void Monster::unselect()
{
}

