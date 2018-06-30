#pragma once
#include <string>
#include "libUnicornio.h"

class myTile
{
public:
	myTile();
	~myTile();

	void createTile(int &id, std::string &nome, std::string &caminho, int &isSolid);

	bool &getSolid();
	bool &getPorta();
	int getId();
	Sprite getSprite();

	void setSolid(bool s);

	void setMonster();
	bool &isMonster();



private:
	bool isSolid;
	int id;
	std::string nome;
	std::string caminho;
	Sprite sprite;

	int idporta;
	
	bool monster, door;

};

