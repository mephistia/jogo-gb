#include "Warrior.h"



Warrior::Warrior()
{
	warrior = false;

	setAtk();
	setDef();
	setHP();
	maxHP = getHP();
}


Warrior::~Warrior()
{
}

void Warrior::skill()
{
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
