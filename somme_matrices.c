#include <stdio.h>
#include <stdlib.h>

int main() {
    int lignes, colonnes;

    // Demander la taille
    printf("Entrez le nombre de lignes : ");
    scanf("%d", &lignes);
    printf("Entrez le nombre de colonnes : ");
    scanf("%d", &colonnes);

    // Allocation dynamique des matrices
    int **A = malloc(lignes * sizeof(int*));
    int **B = malloc(lignes * sizeof(int*));
    int **S = malloc(lignes * sizeof(int*)); // matrice somme

    for (int i = 0; i < lignes; i++) {
        A[i] = malloc(colonnes * sizeof(int));
        B[i] = malloc(colonnes * sizeof(int));
        S[i] = malloc(colonnes * sizeof(int));
    }

    // Remplir la première matrice
    printf("\nSaisir les valeurs de la matrice A :\n");
    for (int i = 0; i < lignes; i++) {
        for (int j = 0; j < colonnes; j++) {
            printf("A[%d][%d] = ", i, j);
            scanf("%d", &A[i][j]);
        }
    }

    // Remplir la deuxième matrice
    printf("\nSaisir les valeurs de la matrice B :\n");
    for (int i = 0; i < lignes; i++) {
        for (int j = 0; j < colonnes; j++) {
            printf("B[%d][%d] = ", i, j);
            scanf("%d", &B[i][j]);
        }
    }

    // Calcul de la somme
    for (int i = 0; i < lignes; i++) {
        for (int j = 0; j < colonnes; j++) {
            S[i][j] = A[i][j] + B[i][j];
        }
    }

    // Affichage du résultat
    printf("\nMatrice somme S = A + B :\n");
    for (int i = 0; i < lignes; i++) {
        for (int j = 0; j < colonnes; j++) {
            printf("%3d ", S[i][j]);
        }
        printf("\n");
    }

    // Libération mémoire
    for (int i = 0; i < lignes; i++) {
        free(A[i]);
        free(B[i]);
        free(S[i]);
    }
    free(A);
    free(B);
    free(S);

    return 0;
}

