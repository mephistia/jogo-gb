#pragma once
#include "libUnicornio.h"
using namespace std;
class Itens
{
public:
	Itens();
	~Itens();
	void inicializar(string nome, int bonusAtk, int bonusDef, int bonusHP, int id);
	bool getPossui();
	Sprite getSprite();
	string getNome();
	int getBonusAtk();
	int getBonusDef();
	int getBonusHP();
	int getID();

	void setPossui(bool p);
	void setNome(string &nome);
	void setBonusAtk(int &atk);
	void setBonusDef(int def);
	void setBonusHP(int &HP);
	void setID(int &id);

private:
	string nome;
	int bonusHP, bonusDef, bonusAtk, id;
	Sprite spr;
	bool possui;

};

