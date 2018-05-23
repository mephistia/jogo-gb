#pragma once
#include "Personagem.h"
class Monstro : public Personagem

{
public:
	Monstro();
	~Monstro();

	void inicializarMonstro(string sheet, int def, int vida);
	void atualizarMonstro();
	void setObj(ObjetoTileMap *objeto);
	void setPos(float x, float y);

	ObjetoTileMap getObjeto();

	void skill();
	bool isSelected();
	void select();
	void unselect();

	Sprite getSprite();
	float getX();
	float getY();
private:
	Sprite sprite;
	ObjetoTileMap* obj;


};

