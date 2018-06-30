#pragma once
#include "libUnicornio.h"
class Itens
{
public:
	Itens();
	~Itens();

	void use();
	void create(int id,std::string nome, std::string caminho, int bonusHP, int bonusMaxHP, int bonusDef, int bonusAtk); // nome do sprite sheet
	bool isInBag();
	void addBag();
	Sprite getSprite();
	std::string getCaminho();
	void setBag(bool b);
	bool isUsed();
	void setUsed(bool b);

	void setPos(int x, int y);
	int getX();
	int getY();
	int getId();
	int gethp();
	int getmaxhp();
	int getdef();
	int getatk();
	std::string getNome();

	void setId(int id);

	void desenhar();

	//sobrecarregar
	friend bool operator<(const Itens &a, const Itens &b);
	friend bool operator==(const Itens &a, const Itens &b);


protected:
	int bonusHP, bonusMaxHP, bonusDef, bonusAtk, id; // id do item, n�o do tipo de item
	std::string nome;
	std::string caminho;
	bool used, inBag;
	Sprite sprite;

	// posi��o do sprite
	int x, y;
	int primeirox;
};

