//******************************************************** 
// Auteur MP Pinaud
// date : 07/09/2020
// fichier: Robot.h
// Interface de la classe CRobotPekee qui améliore le pilotage
// d'un robot Pekee
// Enoncé : Sprint2

// Historique :03/11/2020 : Enoncé Sprint 3
// Ajout de laposition pour suivre le robot
//********************************************************
#pragma once
#include "libRobotPekee.h"

#include "CPosition.h"


class CRobotPekee : protected WRobotPekee
{

public:
	//********************************************************
	// méthode: CRobotPekee
	// rôle: Constructeur de la classe CRobotPekee. Il effectue la 
	//			connexion au robot réel ou au robot simulé
	// paramètres d'entrée:
	//  adrIP : adresse  pour se connecter au robot réel 
	//			ou simulé (dans ce cas vaut localhost)
	//  n    : nom du robot
	//********************************************************
	CRobotPekee( char * n = "Pekee", char * adrIP = "localhost");


	//********************************************************
	// méthode: ~CRobotPekee
	// rôle: Destructeur de la classe CRobotPekee. Il effectue la 
	//			deconnexion au robot réel ou au robot simulé
	//********************************************************
	~CRobotPekee(void);
	
	

	//********************************************************
	// méthode: est_connecte
	// rôle: indique si la connexion au robot reel ou simulé 
	//       est effective
	//********************************************************
	bool est_connecte(void);

	//**********************************************************************
	// Méthode : position
	// Rôle : indique la poistion courante du robot
	// Sorties:	abs : noabscisse, ord : ordonnée, angle en radian
	//**********************************************************************
	void donner_position(float &abs, float &ord, float &angle);
	
	//********************************************************
	// méthode: avancer
	// rôle: avance le robot 
	//********************************************************
	void avancer();

	//********************************************************
	// méthode: reculer
	// rôle: reculer le robot 
	//********************************************************
	void reculer();

	//********************************************************
	// méthode: tournerG
	// rôle: fait tourner le robot vers la gauche
	//********************************************************
	void tournerG();

	//********************************************************
	// méthode: tournerD
	// rôle: fait tourner le robot vers la droite
	//********************************************************
	void tournerD();

	//********************************************************
	// méthode: avancer
	// rôle: avance le robot sur une distance
	// paramètres d'entrée:
	//	distance : distance à parcourir en m
	//	vitesseT : vitesse de translation en mm/s 
	//********************************************************
	 void avancer(float distance, int vitesseT= 100);

	 //********************************************************
	// méthode: reculer
	// rôle: fait reculer le robot sur une distance
	// paramètres d'entrée:
	//	distance : distance à parcourir en m
	//	vitesseT : vitesse de translation en mm/s 
	//********************************************************
	 void reculer(float distance, int vitesseT= 100);

	//**********************************************************************
	// Fonction : clignoter_robot
	// Rôle : fait clignoter le robot
	// Entrées :	nb : nombre de fois où le robot clignote
	//**********************************************************************
	void clignoter(int nb);

	

	
private :

	bool connexion;		// indique si la connexion au robot s'est faite

	char nom [15];		// nom du robot
	char adresseIP[15];	// adresse de connexion au robot

	CPosition position; // position courante du robot

};
