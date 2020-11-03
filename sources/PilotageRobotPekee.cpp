//***********************************************************************
// Date : 07/10/2020		Auteur : MP Pinaud
// Nom du fichier : PilotageRobotPekee.cpp
// Rôle : Programme qui permet de piloter un robotPekee
//**********************************************************************


#include <iostream>

using namespace std;


#include "..\include\CRobotPekee.h"




//**********************************************************************
// Fonction : main
// Rôle : se connecter au robot et le commander
// Variable globale utilisée : robot
//**********************************************************************

int main(void)
{
	

	// Création du robot et Connexion au robot simulé
	CRobotPekee robot("Pekee", "localhost");
	
	bool connecte=false;  // indique si la connexion avec le robot est faite
	
	
	if (robot.est_connecte())
	{
		cout << "connexion avec le robot ok \n";
		
		int rep;

	do
	{
		cout << "Commande du robot" << endl;
		cout << "**************************" << endl<< endl;

		cout << "Que doit faire le robot ?" << endl;
		cout << "1 - Avancer" << endl;
		cout << "2 - Reculer" << endl;
		cout << "3 - Tourner a gauche  " << endl;
		cout << "4 - Tourner a droite" << endl;
		cout << "5 - Avancer sur une distance" << endl;
		cout << "6 - Reculer sur une distance" << endl;
		cout << "7-  Clignoter" << endl;
		cout << "8-  Afficher la position" << endl;
		
		cout << "0 - Fin commande du robot" <<endl;

		cin >> rep;

		switch (rep)
		{
			case 1 :		
						//  AVANCER
						robot.avancer();
						break;
			case 2 :	
						//  RECULER
						robot.reculer();
						break;
					
						
			case 3 :	//  TOURNER A GAUCHE
						robot.tournerG();
						break;

			case 4 :	//  TOURNER A DROITE
						robot.tournerD();
						break;


			case 5 :	//  AVANCER sur une distance
						{
							float distance;
							cout << "Quelle distance de deplacement en metres ?" ;
							cin >> distance;
							int vitesse;
							cout << "Quelle vitesse de translation en mm/s? :" ;
							cin >> vitesse;
	
							robot.avancer(distance,vitesse);
							break;
						}

			case 6 :	//  RECULER sur une distance
						{
							float distance;
							cout << "Quelle distance de deplacement en metres ?" ;
							cin >> distance;
							int vitesse;
							cout << "Quelle vitesse de translation en mm/s ? :" ;
							cin >> vitesse;
	
							robot.reculer(distance,vitesse);
							break;
						}
			
						
			case 7 :	//  CLIGNOTER
						cout << "nombre clignotements :";
						int nb;
						cin >> nb;
						robot.clignoter(nb);
						break;
					

			case 8 :	//  Afficher la position
						float x,y,theta;
						robot.donner_position(x,y,theta);
						cout<< "Position du robot : " << x <<"," << y <<"," << theta << ")";
						break;
						
			
			case 0 :	{
							cout << "Fin commande du robot" <<endl;
							cout << "*********************" << endl;
							break;
						}
			default :	cout << "Erreur de saisie" <<endl;
						break;
		} 
	} while (rep != 0);


	
		
			
	}
	else
	{
		cout << "probleme de connexion avec le robot  \n";
		cout << "pour sortir : appuyer sur une touche\n";

	}

	return 0 ;
}

