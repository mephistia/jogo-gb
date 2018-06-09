#pragma once
#include <string>
#include "libUnicornio.h"

class myTile
{
public:
	myTile();
	~myTile();

	void createTile(int id, std::string nome, std::string caminho, bool isSolid);

	bool getSolid();
	int getId();
	Sprite getSprite();

	void setSolid(bool s);

	void setMonster(bool b);
	bool isMonster();


private:
	bool isSolid;
	int id;
	std::string nome;
	std::string caminho;
	Sprite sprite;

	
	bool monster;

};

