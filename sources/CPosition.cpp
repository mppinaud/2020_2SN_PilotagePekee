//********************************************************
// Auteur MP Pinaud
// date : 06/10/2020
// fichier: Position.cpp
// Code des fonctions de la classe représentant une position
// Historique :
//********************************************************
#include <iostream>
using namespace std;
#include "CPosition.h"



//*************************************************************************
// Méthode: CPosition
// Rôle: Constructeur de la classe point qui initialise l'abscisse et
//       l'ordonnée et l'angle d'une position
// Paramètres d'entrée:
//		x: abscisse du point
//		y : ordonnée du point
//              theta : angle
//*************************************************************************
CPosition::CPosition(const float x, const float y, const float theta)
{
	this->abs = x;
	this->ord = y;
	this->angle = theta;
}



//********************************************************
// Méthode: deplacer
// rôle: déplace la position
// paramètres d'entrée:
//		d:  distance parcourue
//********************************************************
void CPosition::deplacer(const float d)
{
	this ->abs = this ->abs + d * cos(this->angle);
	this ->ord = this ->ord + d * sin(this->angle);
}

//********************************************************
// Méthode: orienter
// rôle: change l'angle par rapport à l'axe des abscisse
// paramètres d'entrée:
//		theta:  nouvel angle
//********************************************************
void CPosition::orienter(const float theta)
{
	this ->angle = this ->angle + theta;
}


//********************************************************
// Méthode: coordonnées
// rôle: indique l'abscisse et l'ordonnée de la position
// paramètres de sortie:
//		x: abscisse du point
//		y : ordonnée du point
//********************************************************
    void CPosition::coordonnees (float &x, float &y)
    {
        x = this->abs;
        y = this->ord;
    }

//********************************************************
// Méthode: orientation
// rôle: indique l'angle par rapport à l'axe des abscisses
// Retour: l'angle de la position
//********************************************************
    float CPosition::orientation()
    {
        return (this->angle);
    }