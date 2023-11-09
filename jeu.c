#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include "jeu.h"

void empiler(Pile *pile, int nvNombre){
    Element *nouveau = malloc(sizeof(*nouveau));
    if (pile == NULL || nouveau == NULL)
    {
        exit(EXIT_FAILURE);
    }

    nouveau->nombre = nvNombre;
    nouveau->suivant = pile->premier;
    pile->premier = nouveau;
}
int depiler(Pile *pile){
    if (pile == NULL)
    {
        exit(EXIT_FAILURE);
    }

    int nombreDepile = 0;
    Element *elementDepile = pile->premier;

    if (pile != NULL && pile->premier != NULL)
    {
        nombreDepile = elementDepile->nombre;
        pile->premier = elementDepile->suivant;
        free(elementDepile);
    }

    return nombreDepile;
}
void Menu(){
   FILE* fichier = NULL;
   int NombreJoueurs,typedejeu=5;
   char t;
   fichier =fopen("sauvgarder.txt","r");
   if (fichier !=NULL)
   {
       printf("vous avez deja une parti sauvgarder \n\n");
       printf("pour continuer taper - o :\n pour commencer une parti taper autre touche\n\n");
       fflush(stdin);
       scanf("%c",&t);
       if (t=='O' || t=='o')
       {  printf("\n%d\n",fgetc(fichier));
          printf("%d\n",fgetc(fichier));
          printf("%d\n",fgetc(fichier));
          printf("%d\n",fgetc(fichier));
          printf("%d\n",fgetc(fichier));
          printf("%d\n",fgetc(fichier));

         //typedejeu =atoi(fgetc(fichier));
        // printf("%d",NombreJoueurs);
       }
       else goto Nouvelle ;
   }
   else {
    Nouvelle :
    printf("\n quelle est le nombre de joueurs ?");
   printf(",\n\n pour jouer seul avec le robot taper 1\n\n");
   fflush(stdin);
   scanf("%d",&NombreJoueurs);
   if (NombreJoueurs==1) jouerseul();
   else jouer(NombreJoueurs);
   }

}
int  gagnant (struct joueurs *joueurs,int NombreJoueurs){
    int g =0,max =joueurs[0].Sommeval;
    for (int i=0;i<NombreJoueurs-1;i++)
    {
        if (max<=joueurs[i+1].Sommeval)
        { max=joueurs[i+1].Sommeval;
            g =i+1; }
    }
    return g;
}
void initializer (int *t,struct tdes *ValDG){

        *t =0 ; *(t+1)=8;  *(t+2) =0;
        for (int i=0;i<6;i++)
           {ValDG[i].somme=0; }
}
void lancer (int *s,int*Des,struct tdes *ValDG){
    srand(time(NULL));
    int i=0,po=0;
    char val,ch;
    printf("\n ");
    for (int z=0;z<*(s+1);z++)
    {
    Des[z]=(rand()%6)+1;
    if (Des[z]==6){ printf("[V]  ");}
    else { printf("[%d]  ",Des[z]);}
    Des[*(s+1)]=-1;
    }

    for(int j=0;j<6;j++)
    {   if (ValDG[j].somme>0) ValDG[j].somme=0;

       while (Des[i]!=-1){
            if (ValDG[j].val==Des[i]&&ValDG[j].somme>=0)  ValDG[j].somme++;
            i++;}
       if (ValDG[j].somme>0) po+=1;
       i=0;
    }
 if(po>0)

 {      LOOP:
    printf("\n\nchoisi une valeur parmi les vals possibles : \n\n");

    fflush(stdin);
    scanf("%c",&val);

       if(val=='v' || val=='V') val=6; else val-=48;

       if (val<7 &&val>0 && ValDG[val-1].somme>0)
       {    if (val==6)
               {
                   val--;
                   *(s+2)=1;
                   *s+=5*ValDG[5].somme;

                   *(s+1)-=ValDG[5].somme;
                     ValDG[5].somme=-1;
               }
           else
          {*s+=ValDG[val-1].val*ValDG[val-1].somme;
           *(s+1)-=ValDG[val-1].somme;
           ValDG[val-1].somme=-1; }
           po--;
       }
       else if (val<7 &&val>0 && ValDG[val-1].somme==-1)
       {
           printf("la valeur est deja choisi\n\n");
           goto LOOP;
       }
       else {
        printf("vous pouvez pas choisir cette valeur\n\n");
       goto LOOP;
       }
 }
else{
    *s =-1;
    printf("\n votre tour est rate car vous pouvez pas choisi les valeurs lancées\n\n");

}

}
void jouer (int NombreJoueurs){
    Pickominos tableaupicko[16]={{1,NULL},{1,NULL},{1,NULL},{1,NULL},{2,NULL},{2,NULL},{2,NULL},
    {2,NULL},{3,NULL},{3,NULL},{3,NULL},{3,NULL},{4,NULL},{4,NULL},{4,NULL},{4,NULL}};
    FILE* fichier = NULL;
    char touche,s,c;
    int touche1;
    int i=0,fini=0,z=0,re=0,g=1;
   struct tdes ValDG[6]={{1,0},{2,0},{3,0},{4,0},{5,0},{6,0}};
   int t[3]={0,8,0};
   int *Des=(int*)calloc(8, sizeof(int));
   joueurs *joueurs =calloc (NombreJoueurs+1,sizeof(joueurs));
   while (re<2){
    fflush(stdin);
    initializer(t,ValDG);

    printf("le joueurs n %d , c'est a toi de jouer \n\n",i+1);
    printf("si tu veux jouer il faut au moins lancer une fois sinon votre tour est rate\n\n");
    fflush(stdin);
    while (t[0]!=-1 && t[1]!=0){
        printf("voulez-vous lancer ? , taper O si non taper n'importe touche\n\n");
        fflush(stdin);
        scanf("%c",&touche);
        if (touche =='O'||touche=='o') lancer(t,Des,ValDG);
        else goto A;

    }
    A:
     if (t[0]!=-1&&t[2]==1&&t[0]-21>=0)
     {
        z=t[0]-21;
        fini =0;
       while (fini==0 &&z>=0)
{
        if (tableaupicko[z].gagnant==NULL)
            {printf("joueur %d t'as ganger le pickomino %d\n\n",i+1,z+21);
             empiler(&joueurs[i].pu,z);
             tableaupicko[z].gagnant=joueurs+i;
             joueurs[i].dernierval=joueurs[i].pu.premier->nombre;
             joueurs[i].Sommeval+=tableaupicko[z].Valeur;
            fini=1; re++;}
        else if (tableaupicko[z].gagnant->dernierval==z)
            {
             printf("joueur %d t'as volé le pickomino %d de joueur\n\n",i+1,z+21);
             empiler(&joueurs[i].pu,z);
             depiler(&tableaupicko[z].gagnant->pu);
             tableaupicko[z].gagnant->dernierval=tableaupicko[z].gagnant->pu.premier->nombre;
             tableaupicko[z].gagnant->Sommeval-=tableaupicko[z].Valeur;
             tableaupicko[z].gagnant=joueurs+i;
             joueurs[i].Sommeval+=tableaupicko[z].Valeur;
             joueurs[i].dernierval=joueurs[i].pu.premier->nombre;
             fini=1;}
        z--;

       }

     }
    printf("\n\nsi vous voulez sauvgarger la parti ,taper p si non taper autre touche pour continuer le jeu\n\n");
     fflush(stdin);
     scanf("%c",&s);
     if (s=='p'|| s=='P')
     {
     fichier = fopen("sauvgarder.txt","w");
    if (fichier != NULL)
    { c='1';
      fputc(c,fichier);
      c = (char)NombreJoueurs;
      fputc(c,fichier);
      c=(char)re;
      fputc(c,fichier);
      for (int q=0;q<NombreJoueurs;q++)
      {
          c=(char)joueurs[q].dernierval;
         fputc(c,fichier);
          c=(char)joueurs[q].Sommeval;
         fputc(c,fichier);
      }
    return 0;
    }
    else {
        printf("on n 'as pas pu sauvgarder la parti");
    }
    fclose(fichier);

     }

    if (i==NombreJoueurs-1) i=0; else
    i++;
   }

   g =gagnant(joueurs,NombreJoueurs);
  printf("le joueur %d c'est vous le gagnant avec une valeur de %d",g+1,joueurs[g].Sommeval);
}
void lancerRobo(int *s,int*Des,struct tdes *ValDG){
      int max=0,valeur=0;
    srand(time(NULL));
    int i=0,po=0;
    char val,ch;
    printf("\n ");
    for (int z=0;z<*(s+1);z++)
    {
    Des[z]=(rand()%6)+1;
    if (Des[z]==6){ printf("[V]  ");}
    else { printf("[%d]  ",Des[z]);}
    Des[*(s+1)]=-1;
    }

    for(int j=0;j<6;j++)
    {   if (ValDG[j].somme>0) ValDG[j].somme=0;

       while (Des[i]!=-1){
            if (ValDG[j].val==Des[i]&&ValDG[j].somme>=0)  ValDG[j].somme++;
            i++;}
       if (ValDG[j].somme>0) po+=1;
       if (ValDG[j].somme*ValDG[j].val >max)
       {
           max =ValDG[j].somme*ValDG[j].val;
           valeur =ValDG[j].val;
       }
       i=0;
    }
    Sleep(2000);
 if(po>0) {

    if (ValDG[5].somme>0){
        printf("\n\nje choisis la valeur V\n\n");
        *s+=5*ValDG[5].somme;
        *(s+1)-=ValDG[5].somme;
        *(s+2)=1;
         ValDG[5].somme=-1;}
    else  {
        printf("\n\nje choisis la valeur %d\n\n",valeur);
        *s+=valeur*ValDG[valeur-1].somme;
        *(s+1)-=ValDG[valeur-1].somme;
         ValDG[valeur-1].somme=-1; }
          }
else{
    *s =-1;
    printf("\n\n j ai rate car je peux pas choisi les valeurs lancees \n\n");
}

}
void jouerseul(){
    Pickominos tableaupicko[16]={{1,NULL},{1,NULL},{1,NULL},{1,NULL},{2,NULL},{2,NULL},{2,NULL},
    {2,NULL},{3,NULL},{3,NULL},{3,NULL},{3,NULL},{4,NULL},{4,NULL},{4,NULL},{4,NULL}};
    FILE* fichier = NULL;
    char touche,c,s;
    int touche1;
    int i=0,fini=0,z=0,re=0,g=1;
   struct tdes ValDG[6]={{1,0},{2,0},{3,0},{4,0},{5,0},{6,0}};
   int t[3]={0,8,0};
   int *Des=(int*)calloc(8, sizeof(int));
  // printf("\n quelle est le nombre de joueurs\n\n");
  // fflush(stdin);
  // scanf("%d",&NombreJoueurs);

   joueurs *joueurs =calloc (3,sizeof(joueurs));
   while (re<2){
    fflush(stdin);
    initializer(t,ValDG);
  if (i==0)
{

   printf("\n\nc'est a toi de jouer \n\n",i+1);
    printf("si tu veux jouer il faut au moins lancer une fois sinon votre tour est rate\n\n");
    fflush(stdin);
    while (t[0]!=-1 && t[1]!=0){
        printf("voulez-vous lancer ? , taper O si non taper n'importe touche\n\n");
        fflush(stdin);
        scanf("%c",&touche);
        if (touche =='O'||touche=='o') lancer(t,Des,ValDG);
        else goto A;
    }
    }
    else if (i==1) {
    printf("c'est mon tour \n\n");
    while (((t[1]>0 &&t[0]<21) ||t[1]>2) && t[0]!=-1 )
       {
       lancerRobo(t,Des,ValDG);}
       goto A;
    }
    A:
     if (t[0]!=-1&&t[2]==1&&t[0]-21>=0)
     {
        z=t[0]-21;
        fini =0;
       while (fini==0 &&z>=0){
        if (tableaupicko[z].gagnant==NULL)
            { if (i==0)
              {printf("t'as ganger le pickomino %d\n\n",z+21);}
              else {printf("j'ai ganger le pickomino %d\n\n",z+21);}
             empiler(&joueurs[i].pu,z);
             tableaupicko[z].gagnant=joueurs+i;
             joueurs[i].dernierval=joueurs[i].pu.premier->nombre;
             joueurs[i].Sommeval+=tableaupicko[z].Valeur;
            fini=1; re++;}
        else if (tableaupicko[z].gagnant->dernierval==z)
             if (i==0)
              {printf("t'as ganger le pickomino %d\n\n",z+21);}
              else {printf("j'ai ganger le pickomino %d\n\n",z+21);}
             empiler(&joueurs[i].pu,z);
             depiler(&tableaupicko[z].gagnant->pu);
             tableaupicko[z].gagnant->dernierval=tableaupicko[z].gagnant->pu.premier->nombre;
             tableaupicko[z].gagnant->Sommeval-=tableaupicko[z].Valeur;
             tableaupicko[z].gagnant=joueurs+i;
             joueurs[i].Sommeval+=tableaupicko[z].Valeur;
             joueurs[i].dernierval=joueurs[i].pu.premier->nombre;
             fini=1;
        z--;
       }
     }

        if (i==0){
     printf("si vous voulez sauvgarger la parti ,taper p si non taper autre touche pour continuer le jeu\n\n");
     fflush(stdin);
     scanf("%c",&s);
     if (s=='p'|| s=='P')
     {
     fichier = fopen("sauvgarder.txt","w");
    if (fichier != NULL)
     { c='0';
      fputc(c,fichier);
      c=(char)re;
      fputc(c,fichier);
      for (int q=0;q<2;q++)
      {
          c=(char)joueurs[q].dernierval;
         fputc(c,fichier);
          c=(char)joueurs[q].Sommeval;
         fputc(c,fichier);
    }
    fclose(fichier);
    }
    else {
        printf("on n 'as pas pu sauvgarder la parti");
    }
     }
     }

    if (i==0) i=1; else i=0;
   }

   g =gagnant(joueurs,2);
   if (g==0)
   {
 printf("c'est vous le gagnant avec une valeur de %d \n\n",joueurs[g].Sommeval);
   }
   else {
printf("c'est moi le gagnant avec une valeur de %d \n\n",joueurs[g].Sommeval);
   }

}
