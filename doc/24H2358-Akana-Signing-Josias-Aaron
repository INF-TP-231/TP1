# STRUCTURE DE DONNÉES II - INF 231_EC2
## Exercices de Travaux Pratiques

---

## 📋 INFORMATIONS ÉTUDIANT
- **Nom complet :** AKANA SIGNING JOSIAS AARON
- **Matricule :** 24H2358
- **Cours :** INF 231_EC2 - Structure de Données II
- **Professeur :** PR Metatagia
- **Type :** Groupe de TP
- **Année académique :** 2024

---

## 📁 STRUCTURE DU PROJET

Ce projet contient **9 programmes C indépendants**, chacun implémentant un exercice spécifique de structures de données. Chaque programme est autonome et peut être compilé et exécuté séparément.

### Liste des fichiers :
```
📂 INF231_TP_STRUCTURES_DONNEES/
├── 📄 exercise1_matrix_sum.c          # Somme de matrices
├── 📄 exercise2_matrix_product.c      # Produit de matrices
├── 📄 exercise3_sequential_search.c   # Recherche séquentielle
├── 📄 exercise4_recursive_mult.c      # Multiplication récursive
├── 📄 exercise5_sorted_test.c         # Test tableau trié
├── 📄 exercise6_median_finder.c       # Recherche médian
├── 📄 exercise7_array_reversal.c      # Inversion tableau
├── 📄 exercise8_cross_product.c       # Produit vectoriel
├── 📄 exercise9_vector_matrix.c       # Produit vecteur×matrice
└── 📄 README.md                       # Ce fichier
```

---

## 🔧 COMPILATION ET EXÉCUTION

### Prérequis système :
- **Compilateur :** GCC (GNU Compiler Collection)
- **Standard :** C99 ou supérieur
- **Bibliothèques :** Standard C (stdio.h, math.h, stdbool.h)
- **Système :** Windows, Linux, macOS

### Compilation individuelle :
```bash
# Exemple pour l'exercice 1
gcc -o exercise1 exercise1_matrix_sum.c

# Avec optimisations et warnings
gcc -Wall -O2 -o exercise1 exercise1_matrix_sum.c

# Pour les programmes utilisant math.h (exercice 8)
gcc -Wall -O2 -lm -o exercise8 exercise8_cross_product.c
```

### Compilation de tous les exercices :
```bash
# Script de compilation (Linux/macOS)
for i in {1..9}; do
    if [ $i -eq 8 ]; then
        gcc -Wall -O2 -lm -o exercise$i exercise${i}_*.c
    else
        gcc -Wall -O2 -o exercise$i exercise${i}_*.c
    fi
done
```

### Exécution :
```bash
./exercise1    # Linux/macOS
exercise1.exe  # Windows
```

---

## 📚 DESCRIPTION DÉTAILLÉE DES EXERCICES

### 🔢 **Exercice 1 : Somme de Matrices**
- **Objectif :** Addition de deux matrices de dimensions identiques
- **Concepts :** Tableaux 2D, validation d'entrées, opérations matricielles
- **Complexité :** O(n×m) temps, O(1) espace additionnel
- **Fonctionnalités :**
  - Saisie interactive des dimensions et éléments
  - Validation des dimensions compatibles
  - Affichage formaté des matrices et du résultat

### ⚡ **Exercice 2 : Produit de Matrices**
- **Objectif :** Multiplication matricielle A × B
- **Concepts :** Algorithme de multiplication standard, compatibilité dimensionnelle
- **Complexité :** O(n³) temps, O(n²) espace
- **Fonctionnalités :**
  - Vérification des conditions de multiplication (colonnes A = lignes B)
  - Triple boucle imbriquée pour le calcul
  - Gestion d'erreurs pour dimensions incompatibles

### 🔍 **Exercice 3 : Recherche Séquentielle**
- **Objectif :** Localiser un élément dans un tableau non trié
- **Concepts :** Parcours linéaire, recherche exhaustive
- **Complexité :** O(n) temps, O(1) espace
- **Fonctionnalités :**
  - Recherche de toutes les occurrences
  - Comptage et positions des éléments trouvés
  - Statistiques de recherche

### 🔄 **Exercice 4 : Multiplication Récursive**
- **Objectif :** Calculer a × b en utilisant uniquement l'addition (+1)
- **Concepts :** Récursivité, cas de base, optimisation
- **Complexité :** O(b) temps, O(b) espace (pile récursive)
- **Fonctionnalités :**
  - Implémentation récursive pure
  - Démonstration étape par étape
  - Comparaison avec méthode itérative

### ✅ **Exercice 5 : Test de Tableau Trié**
- **Objectif :** Vérifier si un tableau est trié (croissant/décroissant)
- **Concepts :** Parcours conditionnel, détection d'ordre
- **Complexité :** O(n) temps, O(1) espace
- **Fonctionnalités :**
  - Détection ordre croissant/décroissant
  - Analyse détaillée des comparaisons
  - Suggestions d'algorithmes de tri

### 📊 **Exercice 6 : Recherche du Médian**
- **Objectif :** Trouver la valeur médiane dans un ensemble de données
- **Concepts :** Tri préalable, statistiques descriptives
- **Complexité :** O(n²) temps (tri à bulles), O(n) espace
- **Fonctionnalités :**
  - Tri automatique par bulles
  - Gestion cas pairs/impairs
  - Analyse de distribution

### 🔀 **Exercice 7 : Inversion de Tableau**
- **Objectif :** Inverser l'ordre des éléments in-place
- **Concepts :** Algorithme symétrique, échange d'éléments
- **Complexité :** O(n) temps, O(1) espace
- **Fonctionnalités :**
  - Inversion en place (sans tableau auxiliaire)
  - Démonstration étape par étape
  - Vérification par double inversion

### ⚡ **Exercice 8 : Produit Vectoriel**
- **Objectif :** Calculer le produit vectoriel de deux vecteurs 3D
- **Concepts :** Algèbre vectorielle, géométrie spatiale
- **Complexité :** O(1) temps, O(1) espace
- **Formule :** u × v = (u₂v₃-u₃v₂, u₃v₁-u₁v₃, u₁v₂-u₂v₁)
- **Fonctionnalités :**
  - Calcul détaillé avec déterminant 3×3
  - Vérification orthogonalité
  - Analyse géométrique (angles, aires)

### 🔢 **Exercice 9 : Produit Vecteur×Matrice**
- **Objectif :** Multiplier un vecteur ligne par une matrice
- **Concepts :** Transformations linéaires, combinaisons linéaires
- **Complexité :** O(n×m) temps, O(m) espace
- **Fonctionnalités :**
  - Calcul par produits scalaires colonnes
  - Interprétation géométrique
  - Vérification par méthodes alternatives

---

## 🧠 CONCEPTS INFORMATIQUES ILLUSTRÉS

### **Structures de Données**
- **Tableaux 1D/2D :** Stockage contigu, accès indexé
- **Vecteurs mathématiques :** Représentation de données spatiales
- **Matrices :** Structures bidimensionnelles pour transformations

### **Algorithmes Fondamentaux**
- **Recherche :** Séquentielle O(n)
- **Tri :** Bulles O(n²), analyse comparative
- **Récursivité :** Cas de base, appels récursifs
- **Manipulation :** Inversion, échange in-place

### **Complexité Algorithmique**
- **Temporelle :** O(1), O(n), O(n²), O(n³)
- **Spatiale :** Mémoire additionnelle vs in-place
- **Optimisation :** Arrêt précoce, conditions de sortie

---

## 🔬 ANALYSE TECHNIQUE

### **Paradigmes de Programmation**
- **Procédural :** Fonctions modulaires, séparation des responsabilités
- **Validation :** Vérification robuste des entrées utilisateur
- **Interface :** Interaction intuitive, messages informatifs

### **Gestion Mémoire**
- **Statique :** Tableaux de taille fixe (MAX_SIZE)
- **Efficacité :** Algorithmes in-place privilégiés
- **Sécurité :** Validation des limites, prévention débordements

### **Portabilité**
- **Standard C :** Compatible tous compilateurs conformes
- **Bibliothèques :** Uniquement standard ANSI C
- **Multi-plateforme :** Windows, Linux, macOS

---

## 🚀 FONCTIONNALITÉS AVANCÉES

### **Interface Utilisateur**
- **Saisie guidée :** Instructions claires étape par étape
- **Validation robuste :** Gestion d'erreurs complète
- **Affichage formaté :** Résultats structurés et lisibles

### **Analyses Détaillées**
- **Calculs étape par étape :** Démonstration pédagogique
- **Vérifications :** Contrôles de cohérence automatiques
- **Statistiques :** Métriques de performance et d'exactitude

### **Optimisations**
- **Arrêt précoce :** Conditions d'optimisation
- **Réutilisation :** Fonctions génériques réutilisables
- **Efficacité :** Algorithmes choisis pour leur performance

---

## 📈 EXTENSIONS POSSIBLES

### **Améliorations Algorithmiques**
1. **Tris avancés :** QuickSort, MergeSort, HeapSort
2. **Recherche optimisée :** Recherche binaire, hachage
3. **Matrices creuses :** Optimisation mémoire
4. **Arithmétique haute précision :** Support grands nombres

### **Fonctionnalités Additionnelles**
1. **Interface graphique :** Visualisation des opérations
2. **Persistence :** Sauvegarde/chargement fichiers
3. **Parallélisation :** Calculs multi-threadés
4. **Tests automatisés :** Suite de tests unitaires

### **Applications Pratiques**
1. **Calcul scientifique :** Simulations numériques
2. **Infographie :** Transformations 3D
3. **Intelligence artificielle :** Opérations sur tenseurs
4. **Cryptographie :** Opérations modulaires

---

## 📋 MÉTHODES DE TEST

### **Validation Manuelle**
- **Cas simples :** Vérification calculs manuels
- **Cas limites :** Tableaux vides, matrices 1×1
- **Données aléatoires :** Tests robustesse

### **Vérifications Automatiques**
- **Propriétés mathématiques :** Commutativité, associativité
- **Invariants :** Propriétés préservées
- **Comparaisons croisées :** Méthodes alternatives

---

## 🎯 OBJECTIFS PÉDAGOGIQUES ATTEINTS

### **Compétences Techniques**
✅ **Maîtrise des tableaux** multidimensionnels  
✅ **Algorithmes fondamentaux** de recherche et tri  
✅ **Récursivité** et optimisation  
✅ **Complexité algorithmique** et analyse de performance  
✅ **Validation d'entrées** et gestion d'erreurs  

### **Compétences Mathématiques**
✅ **Algèbre linéaire** : matrices, vecteurs, transformations  
✅ **Statistiques** : médian, distribution  
✅ **Géométrie** : produits scalaires et vectoriels  
✅ **Analyse numérique** : précision, stabilité  

### **Compétences de Développement**
✅ **Modularité** : code réutilisable et maintenable  
✅ **Documentation** : commentaires et spécifications  
✅ **Tests** : validation et vérification  
✅ **Optimisation** : efficacité temps/espace  

---

## 📞 SUPPORT ET DOCUMENTATION

### **Ressources Académiques**
- **Cours :** Notes de cours INF 231_EC2
- **Professeur :** PR Metatagia
- **Documentation :** Commentaires intégrés dans le code

### **Références Techniques**
- **Standard C :** ISO/IEC 9899
- **Algorithmes :** Cormen, Leiserson, Rivest, Stein
- **Algèbre linéaire :** Gilbert Strang

---

## 📅 INFORMATIONS DE DÉVELOPPEMENT

- **Date de création :** Septembre 2024
- **Dernière mise à jour :** Septembre 2024
- **Version :** 1.0
- **Statut :** Projet académique terminé

---

## 🏆 CONCLUSION

Ce projet démontre une maîtrise complète des **structures de données fondamentales** et des **algorithmes classiques**. Chaque exercice illustre des concepts théoriques par une implémentation pratique robuste et optimisée.

Les programmes développés respectent les **standards de qualité** académiques et industriels, avec une attention particulière portée à la **lisibilité**, la **maintenabilité** et l'**efficacité** du code.

---

**Développé avec passion par :**  
**AKANA SIGNING JOSIAS AARON**  
**Matricule : 24H2358**  
**INF 231_EC2 - Structure de Données II**  
**Sous la direction de PR Metatagia**

---

*Ce projet constitue une base solide pour l'apprentissage avancé des structures de données et de l'algorithmique.*
