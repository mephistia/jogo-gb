#include "Itens.h"



Itens::Itens()
{
}


Itens::~Itens()
{
}

void Itens::inicializar(string nome, int bonusAtk, int bonusDef, int bonusHP, int id)
{
	this->nome = nome;
	spr.setSpriteSheet(nome);
	this->bonusAtk = bonusAtk;
	this->bonusDef = bonusDef;
	this->bonusHP = bonusHP;
	this->id = id;
	possui = false;
}

bool Itens::getPossui()
{
	return possui;
}

void Itens::setPossui(bool p)
{
	possui = p;
}

void Itens::setNome(string & nome)
{
	this->nome = nome;
}

void Itens::setBonusAtk(int & atk)
{
	bonusAtk = atk;
}

void Itens::setBonusDef(int def)
{
	bonusDef = def;
}

void Itens::setBonusHP(int & HP)
{
	bonusHP = HP;
}

void Itens::setID(int & id)
{
	this->id = id;
}

Sprite Itens::getSprite()
{
	return spr;
}

string Itens::getNome()
{
	return nome;
}

int Itens::getBonusAtk()
{
	return bonusAtk;
}

int Itens::getBonusDef()
{
	return bonusDef;
}

int Itens::getBonusHP()
{
	return bonusHP;
}

int Itens::getID()
{
	return id;
}
