/*
 * JoueurExt.h
 *
 *  Créé le : 2013-02-26
 *  Auteur: Alexis Vuillaume
 */

#ifndef JOUEUREXT_H
#define JOUEUREXT_H


#include "Joueur.h"

class JoueurExt : public Joueur {
public:
	JoueurExt(float,float,float,bool, char**);
	JoueurExt();
	virtual ~JoueurExt();

	float getPosRegardx();
	float getPosRegardy();
	float getPosRegardz();

	void setPosRegard(int, int, int);
	void setPosJoueur(int, int, int);
	char** getPseudo();
	void setPseudo(char **);
	void DrawJoueur();

protected:

	char** pseudo;



};

#endif /* JOUEUR_H */