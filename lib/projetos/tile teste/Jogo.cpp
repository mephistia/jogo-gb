#include "Jogo.h"

Jogo::Jogo()
{
}

Jogo::~Jogo()
{
}

void Jogo::inicializar()
{
	uniInicializar(1280, 768, false, "Generic Dungeon");

	// ler mapas
	input.lerMapa(0,"assets/tiles/mapa0.txt");

	// ler sprites de personagem
	gRecursos.carregarSpriteSheet("mage", "assets/sprites/mage.png", 4, 4);

	// inicializar mago
	input.iniciaMage("mage");
	
	// teste
	input.selectClass(1);
}

void Jogo::finalizar()
{
	
	gRecursos.descarregarTudo();

	uniFinalizar();
}

void Jogo::executar()
{

	while(!gTeclado.soltou[TECLA_ESC] && !gEventos.sair)
	{
		uniIniciarFrame();


		// desenhar primeiro mapa aleatoriamente
		input.setMapaAtual(0);
		input.getMap(0).desenhar();



		// desenhar mago
		input.atualizarMage();
		input.desenharMage();


		
		uniTerminarFrame();
	}
}