#pragma once
#include "libUnicornio.h"

class TipoMonstro
{
public:
	TipoMonstro();
	~TipoMonstro();

	int getID();
	int getVida();
	int getDefesa();
	string getNome();
	string getCaminho();

	void setID(int &id);
	void setVida(int &vida);
	void setDefesa(int &defesa);
	void setNome(string &nome);
	void setCaminho(string &caminho);


private:
	int id, vida, defesa;
	string nome, caminho;
};

