#include <stdio.h>
#include <stdlib.h>
#include "mes_fcts.h"
PERSONNEL saisie_personnel()
{
    PERSONNEL p;
    printf("\n saisir le nom ");
    scanf("%s",&p.nom);
    printf("\n saisir le prenom ");
    scanf("%s",&p.prenom);
    printf("\n saisir le numero de telephone ");
    scanf("%s",&p.num_pesonnel);
    printf("\n saisir le poste ");
    scanf("%s",&p.poste);
    printf("\n saisir son adresse ");
    scanf("%s",&p.adresse_personnel);
    return p;
}
void affichage_personnel(PERSONNEL p)
{
    printf("\n le nom du personnel est %s",p.nom);
    printf("\n son prenom est %s",p.prenom);
    printf("\n le numero de personnel est %s",p.num_pesonnel);
    printf("\n le poste est %s",p.poste);
    printf("\n l'adresse est %s",p.adresse_personnel);

}
PRESTATION saisie_prestation()
{
    PRESTATION pres;
    printf("\n saisir la destination");
    scanf("%s",&pres.destination);
    printf("\n saisir la date de debut");
    scanf("%d%d%d",&pres.datedebut.jour,&pres.datedebut.mois,&pres.datedebut.annee);
    printf("\n saisir la date de fin");
    scanf("%d%d%d",&pres.datefin.jour,&pres.datefin.mois,&pres.datefin.annee);
    printf("\n saisir  le nbre de places ");
    scanf("%d",&pres.nbre_places);
    printf("\n saisir le type de voyage");
    scanf("%s",&pres.typeVoyage);
    printf("\n entrer la description");
    int count=0;
    char x;
    while((x=getchar())!='#')
    {

        pres.description[count]=x;
    count++;
    }
    pres.long_description=count;
    printf("\n saisir le prix ");
    scanf("%f ",&pres.prix);
 return pres;

}

void affichage_prestation(PRESTATION pres)
{
     printf("\n la destination est %s",pres.destination);
     printf("\n la date de debut est %d/%d/%d",pres.datedebut.jour,pres.datedebut.mois,pres.datedebut.annee);
     printf("\n la date de fin est %d/%d/%d",pres.datefin.jour,pres.datefin.mois,pres.datefin.annee);
     printf("\n le nbre de places est %d",pres.nbre_places);
     printf("\n le type de voyage est %s",pres.typeVoyage);
     printf("\n la description est ");
     for( int i =0 ;i<pres.long_description;i++)
        printf("%c",pres.description[i]);

    printf("\n le prix est %f ",pres.prix);



}



CLIENT saisie_client()
{
    CLIENT cl;
    printf("\n saisir le nom du client ");
    scanf("%s",&cl.nom_cl);
    printf("\n saisir le prenom du client ");
    scanf("%s",&cl.prenom_cl);
    printf("\n saisir le numero du client ");
    scanf("%s",&cl.num_cl);
    printf("\n saisir l'adresse du client ");
    scanf("%s",&cl.adresse_cl);
    printf("\n saisir le code du client ");
    scanf("%d",&cl.cin_cl);
    printf("\n saisir le passeport  du client ");
    scanf("%s",&cl.passeport);
     printf("saisir l etat civil ");
    scanf("%d",&cl.etat_civil);
    printf("\n saisir le num carte bancaire du client ");
    scanf("%s",&cl.num_carte_bancaire);
    printf("\n saisir la reservation");
    cl.reservation=saisie_prestation();
    return cl;

}

void affichage_client(CLIENT cl )
{
     printf("\n  le nom du client ");
    printf("%s",cl.nom_cl);
    printf("\n  le prenom du client ");
    printf("%s",cl.prenom_cl);
    printf("\n  le numero du client ");
    printf("%s",cl.num_cl);
    printf("\n  l'adresse du client ");
    printf("%s",cl.adresse_cl);
    printf("\n  le code du client ");
    printf("%s",cl.cin_cl);
    printf("\n le passeport  du client ");
    printf("%s",cl.passeport);
    printf("\n le num carte bancaire du client ");
    printf("%s",cl.num_carte_bancaire);
    printf("l etat civil ");
    if(cl.etat_civil==0)
    printf("\n celibataire  ");
    else if(cl.etat_civil==1)
    printf("\n marié  ");
    printf("\n  la reservation");
    affichage_prestation(cl.reservation);


}
PRESTATION* allocation_pres(int n )
{
    PRESTATION* p ;
    p=(PRESTATION* ) malloc (n * sizeof(PRESTATION));
    if(!p) exit(-1);
    return p ;

}
void remplir_tab_prest (PRESTATION* p , int n  )
{
    for(int i=0; i<n ; i++)
    *(p+i)=saisie_prestation();
}
void afficher_tab_prest (PRESTATION* p , int n  )
 {
     for(int i=0; i<n ; i++)
         affichage_prestation(*(p+i));
 }
AGENCE saisie_agence()
{
    AGENCE agc;
    printf("\n saisir le nom d'agence ");
    scanf("%s",&agc.nom_agence);
    printf("\n saisir son adresse ");
    scanf("%s",&agc.adresse);
    printf("\n saisir son numero ");
    scanf("%s",&agc.num_agence);
    printf("\n saisir le nbre de personnel");
    scanf("%d",&agc.nbpersonnel);
    agc.tab_personnels=(PERSONNEL*)malloc(agc.nbpersonnel*sizeof(PERSONNEL));
    if(!agc.tab_personnels) exit(-1);

    for(int i=0;i<agc.nbpersonnel;i++)
    {
        printf("\n saisir le personnel");
        *(agc.tab_personnels+i)=saisie_personnel();
    }
    printf("\n saisir le nbre de clients ");
    scanf("%d",&agc.nbclients);
    agc.tab_clients=(CLIENT*)malloc(agc.nbclients*sizeof(CLIENT));
    if(!agc.tab_clients) exit(-1);
    for(int i=0;i<agc.nbclients;i++)
    *(agc.tab_clients+i)=saisie_client();
    printf("\n saisir le nombre d offres ");
    scanf("%d", &agc.nb_offres);
    agc.offres=(PRESTATION*)malloc(agc.nb_offres*sizeof(PRESTATION));
    if(!agc.offres) exit(-1);
   remplir_tab_prest( agc.offres,agc.nb_offres);

    return agc;

}
void affichage_agence(AGENCE agc )
{
    printf("\n le nom de l agence est %s",agc.nom_agence);
    printf("\n l adresse : %s",agc.adresse);
    printf("\n le numéro de téléphone de l agence est %s",agc.num_agence);
     printf("le nombre de personnel : %d",agc.nbpersonnel);
     printf("\n les  offres  : ");
    for(int i=0;i<agc.nb_offres;i++);
       afficher_tab_prest(agc.offres,agc.nb_offres);
     printf("\n  les personnels  : ");
     for(int i=0;i<agc.nbpersonnel;i++)
        affichage_personnel(*(agc.tab_personnels+i));
    printf("\n le nbre de clients : ");
     printf("%d",agc.nbclients);
      printf("\n les  clients : ");
    for(int i=0;i<agc.nbclients;i++)
        affichage_client( *(agc.tab_clients+i));


}
void rech_destination(PRESTATION*p , int n , char dest)
{
    int i;
    for( i =0 ; i<n ; i++)
    {
        if( (p+i)->destination==dest)
            affichage_prestation(*(p+i));
        printf("\n la destination n'est pas disponible pour le moment");


    }

}

DATE saisie_date()
{
    DATE d ;
    printf("saisir date");
    scanf("%d%d%d",&d.jour , &d.mois, &d.annee);
    return d ;
}
void rech_date(PRESTATION* p , int n , DATE d)
{

    for(int i =0; i<n ; i++)
    {
        if(((p+i)->datedebut.jour==d.jour)&&( (p+i)->datedebut.mois==d.mois)&&( (p+i)->datedebut.annee==d.annee) )
            affichage_prestation(*(p+i));
        printf("\n pas d'offre pendant cette datte là");


    }
}

void tri_prix(PRESTATION* p, int n )
{
   int max,i,j;
   PRESTATION temp;
   for(i=0;i<n;i++)
   {
       max=i;
       for(j=1;j<n;j++)
        if( (p+j)->prix > (p+max)->prix )
           max=j;
            temp=*(p+i);
            *(p+i)=*(p+max);
            *(p+max)=temp;
   }
}


void rech_prix(PRESTATION* p , int n , float prix_min  , float prix_max )
{
       for(int i =0; i<n ; i++)
    {
        if ( ((p+i)->prix > prix_min) && ((p+i)->prix < prix_max) )
            affichage_prestation(*(p+i));

    }



}

void rech_type_voyage(PRESTATION* p , int n ,char voyage )
{

       for(int i =0; i<n ; i++)
    {
        if ((p+i)->typeVoyage == voyage )
            affichage_prestation(*(p+i));

    }

}

void modifier_reservation(CLIENT cl ,int choix )
{
    PRESTATION p ;
    if (choix==1)
    {
        printf("\ annulation de la reservation");
        cl.reservation=p ;

    }
    else if (choix==2)
    {
        printf("\ modification de la reservation");
        cl.reservation=saisie_prestation();

    }
}
float remise( CLIENT c )
{

    int nb_enfants;
    if (c.etat_civil==1)
    {
        printf("\n saisir le nombre d enfants ");
        scanf("%d",&nb_enfants);
        if ((nb_enfants==0 )||(nb_enfants==1 ))
        c.reservation.prix=(c.reservation.prix*5)/100;
        else

           c.reservation.prix=(c.reservation.prix*5*nb_enfants)/100;

    }
}

void creeFichierAgence(FILE**fp)
{
    *fp=fopen("D:\\agencedevoyage","wb+");
    if(!*fp) exit(-1);
}

void remplirFichierAgence(FILE*fp)
{
    AGENCE agc;
    do
    {
        agc=saisie_agence();
        if(agc.nbclients!=0)
        {
            fwrite(&agc.nom_agence,sizeof(char),1,fp);
            fwrite(&agc.adresse,sizeof(char),1,fp);
            fwrite(&agc.num_agence,sizeof(char),1,fp);
            fwrite(&agc.nbclients,sizeof(int),1,fp);
            fwrite(&agc.nbpersonnel,sizeof(int),1,fp);
            fwrite(&agc.nb_offres,sizeof(int),1,fp);
            fwrite(agc.tab_personnels,sizeof(PERSONNEL),agc.nbpersonnel,fp);

            fwrite(agc.tab_clients,sizeof(CLIENT),agc.nbclients,fp);
            fwrite(agc.offres,sizeof(PRESTATION),agc.nb_offres,fp);

        }
    }
    while(agc.nbclients!=0);
}
void afficherFichierAgence(FILE*fp)
{
    AGENCE agc;
    rewind(fp);
    while(1)
    {
        fread(&agc.nom_agence,sizeof(char),1,fp);
        if(feof(fp)) break;
        fread(&agc.adresse,sizeof(char),1,fp);
        fread(&agc.num_agence,sizeof(char),1,fp);
        fread(&agc.nbclients,sizeof(int),1,fp);
        fread(&agc.nbpersonnel,sizeof(int),1,fp);
        fread(&agc.nb_offres,sizeof(int),1,fp);
        agc.tab_personnels=(PERSONNEL*)malloc(agc.nbpersonnel*sizeof(PERSONNEL));
        if(!agc.tab_personnels) exit(-1);
        fread(agc.tab_personnels,sizeof(PERSONNEL),agc.nbpersonnel,fp);
        agc.tab_clients=(CLIENT*)malloc(agc.nbclients*sizeof(CLIENT));
        if(!agc.tab_clients) exit(-2);
        fread(agc.tab_clients,sizeof(CLIENT),agc.nbclients,fp);
        agc.offres=(PRESTATION*)malloc(agc.nb_offres*sizeof(PRESTATION));
        if(!agc.offres) exit(-3);
        fread(agc.offres,sizeof(PRESTATION),agc.nb_offres,fp);
        affichage_agence(agc);
    }
}
