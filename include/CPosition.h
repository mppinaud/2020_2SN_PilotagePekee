//********************************************************
// Auteur MP Pinaud
// date : 06/10/2020
// fichier: Position.h
// Interface de la classe représentant une position
//********************************************************

#pragma once

class CPosition
{
public:

	//*************************************************************************
	// Méthode: CPosition
	// Rôle: Constructeur de la classe point qui initialise l'abscisse, 
	//       l'ordonnée et l'angle de la position
	// Paramètres d'entrée:
	//		x: abscisse du point
	//		y : ordonnée du point
	//      	theta : angle
	//*************************************************************************
	CPosition(const float x=0, const float y=0, const float theta = 0);



	//********************************************************
	// Méthode: deplacer
	// rôle: déplace la position
	// paramètres d'entrée:
	//		d:  distance parcourue
	//********************************************************
	void deplacer(const float d);

	//********************************************************
    	// Méthode: orienter
    	// rôle: change l'angle par rapport à l'axe des abscisse
    	// paramètres d'entrée:
    	//		theta:  nouvel angle
    	//********************************************************
    	void orienter(const float theta);

    	//********************************************************
    	// Méthode: coordonnées
    	// rôle: indique l'abscisse et l'ordonnée de la position
    	// paramètres de sortie:
	//		x: abscisse du point
	//		y : ordonnée du point
    	//********************************************************
    	void coordonnees (float &x, float &y);

    	//********************************************************
    	// Méthode: orientation
    	// rôle: indique l'angle par rapport à l'axe des abscisses
    	// Retour: l'angle de la position
    	//********************************************************
    	float orientation();

	private:
		float abs; // abscisse
		float ord; // ordonnée
		float angle; // angle par rapport à l'axe des abscisses
};
