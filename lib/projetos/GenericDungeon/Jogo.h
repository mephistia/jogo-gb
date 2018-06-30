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
	telaCancel,
	telaSalvar,
	telaSalvo


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
	void tSave();
	void tSaved();

	void passarSala();

private:
	InputJogo input;
	gTexto *txt;
	int randMapa, idTelas;
	
	// sprites de telas
	Sprite hud, chooseclass, mainmenu, gameover, cancelgame, loadgame, savegame, gamesaved, credits;

	// pilha
	Pilha<int> pilha;
	Pilha<myTilemap> pSalas;
	Pilha<myTilemap> pilhaMapas;

	int playerX, playerY;



};

