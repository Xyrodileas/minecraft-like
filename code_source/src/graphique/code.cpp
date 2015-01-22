#include <GL/gl.h>
#include <GL/glu.h>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <cstdio>
#include <stdio.h>
#include <signal.h>
#include <iostream>
#include <cmath>
#include "../Joueur/Joueur.h"
#include "../Joueur/JoueurExt.h"
#include "../Joueur/Controles.h"
#include "../plateau/Plateau.h"
#include <vector>
#define nullptr NULL

#include <SFML/Network.hpp>
#include <cstring>
#include <sstream>
#include <string>
#include <iostream>


/**
  * Inclusion pour le reseau
  */
#include <chrono>
#include <mutex>
//#include "../reseau/reseau.hpp"


char buff[50];
GLuint Nom;


// void* server(void* arg){ // Fonction permettant de créer un serveur
	
// 	Serveur serv;
// 	std::string conversion((char*)arg);
// 	Client cli(conversion);

// 	while(1){

// 			if((conversion = cli.recevoir()) != "")
// 				strcpy(buff, conversion.c_str());
// 	}

// 		return nullptr;

// }



int main(int argc, char** argv)
{

	

	// Création de la fenêtre App
    sf::RenderWindow App(sf::VideoMode(800, 600, 32), "Minecraft-Like");
	sf::Clock Clock;

	glMatrixMode( GL_PROJECTION );
	glLoadIdentity();
	gluPerspective(70,(double)640/480,1,10000);
	glFrontFace(GL_CCW);
	//glEnable(GL_CULL_FACE);
	App.setMouseCursorVisible(false);


	// Variable pour la position de la caméra
	float posx = 300;
	float posy = 150;
	float posz = 590;

	glEnable(GL_DEPTH_TEST);
	glEnable(GL_TEXTURE_2D);
	sf::Image img_data;
	if (!img_data.loadFromFile("terre2.png"))
	{
	    std::cout << "Could not load terre2.png" << std::endl;
	    
	}
	GLuint texture_handle;
	glGenTextures(1, &texture_handle);
	glBindTexture(GL_TEXTURE_2D, texture_handle);
	glTexImage2D(
	    GL_TEXTURE_2D, 
	    0, 
	    GL_RGBA,
	    img_data.getSize().x, 
	    img_data.getSize().y,
	    0,
	    GL_RGBA, GL_UNSIGNED_BYTE, img_data.getPixelsPtr()
	);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	glBindTexture(GL_TEXTURE_2D, texture_handle);
	//glClearDepth(1.f);
    glClearColor(0.f, 0.f, 0.f, 0.f);

    float anglez = 0;
    float anglex = 0;

    float zoom = 1;

	Plateau p(100, 100, 10, 50.f);

	bool supprime = true;

	// On commence par positionner le joueur
	Joueur player1(posx,posy,posz, false);
	float phi;
	Controles controle(argc);


	// vector<JoueurExt> Joueursconnecte;

	// if(argv[3] == "s"){
	// 	int nb_sock = 1;
	// 	pthread_t thread[nb_sock];

	// 	int sock = creer_socket();
	// 	int csock = connexion(sock);
	// 	// Permet d'exécuter le fonction maFonction en parallèle
	// 	pthread_create(thread, NULL, maFonction, &csock);

	// 	pthread_join(*(thread), NULL);

	// }
	int x = 100;
	int y = 100;
	int truue = true;
				JoueurExt testjoueur1(x, 		y, 550, true, (char**)"tt");
				JoueurExt testjoueur3(x+100,	y, 550, true, (char**)"tt");
				JoueurExt testjoueur2(x, 		y, 600, true, (char**)"tt");
				JoueurExt testjoueur4(x+100,	y, 600, true, (char**)"tt");
				JoueurExt testjoueur5(x, 		y, 650, true, (char**)"tt");
				JoueurExt testjoueur6(x+100,	y ,650, true, (char**)"tt");
				JoueurExt testjoueur7(x+50,		y ,650, true, (char**)"tt");

				JoueurExt testjoueur8(x, 		y, 700, true, (char**)"tt");
				JoueurExt testjoueur9(x+100,	y ,700, true, (char**)"tt");
				JoueurExt testjoueur10(x+50,	y ,700, true, (char**)"tt");
				JoueurExt testjoueur11(x, 		y, 750, true, (char**)"tt");
				JoueurExt testjoueur12(x+100,	y ,750, true, (char**)"tt");
				JoueurExt testjoueur13(x+50,	y ,750, true, (char**)"tt");

				JoueurExt testjoueur14(x-50, 	y, 750, true, (char**)"tt");
				JoueurExt testjoueur15(x+150,	y ,750, true, (char**)"tt");
				JoueurExt testjoueur16(x-100,	y, 750, true, (char**)"tt");
				JoueurExt testjoueur17(x+200,	y ,750, true, (char**)"tt");
				JoueurExt testjoueur18(x+50,	y ,800, true, (char**)"tt");

				JoueurExt testjoueurmulti(0,	0 ,0, true, (char**)"titi");
	// if(std::strcmp(argv[2],"server") == 0) {

	// 	pthread_t thread;
	// 	std::cout << "Création du thread" << std::endl;

	// 	pthread_create(&thread, NULL, server, *argv);
	// 	system("ps");
	// 	std::cout << "Thread créé, écoute en cours" << std::endl;
	// }

	char i;

	while (App.isOpen())
	{

	    sf::Event Event;
	    while (App.pollEvent(Event))
	    {
	        // Fermeture de la fenêtre
	        if (Event.type == sf::Event::Closed)
	            App.close();

	        // Touche échappe enfoncée
	        if ((Event.type == sf::Event::KeyPressed) && (Event.key.code == sf::Keyboard::Escape))
	            App.close();
	        if (Event.type == sf::Event::Resized){
	    		glViewport(0, 0, Event.size.width, Event.size.height);
	    	}
	    }

	    // App.SetView(View1);
	    Clock.restart();
	    testjoueur1.setPosJoueur(x, 		y, 550);
		testjoueur3.setPosJoueur(x+100,		y, 550);
		testjoueur2.setPosJoueur(x, 		y, 600);
		testjoueur4.setPosJoueur(x+100,		y, 600);
		testjoueur5.setPosJoueur(x, 		y, 650);
		testjoueur6.setPosJoueur(x+100,		y ,650);
		testjoueur7.setPosJoueur(x+50,		y ,650);
		testjoueur8.setPosJoueur(x, 		y, 700);
		testjoueur9.setPosJoueur(x+100,		y ,700);
		testjoueur10.setPosJoueur(x+50,		y ,700);
		testjoueur11.setPosJoueur(x, 		y, 750);
		testjoueur12.setPosJoueur(x+100,	y ,750);
		testjoueur13.setPosJoueur(x+50,		y ,750);
		testjoueur14.setPosJoueur(x-50, 	y, 750);
		testjoueur15.setPosJoueur(x+150,	y ,750);
		testjoueur16.setPosJoueur(x-100,	y, 750);
		testjoueur17.setPosJoueur(x+200,	y ,750);
		testjoueur18.setPosJoueur(x+50,		y ,800);



		std::string test = buff;
 		std::istringstream iss(test);
    	std::string mot;
    	int coordjoueur[3];
    	int ghg = 0;
    	while ( std::getline( iss, mot, ';' ))
		    {
				std::stringstream convert(mot);
				std::cout << mot << std::endl;
				if ( !(convert >> coordjoueur[ghg]) )
				    coordjoueur[ghg] = 0;
		        ghg += 1;
		        std::cout << ghg << std::endl;
		    }	
		// std::cout << coordjoueur[0] << " " << coordjoueur[1] << " " << coordjoueur[2] << std::endl;
		 testjoueurmulti.setPosJoueur(coordjoueur[0],coordjoueur[1],coordjoueur[2]);
		 


	    if(truue && x < 1000) {
	    	x += 10;
	    	y += 10;
	    }
	    else if(!truue && x >0){
	    	x -= 10;
	    	y -= 10;

	    }
	    else if(x >= 1000){
	    	truue = false;
	    }
	    else if(x == 0){
	    	truue = true;
	    }


		float Framerate = 1.f / Clock.getElapsedTime().asSeconds();


	    // On vérifie si des touches sont enfoncées par l'utilisateur
	    controle.Check(&App);

	    // Focus sur la fenêtre et paramètrage d'openGL
		App.setActive();
	    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();

		// Permet de placer raffraichir la position de la caméra
		controle.Action(player1,p, Framerate);

		player1.maj(controle.getAnglex(), controle.getAngley());

		// On applique les actions de déplacement en fonction des touches enfoncées

	    controle.Sauter(player1, p);

	    // Génération de la map

	    if (supprime)
	    {
	    	p.supprimer_cube(0,0,9);
	    	p.supprimer_cube(1,0,9);

	    	p.supprimer_cube(2,2,2);

	    	supprime = false;
	    }

	    p.afficher_plateau();

	    

	    	    int c = 3000;
		// glBegin(GL_QUADS);        // Fond de la map
		//   glColor3f(0.153,0.51,0.153);    
		//   glVertex3f(-c,c,-c);
		//   glVertex3f(-c,-c,-c);
		//   glVertex3f(c,-c,-c);
		//   glVertex3f(c,c,-c);
		//   glVertex3f(c,c,c);
		//   glVertex3f(-c,c,c);
		//   glVertex3f(-c,-c,c);
		//   glVertex3f(c,-c,c);
		//   glVertex3f(-c,c,-c);
		//   glVertex3f(-c,-c,-c);
		//   glVertex3f(-c,-c,c);
		//   glVertex3f(-c,c,c);
		//   glVertex3f(c,c,c);
		//   glVertex3f(c,-c,c);
		//   glVertex3f(c,-c,-c);
		//   glVertex3f(c,c,-c);
		//   glVertex3f(-c,-c,c);
		//   glVertex3f(-c,-c,-c);
		//   glVertex3f(c,-c,-c);
		//   glVertex3f(c,-c,c);
		//   glVertex3f(c,c,c);
		//   glVertex3f(c,c,-c);
		//   glVertex3f(-c,c,-c);
		//   glVertex3f(-c,c,c);
		//   glEnd();            
		glFlush();



	    testjoueur1.DrawJoueur();
	    testjoueur2.DrawJoueur();
	    testjoueur3.DrawJoueur();
	    testjoueur4.DrawJoueur();
	    testjoueur5.DrawJoueur();
	    testjoueur6.DrawJoueur();
	    testjoueur7.DrawJoueur();
		testjoueur8.DrawJoueur();
		testjoueur9.DrawJoueur();
		testjoueur10.DrawJoueur();
		testjoueur11.DrawJoueur();
		testjoueur12.DrawJoueur();
		testjoueur13.DrawJoueur();
		testjoueur14.DrawJoueur();
		testjoueur15.DrawJoueur();
		testjoueur16.DrawJoueur();
		testjoueur17.DrawJoueur();
		testjoueur18.DrawJoueur();
		testjoueurmulti.DrawJoueur();

		
		// Force openGL à finir l'exécution de ses commandes encore en cours
		glFlush();
		
		// App.SetView(App.GetDefaultView());
		// App.SetView(View);
		// App.Draw(Polygon);
		// App.Draw(sf::Shape::Circle(10, 10, 30, sf::Color::Yellow, 10, sf::Color::Blue));
		// App.SetView(App.GetDefaultView());
	    // On affiche le résultat

	    App.display();

	    if(std::strcmp(argv[2],"client") == 0) {
	    	std::cout << "Mode Client" << std::endl;

			std::string bufferS;
			// bufferS = player1.getPosx().concat(";").concat(player1.getPosy()).concat(";").concat(player1.getPosz());

			// ccode::cli.envoyer(bufferS);
		}

	}


}
