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
	uniRandSetSemente(time(NULL));


	//ler tiles
	input.carregarTiles("bin/assets/tiles/configfix.txt");

	// ler mapas
	input.lerMapa(0,"bin/assets/tiles/mapa0.txt");
	input.lerMapa(1, "bin/assets/tiles/mapa1.txt");

	// ler sprites de personagem
	gRecursos.carregarSpriteSheet("mage", "bin/assets/sprites/mage.png", 4, 4);
	gRecursos.carregarSpriteSheet("warrior", "bin/assets/sprites/warrior.png", 4, 4);
	gRecursos.carregarSpriteSheet("thief", "bin/assets/sprites/thief.png", 4, 4);
	

	// ler sprites de monstros
	gRecursos.carregarSpriteSheet("rat", "bin/assets/sprites/mrat.png", 4, 4);
	gRecursos.carregarSpriteSheet("bat", "bin/assets/sprites/mbat.png", 4, 4);
	gRecursos.carregarSpriteSheet("ghost", "bin/assets/sprites/ghost.png", 4, 4);

	// ler telas
	gRecursos.carregarSpriteSheet("overlay", "bin/assets/sprites/overlay.png", 1, 1);
	hud.setSpriteSheet("overlay");

	// textos diferentes no jogo: 10 de cada item, 1 classe, 4 status
	txt = new gTexto[15];

	// ler fonte
	gRecursos.carregarFonte("font", "bin/assets/fonts/medieval.ttf", 45);

	
	// texto 0 = classe, 1 a 4 = status, 5 a 14 = itens

	for (int i = 0; i < 15; i++) {      // 1 = HP, 2 = Atk, 3 = Def, 4 = Ouro
		txt[i].setFont("font");
		txt[i].centralizar();
		txt[i].cor(98, 80, 47);
	}


	// ler monstros
	input.lerMonstros("bin/assets/sprites/monstersfix.txt");


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

	// mapa atual � o primeiro
	input.setFirstMap();

	// setar posi��es iniciais de capa mapa
	if (randMapa == 0) {
		input.setPosInicial0();
		
	}
	else if (randMapa == 1) {
		input.setPosInicial1();
	}

	// setar as posi��es de monstros e baus
	pos();

	// setar texto da classe
	if (input.getClass() == 1) {
		txt[0].setTxt("Mago");
	}
	else if (input.getClass() == 2) {
		txt[0].setTxt("Guerreiro");
	}
	else if (input.getClass() == 3) {
		txt[0].setTxt("Ladino");
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
	bool bag = false;

	// desenhar primeiro mapa aleatoriamente
	input.getMap(randMapa).desenhar();

	// setar posi��o do jogador se o tile for porta e o mapa � o primeiro
	input.setPosPorta();


	// testar as colis�es
	colisoes();

	input.atualizar();
	input.desenhar();
	// atualizar textos ---- 1 = HP, 2 = Atk, 3 = Def, 4 = Ouro
	txt[1].setTxtHP(input.getPlayerHP(), input.getPlayerMaxHP());
	txt[2].setTxt(std::to_string(input.getPlayerAtk()));
	txt[3].setTxt(std::to_string(input.getPlayerDef()));
	txt[4].setTxt(std::to_string(input.getPlayerGold()));

	hud.desenhar(gJanela.getLargura() / 2, gJanela.getAltura() / 2);
	
	txt[0].desenhar(925, 170);
	
	int tX, tY;
	tX = 930;
	tY = 220;
	txt[1].desenhar(tX, tY);
	txt[2].desenhar(tX, tY += 72);
	txt[3].desenhar(tX, tY += 72);
	txt[4].desenhar(tX, tY += 72);


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
	numMonstros = uniRandEntre(0, 5);
	input.iniciaMonstros(numMonstros);

	// baus
	numBaus = uniRandEntre(0, 2);
	rx = new int[numBaus];
	ry = new int[numBaus];

	for (int i = 0; i < numBaus; i++) {
	
		do {
			rx[i] = uniRandEntre(1, 29);
			ry[i] = uniRandEntre(1, 21);
		} while (input.isSolid(rx[i],ry[i]));

	
		input.setChests(rx[i], ry[i]);
	}


}

void Jogo::colisoes()
{
	for (int i = 0; i < numBaus; i++) {

		// se a posi��o do jogador for bau x+1/x+2 ou bau y+1
		if (input.getPlayerY() == (ry[i] * 32) + 32 && input.getPlayerX() == rx[i] * 32) {
			if (input.getMap(randMapa).getTile(rx[i], ry[i]).getId() == 8) {
				int rr = uniRandEntre(1, 6);
				rr *= 1000;

				input.setPlayerGold(rr);
			}
			input.setOpenChest(rx[i], ry[i]);

		}
		else if (input.getPlayerY() == ry[i] * 32 && input.getPlayerX() == (rx[i] * 32) + 32) {
			if (input.getMap(randMapa).getTile(rx[i], ry[i]).getId() == 8) {
				int rr = uniRandEntre(1, 6);
				rr *= 1000;

				input.setPlayerGold(rr);
			}
			input.setOpenChest(rx[i], ry[i]);

		}
		else if (input.getPlayerY() == ry[i] * 32 && input.getPlayerX() == (rx[i] * 32) - 32) {
			if (input.getMap(randMapa).getTile(rx[i], ry[i]).getId() == 8) {
				int rr = uniRandEntre(1, 6);
				rr *= 1000;

				input.setPlayerGold(rr);
			}
			input.setOpenChest(rx[i], ry[i]);

		}

	}
	
}
