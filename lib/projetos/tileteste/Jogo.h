#pragma once
#include "libUnicornio.h"
#include "InputJogo.h"
#include "gTexto.h"

enum idTelas {

	// telas do enunciado
	telaMenu,
	telaRanking,
	telaCreditos,
	telaCarregar,
	telaJogo,

	// telas auxiliares
	telaSelect,
	telaInventario
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
	void tInventario();
	
	void pos();

	void colisoes();

private:
	InputJogo input;
	gTexto *txt;
	int randMapa, idTelas, *rx, *ry, numBaus, numMonstros;
	
	// sprites de telas
	Sprite hud;
};

