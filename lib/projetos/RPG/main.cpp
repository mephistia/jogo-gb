#include "Jogo.h"

int main(int argc, char* argv[])
{
	srand(time(0));
	
	Jogo jogo;
	jogo.inicializar();
	jogo.executar();
	jogo.finalizar();

	return 0;
}