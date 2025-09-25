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

3)Compilation et exécution <br>
------------------------------------------------------------------------------------------------------------------------------------------------------------------------   
 -Produit vectoriel <br>
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