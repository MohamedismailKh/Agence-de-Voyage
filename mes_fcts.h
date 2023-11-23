#ifndef MES_FCTS_H_INCLUDED
#define MES_FCTS_H_INCLUDED
#include<stdio.h>
#include <stdlib.h>
#include"mes_fcts.h"
struct date
{
    int jour;
    int mois;
    int annee;

};
typedef struct date DATE ;


struct prestation
{
    char destination[20];
    DATE datedebut;
    DATE datefin ;
    int nbre_places ;
    char description[30];
    float prix;
    char  typeVoyage[20];

};
typedef struct prestation PRESTATION ;



struct client
{
    char prenom_cl[20];
    char nom_cl[20];
    char num_cl [20];
    char adresse_cl[30];
    char cin_cl[10];
    char passeport[20];
    char num_carte_bancaire[20];
    int etat_civil;
    PRESTATION reservation ;

};
typedef struct client CLIENT ;



struct personnel
{
char prenom[20];
char nom[20];
char num_pesonnel [20];
char poste[20];
char adresse_personnel[30];
};
typedef struct personnel PERSONNEL;



struct agence
{
    char nom_agence[20] ;
    char adresse[30];
    int nbpersonnel;
    PERSONNEL* tab_personnels ;
    char num_agence[10];
    int nbclients;
    CLIENT* tab_clients;
    int nb_offres;
    PRESTATION* offres;
};
typedef struct agence AGENCE ;

PERSONNEL saisie_personnel();
void affichage_personnel(PERSONNEL);
AGENCE saisie_agence();
void affichage_agence(AGENCE);
PRESTATION saisie_prestation();
void affichage_prestation(PRESTATION);
CLIENT saisie_client();
void affichage_client(CLIENT);
PRESTATION* allocation_pres(int);
void remplir_tab_prest (PRESTATION* , int );
void afficher_tab_prest (PRESTATION*  , int  );
void rech_destination(PRESTATION* , int , char );
DATE saisie_date();
void rech_date(PRESTATION* , int , DATE);
void tri_prix(PRESTATION*, int );
void rech_prix(PRESTATION* , int , float , float );
void rech_type_voyage(PRESTATION* , int ,char );
void modifier_reservation(CLIENT ,int );
float remise(CLIENT);
void creeFichierAgence(FILE**);
void remplirFichierAgence(FILE*);
void afficherFichierAgence(FILE*);

#endif // MES_FCTS_H_INCLUDED
