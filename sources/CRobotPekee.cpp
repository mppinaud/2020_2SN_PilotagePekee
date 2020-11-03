//******************************************************** 
// Auteur MP Pinaud
// date : 07/10/2020
// fichier: CRobotPekee.cpp
// Enoncé : Sprint 2

// Historique :03/11/2020  Enoncé Sprint 3
// Modification ds méthodes de déplacement du robot pour suivre sa position
//********************************************************
#include <iostream>
using namespace std;

#include "..\include\CRobotPekee.h"

//********************************************************
// méthode: CRobotPekee
// rôle: Constructeur de la classe CRobotPekee. Il effectue la 
//			connexion au robot réel ou au robot simulé
// paramètres d'entrée:

//  adrIP : adresse  pour se connecter au robot réel 
//			ou simulé (dans ce cas vaut localhost)
//  n    : nom du robot
//********************************************************
CRobotPekee::CRobotPekee( char * n, char * adrIP)

{	

	strcpy (this->nom, n);
	
	strcpy (this->adresseIP, adrIP);
	if (this-> Connect(adrIP,n))
		this->connexion = true;
	else
		this->connexion = false;
}

//********************************************************
// méthode: ~CRobotPekee
// rôle: Destructeur de la classe CRobotPekee. Il effectue la 
//			deconnexion au robot réel ou au robot simulé
//********************************************************
CRobotPekee::~CRobotPekee(void)
{
	if (this->connexion)
	{
		if (this->Disconnect())
			this->connexion = false;
	}
}


//**********************************************************************
// Fonction : position
// Rôle : indique la poistion courante du robot
// sortie:	abs : noabscisse, ord : ordonnée, angle en radian
//**********************************************************************
void CRobotPekee::donner_position(float &abs, float & ord, float & angle)
{
		this->position.coordonnees(abs,ord);

		angle=this->position.orientation();

}

//********************************************************
// méthode: avancer
// rôle: avance le robot à
//********************************************************
void CRobotPekee::avancer()
{
	float x= 0,y= 0,angle = 0;

	this->ResetPosition();
	this->SetSpeed(100, 0);
	Sleep(300);
	this->GetPosition(x,y,angle);
	Sleep(300);

	this->position.deplacer(x);
	
}
//********************************************************
// méthode: reculer
// rôle: reculer le robot 
//********************************************************
void CRobotPekee::reculer()
{
	float x= 0,y= 0,angle = 0;

	this->ResetPosition();
	this->SetSpeed(-100, 0);
	Sleep(300);
	this->GetPosition(x,y,angle);
	Sleep(300);

	this->position.deplacer(x);
}

//********************************************************
// méthode: tournerG
// rôle: fait tourner le robot vers la gauche
//********************************************************
void CRobotPekee::tournerG()
{

	float x= 0,y= 0,angle = 0;

	this->ResetPosition();
	this->SetSpeed(0, -45);
	Sleep(300);
	this->GetPosition(x,y,angle);
	Sleep(300);

	this->position.orienter(angle);
}
	


//********************************************************
// méthode: tournerD
// rôle: fait tourner le robot vers la droite
//********************************************************
void CRobotPekee::tournerD()
{
	float x= 0,y= 0,angle = 0;

	this->ResetPosition();
	this->SetSpeed(0, 45);
	Sleep(300);
	this->GetPosition(x,y,angle);
	Sleep(300);

	this->position.orienter(angle);
	
}

//********************************************************
// méthode: avancer
// rôle: avance le robot sur une distance
// paramètres d'entrée:
//	distance : distance à parcourir en m
//	vitesseT : vitesse de translation en mm/s 
//********************************************************
void CRobotPekee::avancer(float distance, int vitesseT)
{
	float X, Y;		// position en mètres
	float angle ;	//  angle de rotation compris entre -2PI et 2PI
	bool res;
	// on réinitialise la position 
	res = this->SetPosition(0,0,0);
	Sleep(100);
	X = 0;
	while( abs(X) < distance)  // valeur absolue de X
	{
		this->SetSpeed(vitesseT,0);
		Sleep(100);
		bool  res = this->GetPosition (X,Y,angle);
		Sleep(150);
	}

	this->position.deplacer(X);
}

//********************************************************
// méthode: reculer
// rôle: fait reculer le robot sur une distance
// paramètres d'entrée:
//	distance : distance à parcourir en m
//	vitesseT : vitesse de translation en mm/s 
//********************************************************
void CRobotPekee::reculer (float distance, int vitesseT)
{
	
	this->avancer(distance, -vitesseT);
}

//**********************************************************************
// Fonction : clignoter_robot
// Rôle : fait clignoter le robot
// Entrées :	nb : nombre de fois où le robot clignote
//**********************************************************************
void CRobotPekee::clignoter(int nb)
{
	int i; 
	for (i = 0; i < nb; i++)
	{
		this->LedOn();
		Sleep(200);
		this->LedOff();
		Sleep(200);
	}
}

//********************************************************
// méthode: est_connecte
// rôle: indique si la connexion au robot reel ou simulé 
//       est effective
//********************************************************
bool CRobotPekee::est_connecte(void)
{
	return this->connexion;
}


