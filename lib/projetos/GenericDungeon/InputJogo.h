#pragma once
#include "Mage.h"
#include "Warrior.h"
#include "Thief.h"
#include "myTilemap.h"
#include "Monster.h"
#include "Lista.h"
#include "Itens.h"
#include "Pilha.h"
#include <fstream>
#include <time.h>



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


	void desenharMonstros();

	int getMapaAtual();
	void setMapaAtual(int mapa);

	void selectClass(int i);

	int getClass();

	void setPosInicial0();
	void setPosInicial1();
	void setPosInicial2();
	void setPosInicial3();
	void setPosInicial4();
	void setPosInicial5();

	void setPosVolta0();
	void setPosVolta1();
	void setPosVolta2();
	void setPosVolta3();
	void setPosVolta4();
	void setPosVolta5();



	void setPosPorta();
	bool &isPorta(int x, int y);




	bool isSolid(int x, int y);
	bool isMonster(int x, int y);

	Sprite getPlayerSprite();
	int getPlayerX();
	int getPlayerY();


	void desenhar();
	
	void atualizar();
	void atualizarBag();

	int getPlayerHP();
	int getPlayerMaxHP();
	int getPlayerDef();
	int getPlayerAtk();
	int getPlayerGold();

	void setPlayerGold(int gold);
	void setPlayerHP(int hp);
	

	// inventario
	void addItem(int tipo);
	void deleteItem(int id);
	void desenharItens();

	
	void addBonusItem(int bonusHP, int bonusMaxHP, int bonusDef, int bonusAtk);

	// posição

	// batalha
	void atualizarBatalha();

	// zerar 
	void newBag();
	void unselectAll();

	void mapaInicial();



	void moveMonster(int i);

	void save(std::string nomeArq);
	void carregar(string nomeArq);

	std::string getNomeSpr(int i);


	void testarColisoes();


	myTilemap getSala(int i);
	void lerMapaParaSala(int i, string arq);

	Mage* getMage();
	Warrior* getWarrior();
	Thief* getThief();

private:
	myTilemap mapa[6]; // tipo do mapa
	myTilemap sala[15]; // mapas para adicionar na pilha
	//Pilha<myTilemap> pilhaa; // adicionar o id da sala criada na pilha de fora


	//myTilemap *mapa;
	int mapaAtual, nMonstros, nMapas; // mapas no total do jogo
	Mage mage;
	Warrior warrior;
	Thief thief;

	
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

