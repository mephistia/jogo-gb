#include "TipoMonstro.h"



TipoMonstro::TipoMonstro()
{
}


TipoMonstro::~TipoMonstro()
{
}

int TipoMonstro::getID()
{
	return id;
}

int TipoMonstro::getVida()
{
	return vida;
}

int TipoMonstro::getDefesa()
{
	return defesa;
}

string TipoMonstro::getNome()
{
	return nome;
}

string TipoMonstro::getCaminho()
{
	return caminho;
}

void TipoMonstro::setID(int & id)
{
	this->id = id;
}

void TipoMonstro::setVida(int & vida)
{
	this->vida = vida;
}

void TipoMonstro::setDefesa(int & defesa)
{
	this->defesa = defesa;
}

void TipoMonstro::setNome(string & nome)
{
	this->nome = nome;
}

void TipoMonstro::setCaminho(string & caminho)
{
	this->caminho = caminho;
}
