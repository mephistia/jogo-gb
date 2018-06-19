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

	void lerItens(std::string arq);

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
	bool &isPorta(int x, int y);

	void setChests(int rx, int ry);
	void setOpenChest(int rx, int ry);


	bool isSolid(int x, int y);
	bool isMonster(int x, int y);

	Sprite getPlayerSprite();
	int getPlayerX();
	int getPlayerY();

	Sprite getSpriteBau();

	void desenhar();
	
	void atualizar();
	void atualizarBag();

	int getPlayerHP();
	int getPlayerMaxHP();
	int getPlayerDef();
	int getPlayerAtk();
	int getPlayerGold();

	void setPlayerGold(int gold);

	// inventario
	void addItem(int tipo);
	void deleteItem(int id);
	void desenharItens();

	int getTotalItens();
	
	void addBonusItem(int bonusHP, int bonusMaxHP, int bonusDef, int bonusAtk);

	// posição
	bool podePosicionar(int x, int y);

	// batalha
	void atualizarBatalha();

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
	int *i_def, *i_hp, *i_maxhp, *i_atk;
	std::string *i_nome;
	std::string *i_caminho;
	int totalItens;

	Itens *bag;

	// itens que o jogador pegou
	int playerItens;

	Lista<Itens>lista;
};

