//*************************************************************************************
// Nom du projet : Transgerbeur
// Nom de l'auteur : Donin De Rosière Maxime
// Date de création : 24/11/2026
// Révision ou version :
// Version du compilateur : 
//****************************************************************************************

#include <iostream>
#include <cstring>
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
	

	SRouleau ro1 = { 10.5, 552 };

	SPalette pa1;
	pa1.poids = 101.2;
	strcpy_s(pa1.ref, "ref1");

	EEtat etatC1 = VIDE;

	UContenu cont = { pa1 };
	cont.rouleau = ro1;

	SCasier c1;
	c1.contenu = cont;
	c1.etat = ROULEAU;
	c1.px = 2;
	c1.py = 3;

	c1.contenu.rouleau.numero = 322;

	SCasier c2 = { 1, 4, PALETTE, { {320, "PAL-2026-B"} } };

	SCasier tabCasiers[9] = {};
	tabCasiers[0] = c1;
	tabCasiers[2] = c2;

	cout << "\n-------  Tailles en memoire  -------" << endl;
	cout << "Taille EEtat                : " << sizeof(etatC1) << " octets" << endl;
	cout << "Taille SRouleau             : " << sizeof(ro1) << " octets" << endl;
	cout << "Taille SPalette             : " << sizeof(pa1) << " octets" << endl;
	cout << "Taille UContenu             : " << sizeof(cont) << " octets" << endl;
	cout << "Taille SCasier              : " << sizeof(c1) << " octets" << endl;
	cout << "Taille tabCasiers           : " << sizeof(tabCasiers) << " octets" << endl;

	return 0;


}
