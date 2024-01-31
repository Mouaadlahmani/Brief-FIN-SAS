#include <stdio.h>

// structure pour stocker la date d'echeance d'une tache
struct date_d {
  int jour;
  int mois;
  int annee;
};
// structure pour stocker les informations d'une tache
struct tache {
  char nom[20];
  char description[100];
  int priorite;
  struct date_d date;
};

// tableau pour stocker les taches
struct tache liste[100];
int tachenombre = 0;

// fonction pour ajouter une tache
void ajouter() {
  struct tache nvtache;

  printf("Nom de la tache : ");
  scanf(" %[^\n]s", &nvtache.nom);

  printf("Description de la tache : ");
  scanf(" %[^\n]s", &nvtache.description);

  printf("La priorite (1.Haut | 2.Moyenne | 3.Faible) : ");
  scanf("%d", &nvtache.priorite);

  printf("La date d'echeance : \n");
  printf("Jour : ");
  scanf("%d", &nvtache.date.jour);
  printf("Mois : ");
  scanf("%d", &nvtache.date.mois);
  printf("Annee : ");
  scanf("%d", &nvtache.date.annee);

  liste[tachenombre++] = nvtache;
  printf("Tache ajoutee avec succes. \n");
}

// fonction pour afficher la liste des taches
void afficher() {
  int i;
  if (tachenombre == 0) {
    printf("Aucune tache a afficher. \n");
  } else {
    printf("\nLa liste des taches : \n");
    for (i = 0; i < tachenombre; i++) {
      printf("\nTache N%d: \n", i + 1);
      printf("Nom : %s \n", liste[i].nom);
      printf("Description : %s \n", liste[i].description);
      printf("Priorite : %d \n", liste[i].priorite);
      printf("Date d'echeance : %d/%d/%d \n\n", liste[i].date.jour,
             liste[i].date.mois, liste[i].date.annee);
      printf("----------------------------- \n");
    }
  }
}

// fonction pour modiffier une tache
void modiffier() {
  int tacheindice;

  afficher();
  printf("Quelle tache voulez vous modiffier : ");
  scanf("%d", &tacheindice);

  if (tacheindice >= 1 && tacheindice <= tachenombre) {

    printf("Nouveau nom de tache : ");
    scanf(" %[^\n]", &liste[tacheindice - 1].nom);

    printf("Nouvelle description : ");
    scanf(" %[^\n]", &liste[tacheindice - 1].description);

    printf("Nouvelle priorite : ");
    scanf("%d", &liste[tacheindice - 1].priorite);

    printf("Nouvelle date d'echeance : \n");
    printf("Jour : ");
    scanf("%d", &liste[tacheindice - 1].date.jour);
    printf("Mois : ");
    scanf("%d", &liste[tacheindice - 1].date.mois);
    printf("Annee : ");
    scanf("%d", &liste[tacheindice - 1].date.annee);

    printf("Tache modiffiee avec succes. \n\n");
  } else {
    printf("Tache invalide. \n\n");
  }
}

// fonction pour suprimer une tache
void suprimer() {
  int tacheindice, i;
  afficher();

  printf("Quelle tache voulez vous suprimer : ");
  scanf("%d", &tacheindice);

  if (tacheindice >= 1 && tacheindice <= tachenombre) {
    for (i = tacheindice - 1; i < tachenombre - 1; i++) {
      liste[i] = liste[i + 1];
    }
    tachenombre--;
    printf("La tache suprimee avec succes. \n\n");
  } else {
    printf("Tache invalide. \n\n");
  }
}

// fonction de filtrage des taches par priorite
void filtrer() {
  int i, priorite;
  printf("La priorite a filtrer (1.Haut | 2.Moyenne | 3.Faible) : ");
  scanf("%d", &priorite);
  if (priorite == 1 || priorite == 2 || priorite == 3) {
    printf("\nLes taches de priorite %d : \n", priorite);
    for (i = 0; i < tachenombre; i++) {
      if (liste[i].priorite == priorite) {
        printf("\nNom : %s \n", liste[i].nom);
        printf("Description : %s \n", liste[i].description);
        printf("Priorite : %d \n", liste[i].priorite);
        printf("Date d'echeance : %d/%d/%d \n", liste[i].date.jour,
               liste[i].date.mois, liste[i].date.annee);
        printf("----------------------------- \n");
      }
    }
  } else {
    printf("Priorite invalide. \n\n");
  }
}

int main() {
  int choix;
  do {
    printf("=====MENU===== : \n");
    printf("1.Ajouter une tache : \n");
    printf("2.Afficher la liste des taches : \n");
    printf("3.Modiffier une tache : \n");
    printf("4.Suprimer une tache : \n");
    printf("5.Filtrer les taches par priorite : \n");
    printf("0.Quitter : \n\n");
    printf("Votre choix : ");
    scanf("%d", &choix);

    switch (choix) {
    case 1:
      ajouter();
      break;
    case 2:
      afficher();
      break;
    case 3:
      modiffier();
      break;
    case 4:
      suprimer();
      break;
    case 5:
      filtrer();
      break;
    case 0:
      printf("Le programme est termine");
      break;
    default:
      printf("Choix invalide. Veuillez ressayer. \n");
    }
  } while (choix != 0);

  return 0;
}
