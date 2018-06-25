#pragma once
#include "libUnicornio.h"
#include "InputJogo.h"
#include "gTexto.h"
#include "Pilha.h"

enum idTelas {

	telaMenu,
	telaRanking,
	telaCreditos,
	telaCarregar,
	telaJogo,
	telaSelect, 
	telaGO,
	telaCancel

};

class Jogo
{
public:
	Jogo();
	~Jogo();

	void inicializar();
	void finalizar();

	void executar();

	void tMenu();
	void tRanking();
	void tCreditos();
	void tCarregar();
	void tJogo();
	void tSelect();	
	void tGameOver();
	void tCancel();

	void pos();

	void colisoes();

private:
	InputJogo input;
	gTexto *txt;
	int randMapa, idTelas, *rx, *ry, numBaus, numMonstros;
	
	// sprites de telas
	Sprite hud, chooseclass, mainmenu, gameover, cancelgame;

	// pilha
	Pilha<int> pilha;

};

