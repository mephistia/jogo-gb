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
				if (sala[mapaAtual].getTile((mage.getX() / 32) + 1, (mage.getY() / 32)).getId() == 1
					|| sala[mapaAtual].getTile((mage.getX() / 32) + 1, (mage.getY() / 32)).getId() == 3
					|| sala[mapaAtual].getTile((mage.getX() / 32) + 1, (mage.getY() / 32)).getId() == 4) {
					if (sala[mapaAtual].getNMonsters() == 0) {
						mage.movDir();
					}
					else {
						for (int i = 0; i < sala[mapaAtual].getNMonsters(); i++) {
							int mx = sala[mapaAtual].getMonster(i).getX();
							int my = sala[mapaAtual].getMonster(i).getY();

							if (((getPlayerX() / 32) + 1 == (mx / 32) && (getPlayerY() / 32) == (my / 32))) {
								podemover = false;
								break;
							}
							else {
								podemover = true;
								moveMonster(i);
							}

						}
					}
					
					if (podemover)
						mage.movDir();

					podemover = false;

				}
			}

			// mover esquerda
			else if (gTeclado.pressionou[TECLA_A]) {
				if (sala[mapaAtual].getTile((mage.getX()/32) - 1, (mage.getY()/32)).getId() == 1
					|| sala[mapaAtual].getTile((mage.getX() / 32) - 1, (mage.getY() / 32)).getId() == 3
					|| sala[mapaAtual].getTile((mage.getX() / 32) - 1, (mage.getY() / 32)).getId() == 4) {
					if (sala[mapaAtual].getNMonsters() == 0) {
						mage.movEsq();
					}
					else {
						for (int i = 0; i < sala[mapaAtual].getNMonsters(); i++) {
							int mx = sala[mapaAtual].getMonster(i).getX();
							int my = sala[mapaAtual].getMonster(i).getY();

							if (((getPlayerX() / 32) - 1 == (mx / 32) && (getPlayerY() / 32) == (my / 32))) {
								podemover = false;
								break;
							}
							else {
								podemover = true;

								moveMonster(i);

							}

						}
					}

					if (podemover)
						mage.movEsq();

					podemover = false;
					
				}
			}

			// mover cima
			else if (gTeclado.pressionou[TECLA_W]) {
				if (sala[mapaAtual].getTile((mage.getX()/32), (mage.getY()/32) - 1).getId() == 1
					|| sala[mapaAtual].getTile((mage.getX() / 32), (mage.getY() / 32) - 1).getId() == 3
					|| sala[mapaAtual].getTile((mage.getX() / 32), (mage.getY() / 32) - 1).getId() == 4) {
					if (sala[mapaAtual].getNMonsters() == 0) {
						mage.movCima();
					}
					else {
						for (int i = 0; i < sala[mapaAtual].getNMonsters(); i++) {
							int mx = sala[mapaAtual].getMonster(i).getX();
							int my = sala[mapaAtual].getMonster(i).getY();

							if ((getPlayerX() / 32) == (mx / 32) && (getPlayerY() / 32) - 1 == (my / 32)) {
								podemover = false;
								break;
							}
							else
							{
								podemover = true;

								moveMonster(i);

							}
						}
					}

					if (podemover)
						mage.movCima();
					podemover = false;
				}
			}

			// mover baixo
			else if (gTeclado.pressionou[TECLA_S]) {
				if (sala[mapaAtual].getTile((mage.getX() / 32), (mage.getY() / 32) + 1).getId() == 1
					|| sala[mapaAtual].getTile((mage.getX() / 32), (mage.getY() / 32) + 1).getId() == 3
					|| sala[mapaAtual].getTile((mage.getX() / 32), (mage.getY() / 32) + 1).getId() == 4) {
					if (sala[mapaAtual].getNMonsters() == 0) {
						mage.movBaixo();
					}
					else {
						for (int i = 0; i < sala[mapaAtual].getNMonsters(); i++) {
							int mx = sala[mapaAtual].getMonster(i).getX();
							int my = sala[mapaAtual].getMonster(i).getY();

							if ((getPlayerX() / 32) == (mx / 32) && (getPlayerY() / 32) + 1 == (my / 32)) {

								podemover = false;
								break;
							}
							else
							{
								podemover = true;

								moveMonster(i);

							}
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
				if (sala[mapaAtual].getTile((warrior.getX() / 32) + 1, (warrior.getY() / 32)).getId() == 1
					|| sala[mapaAtual].getTile((warrior.getX() / 32) + 1, (warrior.getY() / 32)).getId() == 3
					|| sala[mapaAtual].getTile((warrior.getX() / 32) + 1, (warrior.getY() / 32)).getId() == 4) {
					if (sala[mapaAtual].getNMonsters() == 0) {
						warrior.movDir();
					}
					else {
						for (int i = 0; i <sala[mapaAtual].getNMonsters(); i++) {
							int mx = sala[mapaAtual].getMonster(i).getX();
							int my = sala[mapaAtual].getMonster(i).getY();

							if ((getPlayerX() / 32) + 1 == (mx / 32) && (getPlayerY() / 32) == (my / 32)) {
								podemover = false;
								break;
							}
							else
							{
								podemover = true;

								moveMonster(i);

							}
						}
					}
					
					if (podemover)
						warrior.movDir();

					podemover = false;
				}
			}

			// mover esquerda
			else if (gTeclado.pressionou[TECLA_A]) {
				if (sala[mapaAtual].getTile((warrior.getX() / 32) - 1, (warrior.getY() / 32)).getId() == 1
					|| sala[mapaAtual].getTile((warrior.getX() / 32) - 1, (warrior.getY() / 32)).getId() == 3
					|| sala[mapaAtual].getTile((warrior.getX() / 32) - 1, (warrior.getY() / 32)).getId() == 4) {
					if (sala[mapaAtual].getNMonsters() == 0) {
						warrior.movEsq();
					}
					else {
						for (int i = 0; i < sala[mapaAtual].getNMonsters(); i++) {
							int mx = sala[mapaAtual].getMonster(i).getX();
							int my = sala[mapaAtual].getMonster(i).getY();

							if ((getPlayerX() / 32) - 1 == (mx / 32) && (getPlayerY() / 32) == (my / 32)) {
								podemover = false;
								break;
							}
							else
							{
								podemover = true;

								moveMonster(i);

							}
						}
					}
					
					if (podemover)
						warrior.movEsq();

					podemover = false;
				}
			}

			// mover cima
			else if (gTeclado.pressionou[TECLA_W]) {
				if (sala[mapaAtual].getTile((warrior.getX() / 32), (warrior.getY() / 32) - 1).getId() == 1
					|| sala[mapaAtual].getTile((warrior.getX() / 32), (warrior.getY() / 32) - 1).getId() == 3
					|| sala[mapaAtual].getTile((warrior.getX() / 32), (warrior.getY() / 32) - 1).getId() == 4) {
					if (sala[mapaAtual].getNMonsters() == 0) {
						warrior.movCima();
					}
					else {
						for (int i = 0; i < sala[mapaAtual].getNMonsters(); i++) {
							int mx = sala[mapaAtual].getMonster(i).getX();
							int my = sala[mapaAtual].getMonster(i).getY();

							if ((getPlayerX() / 32) == (mx / 32) && (getPlayerY() / 32) - 1 == (my / 32)) {
								podemover = false;
								break;
							}
							else
							{
								podemover = true;

								moveMonster(i);

							}
						}
					}
					
					if (podemover)
						warrior.movCima();

					podemover = false;
				}

		
			}

			// mover baixo
			else if (gTeclado.pressionou[TECLA_S]) {
				if (sala[mapaAtual].getTile((warrior.getX() / 32), (warrior.getY() / 32) + 1).getId() == 1
					|| sala[mapaAtual].getTile((warrior.getX() / 32), (warrior.getY() / 32) + 1).getId() == 3
					|| sala[mapaAtual].getTile((warrior.getX() / 32), (warrior.getY() / 32) + 1).getId() == 4) {
					if (sala[mapaAtual].getNMonsters() == 0) {
						warrior.movBaixo();
					}
					else {
						for (int i = 0; i < sala[mapaAtual].getNMonsters(); i++) {
							int mx = sala[mapaAtual].getMonster(i).getX();
							int my = sala[mapaAtual].getMonster(i).getY();

							if ((getPlayerX() / 32) == (mx / 32) && (getPlayerY() / 32) + 1 == (my / 32)) {
								podemover = false;
								break;
							}
							else
							{
								podemover = true;

								moveMonster(i);

							}
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
				if (sala[mapaAtual].getTile((thief.getX() / 32) + 1, (thief.getY() / 32)).getId() == 1
					|| sala[mapaAtual].getTile((thief.getX() / 32) + 1, (thief.getY() / 32)).getId() == 3
					|| sala[mapaAtual].getTile((thief.getX() / 32) + 1, (thief.getY() / 32)).getId() == 4) {
					if (sala[mapaAtual].getNMonsters() == 0) {
						thief.movDir();
					}
					else {
						for (int i = 0; i < sala[mapaAtual].getNMonsters(); i++) {
							int mx = sala[mapaAtual].getMonster(i).getX();
							int my = sala[mapaAtual].getMonster(i).getY();

							if ((getPlayerX() / 32) + 1 == (mx / 32) && (getPlayerY() / 32) == (my / 32)) {
								podemover = false;
								break;
							}
							else
							{
								podemover = true;

								moveMonster(i);

							}
						}
					}
					if (podemover)
						thief.movDir();

					podemover = false;
				}
			}

			// mover esquerda
			else if (gTeclado.pressionou[TECLA_A]) {
				if (sala[mapaAtual].getTile((thief.getX() / 32) - 1, (thief.getY() / 32)).getId() == 1
					|| sala[mapaAtual].getTile((thief.getX() / 32) - 1, (thief.getY() / 32)).getId() == 3
					|| sala[mapaAtual].getTile((thief.getX() / 32) - 1, (thief.getY() / 32)).getId() == 4) {
					if (sala[mapaAtual].getNMonsters() == 0) {
						thief.movEsq();
					}
					else {
						for (int i = 0; i < sala[mapaAtual].getNMonsters(); i++) {
							int mx = sala[mapaAtual].getMonster(i).getX();
							int my = sala[mapaAtual].getMonster(i).getY();

							if ((getPlayerX() / 32) - 1 == (mx / 32) && (getPlayerY() / 32) == (my / 32)) {
								podemover = false;
								break;

							}
							else
							{
								podemover = true;

								moveMonster(i);

							}
						}
					}
					if (podemover)
						thief.movEsq();

					podemover = false;
				}
			}

			// mover cima
			else if (gTeclado.pressionou[TECLA_W]) {
				if (sala[mapaAtual].getTile((thief.getX() / 32), (thief.getY() / 32) - 1).getId() == 1
					|| sala[mapaAtual].getTile((thief.getX() / 32), (thief.getY() / 32) - 1).getId() == 3
					|| sala[mapaAtual].getTile((thief.getX() / 32), (thief.getY() / 32) - 1).getId() == 4) {
					if (sala[mapaAtual].getNMonsters() == 0) {
						thief.movCima();
					}
					else {
						for (int i = 0; i < sala[mapaAtual].getNMonsters(); i++) {
							int mx = sala[mapaAtual].getMonster(i).getX();
							int my = sala[mapaAtual].getMonster(i).getY();

							if ((getPlayerX() / 32) == (mx / 32) && (getPlayerY() / 32) - 1 == (my / 32)) {
								podemover = false;
								break;

							}
							else
							{
								podemover = true;

								moveMonster(i);

							}
						}
					}
					if (podemover)
						thief.movCima();

					podemover = false;
					
				}
			}

			// mover baixo
			else if (gTeclado.pressionou[TECLA_S]) {
				if (sala[mapaAtual].getTile((thief.getX() / 32), (thief.getY() / 32) + 1).getId() == 1
					|| sala[mapaAtual].getTile((thief.getX() / 32), (thief.getY() / 32) + 1).getId() == 3
					|| sala[mapaAtual].getTile((thief.getX() / 32), (thief.getY() / 32) + 1).getId() == 4) {
					if (sala[mapaAtual].getNMonsters() == 0) {
						thief.movBaixo();
					}
					else {

					}for (int i = 0; i < sala[mapaAtual].getNMonsters(); i++) {
						int mx = sala[mapaAtual].getMonster(i).getX();
						int my = sala[mapaAtual].getMonster(i).getY();

						if ((getPlayerX() / 32) == (mx / 32) && (getPlayerY() / 32) + 1 == (my / 32)) {
							podemover = false;
							break;

						}
						else
						{
							podemover = true;

							moveMonster(i);

						}
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


void InputJogo::desenharMonstros()
{


	for (int i = 0; i < sala[mapaAtual].getNMonsters(); i++) {
		
		sala[mapaAtual].getMonster(i).desenhar();
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

void InputJogo::setPosInicial2()
{
	if (getClass() == 1) {
		mage.setPos(1, 6);
	}
	else if (getClass() == 2) {
		warrior.setPos(1, 6);
	}
	else if (getClass() == 3) {
		thief.setPos(1, 6);
	}
}

void InputJogo::setPosInicial3()
{
	if (getClass() == 1) {
		mage.setPos(24, 1);
	}
	else if (getClass() == 2) {
		warrior.setPos(24, 1);
	}
	else if (getClass() == 3) {
		thief.setPos(24, 1);
	}
}

void InputJogo::setPosInicial4()
{
	if (getClass() == 1) {
		mage.setPos(1, 4);
	}
	else if (getClass() == 2) {
		warrior.setPos(1, 4);
	}
	else if (getClass() == 3) {
		thief.setPos(1, 4);
	}
}

void InputJogo::setPosInicial5()
{
	if (getClass() == 1) {
		mage.setPos(30, 6);
	}
	else if (getClass() == 2) {
		warrior.setPos(30, 6);
	}
	else if (getClass() == 3) {
		thief.setPos(30, 6);
	}
}

// posições da porta de baixo
void InputJogo::setPosVolta0()
{
	if (getClass() == 1) {
		mage.setPos(15, 22);
	}
	else if (getClass() == 2) {
		warrior.setPos(15, 22);
	}
	else if (getClass() == 3) {
		thief.setPos(15, 22);
	}
}

void InputJogo::setPosVolta1()
{
	if (getClass() == 1) {
		mage.setPos(30, 16);
	}
	else if (getClass() == 2) {
		warrior.setPos(30, 16);
	}
	else if (getClass() == 3) {
		thief.setPos(30, 16);
	}
}

void InputJogo::setPosVolta2()
{
	if (getClass() == 1) {
		mage.setPos(24, 22);
	}
	else if (getClass() == 2) {
		warrior.setPos(24, 22);
	}
	else if (getClass() == 3) {
		thief.setPos(24, 22);
	}
}

void InputJogo::setPosVolta3()
{
	if (getClass() == 1) {
		mage.setPos(1, 16);
	}
	else if (getClass() == 2) {
		warrior.setPos(1, 16);
	}
	else if (getClass() == 3) {
		thief.setPos(1, 16);
	}
}

void InputJogo::setPosVolta4()
{
	if (getClass() == 1) {
		mage.setPos(1, 19);
	}
	else if (getClass() == 2) {
		warrior.setPos(1, 19);
	}
	else if (getClass() == 3) {
		thief.setPos(1, 19);
	}
}

void InputJogo::setPosVolta5()
{
	if (getClass() == 1) {
		mage.setPos(7, 22);
	}
	else if (getClass() == 2) {
		warrior.setPos(7, 22);
	}
	else if (getClass() == 3) {
		thief.setPos(7, 22);
	}
}

void InputJogo::setPosPorta()
{
		if (getClass() == 1) {

			// se for porta vertical e em cima for solido
			if (sala[mapaAtual].getTile((mage.getX() / 32), (mage.getY() / 32)).getId() == 4 && sala[mapaAtual].getTile((mage.getX() / 32), (mage.getY() / 32) - 1).getSolid()) {
				mage.setPos((mage.getX() / 32), (mage.getY() / 32) + 2);
				mage.setAnimBaixo();
			}

			// se for porta vertical e embaixo for solido
			else if (sala[mapaAtual].getTile((mage.getX() / 32), (mage.getY() / 32)).getId() == 4 && sala[mapaAtual].getTile((mage.getX() / 32), (mage.getY() / 32) + 1).getSolid()) {
				mage.setPos((mage.getX()/32), (mage.getY()/32) - 2);
				mage.setAnimCima();

			}

			// se for porta horizontal e na direita for solido
			else if (sala[mapaAtual].getTile((mage.getX() / 32), (mage.getY() / 32)).getId() == 3 && sala[mapaAtual].getTile((mage.getX() / 32) + 1, (mage.getY() / 32)).getSolid()) {
				mage.setPos((mage.getX()/32) - 2 , (mage.getY()/32));
				mage.setAnimEsq();

			}

			// se for porta horizontal e na esquerda for solido
			else if (sala[mapaAtual].getTile((mage.getX() / 32), (mage.getY() / 32)).getId() == 3 && sala[mapaAtual].getTile((mage.getX() / 32) - 1, (mage.getY() / 32)).getSolid()) {
				mage.setPos((mage.getX()/32) +2, (mage.getY()/32));
				mage.setAnimDir();

			}
		}

		else if (getClass() == 2) {
			// se for porta vertical e em cima for solido
			if (sala[mapaAtual].getTile((warrior.getX() / 32), (warrior.getY() / 32)).getId() == 4 && sala[mapaAtual].getTile((warrior.getX() / 32), (warrior.getY() / 32) - 1).getSolid()) {
				warrior.setPos((warrior.getX()/32), (warrior.getY()/32) + 2);
				warrior.setAnimBaixo();

			}

			// se for porta vertical e embaixo for solido
			else if (sala[mapaAtual].getTile((warrior.getX() / 32), (warrior.getY() / 32)).getId() == 4 && sala[mapaAtual].getTile((warrior.getX() / 32), (warrior.getY() / 32) + 1).getSolid()) {
				warrior.setPos((warrior.getX() / 32), (warrior.getY() / 32) - 2);
				warrior.setAnimCima();


			}

			// se for porta horizontal e na direita for solido
			else if (sala[mapaAtual].getTile((warrior.getX() / 32), (warrior.getY() / 32)).getId() == 3 && sala[mapaAtual].getTile((warrior.getX() / 32) + 1, (warrior.getY() / 32)).getSolid()) {
				warrior.setPos((warrior.getX() / 32) - 2, (warrior.getY() / 32));
				warrior.setAnimEsq();

			}

			// se for porta horizontal e na esquerda for solido
			else if (sala[mapaAtual].getTile((warrior.getX() / 32), (warrior.getY() / 32)).getId() == 3 && sala[mapaAtual].getTile((warrior.getX() / 32) - 1, (warrior.getY() / 32)).getSolid()) {
				warrior.setPos((warrior.getX() / 32) + 2, (warrior.getY() / 32));
				warrior.setAnimDir();

			}
		}

		else if (getClass() == 3) {
			// se for porta vertical e em cima for solido
			if (sala[mapaAtual].getTile((thief.getX() / 32), (thief.getY() / 32)).getId() == 4 && sala[mapaAtual].getTile((thief.getX() / 32), (thief.getY() / 32) - 1).getSolid()) {
				thief.setPos((thief.getX() / 32), (thief.getY() / 32) + 2);
				thief.setAnimBaixo();

			}

			// se for porta vertical e embaixo for solido
			else if (sala[mapaAtual].getTile((thief.getX() / 32), (thief.getY() / 32)).getId() == 4 && sala[mapaAtual].getTile((thief.getX() / 32), (thief.getY() / 32) + 1).getSolid()) {
				thief.setPos((thief.getX() / 32), (thief.getY() / 32) - 2);
				thief.setAnimCima();


			}

			// se for porta horizontal e na direita for solido
			else if (sala[mapaAtual].getTile((thief.getX() / 32), (thief.getY() / 32)).getId() == 3 && sala[mapaAtual].getTile((thief.getX() / 32) + 1, (thief.getY() / 32)).getSolid()) {
				thief.setPos((thief.getX() / 32) -2, (thief.getY() / 32));
				thief.setAnimEsq();

			}

			// se for porta horizontal e na esquerda for solido
			else if (sala[mapaAtual].getTile((thief.getX() / 32), (thief.getY() / 32)).getId() == 3 && sala[mapaAtual].getTile((thief.getX() / 32) - 1, (thief.getY() / 32)).getSolid()) {
				thief.setPos((thief.getX() / 32) + 2, (thief.getY() / 32));
				thief.setAnimDir();

			}
		}
	

}


bool &InputJogo::isPorta(int x, int y)
{
	
	return sala[mapaAtual].getTile(x, y).getPorta();
}


bool InputJogo::isSolid(int x, int y)
{
	if (sala[mapaAtual].getPos(x,y)!= NULL) {
		return sala[mapaAtual].getTile(x, y).getSolid();
	}

	
}

bool InputJogo::isMonster(int  x, int  y)
{
	if (sala[mapaAtual].getPos(x, y) != NULL) {
		return sala[mapaAtual].getTile(x, y).isMonster();
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

//int InputJogo::getTotalItens()
//{
//	return totalItens;
//}

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
	testarColisoes();
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
	// 58 A 67  - F1 a F10
	
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

	i = 0;
	// deletar itens
	for (int tecla = 58; tecla < 68; tecla++) {
		if (gTeclado.pressionou[tecla]) {
			if (bag[i].isInBag()) {
				deleteItem(i);
				break;
			}
		}
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



void InputJogo::atualizarBatalha()
{
	int px = getPlayerX() / 32;
	int py = getPlayerY() / 32;

	int mx, my;

	int mon = 100;

	// ataque
	int patk = uniRandEntre(2, 12);
	int matk;

	bool dir, esq, cima, baixo;



	patk += getPlayerAtk();

	if (gTeclado.pressionou[TECLA_ESPACO]) {

		if (sala[mapaAtual].getNMonsters() != 0) {
			// monstro existe

			for (int i = 0; i < sala[mapaAtual].getNMonsters(); i++) {
				mx = sala[mapaAtual].getMonster(i).getX() / 32;
				my = sala[mapaAtual].getMonster(i).getY() / 32;

				esq = (px == mx - 1 && py == my);
				dir = (px == mx + 1 && py == my);
				baixo = (py == my + 1 && px == mx);
				cima = (py == my - 1 && px == mx);

				if (dir || esq || baixo || cima) {

					mon = i;
					break;
				}
				else
					mon = 100;
			}

			// se existe monstro
			if (mon != 100) {
				matk = sala[mapaAtual].getMonster(mon).getAtk();
				matk += uniRandEntre(2, 12);
				matk -= getPlayerDef();

				if (matk < 0)
					matk = 1;

				matk = -matk; // negativo para causar dano



				patk -= sala[mapaAtual].getMonster(mon).getDef();

				if (patk < 0)
					patk = 1;

				patk = -patk; // negativo para causar dano



				// alterar a vida
				sala[mapaAtual].getMonster(mon).setMoreHP(patk);
				setPlayerHP(matk);

				if (sala[mapaAtual].getMonster(mon).getHP() <= 0) {
					sala[mapaAtual].getMonster(mon).setPos(-100, -100);
				}

				// volta para primeiro estado
				mon = 100;

		

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


void InputJogo::mapaInicial()
{
	nMapas = 15;
	int i = 0;//uniRandEntre(0, 5);
	if (i == 0) {
		lerMapaParaSala(0, "bin/assets/tiles/mapa0.txt");
	}
	else if (i == 1) {
		lerMapaParaSala(0, "bin/assets/tiles/mapa1.txt");
	}
	else if (i == 2) {
		lerMapaParaSala(0, "bin/assets/tiles/mapa2.txt");
	}
	else if (i == 3) {
		lerMapaParaSala(0, "bin/assets/tiles/mapa3.txt");
	}
	else if (i == 4) {
		lerMapaParaSala(0, "bin/assets/tiles/mapa4.txt");
	}
	else if (i == 5) {
		lerMapaParaSala(0, "bin/assets/tiles/mapa5.txt");
	}

	//sala[0].ler("bin/assets/tiles/mapa0.txt");
	sala[0].readMonster();
	sala[0].setChests();
	int r = uniRandEntre(0, 5);
	sala[0].setNMonsters(r);

	mapaAtual = i;

}



myTilemap InputJogo::getSala(int i)
{
	return sala[i];
}

void InputJogo::lerMapaParaSala(int i, string arq)
{
	sala[i].ler(arq);
}

Mage * InputJogo::getMage()
{
		return &mage;
}

Warrior * InputJogo::getWarrior()
{
		return &warrior;
}

Thief * InputJogo::getThief()
{
		return &thief;
}

void InputJogo::moveMonster(int i)
{


	int monsterXDir = (sala[mapaAtual].getMonster(i).getX() / 32) + 1;
	int monsterY = (sala[mapaAtual].getMonster(i).getY()) / 32;
	int monsterX = (sala[mapaAtual].getMonster(i).getX()) / 32;
	int monsterXEsq = (sala[mapaAtual].getMonster(i).getX() /32) - 1;
	int monsterYCima = (sala[mapaAtual].getMonster(i).getY()/32) - 1;
	int monsterYBaixo = (sala[mapaAtual].getMonster(i).getY() /32) + 1;


	int ran = uniRandEntre(1, 4);

	if (ran == 1) { // direita
		
		sala[mapaAtual].getMonster(i).movDir(sala[mapaAtual].getPos(monsterXDir,monsterY));


	}
	else if (ran==2) // esquerda
		sala[mapaAtual].getMonster(i).movEsq(sala[mapaAtual].getPos(monsterXEsq, monsterY));

	else if (ran==3) // cima
		sala[mapaAtual].getMonster(i).movCima(sala[mapaAtual].getPos(monsterX, monsterYCima));

	else // baixo
		sala[mapaAtual].getMonster(i).movBaixo(sala[mapaAtual].getPos(monsterX, monsterYBaixo));



}

void InputJogo::save(std::string nomeArq)
{
	ofstream arquivo;
	arquivo.open(nomeArq, ios::binary);

	if (arquivo) {
		time_t tempo = time(NULL);
		struct tm *temp = localtime(&tempo);
		
		int dia = temp->tm_mday;
		int mes = temp->tm_mon + 1;
		int hora = temp->tm_hour;
		int min = temp->tm_min;

		string sdia = to_string(dia);
		string smes = to_string(mes);
		string shora = to_string(hora);
		string smin = to_string(min);
		string smapa = to_string(mapaAtual);


		string arqnome = smapa + "-" + sdia + "-" + smes + "-" + shora + "-" + smin;
		char namearq[15];
		strcpy(namearq, arqnome.c_str());

		// salvar o nome do arquivo
		arquivo.write(reinterpret_cast<const char*> (&namearq), sizeof(char[15]));


		 // salvar primeiro o numero do mapa atual
		arquivo.write(reinterpret_cast<const char*> (&mapaAtual), sizeof(int));

		// depois salvar a matriz dos tiles
		for (int c = 0; c < 32; c++) {
			for (int l = 0; l < 24; l++) {

				int tileid = mapa[mapaAtual].getTile(c,l).getId();
				arquivo.write(reinterpret_cast<const char*> (&tileid), sizeof(int));
			}
		}

		// depois salvar a qt de monstros
		int nmonstros = mapa[mapaAtual].getNMonsters();
		arquivo.write(reinterpret_cast<const char*> (&nmonstros), sizeof(int));

		// depois salvar cada monstro do mapa com seus atributos
		for (int i = 0; i < nmonstros; i++) {
			int monId = mapa[mapaAtual].getMonster(i).getId();
			int monDef = mapa[mapaAtual].getMonster(i).getDef();
			int monHP = mapa[mapaAtual].getMonster(i).getHP();
			int monMaxHP = mapa[mapaAtual].getMonster(i).getMaxHP();
			int monAtk = mapa[mapaAtual].getMonster(i).getAtk();
			int monX = mapa[mapaAtual].getMonster(i).getX();
			int monY = mapa[mapaAtual].getMonster(i).getY();
			std::string tempnome = mapa[mapaAtual].getMonster(i).getNome();
			string tempcaminho = mapa[mapaAtual].getMonster(i).getCaminho();
			char monName[30];
			char monCaminho[50];
			strcpy(monCaminho, tempcaminho.c_str());
			strcpy(monName, tempnome.c_str());

			arquivo.write(reinterpret_cast<const char*> (&monId), sizeof(int));
			arquivo.write(reinterpret_cast<const char*> (&monDef), sizeof(int));
			arquivo.write(reinterpret_cast<const char*> (&monHP), sizeof(int));
			arquivo.write(reinterpret_cast<const char*> (&monMaxHP), sizeof(int));
			arquivo.write(reinterpret_cast<const char*> (&monAtk), sizeof(int));
			arquivo.write(reinterpret_cast<const char*> (&monX), sizeof(int));
			arquivo.write(reinterpret_cast<const char*> (&monY), sizeof(int));
			arquivo.write(reinterpret_cast<const char*> (&monCaminho), sizeof(char[50]));
			arquivo.write(reinterpret_cast<const char*> (&monName), sizeof(char[30]));
		}
		
		// depois salvar a quantidade de itens
		int tamanho = lista.size();
		arquivo.write(reinterpret_cast<const char*> (&tamanho), sizeof(int));


		// e cada info dos itens
		for (int i = 0; i < tamanho; i++) {
			int iId = lista.retornar().getId();
			int iAtk = lista.retornar().getatk();
			int iDef = lista.retornar().getdef();
			int iHp = lista.retornar().gethp();
			int iMaxHp = lista.retornar().getmaxhp();
			int iX = lista.retornar().getX();
			int iY = lista.retornar().getY();

			std::string tempi = lista.retornar().getNome();
			char iNome[30];
			strcpy(iNome, tempi.c_str());

			string tempca = lista.retornar().getCaminho();
			char iCa[50];
			strcpy(iCa, tempca.c_str());

			bool isbag = lista.retornar().isInBag();
			bool isused = lista.retornar().isUsed();

			arquivo.write(reinterpret_cast<const char*> (&iId), sizeof(int));
			arquivo.write(reinterpret_cast<const char*> (&iAtk), sizeof(int));
			arquivo.write(reinterpret_cast<const char*> (&iDef), sizeof(int));
			arquivo.write(reinterpret_cast<const char*> (&iHp), sizeof(int));
			arquivo.write(reinterpret_cast<const char*> (&iMaxHp), sizeof(int));
			arquivo.write(reinterpret_cast<const char*> (&iX), sizeof(int));
			arquivo.write(reinterpret_cast<const char*> (&iY), sizeof(int));
			arquivo.write(reinterpret_cast<const char*> (&iNome), sizeof(char[30]));
			arquivo.write(reinterpret_cast<const char*> (&iCa), sizeof(char[50]));
			arquivo.write(reinterpret_cast<const char*> (&isbag), sizeof(bool));
			arquivo.write(reinterpret_cast<const char*> (&isused), sizeof(bool));



			lista.andar_frente();
		}

		// e então salvar o status do jogador

		// 1 = mage, 2 = warrior, 3 = thief
		int classe = getClass();
		arquivo.write(reinterpret_cast<const char*> (&classe), sizeof(int));

		int jhp = getPlayerHP();
		int jmaxhp = getPlayerMaxHP();
		int jdef = getPlayerDef();
		int jatk = getPlayerAtk();
		int jgold = getPlayerGold();
		int jy = getPlayerY();
		int jx = getPlayerX();

		std::string tempn = getNomeSpr(classe);
		char nomeSpr[30];
		strcpy(nomeSpr, tempn.c_str());

		arquivo.write(reinterpret_cast<const char*> (&jhp), sizeof(int));
		arquivo.write(reinterpret_cast<const char*> (&jmaxhp), sizeof(int));
		arquivo.write(reinterpret_cast<const char*> (&jdef), sizeof(int));
		arquivo.write(reinterpret_cast<const char*> (&jatk), sizeof(int));
		arquivo.write(reinterpret_cast<const char*> (&jgold), sizeof(int));
		arquivo.write(reinterpret_cast<const char*> (&jy), sizeof(int));
		arquivo.write(reinterpret_cast<const char*> (&jx), sizeof(int));
		arquivo.write(reinterpret_cast<const char*> (&nomeSpr), sizeof(char[30]));
	}
	// fecha o arquivo
	arquivo.close();

}

void InputJogo::carregar(string nomeArq)
{
	ifstream file;
	file.open(nomeArq, ios::binary);
	if (file) {
		// carregar arquivo
		while (file && !file.eof())
		{

			// nome

			char namearq[15];
			file.read(reinterpret_cast<char*> (&namearq), sizeof(char[15]));

			// mapa atual
			file.read(reinterpret_cast<char*> (&mapaAtual), sizeof(int));
			
			// tiles

			for (int c = 0; c < 32; c++) {
				for (int l = 0; l < 24; l++) {
					int tileid;
					file.read(reinterpret_cast<char*> (&tileid), sizeof(int));
					mapa[mapaAtual].setTile(c, l, tileid);

				}
			}

			// monstros

			int nmonstros;
			file.read(reinterpret_cast<char*> (&nmonstros), sizeof(int));
			mapa[mapaAtual].setNMonsters(nmonstros);

			for (int i = 0; i < nmonstros; i++) {
				int monId;
				int monDef;
				int monHP;
				int monMaxHP;
				int monAtk;
				int monX;
				int monY;
				char monName[30];
				char monC[50];
				file.read(reinterpret_cast<char*> (&monId), sizeof(int));
				file.read(reinterpret_cast<char*> (&monDef), sizeof(int));
				file.read(reinterpret_cast<char*> (&monHP), sizeof(int));
				file.read(reinterpret_cast<char*> (&monMaxHP), sizeof(int));
				file.read(reinterpret_cast<char*> (&monAtk), sizeof(int));
				file.read(reinterpret_cast<char*> (&monX), sizeof(int));
				file.read(reinterpret_cast<char*> (&monY), sizeof(int));
				file.read(reinterpret_cast<char*> (&monC), sizeof(char[50]));
				file.read(reinterpret_cast<char*> (&monName), sizeof(char[30]));

				string nom(monName);
				string cam(monC);
				mapa[mapaAtual].getMonster(i).mInicializar(monId, nom, monDef, monHP, cam);
				mapa[mapaAtual].getMonster(i).setMaxHP(monMaxHP);
			}


			// itens
			lista.clear(); // só pra garantir :D

			int qtdItens;
			file.read(reinterpret_cast<char*> (&qtdItens), sizeof(int));

			for (int i = 0; i < qtdItens; i++) {
				int iId;
				int iAtk;
				int iDef;
				int iHp;
				int iMaxHp;
				int iX;
				int iY;
				char iNome[30];
				char iCa[50];
				bool isbag, isused;

				file.read(reinterpret_cast<char*> (&iId), sizeof(int));
				file.read(reinterpret_cast<char*> (&iAtk), sizeof(int));
				file.read(reinterpret_cast<char*> (&iDef), sizeof(int));
				file.read(reinterpret_cast<char*> (&iHp), sizeof(int));
				file.read(reinterpret_cast<char*> (&iMaxHp), sizeof(int));
				file.read(reinterpret_cast<char*> (&iX), sizeof(int));
				file.read(reinterpret_cast<char*> (&iY), sizeof(int));
				file.read(reinterpret_cast<char*> (&iNome), sizeof(char[30]));
				file.read(reinterpret_cast<char*> (&iCa), sizeof(char[50]));
				file.read(reinterpret_cast<char*> (&isbag), sizeof(bool));
				file.read(reinterpret_cast<char*> (&isused), sizeof(bool));



				Itens item;
				string inomes(iNome);
				string icam(iCa);
				item.create(iId, inomes, icam, iHp, iMaxHp, iDef, iAtk);
				item.setBag(isbag);
				item.setUsed(isused);
				item.setPos(iX, iY);
				lista.add_final(item);
			}

			int classe;
			file.read(reinterpret_cast<char*> (&classe), sizeof(int));


			int jhp;
			int jmaxhp;
			int jdef;
			int jatk;
			int jgold;
			int jy;
			int jx;

			char nomeSpr[30];
			
			file.read(reinterpret_cast<char*> (&jhp), sizeof(int));
			file.read(reinterpret_cast<char*> (&jmaxhp), sizeof(int));
			file.read(reinterpret_cast<char*> (&jdef), sizeof(int));
			file.read(reinterpret_cast<char*> (&jatk), sizeof(int));
			file.read(reinterpret_cast<char*> (&jgold), sizeof(int));
			file.read(reinterpret_cast<char*> (&jy), sizeof(int));
			file.read(reinterpret_cast<char*> (&jx), sizeof(int));
			file.read(reinterpret_cast<char*> (&nomeSpr), sizeof(char[30]));

			std::string spritesheet(nomeSpr);

			jx = jx / 32;
			jy = jy / 32;

			if (classe == 1) {
				mage.select();
				mage.setMoreHP(jhp);
				mage.setMoreMaxHP(jmaxhp);
				mage.setMoreDef(jdef);
				mage.setMoreGold(jgold);
				mage.setPos(jx, jy);
				mage.setSprite(spritesheet);

			}
			else if (classe == 2) {
				warrior.select();
				warrior.setMoreHP(jhp);
				warrior.setMoreMaxHP(jmaxhp);
				warrior.setMoreDef(jdef);
				warrior.setMoreGold(jgold);
				warrior.setPos(jx, jy);
				warrior.setSprite(spritesheet);

			}
			else if (classe == 3) {
				thief.select();
				thief.setMoreHP(jhp);
				thief.setMoreMaxHP(jmaxhp);
				thief.setMoreDef(jdef);
				thief.setMoreGold(jgold);
				thief.setPos(jx, jy);
				thief.setSprite(spritesheet);

			}
			// e acabou

		}
	}
	file.close();
}

std::string InputJogo::getNomeSpr(int i)
{
	if (i == 1) {
		return mage.getNomeSpr();
	}
	else if (i == 2)
		return warrior.getNomeSpr();
	else if (i == 3)
		return thief.getNomeSpr();
}


void InputJogo::testarColisoes()
{

	int r = uniRandEntre(0, totalItens-1);

	for (int i = 0; i < sala[mapaAtual].getNumBaus(); i++) {
		if (getPlayerY() == (sala[mapaAtual].getry(i) * 32) + 32 && getPlayerX() == (sala[mapaAtual].getrx(i) * 32)) {
			if (sala[mapaAtual].getTile(sala[mapaAtual].getrx(i), sala[mapaAtual].getry(i)).getId() == 8) {

				int rr = uniRandEntre(1, 6);
				rr *= 1000;

				setPlayerGold(rr);

				// item de teste
				int k = uniRandEntre(0, 100);
				if (k <21)
					addItem(r);	

			}


			sala[mapaAtual].setTile(sala[mapaAtual].getrx(i), sala[mapaAtual].getry(i), 7);
	
		}

		else if (getPlayerY() == (sala[mapaAtual].getry(i) * 32) && getPlayerX() == (sala[mapaAtual].getrx(i) * 32) + 32) {
			if (sala[mapaAtual].getTile(sala[mapaAtual].getrx(i), sala[mapaAtual].getry(i)).getId() == 8) {

				int rr = uniRandEntre(1, 6);
				rr *= 1000;

				setPlayerGold(rr);
				// item de teste
				int k = uniRandEntre(0, 100);
				if (k <21)
					addItem(r);

			}

	
			sala[mapaAtual].setTile(sala[mapaAtual].getrx(i), sala[mapaAtual].getry(i), 7);

		}

		else if (getPlayerY() == (sala[mapaAtual].getry(i) * 32) && getPlayerX() == (sala[mapaAtual].getrx(i) * 32) - 32) {
			if (sala[mapaAtual].getTile(sala[mapaAtual].getrx(i), sala[mapaAtual].getry(i)).getId() == 8) {

				int rr = uniRandEntre(1, 6);
				rr *= 1000;

				setPlayerGold(rr);

				// item de teste
				int k = uniRandEntre(0, 100);
				if (k <21)
					addItem(r);

			}


			sala[mapaAtual].setTile(sala[mapaAtual].getrx(i), sala[mapaAtual].getry(i), 7);

		}
	}
}


