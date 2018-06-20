#include "InputJogo.h"



InputJogo::InputJogo()
{
	mapaAtual = 0;
	playerItens = 0;
	bag = new Itens[10]; // inventario maximo
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
		bool podemover = false;


		if (!mage.estaMovendo()) {

			// mover direita
			if (gTeclado.pressionou[TECLA_D]) {
				if (mapa[mapaAtual].getTile((mage.getX() / 32) + 1, (mage.getY() / 32)).getId() == 1) {
					if (mapa[mapaAtual].getNMonsters() == 0) {
						mage.movDir();
					}
					else {
						for (int i = 0; i < mapa[mapaAtual].getNMonsters(); i++) {
							int mx = mapa[mapaAtual].getMonster(i).getX();
							int my = mapa[mapaAtual].getMonster(i).getY();

							if (((getPlayerX() / 32) + 1 == (mx / 32) && (getPlayerY() / 32) == (my / 32))) {
								podemover = false;
								break;
							}
							else
								podemover = true;

						}
					}
					
					if (podemover)
						mage.movDir();

					podemover = false;

				}
			}

			// mover esquerda
			else if (gTeclado.pressionou[TECLA_A]) {
				if (mapa[mapaAtual].getTile((mage.getX()/32) - 1, (mage.getY()/32)).getId() == 1) {
					if (mapa[mapaAtual].getNMonsters() == 0) {
						mage.movEsq();
					}
					else {
						for (int i = 0; i < mapa[mapaAtual].getNMonsters(); i++) {
							int mx = mapa[mapaAtual].getMonster(i).getX();
							int my = mapa[mapaAtual].getMonster(i).getY();

							if (((getPlayerX() / 32) - 1 == (mx / 32) && (getPlayerY() / 32) == (my / 32))) {
								podemover = false;
								break;
							}
							else
								podemover = true;

						}
					}

					if (podemover)
						mage.movEsq();

					podemover = false;
					
				}
			}

			// mover cima
			else if (gTeclado.pressionou[TECLA_W]) {
				if (mapa[mapaAtual].getTile((mage.getX()/32), (mage.getY()/32) - 1).getId() == 1) {
					if (mapa[mapaAtual].getNMonsters() == 0) {
						mage.movCima();
					}
					else {
						for (int i = 0; i < mapa[mapaAtual].getNMonsters(); i++) {
							int mx = mapa[mapaAtual].getMonster(i).getX();
							int my = mapa[mapaAtual].getMonster(i).getY();

							if ((getPlayerX() / 32) == (mx / 32) && (getPlayerY() / 32) - 1 == (my / 32)) {
								podemover = false;
								break;
							}
							else
								podemover = true;
						}
					}

					if (podemover)
						mage.movCima();
					podemover = false;
				}
			}

			// mover baixo
			else if (gTeclado.pressionou[TECLA_S]) {
				if (mapa[mapaAtual].getTile((mage.getX() / 32), (mage.getY() / 32) + 1).getId() == 1) {
					if (mapa[mapaAtual].getNMonsters() == 0) {
						mage.movBaixo();
					}
					else {
						for (int i = 0; i < mapa[mapaAtual].getNMonsters(); i++) {
							int mx = mapa[mapaAtual].getMonster(i).getX();
							int my = mapa[mapaAtual].getMonster(i).getY();

							if ((getPlayerX() / 32) == (mx / 32) && (getPlayerY() / 32) + 1 == (my / 32)) {

								podemover = false;
								break;
							}
							else
								podemover = true;
						}
					}

					if (podemover)
						mage.movBaixo();

					podemover = false;
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
		bool podemover = false;

		if (!warrior.estaMovendo()) {

			// mover direita
			if (gTeclado.pressionou[TECLA_D]) {
				if (mapa[mapaAtual].getTile((warrior.getX() / 32) + 1, (warrior.getY() / 32)).getId() == 1) {
					if (mapa[mapaAtual].getNMonsters() == 0) {
						warrior.movDir();
					}
					else {
						for (int i = 0; i < mapa[mapaAtual].getNMonsters(); i++) {
							int mx = mapa[mapaAtual].getMonster(i).getX();
							int my = mapa[mapaAtual].getMonster(i).getY();

							if ((getPlayerX() / 32) + 1 == (mx / 32) && (getPlayerY() / 32) == (my / 32)) {
								podemover = false;
								break;
							}
							else
								podemover = true;
						}
					}
					
					if (podemover)
						warrior.movDir();

					podemover = false;
				}
			}

			// mover esquerda
			else if (gTeclado.pressionou[TECLA_A]) {
				if (mapa[mapaAtual].getTile((warrior.getX() / 32) - 1, (warrior.getY() / 32)).getId() == 1) {
					if (mapa[mapaAtual].getNMonsters() == 0) {
						warrior.movEsq();
					}
					else {
						for (int i = 0; i < mapa[mapaAtual].getNMonsters(); i++) {
							int mx = mapa[mapaAtual].getMonster(i).getX();
							int my = mapa[mapaAtual].getMonster(i).getY();

							if ((getPlayerX() / 32) - 1 == (mx / 32) && (getPlayerY() / 32) == (my / 32)) {
								podemover = false;
								break;
							}
							else
								podemover = true;
						}
					}
					
					if (podemover)
						warrior.movEsq();

					podemover = false;
				}
			}

			// mover cima
			else if (gTeclado.pressionou[TECLA_W]) {
				if (mapa[mapaAtual].getTile((warrior.getX() / 32), (warrior.getY() / 32) - 1).getId() == 1) {
					if (mapa[mapaAtual].getNMonsters() == 0) {
						warrior.movCima();
					}
					else {
						for (int i = 0; i < mapa[mapaAtual].getNMonsters(); i++) {
							int mx = mapa[mapaAtual].getMonster(i).getX();
							int my = mapa[mapaAtual].getMonster(i).getY();

							if ((getPlayerX() / 32) == (mx / 32) && (getPlayerY() / 32) - 1 == (my / 32)) {
								podemover = false;
								break;
							}
							else
								podemover = true;
						}
					}
					
					if (podemover)
						warrior.movCima();

					podemover = false;
				}

		
			}

			// mover baixo
			else if (gTeclado.pressionou[TECLA_S]) {
				if (mapa[mapaAtual].getTile((warrior.getX() / 32), (warrior.getY() / 32) + 1).getId() == 1) {
					if (mapa[mapaAtual].getNMonsters() == 0) {
						warrior.movBaixo();
					}
					else {
						for (int i = 0; i < mapa[mapaAtual].getNMonsters(); i++) {
							int mx = mapa[mapaAtual].getMonster(i).getX();
							int my = mapa[mapaAtual].getMonster(i).getY();

							if ((getPlayerX() / 32) == (mx / 32) && (getPlayerY() / 32) + 1 == (my / 32)) {
								podemover = false;
								break;
							}
							else
								podemover = true;
						}
					}
					if (podemover)
						warrior.movBaixo();

					podemover = false;
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
		bool podemover = false;

		if (!thief.estaMovendo()) {

			// mover direita
			if (gTeclado.pressionou[TECLA_D]) {
				if (mapa[mapaAtual].getTile((thief.getX() / 32) + 1, (thief.getY() / 32)).getId() == 1) {
					if (mapa[mapaAtual].getNMonsters() == 0) {
						thief.movDir();
					}
					else {
						for (int i = 0; i < mapa[mapaAtual].getNMonsters(); i++) {
							int mx = mapa[mapaAtual].getMonster(i).getX();
							int my = mapa[mapaAtual].getMonster(i).getY();

							if ((getPlayerX() / 32) + 1 == (mx / 32) && (getPlayerY() / 32) == (my / 32)) {
								podemover = false;
								break;
							}
							else
								podemover = true;
						}
					}
					if (podemover)
						thief.movDir();

					podemover = false;
				}
			}

			// mover esquerda
			else if (gTeclado.pressionou[TECLA_A]) {
				if (mapa[mapaAtual].getTile((thief.getX() / 32) - 1, (thief.getY() / 32)).getId() == 1) {
					if (mapa[mapaAtual].getNMonsters() == 0) {
						thief.movEsq();
					}
					else {
						for (int i = 0; i < mapa[mapaAtual].getNMonsters(); i++) {
							int mx = mapa[mapaAtual].getMonster(i).getX();
							int my = mapa[mapaAtual].getMonster(i).getY();

							if ((getPlayerX() / 32) - 1 == (mx / 32) && (getPlayerY() / 32) == (my / 32)) {
								podemover = false;
								break;

							}
							else
								podemover = true;
						}
					}
					if (podemover)
						thief.movEsq();

					podemover = false;
				}
			}

			// mover cima
			else if (gTeclado.pressionou[TECLA_W]) {
				if (mapa[mapaAtual].getTile((thief.getX() / 32), (thief.getY() / 32) - 1).getId() == 1) {
					if (mapa[mapaAtual].getNMonsters() == 0) {
						thief.movCima();
					}
					else {
						for (int i = 0; i < mapa[mapaAtual].getNMonsters(); i++) {
							int mx = mapa[mapaAtual].getMonster(i).getX();
							int my = mapa[mapaAtual].getMonster(i).getY();

							if ((getPlayerX() / 32) == (mx / 32) && (getPlayerY() / 32) - 1 == (my / 32)) {
								podemover = false;
								break;

							}
							else
								podemover = true;
						}
					}
					if (podemover)
						thief.movCima();

					podemover = false;
					
				}
			}

			// mover baixo
			else if (gTeclado.pressionou[TECLA_S]) {
				if (mapa[mapaAtual].getTile((thief.getX() / 32), (thief.getY() / 32) + 1).getId() == 1) {
					if (mapa[mapaAtual].getNMonsters() == 0) {
						thief.movBaixo();
					}
					else {

					}for (int i = 0; i < mapa[mapaAtual].getNMonsters(); i++) {
						int mx = mapa[mapaAtual].getMonster(i).getX();
						int my = mapa[mapaAtual].getMonster(i).getY();

						if ((getPlayerX() / 32) == (mx / 32) && (getPlayerY() / 32) + 1 == (my / 32)) {
							podemover = false;
							break;

						}
						else
							podemover = true;
					}
					
					if (podemover)
						thief.movBaixo();

					podemover = false;
				}
			}
		}

		

	}
}

void InputJogo::desenharThief()
{
	thief.desenhar();
}

void InputJogo::lerItens(std::string arq)
{
	std::string nome;
	std::string caminho;
	int bAtk, bDano, bDef, bHp, bMaxHp;

	ifstream itens(arq);

	if (itens) {

		itens >> totalItens;

		i_atk = new int[totalItens];
		i_caminho = new std::string[totalItens];
		i_def = new int[totalItens];
		i_hp = new int[totalItens];
		i_maxhp = new int[totalItens];
		i_nome = new std::string[totalItens];

		for (int i = 0; i < totalItens; i++) {
			itens >> nome >> caminho >> bHp >> bMaxHp >> bDef >> bAtk;
			i_nome[i] = nome;
			i_caminho[i] = caminho;
			i_hp[i] = bHp;
			i_maxhp[i] = bMaxHp;
			i_def[i] = bDef;
			i_atk[i] = bAtk;
		}
	}
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
			int random =  uniRandEntre(0, nMonstros-1);

			// inicializar o monstro do mapa com os mesmos dados do tipo random
			mapa[mapaAtual].inicializaMonstro(i, m_id[random], m_def[random], m_hp[random], m_nome[random], m_sheet[random]);

			// setar uma posição para o monstro (em tiles)
			int rx, ry;
			do {
				rx = uniRandEntre(1, 29);
				ry = uniRandEntre(1, 21);
			} while (mapa[mapaAtual].getTile(rx,ry).getId() != 1);

			mapa[mapaAtual].getTile(rx, ry).setMonster();
			mapa[mapaAtual].getMonster(i).setPos(rx, ry);
			
		
		
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
	// se o mapa é o primeiro
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

bool &InputJogo::isPorta(int x, int y)
{
	return mapa[mapaAtual].getTile(x, y).getPorta();
}

void InputJogo::setChests(int rx, int ry)
{
	mapa[mapaAtual].setTile(rx, ry, 8);
}

void InputJogo::setOpenChest(int rx, int ry)
{
	mapa[mapaAtual].setTile(rx, ry, 7);
}

bool InputJogo::isSolid(int x, int y)
{
	if (mapa[mapaAtual].getPos(x,y)!= NULL) {
		return mapa[mapaAtual].getTile(x, y).getSolid();
	}

	
}

bool InputJogo::isMonster(int  x, int  y)
{
	if (mapa[mapaAtual].getPos(x, y) != NULL) {
		return mapa[mapaAtual].getTile(x, y).isMonster();
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

void InputJogo::desenharItens()
{

	for (int i = 0; i < 10; i++) {

		if (&bag[i] != NULL) {
			bag[i].desenhar();
		}
	}
}

int InputJogo::getTotalItens()
{
	return totalItens;
}

void InputJogo::addBonusItem(int bonusHP, int bonusMaxHP, int bonusDef, int bonusAtk)
{
	if (getClass() == 1) {
		mage.setMoreHP(bonusHP);
		mage.setMoreMaxHP(bonusMaxHP);
		mage.setMoreDef(bonusDef);
		mage.setMoreAtk(bonusAtk);
	}
	else if (getClass() == 2) {
		warrior.setMoreHP(bonusHP);
		warrior.setMoreMaxHP(bonusMaxHP);
		warrior.setMoreDef(bonusDef);
		warrior.setMoreAtk(bonusAtk);
	}
	else if (getClass() == 3) {
		thief.setMoreHP(bonusHP);
		thief.setMoreMaxHP(bonusMaxHP);
		thief.setMoreMaxHP(bonusMaxHP);
		thief.setMoreDef(bonusDef);
		thief.setMoreAtk(bonusAtk);
	}
}

void InputJogo::atualizar()
{
	atualizarMonstros();

	atualizarBatalha();

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

void InputJogo::atualizarBag()
{

	// tecla 1 = 30
	// tecla 0 = 39
	
	int i = 0;

	for (int tecla = 30; tecla < 40; tecla++) { // tecla 1 a 9
		if (gTeclado.pressionou[tecla]) {
			if (bag[i].isInBag()) {
				if (bag[i].getNome() == "pao") {
					if (getPlayerHP() == getPlayerMaxHP())
						break;
				}
				addBonusItem(bag[i].gethp(), bag[i].getmaxhp(), bag[i].getdef(), bag[i].getatk());
				deleteItem(i);
				break;
			}
		}

		i++; //incrementa i de fora
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

void InputJogo::setPlayerHP(int hp)
{
	if (getClass() == 1) {
		mage.setMoreHP(hp);
	}
	else if (getClass() == 2) {
		warrior.setMoreHP(hp);
	}
	else if (getClass() == 3) {
		thief.setMoreHP(hp);
	}
}

void InputJogo::addItem(int tipo)
{
	int r = tipo;

	if (playerItens < 10) {

		// array bag auxiliar na criação da lista
		bag[playerItens].create(playerItens, i_nome[r], i_caminho[r], i_hp[r], i_maxhp[r], i_def[r], i_atk[r]); 
		bag[playerItens].addBag();
		// lista armazena os itens atuais no iventário
		lista.add_final(bag[playerItens]);
		
		playerItens++;
	}

}

// deletar ou usar
void InputJogo::deleteItem(int id)
{

	lista.remover(bag[id]); // remove da lista
	for (int i = id; i < playerItens; i++)
	{
		bag[i+1].setPos(bag[i+1].getX() - 42, bag[i+1].getY()); // reposiciona na tela

		bag[i] = bag[i + 1]; // sobrescreve no array

	}

	playerItens--;


}

bool InputJogo::podePosicionar(int x, int y)
{
	// variáveis para até 2 posições em volta

	int x2 = x + 2;
	int x1 = x + 1;

	int y2 = y + 2;
	int y1 = y + 1;

	int x22 = x - 2;
	int x11 = x - 1;

	int y22 = y - 2;
	int y11 = y - 1;


	// se é sólido, não posiciona

	if (isSolid(x, y))
		return false;

	else if (isSolid(x1, y))
		return false;

	else if (isSolid(x2, y))
		return false;

	else if (isSolid(x11, y))
		return false;

	else if (isSolid(x22, y))
		return false;

	else if (isSolid(x, y1))
		return false;

	else if (isSolid(x, y2))
		return false;

	else if (isSolid(x, y11))
		return false;

	else if (isSolid(x, y22))
		return false;

	// não posiciona se for monstro

	if (isMonster(x, y))
		return false;

	else if (isMonster(x1, y))
		return false;

	else if (isMonster(x2, y))
		return false;

	else if (isMonster(x11, y))
		return false;

	else if (isMonster(x22, y))
		return false;

	else if (isMonster(x, y1))
		return false;

	else if (isMonster(x, y2))
		return false;

	else if (isMonster(x, y11))
		return false;

	else if (isMonster(x, y22))
		return false;

	// não posiciona na porta

	else if (isPorta(x, y))
		return false;

	else if (isPorta(x1, y))
		return false;

	else if (isPorta(x11, y))
		return false;

	else if (isPorta(x2, y))
		return false;

	else if (isPorta(x22, y))
		return false;

	else if (isPorta(x, y1))
		return false;

	else if (isPorta(x, y11))
		return false;

	else if (isPorta(x, y2))
		return false;

	else if (isPorta(x, y22))
		return false;

	// não posiciona no jogador

	else if (x == (getPlayerX() / 32) && y == (getPlayerY() / 32))
		return false;

	else if (x == (getPlayerX() / 32) + 1 && y == (getPlayerY() / 32))
		return false;

	else if (x == (getPlayerX() / 32) - 1 && y == (getPlayerY() / 32))
		return false;

	else if (x == (getPlayerX() / 32) && y == (getPlayerY() / 32) + 1)
		return false;

	else if (x == (getPlayerX() / 32) && y == (getPlayerY() / 32) - 1)
		return false;

	else
		return true;
}

void InputJogo::atualizarBatalha()
{
	int px = getPlayerX() / 32;
	int py = getPlayerY() / 32;

	int mx, my;

	int mon = 100;

	// ataque
	int patk = uniRandEntre(2, 12);
	int matk;

	patk += getPlayerAtk();

	if (gTeclado.pressionou[TECLA_ESPACO]) {
		// monstro existe
	
			for (int i = 0; i < mapa[mapaAtual].getNMonsters(); i++) {
				mx = mapa[mapaAtual].getMonster(i).getX();
				my = mapa[mapaAtual].getMonster(i).getY();

				if (getPlayerX() / 32 == (mx / 32) + 1 || getPlayerX() / 32 == (mx / 32) - 1 || getPlayerY() / 32 == (my / 32) + 1 ||
					getPlayerY() / 32 == (my / 32) - 1) {

					mon = i;
					break;
				}
			}

			// se existe monstro
			if (mon != 100) {
				matk = mapa[mapaAtual].getMonster(mon).getAtk();
				matk += uniRandEntre(2,12);
				matk -= getPlayerDef();

				if (matk < 0) 
					matk = 1;
				
				matk = -matk; // negativo para causar dano



				patk -= mapa[mapaAtual].getMonster(mon).getDef();

				if (patk < 0) 
					patk = 1;

				patk = - patk; // negativo para causar dano

				// alterar a vida
				mapa[mapaAtual].getMonster(mon).setMoreHP(patk);
				setPlayerHP(matk);

				if (mapa[mapaAtual].getMonster(mon).getHP() <= 0) {
					mapa[mapaAtual].getMonster(mon).setPos(-100, -100);
				}

			}

	}
}

void InputJogo::newBag()
{
	bag = new Itens[10]; // inventario maximo
	playerItens = 0;
	lista.clear();

}

void InputJogo::unselectAll()
{
	mage.unselect();
	warrior.unselect();
	thief.unselect();
}

void InputJogo::resetMonsters()
{
	mapa[mapaAtual].setMonstersDone(true);

}

void InputJogo::criarSalas(int n)
{
	mapa = new myTilemap[n];
}
