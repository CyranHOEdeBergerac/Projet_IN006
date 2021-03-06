#ifndef SIGNATUREH
#define SIGNATUREH

#include <string.h>
#include<stdlib.h>
#include<stdio.h>
#include"../Partie_1/gestion_cryptage.h"
#include"gestion_clef.h"

/*Structure contenant un tableau de longs représentant une signature*/
typedef struct _signature{
	long* contenu;
	int longueur;
}Signature;

/*Structure contenant la clé publique de l’émetteur (l’électeur), son
message (sa déclaration de vote), et la signature associée.*/
typedef struct _protected{
	Key* pKey;
	char* mess;
	Signature* sgn;
}Protected;


/*Fonction permettant d’allouer et de remplir une signature avec un tableau de long déjà alloué et initialisé. */
Signature* init_signature(long* content, int size);

/*Fonction faisant la deepcopy d'un signature sgn*/
Signature* deep_copy_sgn(Signature* sgn);

/*Fonction permettant de créer une signature à partir du message mess (déclaration de vote) 
et de la clé secrète de l’émetteur.*/
Signature* sign(char* mess, Key* sKey);

/*Fonction qui transforme une signature en chaîne de caractères*/
char* signature_to_str(Signature* sgn);

/*Fonction qui transforme une chaîne de caractères en signature*/

/** @brief Fonction qui transforme une chaine ...
	@param str chaine qui doit être transformée
	@return Signature* la signature issue de la transformation
**/
Signature* str_to_signature(char* str);

/*Fonction permettant d'initaliser et d'allouer la structure protected*/
Protected* init_protected(Key* pKey, char* mess, Signature* sgn);

/*Fonction qui permet de vérifier que la signature contenue dans
pr correspond bien au message et à la personne contenus dans pr.*/
int verify(Protected* pr);


/*Fonction qui permet de passer d'un Protected à sa représentation sous forme de chaîne de caractères de forme 
"cle_publique message signature"*/
char* protected_to_str(Protected* protected);

/*Fonction qui permet de passer d'une chaîne de caractères ("cle_publique message signature") à un Protected*/
Protected* str_to_protected(char* chaine);


/*Fonction permettant de libérer la mémoire allouée à une signature sgn*/
void liberer_signature(Signature* sgn);

/*Fonction permettant de libérer la mémoire allouée à un protected pr*/
void liberer_protected(Protected* pr);


#endif