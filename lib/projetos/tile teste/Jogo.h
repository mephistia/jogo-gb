#pragma once
#include "libUnicornio.h"
#include "InputJogo.h"



class Jogo
{
public:
	Jogo();
	~Jogo();

	void inicializar();
	void finalizar();

	void executar();

private:
	InputJogo input;
	
};

