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

void InputJogo::iniciaMage(std::string sheet)
{
	mage.inicializar(sheet);
	mage.setPos(15, 3);
}

void InputJogo::atualizarMage()
{
	if (mage.isSelected()) {

		mage.atualizar();

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
}
