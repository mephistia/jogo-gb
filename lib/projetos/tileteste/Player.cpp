#include "Player.h"



Player::Player()
{
}


Player::~Player()
{
}

void Player::inicializar(std::string sheet)
{
	sprite.setSpriteSheet(sheet);

	ancoraX = 0.5;
	ancoraY = 0.8;

	sprite.setAncora(ancoraX, ancoraY);

	sprite.setVelocidadeAnimacao(3.5);


	// valores default
	moving = false;
	isDead = false;
	gold = 0;
	vel = 32.0;
	x = 0;
	y = 0;

	setAtk();
	setDef();
	setHP();

}

void Player::setPos(float x, float y)
{
	this->x = x * 32;
	this->y = y * 32;
}

void Player::movDir()
{
	x += vel;
	setAnimDir();
}

void Player::movEsq()
{
	x -= vel;
	setAnimEsq();
}

void Player::movCima()
{
	y -= vel;
	setAnimCima();
}

void Player::movBaixo()
{
	y += vel;
	setAnimBaixo();
}

bool Player::estaMovendo()
{
	return moving;
}

void Player::desenhar()
{
	sprite.desenhar(x, y);
}

void Player::setAnimDir()
{
	sprite.setAnimacao(DIR);
}

void Player::setAnimEsq()
{
	sprite.setAnimacao(ESQ);
}

void Player::setAnimBaixo()
{
	sprite.setAnimacao(BAIXO);
}

void Player::setAnimCima()
{
	sprite.setAnimacao(CIMA);
}

int Player::getAtk()
{
	return atk;
}

int Player::getDef()
{
	return def;
}

int Player::getHP()
{
	return hp;
}

int Player::getMaxHP()
{
	return maxHP;
}

int Player::getGold()
{
	return gold;
}

float Player::getX()
{
	return x;
}

float Player::getY()
{
	return y;
}

Sprite Player::getSprite()
{
	return sprite;
}

float Player::getAncoraX()
{
	return ancoraX;
}

float Player::getAncoraY()
{
	return ancoraY;
}

void Player::setAtk()
{
	int r = rand() % 11 + 2;
	atk = r;
}

void Player::setDef()
{
	def = 7;
}

void Player::setHP()
{
	int r = rand() % 11 + 2;
	hp = r;
	maxHP = r;
}

void Player::setMoreAtk(int & atk)
{
	this->atk += atk;
}

void Player::setMoreDef(int & def)
{
	this->def += def;
}

void Player::setMoreHP(int & hp)
{
	int a = (this->hp + hp);


	if (a < maxHP) {
		this->hp = a;
	}
	else if (a >= maxHP) {
		this->hp = maxHP;
	}
}

void Player::setMoreMaxHP(int & maxhp)
{
	this->maxHP += maxhp;
}

void Player::setMoreGold(int & gold)
{
	this->gold += gold;
	if (this->gold > 14000) {
		this->gold = 14000;
	}
}
