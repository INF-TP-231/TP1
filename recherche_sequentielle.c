/*
 * EXERCISE 3: RECHERCHE SEQUENTIELLE (Sequential Search)
 * Student: AKANA SIGNING JOSIAS AARON
 * Matricule: 24H2358
 * Course: INF 231_EC2 - Structure de Données II
 * Professor: PR Metatagia
 */

#include <stdio.h>

#define MAX_SIZE 100

int sequentialSearch(int array[], int size, int target, int positions[]) {
    int count = 0;
    
    for(int i = 0; i < size; i++) {
        if(array[i] == target) {
            positions[count] = i;
            count++;
        }
    }
    
    return count; // Return number of occurrences found
}

void printArray(int array[], int size) {
    printf("Tableau: [");
    for(int i = 0; i < size; i++) {
        printf("%d", array[i]);
        if(i < size - 1) printf(", ");
    }
    printf("]\n");
}

int main() {
    int array[MAX_SIZE];
    int positions[MAX_SIZE];
    int size, target, found;
    
    printf("=== RECHERCHE SEQUENTIELLE ===\n");
    printf("Etudiant: AKANA SIGNING JOSIAS AARON (24H2358)\n\n");
    
    // Input array size
    printf("Entrez la taille du tableau (max %d): ", MAX_SIZE);
    scanf("%d", &size);
    
    // Validate size
    if(size <= 0 || size > MAX_SIZE) {
        printf("Erreur: Taille invalide!\n");
        return 1;
    }
    
    // Input array elements
    printf("\nEntrez les elements du tableau:\n");
    for(int i = 0; i < size; i++) {
        printf("Element [%d]: ", i);
        scanf("%d", &array[i]);
    }
    
    // Display the array
    printf("\n");
    printArray(array, size);
    
    // Input search target
    printf("\nEntrez l'element a rechercher: ");
    scanf("%d", &target);
    
    // Perform sequential search
    found = sequentialSearch(array, size, target, positions);
    
    // Display results
    printf("\n=== RESULTATS DE LA RECHERCHE ===\n");
    printf("Element recherche: %d\n", target);
    
    if(found > 0) {
        printf("Element trouve! (%d occurrence(s))\n", found);
        printf("Position(s): ");
        for(int i = 0; i < found; i++) {
            printf("%d", positions[i]);
            if(i < found - 1) printf(", ");
        }
        printf("\n");
        
        // Display found elements with their positions
        printf("\nDetails:\n");
        for(int i = 0; i < found; i++) {
            printf("  Tableau[%d] = %d\n", positions[i], target);
        }
    } else {
        printf("Element non trouve dans le tableau.\n");
    }
    
    // Search statistics
    printf("\nStatistiques:\n");
    printf("  Taille du tableau: %d\n", size);
    printf("  Comparaisons effectuees: %d\n", size);
    printf("  Occurrences trouvees: %d\n", found);
    
    return 0;
}