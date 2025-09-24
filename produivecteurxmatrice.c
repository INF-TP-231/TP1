#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TAILLE 10

typedef struct {
    double elements[MAX_TAILLE];
    int taille;
} Vecteur;

typedef struct {
    double elements[MAX_TAILLE][MAX_TAILLE];
    int lignes;
    int colonnes;
} Matrice;

void afficher_vecteur(Vecteur v, const char* nom) {
    printf("%s = [", nom);
    for (int i = 0; i < v.taille; i++) {
        printf("%.2f", v.elements[i]);
        if (i < v.taille - 1) printf(", ");
    }
    printf("]\n");
}

void afficher_matrice(Matrice m, const char* nom) {
    printf("%s =\n", nom);
    for (int i = 0; i < m.lignes; i++) {
        printf("  [");
        for (int j = 0; j < m.colonnes; j++) {
            printf("%6.2f", m.elements[i][j]);
            if (j < m.colonnes - 1) printf(" ");
        }
        printf("]\n");
    }
}

Vecteur saisir_vecteur(const char* nom) {
    Vecteur v;
    printf("Saisie du vecteur %s :\n", nom);
    printf("Taille du vecteur (max %d) : ", MAX_TAILLE);
    scanf("%d", &v.taille);
    
    if (v.taille <= 0 || v.taille > MAX_TAILLE) {
        printf("Taille invalide ! Utilisation de taille 3.\n");
        v.taille = 3;
    }
    
    for (int i = 0; i < v.taille; i++) {
        printf("Élément %d : ", i + 1);
        scanf("%lf", &v.elements[i]);
    }
    return v;
}

Matrice saisir_matrice(const char* nom) {
    Matrice m;
    printf("Saisie de la matrice %s :\n", nom);
    printf("Nombre de lignes (max %d) : ", MAX_TAILLE);
    scanf("%d", &m.lignes);
    printf("Nombre de colonnes (max %d) : ", MAX_TAILLE);
    scanf("%d", &m.colonnes);
    
    if (m.lignes <= 0 || m.lignes > MAX_TAILLE || m.colonnes <= 0 || m.colonnes > MAX_TAILLE) {
        printf("Dimensions invalides ! Utilisation de 3x3.\n");
        m.lignes = m.colonnes = 3;
    }
    
    printf("Entrez les éléments ligne par ligne :\n");
    for (int i = 0; i < m.lignes; i++) {
        printf("Ligne %d : ", i + 1);
        for (int j = 0; j < m.colonnes; j++) {
            scanf("%lf", &m.elements[i][j]);
        }
    }
    return m;
}

int produit_vecteur_matrice(Vecteur v, Matrice m, Vecteur* resultat) {

    if (v.taille != m.lignes) {
        printf(" Erreur : Incompatible pour v × M\n");
        printf("   Taille du vecteur (%d) ≠ Nombre de lignes de la matrice (%d)\n", v.taille, m.lignes);
        return 0;
    }
    
    resultat->taille = m.colonnes;
    
    printf("\n--- CALCUL DÉTAILLÉ : v × M ---\n");
    for (int j = 0; j < m.colonnes; j++) {
        resultat->elements[j] = 0;
        printf("Colonne %d : ", j + 1);
        
        for (int i = 0; i < v.taille; i++) {
            resultat->elements[j] += v.elements[i] * m.elements[i][j];
            printf("%.2f×%.2f", v.elements[i], m.elements[i][j]);
            if (i < v.taille - 1) printf(" + ");
        }
        printf(" = %.2f\n", resultat->elements[j]);
    }
    
    return 1;
}

int produit_matrice_vecteur(Matrice m, Vecteur v, Vecteur* resultat) {
    
    if (m.colonnes != v.taille) {
        printf(" Erreur : Incompatible pour M × v\n");
        printf("   Nombre de colonnes de la matrice (%d) ≠ Taille du vecteur (%d)\n", m.colonnes, v.taille);
        return 0;
    }
    
    resultat->taille = m.lignes;
    
    printf("\n--- CALCUL DÉTAILLÉ : M × v ---\n");
    for (int i = 0; i < m.lignes; i++) {
        resultat->elements[i] = 0;
        printf("Ligne %d : ", i + 1);
        
        for (int j = 0; j < m.colonnes; j++) {
            resultat->elements[i] += m.elements[i][j] * v.elements[j];
            printf("%.2f×%.2f", m.elements[i][j], v.elements[j]);
            if (j < m.colonnes - 1) printf(" + ");
        }
        printf(" = %.2f\n", resultat->elements[i]);
    }
    
    return 1;
}

// Produit matrice × matrice (bonus)
int produit_matrice_matrice(Matrice a, Matrice b, Matrice* resultat) {
    if (a.colonnes != b.lignes) {
        printf(" Erreur : Incompatible pour A × B\n");
        printf("   Colonnes de A (%d) ≠ Lignes de B (%d)\n", a.colonnes, b.lignes);
        return 0;
    }
    
    resultat->lignes = a.lignes;
    resultat->colonnes = b.colonnes;
    
    printf("\n--- CALCUL : A × B ---\n");
    for (int i = 0; i < resultat->lignes; i++) {
        for (int j = 0; j < resultat->colonnes; j++) {
            resultat->elements[i][j] = 0;
            for (int k = 0; k < a.colonnes; k++) {
                resultat->elements[i][j] += a.elements[i][k] * b.elements[k][j];
            }
        }
    }
    
    return 1;
}

void creer_exemples_test(int choix, Vecteur* v, Matrice* m) {
    switch (choix) {
        case 1:
            
            *v = (Vecteur){{2, 3}, 2};
            *m = (Matrice){{{1, 4}, {2, 5}}, 2, 2};
            break;
            
        case 2:
            
            *v = (Vecteur){{1, 2, 3}, 3};
            *m = (Matrice){{{1, 0, 2}, {3, 1, 1}, {0, 2, 1}}, 3, 3};
            break;
            
        case 3:
        
            *v = (Vecteur){{1, 0}, 2};
            *m = (Matrice){{{0, -1}, {1, 0}}, 2, 2};
            break;
            
        case 4:
            // Matrice rectangulaire
            *v = (Vecteur){{1, 2}, 2};
            *m = (Matrice){{{1, 2, 3}, {4, 5, 6}}, 2, 3};
            break;
            
        default:
            // Exemple par défaut
            *v = (Vecteur){{1, 1}, 2};
            *m = (Matrice){{{1, 2}, {3, 4}}, 2, 2};
    }
}

int main() {
    Vecteur v, resultat_v;
    Matrice m, m2, resultat_m;
    int choix, operation;
    
    printf("=== CALCULATEUR PRODUITS VECTEUR × MATRICE ===\n\n");
    
    printf("Types d'opérations disponibles :\n");
    printf("1. Vecteur × Matrice (v × M)\n");
    printf("2. Matrice × Vecteur (M × v)\n");
    printf("3. Matrice × Matrice (M × N)\n");
    printf("Choisissez l'opération : ");
    scanf("%d", &operation);
    
    printf("\nMode de saisie :\n");
    printf("1. Saisie manuelle\n");
    printf("2. Exemples de test\n");
    printf("Votre choix : ");
    scanf("%d", &choix);
    
    if (choix == 2) {
        printf("\nExemples disponibles :\n");
        printf("1. [2,3] × [[1,4],[2,5]] (2D simple)\n");
        printf("2. [1,2,3] × matrice 3×3 (3D)\n");
        printf("3. [1,0] × rotation 90° (transformation géométrique)\n");
        printf("4. [1,2] × matrice 2×3 (rectangulaire)\n");
        printf("Choisissez : ");
        scanf("%d", &choix);
        
        creer_exemples_test(choix, &v, &m);
    } else {
        if (operation == 1) {
            v = saisir_vecteur("v");
            printf("\n");
            m = saisir_matrice("M");
        } else if (operation == 2) {
            m = saisir_matrice("M");
            printf("\n");
            v = saisir_vecteur("v");
        } else if (operation == 3) {
            m = saisir_matrice("A");
            printf("\n");
            m2 = saisir_matrice("B");
        }
    }
    
    printf("\n=== DONNÉES D'ENTRÉE ===\n");
    
    switch (operation) {
        case 1:
            // Vecteur × Matrice
            afficher_vecteur(v, "Vecteur v");
            printf("\n");
            afficher_matrice(m, "Matrice M");
            
            printf("\n=== CALCUL : v × M ===\n");
            printf("Condition : taille(v) = lignes(M) → %d = %d \n", v.taille, m.lignes);
            
            if (produit_vecteur_matrice(v, m, &resultat_v)) {
                printf("\n RÉSULTAT :\n");
                afficher_vecteur(resultat_v, "v × M");
                
                printf("\n INTERPRÉTATION :\n");
                printf("Le vecteur v est transformé par la matrice M.\n");
                printf("Résultat : vecteur de taille %d\n", resultat_v.taille);
            }
            break;
            
        case 2:
            // Matrice × Vecteur
            afficher_matrice(m, "Matrice M");
            printf("\n");
            afficher_vecteur(v, "Vecteur v");
            
            printf("\n=== CALCUL : M × v ===\n");
            printf("Condition : colonnes(M) = taille(v) → %d = %d \n", m.colonnes, v.taille);
            
            if (produit_matrice_vecteur(m, v, &resultat_v)) {
                printf("\n RÉSULTAT :\n");
                afficher_vecteur(resultat_v, "M × v");
                
                printf("\n INTERPRÉTATION :\n");
                printf("Transformation linéaire du vecteur v par la matrice M.\n");
                printf("Résultat : vecteur de taille %d\n", resultat_v.taille);
            }
            break;
            
        case 3:
            // Matrice × Matrice
            afficher_matrice(m, "Matrice A");
            printf("\n");
            afficher_matrice(m2, "Matrice B");
            
            printf("\n=== CALCUL : A × B ===\n");
            printf("Condition : colonnes(A) = lignes(B) → %d = %d \n", m.colonnes, m2.lignes);
            
            if (produit_matrice_matrice(m, m2, &resultat_m)) {
                printf("\n RÉSULTAT :\n");
                afficher_matrice(resultat_m, "A × B");
                
                printf("\n INTERPRÉTATION :\n");
                printf("Composition de deux transformations linéaires.\n");
                printf("Résultat : matrice %d×%d\n", resultat_m.lignes, resultat_m.colonnes);
            }
            break;
            
        default:
            printf("Opération invalide !\n");
            return 1;
    }
    
    if (choix == 3 && operation == 2) {
        printf("\n EXEMPLE SPÉCIAL - ROTATION 90° :\n");
        printf("Le point (1,0) devient (0,1) après rotation de 90° dans le sens anti-horaire.\n");
    }
    
    return 0;
}