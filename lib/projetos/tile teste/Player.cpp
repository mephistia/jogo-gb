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
}

void Player::setPos(float x, float y)
{
	this->x = x * 32;
	this->y = y * 32;
}

void Player::movDir()
{
	x += vel;
	sprite.setAnimacao(DIR);
}

void Player::movEsq()
{
	x -= vel;
	sprite.setAnimacao(ESQ);
}

void Player::movCima()
{
	y -= vel;
	sprite.setAnimacao(CIMA);
}

void Player::movBaixo()
{
	y += vel;
	sprite.setAnimacao(BAIXO);
}

bool Player::estaMovendo()
{
	return moving;
}

void Player::desenhar()
{
	sprite.desenhar(x, y);
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
	this->hp += hp;
}

void Player::setMoreGold(int & gold)
{
	this->gold += gold;
	if (this->gold > 14000) {
		this->gold = 14000;
	}
}