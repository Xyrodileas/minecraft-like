/*
 * Controles.cpp
 *
 *  Créé le : 2013-02-08
 *  Auteur: Alexis Vuillaume
 */

#include "Controles.h"


Controles::Controles(int argc) {
	if(argc > 1)
		azerty = false;
	else
		azerty = true;
	this->saut = 0;

}

Controles::~Controles() {
}

void Controles::Check(sf::RenderWindow *window) ///\brief Vérifie l'état des touches de contrôles
{

		// Initialisation des variables pour récupérer si une touche est enfoncée ou non

		DownKeyDown = sf::Keyboard::isKeyPressed(sf::Keyboard::Down);
		RightKeyDown = sf::Keyboard::isKeyPressed(sf::Keyboard::Right);
		UpKeyDown = sf::Keyboard::isKeyPressed(sf::Keyboard::Up);
		LeftKeyDown = sf::Keyboard::isKeyPressed(sf::Keyboard::Left);
		ZKeyDown = sf::Keyboard::isKeyPressed(sf::Keyboard::Z);
		AKeyDown = sf::Keyboard::isKeyPressed(sf::Keyboard::A);
		SKeyDown = sf::Keyboard::isKeyPressed(sf::Keyboard::S);
		QKeyDown = sf::Keyboard::isKeyPressed(sf::Keyboard::Q);
		DKeyDown = sf::Keyboard::isKeyPressed(sf::Keyboard::D);
		WKeyDown = sf::Keyboard::isKeyPressed(sf::Keyboard::W);
		PlusKeyDown = sf::Keyboard::isKeyPressed(sf::Keyboard::Add);
		MoinKeyDown = sf::Keyboard::isKeyPressed(sf::Keyboard::Subtract);
		SpaceKeyDown = sf::Keyboard::isKeyPressed(sf::Keyboard::Space);
		clicdroit = sf::Mouse::isButtonPressed(sf::Mouse::Right);	
		clicgauche = sf::Mouse::isButtonPressed(sf::Mouse::Left);	
		// MouseX = sf::Keyboard::GetMouseX();
		// MouseY = sf::Keyboard::GetMouseY();

		float posX = sf::Mouse::getPosition(*window).x;
		float posY = sf::Mouse::getPosition(*window).y;

		// if(posX > tmpx)
		// 	MouseX = MouseX+5;
		// if(posX < tmpx)
		// 	MouseX = MouseX-5;
		// if(posY > tmpy)
		// 	MouseY = MouseY+5;
		// if(posY < tmpy)
		// 	MouseY = MouseY-5;		

		// Calcul de la position relative de la souris par rapport à l'axe des origines du jeu
		// MouseY = (MouseY-300)*-1; 
		// MouseX = (MouseX-400)*-1; 

		MouseY = MouseY +(-300+posY)*-1;
		MouseX = MouseX +(-400+posX)*-1;
		
		std::cout << "posX : " << posX << std::endl <<"posY : " << posY << std::endl;
		std::cout << "MouseY : " << MouseY << std::endl <<"MouseX : " << MouseX << std::endl;
		// Calcul de l'angle de vision du joueur
		anglex = ((MouseX*0.3)/400.f)*180;
		angley = ((MouseY*0.3)/300.f)*-90;
		
		// this->anglex = 15;
		// this->angley = 30;
		sf::Mouse::setPosition(sf::Vector2i(400,300), *window);

}
float Controles::getAnglex() {
			return anglex;

}
float Controles::getAngley() {
			return angley;

}

void Controles::Action(Joueur &player1,Plateau &p, float Framerate) ///\brief Applique les actions à faire en fonction des contrôles actionné
{


	if(!p.isCube(player1.getPosx()/50,(int)player1.getPosy()/50,(player1.getPosz()/50)-2))
		player1.setPosz(player1.getPosz()-8);

	if(this->azerty)
	{
	   	if(ZKeyDown)
	   	{
	   		if(!p.isCube(player1.getPosCamx()/50,(int)player1.getPosCamy()/50,player1.getPosz()/50))
	   		{
	   			if(!p.isCube(player1.getPosCamx()/50,(int)player1.getPosCamy()/50,(player1.getPosz()/50))+1)
	   			{
	   				player1.avancer(anglex, angley, Framerate);
	   			}
	   		}
	   	}
	    	
	    if(QKeyDown)
	    {
	   		player1.gauche(anglex, angley, Framerate);
	    }
	}
	else
	{
		if(WKeyDown)
	    	player1.avancer(anglex, angley, Framerate);
	    if(AKeyDown)
	   		player1.gauche(anglex, angley, Framerate); 
	}
	if(SKeyDown)
	    player1.reculer(anglex, angley, Framerate);
	if(SpaceKeyDown && !saut) 
		this->saut=1;
   	if(DKeyDown == true)
	   	player1.droite(anglex, angley, Framerate);
	if(clicdroit == true){
		std::cout << (int)(player1.getPosCamx()/50)<< " " << (int)(player1.getPosCamy()/50) << " " << (int)(player1.getPosCamz()/50-1) << std::endl;

		p.supprimer_cube((int)(player1.getPosCamx()/50), (int)(player1.getPosCamy()/50) , (int)(player1.getPosCamz()/50)-2);
	}
	if(clicgauche == true){
		std::cout << (int)(player1.getPosCamx()/50)<< " " << (int)(player1.getPosCamy()/50) << " " << (int)(player1.getPosCamz()/50-1) << std::endl;

		p.ajouter_cube((int)(player1.getPosCamx()/50), (int)(player1.getPosCamy()/50) , (int)(player1.getPosCamz()/50)-2);
	}
	   

}

void Controles::Sauter(Joueur &player1, Plateau &p) ///\brief Permet de faire sauter le joueur
 {

	
	if(saut>0) {
		float y= - 15*saut*saut + 60*saut + player1.getPosz();
		player1.setPosz(y);
		saut = saut + 0.05;
		if(!p.isCube(player1.getPosx()/50,(int)player1.getPosy()/50,(player1.getPosz()/50)-2))
			saut = 0;
		
		

	}
	if(saut==20)
		saut=0;

}