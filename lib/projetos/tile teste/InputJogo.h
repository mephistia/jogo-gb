#pragma once
#include "Mage.h"
#include "Warrior.h"
#include "Thief.h"
#include "myTilemap.h"
#include <fstream>

class InputJogo
{
public:
	InputJogo();
	~InputJogo();

	myTilemap getMap(int i);
	void lerMapa(int i, std::string arq);
	void carregarTiles(std::string arq);


	void iniciaMage(std::string sheet);
	void atualizarMage();
	void desenharMage();

	void iniciaWarrior(std::string sheet);
	void atualizarWarrior();
	void desenharWarrior();

	void iniciaThief(std::string sheet);
	void atualizarThief();
	void desenharThief();

	int getMapaAtual();
	void setMapaAtual(int mapa);

	void selectClass(int i);

	int getClass();

	void setPosInicial0();
	void setPosInicial1();

	void setPosPorta();
	void setFirstMap();


private:
	myTilemap mapa[6];
	int mapaAtual;
	Mage mage;
	Warrior warrior;
	Thief thief;
};

