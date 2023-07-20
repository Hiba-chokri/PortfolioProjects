#include<stdio.h>
#include <stdlib.h>
#include<time.h>
#include<string.h>
#include<conio.h>
#include<stdbool.h>
#include<windows.h>
                      /*********************************************************************************
					  *                               												   *
					  *              Project by :)                                                     *
					  *	                            ~~Heba Chokri ~~                                   *
					  *                                                                                *
					  *                                                                                *
					  *                                                                                *
					  *                                                                                *
					  *********************************************************************************/

typedef struct voiture{
    int idVoiture;
    char marque[15];
    char nomVoiture[15];
    char couleur[7];
    int nbplaces;
	int prixjour;
    char EnLocation[4];
}voiture;



typedef struct date{
	int j;
	int m;
	int a;
}date;


typedef struct contratLocation{
	float numContrat;
	int idVoiture;
	int idClient;
	date debut;
	date fin;
	int cout;
}contrat;
typedef struct client{
	int idClient;
	char nom[20];
	char prenom[20];
	int cin;
	char adresse[15];
	int telephone;
}client;

voiture v;
client c;
contrat CL;
///////////////////////////////////////////////////////////
void delay(unsigned int mseconds)
{
    clock_t goal = mseconds + clock();
    while (goal > clock());
}
COORD coord = {0,0};
void gotoxy (int x, int y)
{
        coord.X = x; coord.Y = y;
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

////**les fonctions de gestion des voitures*/////////////////////////
///////////////////////////////////
int chercherv(voiture *v, int Id)
 {
  FILE *f;
  f=fopen("voitures.txt","rb");
  	while(fread(v,sizeof(voiture),1,f)==1){
        if(v->idVoiture==Id)
  	   {

  	     return 1;
		 }

  	}
  	     return 0;
 }

void listedesvoitures(){
	 system("cls");
	 int i=0;
	FILE *f=fopen("voitures.txt","rb");
	if(f==NULL){printf("Erreur d'ouverture\n"); exit(1);}
    fseek(f,0,SEEK_SET);
	while(fread(&v,sizeof(voiture),1,f)!=0){
     printf("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");

		printf("la liste des voitures");

		printf("\n Le id de la voiture     : %d",v.idVoiture);
        printf("\n La marque de la voiture : %s",v.marque);
        printf("\n Le nom de la voiture    : %s",v.nomVoiture);
        printf("\n La coleur de la voiture : %s",v.couleur);
        printf("\n Le nombre de place      : %d",v.nbplaces);
        printf("\n Le prix de jour         : %d",v.prixjour);
        printf("\n Location                : %s",v.EnLocation);
        printf("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
	     i++;
		}
		if(i==0){
        printf("*************aucun voiture !!!!******************");
        //sleep(3);
    }
	fseek(f, 0, SEEK_SET);
	fclose(f);
	system("pause");
     system("cls");
}


////////////////////////////////////////////////////////////
void AjouterVoiture(voiture *v)
 {
    system("cls");
    FILE *f=NULL;
    int Id;
    f=fopen("voitures.txt","ab");//ouverture d'un fichier
    if(f==NULL){printf("Erreur d'ouverture\n"); exit(0);}
    else{

        char answer;
        do{
            printf("      *********************************************\n");
            printf("\n\t=>Donner le id de voiture: \n");
            scanf("%d",&v->idVoiture);
            fflush(stdin);
            if(chercherv(v,Id)==1){
                printf("l'Id existe deja essayer d'entrez un autre Id");
                system("Cls");
                AjouterVoiture(v);
            }
            else{
                v->idVoiture==Id;
            printf("\n\t=>Donner la marque de voiture: \n");
            scanf("%s",v->marque);
            fflush(stdin);
            printf("\n\t=>Donnez le nom : \n");
            scanf("%s",v->nomVoiture);
            fflush(stdin);
            printf("Donner la couleur de voiture: \n");
            scanf("%s",v->couleur);
            fflush(stdin);
            printf("\n\t=>Donner la nbr de place de voiture: \n");
            scanf("%d",&v->nbplaces);
            fflush(stdin);
            printf("\n\t=>Donner le prix de jour: \n");
            scanf("%d",&v->prixjour);
            fflush(stdin);
            printf("\n\t=>Est-ce que en locatin(o/n) ??");
            scanf("%s",v->EnLocation);
            fflush(stdin);
            fwrite(v,sizeof(voiture),1,f);
            printf("\n\t=>Voulez-vous ajouter une autre voiture(o/n)?  reponse: ");
            answer=getche();
            printf("\n");
    }
    }while(answer=='o' || answer=='O');
    fclose(f);
    system("cls");
}}
 ////////////////////////////
 void modifierv(){
 	 system("cls");
 	 int Id;
	int aide = 0;
	char reponse;
FILE *f=NULL;
f=fopen("voitures.txt","rb+");
printf("donner le id de voiture :");
scanf("%d",&Id);
 fseek(f, 0, SEEK_SET);
	 while (fread(&v, sizeof(voiture), 1, f) != 0 && aide==0) {
        if (v.idVoiture== Id) {
            aide= 1 ;
            break ;
        }
    }

	   if (aide== 0)  {printf("Cette voiture n'existe pas\n");}
	else {
          fseek(f,-sizeof(voiture),SEEK_CUR);
            v.idVoiture = v.idVoiture ;
			 //fseek(f,-sizeof (voiture),SEEK_CUR) ;
			//struct voiture v;
			//fread(&v,sizeof( voiture),1,f);
			printf("voulez-vous modifier le id(o,n)? reponse=  ");
			scanf("%c",&reponse);
				fflush(stdin);
			if(reponse=='o'  ||  reponse=='O' ){
				printf("nouveau ID de voiture: \n");
				scanf("%d",&v.idVoiture);
				fflush(stdin);
			}
			printf("voulez-vous modifier la marque (o,n)? reponse=  ");
			scanf("%c",&reponse);
				fflush(stdin);
			if(reponse=='o'|| reponse=='O'){
				printf("nouveau Marque de voiture: \n");
				scanf("%s",&v.marque);
				fflush(stdin);
			}
			printf("voulez-vous modifier le nom(o,n)? reponse=  ");
			scanf("%c",&reponse);
				fflush(stdin);
			if(reponse=='o'|| reponse=='O'){
				printf("nouveau Nom de voiture: \n");
				scanf("%s",&v.nomVoiture);
				fflush(stdin);
			}else strcpy(v.nomVoiture,v.nomVoiture) ; printf("\n");
			printf("voulez-vous modifier la couleur(o,n)? reponse=  ");
			scanf("%s",&reponse);
				fflush(stdin);
			if(reponse=='O'|| reponse=='o'){
				printf("nouveau couleur de voiture: \n");
				scanf("%s",&v.couleur);
				fflush(stdin);
			}else strcpy(v.couleur,v.couleur) ; printf("\n");
			printf("voulez-vous modifier le nombre de places(o,n)? reponse=  ");
			scanf("%d",&reponse);
				fflush(stdin);
			if(reponse=='o'|| reponse=='O'){
				printf("nouveau nombre de places voiture: \n");
				scanf("%d",&v.nbplaces);
				fflush(stdin);
			}
			else v.nbplaces,v.nbplaces; printf("\n");
			printf("voulez-vous modifier le prix de jour(o,n)? reponse=  ");
			scanf("%c",&reponse);
				fflush(stdin);
			if(reponse=='O'|| reponse=='o'){
				printf("nouveau prixjour voiture: \n");
				scanf("%d",&v.prixjour);
				fflush(stdin);
			}
			else v.prixjour,v.prixjour; printf("\n");
			printf("voulez-vous modifier la location(o,n)? reponse=  ");
			scanf("%c",&reponse);
				fflush(stdin);
			if(reponse=='o'|| reponse=='O'){
				printf("saisir si en location (oui|non): \n");
				scanf("%s",&v.EnLocation);
				fflush(stdin);
			}
			else strcpy(v.EnLocation,v.EnLocation) ; printf("\n");

			fwrite(&v,sizeof (voiture),1,f);
	}
	 fseek(f, 0, SEEK_SET);
	 system("cls");
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void supprimervoiture(voiture *v){
	 system("cls");
	char rep;
 int Id;
 FILE *f=NULL,*Fich;
 f=fopen("voitures.txt","rb");
 if(f==NULL){printf("Erreur d'ouverture\n"); exit(1);}
 else{
        Fich=fopen("TempGVoiture.txt","wb");
        if(Fich==NULL){printf("\n\n Echec d'ouverture du fichier!!\n\n");
            exit(1);}
        else{
             printf("\n\n\t\t   Entrez le id de voiture que voulez  supprimer : ");
             scanf("%d",&Id);
             fflush(stdin);
             bool id_dedecte=false;
        while(fread(v,sizeof(voiture),1,f)==1){
            if(v->idVoiture==Id){
                id_dedecte=true;
                printf("\n\n => **************///La voiture a ete detect et supprimer avec succes./////**********\n\n");
            }
            else fwrite(v,sizeof(voiture),1,Fich);
        }
        fclose(f);
        fclose(Fich);
        if(id_dedecte==true){
            remove("voitures.txt");
            rename("TempGVoiture.txt","voitures.txt");
        }
        else remove("TempGVoiture.txt");
    }
}

system("cls");
}

/////////////////////*****les fonctions de gestion des clients******///////////////////
void listedesclients(){
	 system("cls");
	 int i=0;
	FILE *f=fopen("clients.txt","rb");
	if(f==NULL){printf("Erreur d'ouverture\n"); exit(1);}
    fseek(f,0,SEEK_SET);
	while(fread(&c,sizeof(client),1,f)!=0){
     printf("\n---------------------------------------\n");

		printf("les listes des clients");

		printf("\n Le id de client     : %d",c.idClient);
        printf("\n le nom de client    : %s",c.nom);
        printf("\n Le prenom de client : %s",c.prenom);
        printf("\n Le cin              : %s",c.cin);
        printf("\n L'adresse de client : %s",c.adresse);
        printf("\n Le num de telephone : %d",c.telephone);
        printf("\n---------------------------------------\n");
	     i++;
		}
		if(i==0){
        printf("aucun client !!!");

    }
	fseek(f, 0, SEEK_SET);
	fclose(f);
	system("pause");
     system("cls");
}

////////////////////////////////////////////////////////////
void Ajouterclient(client *c)
 {
     system("cls");
    FILE *f=NULL;
    f=fopen("clients.txt","ab");//ouverture d'un fichier on mode d'ajoute
    if(f==NULL){printf("Erreur d'ouverture\n"); exit(0);}
    else{
        char answer;
        do{
            printf("      ========================================\n");
            printf("\n\t=>Donner le id de client: \n");
            scanf("%d",&c->idClient);
            printf("\n\t=>Donner le nom de client: \n");
            scanf("%s",c->nom);
            fflush(stdin);
            printf("\n\t=>Donnez le prenom de client : \n");
            scanf("%s",c->prenom);
            fflush(stdin);
            printf("\n\t=>Donner le CIN de client: \n");
            scanf("%d",&c->cin);
            fflush(stdin);
            printf("\n\t=>Donner l'adresse de client: \n");
            gets(c->adresse);
            fflush(stdin);
            printf("\n\t=>Donner le telephone de client: \n");
            scanf("%d",&c->telephone);
            fflush(stdin);
            fwrite(c,sizeof(client),1,f);
            printf("\n\n");
            printf("\n\tVoulez-vous ajouter un autre client(o/n)?  reponse: ");
            answer=getchar();
            printf("\n");
            system("cls");
    }while(answer=='o' || answer=='O');
    fclose(f);
    system("cls");
}
 }
 ////////////////////////////
 void modifierclient(){
 	 system("cls");
 	 int Id;
	int aide = 0;
	char reponse;
FILE *f=NULL;
f=fopen("clients.txt","rb+");
printf("donner le id de client:");
scanf("%d",&Id);
 fseek(f, 0, SEEK_SET);
	 while (fread(&c, sizeof(client), 1, f) != 0 && aide==0) {
        if (c.idClient== Id) {
            aide= 1 ;
            break ;
        }
    }

	   if (aide== 0)  {printf("Ce client n'existe pas\n");}
	else {
         fseek(f,-sizeof(client),SEEK_CUR);
            c.idClient = c.idClient ;
			 //fseek(f,-sizeof (voiture),SEEK_CUR) ;
			//struct voiture v;
			//fread(&v,sizeof( voiture),1,f);
			printf("voulez-vous modifier le id client(o,n)? reponse=  ");
			scanf("%c",&reponse);
				fflush(stdin);
			if(reponse=='o'  ||  reponse=='O' ){
				printf("nouveau ID de client: \n");
				scanf("%d",&c.idClient);
				fflush(stdin);
			}else c.idClient,c.idClient ; printf("\n");
			printf("voulez-vous modifier le nom (o,n)? reponse=  ");
			scanf("%s",&reponse);
				fflush(stdin);
			if(reponse=='o'|| reponse=='O'){
				printf("nouveau nom: \n");
				scanf("%s",&c.nom);
				fflush(stdin);
			}else strcpy(c.nom,c.nom) ; printf("\n");
			printf("voulez-vous modifier le prenom(o,n)? reponse=  ");
			scanf("%s",&reponse);
				fflush(stdin);
			if(reponse=='o'|| reponse=='O'){
				printf("nouveau prenom de client: \n");
				scanf("%s",&c.prenom);
				fflush(stdin);
			}else strcpy(c.prenom,c.prenom) ; printf("\n");
			printf("voulez-vous modifier le cin(o,n)? reponse=  ");
			scanf("%c",&reponse);
				fflush(stdin);
			if(reponse=='O'|| reponse=='o'){
				printf("nouveau cin: \n");
				scanf("%d",&c.cin);
				fflush(stdin);
			}else c.cin,c.cin ; printf("\n");
			printf("voulez-vous modifier l'adresse (o,n)? reponse=  ");
			scanf("%c",&reponse);
				fflush(stdin);
			if(reponse=='o'|| reponse=='O'){
				printf("nouveau adresse: \n");
				scanf("%s",&c.adresse);
				fflush(stdin);
			}
        else strcpy(c.adresse,c.adresse) ; printf("\n");
	     printf("voulez-vous modifier le telephone(o,n)? reponse=  ");
			scanf("%d",&reponse);
				fflush(stdin);
			if(reponse=='O'|| reponse=='o'){
				printf("nouveau telephone: \n");
				scanf("%d",&c.telephone);
				fflush(stdin);
			}
			else c.telephone,c.telephone; printf("\n");

			fwrite(&c,sizeof (client),1,f);
	}
	 fseek(f, 0, SEEK_SET);
	 system("cls");
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void supprimerclient(client *c){
	 system("cls");
	char rep;
 int Id;
 FILE *f=NULL,*Fich;
 f=fopen("clients.txt","rb");
 if(f==NULL){printf("Erreur d'ouverture\n"); exit(1);}
 else{
        Fich=fopen("TempGclient.txt","wb");
        if(Fich==NULL){printf("\n\n Echec d'ouverture du fichier!!\n\n");
            exit(1);}
        else{
             printf("\n\n\t\t   Entrez le id de client que voulez  supprimer : ");
             scanf("%d",&Id);
             fflush(stdin);
             bool id_dedecte=false;
        while(fread(c,sizeof(client),1,f)==1){
            if(c->idClient==Id){
                id_dedecte=true;
                printf("\n\n => Le client a ete detect et supprimer avec succes.\n\n");
            }
            else fwrite(c,sizeof(client),1,Fich);
        }
        fclose(f);
        fclose(Fich);
        if(id_dedecte==true){
            remove("clients.txt");
            rename("TempGclient.txt","clients.txt");
        }
        else remove("TempGclient.txt");
    }
}

//system("cls");
}


//////////////////////////*******les fonctions de location de voiture*********//////////////////////////
void visualise_contrat(){
int num;
int trouve;
  printf("Entrez le numero de contrat que vous Recherchez \n");
  scanf("%d",&num);
  FILE *F;
  F=fopen("contratLocation.txt","rb");//ouverture en mode "read"
  fseek(F,0,SEEK_SET);
  while(fread(&CL,sizeof(contrat),1,F)!=0&&trouve==0){
  	 if(num==CL.numContrat)
  	  {trouve=1;break;}}
  	  if(trouve==0){printf("\n\n -------------------- Ce numero de contrat n'existe Pas !! --------------------\n\n");}
  	  else{fseek(F,-(long)sizeof(contrat),SEEK_CUR);
  	    printf("----------- Information de contrat a Rechercher : -----------\n\n");
  	    printf("le numero de contrat: %d ",&CL.numContrat);
  	    printf("\nle id de voiture  : %d ",CL.idVoiture);
  	    printf("\nle id de client   : %d ",CL.idClient);
  	    printf("\nla date debut     : %d/%d/%d ",CL.debut.j,CL.debut.m,CL.debut.a);
  	    printf("\nla date fin       : %d/%d/%d ",CL.fin.j,CL.fin.m,CL.fin.a);
  	    printf("\nle cout           : %d ",CL.cout);
  	 }fseek(F,0,SEEK_SET);
  	      }
/////////////////////////////*************************************************************
int chercherCL(contrat *CL, int num)
 {
  FILE *f;
  f=fopen("contratLocation.txt","rb");
  	while(fread(&CL,sizeof(contrat),1,f)==1){
        if(CL->numContrat==num)
  	   {

  	     return 1;
		 }

  	}
  	     return 0;
 }

///////////////////////////////////////////////////////////////////////////////////////////////77
	void louer_voiture()
{ int i=0,durloc,reponse,findc=0,findv=0,Id;
char nomclient[20],prenomclient[20];
 FILE* f=NULL;
 FILE* g=NULL;
  FILE* fichectrt=NULL;
     fichectrt=fopen("contratsLocations.txt","ab");
 printf("saisir votre  nom  :\n");
 scanf("%s",&nomclient);
 printf("saisir votre prenom :\n");
 scanf("%s",&prenomclient);
 f=fopen("clients.txt","rb");

 if(f!=NULL)
 {  while(fread(&c,sizeof(client),1,f)==1)
    {
          if(strcmp(c.nom,nomclient)==0&&strcmp(c.prenom,prenomclient)==0){
           findc=1;
             break;
          }
    }
    fclose(f);
    if(findc==0)
    {  printf("************ce nom n'existe pas dans notre liste!!!*******************\n");
         printf("vous voullez ajouter un client? si oui tappez 1 si non tappez 0:\n ");
        scanf("%d",&reponse);
          if(reponse==1){
          f=fopen("clients.txt","ab");
            Ajouterclient(&c);}
    }else{
        char nomVoiture[15],marque[15],couleur[7];
            int nbplaces;
           printf("saisir Idvoiture que vous voulez  :\n");
           scanf("%d",&Id);
            printf("\n\t* La marque : " );
            scanf("%s",marque);
            fflush(stdin);
            printf("\n\t* Le nom de voiture : ");
            scanf("%s",nomVoiture);
            fflush(stdin);
            printf("\n\t* La couleur : ");
            scanf("%s",couleur);
            fflush(stdin);
            printf("\n\t* le nembre de place : ");
            scanf("%d",&nbplaces);
           g=fopen("voitures.txt","rb+");
                     if(g!=NULL)
                     {  while(fread(&v,sizeof(voiture),1,g)==1)
                         {  if (v.idVoiture=Id&&strcmp(v.marque,marque)==0 && strcmp(v.nomVoiture,nomVoiture)==0 && strcmp(v.couleur,couleur)==0 && v.nbplaces==nbplaces)
                            {
                               findv=1;
                                break;
                            }
                        }
                        fclose(f);
                        if(findv==0)
                        {   printf("CE VOITURE N'EXISTE PAS ");
                        }else{
                            if(strcmp(v.EnLocation,"non")==0){
                                strcat(v.EnLocation , "Oui");
                                printf("Cette voiture est disponible .... ");
                                printf("\n ***********Numero de votre contrat :   *****************");
                                scanf("%f",&CL.numContrat);
                                CL.idVoiture=v.idVoiture ;
                                fseek(f,0,SEEK_SET);
                            while(fread(&c,sizeof(client),1,f)==1){
                            if(strcmp(c.nom,nomclient)==0 && strcmp(c.prenom,prenomclient)==0){
                                break;
                            }
                        }
                        CL.idClient=c.idClient ;
                        printf("\n Tu vas prendre la voiture quand ? : ");
                        scanf("%d%d%d" ,&CL.debut.j,&CL.debut.m,&CL.debut.a);
                        printf("\n Jusqu'a : ");
                        scanf("%d %d %d" ,&CL.fin.j,&CL.fin.m,&CL.fin.a);
                       CL.cout = ( CL.fin.j - CL.debut.j ) * v.prixjour ;
                        fwrite (&CL,sizeof(contrat),1,fichectrt);
                          } else{
                            printf("la voiture n'est pas disponible");
                                }

                         }
                          fclose(g);



    fprintf(fichectrt,"\n %f     %d      %d     %d/%d/%d     %d/%d/%d      %d",CL.numContrat,CL.idVoiture,CL.idClient,CL.debut.j,CL.debut.m,CL.debut.a,CL.fin.j,CL.fin.m,CL.fin.a,CL.cout);
     fseek(g, 0, SEEK_SET); fseek(f, 0, SEEK_SET); fseek(fichectrt, 0, SEEK_SET);
    fclose(f);fclose(fichectrt);fclose(g);
}
}
}else { printf("erreur! fichier introuvable \n"); }

}
  void retourner_voiture()/*la fonction retourner voiture comme r�le de supprim� les contrats des voitures qui ont retourn� par les clients et aussi modifier une information concernant la disponibilit� de la voiture retourner c'est � dire la voiture devient disponible. */
{ int i=0,id_vr;
   voiture ch[1000];
   contrat ct[1000];
   FILE* fv=NULL;
   FILE* fc=NULL;
   FILE* tmp1=NULL;
   FILE* tmp2=NULL;
   printf("saisir l'id de voiture retourner :\n");
   scanf("%d",&id_vr);
   fv=fopen("voitures.txt","rb");
   tmp1=fopen("filevr.txt","wb");
   if(fv!=NULL)
   {   while(fread(&v,sizeof(voiture),1,fv)==1)
        {
             if(v.idVoiture==id_vr)
                   {
                         strcpy(v.EnLocation,"non");

                   }

        }
    fclose(fv);
    fclose(tmp1);
    remove("voitures");
    rename("filevr","voitures");
   }
   else
   { printf("erreur! fichier introuvable\n ");
   }
 fc=fopen("contratsLocations","r");
tmp2=fopen("filectrt1","w");
 if(fc!=NULL)
 {  while(i<1000 && !feof(fc))
      {
          fscanf(fc,"\n %f %d %d %d/%d/%d  %d/%d/%d  %d",&CL.numContrat,&CL.idVoiture,&CL.idClient,&CL.debut.j,&CL.debut.m,&CL.debut.a,&CL.fin.j,&CL.fin.m,&CL.fin.a,&CL.cout);
          if(ct[i].idVoiture!=id_vr)
          {
              fprintf(tmp2,"\n %f %d %d %d/%d/%d  %d/%d/%d  %d",CL.numContrat,CL.idVoiture,CL.idClient,CL.debut.j,CL.debut.m,CL.debut.a,CL.fin.j,CL.fin.m,CL.fin.a,CL.cout);
          }
          i++;
      }
      fclose(fc);
      fclose(tmp2);
      remove("ContratsLocations.txt");
      rename("filectrt1","contratsLocations");
 }
 else
    {
      printf("erreur ! fichier introuvable");
   }
}
//////////////////////////////////////7
void modifier_contrat()
 {
 char rep;
 int num;
 printf("\n\n\t\t     entrer le numero de contrat a Modifier : ");
 scanf("%f",num);
 printf("\n\n\t\t     Voulez-vous vraiment Modifier O/N ? ");
 printf("\n\n\t\t   O:oui                               N:Non  ");
 printf("\n\n\t\t             Votre choix : ");
 scanf("%c",&rep);
 fflush(stdin);
 if(chercherCL(&CL,num)==1)
   {
   	printf("\nVoulez vous vraiment Modifier O/N ?");
   	scanf("%c",&rep);
   	fflush(stdin);
   	if(rep=='O' || rep=='o')
   	 {
   	  FILE *F,*Fich;
	  F=fopen("voitures,txt","rb");
	  Fich=fopen("TempLVoiture.txt","ab");
	  while(fread(&CL,sizeof(contrat),1,F)==1){
	  	if(num==CL.numContrat)
	  	  {
	  	    printf("\nEntrer le nouveau numero de Contrat :");
            scanf("%d",&CL.numContrat);
            fflush(stdin);
            printf("\nEntrer le nouveau id de voiture :");
            scanf("%d",&CL.idVoiture);
            fflush(stdin);
            printf("\nEntrer le nouveau id de client :");
            scanf("%d",&CL.idClient);
            fflush(stdin);
            printf("\nEntrer le nouveau date debut (jj/MM/AAAA) :");
            scanf("%d",&CL.debut.j);printf("/");
            scanf("%d",&CL.debut.m);printf("/");
            scanf("%d",&CL.debut.a);
            fflush(stdin);
            printf("\nEntrer le nouveau date de fin (jj/mm/AAAA) :");
            scanf("%d",&CL.fin.j);printf("/");
            scanf("%d",&CL.fin.m);printf("/");
            scanf("%d",&CL.fin.a);
            fflush(stdin);
            printf("\nEntrer le nouveau cout :");
            scanf("%d",&CL.cout);
            fflush(stdin);
		  }
	}
	   fclose(Fich);
	   fclose(F);
	   remove("voitures.txt");
	   rename("TempLVoiture.txt","voitures.txt");
	   printf("\nModification a Reusi!!");
	 }
   }
 else
   {
   system("cls");
   printf("\n\n -------------------- Ce id de voiture n'existe Pas !! --------------------");
   modifier_contrat();
   }
}
//////////////////////////////////7777
void supprimer_contrat(){

 system("cls");

 int num;
 FILE *f=NULL,*Fich;
 f=fopen("contratLocation.txt","rb");
 if(f==NULL){printf("Erreur d'ouverture\n"); exit(1);}
 else{
        Fich=fopen("TempGL.txt","wb");
        if(Fich==NULL){printf("\n\n Echec d'ouverture du fichier!!\n\n");
            exit(1);}
        else{
             printf("\n\n\t\t   Entrez le num de contrat que voulez  supprimer : ");
             scanf("%d",&num);
             fflush(stdin);
             bool num_dedecte=false;
        while(fread(&CL,sizeof(contrat),1,f)==!0){
            if(CL.numContrat==num){
                num_dedecte=true;
                printf("\n\n => **************///La contrat a ete detect et supprimer avec succes./////**********\n\n");
            }
            else fwrite(&CL,sizeof(contrat),1,Fich);
        }
        fclose(f);
        fclose(Fich);
        if(num_dedecte==true){
            remove("contratLocation.txt");
            rename("TempGL.txt","contratLocation.txt");
        }
        else remove("TempGL.txt");
    }
}

system("cls");
}


  ////////////////////////////////////////////////////////////////////////
  	MenuPrincipal(){
	  system("cls");
    int choix;



	printf("\n                                                                                   \xda\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xbf");
	printf("\n                                                                                   \xb3 Menu Principal  \xb3");
	printf("\n                                                                                   \xc0\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xd9");

    printf("\n\n");

    printf("\n                                                                      \xc9\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xbb");
    printf("\n                                                                      \xba                                              \xba");
    printf("\n                                                                      \xba    Location..............................1   \xba");
    printf("\n                                                                      \xba    Gestion voitures......................2   \xba");
    printf("\n                                                                      \xba    Gestion clients.......................3   \xba");
    printf("\n                                                                      \xba    Quitter...............................4   \xba");
    printf("\n                                                                      \xba                                              \xba");
    printf("\n                                                                      \xc8\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xbc");
    printf("\n\n                                                                                      Votre choix  :  ");

    scanf("%d",&choix);
 return choix;

}

  ///////////////////////////////////////////
  int gestiondesvoitures()
	{
	 system("cls");
    int choix;

	printf("\n                                                                                 \xda\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xbf");
	printf("\n                                                                                 \xb3 Gestion des voitures \xb3");
	printf("\n                                                                                 \xc0\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xd9");

    printf("\n\n");

    printf("\n                                                                      \xc9\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xbb");
    printf("\n                                                                      \xba                                              \xba");
    printf("\n                                                                      \xba    Liste des voitures....................1   \xba");
    printf("\n                                                                      \xba    Ajouter voiture.......................2   \xba");
    printf("\n                                                                      \xba    Modifier voiture......................3   \xba");
    printf("\n                                                                      \xba    Supprimer voiture.....................4   \xba");
    printf("\n                                                                      \xba    Retour................................5   \xba");
    printf("\n                                                                      \xba                                              \xba");
    printf("\n                                                                      \xc8\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xbc");
    printf("\n\n                                                                                     Votre choix  :  ");
    scanf("%d",&choix);
    return choix;

}
/////////////////////////////////////////77777
int gestiondesclients(){
	  system("cls");
	 int choix;

	printf("\n                                                                                   \xda\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xbf");
	printf("\n                                                                                   \xb3 Gestion des clients \xb3");
	printf("\n                                                                                   \xc0\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xd9");

    printf("\n\n");

    printf("\n                                                                      \xc9\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xbb");
    printf("\n                                                                      \xba                                              \xba");
    printf("\n                                                                      \xba    Liste des clients.....................1   \xba");
    printf("\n                                                                      \xba    Ajouter client........................2   \xba");
    printf("\n                                                                      \xba    Modifier client.......................3   \xba");
    printf("\n                                                                      \xba    Supprimer client......................4   \xba");
    printf("\n                                                                      \xba    Retour................................5   \xba");
    printf("\n                                                                      \xba                                              \xba");
    printf("\n                                                                      \xc8\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xbc");
    printf("\n\n                                                                                     Votre choix  :  ");

    scanf("%d",&choix);
    return choix;
      system("pause");
}
//////////////////////////_____________Location d'une voiture_____/////////////
int Location()
{
 system("cls");
    int choix;


	printf("\n                                                                                 \xda\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xbf");
	printf("\n                                                                                 \xb3 Location d'une voiture  \xb3");
	printf("\n                                                                                 \xc0\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xd9");

    printf("\n\n");

    printf("\n                                                                       \xc9\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xbb");
    printf("\n                                                                       \xba                                              \xba");
    printf("\n                                                                       \xba    Visualiser contrat...................1    \xba");
    printf("\n                                                                       \xba    Louer voiture........................2    \xba");
    printf("\n                                                                       \xba    Retourner voiture....................3    \xba");
    printf("\n                                                                       \xba    Modifier contrat.....................4    \xba");
    printf("\n                                                                       \xba    Supprimer contrat....................5    \xba");
    printf("\n                                                                       \xba    Retour...............................6    \xba");
    printf("\n                                                                       \xba                                              \xba");
    printf("\n                                                                       \xc8\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xbc");
    printf("\n\n                                                                                     Votre choix  :  ");

    scanf("%d",&choix);
  return choix;

}

/////////////////////////////////////////////////////////////////////////////////////////////////////////
int retour()
{
 int n;
 printf("\n\n ----------------- Voulez-vous retourner au Menu Principal ou Menu Precedent ? -----------------");
 printf("\n\n                0:Menu principal                                  1:Menu precedent ");
 printf("\n\n                                      votre choix :  ");
 scanf("%d",&n);
 return n;
}
char Quitter()
{
 char q;
 printf("\n\n\n\t\t    Voulez-vous vraiment Quitter O/N ? ");
 printf("\n\n\n\t\t  O:oui                               N:Non  ");
 printf("\n\n\n\t\t            Votre choix : ");
 scanf("%c",&q);
 scanf("%c",&q);
 return q;
}
////////////////////////////////////////////////
int main(){
	int choix;
	 char nmu[17];
	  int mdp;
	do{system("color f3");
      char GLV[25]="LOCATION DE VOITURE";
    int i;
    gotoxy(18,5);
    for(i=0;i<15;i++)
   {
   delay(30);
   printf("\xB2");
   }
   for(i=0;i<18;i++)
   {
   delay(5);
   printf("%c",GLV[i]);
   }
   for(i=0;i<15;i++)
   {
   delay(30);
   printf("\xB2");}
    gotoxy(14,10);
    printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\n");
    gotoxy(14,11);
    printf("\xB2\xB2\t\t\t\xB2\xB2\t\t\t   \xB2\xB2");
    gotoxy(14,13);
    printf("\xB2\xB2\t\t\t\xB2\xB2\t\t\t   \xB2\xB2");
    gotoxy(14,12);
    printf("\xB2\xB2   Nom d'utilisateur:   \xB2\xB2\t\t\t   \xB2\xB2");
    gotoxy(14,14);
    printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
    gotoxy(14,15);
    printf("\xB2\xB2\t\t\t\xB2\xB2\t\t\t   \xB2\xB2");
    gotoxy(14,16);
    printf("\xB2\xB2     Mot de passe:\t\xB2\xB2\t\t\t   \xB2\xB2");
    gotoxy(14,17);
    printf("\xB2\xB2\t\t\t\xB2\xB2\t\t\t   \xB2\xB2");
    gotoxy(14,18);
    printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
    gotoxy(53,12);
    scanf("%s",&nmu);
    gotoxy(53,16);
    scanf("%d",&mdp);
        if(mdp!=0000){

        printf("* ERREUR EN NIVEAU DE MOT DE PASS ");
        printf("* SAISIR ENTRER POUR RESSAYER ...");
        getch();system("cls");}
      }while(mdp!=0000);


     printf("\n");
      printf("\n Salut < %s > votre program va lancer en 2 sc ...",nmu);
      delay(2000);

	/////////////////
	int a,b,j,d,n;
char q;
menu:
system("cls");
a=MenuPrincipal();
switch(a)
 {
  case 1:
   VC:
   system("cls");
   b=Location();
   switch(b)
     {
       case 1:
       	system("cls");
       	visualise_contrat();
       	n=retour();
       	if(n)
       	 goto VC;
       	goto menu;
	    break;
	   case 2:
	   	system("cls");
	    louer_voiture();
	    n=retour();
	    if(n)
       	 goto VC;
       	goto menu;
		break;
	   case 3:
	   	system("cls");
	   	//RetournerVoiture();
	   	n=retour();
	   	if(n)
       	 goto VC;
       	goto menu;
	    break;
       case 4:
       	system("cls");
       	modifier_contrat();
       	n=retour();
       	if(n)
       	 goto VC;
       	goto menu;
	    break;
	   case 5:
	   	system("cls");
	   	supprimer_contrat();
	   	n=retour();
	   	if(n)
       	 goto VC;
       	goto menu;
	    break;
	   case 6:
	   	system("cls");
	   	goto menu;
	    break;
	  }
   break;

  case 2:
   GV:
   system("cls");
   j=gestiondesvoitures();
   switch(j)
        {
       case 1:
       	system("cls");
       	listedesvoitures();
       	n=retour();
	   	if(n)
       	 goto GV;
       	goto menu;
	    break;
	   case 2:
	   	system("cls");
	    AjouterVoiture(&v);
	    n=retour();
	   	if(n)
       	 goto GV;
       	goto menu;
		break;
	   case 3:
	   	system("cls");
	   	modifierv();
	   	n=retour();
	   	if(n)
       	 goto GV;
       	goto menu;
	    break;
       case 4:
       	system("cls");
       	supprimervoiture(&v);
       	n=retour();
	   	if(n)
       	 goto GV;
       	goto menu;
	    break;
	   case 5:
	   	system("cls");
	    goto menu;
	    break;
	  }
   break;

  case 3:
   GC:
   system("cls");
   d=gestiondesclients();
   switch(d)
        {
       case 1:
       	system("cls");
       	listedesclients();
       	n=retour();
	   	if(n)
       	 goto GC;
       	goto menu;
	    break;
	   case 2:
	   	system("cls");
	    Ajouterclient(&c);
	    n=retour();
	   	if(n)
       	 goto GC;
       	goto menu;
		break;
	   case 3:
	   	system("cls");
	   	modifierclient();
	   	n=retour();
	   	if(n)
       	 goto GC;
       	goto menu;
	    break;
       case 4:
       	system("cls");
       	supprimerclient(&c);
       	n=retour();
	   	if(n)
       	 goto GC;
       	goto menu;
	    break;
	   case 5:
	   	system("cls");
	   	goto menu;
	    break;
	  }
   break;

  case 4:
   Q:
   q=Quitter();
   if(q=='O' || q=='o')
      system("exit");
   else if(q=='N' || q=='n')
     {
  	  system("cls");
	  goto menu;
	  }
   else
     {
      system("cls");
 	  printf("\n\n\n\t\t Vous devez saisir O pour Oui ou N pour Non !!\n\n");
      goto Q;
	  }

    break;

  default :
  system("cls");
  	 printf("\n\n\t\t s'il vous pla�t saisir un nombre entre 1 et 4 !!\n\n");
  	 goto menu;
 }}


