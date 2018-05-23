#include "Thief.h"



Thief::Thief()
{
	thief = false;
	canUseS = false;
	isDown = false;


	setAtk();
	setDef();
	setHP();
	maxHP = getHP();
	

	
}


Thief::~Thief()
{
}

void Thief::skill()
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

bool Thief::isSelected()
{
	return thief;
}

void Thief::select()
{
	thief = true;
}

void Thief::unselect()
{
	thief = false;
}

