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
	this->caminho = caminho;


	sprite.setSpriteSheet(nome);

	ancoraX = 0.5;
	ancoraY = 0.8;

	sprite.setAncora(ancoraX, ancoraY);

	sprite.setVelocidadeAnimacao(3.5);
	

	

	moving = false;
	isDead = false;
	gold = 0;
	vel = 32.0;
	x = 0;
	y = 0;
	setAtk();
}

int Monster::getId()
{
	return id;
}

std::string Monster::getNome()
{
	return nome;
}

void Monster::setId(int id)
{
	this->id = id;
}

void Monster::setNome(std::string nome)
{
	this->nome = nome;
}

void Monster::movDir(int tile)
{
	if (tile == 1) {
		x += 32;
		sprite.setAnimacao(DIR);
	}
}

void Monster::movEsq(int tile)
{
	if (tile == 1) {
		x -= 32;
		sprite.setAnimacao(ESQ);
	}
}

void Monster::movCima(int tile)
{
	if (tile == 1) {
		y -= 32;
		sprite.setAnimacao(CIMA);
	}
}

void Monster::movBaixo(int tile)
{
	if (tile == 1) {
		y += 32;
		sprite.setAnimacao(BAIXO);
	}
}


std::string Monster::getCaminho()
{
	return caminho;
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

