#include "Warrior.h"



Warrior::Warrior()
{
	warrior = false;
	canUseS = false;
	isDown = false;

	setAtk();
	setDef();
	setHP();
	maxHP = getHP();

	// guerreiro tem mais HP
	int *warHP = new int;
	*warHP = 3;
	setMoreHP(*warHP);

	// guerreiro tem mais Defesa
	int *warDef = new int;
	*warDef = 3;
	setMoreDef(*warDef);

	defOriginal = getDef();




}


Warrior::~Warrior()
{
}

void Warrior::skill()
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


bool Warrior::isSelected()
{
	return warrior;
}

void Warrior::select()
{
	warrior = true;
}

void Warrior::unselect()
{
	warrior = false;
}
