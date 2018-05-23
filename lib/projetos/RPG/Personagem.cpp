#include "Personagem.h"

Personagem::Personagem()
{
	isDead = false;
	objeto = NULL;
	gold = 0;
	cor.r = 18;
	cor.g = 186;
	cor.b = 0;
	cor.a = 255;

	bar.x = 30;
	bar.y = 30;
	bar.larg = 500;
	bar.alt = 30;

	barFundo.x = 28;
	barFundo.y = 28;
	barFundo.larg = 504; 
	barFundo.alt = 34;

}

Personagem::~Personagem()
{

}


string Personagem::getName()
{
	return name;
}

int Personagem::getAtk()
{
	return atk;
}

int Personagem::getDef()
{
	return def;
}

int Personagem::getHP()
{
	return hp;
}

int Personagem::getMaxHP()
{
	return maxHP;
}

int Personagem::getGold()
{
	return gold;
}

float Personagem::getX()
{
	return objeto->getXCentro();
}

float Personagem::getY()
{
	return objeto->getYCentro();
}

Sprite Personagem::getSprite()
{
	return spr;
}

ObjetoTileMap Personagem::getObjeto()
{
	return *objeto;
}

float Personagem::getAncoraX()
{
	return ancoraX;
}

float Personagem::getAncoraY()
{
	return ancoraY;
}

bool Personagem::getUseS()
{
	return canUseS;
}

void Personagem::setAtk()
{
	int r = rand() % 11 + 2;
	atk = r;
}

void Personagem::setDef()
{
	def = 7;
}

void Personagem::setHP()
{
	int r = rand() % 11 + 2;
	hp = r;
	maxHP = r;

}

void Personagem::setMoreAtk(int & atk)
{
	this->atk += atk;
}

void Personagem::setMoreDef(int & def)
{
	this->def += def;
}

void Personagem::setMoreHP(int & hp)
{
	this->hp += hp;
}

void Personagem::setUseS(bool  podeusar)
{
	canUseS = podeusar;
}

void Personagem::setMoreGold(int & gold)
{
		this->gold += gold;
		if (this->gold > 14000) {
			this->gold = 14000;
		}
}

void Personagem::setName(string & nome)
{
	this->name = nome;
}

void Personagem::atualizarAnimacao()
{
	if (movendo)
	{
		if (destino.x - inicio.x > 0.0)
		{
			spr.setAnimacao(ANIMACAO_DIR);
		}

		else if (destino.x - inicio.x < 0.0)
		{
			spr.setAnimacao(ANIMACAO_ESQ);
		}
		else if (destino.y - inicio.y > 0.0)
		{
			spr.setAnimacao(ANIMACAO_BAIXO); 
		}
		else if (destino.y - inicio.y < 0.0)
		{
			spr.setAnimacao(ANIMACAO_CIMA);
		}

		spr.avancarAnimacao();
	}
	else
	{
		spr.setFrame(0);
	}
}

void Personagem::atualizarMovimento()
{
	if (movendo)
	{
		// interpolador para ficar com animação natural

		float x = inicio.x + (destino.x - inicio.x)*interpolador;
		float y = inicio.y + (destino.y - inicio.y)*interpolador;

	
		interpolador += vel * gTempo.getDeltaTempo();

	
		if (interpolador >= 1.0)
		{
			interpolador = 0.0f;
			x = destino.x;			
			y = destino.y;		
			inicio.x = destino.x;
			inicio.y = destino.y;
			movendo = false;
		}

		
		objeto->setPosCentro(x, y);
		
	}
}



void Personagem::inicializar(string sheet, ObjetoTileMap * objeto)
{
	spr.setSpriteSheet(sheet);

	ancoraX = 0.4;
	ancoraY = 0.5;

	spr.setAncora(ancoraX, ancoraY);

	spr.setVelocidadeAnimacao(3.5);

	this->objeto = objeto;

	objeto->setSprite(&spr);

	// valores default
	movendo = false;
	gold = 0;
	inicio.x = objeto->getXCentro();
	inicio.y = objeto->getYCentro();
	destino.x = 0;
	destino.y = 0;
	interpolador = 0.0f;
	vel = 2.0;
}


void Personagem::setPos(float x, float y)
{
	objeto->setPos(x, y);

}

void Personagem::atualizar()
{
	atualizarAnimacao();
	atualizarMovimento();
	if (gold > 14000)
		gold = 14000;
}


void Personagem::setDestino(float x, float y)
{
	destino.x = x;
	destino.y = y;
	movendo = true;
}

bool Personagem::estaMovendo()
{
	return movendo;
}

void Personagem::desenhaVida()
{
	bar.larg = getHP() * 50;
	barFundo.larg = (getMaxHP() * 50) + 4;
	gGraficos.desenharRetangulo(barFundo, 0, 0, 0, 255, true);
	gGraficos.desenharRetangulo(bar, cor.r, cor.g, cor.b, cor.a, true);

}

void Personagem::setSom(string nome)
{
	som.setAudio(nome);
}

bool Personagem::getAtacou()
{
	return atacou;
}

void Personagem::setAtacou(bool atacou)
{
	this->atacou = atacou;
}
