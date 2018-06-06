#include "InputJogo.h"



InputJogo::InputJogo()
{
	mapaAtual = 0;
}


InputJogo::~InputJogo()
{
}

myTilemap InputJogo::getMap(int i)
{
	return mapa[i];
}



void InputJogo::lerMapa(int i, std::string arq)
{
	mapa[i].ler(arq);
}

void InputJogo::carregarTiles(std::string arq)
{
	int totalTiles, id;
	std::string nome, caminho;
	bool solido;

	ifstream tiles(arq);
	if (tiles) {
		tiles >> totalTiles;

		for (int i = 0; i < totalTiles; i++) {

			tiles >> id >> nome >> caminho;

			gRecursos.carregarSpriteSheet(nome, caminho, 1, 1);

		}

		tiles.close();
	}
	else {
		exit(0);
	}
}

void InputJogo::iniciaMage(std::string sheet)
{
	mage.inicializar(sheet);
	
}

void InputJogo::atualizarMage()
{
	if (mage.isSelected()) {

		if (!mage.estaMovendo()) {

			// mover direita
			if (gTeclado.pressionou[TECLA_DIR]) {
				if (!mapa[mapaAtual].getTile((mage.getX()/32) + 1, (mage.getY()/32)).getSolid()) {
					mage.movDir();
				}
			}

			// mover esquerda
			else if (gTeclado.pressionou[TECLA_ESQ]) {
				if (!mapa[mapaAtual].getTile((mage.getX()/32) - 1, (mage.getY()/32)).getSolid()) {
					mage.movEsq();
				}
			}

			// mover cima
			else if (gTeclado.pressionou[TECLA_CIMA]) {
				if (!mapa[mapaAtual].getTile((mage.getX()/32), (mage.getY()/32) - 1).getSolid()) {
					mage.movCima();
				}
			}

			// mover baixo
			else if (gTeclado.pressionou[TECLA_BAIXO]) {
				if (!mapa[mapaAtual].getTile((mage.getX()/32), (mage.getY()/32) + 1).getSolid()) {
					mage.movBaixo();
				}
			}
		}
		
	}
}

void InputJogo::desenharMage()
{
	mage.desenhar();
}

void InputJogo::iniciaWarrior(std::string sheet)
{
	warrior.inicializar(sheet);
}

void InputJogo::atualizarWarrior()
{
	if (warrior.isSelected()) {

		if (!warrior.estaMovendo()) {

			// mover direita
			if (gTeclado.pressionou[TECLA_DIR]) {
				if (!mapa[mapaAtual].getTile((warrior.getX() / 32) + 1, (warrior.getY() / 32)).getSolid()) {
					warrior.movDir();
				}
			}

			// mover esquerda
			else if (gTeclado.pressionou[TECLA_ESQ]) {
				if (!mapa[mapaAtual].getTile((warrior.getX() / 32) - 1, (warrior.getY() / 32)).getSolid()) {
					warrior.movEsq();
				}
			}

			// mover cima
			else if (gTeclado.pressionou[TECLA_CIMA]) {
				if (!mapa[mapaAtual].getTile((warrior.getX() / 32), (warrior.getY() / 32) - 1).getSolid()) {
					warrior.movCima();
				}
			}

			// mover baixo
			else if (gTeclado.pressionou[TECLA_BAIXO]) {
				if (!mapa[mapaAtual].getTile((warrior.getX() / 32), (warrior.getY() / 32) + 1).getSolid()) {
					warrior.movBaixo();
				}
			}
		}

	}
}

void InputJogo::desenharWarrior()
{
	warrior.desenhar();
}

void InputJogo::iniciaThief(std::string sheet)
{
	thief.inicializar(sheet);
}

void InputJogo::atualizarThief()
{
	if (thief.isSelected()) {

		if (!thief.estaMovendo()) {

			// mover direita
			if (gTeclado.pressionou[TECLA_DIR]) {
				if (!mapa[mapaAtual].getTile((thief.getX() / 32) + 1, (thief.getY() / 32)).getSolid()) {
					thief.movDir();
				}
			}

			// mover esquerda
			else if (gTeclado.pressionou[TECLA_ESQ]) {
				if (!mapa[mapaAtual].getTile((thief.getX() / 32) - 1, (thief.getY() / 32)).getSolid()) {
					thief.movEsq();
				}
			}

			// mover cima
			else if (gTeclado.pressionou[TECLA_CIMA]) {
				if (!mapa[mapaAtual].getTile((warrior.getX() / 32), (thief.getY() / 32) - 1).getSolid()) {
					thief.movCima();
				}
			}

			// mover baixo
			else if (gTeclado.pressionou[TECLA_BAIXO]) {
				if (!mapa[mapaAtual].getTile((thief.getX() / 32), (thief.getY() / 32) + 1).getSolid()) {
					thief.movBaixo();
				}
			}
		}

	}
}

void InputJogo::desenharThief()
{
	thief.desenhar();
}

int InputJogo::getMapaAtual()
{
	return mapaAtual;
}

void InputJogo::setMapaAtual(int mapa)
{
	mapaAtual = mapa;
}

void InputJogo::selectClass(int i)
{
	if (i == 1) {
		mage.select();
	}
	else if (i == 2) {
		warrior.select();
	}
	else if (i == 3) {
		thief.select();
	}
}

int InputJogo::getClass()
{
	if (mage.isSelected()) {
		return 1;
	}
	else if (warrior.isSelected()) {
		return 2;
	}
	else if (thief.isSelected()) {
		return 3;
	}
}

void InputJogo::setPosInicial0()
{
	if (getClass() == 1) {
		mage.setPos(15, 1);
	}
	else if (getClass() == 2) {
		warrior.setPos(15, 1);
	}
	else if (getClass() == 3) {
		thief.setPos(15, 1);
	}
}

void InputJogo::setPosInicial1()
{
	if (getClass() == 1) {
		mage.setPos(5, 1);
	}
	else if (getClass() == 2) {
		warrior.setPos(5, 1);
	}
	else if (getClass() == 3) {
		thief.setPos(5, 1);
	}
}
