#include "Mage.h"



Mage::Mage()
{
	mage = false;

	setAtk();
	setDef();
	setHP();
	maxHP = getHP();
}


Mage::~Mage()
{
}

void Mage::skill()
{
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
