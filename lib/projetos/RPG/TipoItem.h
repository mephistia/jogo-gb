#pragma once
#include "libUnicornio.h"
using namespace std;
class TipoItem
{
public:
	TipoItem();
	~TipoItem();
	// gets
	string getNome();
	int getBonusHP();
	int getBonusDef();
	int getBonusAtk();
	Sprite getSprite();
	int getId();

	// sets
	void setNome(string &nome);
	void setBonusHP(int &HP);
	void setBonusDef(int &def);
	void setBonusAtk(int &atk);
	void setFile(string &file);
	void setId(int &id);
	

private:
	string nome, file;
	int bonusHP, bonusDef, bonusAtk, id;
	Sprite spr;
};

