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
	gRecursos.carregarSpriteSheet("loadgame", "bin/assets/state/loadgame.png", 1, 1);
	gRecursos.carregarSpriteSheet("savegame", "bin/assets/state/savegame.png", 1, 1);
	gRecursos.carregarSpriteSheet("gamesaved", "bin/assets/state/gamesaved.png", 1, 1);
	gRecursos.carregarSpriteSheet("credits", "bin/assets/state/credits.png", 1, 1);

	hud.setSpriteSheet("overlay");
	chooseclass.setSpriteSheet("chooseclass");
	gameover.setSpriteSheet("gameover");
	mainmenu.setSpriteSheet("mainmenu");
	cancelgame.setSpriteSheet("cancelgame");
	loadgame.setSpriteSheet("loadgame");
	savegame.setSpriteSheet("savegame");
	gamesaved.setSpriteSheet("gamesaved");
	credits.setSpriteSheet("credits");



	// textos diferentes no jogo: 1 classe, 4 status, 3 nomes de saves
	int numtxt = 8;
	txt = new gTexto[numtxt];

	// ler fonte
	gRecursos.carregarFonte("font", "bin/assets/fonts/medieval.ttf", 30);

	
	// texto 0 = classe, 1 a 4 = status

	for (int i = 0; i < numtxt; i++) {      
		txt[i].setFont("font");
		txt[i].centralizar();
		txt[i].cor(255, 246, 242); //
	}



	//// ler monstros
	//input.lerMonstros("bin/assets/sprites/monstersfix.txt");




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
		case telaSalvar:
			tSave();
			break;
		case telaSalvo:
			tSaved();
			break;
		}


		
		uniTerminarFrame();
	}
}

void Jogo::tMenu()
{
	mainmenu.desenhar(gJanela.getLargura() / 2, gJanela.getAltura() / 2);
	// ler mapas
	input.lerMapa(0, "bin/assets/tiles/mapa0.txt");
	input.lerMapa(1, "bin/assets/tiles/mapa1.txt");
	input.lerMapa(2, "bin/assets/tiles/mapa2.txt");
	input.lerMapa(3, "bin/assets/tiles/mapa3.txt");
	input.lerMapa(4, "bin/assets/tiles/mapa4.txt");
	input.lerMapa(5, "bin/assets/tiles/mapa5.txt");

	if (gTeclado.pressionou[TECLA_1]) {


		// ir para tela de seleção
		pilha.push(telaSelect);

	}

	if (gTeclado.pressionou[TECLA_2]) {


		// ir para tela de carregamento
		pilha.push(telaCarregar);

	}

	if (gTeclado.pressionou[TECLA_4]) {


		// ir para tela de creditos
		pilha.push(telaCreditos);

	}
}

void Jogo::tRanking()
{
}

void Jogo::tCreditos()
{
	credits.desenhar(gJanela.getLargura() / 2, gJanela.getAltura() / 2);
	if (gTeclado.pressionou[TECLA_VOLTAR]) {

		pilha.pop();

	}
}

void Jogo::tCarregar()
{
	// desenhar tela
	loadgame.desenhar(gJanela.getLargura() / 2, gJanela.getAltura() / 2);



	// txt 5, 6 e 7 são de slots
	ifstream file; // tenta abrir o arquivo 1
	file.open("save1.dat", ios::binary);
	if (!file) { 
		txt[5].setTxt("Empty Slot");
		txt[5].desenhar(190, 400);

	}
	else {
		char arq[15];

		// se o save existir, extrai o nome e passa para o txt
		file.read(reinterpret_cast<char*> (&arq), sizeof(char[15]));
		string save1(arq);
		txt[5].setTxt(save1);
		txt[5].desenhar(190, 400);



	}
		
	
	file.close();


	ifstream file2; // tenta abrir o segundo arquivo
	file.open("save2.dat", ios::binary);

	if (!file2) {

		txt[6].setTxt("Empty Slot");
		txt[6].desenhar(510, 400);
	}
	else {
		char arq[15];

		file.read(reinterpret_cast<char*> (&arq), sizeof(char[15]));		string save2(arq);		txt[6].setTxt(save2);		txt[6].desenhar(510, 400);


	}

	file2.close();

	ifstream file3; // tenta abrir o terceiro arquivo
	file.open("save3.dat", ios::binary);

	if (!file3) {

		txt[7].setTxt("Empty Slot");
		txt[7].desenhar(800, 400);
	}
	else {

		char arq[15];
		file.read(reinterpret_cast<char*> (&arq), sizeof(char[15]));		string save2(arq);		txt[7].setTxt(save2);
		txt[7].desenhar(800, 400);


	}


	file3.close();


	if (gTeclado.pressionou[TECLA_1]) {
		ifstream file; // tenta abrir o arquivo 1

		file.open("save1.dat", ios::binary);
		if (!file) {
			pilha.pop();
		}
		else {
			// ler mapas
			input.lerMapa(0, "bin/assets/tiles/mapa0.txt");
			input.lerMapa(1, "bin/assets/tiles/mapa1.txt");

			input.carregar("save1.dat");
			file.close();
			pilha.push(telaJogo);
		}
	}

	if (gTeclado.pressionou[TECLA_2]) {
		ifstream file; // tenta abrir o arquivo 2

		file.open("save2.dat", ios::binary);
		if (!file) {
			pilha.pop();
		}
		else {
			// ler mapas
			input.lerMapa(0, "bin/assets/tiles/mapa0.txt");
			input.lerMapa(1, "bin/assets/tiles/mapa1.txt");

			input.carregar("save2.dat");
			file.close();
			pilha.push(telaJogo);
		}
	}

	if (gTeclado.pressionou[TECLA_3]) {
		ifstream file; // tenta abrir o arquivo 3

		file.open("save3.dat", ios::binary);
		if (!file) {
			pilha.pop();
		}
		else {
			// ler mapas
			input.lerMapa(0, "bin/assets/tiles/mapa0.txt");
			input.lerMapa(1, "bin/assets/tiles/mapa1.txt");

			input.carregar("save3.dat");
			file.close();
			pilha.push(telaJogo);
		}
	}

	if (gTeclado.pressionou[TECLA_VOLTAR]) {
		pilha.pop();
	}

}
void Jogo::tSelect()
{

	txt[0].setTxt("");
	input.unselectAll();


	// -------------------------------------     NOVO JOGO     -------------------------------------------------

	// mapa inicial
	input.mapaInicial();

	randMapa = input.getMapaAtual();




	// inicializar
	input.iniciaMage("mage");
	input.iniciaThief("thief");
	input.iniciaWarrior("warrior");

	input.selectClass(NULL);

	input.newBag();

	// push sala
	pSalas.push(input.getSala(randMapa));

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
		else if (randMapa == 2) {
			input.setPosInicial2();
		}
		else if (randMapa == 3) {
			input.setPosInicial3();
		}
		else if (randMapa == 4) {
			input.setPosInicial4();
		}
		else if (randMapa == 5) {
			input.setPosInicial5();
		}
		// setar posição do jogador se o tile for porta e o mapa é o primeiro
		input.setPosPorta();

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
		else if (randMapa == 2) {
			input.setPosInicial2();
		}
		else if (randMapa == 3) {
			input.setPosInicial3();
		}
		else if (randMapa == 4) {
			input.setPosInicial4();
		}
		else if (randMapa == 5) {
			input.setPosInicial5();
		}
		// setar posição do jogador se o tile for porta e o mapa é o primeiro
		input.setPosPorta();
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
		else if (randMapa == 2) {
			input.setPosInicial2();
		}
		else if (randMapa == 3) {
			input.setPosInicial3();
		}
		else if (randMapa == 4) {
			input.setPosInicial4();
		}
		else if (randMapa == 5) {
			input.setPosInicial5();
		}
		// setar posição do jogador se o tile for porta e o mapa é o primeiro
		input.setPosPorta();
		txt[0].setTxt("Rogue");

		pilha.push(telaJogo);

	}
}


void Jogo::tJogo()
{

	if (gTeclado.pressionou[TECLA_VOLTAR]) {
		pilha.push(telaCancel);
	}

	if (gTeclado.pressionou[TECLA_ENTER]) {
		pilha.push(telaSalvar);
	}

	passarSala();

	// desenhar o mapa
	pSalas.top().desenhar();


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


	
	// atualizar a sala da pilha
	pSalas.pop();
	pSalas.push(input.getSala(randMapa));
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

void Jogo::tSave()
{
	savegame.desenhar(gJanela.getLargura() / 2, gJanela.getAltura() / 2);

	if (gTeclado.pressionou[TECLA_1]) {

		// nome do arquivo deve ser salvo dentro do proprio arquivo

		// 3 saves; se existir o terceiro, sobrepõe o 1 sempre
		std::string save = "save";
		std::string dat = ".dat";
		std::string num = std::to_string(1);


		std::string result = save + num + dat;

		ifstream file; // tenta abrir o arquivo para ver se já existe

		file.open(result,ios::binary);

		if (file) { // se existe, tenta abrir com save2.dat
			num = std::to_string(2);
			result = save + num + dat;

			std::ifstream file2(result, std::ios::binary);

			if (file2) { // se existe, tenta abrir com save3.dat
				num = std::to_string(3);
				result = save + num + dat;

				std::ifstream file3(result, std::ios::binary);

				if (file3) { // se existe, arquivo para sobrescrever é save1.dat
					num = std::to_string(1);
					result = save + num + dat;

				}
				file3.close();


			}
			file2.close();

		}
		file.close();

		input.save(result);
		pilha.push(telaSalvo);
	}
	if (gTeclado.pressionou[TECLA_2]) {
		pilha.pop();
	}


}

void Jogo::tSaved()
{

	gamesaved.desenhar(gJanela.getLargura() / 2, gJanela.getAltura() / 2);

	if (gTeclado.pressionou[TECLA_ENTER]) {

		// volta a tela de confirmação, volta pra tela do jogo
		pilha.pop();
		pilha.pop();
	}

	if (gTeclado.pressionou[TECLA_ESPACO]) {
		do {
			pilha.pop();
		} while (pilha.top() != 0);
	}
}

void Jogo::passarSala()
{
	if (input.getClass() == 1) {
		playerX = input.getMage()->getX()/32;
		playerY = input.getMage()->getY()/32;
	}
	else if (input.getClass() == 2) {
		playerX = input.getWarrior()->getX()/32;
		playerY = input.getWarrior()->getY()/32;
	}
	else if (input.getClass() == 3) {
		playerX = input.getThief()->getX()/32;
		playerY = input.getThief()->getY()/32;
	}


	if (input.getSala(randMapa).getPos(playerX, playerY) == 3 || input.getSala(randMapa).getPos(playerX, playerY) == 4) {
		if ((playerY*32 > gJanela.getAltura() / 2) && pSalas.isRedoEmpty() && !input.getSala(randMapa).isEnd()) {

			int a = uniRandEntre(0, 5);

			randMapa++;
			

			if (a == 0) {
				input.lerMapaParaSala(randMapa,"bin/assets/tiles/mapa0.txt");
				input.getSala(randMapa).readMonster();
				input.getSala(randMapa).setChests();
				int r = uniRandEntre(0, 5);
				input.getSala(randMapa).setNMonsters(r);
				input.setMapaAtual(randMapa);
				input.setPosInicial0();
				input.setPosPorta();
			}
			else if (a == 1) {
				input.lerMapaParaSala(randMapa, "bin/assets/tiles/mapa1.txt");
				input.getSala(randMapa).readMonster();
				input.getSala(randMapa).setChests();
				int r = uniRandEntre(0, 5);
				input.getSala(randMapa).setNMonsters(r);
				input.setMapaAtual(randMapa);
				input.setPosInicial1();
				input.setPosPorta();

			}
			else if (a == 2) {
				input.lerMapaParaSala(randMapa, "bin/assets/tiles/mapa2.txt");
				input.getSala(randMapa).readMonster();
				input.getSala(randMapa).setChests();
				int r = uniRandEntre(0, 5);
				input.getSala(randMapa).setNMonsters(r);
				input.setMapaAtual(randMapa);
				input.setPosInicial2();
				input.setPosPorta();

			}
			else if (a == 3) {
				input.lerMapaParaSala(randMapa, "bin/assets/tiles/mapa3.txt");
				input.getSala(randMapa).readMonster();
				input.getSala(randMapa).setChests();
				int r = uniRandEntre(0, 5);
				input.getSala(randMapa).setNMonsters(r);
				input.setMapaAtual(randMapa);
				input.setPosInicial3();
				input.setPosPorta();

			}
			else if (a == 4) {
				input.lerMapaParaSala(randMapa, "bin/assets/tiles/mapa4.txt");
				input.getSala(randMapa).readMonster();
				input.getSala(randMapa).setChests();
				int r = uniRandEntre(0, 5);
				input.getSala(randMapa).setNMonsters(r);
				input.setMapaAtual(randMapa);
				input.setPosInicial4();
				input.setPosPorta();

			}
			else if (a == 5) {
				input.lerMapaParaSala(randMapa, "bin/assets/tiles/mapa5.txt");
				input.getSala(randMapa).readMonster();
				input.getSala(randMapa).setChests();
				int r = uniRandEntre(0, 5);
				input.getSala(randMapa).setNMonsters(r);
				input.setMapaAtual(randMapa);
				input.setPosInicial5();
				input.setPosPorta();

			}

			

			if (randMapa > 9 && randMapa != 15) {
				int ra = uniRandEntre(1, 6);
				if (ra == 1) {
					input.getSala(randMapa).setEnd(true);
				}
			}
			else if (randMapa == 15) {
				input.getSala(randMapa).setEnd(true);

			}

			pSalas.push(input.getSala(randMapa));


		}
		else if ((playerY*32 > gJanela.getAltura() / 2) && input.getSala(randMapa).isEnd()) {
			// tela final
		}

		else if ((playerY*32 > gJanela.getAltura() / 2) && !pSalas.isRedoEmpty()) {
			pSalas.redo();
			randMapa++;
		}
		else if (playerY*32 < gJanela.getAltura() / 2) {
			if (randMapa > 0) {
				pSalas.undo();
				randMapa--;

				if (input.getSala(randMapa).getMapId() == 0) {
					input.setPosVolta0();
				}
				else if (input.getSala(randMapa).getMapId() == 1) {
					input.setPosVolta1();
				}
				else if (input.getSala(randMapa).getMapId() == 2) {
					input.setPosVolta3();
				}
				else if (input.getSala(randMapa).getMapId() == 3) {
					input.setPosVolta3();
				}
				else if (input.getSala(randMapa).getMapId() == 4) {
					input.setPosVolta4();
				}
				else if (input.getSala(randMapa).getMapId() == 5) {
					input.setPosVolta5();
				}
			}
		}
	}
}


