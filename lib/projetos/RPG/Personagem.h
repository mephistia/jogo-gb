#pragma once
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include "libUnicornio.h"



using namespace std;

enum AnimacaoPersonagem
{
	ANIMACAO_BAIXO,
	ANIMACAO_ESQ,
	ANIMACAO_DIR,
	ANIMACAO_CIMA
};

class Personagem
{
public:
	Personagem();
	~Personagem();

	// habilidade
	virtual void skill() = 0;
	//virtual void espaco() = 0;
	virtual bool isSelected() = 0;
	virtual void select() = 0;
	virtual void unselect() = 0;

	//inicio
	void inicializar(string sheet, ObjetoTileMap* objeto);


	// posição
	void setPos(float x, float y);

	// sprite
	void atualizar();

	void setDestino(float x, float y);
	bool estaMovendo();

	// gets
	string getName();
	int getAtk();
	int getDef();
	int getHP();
	int getMaxHP();
	int getGold();
	float getX();
	float getY();
	Sprite getSprite();
	ObjetoTileMap getObjeto();
	float getAncoraX();
	float getAncoraY();
	bool getUseS();

	// sets sorteios
	void setAtk();
	void setDef();
	void setHP();

	// sets meio do jogo
	void setMoreAtk(int &atk);
	void setMoreDef(int &def);
	void setMoreHP(int &hp);
	void setUseS(bool podeusar);
	void setMoreGold(int &gold);

	// set nome
	void setName(string &nome);

	// atualizar
	void atualizarAnimacao();
	void atualizarMovimento();

	// desenhar hp 
	void desenhaVida();

	//som
	void setSom(string nome);

	bool getAtacou();
	void setAtacou(bool atacou);
protected:
	
	string name;
	int atk, def, hp, gold, maxHP;
	bool isDead, canUseS, isDown, movendo, atacou;

	// sprite
	ObjetoTileMap* objeto;
	Sprite spr;
	float x, y;
	float vel;
	float ancoraX, ancoraY;

	Vetor2D destino;
	Vetor2D inicio;
	float interpolador;

	Som som;

	// para retangulo
	Cor cor;
	Quad bar;
	Quad barFundo;


};

