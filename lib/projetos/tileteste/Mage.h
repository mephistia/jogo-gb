#pragma once
#include "Player.h"

class Mage: public Player
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
};

