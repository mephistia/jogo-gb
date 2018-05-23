#pragma once
#include "Personagem.h"
class Mage : public Personagem
{
public:
	Mage();
	~Mage();

	void skill();
	bool isSelected();
	void select();
	void unselect();


private:
	bool mage;
	int atkOriginal;

};

