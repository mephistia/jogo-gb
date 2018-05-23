#include "Mage.h"



Mage::Mage()
{
	mage = false;

	setAtk();
	setDef();
	setHP();
	maxHP = getHP();

	// mago tem mais poder de ataque
	int *Atk = new int;
	*Atk = 3;
	setMoreAtk(*Atk);

	atkOriginal = getAtk();
}


Mage::~Mage()
{
	
}

void Mage::skill()
{
	if (gTeclado.pressionou[TECLA_ESPACO]) {
		som.tocar();
		atacou = true;
	}
	else if (gTeclado.soltou[TECLA_ESPACO]) {
		atacou = false;
	}
	else
		atacou = false;
}


bool Mage::isSelected()
{
	return mage;
}

void Mage::select()
{
	mage = true;
}

void Mage::unselect()
{
	mage = false;
}

