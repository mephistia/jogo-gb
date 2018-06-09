#pragma once
#include "Player.h"

class Thief: public Player
{
public:
	Thief();
	~Thief();

	void skill();
	bool isSelected();
	void select();
	void unselect();

private:
	bool thief;
};

