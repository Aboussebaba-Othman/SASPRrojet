#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct etudiant {
    int num;
    char nom[30];
    char prenom[30];
    char date_naissance[30];
    char departement[30];
    float Note_generale;


};
struct etudiant etudiants[100];

void menu(){
    int choix;
    do{
        printf("------- MENU-----------\n");
        printf("1 : Ajouter un etudiant\n");
        printf("2 : Modifier un etudiant\n");
        printf("3 : supprimer un etudiant\n");
        printf("4 : Afficher les details d'un etudiant \n");
        printf("5 : Calculer la moyenne generale \n");
        printf("6 : Statistiques\n");
        printf("7 : Trier un etudiant\n");
        printf(" choisir votre choix :");
        scanf("%d",&choix);

        switch(choix){
            case 1:
                ajeuter();
            break;
            case 2:
                Modifier();
                break;
            case 3:
                supprimer();
                break;
            case 4:
                affichage();
                break;
            case 5:
                moyen_generale();
                break;
            case 6:
                Statistiques();
                break;

        }
    }while(choix != 7);

}
int nbr_etudiants = 0;
int id =0;
void ajeuter(){
    printf("enter les informations de etudiant :\n");

    printf("entre le nom de etudiant:\t");
    scanf(" %[^\n]s",etudiants[nbr_etudiants].nom);

    printf("entre le prenom de etudiant:\t");
    scanf(" %[^\n]s",etudiants[nbr_etudiants].prenom);

    printf("entre la date_naissance:\t");
    scanf(" %[^\n]s",&etudiants[nbr_etudiants].date_naissance);

    printf("entre le departement:\t");
    scanf(" %[^\n]s",&etudiants[nbr_etudiants].departement);

    printf("entre la note generale:\t");
    scanf("%f",&etudiants[nbr_etudiants].Note_generale);
    etudiants[nbr_etudiants].num = ++id;
    nbr_etudiants++;


}

void Modifier(){
    int choix,num_modifier;
    printf("entre le num de etudiant qui modifier:");
    scanf("%d",&num_modifier);
    for(int i=0;i<nbr_etudiants;i++){
        if(num_modifier==etudiants[i].num){
            printf("1: modifier le nom :%s\n",etudiants[i].nom);
            printf("2: modifier le prenom :%s\n",etudiants[i].prenom);
            printf("3: modifier la date_naissance :%s\n",etudiants[i].date_naissance);
            printf("4: modifier le departement :%s\n",etudiants[i].departement);
            printf("5: modifier la Note_generale :%f\n",etudiants[i].Note_generale);
            printf("choisir voitre choix :");
            scanf("%d",&choix);

        switch(choix){

        case 1:
            printf("modifier le nom de etudiant:\t");
            scanf(" %[^\n]s",etudiants[i].nom);
            break;
        case 2:
            printf("modifier le prenom de etudiant:\t");
            scanf(" %[^\n]s",etudiants[i].prenom);
            break;
        case 3:
            printf("modifierla date_naissance:\t");
            scanf(" %[^\n]s",&etudiants[i].date_naissance);
            break;
        case 4:
            printf("modifier le departement:\t");
            scanf(" %[^\n]s",&etudiants[i].departement);
            break;
        case 5:
            printf("modifier la note general de etudiant:\t");
            scanf("%f",&etudiants[i].Note_generale);
            break;


        }
        }

    }
}
int num_etudiant_suprime;
void supprimer(){


    int exest = 0;
    printf("entre le num de etudiant qui seprimer\n");
    scanf("%d",&num_etudiant_suprime);
        for(int i=0;i<nbr_etudiants;i++){
            if(num_etudiant_suprime==etudiants[i].num){
                for(int j=i;i<nbr_etudiants;i++){
                    etudiants[j] = etudiants[j+1];

                    exest++;
                    printf("le etudiant est supprimer .\n");
                }
                nbr_etudiants--;

            }
        }
        if(!exest){
            printf("errur");
        }
}



void affichage(){
        printf("les informations complètes des étudiants est:\n");
        for(int i=0;i<nbr_etudiants;i++){
            printf("num  :%d\n",etudiants[i].num);
            printf("le nom :%s\n",etudiants[i].nom);
            printf("le prenom :%s\n",etudiants[i].prenom);
            printf("date_naissance :%s\n",etudiants[i].date_naissance);
            printf("departement :%s\n",etudiants[i].departement);
            printf("Note_generale :%f\n",etudiants[i].Note_generale);
            printf("------------------------\n");

        }

}
void moyen_generale(){
   char T[20][50];
   int countDep;
  for (int i = 0; i < nbr_etudiants; i++){
    int alreadyPrinted = 0;
    for (int j = 0; j < i; j++){
      if (strcmp(etudiants[i].departement, etudiants[j].departement) == 0){
        alreadyPrinted = 1;
        break;
      }
    }
    if (!alreadyPrinted){
      printf("%s\n", etudiants[i].departement);
      strcpy(T[countDep], etudiants[i].departement);
      countDep++;
    }
  }

  for (int i = 0; i < countDep; i++){
    float somme = 0;
    int lengthDep = 0;

    for (int j = 0; j < nbr_etudiants; j++){
      if (strcmp(T[i], etudiants[j].departement) == 0){
        somme += etudiants[j].Note_generale;
        lengthDep++;
      }
    }
        printf("Departement %d %s %.2f \n: ", i + 1, etudiants[i].departement, somme / lengthDep);
    }
}
void Statistiques(){
    int tmp,i,j;
    int choix;
    printf("------------------------------------\n");
    printf("1 :Afficher le nombre total d'étudiants inscrits\n");
    printf("2 :Afficher le nombre d'étudiants dans chaque département\n");
    printf("3 :Afficher les étudiants ayant une moyenne générale supérieure à un certain seuil\n");
    printf("4 :Afficher les 3 étudiants ayant les meilleures notes\n");
    printf("5 :Afficher le nombre d'étudiants ayant réussi dans chaque département\n");
    printf("-----------------------------\n");
    printf("choisir votre choix :\t");
    scanf("%d",&choix);

    switch(choix){
        int moyen_cmp;
        case 1:
            printf(" le nombre total d'etudiants inscrits est : %d\n",nbr_etudiants);
            break;
        case 2:
            nombre_detudiants_departements();
            break;
        case 3:

            printf("entre la moyen :");
            scanf("%d",&moyen_cmp);
            for(i=0;i<nbr_etudiants;i++){
                if(etudiants[i].Note_generale> moyen_cmp){
                    printf("le nom :%s\n",etudiants[i].nom);
                    printf("le prenom :%s\n",etudiants[i].prenom);
                    printf("date_naissance :%s\n",etudiants[i].date_naissance);
                    printf("departement :%s\n",etudiants[i].departement);
                    printf("Note_generale :%f\n",etudiants[i].Note_generale);
                }
            }

        case 4:
            printf("Les 3 etudiants avec les meilleures notes:\n");
            for (i = 0; i < nbr_etudiants; i++) {
                    tmp = etudiants[i].Note_generale;
                    j = i-1;
                    while(tmp > etudiants[i].Note_generale && j>=0){
                    etudiants[j+1].Note_generale=etudiants[i].Note_generale;
                    j--;
                }
            etudiants[j+1].Note_generale = tmp;
        }
            for(i = 0; i < nbr_etudiants; i++){
                printf("%d",etudiants[i]);
        }

    }
}

void nombre_detudiants_departements(){
    int departement_count[]={};
    char departements[30];
    int nb_departements = 0;
    int j;

    for (int i = 0; i < nbr_etudiants; i++) {
        for (int j = 0; j < nb_departements; j++){
            if (strcmp(departements[j],etudiants[i].departement) == 0) {
                departement_count[j]++;
                break;
            }
        }
        if(j == nb_departements){
            strcpy(departements[nb_departements], etudiants[i].departement);
            departement_count[nb_departements++] = 1;
        }
    }

    for (int i = 0; i < nb_departements; i++) {
        printf("Nombre d'étudiants dans le département %s : %d\n", departements[i], departement_count[i]);
    }
}

int main()
{
    menu();
    ajeuter();
    return 0;
}
