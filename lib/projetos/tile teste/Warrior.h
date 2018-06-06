#pragma once
#include "Player.h"
class Warrior: public Player
{
public:
	Warrior();
	~Warrior();


	void skill();
	bool isSelected();
	void select();
	void unselect();

private:
	bool warrior;
};

