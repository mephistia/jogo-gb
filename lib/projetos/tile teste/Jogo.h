#pragma once
#include "libUnicornio.h"
#include "InputJogo.h"

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
	

private:
	InputJogo input;
	int randMapa, idTelas;
	
};

