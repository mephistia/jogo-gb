#pragma once
#include "Mage.h"
#include "Warrior.h"
#include "Thief.h"
#include "myTilemap.h"
#include "Monster.h"
#include "Lista.h"
#include "Itens.h"
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

	void lerMonstros(std::string arq);
	void iniciaMonstros(int n);
	void atualizarMonstros();
	void desenharMonstros();

	int getMapaAtual();
	void setMapaAtual(int mapa);

	void selectClass(int i);

	int getClass();

	void setPosInicial0();
	void setPosInicial1();

	void setPosPorta();
	void setFirstMap();

	void setChests(int rx, int ry);
	void setOpenChest(int rx, int ry);


	bool isSolid(int &x, int &y);

	Sprite getPlayerSprite();
	int getPlayerX();
	int getPlayerY();

	Sprite getSpriteBau();

	void desenhar();
	void atualizar();

	int getPlayerHP();
	int getPlayerMaxHP();
	int getPlayerDef();
	int getPlayerAtk();
	int getPlayerGold();

	void setPlayerGold(int gold);


private:
	myTilemap mapa[6];
	int mapaAtual, nMonstros;
	Mage mage;
	Warrior warrior;
	Thief thief;

	// array dos monstros
	int *m_id, *m_def, *m_hp;
	std::string *m_nome;
	std::string *m_sheet;

	// array dos itens
	int *i_id, i_def, i_hp, i_maxp, i_atk;
	std::string *i_nome;
	std::string *i_caminho;
};

