#pragma once
#include "libUnicornio.h"
#include <string>
#include <ctime>
#include <iostream>

enum Anim
{
	BAIXO,
	ESQ,
	DIR,
	CIMA
};

class Player
{
protected:
	int atk, def, hp, gold, maxHP;
	bool isDead, moving;

	Sprite sprite;
	std::string nomeSpr;
	

	float x, y;
	float vel;
	float ancoraX, ancoraY;



public:
	Player();
	~Player();

// métodos virtuais:

	// habilidade
	virtual void skill() = 0;

	// seleção da classe
	virtual bool isSelected() = 0;
	virtual void select() = 0;
	virtual void unselect() = 0;

// outros métodos:

	// inicializar com sprite
	void inicializar(std::string sheet);

	// posição
	void setPos(float x, float y);

	// atualizar
	void movDir();
	void movEsq();
	void movCima();
	void movBaixo();
	bool estaMovendo();
	void desenhar();

	void setAnimDir();
	void setAnimEsq();
	void setAnimBaixo();
	void setAnimCima();

	// gets
	int getAtk();
	int getDef();
	int getHP();
	int getMaxHP();
	int getGold();
	float getX();
	float getY();
	Sprite getSprite();
	float getAncoraX();
	float getAncoraY();
	

	// sets iniciais por sorteio
	void setAtk();
	void setDef();
	void setHP();

	// sets de itens
	void setMoreAtk(int &atk);
	void setMoreDef(int &def);
	void setMoreHP(int &hp);
	void setMoreMaxHP(int &maxhp);
	void setMoreGold(int &gold);


	std::string getNomeSpr();
	void setSprite(string spr);

};

