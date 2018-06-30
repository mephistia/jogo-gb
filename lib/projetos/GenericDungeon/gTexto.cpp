#include "gTexto.h"



gTexto::gTexto()
{
}


gTexto::~gTexto()
{
}

void gTexto::setTxt(std::string txt)
{
	this->txt.setString(txt);
}

std::string gTexto::getTxt()
{
	return std::string();
}


void gTexto::centralizar()
{
	txt.setAlinhamento(TEXTO_CENTRALIZADO);
}

void gTexto::desenhar(int x, int y)
{
	txt.desenhar(x, y);
}

void gTexto::cor(int r, int g, int b)
{
	txt.setCor(r, g, b);
}

void gTexto::setFont(std::string font)
{
	txt.setFonte(font);
}

void gTexto::setTxtHP(int atu, int max)
{
	std::string set;


	std::string a = std::to_string(atu);
	std::string m = std::to_string(max);

	set = a + "/" + m;

	txt.setString(set);
}

void gTexto::escalar(int a)
{
	txt.setEscala(a, a);
}
