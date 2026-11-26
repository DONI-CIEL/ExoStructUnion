//*************************************************************************************
// Nom du projet : Transgerbeur
// Nom de l'auteur : Donin De Rosière Maxime
// Date de création : 24/11/2026
// Révision ou version :
// Version du compilateur : 
//****************************************************************************************

#include <iostream>
using namespace std;

struct Srgb
{
	unsigned char r;
	unsigned char g;
	unsigned char b;
};

union UColor
{
	unsigned int val;
	Srgb components;
	unsigned char tabCol[3];
};

int main()
{
	cout << "-------  Test de UColor en Hexadecimal  -------" << endl;

	UColor col = {}; // Initialise les octets à 0
	unsigned int saisie; // Variable temporaire pour lire proprement un nombre avec cin

	// Saisie en hexadécimal des composantes R, G, B
	cout << "Entrez la valeur de R en hexa (ex: FF) : ";
	cin >> hex >> saisie;
	col.components.r = saisie;

	cout << "Entrez la valeur de G en hexa (ex: A2) : ";
	cin >> hex >> saisie;
	col.components.g = saisie;

	cout << "Entrez la valeur de B en hexa (ex: 10) : ";
	cin >> hex >> saisie;
	col.components.b = saisie;

	// Affichage des différents membres de l'union en hexadécimal
	cout << "\n--- Resultat dans l'union UColor ---" << endl;
	cout << "Composantes RGB : R=" << hex << (int)col.components.r
		<< " | G=" << hex << (int)col.components.g
		<< " | B=" << hex << (int)col.components.b << endl;

	cout << "Tableau tabCol  : [0]=" << hex << (int)col.tabCol[0]
		<< " | [1]=" << hex << (int)col.tabCol[1]
		<< " | [2]=" << hex << (int)col.tabCol[2] << endl;

	cout << "Entier complet (val) : 0x" << hex << col.val << endl;

	// Test inverse : modifier 'val' directement en hexa
	cout << "\nEntrez une couleur complete sur 32 bits en hexa (ex: 00112233) : ";
	cin >> hex >> col.val;

	cout << "Nouvelles composantes : R=" << hex << (int)col.components.r
		<< " | G=" << hex << (int)col.components.g
		<< " | B=" << hex << (int)col.components.b << endl;

	return 0;
}
