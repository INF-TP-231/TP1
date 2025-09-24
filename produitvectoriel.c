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