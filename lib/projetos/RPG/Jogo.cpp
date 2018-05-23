#include "Jogo.h"

Jogo::Jogo()
{
}

Jogo::~Jogo()
{
}

void Jogo::inicializar()
{
	uniInicializar(1024, 768, false, "Generic Adventures");



	gRecursos.carregarSpriteSheet("mage", "assets/sprite1.png", 4, 4);
	gRecursos.carregarSpriteSheet("thief", "assets/sprite2.png", 4, 4);
	gRecursos.carregarSpriteSheet("warrior", "assets/sprite3.png", 4, 4);

	gRecursos.carregarSpriteSheet("Demonio", "assets/demonio.png", 1, 4);
	gRecursos.carregarSpriteSheet("Flor", "assets/flor.png", 1, 4);
	gRecursos.carregarSpriteSheet("Slime", "assets/slime.png", 1, 4);

	gRecursos.carregarSpriteSheet("telaSelect", "assets/select.png");

	gRecursos.carregarSpriteSheet("btn1", "assets/btn1.png");
	gRecursos.carregarSpriteSheet("btn2", "assets/btn2.png");
	gRecursos.carregarSpriteSheet("btn3", "assets/btn3.png");

	gRecursos.carregarSpriteSheet("Cristal", "assets/cristal.png", 1, 1);
	Cristal.setSpriteSheet("Cristal");

	gRecursos.carregarSpriteSheet("Presa", "assets/presa.png", 1, 1);
	Presa.setSpriteSheet("Presa");

	gRecursos.carregarSpriteSheet("Pergaminho", "assets/pergaminho.png", 1, 1);
	Pergaminho.setSpriteSheet("Pergaminho");

	gRecursos.carregarSpriteSheet("Pedra", "assets/pedra.png", 1, 1);
	Pedra.setSpriteSheet("Pedra");
	

	gRecursos.carregarSpriteSheet("bauFechado", "assets/bauFechado.png", 1, 1);
	bauFechado.setSpriteSheet("bauFechado");

	gRecursos.carregarSpriteSheet("bauAberto", "assets/bauAberto.png", 1, 1);
	bauAberto.setSpriteSheet("bauAberto");

	gRecursos.carregarSpriteSheet("Inventario", "assets/bag.png", 1, 1);

	gRecursos.carregarAudio("mageskill", "assets/som/mageskill.wav");
	gRecursos.carregarAudio("thiefskill", "assets/som/thiefskill.wav");
	gRecursos.carregarAudio("warriorskill", "assets/som/warriorskill.wav");

	gRecursos.carregarFonte("fonte", "assets/cambria.ttf", 22);

	
		texto1.setFonte("fonte");
		texto1.setLarguraMaxima(500);

		texto2.setFonte("fonte");
		texto2.setLarguraMaxima(500);

		texto3.setFonte("fonte");
		texto3.setLarguraMaxima(500);

		texto4.setFonte("fonte");
		texto4.setLarguraMaxima(500);

		texto5.setFonte("fonte");
		texto5.setLarguraMaxima(500);

		texto6.setFonte("fonte");
		texto6.setLarguraMaxima(500);

		texto7.setFonte("fonte");
		texto7.setLarguraMaxima(500);

		texto8.setFonte("fonte");
		texto8.setLarguraMaxima(500);

		texto9.setFonte("fonte");
		texto9.setLarguraMaxima(500);

		texto10.setFonte("fonte");
		texto10.setLarguraMaxima(500);
	

	fundoInventario.setSpriteSheet("Inventario");
	fundoSelect.setSpriteSheet("telaSelect");
	btn1.setSpriteSheet("btn1");
	btn2.setSpriteSheet("btn2");
	btn3.setSpriteSheet("btn3");


	btn1.setPos(196, 550);
	btn2.setPos(511, 550);
	btn3.setPos(828, 550);

	randMapa = uniRandEntre(1, 6);
	mAtacou = false;
	gameover = false;
	newHP = 0;

	idTelas = T_SELECT;
}

void Jogo::finalizar()
{

	gRecursos.descarregarTudo();

	mapa.descarregar();
	mapa2.descarregar();
	mapa3.descarregar();
	mapa4.descarregar();
	mapa5.descarregar();
	mapa6.descarregar();

	uniFinalizar();
}

void Jogo::executar()
{
	while(!gTeclado.soltou[TECLA_ESC] && !gEventos.sair)
	{
		uniIniciarFrame();

		switch (idTelas) {
		case T_SELECT:
			telaSelect();
			break;
		case T_JOGO:
			telaJogo();
			break;
		case T_MOCHILA:
			telaMochila();
			break;
		}
		

		uniTerminarFrame();
	}
}

void Jogo::atualizarInputMage()
{
	if (mage->isSelected()) {
		if (!mage->estaMovendo())
		{
			if (gTeclado.segurando[TECLA_DIR])
			{
				if (randMapa == 1) {
					if (mapa.tileECaminhavel(mage->getX() + 1.0, mage->getY()))
					{
						mage->setDestino(mage->getX() + 1.0, mage->getY());
					}
				}
				else if (randMapa == 2) {
					if (mapa2.tileECaminhavel(mage->getX() + 1.0, mage->getY()))
					{
						mage->setDestino(mage->getX() + 1.0, mage->getY());
					}
				}
				else if (randMapa == 3) {
					if (mapa3.tileECaminhavel(mage->getX() + 1.0, mage->getY()))
					{
						mage->setDestino(mage->getX() + 1.0, mage->getY());
					}
				}
				else if (randMapa == 4) {
					if (mapa4.tileECaminhavel(mage->getX() + 1.0, mage->getY()))
					{
						mage->setDestino(mage->getX() + 1.0, mage->getY());
					}
				}
				else if (randMapa == 5) {
					if (mapa5.tileECaminhavel(mage->getX() + 1.0, mage->getY()))
					{
						mage->setDestino(mage->getX() + 1.0, mage->getY());
					}
				}
				else if (randMapa == 6) {
					if (mapa6.tileECaminhavel(mage->getX() + 1.0, mage->getY()))
					{
						mage->setDestino(mage->getX() + 1.0, mage->getY());
					}
				}
				
			}
			else if (gTeclado.segurando[TECLA_ESQ])
			{
				if (randMapa == 1) {
					if (mapa.tileECaminhavel(mage->getX() - 1.0, mage->getY()))
					{
						mage->setDestino(mage->getX() - 1.0, mage->getY());
					}
				}
				else if (randMapa == 2) {
					if (mapa2.tileECaminhavel(mage->getX() - 1.0, mage->getY()))
					{
						mage->setDestino(mage->getX() - 1.0, mage->getY());
					}
				}
				else if (randMapa == 3) {
					if (mapa3.tileECaminhavel(mage->getX() - 1.0, mage->getY()))
					{
						mage->setDestino(mage->getX() - 1.0, mage->getY());
					}
				}
				else if (randMapa == 4) {
					if (mapa4.tileECaminhavel(mage->getX() - 1.0, mage->getY()))
					{
						mage->setDestino(mage->getX() - 1.0, mage->getY());
					}
				}
				else if (randMapa == 5) {
					if (mapa5.tileECaminhavel(mage->getX() - 1.0, mage->getY()))
					{
						mage->setDestino(mage->getX() - 1.0, mage->getY());
					}
				}
				else if (randMapa == 6) {
					if (mapa6.tileECaminhavel(mage->getX() - 1.0, mage->getY()))
					{
						mage->setDestino(mage->getX() - 1.0, mage->getY());
					}
				}
			}
			else if (gTeclado.segurando[TECLA_CIMA])
			{
				if (randMapa == 1) {
					if (mapa.tileECaminhavel(mage->getX(), mage->getY() - 1.0))
					{
						mage->setDestino(mage->getX(), mage->getY() - 1.0);
					}
				}
				else if (randMapa == 2) {
					if (mapa2.tileECaminhavel(mage->getX(), mage->getY() - 1.0))
					{
						mage->setDestino(mage->getX(), mage->getY() - 1.0);
					}
				}
				else if (randMapa == 3) {
					if (mapa3.tileECaminhavel(mage->getX(), mage->getY() - 1.0))
					{
						mage->setDestino(mage->getX(), mage->getY() - 1.0);
					}
				}
				else if (randMapa == 4) {
					if (mapa4.tileECaminhavel(mage->getX(), mage->getY() - 1.0))
					{
						mage->setDestino(mage->getX(), mage->getY() - 1.0);
					}
				}
				else if (randMapa == 5) {
					if (mapa5.tileECaminhavel(mage->getX(), mage->getY() - 1.0))
					{
						mage->setDestino(mage->getX(), mage->getY() - 1.0);
					}
				}
				else if (randMapa == 6) {
					if (mapa6.tileECaminhavel(mage->getX(), mage->getY() - 1.0))
					{
						mage->setDestino(mage->getX(), mage->getY() - 1.0);
					}
				}
			}
			else if (gTeclado.segurando[TECLA_BAIXO])
			{
				if (randMapa == 1) {
					if (mapa.tileECaminhavel(mage->getX(), mage->getY() + 1.0))
					{
						mage->setDestino(mage->getX(), mage->getY() + 1.0);
					}
				}
				else if (randMapa == 2) {
					if (mapa2.tileECaminhavel(mage->getX(), mage->getY() + 1.0))
					{
						mage->setDestino(mage->getX(), mage->getY() + 1.0);
					}
				}
				else if (randMapa == 3) {
					if (mapa3.tileECaminhavel(mage->getX(), mage->getY() + 1.0))
					{
						mage->setDestino(mage->getX(), mage->getY() + 1.0);
					}
				}
				else if (randMapa == 4) {
					if (mapa4.tileECaminhavel(mage->getX(), mage->getY() + 1.0))
					{
						mage->setDestino(mage->getX(), mage->getY() + 1.0);
					}
				}
				else if (randMapa == 5) {
					if (mapa5.tileECaminhavel(mage->getX(), mage->getY() + 1.0))
					{
						mage->setDestino(mage->getX(), mage->getY() + 1.0);
					}
				}
				else if (randMapa == 6) {
					if (mapa6.tileECaminhavel(mage->getX(), mage->getY() + 1.0))
					{
						mage->setDestino(mage->getX(), mage->getY() + 1.0);
					}
				}
				
			}
		}
	}
}

void Jogo::atualizarInputWarrior()
{
	if (warrior->isSelected()) {
		if (!warrior->estaMovendo())
		{
			if (gTeclado.segurando[TECLA_DIR])
			{
				if (randMapa == 1) {
					if (mapa.tileECaminhavel(warrior->getX() + 1.0, warrior->getY()))
					{
						warrior->setDestino(warrior->getX() + 1.0, warrior->getY());
					}
				}
				else if (randMapa == 2) {
					if (mapa2.tileECaminhavel(warrior->getX() + 1.0, warrior->getY()))
					{
						warrior->setDestino(warrior->getX() + 1.0, warrior->getY());
					}
				}
				else if (randMapa == 3) {
					if (mapa3.tileECaminhavel(warrior->getX() + 1.0, warrior->getY()))
					{
						warrior->setDestino(warrior->getX() + 1.0, warrior->getY());
					}
				}
				else if (randMapa == 4) {
					if (mapa4.tileECaminhavel(warrior->getX() + 1.0, warrior->getY()))
					{
						warrior->setDestino(warrior->getX() + 1.0, warrior->getY());
					}
				}
				else if (randMapa == 5) {
					if (mapa5.tileECaminhavel(warrior->getX() + 1.0, warrior->getY()))
					{
						warrior->setDestino(warrior->getX() + 1.0, warrior->getY());
					}
				}
				else if (randMapa == 6) {
					if (mapa6.tileECaminhavel(warrior->getX() + 1.0, warrior->getY()))
					{
						warrior->setDestino(warrior->getX() + 1.0, warrior->getY());
					}
				}
			}
			else if (gTeclado.segurando[TECLA_ESQ])
			{
				if (randMapa == 1) {
					if (mapa.tileECaminhavel(warrior->getX() - 1.0, warrior->getY()))
					{
						warrior->setDestino(warrior->getX() - 1.0, warrior->getY());
					}
				}
				else if (randMapa == 2) {
					if (mapa2.tileECaminhavel(warrior->getX() - 1.0, warrior->getY()))
					{
						warrior->setDestino(warrior->getX() - 1.0, warrior->getY());
					}
				}
				else if (randMapa == 3) {
					if (mapa3.tileECaminhavel(warrior->getX() - 1.0, warrior->getY()))
					{
						warrior->setDestino(warrior->getX() - 1.0, warrior->getY());
					}
				}
				else if (randMapa == 4) {
					if (mapa4.tileECaminhavel(warrior->getX() - 1.0, warrior->getY()))
					{
						warrior->setDestino(warrior->getX() - 1.0, warrior->getY());
					}
				}
				else if (randMapa == 5) {
					if (mapa5.tileECaminhavel(warrior->getX() - 1.0, warrior->getY()))
					{
						warrior->setDestino(warrior->getX() - 1.0, warrior->getY());
					}
				}
				else if (randMapa == 6) {
					if (mapa6.tileECaminhavel(warrior->getX() - 1.0, warrior->getY()))
					{
						warrior->setDestino(warrior->getX() - 1.0, warrior->getY());
					}
				}
				
			}
			else if (gTeclado.segurando[TECLA_CIMA])
			{
				if (randMapa == 1) {
					if (mapa.tileECaminhavel(warrior->getX(), warrior->getY() - 1.0))
					{
						warrior->setDestino(warrior->getX(), warrior->getY() - 1.0);
					}
				}
				else if (randMapa == 2) {
					if (mapa2.tileECaminhavel(warrior->getX(), warrior->getY() - 1.0))
					{
						warrior->setDestino(warrior->getX(), warrior->getY() - 1.0);
					}
				}
				else if (randMapa == 3) {
					if (mapa3.tileECaminhavel(warrior->getX(), warrior->getY() - 1.0))
					{
						warrior->setDestino(warrior->getX(), warrior->getY() - 1.0);
					}
				}
				else if (randMapa == 4) {
					if (mapa4.tileECaminhavel(warrior->getX(), warrior->getY() - 1.0))
					{
						warrior->setDestino(warrior->getX(), warrior->getY() - 1.0);
					}
				}
				else if (randMapa == 5) {
					if (mapa5.tileECaminhavel(warrior->getX(), warrior->getY() - 1.0))
					{
						warrior->setDestino(warrior->getX(), warrior->getY() - 1.0);
					}
				}
				else if (randMapa == 6) {
					if (mapa6.tileECaminhavel(warrior->getX(), warrior->getY() - 1.0))
					{
						warrior->setDestino(warrior->getX(), warrior->getY() - 1.0);
					}
				}
				
			}
			else if (gTeclado.segurando[TECLA_BAIXO])
			{
				if (randMapa == 1) {
					if (mapa.tileECaminhavel(warrior->getX(), warrior->getY() + 1.0))
					{
						warrior->setDestino(warrior->getX(), warrior->getY() + 1.0);
					}
				}
				else if (randMapa == 2) {
					if (mapa2.tileECaminhavel(warrior->getX(), warrior->getY() + 1.0))
					{
						warrior->setDestino(warrior->getX(), warrior->getY() + 1.0);
					}
				}
				else if (randMapa == 3) {
					if (mapa3.tileECaminhavel(warrior->getX(), warrior->getY() + 1.0))
					{
						warrior->setDestino(warrior->getX(), warrior->getY() + 1.0);
					}
				}
				else if (randMapa == 4) {
					if (mapa4.tileECaminhavel(warrior->getX(), warrior->getY() + 1.0))
					{
						warrior->setDestino(warrior->getX(), warrior->getY() + 1.0);
					}
				}
				else if (randMapa == 5) {
					if (mapa5.tileECaminhavel(warrior->getX(), warrior->getY() + 1.0))
					{
						warrior->setDestino(warrior->getX(), warrior->getY() + 1.0);
					}
				}
				else if (randMapa == 6) {
					if (mapa6.tileECaminhavel(warrior->getX(), warrior->getY() + 1.0))
					{
						warrior->setDestino(warrior->getX(), warrior->getY() + 1.0);
					}
				}
				
			}
		}
	}
}

void Jogo::atualizarInputThief()
{
	if (thief->isSelected()) {
		if (!thief->estaMovendo())
		{
			if (gTeclado.segurando[TECLA_DIR])
			{
				if (randMapa == 1) {
					if (mapa.tileECaminhavel(thief->getX() + 1.0, thief->getY()))
					{
						thief->setDestino(thief->getX() + 1.0, thief->getY());
					}
				}
				else if (randMapa == 2) {
					if (mapa2.tileECaminhavel(thief->getX() + 1.0, thief->getY()))
					{
						thief->setDestino(thief->getX() + 1.0, thief->getY());
					}
				}
				else if (randMapa == 3) {
					if (mapa3.tileECaminhavel(thief->getX() + 1.0, thief->getY()))
					{
						thief->setDestino(thief->getX() + 1.0, thief->getY());
					}
				}
				else if (randMapa == 4) {
					if (mapa4.tileECaminhavel(thief->getX() + 1.0, thief->getY()))
					{
						thief->setDestino(thief->getX() + 1.0, thief->getY());
					}
				}
				else if (randMapa == 5) {
					if (mapa5.tileECaminhavel(thief->getX() + 1.0, thief->getY()))
					{
						thief->setDestino(thief->getX() + 1.0, thief->getY());
					}
				}
				else if (randMapa == 6) {
					if (mapa6.tileECaminhavel(thief->getX() + 1.0, thief->getY()))
					{
						thief->setDestino(thief->getX() + 1.0, thief->getY());
					}
				}
			}
			else if (gTeclado.segurando[TECLA_ESQ])
			{
				if (randMapa == 1) {
					if (mapa.tileECaminhavel(thief->getX() - 1.0, thief->getY()))
					{
						thief->setDestino(thief->getX() - 1.0, thief->getY());
					}
				}
				else if (randMapa == 2) {
					if (mapa2.tileECaminhavel(thief->getX() - 1.0, thief->getY()))
					{
						thief->setDestino(thief->getX() - 1.0, thief->getY());
					}
				}
				else if (randMapa == 3) {
					if (mapa3.tileECaminhavel(thief->getX() - 1.0, thief->getY()))
					{
						thief->setDestino(thief->getX() - 1.0, thief->getY());
					}
				}
				else if (randMapa == 4) {
					if (mapa4.tileECaminhavel(thief->getX() - 1.0, thief->getY()))
					{
						thief->setDestino(thief->getX() - 1.0, thief->getY());
					}
				}
				else if (randMapa == 5) {
					if (mapa5.tileECaminhavel(thief->getX() - 1.0, thief->getY()))
					{
						thief->setDestino(thief->getX() - 1.0, thief->getY());
					}
				}
				else if (randMapa == 6) {
					if (mapa6.tileECaminhavel(thief->getX() - 1.0, thief->getY()))
					{
						thief->setDestino(thief->getX() - 1.0, thief->getY());
					}
				}
				
			}
			else if (gTeclado.segurando[TECLA_CIMA])
			{
				if (randMapa == 1) {
					if (mapa.tileECaminhavel(thief->getX(), thief->getY() - 1.0))
					{
						thief->setDestino(thief->getX(), thief->getY() - 1.0);
					}
				}
				else if (randMapa == 2) {
					if (mapa2.tileECaminhavel(thief->getX(), thief->getY() - 1.0))
					{
						thief->setDestino(thief->getX(), thief->getY() - 1.0);
					}
				}
				else if (randMapa == 3) {
					if (mapa3.tileECaminhavel(thief->getX(), thief->getY() - 1.0))
					{
						thief->setDestino(thief->getX(), thief->getY() - 1.0);
					}
				}
				else if (randMapa == 4) {
					if (mapa4.tileECaminhavel(thief->getX(), thief->getY() - 1.0))
					{
						thief->setDestino(thief->getX(), thief->getY() - 1.0);
					}
				}
				else if (randMapa == 5) {
					if (mapa5.tileECaminhavel(thief->getX(), thief->getY() - 1.0))
					{
						thief->setDestino(thief->getX(), thief->getY() - 1.0);
					}
				}
				else if (randMapa == 6) {
					if (mapa6.tileECaminhavel(thief->getX(), thief->getY() - 1.0))
					{
						thief->setDestino(thief->getX(), thief->getY() - 1.0);
					}
				}
				
			}
			else if (gTeclado.segurando[TECLA_BAIXO])
			{
				if (randMapa == 1) {
					if (mapa.tileECaminhavel(thief->getX(), thief->getY() + 1.0))
					{
						thief->setDestino(thief->getX(), thief->getY() + 1.0);
					}
				}
				else if (randMapa == 2) {
					if (mapa2.tileECaminhavel(thief->getX(), thief->getY() + 1.0))
					{
						thief->setDestino(thief->getX(), thief->getY() + 1.0);
					}
				}
				else if (randMapa == 3) {
					if (mapa3.tileECaminhavel(thief->getX(), thief->getY() + 1.0))
					{
						thief->setDestino(thief->getX(), thief->getY() + 1.0);
					}
				}
				else if (randMapa == 4) {
					if (mapa4.tileECaminhavel(thief->getX(), thief->getY() + 1.0))
					{
						thief->setDestino(thief->getX(), thief->getY() + 1.0);
					}
				}
				else if (randMapa == 5) {
					if (mapa5.tileECaminhavel(thief->getX(), thief->getY() + 1.0))
					{
						thief->setDestino(thief->getX(), thief->getY() + 1.0);
					}
				}
				else if (randMapa == 6) {
					if (mapa6.tileECaminhavel(thief->getX(), thief->getY() + 1.0))
					{
						thief->setDestino(thief->getX(), thief->getY() + 1.0);
					}
				}
				
			}
		}
	}
}

void Jogo::telaSelect()
{
	fundoSelect.desenhar(gJanela.getLargura() / 2, gJanela.getAltura() / 2);

	btn1.atualizar();
	btn2.atualizar();
	btn3.atualizar();

	btn1.desenhar();
	btn2.desenhar();
	btn3.desenhar();

	warrior = new Warrior();
	mage = new Mage();
	thief = new Thief();


	// depois que sorteou as posições, confere o input:
	
	// botão do guerreiro
	if (btn1.estaClicado()) {

		if (randMapa == 1) {

			mapa.carregar("assets/mapa1.json");
			mapa.carregarConfigTileSet("tiles", "assets/config.txt");
			warrior->inicializar("warrior", mapa.getCamadaDeObjetos("Objetos")->getObjeto("Player"));
			warrior->setPos(15, 2);
		}
		else if (randMapa == 2) {

			mapa2.carregar("assets/mapa2.json");
			mapa2.carregarConfigTileSet("tiles", "assets/config.txt");
			warrior->inicializar("warrior", mapa2.getCamadaDeObjetos("Objetos")->getObjeto("Player"));
			warrior->setPos(2, 4);
		}
		else if (randMapa == 3) {

			mapa3.carregar("assets/mapa3.json");
			mapa3.carregarConfigTileSet("tiles", "assets/config.txt");
			warrior->inicializar("warrior", mapa3.getCamadaDeObjetos("Objetos")->getObjeto("Player"));
			
		}
		else if (randMapa == 4) {

			mapa4.carregar("assets/mapa4.json");
			mapa4.carregarConfigTileSet("tiles", "assets/config.txt");
			warrior->inicializar("warrior", mapa4.getCamadaDeObjetos("Objetos")->getObjeto("Player"));

		}
		else if (randMapa == 5) {

			mapa5.carregar("assets/mapa5.json");
			mapa5.carregarConfigTileSet("tiles", "assets/config.txt");
			warrior->inicializar("warrior", mapa5.getCamadaDeObjetos("Objetos")->getObjeto("Player"));

		}
		else if (randMapa == 6) {

			mapa6.carregar("assets/mapa6.json");
			mapa6.carregarConfigTileSet("tiles", "assets/config.txt");
			warrior->inicializar("warrior", mapa6.getCamadaDeObjetos("Objetos")->getObjeto("Player"));

		}

		warrior->select();
		warrior->setSom("warriorskill");
		setarMonstros();
		setarItens();
		playerSpr = *warrior->getObjeto().getSprite();

		idTelas = T_JOGO;
	}

	// botão do ladino
	if (btn2.estaClicado()) {

		if (randMapa == 1) {

			mapa.carregar("assets/mapa1.json");
			mapa.carregarConfigTileSet("tiles", "assets/config.txt");
			thief->inicializar("thief", mapa.getCamadaDeObjetos("Objetos")->getObjeto("Player"));
			thief->setPos(15, 2);
		}
		else if (randMapa == 2) {

			mapa2.carregar("assets/mapa2.json");
			mapa2.carregarConfigTileSet("tiles", "assets/config.txt");
			thief->inicializar("thief", mapa2.getCamadaDeObjetos("Objetos")->getObjeto("Player"));
			thief->setPos(2, 4);
		}
		else if (randMapa == 3) {

			mapa3.carregar("assets/mapa3.json");
			mapa3.carregarConfigTileSet("tiles", "assets/config.txt");
			thief->inicializar("thief", mapa3.getCamadaDeObjetos("Objetos")->getObjeto("Player"));
			
		}
		else if (randMapa == 4) {

			mapa4.carregar("assets/mapa4.json");
			mapa4.carregarConfigTileSet("tiles", "assets/config.txt");
			thief->inicializar("thief", mapa4.getCamadaDeObjetos("Objetos")->getObjeto("Player"));

		}
		else if (randMapa == 5) {

			mapa5.carregar("assets/mapa5.json");
			mapa5.carregarConfigTileSet("tiles", "assets/config.txt");
			thief->inicializar("thief", mapa5.getCamadaDeObjetos("Objetos")->getObjeto("Player"));

		}
		else if (randMapa == 6) {

			mapa6.carregar("assets/mapa6.json");
			mapa6.carregarConfigTileSet("tiles", "assets/config.txt");
			thief->inicializar("thief", mapa6.getCamadaDeObjetos("Objetos")->getObjeto("Player"));

		}


		thief->select();
		thief->setSom("thiefskill");
		setarMonstros();
		setarItens();
		playerSpr = *thief->getObjeto().getSprite();

		idTelas = T_JOGO;
	}

	// botão do mago
	if (btn3.estaClicado()) {

		if (randMapa == 1) {

			mapa.carregar("assets/mapa1.json");
			mapa.carregarConfigTileSet("tiles", "assets/config.txt");
			mage->inicializar("mage", mapa.getCamadaDeObjetos("Objetos")->getObjeto("Player"));
			mage->setPos(15, 2);
		}
		else if (randMapa == 2) {

			mapa2.carregar("assets/mapa2.json");
			mapa2.carregarConfigTileSet("tiles", "assets/config.txt");
			mage->inicializar("mage", mapa2.getCamadaDeObjetos("Objetos")->getObjeto("Player"));
			mage->setPos(2, 4);

		}
		else if (randMapa == 3) {

			mapa3.carregar("assets/mapa3.json");
			mapa3.carregarConfigTileSet("tiles", "assets/config.txt");
			mage->inicializar("mage", mapa3.getCamadaDeObjetos("Objetos")->getObjeto("Player"));

		}
		else if (randMapa == 4) {

			mapa4.carregar("assets/mapa4.json");
			mapa4.carregarConfigTileSet("tiles", "assets/config.txt");
			mage->inicializar("mage", mapa4.getCamadaDeObjetos("Objetos")->getObjeto("Player"));

		}
		else if (randMapa == 5) {

			mapa5.carregar("assets/mapa5.json");
			mapa5.carregarConfigTileSet("tiles", "assets/config.txt");
			mage->inicializar("mage", mapa5.getCamadaDeObjetos("Objetos")->getObjeto("Player"));

		}
		else if (randMapa == 6) {

			mapa6.carregar("assets/mapa6.json");
			mapa6.carregarConfigTileSet("tiles", "assets/config.txt");
			mage->inicializar("mage", mapa6.getCamadaDeObjetos("Objetos")->getObjeto("Player"));

		}

		mage->select();
		mage->setSom("mageskill");
		setarMonstros();
		setarItens();
		playerSpr = *mage->getObjeto().getSprite();


		idTelas = T_JOGO;
	}
}

void Jogo::telaJogo()
{
	
	if (gameover) {
		
		// idTelas = T_GAMEOVER precisa ser criada.


	}

	// tela do inventário:
	if (gTeclado.pressionou[TECLA_I]) {
		idTelas = T_MOCHILA;
	}

	// atualiza input do jogador
	if (mage->isSelected()) {
		
		atualizarInputMage();
		mage->atualizar();
		mage->skill();
		playerDef = mage->getDef();
		
	}
	else if (warrior->isSelected()) {
			
		atualizarInputWarrior();
		warrior->atualizar();
		warrior->skill();
		playerDef = warrior->getDef();
	}
	else if (thief->isSelected()) {
		
		atualizarInputThief();
		thief->atualizar();
		thief->skill();
		playerDef = thief->getDef();
	}
	// atualiza animação do monstro
	for (int i = 0; i < monstrosNaSala; i++) {
		monstro[i].atualizarMonstro();
	}

	// mapa desenhado de acordo com sorteio, monstro e jogador são desenhados com o mapa
	if (randMapa == 1) {
		
		mapa.desenhar();


		if (mage->isSelected()) {
			mapa.setPosCentro(mage->getX(), mage->getY());
			playerX = mage->getX();
			playerY = mage->getY();
			mage->desenhaVida();
		}
		else if (warrior->isSelected()) {
			mapa.setPosCentro(warrior->getX(), warrior->getY());
			playerX = warrior->getX();
			playerY = warrior->getY();
			warrior->desenhaVida();
		}
		else if (thief->isSelected()) {
			mapa.setPosCentro(thief->getX(), thief->getY());
			playerX = thief->getX();
			playerY = thief->getY();
			thief->desenhaVida();
		}


	}
	else if (randMapa == 2) {

		mapa2.desenhar();


		if (mage->isSelected()) {
			mapa2.setPosCentro(mage->getX(), mage->getY());
			playerX = mage->getX();
			playerY = mage->getY();
			mage->desenhaVida();
		}
		else if (warrior->isSelected()) {
			mapa2.setPosCentro(warrior->getX(), warrior->getY());
			playerX = warrior->getX();
			playerY = warrior->getY();
			warrior->desenhaVida();
		}
		else if (thief->isSelected()) {
			mapa2.setPosCentro(thief->getX(), thief->getY());
			playerX = thief->getX();
			playerY = thief->getY();
			thief->desenhaVida();
		}

	}
	else if (randMapa == 3) {

		mapa3.desenhar();


		if (mage->isSelected()) {
			mapa3.setPosCentro(mage->getX(), mage->getY());
			playerX = mage->getX();
			playerY = mage->getY();
			mage->desenhaVida();
		}
		else if (warrior->isSelected()) {
			mapa3.setPosCentro(warrior->getX(), warrior->getY());
			playerX = warrior->getX();
			playerY = warrior->getY();
			warrior->desenhaVida();
		}
		else if (thief->isSelected()) {
			mapa3.setPosCentro(thief->getX(), thief->getY());
			playerX = thief->getX();
			playerY = thief->getY();
			thief->desenhaVida();
		}

	}
	else if (randMapa == 4) {

		mapa4.desenhar();


		if (mage->isSelected()) {
			mapa4.setPosCentro(mage->getX(), mage->getY());
			playerX = mage->getX();
			playerY = mage->getY();
			mage->desenhaVida();
		}
		else if (warrior->isSelected()) {
			mapa4.setPosCentro(warrior->getX(), warrior->getY());
			playerX = warrior->getX();
			playerY = warrior->getY();
			warrior->desenhaVida();
		}
		else if (thief->isSelected()) {
			mapa4.setPosCentro(thief->getX(), thief->getY());
			playerX = thief->getX();
			playerY = thief->getY();
			thief->desenhaVida();
		}

	}
	else if (randMapa == 5) {

		mapa5.desenhar();


		if (mage->isSelected()) {
			mapa5.setPosCentro(mage->getX(), mage->getY());
			playerX = mage->getX();
			playerY = mage->getY();
			mage->desenhaVida();
		}
		else if (warrior->isSelected()) {
			mapa5.setPosCentro(warrior->getX(), warrior->getY());
			playerX = warrior->getX();
			playerY = warrior->getY();
			warrior->desenhaVida();
		}
		else if (thief->isSelected()) {
			mapa5.setPosCentro(thief->getX(), thief->getY());
			playerX = thief->getX();
			playerY = thief->getY();
			thief->desenhaVida();
		}

	}
	else if (randMapa == 6) {

		mapa2.desenhar();


		if (mage->isSelected()) {
			mapa6.setPosCentro(mage->getX(), mage->getY());
			playerX = mage->getX();
			playerY = mage->getY();
			mage->desenhaVida();
		}
		else if (warrior->isSelected()) {
			mapa6.setPosCentro(warrior->getX(), warrior->getY());
			playerX = warrior->getX();
			playerY = warrior->getY();
			warrior->desenhaVida();
		}
		else if (thief->isSelected()) {
			mapa6.setPosCentro(thief->getX(), thief->getY());
			playerX = thief->getX();
			playerY = thief->getY();
			thief->desenhaVida();
		}

	}
	
	testarColisao();
	testarColisaoBaus();
}

void Jogo::lerMonstros()
{

	string nomeMonstro, fileMonstro;
	int vida, def, idM = 0;

	ifstream monstros("assets/monst.txt");

	if (monstros) {

		monstros >> nMonstrosLidos;

		tipo = new TipoMonstro[nMonstrosLidos]();


		for (int i = 0; i < nMonstrosLidos; i++) {


			monstros >> idM;
			tipo[i].setID(idM);

			monstros >> vida;
			tipo[i].setVida(vida);

			monstros >> def;
			tipo[i].setDefesa(def);

			monstros >> fileMonstro;
			tipo[i].setCaminho(fileMonstro);

			monstros >> nomeMonstro;
			tipo[i].setNome(nomeMonstro);

		}
	}
	else
		nMonstrosLidos = 0;
	monstros.close();
}

void Jogo::lerItens()
{
	string nomeItem, fileItem;
	int bonusHP, bonusDef, bonusAtk, id = 0;

	ifstream itens("assets/itens.txt");

	if (itens)
	{
		itens >> qtdItens;
		tipoI = new TipoItem[qtdItens]();

		for (int i = 0; i < qtdItens; i++) {
			itens >> id;
			tipoI[i].setId(id);
			itens >> nomeItem;
			tipoI[i].setNome(nomeItem);
			itens >> fileItem;
			tipoI[i].setFile(fileItem);
			itens >> bonusHP;
			tipoI[i].setBonusHP(bonusHP);
			itens >> bonusDef;
			tipoI[i].setBonusDef(bonusDef);
			itens >> bonusAtk;
			tipoI[i].setBonusAtk(bonusAtk);
		}
	}
	else
		qtdItens = 0;
	itens.close();
}

void Jogo::setarMonstros()
{
	// sorteios antes da tela do jogo
	monstrosNaSala = uniRandEntre(0, 5);
	monstro = new Monstro[monstrosNaSala];
	lerMonstros(); // ler os tipos de monstros disponíveis

	int randTipo, monX, monY;

	if (randMapa == 1) {
		if (monstrosNaSala > 0) { // Se é > 0, já possui 1. Se é > 1, já possui 2 e assim por diante.

			randTipo = uniRandEntre(0, nMonstrosLidos-1);
			monstro[0].inicializarMonstro(tipo[randTipo].getNome(), tipo[randTipo].getDefesa(), tipo[randTipo].getVida());
			

			// sortear posição até ser disponível
			do {
				monX = uniRandEntre(0, 31);
				monY = uniRandEntre(0, 23);
			} while (!mapa.tileECaminhavel(monX, monY) || mapa.existeObjetoNaPos(monX, monY) || mapa.existeObjetoNaPos(monX + 1, monY + 1) || mapa.existeObjetoNaPos(monX + 2, monY + 2));

			// quando a posição sorteada for disponível:

			monstro[0].setObj(mapa.getCamadaDeObjetos("Monstros")->getObjeto("monstro1"));
			monstro[0].setPos(monX, monY);

			// deixar o monstro visível
			mapa.getCamadaDeObjetos("Monstros")->getObjeto("monstro1")->setVisivel(true);

			if (monstrosNaSala > 1) {

				randTipo = uniRandEntre(0, nMonstrosLidos-1);
				monstro[1].inicializarMonstro(tipo[randTipo].getNome(), tipo[randTipo].getDefesa(), tipo[randTipo].getVida());

				do {
					monX = uniRandEntre(0, 31);
					monY = uniRandEntre(0, 23);
				} while (!mapa.tileECaminhavel(monX, monY) || mapa.existeObjetoNaPos(monX, monY) || mapa.existeObjetoNaPos(monX + 1, monY + 1) || mapa.existeObjetoNaPos(monX + 2, monY + 2));


				monstro[1].setObj(mapa.getCamadaDeObjetos("Monstros")->getObjeto("monstro2"));
				monstro[1].setPos(monX, monY);
				mapa.getCamadaDeObjetos("Monstros")->getObjeto("monstro2")->setVisivel(true);


				if (monstrosNaSala > 2) {

					randTipo = uniRandEntre(0, nMonstrosLidos-1);
					monstro[2].inicializarMonstro(tipo[randTipo].getNome(), tipo[randTipo].getDefesa(), tipo[randTipo].getVida());

					do {
						monX = uniRandEntre(0, 31);
						monY = uniRandEntre(0, 23);
					} while (!mapa.tileECaminhavel(monX, monY) || mapa.existeObjetoNaPos(monX, monY) || mapa.existeObjetoNaPos(monX + 1, monY + 1) || mapa.existeObjetoNaPos(monX + 2, monY + 2));


					monstro[2].setObj(mapa.getCamadaDeObjetos("Monstros")->getObjeto("monstro3"));
					monstro[2].setPos(monX, monY);
					mapa.getCamadaDeObjetos("Monstros")->getObjeto("monstro3")->setVisivel(true);


					if (monstrosNaSala > 3) {
						randTipo = uniRandEntre(0, nMonstrosLidos-1);
						monstro[3].inicializarMonstro(tipo[randTipo].getNome(), tipo[randTipo].getDefesa(), tipo[randTipo].getVida());

						do {
							monX = uniRandEntre(0, 31);
							monY = uniRandEntre(0, 23);
						} while (!mapa.tileECaminhavel(monX, monY) || mapa.existeObjetoNaPos(monX, monY) || mapa.existeObjetoNaPos(monX + 1, monY + 1) || mapa.existeObjetoNaPos(monX + 2, monY + 2));


						monstro[3].setObj(mapa.getCamadaDeObjetos("Monstros")->getObjeto("monstro4"));
						monstro[3].setPos(monX, monY);
						mapa.getCamadaDeObjetos("Monstros")->getObjeto("monstro4")->setVisivel(true);


						if (monstrosNaSala > 4) {

							randTipo = uniRandEntre(0, nMonstrosLidos-1);
							monstro[4].inicializarMonstro(tipo[randTipo].getNome(), tipo[randTipo].getDefesa(), tipo[randTipo].getVida());

							do {
								monX = uniRandEntre(0, 31);
								monY = uniRandEntre(0, 23);
							} while (!mapa.tileECaminhavel(monX, monY) || mapa.existeObjetoNaPos(monX, monY) || mapa.existeObjetoNaPos(monX + 1, monY + 1) || mapa.existeObjetoNaPos(monX + 2, monY + 2));


							monstro[4].setObj(mapa.getCamadaDeObjetos("Monstros")->getObjeto("monstro5"));
							monstro[4].setPos(monX, monY);
							mapa.getCamadaDeObjetos("Monstros")->getObjeto("monstro5")->setVisivel(true);

						}
					}
				}
			}

		}
	}
	else if (randMapa == 2) { // mapa 2
		if (monstrosNaSala > 0) { // Se é > 0, já possui 1. Se é > 1, já possui 2 e assim por diante.

			randTipo = uniRandEntre(0, nMonstrosLidos-1);
			monstro[0].inicializarMonstro(tipo[randTipo].getNome(), tipo[randTipo].getDefesa(), tipo[randTipo].getVida());

			// sortear posição até ser disponível
			do {
				monX = uniRandEntre(0, 31);
				monY = uniRandEntre(0, 23);
			} while (!mapa2.tileECaminhavel(monX, monY) || mapa2.existeObjetoNaPos(monX, monY) || mapa2.existeObjetoNaPos(monX + 1, monY + 1) || mapa2.existeObjetoNaPos(monX + 2, monY + 2));

			// quando a posição sorteada for disponível:
			monstro[0].setObj(mapa2.getCamadaDeObjetos("Monstros")->getObjeto("monstro1"));
			monstro[0].setPos(monX, monY);

			// deixar o monstro visivel
			mapa2.getCamadaDeObjetos("Monstros")->getObjeto("monstro1")->setVisivel(true);


			if (monstrosNaSala > 1) {

				randTipo = uniRandEntre(0, nMonstrosLidos-1);
				monstro[1].inicializarMonstro(tipo[randTipo].getNome(), tipo[randTipo].getDefesa(), tipo[randTipo].getVida());

				do {
					monX = uniRandEntre(0, 31);
					monY = uniRandEntre(0, 23);
				} while (!mapa2.tileECaminhavel(monX, monY) || mapa2.existeObjetoNaPos(monX, monY) || mapa2.existeObjetoNaPos(monX + 1, monY + 1) || mapa2.existeObjetoNaPos(monX + 2, monY + 2));


				monstro[1].setObj(mapa2.getCamadaDeObjetos("Monstros")->getObjeto("monstro2"));
				monstro[1].setPos(monX, monY);
				mapa2.getCamadaDeObjetos("Monstros")->getObjeto("monstro2")->setVisivel(true);


				if (monstrosNaSala > 2) {

					randTipo = uniRandEntre(0, nMonstrosLidos-1);
					monstro[2].inicializarMonstro(tipo[randTipo].getNome(), tipo[randTipo].getDefesa(), tipo[randTipo].getVida());

					do {
						monX = uniRandEntre(0, 31);
						monY = uniRandEntre(0, 23);
					} while (!mapa2.tileECaminhavel(monX, monY) || mapa2.existeObjetoNaPos(monX, monY) || mapa2.existeObjetoNaPos(monX + 1, monY + 1) || mapa2.existeObjetoNaPos(monX + 2, monY + 2));


					monstro[2].setObj(mapa2.getCamadaDeObjetos("Monstros")->getObjeto("monstro3"));
					monstro[2].setPos(monX, monY);
					mapa2.getCamadaDeObjetos("Monstros")->getObjeto("monstro3")->setVisivel(true);


					if (monstrosNaSala > 3) {
						randTipo = uniRandEntre(0, nMonstrosLidos-1);
						monstro[3].inicializarMonstro(tipo[randTipo].getNome(), tipo[randTipo].getDefesa(), tipo[randTipo].getVida());

						do {
							monX = uniRandEntre(0, 31);
							monY = uniRandEntre(0, 23);
						} while (!mapa2.tileECaminhavel(monX, monY) || mapa2.existeObjetoNaPos(monX, monY) || mapa2.existeObjetoNaPos(monX + 1, monY + 1) || mapa2.existeObjetoNaPos(monX + 2, monY + 2));


						monstro[3].setObj(mapa2.getCamadaDeObjetos("Monstros")->getObjeto("monstro4"));
						monstro[3].setPos(monX, monY);
						mapa2.getCamadaDeObjetos("Monstros")->getObjeto("monstro4")->setVisivel(true);


						if (monstrosNaSala > 4) {

							randTipo = uniRandEntre(0, nMonstrosLidos-1);
							monstro[4].inicializarMonstro(tipo[randTipo].getNome(), tipo[randTipo].getDefesa(), tipo[randTipo].getVida());

							do {
								monX = uniRandEntre(0, 31);
								monY = uniRandEntre(0, 23);
							} while (!mapa2.tileECaminhavel(monX, monY) || mapa2.existeObjetoNaPos(monX, monY) || mapa2.existeObjetoNaPos(monX + 1, monY + 1) || mapa2.existeObjetoNaPos(monX + 2, monY + 2));


							monstro[4].setObj(mapa2.getCamadaDeObjetos("Monstros")->getObjeto("monstro5"));
							monstro[4].setPos(monX, monY);
							mapa2.getCamadaDeObjetos("Monstros")->getObjeto("monstro5")->setVisivel(true);

						}
					}
				}
			}

		}
	}
	else if (randMapa == 3) { // mapa 3
		if (monstrosNaSala > 0) { // Se é > 0, já possui 1. Se é > 1, já possui 2 e assim por diante.

			randTipo = uniRandEntre(0, nMonstrosLidos - 1);
			monstro[0].inicializarMonstro(tipo[randTipo].getNome(), tipo[randTipo].getDefesa(), tipo[randTipo].getVida());

			// sortear posição até ser disponível
			do {
				monX = uniRandEntre(0, 31);
				monY = uniRandEntre(0, 23);
			} while (!mapa3.tileECaminhavel(monX, monY) || mapa3.existeObjetoNaPos(monX, monY) || mapa3.existeObjetoNaPos(monX + 1, monY + 1) || mapa3.existeObjetoNaPos(monX + 2, monY + 2));

			// quando a posição sorteada for disponível:
			monstro[0].setObj(mapa3.getCamadaDeObjetos("Monstros")->getObjeto("monstro1"));
			monstro[0].setPos(monX, monY);

			// deixar o monstro visivel
			mapa3.getCamadaDeObjetos("Monstros")->getObjeto("monstro1")->setVisivel(true);


			if (monstrosNaSala > 1) {

				randTipo = uniRandEntre(0, nMonstrosLidos - 1);
				monstro[1].inicializarMonstro(tipo[randTipo].getNome(), tipo[randTipo].getDefesa(), tipo[randTipo].getVida());

				do {
					monX = uniRandEntre(0, 31);
					monY = uniRandEntre(0, 23);
				} while (!mapa3.tileECaminhavel(monX, monY) || mapa3.existeObjetoNaPos(monX, monY) || mapa3.existeObjetoNaPos(monX + 1, monY + 1) || mapa3.existeObjetoNaPos(monX + 2, monY + 2));


				monstro[1].setObj(mapa3.getCamadaDeObjetos("Monstros")->getObjeto("monstro2"));
				monstro[1].setPos(monX, monY);
				mapa3.getCamadaDeObjetos("Monstros")->getObjeto("monstro2")->setVisivel(true);


				if (monstrosNaSala > 2) {

					randTipo = uniRandEntre(0, nMonstrosLidos - 1);
					monstro[2].inicializarMonstro(tipo[randTipo].getNome(), tipo[randTipo].getDefesa(), tipo[randTipo].getVida());

					do {
						monX = uniRandEntre(0, 31);
						monY = uniRandEntre(0, 23);
					} while (!mapa3.tileECaminhavel(monX, monY) || mapa3.existeObjetoNaPos(monX, monY) || mapa3.existeObjetoNaPos(monX + 1, monY + 1) || mapa3.existeObjetoNaPos(monX + 2, monY + 2));


					monstro[2].setObj(mapa3.getCamadaDeObjetos("Monstros")->getObjeto("monstro3"));
					monstro[2].setPos(monX, monY);
					mapa3.getCamadaDeObjetos("Monstros")->getObjeto("monstro3")->setVisivel(true);


					if (monstrosNaSala > 3) {
						randTipo = uniRandEntre(0, nMonstrosLidos - 1);
						monstro[3].inicializarMonstro(tipo[randTipo].getNome(), tipo[randTipo].getDefesa(), tipo[randTipo].getVida());

						do {
							monX = uniRandEntre(0, 31);
							monY = uniRandEntre(0, 23);
						} while (!mapa3.tileECaminhavel(monX, monY) || mapa3.existeObjetoNaPos(monX, monY) || mapa3.existeObjetoNaPos(monX + 1, monY + 1) || mapa3.existeObjetoNaPos(monX + 2, monY + 2));


						monstro[3].setObj(mapa3.getCamadaDeObjetos("Monstros")->getObjeto("monstro4"));
						monstro[3].setPos(monX, monY);
						mapa3.getCamadaDeObjetos("Monstros")->getObjeto("monstro4")->setVisivel(true);


						if (monstrosNaSala > 4) {

							randTipo = uniRandEntre(0, nMonstrosLidos - 1);
							monstro[4].inicializarMonstro(tipo[randTipo].getNome(), tipo[randTipo].getDefesa(), tipo[randTipo].getVida());

							do {
								monX = uniRandEntre(0, 31);
								monY = uniRandEntre(0, 23);
							} while (!mapa3.tileECaminhavel(monX, monY) || mapa3.existeObjetoNaPos(monX, monY) || mapa3.existeObjetoNaPos(monX + 1, monY + 1) || mapa3.existeObjetoNaPos(monX + 2, monY + 2));


							monstro[4].setObj(mapa3.getCamadaDeObjetos("Monstros")->getObjeto("monstro5"));
							monstro[4].setPos(monX, monY);
							mapa3.getCamadaDeObjetos("Monstros")->getObjeto("monstro5")->setVisivel(true);

						}
					}
				}
			}

		}
	}
	else if (randMapa == 4) { // mapa 4
		if (monstrosNaSala > 0) { // Se é > 0, já possui 1. Se é > 1, já possui 2 e assim por diante.

			randTipo = uniRandEntre(0, nMonstrosLidos - 1);
			monstro[0].inicializarMonstro(tipo[randTipo].getNome(), tipo[randTipo].getDefesa(), tipo[randTipo].getVida());

			// sortear posição até ser disponível
			do {
				monX = uniRandEntre(0, 31);
				monY = uniRandEntre(0, 23);
			} while (!mapa4.tileECaminhavel(monX, monY) || mapa4.existeObjetoNaPos(monX, monY) || mapa4.existeObjetoNaPos(monX + 1, monY + 1) || mapa4.existeObjetoNaPos(monX + 2, monY + 2));

			// quando a posição sorteada for disponível:
			monstro[0].setObj(mapa4.getCamadaDeObjetos("Monstros")->getObjeto("monstro1"));
			monstro[0].setPos(monX, monY);

			// deixar o monstro visivel
			mapa4.getCamadaDeObjetos("Monstros")->getObjeto("monstro1")->setVisivel(true);


			if (monstrosNaSala > 1) {

				randTipo = uniRandEntre(0, nMonstrosLidos - 1);
				monstro[1].inicializarMonstro(tipo[randTipo].getNome(), tipo[randTipo].getDefesa(), tipo[randTipo].getVida());

				do {
					monX = uniRandEntre(0, 31);
					monY = uniRandEntre(0, 23);
				} while (!mapa4.tileECaminhavel(monX, monY) || mapa4.existeObjetoNaPos(monX, monY) || mapa4.existeObjetoNaPos(monX + 1, monY + 1) || mapa4.existeObjetoNaPos(monX + 2, monY + 2));


				monstro[1].setObj(mapa4.getCamadaDeObjetos("Monstros")->getObjeto("monstro2"));
				monstro[1].setPos(monX, monY);
				mapa4.getCamadaDeObjetos("Monstros")->getObjeto("monstro2")->setVisivel(true);


				if (monstrosNaSala > 2) {

					randTipo = uniRandEntre(0, nMonstrosLidos - 1);
					monstro[2].inicializarMonstro(tipo[randTipo].getNome(), tipo[randTipo].getDefesa(), tipo[randTipo].getVida());

					do {
						monX = uniRandEntre(0, 31);
						monY = uniRandEntre(0, 23);
					} while (!mapa4.tileECaminhavel(monX, monY) || mapa4.existeObjetoNaPos(monX, monY) || mapa4.existeObjetoNaPos(monX + 1, monY + 1) || mapa4.existeObjetoNaPos(monX + 2, monY + 2));


					monstro[2].setObj(mapa4.getCamadaDeObjetos("Monstros")->getObjeto("monstro3"));
					monstro[2].setPos(monX, monY);
					mapa4.getCamadaDeObjetos("Monstros")->getObjeto("monstro3")->setVisivel(true);


					if (monstrosNaSala > 3) {
						randTipo = uniRandEntre(0, nMonstrosLidos - 1);
						monstro[3].inicializarMonstro(tipo[randTipo].getNome(), tipo[randTipo].getDefesa(), tipo[randTipo].getVida());

						do {
							monX = uniRandEntre(0, 31);
							monY = uniRandEntre(0, 23);
						} while (!mapa4.tileECaminhavel(monX, monY) || mapa4.existeObjetoNaPos(monX, monY) || mapa4.existeObjetoNaPos(monX + 1, monY + 1) || mapa4.existeObjetoNaPos(monX + 2, monY + 2));


						monstro[3].setObj(mapa4.getCamadaDeObjetos("Monstros")->getObjeto("monstro4"));
						monstro[3].setPos(monX, monY);
						mapa4.getCamadaDeObjetos("Monstros")->getObjeto("monstro4")->setVisivel(true);


						if (monstrosNaSala > 4) {

							randTipo = uniRandEntre(0, nMonstrosLidos - 1);
							monstro[4].inicializarMonstro(tipo[randTipo].getNome(), tipo[randTipo].getDefesa(), tipo[randTipo].getVida());

							do {
								monX = uniRandEntre(0, 31);
								monY = uniRandEntre(0, 23);
							} while (!mapa4.tileECaminhavel(monX, monY) || mapa4.existeObjetoNaPos(monX, monY) || mapa4.existeObjetoNaPos(monX + 1, monY + 1) || mapa4.existeObjetoNaPos(monX + 2, monY + 2));


							monstro[4].setObj(mapa4.getCamadaDeObjetos("Monstros")->getObjeto("monstro5"));
							monstro[4].setPos(monX, monY);
							mapa4.getCamadaDeObjetos("Monstros")->getObjeto("monstro5")->setVisivel(true);

						}
					}
				}
			}

		}
	}
	else if (randMapa == 5) { // mapa 5
		if (monstrosNaSala > 0) { // Se é > 0, já possui 1. Se é > 1, já possui 2 e assim por diante.

			randTipo = uniRandEntre(0, nMonstrosLidos - 1);
			monstro[0].inicializarMonstro(tipo[randTipo].getNome(), tipo[randTipo].getDefesa(), tipo[randTipo].getVida());

			// sortear posição até ser disponível
			do {
				monX = uniRandEntre(0, 31);
				monY = uniRandEntre(0, 23);
			} while (!mapa5.tileECaminhavel(monX, monY) || mapa5.existeObjetoNaPos(monX, monY) || mapa5.existeObjetoNaPos(monX + 1, monY + 1) || mapa5.existeObjetoNaPos(monX + 2, monY + 2));

			// quando a posição sorteada for disponível:
			monstro[0].setObj(mapa5.getCamadaDeObjetos("Monstros")->getObjeto("monstro1"));
			monstro[0].setPos(monX, monY);

			// deixar o monstro visivel
			mapa5.getCamadaDeObjetos("Monstros")->getObjeto("monstro1")->setVisivel(true);


			if (monstrosNaSala > 1) {

				randTipo = uniRandEntre(0, nMonstrosLidos - 1);
				monstro[1].inicializarMonstro(tipo[randTipo].getNome(), tipo[randTipo].getDefesa(), tipo[randTipo].getVida());

				do {
					monX = uniRandEntre(0, 31);
					monY = uniRandEntre(0, 23);
				} while (!mapa5.tileECaminhavel(monX, monY) || mapa5.existeObjetoNaPos(monX, monY) || mapa5.existeObjetoNaPos(monX + 1, monY + 1) || mapa5.existeObjetoNaPos(monX + 2, monY + 2));


				monstro[1].setObj(mapa5.getCamadaDeObjetos("Monstros")->getObjeto("monstro2"));
				monstro[1].setPos(monX, monY);
				mapa5.getCamadaDeObjetos("Monstros")->getObjeto("monstro2")->setVisivel(true);


				if (monstrosNaSala > 2) {

					randTipo = uniRandEntre(0, nMonstrosLidos - 1);
					monstro[2].inicializarMonstro(tipo[randTipo].getNome(), tipo[randTipo].getDefesa(), tipo[randTipo].getVida());

					do {
						monX = uniRandEntre(0, 31);
						monY = uniRandEntre(0, 23);
					} while (!mapa5.tileECaminhavel(monX, monY) || mapa5.existeObjetoNaPos(monX, monY) || mapa5.existeObjetoNaPos(monX + 1, monY + 1) || mapa5.existeObjetoNaPos(monX + 2, monY + 2));


					monstro[2].setObj(mapa5.getCamadaDeObjetos("Monstros")->getObjeto("monstro3"));
					monstro[2].setPos(monX, monY);
					mapa5.getCamadaDeObjetos("Monstros")->getObjeto("monstro3")->setVisivel(true);


					if (monstrosNaSala > 3) {
						randTipo = uniRandEntre(0, nMonstrosLidos - 1);
						monstro[3].inicializarMonstro(tipo[randTipo].getNome(), tipo[randTipo].getDefesa(), tipo[randTipo].getVida());

						do {
							monX = uniRandEntre(0, 31);
							monY = uniRandEntre(0, 23);
						} while (!mapa5.tileECaminhavel(monX, monY) || mapa5.existeObjetoNaPos(monX, monY) || mapa5.existeObjetoNaPos(monX + 1, monY + 1) || mapa5.existeObjetoNaPos(monX + 2, monY + 2));


						monstro[3].setObj(mapa5.getCamadaDeObjetos("Monstros")->getObjeto("monstro4"));
						monstro[3].setPos(monX, monY);
						mapa5.getCamadaDeObjetos("Monstros")->getObjeto("monstro4")->setVisivel(true);


						if (monstrosNaSala > 4) {

							randTipo = uniRandEntre(0, nMonstrosLidos - 1);
							monstro[4].inicializarMonstro(tipo[randTipo].getNome(), tipo[randTipo].getDefesa(), tipo[randTipo].getVida());

							do {
								monX = uniRandEntre(0, 31);
								monY = uniRandEntre(0, 23);
							} while (!mapa5.tileECaminhavel(monX, monY) || mapa5.existeObjetoNaPos(monX, monY) || mapa5.existeObjetoNaPos(monX + 1, monY + 1) || mapa5.existeObjetoNaPos(monX + 2, monY + 2));


							monstro[4].setObj(mapa5.getCamadaDeObjetos("Monstros")->getObjeto("monstro5"));
							monstro[4].setPos(monX, monY);
							mapa5.getCamadaDeObjetos("Monstros")->getObjeto("monstro5")->setVisivel(true);

						}
					}
				}
			}

		}
	}
	else if (randMapa == 6) { // mapa 6
		if (monstrosNaSala > 0) { // Se é > 0, já possui 1. Se é > 1, já possui 2 e assim por diante.

			randTipo = uniRandEntre(0, nMonstrosLidos - 1);
			monstro[0].inicializarMonstro(tipo[randTipo].getNome(), tipo[randTipo].getDefesa(), tipo[randTipo].getVida());

			// sortear posição até ser disponível
			do {
				monX = uniRandEntre(0, 31);
				monY = uniRandEntre(0, 23);
			} while (!mapa6.tileECaminhavel(monX, monY) || mapa6.existeObjetoNaPos(monX, monY) || mapa6.existeObjetoNaPos(monX + 1, monY + 1) || mapa6.existeObjetoNaPos(monX + 2, monY + 2));

			// quando a posição sorteada for disponível:
			monstro[0].setObj(mapa6.getCamadaDeObjetos("Monstros")->getObjeto("monstro1"));
			monstro[0].setPos(monX, monY);

			// deixar o monstro visivel
			mapa6.getCamadaDeObjetos("Monstros")->getObjeto("monstro1")->setVisivel(true);


			if (monstrosNaSala > 1) {

				randTipo = uniRandEntre(0, nMonstrosLidos - 1);
				monstro[1].inicializarMonstro(tipo[randTipo].getNome(), tipo[randTipo].getDefesa(), tipo[randTipo].getVida());

				do {
					monX = uniRandEntre(0, 31);
					monY = uniRandEntre(0, 23);
				} while (!mapa6.tileECaminhavel(monX, monY) || mapa6.existeObjetoNaPos(monX, monY) || mapa6.existeObjetoNaPos(monX + 1, monY + 1) || mapa6.existeObjetoNaPos(monX + 2, monY + 2));


				monstro[1].setObj(mapa6.getCamadaDeObjetos("Monstros")->getObjeto("monstro2"));
				monstro[1].setPos(monX, monY);
				mapa6.getCamadaDeObjetos("Monstros")->getObjeto("monstro2")->setVisivel(true);


				if (monstrosNaSala > 2) {

					randTipo = uniRandEntre(0, nMonstrosLidos - 1);
					monstro[2].inicializarMonstro(tipo[randTipo].getNome(), tipo[randTipo].getDefesa(), tipo[randTipo].getVida());

					do {
						monX = uniRandEntre(0, 31);
						monY = uniRandEntre(0, 23);
					} while (!mapa6.tileECaminhavel(monX, monY) || mapa6.existeObjetoNaPos(monX, monY) || mapa6.existeObjetoNaPos(monX + 1, monY + 1) || mapa6.existeObjetoNaPos(monX + 2, monY + 2));


					monstro[2].setObj(mapa6.getCamadaDeObjetos("Monstros")->getObjeto("monstro3"));
					monstro[2].setPos(monX, monY);
					mapa6.getCamadaDeObjetos("Monstros")->getObjeto("monstro3")->setVisivel(true);


					if (monstrosNaSala > 3) {
						randTipo = uniRandEntre(0, nMonstrosLidos - 1);
						monstro[3].inicializarMonstro(tipo[randTipo].getNome(), tipo[randTipo].getDefesa(), tipo[randTipo].getVida());

						do {
							monX = uniRandEntre(0, 31);
							monY = uniRandEntre(0, 23);
						} while (!mapa6.tileECaminhavel(monX, monY) || mapa6.existeObjetoNaPos(monX, monY) || mapa6.existeObjetoNaPos(monX + 1, monY + 1) || mapa6.existeObjetoNaPos(monX + 2, monY + 2));


						monstro[3].setObj(mapa6.getCamadaDeObjetos("Monstros")->getObjeto("monstro4"));
						monstro[3].setPos(monX, monY);
						mapa6.getCamadaDeObjetos("Monstros")->getObjeto("monstro4")->setVisivel(true);


						if (monstrosNaSala > 4) {

							randTipo = uniRandEntre(0, nMonstrosLidos - 1);
							monstro[4].inicializarMonstro(tipo[randTipo].getNome(), tipo[randTipo].getDefesa(), tipo[randTipo].getVida());

							do {
								monX = uniRandEntre(0, 31);
								monY = uniRandEntre(0, 23);
							} while (!mapa6.tileECaminhavel(monX, monY) || mapa6.existeObjetoNaPos(monX, monY) || mapa6.existeObjetoNaPos(monX + 1, monY + 1) || mapa6.existeObjetoNaPos(monX + 2, monY + 2));


							monstro[4].setObj(mapa6.getCamadaDeObjetos("Monstros")->getObjeto("monstro5"));
							monstro[4].setPos(monX, monY);
							mapa6.getCamadaDeObjetos("Monstros")->getObjeto("monstro5")->setVisivel(true);

						}
					}
				}
			}

		}
	}
}

void Jogo::setarItens()
{
	// sorteios antes:
	tesourosNaSala = uniRandEntre(0, 2);
	tesouros = new Tesouro[tesourosNaSala];
	lerItens();

	int randTipoItem, posX, posY;

	// adiciona tesouros na sala
	if (randMapa == 1) {

		if (tesourosNaSala > 0) {

			sortear = uniRandEntre(0, 100);
			if (sortear < 21) {
				randTipoItem = uniRandEntre(0, qtdItens - 1);
				tesouros[0].inicializar(tipoI[randTipoItem].getNome(), tipoI[randTipoItem].getBonusHP(), tipoI[randTipoItem].getBonusDef(), tipoI[randTipoItem].getBonusAtk(), tipoI[randTipoItem].getId());
				tesouros[0].setIoO(1);
				tesouros[0].getObj().setPropriedade("NomeItem", tipoI[randTipoItem].getNome());

				if (tesouros[0].getObj().getPropriedade("NomeItem") == "Cristal") {
					tesouros[0].getObj().setPropriedade("Descricao", "Este item dá +3 pontos de ataque.");
				}
				else if (tesouros[0].getObj().getPropriedade("NomeItem") == "Presa") {
					tesouros[0].getObj().setPropriedade("Descricao", "Este item aumenta em 3 sua vida máxima.");
				}
				else if (tesouros[0].getObj().getPropriedade("NomeItem") == "Pedra") {
					tesouros[0].getObj().setPropriedade("Descricao", "Este item dá +3 pontos de defesa.");
				}
				else if (tesouros[0].getObj().getPropriedade("NomeItem") == "Pergaminho") {
					tesouros[0].getObj().setPropriedade("Descricao", "Este item aumenta em 1 o ataque, vida máxima e defesa.");
				}

				
			}
			else {
				int gold = uniRandEntre(1, 6) * 1000;
				tesouros[0].setGold(gold);
			}
			
			do {
				posX = uniRandEntre(0, 31);
				posY = uniRandEntre(0, 23);
			} while (!mapa.tileECaminhavel(posX, posY) || mapa.existeObjetoNaPos(posX, posY) || mapa.existeObjetoNaPos(posX + 1, posY + 1) || mapa.existeObjetoNaPos(posX + 2, posY + 2));

			tesouros[0].setSprite("bauFechado");
			tesouros[0].setObj(mapa.getCamadaDeObjetos("Objetos")->getObjeto("tesouro1"));
			tesouros[0].setPos(posX, posY);
			
			mapa.getCamadaDeObjetos("Objetos")->getObjeto("tesouro1")->setVisivel(true);

			if (tesourosNaSala > 1) {

				sortear = uniRandEntre(0, 100);
				if (sortear < 21) {
					randTipoItem = uniRandEntre(0, qtdItens - 1);
					tesouros[1].inicializar(tipoI[randTipoItem].getNome(), tipoI[randTipoItem].getBonusHP(), tipoI[randTipoItem].getBonusDef(), tipoI[randTipoItem].getBonusAtk(), tipoI[randTipoItem].getId());
					tesouros[1].setIoO(1);
					tesouros[1].getObj().setPropriedade("NomeItem", tipoI[randTipoItem].getNome());

					if (tesouros[1].getObj().getPropriedade("NomeItem") == "Cristal") {
						tesouros[1].getObj().setPropriedade("Descricao", "Este item dá +3 pontos de ataque.");
					}
					else if (tesouros[1].getObj().getPropriedade("NomeItem") == "Presa") {
						tesouros[1].getObj().setPropriedade("Descricao", "Este item aumenta em 3 sua vida máxima.");
					}
					else if (tesouros[1].getObj().getPropriedade("NomeItem") == "Pedra") {
						tesouros[1].getObj().setPropriedade("Descricao", "Este item dá +3 pontos de defesa.");
					}
					else if (tesouros[1].getObj().getPropriedade("NomeItem") == "Pergaminho") {
						tesouros[1].getObj().setPropriedade("Descricao", "Este item aumenta em 1 o ataque, vida máxima e defesa.");
					}

					

				}
				else {
					int gold = uniRandEntre(1, 6) * 1000;
					tesouros[1].setGold(gold);
				}
				do {
					posX = uniRandEntre(0, 31);
					posY = uniRandEntre(0, 23);
				} while (!mapa.tileECaminhavel(posX, posY) || mapa.existeObjetoNaPos(posX, posY) || mapa.existeObjetoNaPos(posX + 1, posY + 1) || mapa.existeObjetoNaPos(posX + 2, posY + 2));

				tesouros[1].setSprite("bauFechado");
				tesouros[1].setObj(mapa.getCamadaDeObjetos("Objetos")->getObjeto("tesouro2"));
				tesouros[1].setPos(posX, posY);

				mapa.getCamadaDeObjetos("Objetos")->getObjeto("tesouro2")->setVisivel(true);
			}
		}


	}
	else if (randMapa == 2) {

		if (tesourosNaSala > 0) {

			sortear = uniRandEntre(0, 100);
			if (sortear < 21) {
				randTipoItem = uniRandEntre(0, qtdItens - 1);
				tesouros[0].inicializar(tipoI[randTipoItem].getNome(), tipoI[randTipoItem].getBonusHP(), tipoI[randTipoItem].getBonusDef(), tipoI[randTipoItem].getBonusAtk(), tipoI[randTipoItem].getId());
				tesouros[0].setIoO(1);
				tesouros[0].getObj().setPropriedade("NomeItem", tipoI[randTipoItem].getNome());

				if (tesouros[0].getObj().getPropriedade("NomeItem") == "Cristal") {
					tesouros[0].getObj().setPropriedade("Descricao", "Este item dá +3 pontos de ataque.");
				}
				else if (tesouros[0].getObj().getPropriedade("NomeItem") == "Presa") {
					tesouros[0].getObj().setPropriedade("Descricao", "Este item aumenta em 3 sua vida máxima.");
				}
				else if (tesouros[0].getObj().getPropriedade("NomeItem") == "Pedra") {
					tesouros[0].getObj().setPropriedade("Descricao", "Este item dá +3 pontos de defesa.");
				}
				else if (tesouros[0].getObj().getPropriedade("NomeItem") == "Pergaminho") {
					tesouros[0].getObj().setPropriedade("Descricao", "Este item aumenta em 1 o ataque, vida máxima e defesa.");
				}


			}
			else {
				int gold = uniRandEntre(1, 6) * 1000;
				tesouros[0].setGold(gold);
			}
			do {
				posX = uniRandEntre(0, 31);
				posY = uniRandEntre(0, 23);
			} while (!mapa2.tileECaminhavel(posX, posY) || mapa2.existeObjetoNaPos(posX, posY) || mapa2.existeObjetoNaPos(posX + 1, posY + 1) || mapa2.existeObjetoNaPos(posX + 2, posY + 2));


			tesouros[0].setSprite("bauFechado");
			tesouros[0].setObj(mapa2.getCamadaDeObjetos("Objetos")->getObjeto("tesouro1"));
			tesouros[0].setPos(posX, posY);
			mapa2.getCamadaDeObjetos("Objetos")->getObjeto("tesouro1")->setVisivel(true);

			if (tesourosNaSala > 1) {

				sortear = uniRandEntre(0, 100);
				if (sortear < 21) {
					randTipoItem = uniRandEntre(0, qtdItens - 1);
					tesouros[1].inicializar(tipoI[randTipoItem].getNome(), tipoI[randTipoItem].getBonusHP(), tipoI[randTipoItem].getBonusDef(), tipoI[randTipoItem].getBonusAtk(),tipoI[randTipoItem].getId());
					tesouros[1].setIoO(1);
					tesouros[1].getObj().setPropriedade("NomeItem", tipoI[randTipoItem].getNome());

					if (tesouros[1].getObj().getPropriedade("NomeItem") == "Cristal") {
						tesouros[1].getObj().setPropriedade("Descricao", "Este item dá +3 pontos de ataque.");
					}
					else if (tesouros[1].getObj().getPropriedade("NomeItem") == "Presa") {
						tesouros[1].getObj().setPropriedade("Descricao", "Este item aumenta em 3 sua vida máxima.");
					}
					else if (tesouros[1].getObj().getPropriedade("NomeItem") == "Pedra") {
						tesouros[1].getObj().setPropriedade("Descricao", "Este item dá +3 pontos de defesa.");
					}
					else if (tesouros[1].getObj().getPropriedade("NomeItem") == "Pergaminho") {
						tesouros[1].getObj().setPropriedade("Descricao", "Este item aumenta em 1 o ataque, vida máxima e defesa.");
					}


				}
				else {
					int gold = uniRandEntre(1, 6) * 1000;
					tesouros[1].setGold(gold);
				}
				do {
					posX = uniRandEntre(0, 31);
					posY = uniRandEntre(0, 23);
				} while (!mapa2.tileECaminhavel(posX, posY) || mapa2.existeObjetoNaPos(posX, posY) || mapa2.existeObjetoNaPos(posX + 1, posY + 1) || mapa2.existeObjetoNaPos(posX + 2, posY + 2));

				tesouros[1].setSprite("bauFechado");
				tesouros[1].setObj(mapa2.getCamadaDeObjetos("Objetos")->getObjeto("tesouro2"));
				tesouros[1].setPos(posX, posY);
				mapa2.getCamadaDeObjetos("Objetos")->getObjeto("tesouro2")->setVisivel(true);
			}


		}
	}
	else if (randMapa == 3) {

		if (tesourosNaSala > 0) {

			sortear = uniRandEntre(0, 100);
			if (sortear < 21) {
				randTipoItem = uniRandEntre(0, qtdItens - 1);
				tesouros[0].inicializar(tipoI[randTipoItem].getNome(), tipoI[randTipoItem].getBonusHP(), tipoI[randTipoItem].getBonusDef(), tipoI[randTipoItem].getBonusAtk(), tipoI[randTipoItem].getId());
				tesouros[0].setIoO(1);
				tesouros[0].getObj().setPropriedade("NomeItem", tipoI[randTipoItem].getNome());

				if (tesouros[0].getObj().getPropriedade("NomeItem") == "Cristal") {
					tesouros[0].getObj().setPropriedade("Descricao", "Este item dá +3 pontos de ataque.");
				}
				else if (tesouros[0].getObj().getPropriedade("NomeItem") == "Presa") {
					tesouros[0].getObj().setPropriedade("Descricao", "Este item aumenta em 3 sua vida máxima.");
				}
				else if (tesouros[0].getObj().getPropriedade("NomeItem") == "Pedra") {
					tesouros[0].getObj().setPropriedade("Descricao", "Este item dá +3 pontos de defesa.");
				}
				else if (tesouros[0].getObj().getPropriedade("NomeItem") == "Pergaminho") {
					tesouros[0].getObj().setPropriedade("Descricao", "Este item aumenta em 1 o ataque, vida máxima e defesa.");
				}


			}
			else {
				int gold = uniRandEntre(1, 6) * 1000;
				tesouros[0].setGold(gold);
			}
			do {
				posX = uniRandEntre(0, 31);
				posY = uniRandEntre(0, 23);
			} while (!mapa3.tileECaminhavel(posX, posY) || mapa3.existeObjetoNaPos(posX, posY) || mapa3.existeObjetoNaPos(posX + 1, posY + 1) || mapa3.existeObjetoNaPos(posX + 2, posY + 2));


			tesouros[0].setSprite("bauFechado");
			tesouros[0].setObj(mapa3.getCamadaDeObjetos("Objetos")->getObjeto("tesouro1"));
			tesouros[0].setPos(posX, posY);
			mapa3.getCamadaDeObjetos("Objetos")->getObjeto("tesouro1")->setVisivel(true);

			if (tesourosNaSala > 1) {

				sortear = uniRandEntre(0, 100);
				if (sortear < 21) {
					randTipoItem = uniRandEntre(0, qtdItens - 1);
					tesouros[1].inicializar(tipoI[randTipoItem].getNome(), tipoI[randTipoItem].getBonusHP(), tipoI[randTipoItem].getBonusDef(), tipoI[randTipoItem].getBonusAtk(), tipoI[randTipoItem].getId());
					tesouros[1].setIoO(1);
					tesouros[1].getObj().setPropriedade("NomeItem", tipoI[randTipoItem].getNome());

					if (tesouros[1].getObj().getPropriedade("NomeItem") == "Cristal") {
						tesouros[1].getObj().setPropriedade("Descricao", "Este item dá +3 pontos de ataque.");
					}
					else if (tesouros[1].getObj().getPropriedade("NomeItem") == "Presa") {
						tesouros[1].getObj().setPropriedade("Descricao", "Este item aumenta em 3 sua vida máxima.");
					}
					else if (tesouros[1].getObj().getPropriedade("NomeItem") == "Pedra") {
						tesouros[1].getObj().setPropriedade("Descricao", "Este item dá +3 pontos de defesa.");
					}
					else if (tesouros[1].getObj().getPropriedade("NomeItem") == "Pergaminho") {
						tesouros[1].getObj().setPropriedade("Descricao", "Este item aumenta em 1 o ataque, vida máxima e defesa.");
					}


				}
				else {
					int gold = uniRandEntre(1, 6) * 1000;
					tesouros[1].setGold(gold);
				}
				do {
					posX = uniRandEntre(0, 31);
					posY = uniRandEntre(0, 23);
				} while (!mapa3.tileECaminhavel(posX, posY) || mapa3.existeObjetoNaPos(posX, posY) || mapa3.existeObjetoNaPos(posX + 1, posY + 1) || mapa3.existeObjetoNaPos(posX + 2, posY + 2));

				tesouros[1].setSprite("bauFechado");
				tesouros[1].setObj(mapa3.getCamadaDeObjetos("Objetos")->getObjeto("tesouro2"));
				tesouros[1].setPos(posX, posY);
				mapa3.getCamadaDeObjetos("Objetos")->getObjeto("tesouro2")->setVisivel(true);
			}


		}
	}
	else if (randMapa == 4) {

		if (tesourosNaSala > 0) {

			sortear = uniRandEntre(0, 100);
			if (sortear < 21) {
				randTipoItem = uniRandEntre(0, qtdItens - 1);
				tesouros[0].inicializar(tipoI[randTipoItem].getNome(), tipoI[randTipoItem].getBonusHP(), tipoI[randTipoItem].getBonusDef(), tipoI[randTipoItem].getBonusAtk(), tipoI[randTipoItem].getId());
				tesouros[0].setIoO(1);
				tesouros[0].getObj().setPropriedade("NomeItem", tipoI[randTipoItem].getNome());

				if (tesouros[0].getObj().getPropriedade("NomeItem") == "Cristal") {
					tesouros[0].getObj().setPropriedade("Descricao", "Este item dá +3 pontos de ataque.");
				}
				else if (tesouros[0].getObj().getPropriedade("NomeItem") == "Presa") {
					tesouros[0].getObj().setPropriedade("Descricao", "Este item aumenta em 3 sua vida máxima.");
				}
				else if (tesouros[0].getObj().getPropriedade("NomeItem") == "Pedra") {
					tesouros[0].getObj().setPropriedade("Descricao", "Este item dá +3 pontos de defesa.");
				}
				else if (tesouros[0].getObj().getPropriedade("NomeItem") == "Pergaminho") {
					tesouros[0].getObj().setPropriedade("Descricao", "Este item aumenta em 1 o ataque, vida máxima e defesa.");
				}


			}
			else {
				int gold = uniRandEntre(1, 6) * 1000;
				tesouros[0].setGold(gold);
			}
			do {
				posX = uniRandEntre(0, 31);
				posY = uniRandEntre(0, 23);
			} while (!mapa4.tileECaminhavel(posX, posY) || mapa4.existeObjetoNaPos(posX, posY) || mapa4.existeObjetoNaPos(posX + 1, posY + 1) || mapa4.existeObjetoNaPos(posX + 2, posY + 2));


			tesouros[0].setSprite("bauFechado");
			tesouros[0].setObj(mapa4.getCamadaDeObjetos("Objetos")->getObjeto("tesouro1"));
			tesouros[0].setPos(posX, posY);
			mapa4.getCamadaDeObjetos("Objetos")->getObjeto("tesouro1")->setVisivel(true);

			if (tesourosNaSala > 1) {

				sortear = uniRandEntre(0, 100);
				if (sortear < 21) {
					randTipoItem = uniRandEntre(0, qtdItens - 1);
					tesouros[1].inicializar(tipoI[randTipoItem].getNome(), tipoI[randTipoItem].getBonusHP(), tipoI[randTipoItem].getBonusDef(), tipoI[randTipoItem].getBonusAtk(), tipoI[randTipoItem].getId());
					tesouros[1].setIoO(1);
					tesouros[1].getObj().setPropriedade("NomeItem", tipoI[randTipoItem].getNome());

					if (tesouros[1].getObj().getPropriedade("NomeItem") == "Cristal") {
						tesouros[1].getObj().setPropriedade("Descricao", "Este item dá +3 pontos de ataque.");
					}
					else if (tesouros[1].getObj().getPropriedade("NomeItem") == "Presa") {
						tesouros[1].getObj().setPropriedade("Descricao", "Este item aumenta em 3 sua vida máxima.");
					}
					else if (tesouros[1].getObj().getPropriedade("NomeItem") == "Pedra") {
						tesouros[1].getObj().setPropriedade("Descricao", "Este item dá +3 pontos de defesa.");
					}
					else if (tesouros[1].getObj().getPropriedade("NomeItem") == "Pergaminho") {
						tesouros[1].getObj().setPropriedade("Descricao", "Este item aumenta em 1 o ataque, vida máxima e defesa.");
					}


				}
				else {
					int gold = uniRandEntre(1, 6) * 1000;
					tesouros[1].setGold(gold);
				}
				do {
					posX = uniRandEntre(0, 31);
					posY = uniRandEntre(0, 23);
				} while (!mapa4.tileECaminhavel(posX, posY) || mapa4.existeObjetoNaPos(posX, posY) || mapa4.existeObjetoNaPos(posX + 1, posY + 1) || mapa4.existeObjetoNaPos(posX + 2, posY + 2));

				tesouros[1].setSprite("bauFechado");
				tesouros[1].setObj(mapa4.getCamadaDeObjetos("Objetos")->getObjeto("tesouro2"));
				tesouros[1].setPos(posX, posY);
				mapa4.getCamadaDeObjetos("Objetos")->getObjeto("tesouro2")->setVisivel(true);
			}


		}
	}
	else if (randMapa == 5) {

		if (tesourosNaSala > 0) {

			sortear = uniRandEntre(0, 100);
			if (sortear < 21) {
				randTipoItem = uniRandEntre(0, qtdItens - 1);
				tesouros[0].inicializar(tipoI[randTipoItem].getNome(), tipoI[randTipoItem].getBonusHP(), tipoI[randTipoItem].getBonusDef(), tipoI[randTipoItem].getBonusAtk(), tipoI[randTipoItem].getId());
				tesouros[0].setIoO(1);
				tesouros[0].getObj().setPropriedade("NomeItem", tipoI[randTipoItem].getNome());

				if (tesouros[0].getObj().getPropriedade("NomeItem") == "Cristal") {
					tesouros[0].getObj().setPropriedade("Descricao", "Este item dá +3 pontos de ataque.");
				}
				else if (tesouros[0].getObj().getPropriedade("NomeItem") == "Presa") {
					tesouros[0].getObj().setPropriedade("Descricao", "Este item aumenta em 3 sua vida máxima.");
				}
				else if (tesouros[0].getObj().getPropriedade("NomeItem") == "Pedra") {
					tesouros[0].getObj().setPropriedade("Descricao", "Este item dá +3 pontos de defesa.");
				}
				else if (tesouros[0].getObj().getPropriedade("NomeItem") == "Pergaminho") {
					tesouros[0].getObj().setPropriedade("Descricao", "Este item aumenta em 1 o ataque, vida máxima e defesa.");
				}


			}
			else {
				int gold = uniRandEntre(1, 6) * 1000;
				tesouros[0].setGold(gold);
			}
			do {
				posX = uniRandEntre(0, 31);
				posY = uniRandEntre(0, 23);
			} while (!mapa5.tileECaminhavel(posX, posY) || mapa5.existeObjetoNaPos(posX, posY) || mapa5.existeObjetoNaPos(posX + 1, posY + 1) || mapa5.existeObjetoNaPos(posX + 2, posY + 2));


			tesouros[0].setSprite("bauFechado");
			tesouros[0].setObj(mapa5.getCamadaDeObjetos("Objetos")->getObjeto("tesouro1"));
			tesouros[0].setPos(posX, posY);
			mapa5.getCamadaDeObjetos("Objetos")->getObjeto("tesouro1")->setVisivel(true);

			if (tesourosNaSala > 1) {

				sortear = uniRandEntre(0, 100);
				if (sortear < 21) {
					randTipoItem = uniRandEntre(0, qtdItens - 1);
					tesouros[1].inicializar(tipoI[randTipoItem].getNome(), tipoI[randTipoItem].getBonusHP(), tipoI[randTipoItem].getBonusDef(), tipoI[randTipoItem].getBonusAtk(), tipoI[randTipoItem].getId());
					tesouros[1].setIoO(1);
					tesouros[1].getObj().setPropriedade("NomeItem", tipoI[randTipoItem].getNome());

					if (tesouros[1].getObj().getPropriedade("NomeItem") == "Cristal") {
						tesouros[1].getObj().setPropriedade("Descricao", "Este item dá +3 pontos de ataque.");
					}
					else if (tesouros[1].getObj().getPropriedade("NomeItem") == "Presa") {
						tesouros[1].getObj().setPropriedade("Descricao", "Este item aumenta em 3 sua vida máxima.");
					}
					else if (tesouros[1].getObj().getPropriedade("NomeItem") == "Pedra") {
						tesouros[1].getObj().setPropriedade("Descricao", "Este item dá +3 pontos de defesa.");
					}
					else if (tesouros[1].getObj().getPropriedade("NomeItem") == "Pergaminho") {
						tesouros[1].getObj().setPropriedade("Descricao", "Este item aumenta em 1 o ataque, vida máxima e defesa.");
					}


				}
				else {
					int gold = uniRandEntre(1, 6) * 1000;
					tesouros[1].setGold(gold);
				}
				do {
					posX = uniRandEntre(0, 31);
					posY = uniRandEntre(0, 23);
				} while (!mapa5.tileECaminhavel(posX, posY) || mapa5.existeObjetoNaPos(posX, posY) || mapa5.existeObjetoNaPos(posX + 1, posY + 1) || mapa5.existeObjetoNaPos(posX + 2, posY + 2));

				tesouros[1].setSprite("bauFechado");
				tesouros[1].setObj(mapa5.getCamadaDeObjetos("Objetos")->getObjeto("tesouro2"));
				tesouros[1].setPos(posX, posY);
				mapa5.getCamadaDeObjetos("Objetos")->getObjeto("tesouro2")->setVisivel(true);
			}


		}
	}
	else if (randMapa == 6) {

		if (tesourosNaSala > 0) {

			sortear = uniRandEntre(0, 100);
			if (sortear < 21) {
				randTipoItem = uniRandEntre(0, qtdItens - 1);
				tesouros[0].inicializar(tipoI[randTipoItem].getNome(), tipoI[randTipoItem].getBonusHP(), tipoI[randTipoItem].getBonusDef(), tipoI[randTipoItem].getBonusAtk(), tipoI[randTipoItem].getId());
				tesouros[0].setIoO(1);
				tesouros[0].getObj().setPropriedade("NomeItem", tipoI[randTipoItem].getNome());

				if (tesouros[0].getObj().getPropriedade("NomeItem") == "Cristal") {
					tesouros[0].getObj().setPropriedade("Descricao", "Este item dá +3 pontos de ataque.");
				}
				else if (tesouros[0].getObj().getPropriedade("NomeItem") == "Presa") {
					tesouros[0].getObj().setPropriedade("Descricao", "Este item aumenta em 3 sua vida máxima.");
				}
				else if (tesouros[0].getObj().getPropriedade("NomeItem") == "Pedra") {
					tesouros[0].getObj().setPropriedade("Descricao", "Este item dá +3 pontos de defesa.");
				}
				else if (tesouros[0].getObj().getPropriedade("NomeItem") == "Pergaminho") {
					tesouros[0].getObj().setPropriedade("Descricao", "Este item aumenta em 1 o ataque, vida máxima e defesa.");
				}


			}
			else {
				int gold = uniRandEntre(1, 6) * 1000;
				tesouros[0].setGold(gold);
			}
			do {
				posX = uniRandEntre(0, 31);
				posY = uniRandEntre(0, 23);
			} while (!mapa6.tileECaminhavel(posX, posY) || mapa6.existeObjetoNaPos(posX, posY) || mapa6.existeObjetoNaPos(posX + 1, posY + 1) || mapa6.existeObjetoNaPos(posX + 2, posY + 2));


			tesouros[0].setSprite("bauFechado");
			tesouros[0].setObj(mapa6.getCamadaDeObjetos("Objetos")->getObjeto("tesouro1"));
			tesouros[0].setPos(posX, posY);
			mapa6.getCamadaDeObjetos("Objetos")->getObjeto("tesouro1")->setVisivel(true);

			if (tesourosNaSala > 1) {

				sortear = uniRandEntre(0, 100);
				if (sortear < 21) {
					randTipoItem = uniRandEntre(0, qtdItens - 1);
					tesouros[1].inicializar(tipoI[randTipoItem].getNome(), tipoI[randTipoItem].getBonusHP(), tipoI[randTipoItem].getBonusDef(), tipoI[randTipoItem].getBonusAtk(), tipoI[randTipoItem].getId());
					tesouros[1].setIoO(1);
					tesouros[1].getObj().setPropriedade("NomeItem", tipoI[randTipoItem].getNome());

					if (tesouros[1].getObj().getPropriedade("NomeItem") == "Cristal") {
						tesouros[1].getObj().setPropriedade("Descricao", "Este item dá +3 pontos de ataque.");
					}
					else if (tesouros[1].getObj().getPropriedade("NomeItem") == "Presa") {
						tesouros[1].getObj().setPropriedade("Descricao", "Este item aumenta em 3 sua vida máxima.");
					}
					else if (tesouros[1].getObj().getPropriedade("NomeItem") == "Pedra") {
						tesouros[1].getObj().setPropriedade("Descricao", "Este item dá +3 pontos de defesa.");
					}
					else if (tesouros[1].getObj().getPropriedade("NomeItem") == "Pergaminho") {
						tesouros[1].getObj().setPropriedade("Descricao", "Este item aumenta em 1 o ataque, vida máxima e defesa.");
					}


				}
				else {
					int gold = uniRandEntre(1, 6) * 1000;
					tesouros[1].setGold(gold);
				}
				do {
					posX = uniRandEntre(0, 31);
					posY = uniRandEntre(0, 23);
				} while (!mapa6.tileECaminhavel(posX, posY) || mapa6.existeObjetoNaPos(posX, posY) || mapa6.existeObjetoNaPos(posX + 1, posY + 1) || mapa6.existeObjetoNaPos(posX + 2, posY + 2));

				tesouros[1].setSprite("bauFechado");
				tesouros[1].setObj(mapa6.getCamadaDeObjetos("Objetos")->getObjeto("tesouro2"));
				tesouros[1].setPos(posX, posY);
				mapa6.getCamadaDeObjetos("Objetos")->getObjeto("tesouro2")->setVisivel(true);
			}


		}
	}
}

void Jogo::testarColisao()
{
	if (randMapa == 1) {
		time(&end);

		if (mapa.getCamadaDeObjetos("Monstros")->existeObjetoDoTipoNaPos("Monstro1", playerX, playerY)) {

			if (!mAtacou) {

				newHP = monstro[1].getAtk() - playerDef;
				newHP *= -1;
				if (mage->isSelected()) {
					if (newHP > 0)
						mage->setMoreHP(newHP);

					mage->setUseS(true);
					if (mage->getAtacou()) {
						int mHP = mage->getAtk() - monstro[1].getDef();
						mHP *= -1;
						monstro[1].setMoreHP(mHP);
						if (monstro[1].getHP() < 0) {
							monstro[1].getObjeto().setPos(-10, -10);
						}
					}
				}

				else if (thief->isSelected()) {
					if (newHP > 0)
						thief->setMoreHP(newHP);
					thief->setUseS(true);
					if (thief->getAtacou()) {
						int mHP = thief->getAtk() - monstro[1].getDef();
						mHP *= -1;
						monstro[1].setMoreHP(mHP);
						if (monstro[1].getHP() < 0) {
							monstro[1].getObjeto().setPos(-10, -10);
						}
					}
				}
				else if (warrior->isSelected()) {
					if (newHP > 0)
						warrior->setMoreHP(newHP);
					warrior->setUseS(true);
					if (warrior->getAtacou()) {
						int mHP = warrior->getAtk() - monstro[1].getDef();
						mHP *= -1;
						monstro[1].setMoreHP(mHP);
						if (monstro[1].getHP() < 0) {
							monstro[1].getObjeto().setPos(-10, -10);
						}
					}
				}

				time(&start);
				mAtacou;
			}
			else {
				tempo = difftime(end, start);
				if (tempo >= 1) {
					!mAtacou;
				}
			}
		}

		else if (mapa.getCamadaDeObjetos("Monstros")->existeObjetoDoTipoNaPos("Monstro2", playerX, playerY)) {

			if (!mAtacou) {

				newHP = monstro[2].getAtk() - playerDef;
				newHP *= -1;
				if (mage->isSelected()) {
					if (newHP > 0)
						mage->setMoreHP(newHP);

					mage->setUseS(true);
					if (mage->getAtacou()) {
						int mHP = mage->getAtk() - monstro[2].getDef();
						mHP *= -1;
						monstro[2].setMoreHP(mHP);
						if (monstro[2].getHP() < 0) {
							monstro[2].getObjeto().setPos(-10, -10);
						}
					}
				}

				else if (thief->isSelected()) {
					if (newHP > 0)
						thief->setMoreHP(newHP);
					thief->setUseS(true);
					if (thief->getAtacou()) {
						int mHP = thief->getAtk() - monstro[2].getDef();
						mHP *= -1;
						monstro[2].setMoreHP(mHP);
						if (monstro[2].getHP() < 0) {
							monstro[2].getObjeto().setPos(-10, -10);
						}
					}
				}
				else if (warrior->isSelected()) {
					if (newHP > 0)
						warrior->setMoreHP(newHP);
					warrior->setUseS(true);
					if (warrior->getAtacou()) {
						int mHP = warrior->getAtk() - monstro[2].getDef();
						mHP *= -1;
						monstro[2].setMoreHP(mHP);
						if (monstro[2].getHP() < 0) {
							monstro[2].getObjeto().setPos(-10, -10);
						}
					}
				}

				time(&start);
				mAtacou;
			}
			else {
				tempo = difftime(end, start);
				if (tempo >= 1) {
					!mAtacou;
				}
			}
		}

		else if (mapa.getCamadaDeObjetos("Monstros")->existeObjetoDoTipoNaPos("Monstro3", playerX, playerY)) {

			if (!mAtacou) {

				newHP = monstro[3].getAtk() - playerDef;
				newHP *= -1;
				if (mage->isSelected()) {
					if (newHP > 0)
						mage->setMoreHP(newHP);

					mage->setUseS(true);
					if (mage->getAtacou()) {
						int mHP = mage->getAtk() - monstro[3].getDef();
						mHP *= -1;
						monstro[3].setMoreHP(mHP);
						if (monstro[3].getHP() < 0) {
							monstro[3].getObjeto().setPos(-10, -10);
						}
					}
				}

				else if (thief->isSelected()) {
					if (newHP > 0)
						thief->setMoreHP(newHP);
					thief->setUseS(true);
					if (thief->getAtacou()) {
						int mHP = thief->getAtk() - monstro[3].getDef();
						mHP *= -1;
						monstro[3].setMoreHP(mHP);
						if (monstro[3].getHP() < 0) {
							monstro[3].getObjeto().setPos(-10, -10);
						}
					}
				}
				else if (warrior->isSelected()) {
					if (newHP > 0)
						warrior->setMoreHP(newHP);
					warrior->setUseS(true);
					if (warrior->getAtacou()) {
						int mHP = warrior->getAtk() - monstro[3].getDef();
						mHP *= -1;
						monstro[3].setMoreHP(mHP);
						if (monstro[3].getHP() < 0) {
							monstro[3].getObjeto().setPos(-10, -10);
						}
					}
				}

				time(&start);
				mAtacou;
			}
			else {
				tempo = difftime(end, start);
				if (tempo >= 1) {
					!mAtacou;
				}
			}
		}

		else if (mapa.getCamadaDeObjetos("Monstros")->existeObjetoDoTipoNaPos("Monstro4", playerX, playerY)) {

			if (!mAtacou) {

				newHP = monstro[4].getAtk() - playerDef;
				newHP *= -1;
				if (mage->isSelected()) {
					if (newHP > 0)
						mage->setMoreHP(newHP);

					mage->setUseS(true);
					if (mage->getAtacou()) {
						int mHP = mage->getAtk() - monstro[4].getDef();
						mHP *= -1;
						monstro[4].setMoreHP(mHP);
						if (monstro[4].getHP() < 0) {
							monstro[4].getObjeto().setPos(-10, -10);
						}
					}
				}

				else if (thief->isSelected()) {
					if (newHP > 0)
						thief->setMoreHP(newHP);
					thief->setUseS(true);
					if (thief->getAtacou()) {
						int mHP = thief->getAtk() - monstro[4].getDef();
						mHP *= -1;
						monstro[4].setMoreHP(mHP);
						if (monstro[4].getHP() < 0) {
							monstro[4].getObjeto().setPos(-10, -10);
						}
					}
				}
				else if (warrior->isSelected()) {
					if (newHP > 0)
						warrior->setMoreHP(newHP);
					warrior->setUseS(true);
					if (warrior->getAtacou()) {
						int mHP = warrior->getAtk() - monstro[4].getDef();
						mHP *= -1;
						monstro[4].setMoreHP(mHP);
						if (monstro[4].getHP() < 0) {
							monstro[4].getObjeto().setPos(-10, -10);
						}
					}
				}

				time(&start);
				mAtacou;
			}
			else {
				tempo = difftime(end, start);
				if (tempo >= 1) {
					!mAtacou;
				}
			}
		}

		else if (mapa.getCamadaDeObjetos("Monstros")->existeObjetoDoTipoNaPos("Monstro5", playerX, playerY)) {

			if (!mAtacou) {

				newHP = monstro[5].getAtk() - playerDef;
				newHP *= -1;
				if (mage->isSelected()) {
					if (newHP > 0)
						mage->setMoreHP(newHP);

					mage->setUseS(true);
					if (mage->getAtacou()) {
						int mHP = mage->getAtk() - monstro[5].getDef();
						mHP *= -1;
						monstro[5].setMoreHP(mHP);
						if (monstro[5].getHP() < 0) {
							monstro[5].getObjeto().setPos(-10, -10);
						}
					}
				}

				else if (thief->isSelected()) {
					if (newHP > 0)
						thief->setMoreHP(newHP);
					thief->setUseS(true);
					if (thief->getAtacou()) {
						int mHP = thief->getAtk() - monstro[5].getDef();
						mHP *= -1;
						monstro[5].setMoreHP(mHP);
						if (monstro[5].getHP() < 0) {
							monstro[5].getObjeto().setPos(-10, -10);
						}
					}
				}
				else if (warrior->isSelected()) {
					if (newHP > 0)
						warrior->setMoreHP(newHP);
					warrior->setUseS(true);
					if (warrior->getAtacou()) {
						int mHP = warrior->getAtk() - monstro[5].getDef();
						mHP *= -1;
						monstro[5].setMoreHP(mHP);
						if (monstro[5].getHP() < 0) {
							monstro[5].getObjeto().setPos(-10, -10);
						}
					}
				}

				time(&start);
				mAtacou;
			}
			else {
				tempo = difftime(end, start);
				if (tempo >= 1) {
					!mAtacou;
				}
			}
		}
		else {

			if (mage->isSelected()) {
				mage->setUseS(false);
			}
			else if (thief->isSelected()) {
				thief->setUseS(false);
			}
			else if (warrior->isSelected()) {
				warrior->setUseS(false);
			}
		}

	}

	else if (randMapa == 2) {
		time(&end);

		if (mapa2.getCamadaDeObjetos("Monstros")->existeObjetoDoTipoNaPos("Monstro1", playerX, playerY)) {

			if (!mAtacou) {

				newHP = monstro[1].getAtk() - playerDef;
				newHP *= -1;
				if (mage->isSelected()) {
					if (newHP > 0)
						mage->setMoreHP(newHP);

					mage->setUseS(true);
					if (mage->getAtacou()) {
						int mHP = mage->getAtk() - monstro[1].getDef();
						mHP *= -1;
						monstro[1].setMoreHP(mHP);
						if (monstro[1].getHP() < 0) {
							monstro[1].getObjeto().setPos(-10, -10);
						}
					}
				}

				else if (thief->isSelected()) {
					if (newHP > 0)
						thief->setMoreHP(newHP);
					thief->setUseS(true);
					if (thief->getAtacou()) {
						int mHP = thief->getAtk() - monstro[1].getDef();
						mHP *= -1;
						monstro[1].setMoreHP(mHP);
						if (monstro[1].getHP() < 0) {
							monstro[1].getObjeto().setPos(-10, -10);
						}
					}
				}
				else if (warrior->isSelected()) {
					if (newHP > 0)
						warrior->setMoreHP(newHP);
					warrior->setUseS(true);
					if (warrior->getAtacou()) {
						int mHP = warrior->getAtk() - monstro[1].getDef();
						mHP *= -1;
						monstro[1].setMoreHP(mHP);
						if (monstro[1].getHP() < 0) {
							monstro[1].getObjeto().setPos(-10, -10);
						}
					}
				}

				time(&start);
				mAtacou;
			}
			else {
				tempo = difftime(end, start);
				if (tempo >= 1) {
					!mAtacou;
				}
			}
		}

		else if (mapa2.getCamadaDeObjetos("Monstros")->existeObjetoDoTipoNaPos("Monstro2", playerX, playerY)) {

			if (!mAtacou) {

				newHP = monstro[2].getAtk() - playerDef;
				newHP *= -1;
				if (mage->isSelected()) {
					if (newHP > 0)
						mage->setMoreHP(newHP);

					mage->setUseS(true);
					if (mage->getAtacou()) {
						int mHP = mage->getAtk() - monstro[2].getDef();
						mHP *= -1;
						monstro[2].setMoreHP(mHP);
						if (monstro[2].getHP() < 0) {
							monstro[2].getObjeto().setPos(-10, -10);
						}
					}
				}

				else if (thief->isSelected()) {
					if (newHP > 0)
						thief->setMoreHP(newHP);
					thief->setUseS(true);
					if (thief->getAtacou()) {
						int mHP = thief->getAtk() - monstro[2].getDef();
						mHP *= -1;
						monstro[2].setMoreHP(mHP);
						if (monstro[2].getHP() < 0) {
							monstro[2].getObjeto().setPos(-10, -10);
						}
					}
				}
				else if (warrior->isSelected()) {
					if (newHP > 0)
						warrior->setMoreHP(newHP);
					warrior->setUseS(true);
					if (warrior->getAtacou()) {
						int mHP = warrior->getAtk() - monstro[2].getDef();
						mHP *= -1;
						monstro[2].setMoreHP(mHP);
						if (monstro[2].getHP() < 0) {
							monstro[2].getObjeto().setPos(-10, -10);
						}
					}
				}

				time(&start);
				mAtacou;
			}
			else {
				tempo = difftime(end, start);
				if (tempo >= 1) {
					!mAtacou;
				}
			}
		}

		else if (mapa2.getCamadaDeObjetos("Monstros")->existeObjetoDoTipoNaPos("Monstro3", playerX, playerY)) {

			if (!mAtacou) {

				newHP = monstro[3].getAtk() - playerDef;
				newHP *= -1;
				if (mage->isSelected()) {
					if (newHP > 0)
						mage->setMoreHP(newHP);

					mage->setUseS(true);
					if (mage->getAtacou()) {
						int mHP = mage->getAtk() - monstro[3].getDef();
						mHP *= -1;
						monstro[3].setMoreHP(mHP);
						if (monstro[3].getHP() < 0) {
							monstro[3].getObjeto().setPos(-10, -10);
						}
					}
				}

				else if (thief->isSelected()) {
					if (newHP > 0)
						thief->setMoreHP(newHP);
					thief->setUseS(true);
					if (thief->getAtacou()) {
						int mHP = thief->getAtk() - monstro[3].getDef();
						mHP *= -1;
						monstro[3].setMoreHP(mHP);
						if (monstro[3].getHP() < 0) {
							monstro[3].getObjeto().setPos(-10, -10);
						}
					}
				}
				else if (warrior->isSelected()) {
					if (newHP > 0)
						warrior->setMoreHP(newHP);
					warrior->setUseS(true);
					if (warrior->getAtacou()) {
						int mHP = warrior->getAtk() - monstro[3].getDef();
						mHP *= -1;
						monstro[3].setMoreHP(mHP);
						if (monstro[3].getHP() < 0) {
							monstro[3].getObjeto().setPos(-10, -10);
						}
					}
				}

				time(&start);
				mAtacou;
			}
			else {
				tempo = difftime(end, start);
				if (tempo >= 1) {
					!mAtacou;
				}
			}
		}

		else if (mapa2.getCamadaDeObjetos("Monstros")->existeObjetoDoTipoNaPos("Monstro4", playerX, playerY)) {

			if (!mAtacou) {

				newHP = monstro[4].getAtk() - playerDef;
				newHP *= -1;
				if (mage->isSelected()) {
					if (newHP > 0)
						mage->setMoreHP(newHP);

					mage->setUseS(true);
					if (mage->getAtacou()) {
						int mHP = mage->getAtk() - monstro[4].getDef();
						mHP *= -1;
						monstro[4].setMoreHP(mHP);
						if (monstro[4].getHP() < 0) {
							monstro[4].getObjeto().setPos(-10, -10);
						}
					}
				}

				else if (thief->isSelected()) {
					if (newHP > 0)
						thief->setMoreHP(newHP);
					thief->setUseS(true);
					if (thief->getAtacou()) {
						int mHP = thief->getAtk() - monstro[4].getDef();
						mHP *= -1;
						monstro[4].setMoreHP(mHP);
						if (monstro[4].getHP() < 0) {
							monstro[4].getObjeto().setPos(-10, -10);
						}
					}
				}
				else if (warrior->isSelected()) {
					if (newHP > 0)
						warrior->setMoreHP(newHP);
					warrior->setUseS(true);
					if (warrior->getAtacou()) {
						int mHP = warrior->getAtk() - monstro[4].getDef();
						mHP *= -1;
						monstro[4].setMoreHP(mHP);
						if (monstro[4].getHP() < 0) {
							monstro[4].getObjeto().setPos(-10, -10);
						}
					}
				}

				time(&start);
				mAtacou;
			}
			else {
				tempo = difftime(end, start);
				if (tempo >= 1) {
					!mAtacou;
				}
			}
		}

		else if (mapa2.getCamadaDeObjetos("Monstros")->existeObjetoDoTipoNaPos("Monstro5", playerX, playerY)) {

			if (!mAtacou) {

				newHP = monstro[5].getAtk() - playerDef;
				newHP *= -1;
				if (mage->isSelected()) {
					if (newHP > 0)
						mage->setMoreHP(newHP);

					mage->setUseS(true);
					if (mage->getAtacou()) {
						int mHP = mage->getAtk() - monstro[5].getDef();
						mHP *= -1;
						monstro[5].setMoreHP(mHP);
						if (monstro[5].getHP() < 0) {
							monstro[5].getObjeto().setPos(-10, -10);
						}
					}
				}

				else if (thief->isSelected()) {
					if (newHP > 0)
						thief->setMoreHP(newHP);
					thief->setUseS(true);
					if (thief->getAtacou()) {
						int mHP = thief->getAtk() - monstro[5].getDef();
						mHP *= -1;
						monstro[5].setMoreHP(mHP);
						if (monstro[5].getHP() < 0) {
							monstro[5].getObjeto().setPos(-10, -10);
						}
					}
				}
				else if (warrior->isSelected()) {
					if (newHP > 0)
						warrior->setMoreHP(newHP);
					warrior->setUseS(true);
					if (warrior->getAtacou()) {
						int mHP = warrior->getAtk() - monstro[5].getDef();
						mHP *= -1;
						monstro[5].setMoreHP(mHP);
						if (monstro[5].getHP() < 0) {
							monstro[5].getObjeto().setPos(-10, -10);
						}
					}
				}

				time(&start);
				mAtacou;
			}
			else {
				tempo = difftime(end, start);
				if (tempo >= 1) {
					!mAtacou;
				}
			}
		}
		else {

			if (mage->isSelected()) {
				mage->setUseS(false);
			}
			else if (thief->isSelected()) {
				thief->setUseS(false);
			}
			else if (warrior->isSelected()) {
				warrior->setUseS(false);
			}
		}
	}
		else if (randMapa == 3) {
			time(&end);

			if (mapa3.getCamadaDeObjetos("Monstros")->existeObjetoDoTipoNaPos("Monstro1", playerX, playerY)) {

				if (!mAtacou) {

					newHP = monstro[1].getAtk() - playerDef;
					newHP *= -1;
					if (mage->isSelected()) {
						if (newHP > 0)
							mage->setMoreHP(newHP);

						mage->setUseS(true);
						if (mage->getAtacou()) {
							int mHP = mage->getAtk() - monstro[1].getDef();
							mHP *= -1;
							monstro[1].setMoreHP(mHP);
							if (monstro[1].getHP() < 0) {
								monstro[1].getObjeto().setPos(-10, -10);
							}
						}
					}

					else if (thief->isSelected()) {
						if (newHP > 0)
							thief->setMoreHP(newHP);
						thief->setUseS(true);
						if (thief->getAtacou()) {
							int mHP = thief->getAtk() - monstro[1].getDef();
							mHP *= -1;
							monstro[1].setMoreHP(mHP);
							if (monstro[1].getHP() < 0) {
								monstro[1].getObjeto().setPos(-10, -10);
							}
						}
					}
					else if (warrior->isSelected()) {
						if (newHP > 0)
							warrior->setMoreHP(newHP);
						warrior->setUseS(true);
						if (warrior->getAtacou()) {
							int mHP = warrior->getAtk() - monstro[1].getDef();
							mHP *= -1;
							monstro[1].setMoreHP(mHP);
							if (monstro[1].getHP() < 0) {
								monstro[1].getObjeto().setPos(-10, -10);
							}
						}
					}

					time(&start);
					mAtacou;
				}
				else {
					tempo = difftime(end, start);
					if (tempo >= 1) {
						!mAtacou;
					}
				}
			}

			else if (mapa3.getCamadaDeObjetos("Monstros")->existeObjetoDoTipoNaPos("Monstro2", playerX, playerY)) {

				if (!mAtacou) {

					newHP = monstro[2].getAtk() - playerDef;
					newHP *= -1;
					if (mage->isSelected()) {
						if (newHP > 0)
							mage->setMoreHP(newHP);

						mage->setUseS(true);
						if (mage->getAtacou()) {
							int mHP = mage->getAtk() - monstro[2].getDef();
							mHP *= -1;
							monstro[2].setMoreHP(mHP);
							if (monstro[2].getHP() < 0) {
								monstro[2].getObjeto().setPos(-10, -10);
							}
						}
					}

					else if (thief->isSelected()) {
						if (newHP > 0)
							thief->setMoreHP(newHP);
						thief->setUseS(true);
						if (thief->getAtacou()) {
							int mHP = thief->getAtk() - monstro[2].getDef();
							mHP *= -1;
							monstro[2].setMoreHP(mHP);
							if (monstro[2].getHP() < 0) {
								monstro[2].getObjeto().setPos(-10, -10);
							}
						}
					}
					else if (warrior->isSelected()) {
						if (newHP > 0)
							warrior->setMoreHP(newHP);
						warrior->setUseS(true);
						if (warrior->getAtacou()) {
							int mHP = warrior->getAtk() - monstro[2].getDef();
							mHP *= -1;
							monstro[2].setMoreHP(mHP);
							if (monstro[2].getHP() < 0) {
								monstro[2].getObjeto().setPos(-10, -10);
							}
						}
					}

					time(&start);
					mAtacou;
				}
				else {
					tempo = difftime(end, start);
					if (tempo >= 1) {
						!mAtacou;
					}
				}
			}

			else if (mapa3.getCamadaDeObjetos("Monstros")->existeObjetoDoTipoNaPos("Monstro3", playerX, playerY)) {

				if (!mAtacou) {

					newHP = monstro[3].getAtk() - playerDef;
					newHP *= -1;
					if (mage->isSelected()) {
						if (newHP > 0)
							mage->setMoreHP(newHP);

						mage->setUseS(true);
						if (mage->getAtacou()) {
							int mHP = mage->getAtk() - monstro[3].getDef();
							mHP *= -1;
							monstro[3].setMoreHP(mHP);
							if (monstro[3].getHP() < 0) {
								monstro[3].getObjeto().setPos(-10, -10);
							}
						}
					}

					else if (thief->isSelected()) {
						if (newHP > 0)
							thief->setMoreHP(newHP);
						thief->setUseS(true);
						if (thief->getAtacou()) {
							int mHP = thief->getAtk() - monstro[3].getDef();
							mHP *= -1;
							monstro[3].setMoreHP(mHP);
							if (monstro[3].getHP() < 0) {
								monstro[3].getObjeto().setPos(-10, -10);
							}
						}
					}
					else if (warrior->isSelected()) {
						if (newHP > 0)
							warrior->setMoreHP(newHP);
						warrior->setUseS(true);
						if (warrior->getAtacou()) {
							int mHP = warrior->getAtk() - monstro[3].getDef();
							mHP *= -1;
							monstro[3].setMoreHP(mHP);
							if (monstro[3].getHP() < 0) {
								monstro[3].getObjeto().setPos(-10, -10);
							}
						}
					}

					time(&start);
					mAtacou;
				}
				else {
					tempo = difftime(end, start);
					if (tempo >= 1) {
						!mAtacou;
					}
				}
			}

			else if (mapa3.getCamadaDeObjetos("Monstros")->existeObjetoDoTipoNaPos("Monstro4", playerX, playerY)) {

				if (!mAtacou) {

					newHP = monstro[4].getAtk() - playerDef;
					newHP *= -1;
					if (mage->isSelected()) {
						if (newHP > 0)
							mage->setMoreHP(newHP);

						mage->setUseS(true);
						if (mage->getAtacou()) {
							int mHP = mage->getAtk() - monstro[4].getDef();
							mHP *= -1;
							monstro[4].setMoreHP(mHP);
							if (monstro[4].getHP() < 0) {
								monstro[4].getObjeto().setPos(-10, -10);
							}
						}
					}

					else if (thief->isSelected()) {
						if (newHP > 0)
							thief->setMoreHP(newHP);
						thief->setUseS(true);
						if (thief->getAtacou()) {
							int mHP = thief->getAtk() - monstro[4].getDef();
							mHP *= -1;
							monstro[4].setMoreHP(mHP);
							if (monstro[4].getHP() < 0) {
								monstro[4].getObjeto().setPos(-10, -10);
							}
						}
					}
					else if (warrior->isSelected()) {
						if (newHP > 0)
							warrior->setMoreHP(newHP);
						warrior->setUseS(true);
						if (warrior->getAtacou()) {
							int mHP = warrior->getAtk() - monstro[4].getDef();
							mHP *= -1;
							monstro[4].setMoreHP(mHP);
							if (monstro[4].getHP() < 0) {
								monstro[4].getObjeto().setPos(-10, -10);
							}
						}
					}

					time(&start);
					mAtacou;
				}
				else {
					tempo = difftime(end, start);
					if (tempo >= 1) {
						!mAtacou;
					}
				}
			}

			else if (mapa3.getCamadaDeObjetos("Monstros")->existeObjetoDoTipoNaPos("Monstro5", playerX, playerY)) {

				if (!mAtacou) {

					newHP = monstro[5].getAtk() - playerDef;
					newHP *= -1;
					if (mage->isSelected()) {
						if (newHP > 0)
							mage->setMoreHP(newHP);

						mage->setUseS(true);
						if (mage->getAtacou()) {
							int mHP = mage->getAtk() - monstro[5].getDef();
							mHP *= -1;
							monstro[5].setMoreHP(mHP);
							if (monstro[5].getHP() < 0) {
								monstro[5].getObjeto().setPos(-10, -10);
							}
						}
					}

					else if (thief->isSelected()) {
						if (newHP > 0)
							thief->setMoreHP(newHP);
						thief->setUseS(true);
						if (thief->getAtacou()) {
							int mHP = thief->getAtk() - monstro[5].getDef();
							mHP *= -1;
							monstro[5].setMoreHP(mHP);
							if (monstro[5].getHP() < 0) {
								monstro[5].getObjeto().setPos(-10, -10);
							}
						}
					}
					else if (warrior->isSelected()) {
						if (newHP > 0)
							warrior->setMoreHP(newHP);
						warrior->setUseS(true);
						if (warrior->getAtacou()) {
							int mHP = warrior->getAtk() - monstro[5].getDef();
							mHP *= -1;
							monstro[5].setMoreHP(mHP);
							if (monstro[5].getHP() < 0) {
								monstro[5].getObjeto().setPos(-10, -10);
							}
						}
					}

					time(&start);
					mAtacou;
				}
				else {
					tempo = difftime(end, start);
					if (tempo >= 1) {
						!mAtacou;
					}
				}
			}
			else {

				if (mage->isSelected()) {
					mage->setUseS(false);
				}
				else if (thief->isSelected()) {
					thief->setUseS(false);
				}
				else if (warrior->isSelected()) {
					warrior->setUseS(false);
				}
			}
		}
			else if (randMapa == 4) {
				time(&end);

				if (mapa4.getCamadaDeObjetos("Monstros")->existeObjetoDoTipoNaPos("Monstro1", playerX, playerY)) {

					if (!mAtacou) {

						newHP = monstro[1].getAtk() - playerDef;
						newHP *= -1;
						if (mage->isSelected()) {
							if (newHP > 0)
								mage->setMoreHP(newHP);

							mage->setUseS(true);
							if (mage->getAtacou()) {
								int mHP = mage->getAtk() - monstro[1].getDef();
								mHP *= -1;
								monstro[1].setMoreHP(mHP);
								if (monstro[1].getHP() < 0) {
									monstro[1].getObjeto().setPos(-10, -10);
								}
							}
						}

						else if (thief->isSelected()) {
							if (newHP > 0)
								thief->setMoreHP(newHP);
							thief->setUseS(true);
							if (thief->getAtacou()) {
								int mHP = thief->getAtk() - monstro[1].getDef();
								mHP *= -1;
								monstro[1].setMoreHP(mHP);
								if (monstro[1].getHP() < 0) {
									monstro[1].getObjeto().setPos(-10, -10);
								}
							}
						}
						else if (warrior->isSelected()) {
							if (newHP > 0)
								warrior->setMoreHP(newHP);
							warrior->setUseS(true);
							if (warrior->getAtacou()) {
								int mHP = warrior->getAtk() - monstro[1].getDef();
								mHP *= -1;
								monstro[1].setMoreHP(mHP);
								if (monstro[1].getHP() < 0) {
									monstro[1].getObjeto().setPos(-10, -10);
								}
							}
						}

						time(&start);
						mAtacou;
					}
					else {
						tempo = difftime(end, start);
						if (tempo >= 1) {
							!mAtacou;
						}
					}
				}

				else if (mapa4.getCamadaDeObjetos("Monstros")->existeObjetoDoTipoNaPos("Monstro2", playerX, playerY)) {

					if (!mAtacou) {

						newHP = monstro[2].getAtk() - playerDef;
						newHP *= -1;
						if (mage->isSelected()) {
							if (newHP > 0)
								mage->setMoreHP(newHP);

							mage->setUseS(true);
							if (mage->getAtacou()) {
								int mHP = mage->getAtk() - monstro[2].getDef();
								mHP *= -1;
								monstro[2].setMoreHP(mHP);
								if (monstro[2].getHP() < 0) {
									monstro[2].getObjeto().setPos(-10, -10);
								}
							}
						}

						else if (thief->isSelected()) {
							if (newHP > 0)
								thief->setMoreHP(newHP);
							thief->setUseS(true);
							if (thief->getAtacou()) {
								int mHP = thief->getAtk() - monstro[2].getDef();
								mHP *= -1;
								monstro[2].setMoreHP(mHP);
								if (monstro[2].getHP() < 0) {
									monstro[2].getObjeto().setPos(-10, -10);
								}
							}
						}
						else if (warrior->isSelected()) {
							if (newHP > 0)
								warrior->setMoreHP(newHP);
							warrior->setUseS(true);
							if (warrior->getAtacou()) {
								int mHP = warrior->getAtk() - monstro[2].getDef();
								mHP *= -1;
								monstro[2].setMoreHP(mHP);
								if (monstro[2].getHP() < 0) {
									monstro[2].getObjeto().setPos(-10, -10);
								}
							}
						}

						time(&start);
						mAtacou;
					}
					else {
						tempo = difftime(end, start);
						if (tempo >= 1) {
							!mAtacou;
						}
					}
				}

				else if (mapa4.getCamadaDeObjetos("Monstros")->existeObjetoDoTipoNaPos("Monstro3", playerX, playerY)) {

					if (!mAtacou) {

						newHP = monstro[3].getAtk() - playerDef;
						newHP *= -1;
						if (mage->isSelected()) {
							if (newHP > 0)
								mage->setMoreHP(newHP);

							mage->setUseS(true);
							if (mage->getAtacou()) {
								int mHP = mage->getAtk() - monstro[3].getDef();
								mHP *= -1;
								monstro[3].setMoreHP(mHP);
								if (monstro[3].getHP() < 0) {
									monstro[3].getObjeto().setPos(-10, -10);
								}
							}
						}

						else if (thief->isSelected()) {
							if (newHP > 0)
								thief->setMoreHP(newHP);
							thief->setUseS(true);
							if (thief->getAtacou()) {
								int mHP = thief->getAtk() - monstro[3].getDef();
								mHP *= -1;
								monstro[3].setMoreHP(mHP);
								if (monstro[3].getHP() < 0) {
									monstro[3].getObjeto().setPos(-10, -10);
								}
							}
						}
						else if (warrior->isSelected()) {
							if (newHP > 0)
								warrior->setMoreHP(newHP);
							warrior->setUseS(true);
							if (warrior->getAtacou()) {
								int mHP = warrior->getAtk() - monstro[3].getDef();
								mHP *= -1;
								monstro[3].setMoreHP(mHP);
								if (monstro[3].getHP() < 0) {
									monstro[3].getObjeto().setPos(-10, -10);
								}
							}
						}

						time(&start);
						mAtacou;
					}
					else {
						tempo = difftime(end, start);
						if (tempo >= 1) {
							!mAtacou;
						}
					}
				}

				else if (mapa4.getCamadaDeObjetos("Monstros")->existeObjetoDoTipoNaPos("Monstro4", playerX, playerY)) {

					if (!mAtacou) {

						newHP = monstro[4].getAtk() - playerDef;
						newHP *= -1;
						if (mage->isSelected()) {
							if (newHP > 0)
								mage->setMoreHP(newHP);

							mage->setUseS(true);
							if (mage->getAtacou()) {
								int mHP = mage->getAtk() - monstro[4].getDef();
								mHP *= -1;
								monstro[4].setMoreHP(mHP);
								if (monstro[4].getHP() < 0) {
									monstro[4].getObjeto().setPos(-10, -10);
								}
							}
						}

						else if (thief->isSelected()) {
							if (newHP > 0)
								thief->setMoreHP(newHP);
							thief->setUseS(true);
							if (thief->getAtacou()) {
								int mHP = thief->getAtk() - monstro[4].getDef();
								mHP *= -1;
								monstro[4].setMoreHP(mHP);
								if (monstro[4].getHP() < 0) {
									monstro[4].getObjeto().setPos(-10, -10);
								}
							}
						}
						else if (warrior->isSelected()) {
							if (newHP > 0)
								warrior->setMoreHP(newHP);
							warrior->setUseS(true);
							if (warrior->getAtacou()) {
								int mHP = warrior->getAtk() - monstro[4].getDef();
								mHP *= -1;
								monstro[4].setMoreHP(mHP);
								if (monstro[4].getHP() < 0) {
									monstro[4].getObjeto().setPos(-10, -10);
								}
							}
						}

						time(&start);
						mAtacou;
					}
					else {
						tempo = difftime(end, start);
						if (tempo >= 1) {
							!mAtacou;
						}
					}
				}

				else if (mapa4.getCamadaDeObjetos("Monstros")->existeObjetoDoTipoNaPos("Monstro5", playerX, playerY)) {

					if (!mAtacou) {

						newHP = monstro[5].getAtk() - playerDef;
						newHP *= -1;
						if (mage->isSelected()) {
							if (newHP > 0)
								mage->setMoreHP(newHP);

							mage->setUseS(true);
							if (mage->getAtacou()) {
								int mHP = mage->getAtk() - monstro[5].getDef();
								mHP *= -1;
								monstro[5].setMoreHP(mHP);
								if (monstro[5].getHP() < 0) {
									monstro[5].getObjeto().setPos(-10, -10);
								}
							}
						}

						else if (thief->isSelected()) {
							if (newHP > 0)
								thief->setMoreHP(newHP);
							thief->setUseS(true);
							if (thief->getAtacou()) {
								int mHP = thief->getAtk() - monstro[5].getDef();
								mHP *= -1;
								monstro[5].setMoreHP(mHP);
								if (monstro[5].getHP() < 0) {
									monstro[5].getObjeto().setPos(-10, -10);
								}
							}
						}
						else if (warrior->isSelected()) {
							if (newHP > 0)
								warrior->setMoreHP(newHP);
							warrior->setUseS(true);
							if (warrior->getAtacou()) {
								int mHP = warrior->getAtk() - monstro[5].getDef();
								mHP *= -1;
								monstro[5].setMoreHP(mHP);
								if (monstro[5].getHP() < 0) {
									monstro[5].getObjeto().setPos(-10, -10);
								}
							}
						}

						time(&start);
						mAtacou;
					}
					else {
						tempo = difftime(end, start);
						if (tempo >= 1) {
							!mAtacou;
						}
					}
				}
				else {

					if (mage->isSelected()) {
						mage->setUseS(false);
					}
					else if (thief->isSelected()) {
						thief->setUseS(false);
					}
					else if (warrior->isSelected()) {
						warrior->setUseS(false);
					}
				}
			}
				else if (randMapa == 5) {
					time(&end);

					if (mapa5.getCamadaDeObjetos("Monstros")->existeObjetoDoTipoNaPos("Monstro1", playerX, playerY)) {

						if (!mAtacou) {

							newHP = monstro[1].getAtk() - playerDef;
							newHP *= -1;
							if (mage->isSelected()) {
								if (newHP > 0)
									mage->setMoreHP(newHP);

								mage->setUseS(true);
								if (mage->getAtacou()) {
									int mHP = mage->getAtk() - monstro[1].getDef();
									mHP *= -1;
									monstro[1].setMoreHP(mHP);
									if (monstro[1].getHP() < 0) {
										monstro[1].getObjeto().setPos(-10, -10);
									}
								}
							}

							else if (thief->isSelected()) {
								if (newHP > 0)
									thief->setMoreHP(newHP);
								thief->setUseS(true);
								if (thief->getAtacou()) {
									int mHP = thief->getAtk() - monstro[1].getDef();
									mHP *= -1;
									monstro[1].setMoreHP(mHP);
									if (monstro[1].getHP() < 0) {
										monstro[1].getObjeto().setPos(-10, -10);
									}
								}
							}
							else if (warrior->isSelected()) {
								if (newHP > 0)
									warrior->setMoreHP(newHP);
								warrior->setUseS(true);
								if (warrior->getAtacou()) {
									int mHP = warrior->getAtk() - monstro[1].getDef();
									mHP *= -1;
									monstro[1].setMoreHP(mHP);
									if (monstro[1].getHP() < 0) {
										monstro[1].getObjeto().setPos(-10, -10);
									}
								}
							}

							time(&start);
							mAtacou;
						}
						else {
							tempo = difftime(end, start);
							if (tempo >= 1) {
								!mAtacou;
							}
						}
					}

					else if (mapa5.getCamadaDeObjetos("Monstros")->existeObjetoDoTipoNaPos("Monstro2", playerX, playerY)) {

						if (!mAtacou) {

							newHP = monstro[2].getAtk() - playerDef;
							newHP *= -1;
							if (mage->isSelected()) {
								if (newHP > 0)
									mage->setMoreHP(newHP);

								mage->setUseS(true);
								if (mage->getAtacou()) {
									int mHP = mage->getAtk() - monstro[2].getDef();
									mHP *= -1;
									monstro[2].setMoreHP(mHP);
									if (monstro[2].getHP() < 0) {
										monstro[2].getObjeto().setPos(-10, -10);
									}
								}
							}

							else if (thief->isSelected()) {
								if (newHP > 0)
									thief->setMoreHP(newHP);
								thief->setUseS(true);
								if (thief->getAtacou()) {
									int mHP = thief->getAtk() - monstro[2].getDef();
									mHP *= -1;
									monstro[2].setMoreHP(mHP);
									if (monstro[2].getHP() < 0) {
										monstro[2].getObjeto().setPos(-10, -10);
									}
								}
							}
							else if (warrior->isSelected()) {
								if (newHP > 0)
									warrior->setMoreHP(newHP);
								warrior->setUseS(true);
								if (warrior->getAtacou()) {
									int mHP = warrior->getAtk() - monstro[2].getDef();
									mHP *= -1;
									monstro[2].setMoreHP(mHP);
									if (monstro[2].getHP() < 0) {
										monstro[2].getObjeto().setPos(-10, -10);
									}
								}
							}

							time(&start);
							mAtacou;
						}
						else {
							tempo = difftime(end, start);
							if (tempo >= 1) {
								!mAtacou;
							}
						}
					}

					else if (mapa5.getCamadaDeObjetos("Monstros")->existeObjetoDoTipoNaPos("Monstro3", playerX, playerY)) {

						if (!mAtacou) {

							newHP = monstro[3].getAtk() - playerDef;
							newHP *= -1;
							if (mage->isSelected()) {
								if (newHP > 0)
									mage->setMoreHP(newHP);

								mage->setUseS(true);
								if (mage->getAtacou()) {
									int mHP = mage->getAtk() - monstro[3].getDef();
									mHP *= -1;
									monstro[3].setMoreHP(mHP);
									if (monstro[3].getHP() < 0) {
										monstro[3].getObjeto().setPos(-10, -10);
									}
								}
							}

							else if (thief->isSelected()) {
								if (newHP > 0)
									thief->setMoreHP(newHP);
								thief->setUseS(true);
								if (thief->getAtacou()) {
									int mHP = thief->getAtk() - monstro[3].getDef();
									mHP *= -1;
									monstro[3].setMoreHP(mHP);
									if (monstro[3].getHP() < 0) {
										monstro[3].getObjeto().setPos(-10, -10);
									}
								}
							}
							else if (warrior->isSelected()) {
								if (newHP > 0)
									warrior->setMoreHP(newHP);
								warrior->setUseS(true);
								if (warrior->getAtacou()) {
									int mHP = warrior->getAtk() - monstro[3].getDef();
									mHP *= -1;
									monstro[3].setMoreHP(mHP);
									if (monstro[3].getHP() < 0) {
										monstro[3].getObjeto().setPos(-10, -10);
									}
								}
							}

							time(&start);
							mAtacou;
						}
						else {
							tempo = difftime(end, start);
							if (tempo >= 1) {
								!mAtacou;
							}
						}
					}

					else if (mapa5.getCamadaDeObjetos("Monstros")->existeObjetoDoTipoNaPos("Monstro4", playerX, playerY)) {

						if (!mAtacou) {

							newHP = monstro[4].getAtk() - playerDef;
							newHP *= -1;
							if (mage->isSelected()) {
								if (newHP > 0)
									mage->setMoreHP(newHP);

								mage->setUseS(true);
								if (mage->getAtacou()) {
									int mHP = mage->getAtk() - monstro[4].getDef();
									mHP *= -1;
									monstro[4].setMoreHP(mHP);
									if (monstro[4].getHP() < 0) {
										monstro[4].getObjeto().setPos(-10, -10);
									}
								}
							}

							else if (thief->isSelected()) {
								if (newHP > 0)
									thief->setMoreHP(newHP);
								thief->setUseS(true);
								if (thief->getAtacou()) {
									int mHP = thief->getAtk() - monstro[4].getDef();
									mHP *= -1;
									monstro[4].setMoreHP(mHP);
									if (monstro[4].getHP() < 0) {
										monstro[4].getObjeto().setPos(-10, -10);
									}
								}
							}
							else if (warrior->isSelected()) {
								if (newHP > 0)
									warrior->setMoreHP(newHP);
								warrior->setUseS(true);
								if (warrior->getAtacou()) {
									int mHP = warrior->getAtk() - monstro[4].getDef();
									mHP *= -1;
									monstro[4].setMoreHP(mHP);
									if (monstro[4].getHP() < 0) {
										monstro[4].getObjeto().setPos(-10, -10);
									}
								}
							}

							time(&start);
							mAtacou;
						}
						else {
							tempo = difftime(end, start);
							if (tempo >= 1) {
								!mAtacou;
							}
						}
					}

					else if (mapa5.getCamadaDeObjetos("Monstros")->existeObjetoDoTipoNaPos("Monstro5", playerX, playerY)) {

						if (!mAtacou) {

							newHP = monstro[5].getAtk() - playerDef;
							newHP *= -1;
							if (mage->isSelected()) {
								if (newHP > 0)
									mage->setMoreHP(newHP);

								mage->setUseS(true);
								if (mage->getAtacou()) {
									int mHP = mage->getAtk() - monstro[5].getDef();
									mHP *= -1;
									monstro[5].setMoreHP(mHP);
									if (monstro[5].getHP() < 0) {
										monstro[5].getObjeto().setPos(-10, -10);
									}
								}
							}

							else if (thief->isSelected()) {
								if (newHP > 0)
									thief->setMoreHP(newHP);
								thief->setUseS(true);
								if (thief->getAtacou()) {
									int mHP = thief->getAtk() - monstro[5].getDef();
									mHP *= -1;
									monstro[5].setMoreHP(mHP);
									if (monstro[5].getHP() < 0) {
										monstro[5].getObjeto().setPos(-10, -10);
									}
								}
							}
							else if (warrior->isSelected()) {
								if (newHP > 0)
									warrior->setMoreHP(newHP);
								warrior->setUseS(true);
								if (warrior->getAtacou()) {
									int mHP = warrior->getAtk() - monstro[5].getDef();
									mHP *= -1;
									monstro[5].setMoreHP(mHP);
									if (monstro[5].getHP() < 0) {
										monstro[5].getObjeto().setPos(-10, -10);
									}
								}
							}

							time(&start);
							mAtacou;
						}
						else {
							tempo = difftime(end, start);
							if (tempo >= 1) {
								!mAtacou;
							}
						}
					}
					else {

						if (mage->isSelected()) {
							mage->setUseS(false);
						}
						else if (thief->isSelected()) {
							thief->setUseS(false);
						}
						else if (warrior->isSelected()) {
							warrior->setUseS(false);
						}
					}
				}
					else if (randMapa == 6) {
						time(&end);

						if (mapa6.getCamadaDeObjetos("Monstros")->existeObjetoDoTipoNaPos("Monstro1", playerX, playerY)) {

							if (!mAtacou) {

								newHP = monstro[1].getAtk() - playerDef;
								newHP *= -1;
								if (mage->isSelected()) {
									if (newHP > 0)
										mage->setMoreHP(newHP);

									mage->setUseS(true);
									if (mage->getAtacou()) {
										int mHP = mage->getAtk() - monstro[1].getDef();
										mHP *= -1;
										monstro[1].setMoreHP(mHP);
										if (monstro[1].getHP() < 0) {
											monstro[1].getObjeto().setPos(-10, -10);
										}
									}
								}

								else if (thief->isSelected()) {
									if (newHP > 0)
										thief->setMoreHP(newHP);
									thief->setUseS(true);
									if (thief->getAtacou()) {
										int mHP = thief->getAtk() - monstro[1].getDef();
										mHP *= -1;
										monstro[1].setMoreHP(mHP);
										if (monstro[1].getHP() < 0) {
											monstro[1].getObjeto().setPos(-10, -10);
										}
									}
								}
								else if (warrior->isSelected()) {
									if (newHP > 0)
										warrior->setMoreHP(newHP);
									warrior->setUseS(true);
									if (warrior->getAtacou()) {
										int mHP = warrior->getAtk() - monstro[1].getDef();
										mHP *= -1;
										monstro[1].setMoreHP(mHP);
										if (monstro[1].getHP() < 0) {
											monstro[1].getObjeto().setPos(-10, -10);
										}
									}
								}

								time(&start);
								mAtacou;
							}
							else {
								tempo = difftime(end, start);
								if (tempo >= 1) {
									!mAtacou;
								}
							}
						}

						else if (mapa6.getCamadaDeObjetos("Monstros")->existeObjetoDoTipoNaPos("Monstro2", playerX, playerY)) {

							if (!mAtacou) {

								newHP = monstro[2].getAtk() - playerDef;
								newHP *= -1;
								if (mage->isSelected()) {
									if (newHP > 0)
										mage->setMoreHP(newHP);

									mage->setUseS(true);
									if (mage->getAtacou()) {
										int mHP = mage->getAtk() - monstro[2].getDef();
										mHP *= -1;
										monstro[2].setMoreHP(mHP);
										if (monstro[2].getHP() < 0) {
											monstro[2].getObjeto().setPos(-10, -10);
										}
									}
								}

								else if (thief->isSelected()) {
									if (newHP > 0)
										thief->setMoreHP(newHP);
									thief->setUseS(true);
									if (thief->getAtacou()) {
										int mHP = thief->getAtk() - monstro[2].getDef();
										mHP *= -1;
										monstro[2].setMoreHP(mHP);
										if (monstro[2].getHP() < 0) {
											monstro[2].getObjeto().setPos(-10, -10);
										}
									}
								}
								else if (warrior->isSelected()) {
									if (newHP > 0)
										warrior->setMoreHP(newHP);
									warrior->setUseS(true);
									if (warrior->getAtacou()) {
										int mHP = warrior->getAtk() - monstro[2].getDef();
										mHP *= -1;
										monstro[2].setMoreHP(mHP);
										if (monstro[2].getHP() < 0) {
											monstro[2].getObjeto().setPos(-10, -10);
										}
									}
								}

								time(&start);
								mAtacou;
							}
							else {
								tempo = difftime(end, start);
								if (tempo >= 1) {
									!mAtacou;
								}
							}
						}

						else if (mapa6.getCamadaDeObjetos("Monstros")->existeObjetoDoTipoNaPos("Monstro3", playerX, playerY)) {

							if (!mAtacou) {

								newHP = monstro[3].getAtk() - playerDef;
								newHP *= -1;
								if (mage->isSelected()) {
									if (newHP > 0)
										mage->setMoreHP(newHP);

									mage->setUseS(true);
									if (mage->getAtacou()) {
										int mHP = mage->getAtk() - monstro[3].getDef();
										mHP *= -1;
										monstro[3].setMoreHP(mHP);
										if (monstro[3].getHP() < 0) {
											monstro[3].getObjeto().setPos(-10, -10);
										}
									}
								}

								else if (thief->isSelected()) {
									if (newHP > 0)
										thief->setMoreHP(newHP);
									thief->setUseS(true);
									if (thief->getAtacou()) {
										int mHP = thief->getAtk() - monstro[3].getDef();
										mHP *= -1;
										monstro[3].setMoreHP(mHP);
										if (monstro[3].getHP() < 0) {
											monstro[3].getObjeto().setPos(-10, -10);
										}
									}
								}
								else if (warrior->isSelected()) {
									if (newHP > 0)
										warrior->setMoreHP(newHP);
									warrior->setUseS(true);
									if (warrior->getAtacou()) {
										int mHP = warrior->getAtk() - monstro[3].getDef();
										mHP *= -1;
										monstro[3].setMoreHP(mHP);
										if (monstro[3].getHP() < 0) {
											monstro[3].getObjeto().setPos(-10, -10);
										}
									}
								}

								time(&start);
								mAtacou;
							}
							else {
								tempo = difftime(end, start);
								if (tempo >= 1) {
									!mAtacou;
								}
							}
						}

						else if (mapa6.getCamadaDeObjetos("Monstros")->existeObjetoDoTipoNaPos("Monstro4", playerX, playerY)) {

							if (!mAtacou) {

								newHP = monstro[4].getAtk() - playerDef;
								newHP *= -1;
								if (mage->isSelected()) {
									if (newHP > 0)
										mage->setMoreHP(newHP);

									mage->setUseS(true);
									if (mage->getAtacou()) {
										int mHP = mage->getAtk() - monstro[4].getDef();
										mHP *= -1;
										monstro[4].setMoreHP(mHP);
										if (monstro[4].getHP() < 0) {
											monstro[4].getObjeto().setPos(-10, -10);
										}
									}
								}

								else if (thief->isSelected()) {
									if (newHP > 0)
										thief->setMoreHP(newHP);
									thief->setUseS(true);
									if (thief->getAtacou()) {
										int mHP = thief->getAtk() - monstro[4].getDef();
										mHP *= -1;
										monstro[4].setMoreHP(mHP);
										if (monstro[4].getHP() < 0) {
											monstro[4].getObjeto().setPos(-10, -10);
										}
									}
								}
								else if (warrior->isSelected()) {
									if (newHP > 0)
										warrior->setMoreHP(newHP);
									warrior->setUseS(true);
									if (warrior->getAtacou()) {
										int mHP = warrior->getAtk() - monstro[4].getDef();
										mHP *= -1;
										monstro[4].setMoreHP(mHP);
										if (monstro[4].getHP() < 0) {
											monstro[4].getObjeto().setPos(-10, -10);
										}
									}
								}

								time(&start);
								mAtacou;
							}
							else {
								tempo = difftime(end, start);
								if (tempo >= 1) {
									!mAtacou;
								}
							}
						}

						else if (mapa6.getCamadaDeObjetos("Monstros")->existeObjetoDoTipoNaPos("Monstro5", playerX, playerY)) {

							if (!mAtacou) {

								newHP = monstro[5].getAtk() - playerDef;
								newHP *= -1;
								if (mage->isSelected()) {
									if (newHP > 0)
										mage->setMoreHP(newHP);

									mage->setUseS(true);
									if (mage->getAtacou()) {
										int mHP = mage->getAtk() - monstro[5].getDef();
										mHP *= -1;
										monstro[5].setMoreHP(mHP);
										if (monstro[5].getHP() < 0) {
											monstro[5].getObjeto().setPos(-10, -10);
										}
									}
								}

								else if (thief->isSelected()) {
									if (newHP > 0)
										thief->setMoreHP(newHP);
									thief->setUseS(true);
									if (thief->getAtacou()) {
										int mHP = thief->getAtk() - monstro[5].getDef();
										mHP *= -1;
										monstro[5].setMoreHP(mHP);
										if (monstro[5].getHP() < 0) {
											monstro[5].getObjeto().setPos(-10, -10);
										}
									}
								}
								else if (warrior->isSelected()) {
									if (newHP > 0)
										warrior->setMoreHP(newHP);
									warrior->setUseS(true);
									if (warrior->getAtacou()) {
										int mHP = warrior->getAtk() - monstro[5].getDef();
										mHP *= -1;
										monstro[5].setMoreHP(mHP);
										if (monstro[5].getHP() < 0) {
											monstro[5].getObjeto().setPos(-10, -10);
										}
									}
								}

								time(&start);
								mAtacou;
							}
							else {
								tempo = difftime(end, start);
								if (tempo >= 1) {
									!mAtacou;
								}
							}
						}
						else {

							if (mage->isSelected()) {
								mage->setUseS(false);
							}
							else if (thief->isSelected()) {
								thief->setUseS(false);
							}
							else if (warrior->isSelected()) {
								warrior->setUseS(false);
							}
						}
					}
}

void Jogo::testarColisaoBaus()
{
	if (randMapa == 1) {
		if (mapa.existeObjetoDoTipoNaPos("tesouro1", playerX, playerY)) {

			if (!tesouros[0].getItem().getPossui() && tesouros[0].getIoO() == 1) {
					tesouros[0].getItem().setPossui(true);
					mochila.addItem(tesouros[0].getItem());
					tesouros[0].getObj().setSprite(&bauAberto);
			}
				else if (tesouros[0].getIoO() == 0) {
					if (mage->isSelected()) {
						int gold = tesouros[0].getGold();
						mage->setMoreGold(gold);
					}
					else if (thief->isSelected()) {
						int gold = tesouros[0].getGold();
						thief->setMoreGold(gold);
					}
					else if (warrior->isSelected()) {
						int gold = tesouros[0].getGold();
						warrior->setMoreGold(gold);
					}
					tesouros[0].getObj().setSprite(&bauAberto);


				}
		}
			
		

		if (mapa.existeObjetoDoTipoNaPos("tesouro2", playerX, playerY)) {

			if (!tesouros[1].getItem().getPossui() && tesouros[1].getIoO() == 1) {
				tesouros[1].getItem().setPossui(true);
				mochila.addItem(tesouros[1].getItem());
				tesouros[1].getObj().setSprite(&bauAberto);

			}
			else if (tesouros[1].getIoO() == 0) {
				if (mage->isSelected()) {
					int gold = tesouros[1].getGold();
					mage->setMoreGold(gold);
				}
				else if (thief->isSelected()) {
					int gold = tesouros[1].getGold();
					thief->setMoreGold(gold);
				}
				else if (warrior->isSelected()) {
					int gold = tesouros[1].getGold();
					warrior->setMoreGold(gold);
				}
				tesouros[1].getObj().setSprite(&bauAberto);


			}
		}
	}
	else if (randMapa == 2) {
		if (mapa2.existeObjetoDoTipoNaPos("tesouro1", playerX, playerY)) {

			if (!tesouros[0].getItem().getPossui() && tesouros[0].getIoO() == 1) {
				tesouros[0].getItem().setPossui(true);
				mochila.addItem(tesouros[0].getItem());
				tesouros[0].getObj().setSprite(&bauAberto);
			}
			else if (tesouros[0].getIoO() == 0) {
				if (mage->isSelected()) {
					int gold = tesouros[0].getGold();
					mage->setMoreGold(gold);
				}
				else if (thief->isSelected()) {
					int gold = tesouros[0].getGold();
					thief->setMoreGold(gold);
				}
				else if (warrior->isSelected()) {
					int gold = tesouros[0].getGold();
					warrior->setMoreGold(gold);
				}
				tesouros[0].getObj().setSprite(&bauAberto);


			}
		}



		if (mapa2.existeObjetoDoTipoNaPos("tesouro2", playerX, playerY)) {

			if (!tesouros[1].getItem().getPossui() && tesouros[1].getIoO() == 1) {
				tesouros[1].getItem().setPossui(true);
				mochila.addItem(tesouros[1].getItem());
				tesouros[1].getObj().setSprite(&bauAberto);

			}
			else if (tesouros[1].getIoO() == 0) {
				if (mage->isSelected()) {
					int gold = tesouros[1].getGold();
					mage->setMoreGold(gold);
				}
				else if (thief->isSelected()) {
					int gold = tesouros[1].getGold();
					thief->setMoreGold(gold);
				}
				else if (warrior->isSelected()) {
					int gold = tesouros[1].getGold();
					warrior->setMoreGold(gold);
				}
				tesouros[1].getObj().setSprite(&bauAberto);


			}
		}
	}
	else if (randMapa == 3) {
		if (mapa3.existeObjetoDoTipoNaPos("tesouro1", playerX, playerY)) {

			if (!tesouros[0].getItem().getPossui() && tesouros[0].getIoO() == 1) {
				tesouros[0].getItem().setPossui(true);
				mochila.addItem(tesouros[0].getItem());
				tesouros[0].getObj().setSprite(&bauAberto);
			}
			else if (tesouros[0].getIoO() == 0) {
				if (mage->isSelected()) {
					int gold = tesouros[0].getGold();
					mage->setMoreGold(gold);
				}
				else if (thief->isSelected()) {
					int gold = tesouros[0].getGold();
					thief->setMoreGold(gold);
				}
				else if (warrior->isSelected()) {
					int gold = tesouros[0].getGold();
					warrior->setMoreGold(gold);
				}
				tesouros[0].getObj().setSprite(&bauAberto);


			}
		}



		if (mapa3.existeObjetoDoTipoNaPos("tesouro2", playerX, playerY)) {

			if (!tesouros[1].getItem().getPossui() && tesouros[1].getIoO() == 1) {
				tesouros[1].getItem().setPossui(true);
				mochila.addItem(tesouros[1].getItem());
				tesouros[1].getObj().setSprite(&bauAberto);

			}
			else if (tesouros[1].getIoO() == 0) {
				if (mage->isSelected()) {
					int gold = tesouros[1].getGold();
					mage->setMoreGold(gold);
				}
				else if (thief->isSelected()) {
					int gold = tesouros[1].getGold();
					thief->setMoreGold(gold);
				}
				else if (warrior->isSelected()) {
					int gold = tesouros[1].getGold();
					warrior->setMoreGold(gold);
				}
				tesouros[1].getObj().setSprite(&bauAberto);


			}
		}
	}
	else if (randMapa == 4) {
		if (mapa4.existeObjetoDoTipoNaPos("tesouro1", playerX, playerY)) {

			if (!tesouros[0].getItem().getPossui() && tesouros[0].getIoO() == 1) {
				tesouros[0].getItem().setPossui(true);
				mochila.addItem(tesouros[0].getItem());
				tesouros[0].getObj().setSprite(&bauAberto);
			}
			else if (tesouros[0].getIoO() == 0) {
				if (mage->isSelected()) {
					int gold = tesouros[0].getGold();
					mage->setMoreGold(gold);
				}
				else if (thief->isSelected()) {
					int gold = tesouros[0].getGold();
					thief->setMoreGold(gold);
				}
				else if (warrior->isSelected()) {
					int gold = tesouros[0].getGold();
					warrior->setMoreGold(gold);
				}
				tesouros[0].getObj().setSprite(&bauAberto);


			}
		}



		if (mapa4.existeObjetoDoTipoNaPos("tesouro2", playerX, playerY)) {

			if (!tesouros[1].getItem().getPossui() && tesouros[1].getIoO() == 1) {
				tesouros[1].getItem().setPossui(true);
				mochila.addItem(tesouros[1].getItem());
				tesouros[1].getObj().setSprite(&bauAberto);

			}
			else if (tesouros[1].getIoO() == 0) {
				if (mage->isSelected()) {
					int gold = tesouros[1].getGold();
					mage->setMoreGold(gold);
				}
				else if (thief->isSelected()) {
					int gold = tesouros[1].getGold();
					thief->setMoreGold(gold);
				}
				else if (warrior->isSelected()) {
					int gold = tesouros[1].getGold();
					warrior->setMoreGold(gold);
				}
				tesouros[1].getObj().setSprite(&bauAberto);


			}
		}
	}
	else if (randMapa == 5) {
		if (mapa5.existeObjetoDoTipoNaPos("tesouro1", playerX, playerY)) {

			if (!tesouros[0].getItem().getPossui() && tesouros[0].getIoO() == 1) {
				tesouros[0].getItem().setPossui(true);
				mochila.addItem(tesouros[0].getItem());
				tesouros[0].getObj().setSprite(&bauAberto);
			}
			else if (tesouros[0].getIoO() == 0) {
				if (mage->isSelected()) {
					int gold = tesouros[0].getGold();
					mage->setMoreGold(gold);
				}
				else if (thief->isSelected()) {
					int gold = tesouros[0].getGold();
					thief->setMoreGold(gold);
				}
				else if (warrior->isSelected()) {
					int gold = tesouros[0].getGold();
					warrior->setMoreGold(gold);
				}
				tesouros[0].getObj().setSprite(&bauAberto);


			}
		}



		if (mapa5.existeObjetoDoTipoNaPos("tesouro2", playerX, playerY)) {

			if (!tesouros[1].getItem().getPossui() && tesouros[1].getIoO() == 1) {
				tesouros[1].getItem().setPossui(true);
				mochila.addItem(tesouros[1].getItem());
				tesouros[1].getObj().setSprite(&bauAberto);

			}
			else if (tesouros[1].getIoO() == 0) {
				if (mage->isSelected()) {
					int gold = tesouros[1].getGold();
					mage->setMoreGold(gold);
				}
				else if (thief->isSelected()) {
					int gold = tesouros[1].getGold();
					thief->setMoreGold(gold);
				}
				else if (warrior->isSelected()) {
					int gold = tesouros[1].getGold();
					warrior->setMoreGold(gold);
				}
				tesouros[1].getObj().setSprite(&bauAberto);


			}
		}
	}
	else if (randMapa == 6) {
		if (mapa6.existeObjetoDoTipoNaPos("tesouro1", playerX, playerY)) {

			if (!tesouros[0].getItem().getPossui() && tesouros[0].getIoO() == 1) {
				tesouros[0].getItem().setPossui(true);
				mochila.addItem(tesouros[0].getItem());
				tesouros[0].getObj().setSprite(&bauAberto);
			}
			else if (tesouros[0].getIoO() == 0) {
				if (mage->isSelected()) {
					int gold = tesouros[0].getGold();
					mage->setMoreGold(gold);
				}
				else if (thief->isSelected()) {
					int gold = tesouros[0].getGold();
					thief->setMoreGold(gold);
				}
				else if (warrior->isSelected()) {
					int gold = tesouros[0].getGold();
					warrior->setMoreGold(gold);
				}
				tesouros[0].getObj().setSprite(&bauAberto);


			}
		}



		if (mapa6.existeObjetoDoTipoNaPos("tesouro2", playerX, playerY)) {

			if (!tesouros[1].getItem().getPossui() && tesouros[1].getIoO() == 1) {
				tesouros[1].getItem().setPossui(true);
				mochila.addItem(tesouros[1].getItem());
				tesouros[1].getObj().setSprite(&bauAberto);

			}
			else if (tesouros[1].getIoO() == 0) {
				if (mage->isSelected()) {
					int gold = tesouros[1].getGold();
					mage->setMoreGold(gold);
				}
				else if (thief->isSelected()) {
					int gold = tesouros[1].getGold();
					thief->setMoreGold(gold);
				}
				else if (warrior->isSelected()) {
					int gold = tesouros[1].getGold();
					warrior->setMoreGold(gold);
				}
				tesouros[1].getObj().setSprite(&bauAberto);


			}
		}
	}

}

void Jogo::telaMochila()
{
	fundoInventario.desenhar(gJanela.getLargura()/2, gJanela.getAltura()/2);

	// sair do inventário
	if (gTeclado.pressionou[TECLA_I]) {
		idTelas = T_JOGO;
	}

	if (mochila.getItensNaMochila() > 0) {
		
		if (tesouros[0].getIoO() == 1 && tesouros[0].getItem().getPossui()) {

			tesouros[0].getItemSprite().desenhar(80, 150);
			texto1.setString(tesouros[0].getItem().getNome());
			texto2.setString(tesouros[0].getObj().getPropriedade("Descricao"));

			texto1.desenhar(200, 150);
			texto2.desenhar(200, 270);


			if (tesouros[1].getIoO() == 1 && tesouros[1].getItem().getPossui()) {

				tesouros[1].getItemSprite().desenhar(80, 330);
				texto3.setString(tesouros[1].getItem().getNome());
				texto4.setString(tesouros[1].getObj().getPropriedade("Descricao"));

				texto3.desenhar(200, 330);
				texto4.desenhar(200, 450);
			}
		}
	}
}

