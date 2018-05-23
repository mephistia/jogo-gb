#pragma once
#include "Itens.h"

class Tesouro
{
public:
	Tesouro();
	~Tesouro();
	void setSprite(string sheet);
	void inicializar(string nome, int bonusHP, int bonusDef, int bonusAtk, int id);
	void setGold(int gold);
	void setObj(ObjetoTileMap *obj);
	void setPos(float x, float y);
	int getGold();
	int getIoO();
	void setIoO(int i);
	Itens getItem();
	float getX();
	float getY();

	Sprite getItemSprite();
	ObjetoTileMap getObj();
private:
	Itens item;
	Sprite sprite;
	ObjetoTileMap *obj;
	int gold, itemOuOuro; // ouro = 0, item = 1
};

