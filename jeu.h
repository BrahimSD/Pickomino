#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
typedef struct joueurs joueurs;
typedef struct Element Element;
typedef struct Pickominos Pickominos ;
typedef struct Pile Pile;
struct Element
{
    int nombre;
    Element *suivant;
};
struct Pile
{
    Element *premier;
};

typedef struct Element Element;

struct tdes {
int val;
int somme;
};
struct Pickominos {
int Valeur;
joueurs *gagnant;
};
struct joueurs {
int Sommeval;
int dernierval;
struct Pile pu;
};
void empiler(Pile *pile, int nvNombre);
void Menu();
int  gagnant (struct joueurs *joueurs,int NombreJoueurs);
void initializer (int *t,struct tdes *ValDG);
void lancer (int *s,int*Des,struct tdes *ValDG);
void jouer (int NombreJoueurs);
void lancerRobo(int *s,int*Des,struct tdes *ValDG);
void jouerseul();
