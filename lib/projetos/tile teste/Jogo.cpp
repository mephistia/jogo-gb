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

	srand(time(0));


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
	int r = uniRandEntre(1, 3);
	input.selectClass(r);

	// mapa aleatorio
	randMapa = uniRandEntre(0, 1);
	input.setMapaAtual(randMapa);
	// mapa atual é o primeiro
	input.setFirstMap();

	// setar posições iniciais de capa mapa
	if (randMapa == 0) {
		input.setPosInicial0();
		
	}
	else if (randMapa == 1) {
		input.setPosInicial1();
	}

	idTelas = telaJogo;
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

		switch (idTelas) {
		case telaMenu:
			tMenu();
			break;
		case telaRanking:
			tRanking();
			break;
		case telaCreditos:
			tCreditos();
			break;
		case telaCarregar:
			tCarregar();
			break;
		case telaJogo:
			tJogo();
			break;
		case telaSelect:
			tSelect();
			break;
		case telaInventario:
			tInventario();
			break;
		}


		
		uniTerminarFrame();
	}
}

void Jogo::tMenu()
{
}

void Jogo::tRanking()
{
}

void Jogo::tCreditos()
{
}

void Jogo::tCarregar()
{
}

void Jogo::tJogo()
{

	// desenhar primeiro mapa aleatoriamente
	input.getMap(randMapa).desenhar();

	// setar posição do jogador se o tile for porta e a sala nao foi visitada
	input.setPosPorta();



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
		input.desenharThief();
	}

}

void Jogo::tSelect()
{
}

void Jogo::tInventario()
{
}
