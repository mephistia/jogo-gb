#pragma once
#include "Player.h"
class Monster: public Player
{
public:
	Monster();
	~Monster();

	void mInicializar(int id, std::string nome, int def, int hp, std::string caminho);

	void skill();
	bool isSelected();
	void select();
	void unselect();

private:
	int id;
	std::string nome;
};

