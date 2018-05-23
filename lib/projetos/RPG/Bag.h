#include "libUnicornio.h"
#include "Itens.h"

class Bag
{
public:
	Bag();
	~Bag();
	Itens getItem(string nome);
	void addItem(Itens item);
	void setMochilaCheia(bool b);
	bool getMochilaCheia();
	void deleteItem(string nome);
	int getItensNaMochila();
	bool existeItem(string nome);

private:
	Itens * item;
	int maxItens, itensNaMochila;
	bool mochilaCheia;
};
