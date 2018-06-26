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

	pilha.push(telaMenu);

	// ler musica
	gRecursos.carregarMusica("m", "bin/assets/audio/nf.ogg");
	gMusica.setVolumeGlobal(100);
	


	//ler tiles
	input.carregarTiles("bin/assets/tiles/configfix.txt");



	// ler itens txt
	input.lerItens("bin/assets/sprites/itens.txt");

	// ler sprites de personagem
	gRecursos.carregarSpriteSheet("mage", "bin/assets/sprites/mage.png",4,3);
	gRecursos.carregarSpriteSheet("warrior", "bin/assets/sprites/warrior.png", 4, 3);
	gRecursos.carregarSpriteSheet("thief", "bin/assets/sprites/thief.png", 4, 3);
	
	// ler sprites de itens
	gRecursos.carregarSpriteSheet("armadura", "bin/assets/sprites/armadura.png", 1, 1);
	gRecursos.carregarSpriteSheet("colar", "bin/assets/sprites/colar.png", 1, 1);
	gRecursos.carregarSpriteSheet("elmo", "bin/assets/sprites/elmo.png", 1, 1);
	gRecursos.carregarSpriteSheet("livro", "bin/assets/sprites/livro.png", 1, 1);
	gRecursos.carregarSpriteSheet("luva", "bin/assets/sprites/luva.png", 1, 1);
	gRecursos.carregarSpriteSheet("pao", "bin/assets/sprites/pao.png", 1, 1);


	// ler sprites de monstros
	gRecursos.carregarSpriteSheet("rat", "bin/assets/sprites/mrat.png", 4, 3);
	gRecursos.carregarSpriteSheet("bat", "bin/assets/sprites/mbat.png", 4, 3);
	gRecursos.carregarSpriteSheet("ghost", "bin/assets/sprites/mghost.png", 4, 3);

	// ler telas (estados)
	gRecursos.carregarSpriteSheet("overlay", "bin/assets/state/overlay2.png", 1, 1);
	gRecursos.carregarSpriteSheet("chooseclass", "bin/assets/state/chooseclass.png", 1, 1);
	gRecursos.carregarSpriteSheet("gameover", "bin/assets/state/gameover.png", 1, 1);
	gRecursos.carregarSpriteSheet("mainmenu", "bin/assets/state/mainmenu.png", 1, 1);
	gRecursos.carregarSpriteSheet("cancelgame", "bin/assets/state/cancelgame.png", 1, 1);

	hud.setSpriteSheet("overlay");
	chooseclass.setSpriteSheet("chooseclass");
	gameover.setSpriteSheet("gameover");
	mainmenu.setSpriteSheet("mainmenu");
	cancelgame.setSpriteSheet("cancelgame");



	// textos diferentes no jogo: 1 classe, 4 status
	int numtxt = 5;
	txt = new gTexto[numtxt];

	// ler fonte
	gRecursos.carregarFonte("font", "bin/assets/fonts/medieval.ttf", 30);

	
	// texto 0 = classe, 1 a 4 = status

	for (int i = 0; i < numtxt; i++) {      
		txt[i].setFont("font");
		txt[i].centralizar();
		txt[i].cor(255, 246, 242); //
	}



	// ler monstros
	input.lerMonstros("bin/assets/sprites/monstersfix.txt");




}

void Jogo::finalizar()
{
	
	gRecursos.descarregarTudo();


	uniFinalizar();
}

void Jogo::executar()
{
	if (!gTeclado.pressionou[TECLA_ESC])
		gMusica.tocar("m", true);

	while(!gTeclado.soltou[TECLA_ESC] && !gEventos.sair)
	{
		uniIniciarFrame();

	


		switch (pilha.top()) {
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
		case telaGO:
			tGameOver();
			break;
		case telaCancel:
			tCancel();
			break;
		}


		
		uniTerminarFrame();
	}
}

void Jogo::tMenu()
{
	mainmenu.desenhar(gJanela.getLargura() / 2, gJanela.getAltura() / 2);


	if (gTeclado.pressionou[TECLA_1]) {


		// ir para tela de seleção
		pilha.push(telaSelect);

	}
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
void Jogo::tSelect()
{

	txt[0].setTxt("");
	input.unselectAll();


	// -------------------------------------     NOVO JOGO     -------------------------------------------------


	// ler mapas
	input.lerMapa(0, "bin/assets/tiles/mapa0.txt");
	input.lerMapa(1, "bin/assets/tiles/mapa1.txt");


	// mapa 0
	input.mapaInicial();
	randMapa = input.getMapaAtual();

	//randMapa = uniRandEntre(0, 1);
	//input.setMapaAtual(randMapa);

	input.resetMonsters();

	// limpar a pilha
	input.getPilha().clear();


	// setar as posições de monstros e baus
	pos();

	// adicionar sala na pilha
	input.getPilha().push(input.getSala());

	// inicializar
	input.iniciaMage("mage");
	input.iniciaThief("thief");
	input.iniciaWarrior("warrior");

	input.selectClass(NULL);

	input.newBag();



	// desenhar a tela
	chooseclass.desenhar(gJanela.getLargura() / 2, gJanela.getAltura() / 2);

	if (gTeclado.pressionou[TECLA_VOLTAR]) {
		pilha.pop();
	}

	if (gTeclado.pressionou[TECLA_1]) {
		input.selectClass(1);
		// setar posições iniciais de capa mapa
		if (randMapa == 0) {
			input.setPosInicial0();

		}
		else if (randMapa == 1) {
			input.setPosInicial1();
		}
		txt[0].setTxt("Mage");

		pilha.push(telaJogo);
	}

	if (gTeclado.pressionou[TECLA_2]) {
		input.selectClass(2);
		// setar posições iniciais de capa mapa
		if (randMapa == 0) {
			input.setPosInicial0();

		}
		else if (randMapa == 1) {
			input.setPosInicial1();
		}
		txt[0].setTxt("Valkyrie");

		pilha.push(telaJogo);

	}

	if (gTeclado.pressionou[TECLA_3]) {
		input.selectClass(3);
		// setar posições iniciais de capa mapa
		if (randMapa == 0) {
			input.setPosInicial0();

		}
		else if (randMapa == 1) {
			input.setPosInicial1();
		}
		txt[0].setTxt("Rogue");

		pilha.push(telaJogo);

	}
}


void Jogo::tJogo()
{

	if (gTeclado.pressionou[TECLA_VOLTAR]) {
		pilha.push(telaCancel);
	}

	// seta a variavel como o mapa atual
	randMapa = input.getMapaAtual();

	// desenhar o mapa
	input.getMap(randMapa).desenhar();
	/*input.getPilha().top().desenhar(); // dá erro de memória*/

	// setar posição do jogador se o tile for porta e o mapa é o primeiro
	input.setPosPorta();


	// testar as colisões
	colisoes();

	// testar vida
	if (input.getPlayerHP() <= 0) {
		pilha.push(telaGO);
	}


	// atualizar e desenhar
	input.atualizar();
	input.atualizarBag();
	input.desenhar();


	// atualizar textos ---- 1 = HP, 2 = Atk, 3 = Def, 4 = Ouro
	txt[1].setTxtHP(input.getPlayerHP(), input.getPlayerMaxHP());
	txt[2].setTxt(std::to_string(input.getPlayerAtk()));
	txt[3].setTxt(std::to_string(input.getPlayerDef()));
	txt[4].setTxt(std::to_string(input.getPlayerGold()));

	hud.desenhar(gJanela.getLargura() / 2, gJanela.getAltura() / 2);
	
	txt[0].desenhar(925, 185);
	input.desenharItens();
	
	int tX, tY;
	tX = 930;
	tY = 240;
	txt[1].desenhar(tX, tY);
	txt[2].desenhar(tX, tY += 60);
	txt[3].desenhar(tX, tY += 60);
	txt[4].desenhar(tX, tY += 60);


}


void Jogo::tGameOver()
{
	gameover.desenhar(gJanela.getLargura() / 2, gJanela.getAltura() / 2);

	
	if (gTeclado.pressionou[TECLA_VOLTAR]) {
		

		do {
			pilha.pop();
		} while (pilha.top() != 0);


	}
	
}

void Jogo::tCancel()
{
	cancelgame.desenhar(gJanela.getLargura() / 2, gJanela.getAltura() / 2);
	if (gTeclado.pressionou[TECLA_1]) {

		do {
			pilha.pop();
		} while (pilha.top() != 0);
	}

	if (gTeclado.pressionou[TECLA_2]) {
		pilha.pop();
	}
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
		} while (input.getMap(randMapa).getTile(rx[i],ry[i]).getId() != 1);

	
		input.setChests(rx[i], ry[i]);
	}


}

void Jogo::colisoes()
{
	int ra = uniRandEntre(0, input.getTotalItens() - 1);
	for (int i = 0; i < numBaus; i++) {

		// se a posição do jogador for bau x+1/x+2 ou bau y+1
		if (input.getPlayerY() == (ry[i] * 32) + 32 && input.getPlayerX() == rx[i] * 32) {
			if (input.getMap(randMapa).getTile(rx[i], ry[i]).getId() == 8) {
				int rr = uniRandEntre(1, 6);
				rr *= 1000;

				input.setPlayerGold(rr);

				// item teste
				input.addItem(ra);
			}
			input.setOpenChest(rx[i], ry[i]);

		}
		else if (input.getPlayerY() == ry[i] * 32 && input.getPlayerX() == (rx[i] * 32) + 32) {
			if (input.getMap(randMapa).getTile(rx[i], ry[i]).getId() == 8) {
				int rr = uniRandEntre(1, 6);
				rr *= 1000;

				input.setPlayerGold(rr);
				// item teste
				input.addItem(ra);
			}
			input.setOpenChest(rx[i], ry[i]);

		}
		else if (input.getPlayerY() == ry[i] * 32 && input.getPlayerX() == (rx[i] * 32) - 32) {
			if (input.getMap(randMapa).getTile(rx[i], ry[i]).getId() == 8) {
				int rr = uniRandEntre(1, 6);
				rr *= 1000;

				input.setPlayerGold(rr);
				// item teste
				input.addItem(ra);
			}
			input.setOpenChest(rx[i], ry[i]);

		}

	}
	
}

