#include "Bag.h"



Bag::Bag()
{
	maxItens = 10;
	itensNaMochila = 0;
	item = new Itens[maxItens];

	//for (int i = 0; i < maxItens; i++) {
	//	item[i].inicializar("", 0, 0, 0, 0);
	//}

	mochilaCheia = false;
}


Bag::~Bag()
{
}

Itens Bag::getItem(string nome)
{
	for (int i = 0; i < maxItens; i++) {

		if (item[i].getNome() == nome) {
			return item[i];
		}
	}
}


void Bag::addItem(Itens item)
{
	for (int i = 0; i < maxItens; i++) {

		if (itensNaMochila == maxItens) {
			mochilaCheia = true;
			break;
		}

		else if (this->item[i].getNome() == "") {
			string nome = item.getNome();

			int atk, def, hp, id;
			atk = item.getBonusAtk();
			def = item.getBonusDef();
			hp = item.getBonusHP();
			id = item.getID();
			this->item[i].inicializar(nome, atk, def, hp, id);
			this->item[i].setPossui(true);
			itensNaMochila++;
			break;
		}

	}
}

void Bag::setMochilaCheia(bool b)
{
	mochilaCheia = b;
}

bool Bag::getMochilaCheia()
{
	return mochilaCheia;
}

void Bag::deleteItem(string nome)
{
	for (int i = 0; i < maxItens; i++) {
		if (nome == item[i].getNome()) {
			item[i].inicializar("", 0, 0, 0, 0);
			item[i].setPossui(false);
			itensNaMochila--;
		}
	}
}

int Bag::getItensNaMochila()
{
	return itensNaMochila;
}

bool Bag::existeItem(string nome)
{
	for (int i = 0; i < maxItens; i++) {

		if (item[i].getNome() == nome) {
			return true;
		}
	}
	return false;
}
