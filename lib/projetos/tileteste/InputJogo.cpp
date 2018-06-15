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


	ifstream tiles(arq);
	if (tiles.is_open()) {
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
			if (gTeclado.pressionou[TECLA_D]) {
				if (!mapa[mapaAtual].getTile((mage.getX()/32) + 1, (mage.getY()/32)).getSolid()) {
					mage.movDir();
				}
			}

			// mover esquerda
			else if (gTeclado.pressionou[TECLA_A]) {
				if (!mapa[mapaAtual].getTile((mage.getX()/32) - 1, (mage.getY()/32)).getSolid()) {
					mage.movEsq();
				}
			}

			// mover cima
			else if (gTeclado.pressionou[TECLA_W]) {
				if (!mapa[mapaAtual].getTile((mage.getX()/32), (mage.getY()/32) - 1).getSolid()) {
					mage.movCima();
				}
			}

			// mover baixo
			else if (gTeclado.pressionou[TECLA_S]) {
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
			if (gTeclado.pressionou[TECLA_D]) {
				if (!mapa[mapaAtual].getTile((warrior.getX() / 32) + 1, (warrior.getY() / 32)).getSolid()) {
					warrior.movDir();
				}
			}

			// mover esquerda
			else if (gTeclado.pressionou[TECLA_A]) {
				if (!mapa[mapaAtual].getTile((warrior.getX() / 32) - 1, (warrior.getY() / 32)).getSolid()) {
					warrior.movEsq();
				}
			}

			// mover cima
			else if (gTeclado.pressionou[TECLA_W]) {
				if (!mapa[mapaAtual].getTile((warrior.getX() / 32), (warrior.getY() / 32) - 1).getSolid()) {
					warrior.movCima();
				}
			}

			// mover baixo
			else if (gTeclado.pressionou[TECLA_S]) {
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
			if (gTeclado.pressionou[TECLA_D]) {
				if (!mapa[mapaAtual].getTile((thief.getX() / 32) + 1, (thief.getY() / 32)).getSolid()) {
					thief.movDir();
				}
			}

			// mover esquerda
			else if (gTeclado.pressionou[TECLA_A]) {
				if (!mapa[mapaAtual].getTile((thief.getX() / 32) - 1, (thief.getY() / 32)).getSolid()) {
					thief.movEsq();
				}
			}

			// mover cima
			else if (gTeclado.pressionou[TECLA_W]) {
				if (!mapa[mapaAtual].getTile((thief.getX() / 32), (thief.getY() / 32) - 1).getSolid()) {
					thief.movCima();
				}
			}

			// mover baixo
			else if (gTeclado.pressionou[TECLA_S]) {
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

void InputJogo::lerMonstros(std::string arq)
{
	int id, def, hp;
	std::string caminho, nome;
	ifstream monstros(arq);

	if (monstros) {
		monstros >> nMonstros;

		m_id = new int[nMonstros];
		m_def = new int[nMonstros];
		m_hp = new int[nMonstros];
		m_sheet = new std::string[nMonstros];
		m_nome = new std::string[nMonstros];
		

		for (int i = 0; i < nMonstros; i++) {
			monstros >> id >> nome >> def >> hp >> caminho;
			m_id[i] = id;
			m_nome[i] = nome;
			m_def[i] = def;
			m_hp[i] = hp;
			m_sheet[i] = caminho;
		}
	}
}

// inicializa os monstros para o mapa atual
void InputJogo::iniciaMonstros(int n)
{
	if (!mapa[mapaAtual].getMonstersDone()) {

		mapa[mapaAtual].setNMonsters(n);
		for (int i = 0; i < n; i++) {

			// sortear um tipo
			int random = uniRandEntre(0, nMonstros - 1);

			// inicializar o monstro do mapa com os mesmos dados do tipo random
			mapa[mapaAtual].inicializaMonstro(i, m_id[random], m_def[random], m_hp[random], m_nome[random], m_sheet[random]);

			// setar uma posi��o para o monstro (em tiles)
			int rx, ry;
			do {
				rx = uniRandEntre(1, 29);
				ry = uniRandEntre(1, 21);
			} while (isSolid(rx, ry) == true);


			mapa[mapaAtual].getMonster(i).setPos(rx, ry);
			mapa[mapaAtual].getTile(rx, ry).setSolid(true);
		
		
		}

		mapa[mapaAtual].setMonstersDone(true);
	}
}

void InputJogo::atualizarMonstros()
{
	for (int i = 0; i < mapa[mapaAtual].getNMonsters(); i++) {
		mapa[mapaAtual].getMonster(i).setAnimBaixo();

	}
}

void InputJogo::desenharMonstros()
{
	for (int i = 0; i < mapa[mapaAtual].getNMonsters(); i++) {
		
		mapa[mapaAtual].getMonster(i).desenhar();
	}
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

void InputJogo::setPosPorta()
{
	// se o mapa � o primeiro
	if (mapa[mapaAtual].getFirst()) {
		if (getClass() == 1) {

			// se for porta vertical e em cima for solido
			if (mapa[mapaAtual].getTile((mage.getX() / 32), (mage.getY() / 32)).getId() == 4 && mapa[mapaAtual].getTile((mage.getX() / 32), (mage.getY() / 32) - 1).getSolid()) {
				mage.setPos((mage.getX() / 32), (mage.getY() / 32) + 2);
				mage.setAnimBaixo();
				mapa[mapaAtual].setFirst(false);
			}

			// se for porta vertical e embaixo for solido
			else if (mapa[mapaAtual].getTile((mage.getX() / 32), (mage.getY() / 32)).getId() == 4 && mapa[mapaAtual].getTile((mage.getX() / 32), (mage.getY() / 32) + 1).getSolid()) {
				mage.setPos((mage.getX()/32), (mage.getY()/32) - 2);
				mage.setAnimCima();
				mapa[mapaAtual].setFirst(false);

			}

			// se for porta horizontal e na direita for solido
			else if (mapa[mapaAtual].getTile((mage.getX() / 32), (mage.getY() / 32)).getId() == 3 && mapa[mapaAtual].getTile((mage.getX() / 32) + 1, (mage.getY() / 32)).getSolid()) {
				mage.setPos((mage.getX()/32) - 2 , (mage.getY()/32));
				mage.setAnimEsq();
				mapa[mapaAtual].setFirst(false);

			}

			// se for porta horizontal e na esquerda for solido
			else if (mapa[mapaAtual].getTile((mage.getX() / 32), (mage.getY() / 32)).getId() == 3 && mapa[mapaAtual].getTile((mage.getX() / 32) - 1, (mage.getY() / 32)).getSolid()) {
				mage.setPos((mage.getX()/32) +2, (mage.getY()/32));
				mage.setAnimDir();
				mapa[mapaAtual].setFirst(false);

			}
		}

		else if (getClass() == 2) {
			// se for porta vertical e em cima for solido
			if (mapa[mapaAtual].getTile((warrior.getX() / 32), (warrior.getY() / 32)).getId() == 4 && mapa[mapaAtual].getTile((warrior.getX() / 32), (warrior.getY() / 32) - 1).getSolid()) {
				warrior.setPos((warrior.getX()/32), (warrior.getY()/32) + 2);
				warrior.setAnimBaixo();
				mapa[mapaAtual].setFirst(false);

			}

			// se for porta vertical e embaixo for solido
			else if (mapa[mapaAtual].getTile((warrior.getX() / 32), (warrior.getY() / 32)).getId() == 4 && mapa[mapaAtual].getTile((warrior.getX() / 32), (warrior.getY() / 32) + 1).getSolid()) {
				warrior.setPos((warrior.getX() / 32), (warrior.getY() / 32) - 2);
				warrior.setAnimCima();
				mapa[mapaAtual].setFirst(false);


			}

			// se for porta horizontal e na direita for solido
			else if (mapa[mapaAtual].getTile((warrior.getX() / 32), (warrior.getY() / 32)).getId() == 3 && mapa[mapaAtual].getTile((warrior.getX() / 32) + 1, (warrior.getY() / 32)).getSolid()) {
				warrior.setPos((warrior.getX() / 32) - 2, (warrior.getY() / 32));
				warrior.setAnimEsq();
				mapa[mapaAtual].setFirst(false);

			}

			// se for porta horizontal e na esquerda for solido
			else if (mapa[mapaAtual].getTile((warrior.getX() / 32), (warrior.getY() / 32)).getId() == 3 && mapa[mapaAtual].getTile((warrior.getX() / 32) - 1, (warrior.getY() / 32)).getSolid()) {
				warrior.setPos((warrior.getX() / 32) + 2, (warrior.getY() / 32));
				warrior.setAnimDir();
				mapa[mapaAtual].setFirst(false);

			}
		}

		else if (getClass() == 3) {
			// se for porta vertical e em cima for solido
			if (mapa[mapaAtual].getTile((thief.getX() / 32), (thief.getY() / 32)).getId() == 4 && mapa[mapaAtual].getTile((thief.getX() / 32), (thief.getY() / 32) - 1).getSolid()) {
				thief.setPos((thief.getX() / 32), (thief.getY() / 32) + 2);
				thief.setAnimBaixo();
				mapa[mapaAtual].setFirst(false);

			}

			// se for porta vertical e embaixo for solido
			else if (mapa[mapaAtual].getTile((thief.getX() / 32), (thief.getY() / 32)).getId() == 4 && mapa[mapaAtual].getTile((thief.getX() / 32), (thief.getY() / 32) + 1).getSolid()) {
				thief.setPos((thief.getX() / 32), (thief.getY() / 32) - 2);
				thief.setAnimCima();
				mapa[mapaAtual].setFirst(false);


			}

			// se for porta horizontal e na direita for solido
			else if (mapa[mapaAtual].getTile((thief.getX() / 32), (thief.getY() / 32)).getId() == 3 && mapa[mapaAtual].getTile((thief.getX() / 32) + 1, (thief.getY() / 32)).getSolid()) {
				thief.setPos((thief.getX() / 32) -2, (thief.getY() / 32));
				thief.setAnimEsq();
				mapa[mapaAtual].setFirst(false);

			}

			// se for porta horizontal e na esquerda for solido
			else if (mapa[mapaAtual].getTile((thief.getX() / 32), (thief.getY() / 32)).getId() == 3 && mapa[mapaAtual].getTile((thief.getX() / 32) - 1, (thief.getY() / 32)).getSolid()) {
				thief.setPos((thief.getX() / 32) + 2, (thief.getY() / 32));
				thief.setAnimDir();
				mapa[mapaAtual].setFirst(false);

			}
		}
	}
}

void InputJogo::setFirstMap()
{
	mapa[mapaAtual].setFirst(true);
}

void InputJogo::setChests(int rx, int ry)
{
	mapa[mapaAtual].setTile(rx, ry, 8);
}

void InputJogo::setOpenChest(int rx, int ry)
{
	mapa[mapaAtual].setTile(rx, ry, 7);
}

bool InputJogo::isSolid(int &x, int &y)
{
	if (mapa[mapaAtual].getPos(x,y)!= NULL) {
		return mapa[mapaAtual].getTile(x, y).getSolid();
	}

	
}

Sprite InputJogo::getPlayerSprite()
{
	if (getClass() == 1) {
		return mage.getSprite();
	}
	else if (getClass() == 2) {
		return warrior.getSprite();
	}
	else if (getClass() == 3) {
		return thief.getSprite();
	}
}

int InputJogo::getPlayerX()
{
	if (getClass() == 1) {
		return mage.getX();
	}
	else if (getClass() == 2) {
		return warrior.getX();
	}
	else if(getClass() == 3) {
		return thief.getX();
	}
}

int InputJogo::getPlayerY()
{
	if (getClass() == 1) {
		return mage.getY();
	}
	else if (getClass() == 2) {
		return warrior.getY();
	}
	else if (getClass() == 3) {
		return thief.getY();
	}
}

Sprite InputJogo::getSpriteBau()
{
	return mapa[mapaAtual].getBauSprite();
}

void InputJogo::desenhar()
{
	desenharMonstros();

	if (getClass() == 1) {
		mage.desenhar();
	}
	else if (getClass() == 2) {
		warrior.desenhar();
	}
	else if (getClass() == 3) {
		thief.desenhar();
	}
}

void InputJogo::atualizar()
{
	atualizarMonstros();

	if (getClass() == 1) {
		atualizarMage();
	}
	else if (getClass() == 2) {
		atualizarWarrior();
	}
	else if (getClass() == 3) {
		atualizarThief();
	}
}

int InputJogo::getPlayerHP()
{
	if (getClass() == 1) {
		return mage.getHP();
	}
	else if (getClass() == 2) {
		return warrior.getHP();
	}
	else if (getClass() == 3) {
		return thief.getHP();
	}
}

int InputJogo::getPlayerMaxHP()
{
	if (getClass() == 1) {
		return mage.getMaxHP();
	}
	else if (getClass() == 2) {
		return warrior.getMaxHP();
	}
	else if (getClass() == 3) {
		return thief.getMaxHP();
	}
}

int InputJogo::getPlayerDef()
{
	if (getClass() == 1) {
		return mage.getDef();
	}
	else if (getClass() == 2) {
		return warrior.getDef();
	}
	else if (getClass() == 3) {
		return thief.getDef();
	}
}

int InputJogo::getPlayerAtk()
{
	if (getClass() == 1) {
		return mage.getAtk();
	}
	else if (getClass() == 2) {
		return warrior.getAtk();
	}
	else if (getClass() == 3) {
		return thief.getAtk();
	}
}

int InputJogo::getPlayerGold()
{
	if (getClass() == 1) {
		return mage.getGold();
	}
	else if (getClass() == 2) {
		return warrior.getGold();
	}
	else if (getClass() == 3) {
		return thief.getGold();
	}
}

void InputJogo::setPlayerGold(int gold)
{
	if (getClass() == 1) {
		 mage.setMoreGold(gold);
	}
	else if (getClass() == 2) {
		 warrior.setMoreGold(gold);
	}
	else if (getClass() == 3) {
		 thief.setMoreGold(gold);
	}
}

