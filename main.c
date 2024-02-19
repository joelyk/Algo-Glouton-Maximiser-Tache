#include <stdio.h>
#include <stdlib.h>

// Structure pour représenter une tâche
typedef struct {
    int duree; // Durée d'exécution de la tâche
    int date_limite; // Date limite pour la tâche
} Tache;

// Fonction de comparaison pour le tri des tâches par date limite croissante
int comparer_taches(const void *a, const void *b) {
    Tache *tacheA = (Tache *)a;
    Tache *tacheB = (Tache *)b;
    if (tacheA->date_limite == tacheB->date_limite) {
        // En cas d'égalité des dates limites, priorité à la tâche avec la durée la plus petite
        return tacheA->duree - tacheB->duree;
    }
    return tacheA->date_limite - tacheB->date_limite;
}

// Algorithme glouton pour maximiser le nombre de tâches réalisées avec durée totale minimale
int nombreTachesRealisees(Tache taches[], int n) {
    // Tri des tâches par date limite croissante et durée croissante en cas d'égalité des dates limites
    qsort(taches, n, sizeof(Tache), comparer_taches);

    int nombre_taches_realisees = 0;
    int temps_actuel = 0;
    int duree_totale = 0;

    // Tableau pour stocker les tâches réalisées
    Tache taches_realisees[n];

    // Affichage des tâches au départ
    printf("\nTaches realisees:\n");
    printf("| Tache | Duree | Date Limite |\n");
    printf("|-------|-------|-------------|\n");
    for (int i = 0; i < n; i++) {
        printf("| %5d | %5d | %11d |\n", i + 1, taches[i].duree, taches[i].date_limite);
    }

    // Parcours des tâches triées
    for (int i = 0; i < n; i++) {
        // Vérifier si la tâche peut être réalisée sans dépasser sa date limite
        if (temps_actuel + taches[i].duree <= taches[i].date_limite) {
            // Ajouter la tâche réalisée au tableau
            taches_realisees[nombre_taches_realisees] = taches[i];

            temps_actuel += taches[i].duree;
            nombre_taches_realisees++;
            duree_totale += taches[i].duree;
        }
    }

    // Affichage du résultat
    printf("\nResultat obtenu: www.PandaCodeur.com\n");
    printf("Nombre de taches realisees : %d\n", nombre_taches_realisees);
    printf("Duree totale minimale : %d\n", duree_totale);

    // Affichage des tâches réalisées
    printf("\nTaches realisees:\n");
    printf("| Tache | Duree | Date Limite |\n");
    printf("|-------|-------|-------------|\n");
    for (int i = 0; i < nombre_taches_realisees; i++) {
        printf("| %5d | %5d | %11d |\n", i + 1, taches_realisees[i].duree, taches_realisees[i].date_limite);
    }

    return nombre_taches_realisees;
}

int main() {
    // Exemple de tâches avec leur durée et date limite
    Tache taches[] = {{5, 15}, {2, 6}, {4, 15}, {4, 8}, {1, 8}, {2, 6}};
    int n = sizeof(taches) / sizeof(taches[0]);

    // Appel de la fonction pour obtenir le nombre de tâches réalisées
    int nombre_taches_realisees = nombreTachesRealisees(taches, n);

    return 0;
}
