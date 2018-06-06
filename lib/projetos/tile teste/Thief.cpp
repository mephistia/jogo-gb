#include "Thief.h"



Thief::Thief()
{
	thief = false;

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
