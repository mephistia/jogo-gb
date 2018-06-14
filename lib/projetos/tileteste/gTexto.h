#pragma once
#include "libUnicornio.h"
class gTexto
{
public:
	gTexto();
	~gTexto();
	void setTxt(std::string txt);
	std::string getTxt();
	void centralizar();
	void desenhar(int x, int y);
	void cor(int r, int g, int b);
	void setFont(std::string font);
	void setTxtHP(int atu, int max);
	void escalar(int a);
private:
	Texto txt;
};

