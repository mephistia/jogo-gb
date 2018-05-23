#pragma once
#include <ctime>
#include "Mage.h"
#include "Warrior.h"
#include "Thief.h"
#include "Monstro.h"
#include "TipoMonstro.h"
#include "TipoItem.h"
#include "Tesouro.h"
#include "Bag.h"
#include <fstream>
#include "libUnicornio.h"

enum idTelas {
	T_SELECT,
	T_JOGO,
	T_MOCHILA
};
class Jogo
{
public:
	Jogo();
	~Jogo();

	void inicializar();
	void finalizar();

	void executar();

	void atualizarInputMage(); // atualizar inputs para cada classe diferente no executar
	void atualizarInputWarrior();
	void atualizarInputThief();
	void telaSelect();
	void telaJogo();

	void lerMonstros();
	void lerItens();
	void setarMonstros();
	void setarItens();

	void testarColisao();
	void testarColisaoBaus();
	void telaMochila();

private:
	TileMap mapa, mapa2, mapa3, mapa4, mapa5, mapa6;
	Mage *mage;
	Warrior *warrior;
	Thief *thief;
	BotaoSprite btn1, btn2, btn3;
	Sprite fundoSelect, fundoInventario;
	int idTelas;
	int randMapa;

	Texto texto;

	int nMonstrosLidos, monstrosNaSala;
	Monstro *monstro;
	TipoMonstro *tipo;

	Sprite playerSpr;
	float playerX, playerY, playerDef;
	bool colidiu;

	// flag para conferir se o monstro já atacou:
	bool mAtacou;

	int newHP;

	// tempo
	time_t start, end;
	double tempo;

	// flag de game over
	bool gameover;

	// itens
	TipoItem *tipoI;
	Tesouro *tesouros;
	Bag mochila;
	int tesourosNaSala, qtdItens, sortear;
	Sprite Cristal, Presa, Pedra, Pergaminho, bauAberto, bauFechado;
	Texto texto1, texto2, texto3, texto4, texto5, texto6, texto7, texto8, texto9, texto10;
};

