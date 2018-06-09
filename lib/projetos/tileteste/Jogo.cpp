#include "Jogo.h"

Jogo::Jogo()
{
}

Jogo::~Jogo()
{
}

void Jogo::inicializar()
{
	uniInicializar(1024, 768, false, "Generic Dungeon");

	srand(time(0));


	//ler tiles
	input.carregarTiles("C:/Users/ander/Documents/GitHub/jogo-gb/lib/projetos/tileteste/bin/assets/tiles/config.txt");

	// ler mapas
	input.lerMapa(0,"C:/Users/ander/Documents/GitHub/jogo-gb/lib/projetos/tileteste/bin/assets/tiles/mapa0.txt");
	input.lerMapa(1, "C:/Users/ander/Documents/GitHub/jogo-gb/lib/projetos/tileteste/bin/assets/tiles/mapa1.txt");

	// ler sprites de personagem
	gRecursos.carregarSpriteSheet("mage", "C:/Users/ander/Documents/GitHub/jogo-gb/lib/projetos/tileteste/bin/assets/sprites/mage.png", 4, 4);
	gRecursos.carregarSpriteSheet("warrior", "C:/Users/ander/Documents/GitHub/jogo-gb/lib/projetos/tileteste/bin/assets/sprites/warrior.png", 4, 4);
	gRecursos.carregarSpriteSheet("thief", "C:/Users/ander/Documents/GitHub/jogo-gb/lib/projetos/tileteste/bin/assets/sprites/thief.png", 4, 4);

	// ler sprites de monstros
	gRecursos.carregarSpriteSheet("Rat", "C:/Users/ander/Documents/GitHub/jogo-gb/lib/projetos/tileteste/bin/assets/sprites/mrat.png", 4, 4);
	gRecursos.carregarSpriteSheet("Bat", "C:/Users/ander/Documents/GitHub/jogo-gb/lib/projetos/tileteste/bin/assets/sprites/mbat.png", 4, 4);
	gRecursos.carregarSpriteSheet("Ghost", "C:/Users/ander/Documents/GitHub/jogo-gb/lib/projetos/tileteste/bin/assets/sprites/ghost.png", 4, 4);

	// ler monstros
	input.lerMonstros("C:/Users/ander/Documents/GitHub/jogo-gb/lib/projetos/tileteste/bin/assets/sprites/monsters.txt");


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

	// setar as posições de monstros e baus
	pos();

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

	// setar posição do jogador se o tile for porta e o mapa é o primeiro
	input.setPosPorta();


	// testar as colisões
	colisoes();


	// atualizar 
	input.atualizar();


	// desenhar 
	input.desenhar();

	

}

void Jogo::tSelect()
{
}

void Jogo::tInventario()
{
}

void Jogo::pos()
{
	// monstros no mapa
	numMonstros = 3; /*uniRandEntre(0, 5);*/
	input.iniciaMonstros(numMonstros);

	// baus
	numBaus = uniRandEntre(0, 2);
	rx = new int[numBaus];
	ry = new int[numBaus];

	for (int i = 0; i < numBaus; i++) {
	
		do {
			rx[i] = uniRandEntre(0, 29);
			ry[i] = uniRandEntre(0, 21);
		} while (input.isSolid(rx[i] + 2, ry[i] + 2) || input.isSolid(rx[i] + 1, ry[i] + 1) ||
			    input.getMap(randMapa).getTile(rx[i]+2,ry[i]+2).isMonster() || input.getMap(randMapa).getTile(rx[i] + 1, ry[i] + 1).isMonster() ||
				input.getMap(randMapa).getTile(rx[i], ry[i]).isMonster() || input.isSolid(rx[i],ry[i]));

	
		input.setChests(rx[i], ry[i]);
	}


}

void Jogo::colisoes()
{
	for (int i = 0; i < numBaus; i++) {

		// se a posição do jogador for bau x+1 ou bau y+1
		if (input.getPlayerY() == (ry[i]*32) +32 && input.getPlayerX() == rx[i]*32)
			input.setOpenChest(rx[i], ry[i]);

	}
	
}
