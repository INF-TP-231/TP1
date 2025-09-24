#include <stdio.h>
#include <stdlib.h>

void afficher_tableau(int tableau[], int taille) {
    printf("[");
    for (int i = 0; i < taille; i++) {
        printf("%d", tableau[i]);
        if (i < taille - 1) {
            printf(", ");
        }
    }
    printf("]\n");
}

void tri_selection(int tableau[], int taille) {
    int i, j, min_idx, temp;
    
    for (i = 0; i < taille - 1; i++) {
    
        min_idx = i;
        for (j = i + 1; j < taille; j++) {
            if (tableau[j] < tableau[min_idx]) {
                min_idx = j;
            }
        }
        
        if (min_idx != i) {
            temp = tableau[i];
            tableau[i] = tableau[min_idx];
            tableau[min_idx] = temp;
        }
    }
}

void tri_bulles(int tableau[], int taille) {
    int i, j, temp;
    int echange;
    
    for (i = 0; i < taille - 1; i++) {
        echange = 0;
        for (j = 0; j < taille - 1 - i; j++) {
            if (tableau[j] > tableau[j + 1]) {
                // Échanger les éléments
                temp = tableau[j];
                tableau[j] = tableau[j + 1];
                tableau[j + 1] = temp;
                echange = 1;
            }
        }
        
        if (echange == 0) {
            break;
        }
    }
}

double calculer_mediane(int tableau[], int taille) {
    
    int *copie = (int*)malloc(taille * sizeof(int));
    if (copie == NULL) {
        printf("Erreur d'allocation mémoire !\n");
        return -1;
    }
    
    for (int i = 0; i < taille; i++) {
        copie[i] = tableau[i];
    }
    
    tri_selection(copie, taille);
    
    printf("Tableau trié : ");
    afficher_tableau(copie, taille);
    
    double mediane;
    
    if (taille % 2 == 1) {
        
        mediane = copie[taille / 2];
        printf("Taille impaire (%d éléments)\n", taille);
        printf("Médiane = élément à l'indice %d = %d\n", taille / 2, copie[taille / 2]);
    } else {
    
        int idx1 = (taille / 2) - 1;
        int idx2 = taille / 2;
        mediane = (copie[idx1] + copie[idx2]) / 2.0;
        printf("Taille paire (%d éléments)\n", taille);
        printf("Médiane = moyenne de %d et %d = (%.1f + %.1f) / 2 = %.1f\n", 
               copie[idx1], copie[idx2], (double)copie[idx1], (double)copie[idx2], mediane);
    }
    
    free(copie);  
    return mediane;
}

int saisir_tableau(int tableau[], int taille_max) {
    int taille;
    
    printf("Combien d'éléments voulez-vous saisir (max %d) ? ", taille_max);
    scanf("%d", &taille);
    
    if (taille <= 0 || taille > taille_max) {
        printf("Taille invalide !\n");
        return 0;
    }
    
    printf("Entrez les %d éléments :\n", taille);
    for (int i = 0; i < taille; i++) {
        printf("Élément %d : ", i + 1);
        scanf("%d", &tableau[i]);
    }
    
    return taille;
}

int main() {
    const int TAILLE_MAX = 100;
    int tableau[TAILLE_MAX];
    int choix, taille;
    double mediane;
    
    printf("=== CALCULATEUR DE MÉDIANE ===\n\n");
    
    printf("Choisissez une option :\n");
    printf("1. Saisir votre propre tableau\n");
    printf("2. Utiliser un tableau de test\n");
    printf("Votre choix : ");
    scanf("%d", &choix);
    
    if (choix == 1) {
        // Saisie utilisateur
        taille = saisir_tableau(tableau, TAILLE_MAX);
        if (taille == 0) {
            return 1;
        }
    } else {
        // Tableaux de test
        printf("\nTableaux de test disponibles :\n");
        printf("1. [1, 3, 5, 7, 9] (impair)\n");
        printf("2. [2, 4, 6, 8] (pair)\n");
        printf("3. [10, 1, 8, 3, 5, 2, 7, 4, 6, 9] (mélangé)\n");
        printf("4. [42] (un seul élément)\n");
        printf("Choisissez : ");
        scanf("%d", &choix);
        
        switch (choix) {
            case 1:
                taille = 5;
                int test1[] = {1, 3, 5, 7, 9};
                for (int i = 0; i < taille; i++) tableau[i] = test1[i];
                break;
            case 2:
                taille = 4;
                int test2[] = {2, 4, 6, 8};
                for (int i = 0; i < taille; i++) tableau[i] = test2[i];
                break;
            case 3:
                taille = 10;
                int test3[] = {10, 1, 8, 3, 5, 2, 7, 4, 6, 9};
                for (int i = 0; i < taille; i++) tableau[i] = test3[i];
                break;
            case 4:
                taille = 1;
                tableau[0] = 42;
                break;
            default:
                printf("Choix invalide !\n");
                return 1;
        }
    }
    
    printf("\n--- CALCUL DE LA MÉDIANE ---\n");
    printf("Tableau original : ");
    afficher_tableau(tableau, taille);
    
    mediane = calculer_mediane(tableau, taille);
    
    if (mediane != -1) {
        printf("\n RÉSULTAT : La médiane est %.1f\n", mediane);
    }
    
    return 0;
}
