#pragma once
#include "Personagem.h"

class Thief : public Personagem
{
public:
	Thief();
	~Thief();

	void skill();
	bool isSelected();
	void select();
	void unselect();


private:
	float metade;
	bool thief;
};

