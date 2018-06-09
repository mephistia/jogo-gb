#pragma once
#include "Player.h"
class Monster: public Player
{
public:
	Monster();
	~Monster();

	void mInicializar(int id, std::string nome, int def, int hp, std::string caminho);

	int getId();
	std::string getNome();

	void setId(int id);
	void setNome(std::string nome);
	
	std::string getCaminho();

	void skill();
	bool isSelected();
	void select();
	void unselect();

private:
	int id;
	std::string nome;
	
};

