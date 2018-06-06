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

	//ler tiles
	input.carregarTiles("assets/tiles/tiles.txt");

	// ler mapas
	input.lerMapa(0,"assets/tiles/mapa0.txt");
	input.lerMapa(1, "assets/tiles/mapa1.txt");

	// ler sprites de personagem
	gRecursos.carregarSpriteSheet("mage", "assets/sprites/mage.png", 4, 4);
	gRecursos.carregarSpriteSheet("warrior", "assets/sprites/warrior.png", 4, 4);
	gRecursos.carregarSpriteSheet("thief", "assets/sprites/thief.png", 4, 4);


	// inicializar classes
	input.iniciaMage("mage");
	input.iniciaThief("thief");
	input.iniciaWarrior("warrior");
	
	// selecionar rand teste
	int r = rand() % 2 + 1;
	input.selectClass(r);

	// mapa aleatorio
	randMapa = rand() % 1;
	input.setMapaAtual(randMapa);

	// setar posições iniciais de capa mapa
	if (randMapa == 0) {
		input.setPosInicial0();
	}
	else if (randMapa == 1) {
		input.setPosInicial1();
	}

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
		input.getMap(randMapa).desenhar();

		// setar posição do jogador se o tile for porta.



		// desenhar mago
		if (input.getClass() == 1) {
			input.atualizarMage();
			input.desenharMage();
		}
		else if (input.getClass() == 2) {
			input.atualizarWarrior();
			input.desenharWarrior();
		}
		else if (input.getClass() == 3) {
			input.atualizarThief();
			input.atualizarThief();
		}
		


		
		uniTerminarFrame();
	}
}