#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//structure pour stocker les informations d'une tache
struct Tache{
    char description[100];
    char date[20];
    int priorite;
};

//tableau pour stocker les taches
    struct Tache liste[100];
    int tachenombre = 0;

//fonction pour ajouter une tache
void ajouter(){
    struct Tache nvtache;
    
    printf("Description de la tache : ");
    scanf(" %[^\n]",&nvtache.description);

    printf("Date d'echeance (format : jj/mm/aaaa) : ");
    scanf("%s",&nvtache.date);

    printf("Priorite (1 ou 2) : ");
    scanf("%d",&nvtache.priorite);

    liste[tachenombre++] = nvtache;

    printf("Tache ajoutee avec succees. \n");
}

//fonction pour afficher la liste des taches
void afficher(){
    int i;
   if(tachenombre == 0){
    printf("Aucune tache a afficher. \n");
    }
    else{
        printf("La liste des taches : \n");
        for(i=0;i<tachenombre;i++){
            printf("Tache : %d \n",i+1);
            printf("Decription : %s \n",liste[i].description);
            printf("Date d'echeance : %s \n",liste[i].date);
            printf("Priorite : %d \n",liste[i].priorite);
        }
    }
}

//fonction pour modiffier une tache
void modiffier(){
    int tacheindice;
    
    afficher();
    
    printf("Quelle tache voulez vous modiffier : ");
    scanf("%d",&tacheindice);

    if(tacheindice>=1 && tacheindice<=tachenombre){

       printf("Nouvelle description : ");
       scanf(" %[^\n]",&liste[tacheindice-1].description);

       printf("La vouvelle date d'echeance : ");
       scanf("%s",&liste[tacheindice-1].date);

       printf("La nouvelle priorite : ");
       scanf("%d",&liste[tacheindice-1].priorite);

       printf("Tache modiffiee avec succees. \n");
    }
    else{
        printf("Numero de tache invalide. \n");
    }
}

int main()
{
    int choix;
    do{
    	printf("=====MENU===== : \n");
        printf("1.Ajouter un tache. \n");
        printf("2.Afficher la liste des taches. \n");
        printf("3.Modiffier une tache. \n");
        printf("0.Quitter. \n");
        printf("Votre choix :");
        scanf("%d",&choix);
        switch(choix){
                case 1 : ajouter();
                        break;
                case 2 : afficher();
                        break;
                case 3 : modiffier();
                        break;
                case 0 : printf("Le programme est termine");
                        break;
                default : printf("Choix invalide ,Veuillez ressayer");
                        break;
        }
    }while(choix != 0);
    return 0;
}
