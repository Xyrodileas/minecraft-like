/*
 * JoueurExt.h
 *
 *  Créé le : 2013-02-26
 *  Auteur: Alexis Vuillaume
 */

#ifndef JOUEUREXT_H
#define JOUEUREXT_H

class JoueurExt : public Joueur {
public:
	JoueurExt(float,float,float,bool);
	JoueurExt();
	virtual ~JoueurExt();

	Point getPosRegard();
	Point getPosJoueur();
	void setPosRegard();
	void setPosJoueur();
	char** getPseudo();
	void setPseudo();
	void DrawJoueur();
	void setPosJoueur(int, int, int);

protected:

	char** pseudo;



};

#endif /* JOUEUR_H */