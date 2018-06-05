#pragma once
#include "Mage.h"
#include "myTilemap.h"

class InputJogo
{
public:
	InputJogo();
	~InputJogo();

	myTilemap getMap(int i);
	void lerMapa(int i, std::string arq);

	void iniciaMage(std::string sheet);
	void atualizarMage();
	void desenharMage();

	int getMapaAtual();
	void setMapaAtual(int mapa);

	void selectClass(int i);



private:
	myTilemap mapa[6];
	int mapaAtual;
	Mage mage;
};

