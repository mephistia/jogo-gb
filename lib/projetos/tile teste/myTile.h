#pragma once
#include <string>
#include "libUnicornio.h"

class myTile
{
public:
	myTile();
	~myTile();

	void createTile(int id, std::string nome, std::string caminho, bool isSolid);

private:
	bool isSolid;
	int id;
	std::string nome;
	std::string caminho;
	Sprite sprite;

};

