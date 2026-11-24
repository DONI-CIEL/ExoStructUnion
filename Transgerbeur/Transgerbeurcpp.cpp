//*************************************************************************************
// Nom du projet : Transgerbeur
// Nom de l'auteur : Donin De Rosière Maxime
// Date de création : 24/11/2026
// Révision ou version :
// Version du compilateur : 
//****************************************************************************************

#include <iostream>
using namespace std;


// 1. énumération pour l'état du contenu
enum EEtat {
	VIDE,
	PALETTE,
	ROULEAU
};

// 2. structure pour une palette
struct SPalette {
	int poids;
	char ref[20];
};
// 3. structure pour un rouleau
struct SRouleau {
	float longueur;
	int numero;
};

// 4. union pour le contenu (soit une palette, soit un rouleau)
union UContenu {
	SPalette palette;
	SRouleau rouleau;
};

// 5. structure pour un casier complet
struct SCasier {
	int px;
	int py;
	EEtat etat;
	UContenu contenu;
};

int main()
{

	cout << " Programme Transgerbeur " << endl;

	SPalette palette;
	SRouleau rouleau;
	SCasier casier;
	SCasier tabCasiers[9]; // Le tableau de 9 casiers

	return 0;


}
