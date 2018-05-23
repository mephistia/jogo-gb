#pragma once
#include "Personagem.h"


class Warrior : public Personagem
{
public:
	Warrior();
	~Warrior();

	void skill();
	bool isSelected();
	void select();
	void unselect();


private:
	int defOriginal;
	bool warrior;
};

