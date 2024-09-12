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
        printf("7 : Rechercher un etudiant \n");
        printf("8 : Trier un etudiant\n");
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
            case 7:
                rechercher_etudiant_par_nom();
                break;
            case 8:
                 printf("Trier par:\n1) Alphabetiquement\n2) Par Moyenne Generale\n3) Par Moyenne plus 10\n");
            int sortChoice;
            scanf("%d", &sortChoice);
            if (sortChoice == 1) {
                Trier_alpha();
            } else if (sortChoice == 2) {
                trie_moyen_general();
            }/*else if (sortChoice == 3) {
                trierPlus10();
            } else {
                printf("Choix invalide!\n");
            }*/
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
   char T[30][50];
   int count_Deprt = 0;
  for (int i = 0; i < nbr_etudiants; i++){
    int alreadyPrinted = 0;
    for (int j = 0; j < i; j++){
      if (strcmp(etudiants[i].departement, etudiants[j].departement) == 0){
        alreadyPrinted = 1;
        break;
      }
    }
    if (!alreadyPrinted){
      strcpy(T[count_Deprt], etudiants[i].departement);
      count_Deprt++;
    }
  }

  for (int i = 0; i < count_Deprt; i++){
    float somme = 0;
    int lengthDep = 0;

    for (int j = 0; j < nbr_etudiants; j++){
      if (strcmp(T[i], etudiants[j].departement) == 0){
        somme += etudiants[j].Note_generale;
        lengthDep++;
      }
    }
        printf("Departement %d %s  %.2f \n :", i + 1, etudiants[i].departement, somme / lengthDep);
    }
    float SOMME =0;
    for(int i=0;i<nbr_etudiants;i++){
        SOMME += etudiants[i].Note_generale;
    }
    printf("la moyen generale de universite :%.2f\n",SOMME/nbr_etudiants);
}
void Statistiques(){
    int tmp,i,j;
    int choix;
    printf("------------------------------------\n");
    printf("1 :Afficher le nombre total de etudiants inscrits\n");
    printf("2 :Afficher le nombre d'etudiants dans chaque departement\n");
    printf("3 :Afficher les etudiants ayant une moyenne generale superieure à un certain seuil\n");
    printf("4 :Afficher les 3 etudiants ayant les meilleures notes\n");
    printf("5 :Afficher le nombre de etudiants ayant reussi dans chaque departement\n");
    printf("-----------------------------\n");
    printf("choisir votre choix :\t");
    scanf("%d",&choix);

    switch(choix){
        int moyen_cmp,temp;
        char T[30][50];
        int count_Deprt = 0;
        float somme = 0;
        int lengthDep = 0;
        int alreadyPrinted = 0;
        case 1:
            printf(" le nombre total d'etudiants inscrits est : %d\n",nbr_etudiants);
            break;
       /* case 2:
            nombre_detudiants_departements();
            break;*/
        case 3:

            printf("entre la moyen :");
            scanf("%d",&moyen_cmp);
            for(i=0;i<nbr_etudiants;i++){
                if(etudiants[i].Note_generale >= moyen_cmp){
                    printf("-----------------------------\n");
                    printf("le nom :%s\n",etudiants[i].nom);
                    printf("le prenom :%s\n",etudiants[i].prenom);
                    printf("Note_generale :%f\n",etudiants[i].Note_generale);
                    printf("-----------------------------\n");
                }
            }
            break;

        case 4:
            for(int i=0;i<nbr_etudiants;i++){
                for(int j=i+1;j<nbr_etudiants;j++){
                if(etudiants[i].Note_generale<etudiants[j].Note_generale){
                temp=etudiants[i].Note_generale;
                etudiants[i].Note_generale=etudiants[j].Note_generale;
                etudiants[j].Note_generale=temp;

                }
            }
          }
           printf("le 3 etudiants ayant les meilleures notes:\n ");
      for(int i=0;i<3;i++){
        printf("letudente: %d\t :  NOM:%s\t  departement :%s\t  note:%.2f\n",i+1,etudiants[i].nom,etudiants[i].departement,etudiants[i].Note_generale);
      }

     break;

        case 5:
            for (i = 0; i < nbr_etudiants; i++){
            alreadyPrinted = 0;
            for (j = 0; j < i; j++){
            if (strcmp(etudiants[i].departement, etudiants[j].departement) == 0){
            alreadyPrinted = 1;
            break;
            }
        }
            if (!alreadyPrinted){
            strcpy(T[count_Deprt], etudiants[i].departement);
            count_Deprt++;
            }
        }
              printf("les etudiants reussi dans le departement %s est :\n",T[i]);
            for (i = 0; i < count_Deprt; i++){

            lengthDep = 0;

            for (j = 0; j < nbr_etudiants; j++){
              if (strcmp(T[i], etudiants[j].departement) == 0)
              {
                if(etudiants[j].Note_generale>=10)
                    {
                    printf("%s : %f\n",etudiants[j].nom,etudiants[j].Note_generale);
                    }
              }
            }

            }


    }

}
void rechercher_etudiant_par_nom() {
    char nom_cherch[30];
    printf("Nom de l'etudiant a rechercher :\n ");
    scanf(" %[^\n]s",nom_cherch);

    for (int i = 0; i < nbr_etudiants; i++) {
        if (strcmp(etudiants[i].nom,nom_cherch) == 0) {
            printf("num  :%d\n",etudiants[i].num);
            printf("le nom :%s\n",etudiants[i].nom);
            printf("le prenom :%s\n",etudiants[i].prenom);
            printf("date_naissance :%s\n",etudiants[i].date_naissance);
            printf("departement :%s\n",etudiants[i].departement);
            printf("Note_generale :%.2f\n",etudiants[i].Note_generale);
            printf("------------------------\n");
        }
    }
}
void Trier_alpha(){
char tableu[30];
for(int i=0;i<nbr_etudiants;i++){
       for(int j=i+1;j<nbr_etudiants;j++){
        if(strcmp(etudiants[i].nom,etudiants[j].nom)>0){
            strcpy(tableu,etudiants[i].nom);
            strcpy(etudiants[i].nom,etudiants[j].nom);
           strcpy(etudiants[j].nom,tableu);
        }
       }


      }
      for(int i=0;i<nbr_etudiants;i++){
            printf("num  :%d\n",etudiants[i].num);
            printf("le nom :%s\t",etudiants[i].nom);
            printf("le prenom :%s\t",etudiants[i].prenom);
            printf("date_naissance :%s\n",etudiants[i].date_naissance);
            printf("departement :%s\t",etudiants[i].departement);
            printf("Note_generale :%f\n",etudiants[i].Note_generale);

}
}
void trie_moyen_general(){


for(int i=0;i<nbr_etudiants;i++){
        struct etudiant tmp ;
        for(int j=i+1;j<nbr_etudiants;j++){
        if(etudiants[i].Note_generale < etudiants[j].Note_generale){
            tmp = etudiants[j+1];
            etudiants[j+1] = etudiants[i];
            etudiants[i] = tmp;
        }
       }


      }
      for(int i=0;i<nbr_etudiants;i++){
            printf("num  :%d\n",etudiants[i].num);
            printf("le nom :%s\t",etudiants[i].nom);
            printf("le prenom :%s\t",etudiants[i].prenom);
            printf("date_naissance :%s\n",etudiants[i].date_naissance);
            printf("departement :%s\t",etudiants[i].departement);
            printf("Note_generale :%f\n",etudiants[i].Note_generale);

}


}

int main()
{
    menu();
    ajeuter();
    return 0;
}
