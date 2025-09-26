#include <stdio.h>
#include <stdlib.h>

int main() {
    int lignesA, colonnesA, lignesB, colonnesB;

    // Lecture des dimensions
    printf("Entrez le nombre de lignes de A : ");
    scanf("%d", &lignesA);
    printf("Entrez le nombre de colonnes de A : ");
    scanf("%d", &colonnesA);

    printf("Entrez le nombre de lignes de B : ");
    scanf("%d", &lignesB);
    printf("Entrez le nombre de colonnes de B : ");
    scanf("%d", &colonnesB);

    // Vérification compatibilité
    if (colonnesA != lignesB) {
        printf("\nErreur : le produit n'est pas possible (colonnesA != lignesB).\n");
        return 1;
    }

    // Allocation dynamique
    int **A = malloc(lignesA * sizeof(int*));
    int **B = malloc(lignesB * sizeof(int*));
    int **P = malloc(lignesA * sizeof(int*)); // produit

    for (int i = 0; i < lignesA; i++) {
        A[i] = malloc(colonnesA * sizeof(int));
        P[i] = malloc(colonnesB * sizeof(int));
    }
    for (int i = 0; i < lignesB; i++) {
        B[i] = malloc(colonnesB * sizeof(int));
    }

    // Remplissage A
    printf("\nSaisir les valeurs de la matrice A :\n");
    for (int i = 0; i < lignesA; i++) {
        for (int j = 0; j < colonnesA; j++) {
            printf("A[%d][%d] = ", i, j);
            scanf("%d", &A[i][j]);
        }
    }

    // Remplissage B
    printf("\nSaisir les valeurs de la matrice B :\n");
    for (int i = 0; i < lignesB; i++) {
        for (int j = 0; j < colonnesB; j++) {
            printf("B[%d][%d] = ", i, j);
            scanf("%d", &B[i][j]);
        }
    }

    // Produit matriciel
    for (int i = 0; i < lignesA; i++) {
        for (int j = 0; j < colonnesB; j++) {
            P[i][j] = 0;
            for (int k = 0; k < colonnesA; k++) {
                P[i][j] += A[i][k] * B[k][j];
            }
        }
    }

    // Affichage résultat
    printf("\nProduit P = A × B :\n");
    for (int i = 0; i < lignesA; i++) {
        for (int j = 0; j < colonnesB; j++) {
            printf("%5d ", P[i][j]);
        }
        printf("\n");
    }

    // Libération mémoire
    for (int i = 0; i < lignesA; i++) {
        free(A[i]);
        free(P[i]);
    }
    for (int i = 0; i < lignesB; i++) {
        free(B[i]);
    }
    free(A);
    free(B);
    free(P);

    return 0;
}

