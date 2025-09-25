# KAMENI FRANCK ARTHUR
**Participation au travail de groupe pour l'unité INF231**

## Tâches Réalisées

### 1. Programme de test de tableau trié (`short_test.c`)
### 2. Programme de produit entre  matrices (`somme.c`)

---

## Analyse des Programmes

### 1. Programme de test de tableau trié

#### Objectif
Développer un programme permettant de vérifier si un tableau est trié en ordre croissant.

#### Principe Algorithmique
- Parcourir le tableau jusqu'à l'avant-dernier élément (n-1 itérations)
- Comparer chaque élément avec son successeur
- Si un élément est supérieur à son successeur : le tableau n'est pas trié
- Si toutes les comparaisons sont valides : le tableau est trié

#### Complexité
- **Temps :** O(n) - parcours linéaire du tableau
- **Espace :** O(1) - utilisation de mémoire constante

### 2. Programme de produit matriciel

#### Objectif
Calculer le produit de deux matrices A et B avec vérification de la compatibilité des dimensions.

#### Principe Mathématique
Pour deux matrices :
- A de dimensions (lignesA × colonnesA)
- B de dimensions (lignesB × colonnesB)

Le produit A × B n'est possible que si **colonnesA = lignesB**

La matrice résultante P aura pour dimensions : **(lignesA × colonnesB)**

Chaque élément P[i][j] est calculé par :
P[i][j] = Σ (A[i][k] × B[k][j]) pour k de 0 à colonnesA-1
## utilisation

### Prérequis
- gcc

### Compiler le test de tableau trié
gcc -o short_test short_test.c

### Compiler le produit matriciel
gcc -o somme somme.c
