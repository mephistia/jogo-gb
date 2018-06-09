#pragma once
#include "libUnicornio.h"
class Itens
{
public:
	Itens();
	~Itens();

protected:
	int bonusHP, bonusDef, bonusAtk, bonusGold;
	std::string nome;
	bool equipped;
};

