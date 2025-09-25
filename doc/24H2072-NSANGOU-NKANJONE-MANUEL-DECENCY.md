Cahier de suivi individuel — INF231 (TP)
===============================================

#Etudiant:NSANGOU NKANJONE MANUEL DECENCY <br>

#Matricule:24H2072 <br>

#Exercice attribué: Produit Vectoriel et Produit vecteurxmatrice <br>

1)Objectif de l'exercice <br>
------------------------------------------------------------------------------------------------------------------------------------------------------------------------

6.Produit vectoriel <br>
 ou il fallait implémenter le produit vectoriel de deux vecteurs en utilisant des tableaux en C.

7.Produit vecteur-matrice <br>
 ou il fallait implémenter le produit d'un vecteur par une matrice en utilisant des tableaux en C.
------------------------------------------------------------------------------------------------------------------------------------------------------------------------

2)Algorithme(description textuelle) <br>
------------------------------------------------------------------------------------------------------------------------------------------------------------------------

6.Produit vectoriel <br>
Pour calculer le produit vectoriel de deux vecteurs A et B en C, nous allons utiliser la formule suivante :
C = A x B <br>
où C est le vecteur résultant. Les coordonnées de C sont données par :
Cx = Ay * Bz - Az * By <br>
Cy = Az * Bx - Ax * Bz <br>
Cz = Ax * By - Ay * Bx <br>
Nous allons donc créer une fonction qui prend en entrée deux vecteurs et qui retourne leur produit vectoriel.

7.Produit vecteur-matrice <br>
Pour calculer le produit d'un vecteur V par une matrice M en C, nous allons utiliser la formule suivante :<br>
R = V * M <br>
où R est le vecteur résultant. Les coordonnées de R sont données par :<br>
Ri = Σ (Vj * Mji) pour j allant de 1 à n <br>
où n est le nombre de colonnes de la matrice M et m est le nombre de lignes de M. <br>
Nous allons donc créer une fonction qui prend en entrée un vecteur et une matrice et qui retourne le vecteur résultant du produit.<br>
------------------------------------------------------------------------------------------------------------------------------------------------------------------------

3)Code source<br>
------------------------------------------------------------------------------------------------------------------------

6.Produit vectoriel (Fichier: produitvectoriel.c et produitvecteurxmatrice.c)<br>

```c

#include <stdio.h>
#include <math.h>

typedef struct {
    double x;
    double y; 
    double z;
} Vecteur3D;

void afficher_vecteur(Vecteur3D v, const char* nom) {
    printf("%s = (%.2f, %.2f, %.2f)\n", nom, v.x, v.y, v.z);
}

Vecteur3D produit_vectoriel(Vecteur3D u, Vecteur3D v) {
    Vecteur3D resultat;
    
    // Formule du produit vectoriel :
    // u × v = (u.y*v.z - u.z*v.y, u.z*v.x - u.x*v.z, u.x*v.y - u.y*v.x)
    resultat.x = u.y * v.z - u.z * v.y;
    resultat.y = u.z * v.x - u.x * v.z;
    resultat.z = u.x * v.y - u.y * v.x;
    
    return resultat;
}

double produit_scalaire(Vecteur3D u, Vecteur3D v) {
    return u.x * v.x + u.y * v.y + u.z * v.z;
}

double norme_vecteur(Vecteur3D v) {
    return sqrt(v.x * v.x + v.y * v.y + v.z * v.z);
}

double angle_entre_vecteurs(Vecteur3D u, Vecteur3D v) {
    double prod_scal = produit_scalaire(u, v);
    double norme_u = norme_vecteur(u);
    double norme_v = norme_vecteur(v);
    
    if (norme_u == 0 || norme_v == 0) {
        return 0; 
    }
    
    double cos_angle = prod_scal / (norme_u * norme_v);
    
    if (cos_angle > 1.0) cos_angle = 1.0;
    if (cos_angle < -1.0) cos_angle = -1.0;
    
    return acos(cos_angle);
}

int sont_paralleles(Vecteur3D u, Vecteur3D v) {
    Vecteur3D produit = produit_vectoriel(u, v);
    double norme = norme_vecteur(produit);
    return (norme < 1e-10);
}

Vecteur3D normaliser_vecteur(Vecteur3D v) {
    Vecteur3D resultat = {0, 0, 0};
    double norme = norme_vecteur(v);
    
    if (norme != 0) {
        resultat.x = v.x / norme;
        resultat.y = v.y / norme;
        resultat.z = v.z / norme;
    }
    
    return resultat;
}

Vecteur3D saisir_vecteur(const char* nom) {
    Vecteur3D v;
    printf("Saisie du vecteur %s :\n", nom);
    printf("Composante x : ");
    scanf("%lf", &v.x);
    printf("Composante y : ");
    scanf("%lf", &v.y);
    printf("Composante z : ");
    scanf("%lf", &v.z);
    return v;
}

void afficher_calcul_detaille(Vecteur3D u, Vecteur3D v, Vecteur3D produit) {
    printf("\n--- CALCUL DÉTAILLÉ ---\n");
    printf("Formule : u × v = (u.y*v.z - u.z*v.y, u.z*v.x - u.x*v.z, u.x*v.y - u.y*v.x)\n\n");
    
    printf("Composante x :\n");
    printf("  u.y * v.z - u.z * v.y = %.2f * %.2f - %.2f * %.2f = %.2f - %.2f = %.2f\n",
           u.y, v.z, u.z, v.y, u.y * v.z, u.z * v.y, produit.x);
    
    printf("Composante y :\n");
    printf("  u.z * v.x - u.x * v.z = %.2f * %.2f - %.2f * %.2f = %.2f - %.2f = %.2f\n",
           u.z, v.x, u.x, v.z, u.z * v.x, u.x * v.z, produit.y);
    
    printf("Composante z :\n");
    printf("  u.x * v.y - u.y * v.x = %.2f * %.2f - %.2f * %.2f = %.2f - %.2f = %.2f\n",
           u.x, v.y, u.y, v.x, u.x * v.y, u.y * v.x, produit.z);
}

int main() {
    Vecteur3D u, v, produit;
    int choix;
    
    printf("=== CALCULATEUR DE PRODUIT VECTORIEL ===\n\n");
    
    printf("Choisissez une option :\n");
    printf("1. Saisir vos propres vecteurs\n");
    printf("2. Utiliser des vecteurs de test\n");
    printf("Votre choix : ");
    scanf("%d", &choix);
    
    if (choix == 1) {
        
        u = saisir_vecteur("u");
        printf("\n");
        v = saisir_vecteur("v");
    } else {
        // Vecteurs de test
        printf("\nVecteurs de test disponibles :\n");
        printf("1. u=(1,0,0) et v=(0,1,0) [vecteurs unitaires perpendiculaires]\n");
        printf("2. u=(1,2,3) et v=(4,5,6) [vecteurs quelconques]\n");
        printf("3. u=(2,4,6) et v=(1,2,3) [vecteurs parallèles]\n");
        printf("4. u=(3,0,4) et v=(0,5,0) [cas mixte]\n");
        printf("Choisissez : ");
        scanf("%d", &choix);
        
        switch (choix) {
            case 1:
                u = (Vecteur3D){1, 0, 0};
                v = (Vecteur3D){0, 1, 0};
                break;
            case 2:
                u = (Vecteur3D){1, 2, 3};
                v = (Vecteur3D){4, 5, 6};
                break;
            case 3:
                u = (Vecteur3D){2, 4, 6};
                v = (Vecteur3D){1, 2, 3};
                break;
            case 4:
                u = (Vecteur3D){3, 0, 4};
                v = (Vecteur3D){0, 5, 0};
                break;
            default:
                printf("Choix invalide !\n");
                return 1;
        }
    }
    
    produit = produit_vectoriel(u, v);
    
    printf("\n=== RÉSULTATS ===\n");
    afficher_vecteur(u, "Vecteur u");
    afficher_vecteur(v, "Vecteur v");
    printf("\n");
    afficher_vecteur(produit, "u × v");
    
    double norme_produit = norme_vecteur(produit);
    printf("\nNorme de u × v = %.2f\n", norme_produit);
    
    printf("\n=== PROPRIÉTÉS ===\n");
    
    double prod_scal_u = produit_scalaire(u, produit);
    double prod_scal_v = produit_scalaire(v, produit);
    printf("u • (u × v) = %.6f (doit être ≈ 0)\n", prod_scal_u);
    printf("v • (u × v) = %.6f (doit être ≈ 0)\n", prod_scal_v);
    
    if (sont_paralleles(u, v)) {
        printf("  Les vecteurs u et v sont parallèles !\n");
        printf("   Le produit vectoriel est le vecteur nul.\n");
    } else {
        printf(" Les vecteurs u et v ne sont pas parallèles.\n");
    }
    
    printf("\nAire du parallélogramme formé par u et v = %.2f\n", norme_produit);
    
    double angle_rad = angle_entre_vecteurs(u, v);
    double angle_deg = angle_rad * 180.0 / M_PI;
    printf("Angle entre u et v = %.2f° (%.2f radians)\n", angle_deg, angle_rad);
    
    printf("\nVoulez-vous voir le calcul détaillé ? (1=oui, 0=non) : ");
    scanf("%d", &choix);
    if (choix == 1) {
        afficher_calcul_detaille(u, v, produit);
    }
    
    Vecteur3D produit_inverse = produit_vectoriel(v, u);
    printf("\n=== VÉRIFICATION : ANTI-COMMUTATIVITÉ ===\n");
    afficher_vecteur(produit_inverse, "v × u");
    printf("Vérification : u × v = -(v × u) ?\n");
    printf("u × v = (%.2f, %.2f, %.2f)\n", produit.x, produit.y, produit.z);
    printf("-(v × u) = (%.2f, %.2f, %.2f)\n", -produit_inverse.x, -produit_inverse.y, -produit_inverse.z);
    
    return 0;
}
```
7.Produit vecteurxmatrice (Fichier: produitvecteurxmatrice.c)

```c

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
```
------------------------------------------------------------------------------------------------------------------------

4)Compilation et exécution <br>
------------------------------------------------------------------------------------------------------------------------------------------------------------------------    -Produit vectoriel <br>
Pour compiler et exécuter le programme de produit vectoriel, vous pouvez utiliser les commandes suivantes dans votre terminal : <br>

```bash

gcc -o produit_vectoriel produitvectoriel.c -lm
./produit_vectoriel
```

   -Produit vecteur-matrice <br>
Pour compiler et exécuter le programme de produit vecteur-matrice, vous pouvez utiliser les commandes suivantes dans votre terminal :

```bash
gcc -o produit_vecteur_matrice produitvecteurxmatrice.c
./produit_vecteur_matrice
```
------------------------------------------------------------------------------------------------------------------------------------------------------------------------