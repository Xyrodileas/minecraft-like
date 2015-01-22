/*
 * Ecran.h
 *
 *  Créé le : 2013-02-08
 *  Auteur: Alexis Vuillaume
 */

#ifndef ECRAN_H_
#define ECRAN_H_

class Ecran {
public:
	Ecran();
	virtual ~Ecran(int, int, char*);
	void dessiner();
private:
	int haut;
	int larg;
	char* nom ="noname";
};

#endif /* ECRAN_H_ */