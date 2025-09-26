NOM : YVANA EMILIA LALANE LARCIER
MATRICULE : 24G2439
README
TP INF231 - TESTER LE TRI D'UN TABLEAU ET TROUVER LE MEDIAN D'UN TABLEAU

I. TESTER LE TRI D'UN TABLEAU


1. Description

Ce programme en langage C permet de vérifier si un tableau d’entiers est trié dans l’ordre croissant.
Il parcourt le tableau élément par élément et affiche si le tableau est :

- Trié (chaque élément est inférieur ou égal au suivant)

- Non trié (au moins un élément est plus grand que le suivant)


2. Fonctionnement

- L’utilisateur saisit la taille du tableau n.

- L’utilisateur entre les n valeurs du tableau.

- Le programme compare chaque paire d’éléments consécutifs tab[i] et tab[i+1].


3. Resultat

Si tous les éléments respectent tab[i] <= tab[i+1], le tableau est trié.

Sinon, le tableau est non trié.


4. Compilation et exécution

Pour compiler le programme "sort_test.c" ouvrez votre terminal et tapez la commande :

gcc sort_test.c -o test_tri

Ensuite, pour exécuter le programme tapez la commande :

./test_tri


5. Exemple de sortie

Entrez la taille du tableau : 5
Entrez les éléments :
2 4 6 8 10
Tri valide

Entrez la taille du tableau : 5
Entrez les éléments :
3 7 1 9 5
Tri invalide



II. TROUVER LE MEDIAN D'UN TABLEAU


1. Description

Ce programme en langage C permet de trouver la médiane d’un tableau d’entiers étant trié au préalable.
La médiane est la valeur centrale d’un ensemble de données lorsque celles-ci sont triées :

Si le nombre d’éléments est impair → la médiane est l’élément du milieu.

Si le nombre d’éléments est pair → la médiane est la moyenne des deux éléments centraux.


2. Fonctionnement

- L’utilisateur saisit la taille du tableau n.

- L’utilisateur entre les n valeurs du tableau.

- Le programme trie le tableau en ordre croissant (tri simple).


- Le programme calcule et affiche la médiane selon la formule :

impair : tab[n/2]

pair : (tab[n/2 - 1] + tab[n/2]) / 2.0


3. Organisation du code

Le programme est découpé en plusieurs étapes :

- Saisie du tableau

- Tri du tableau (par exemple tri à bulles)

- Affichage du tableau trié

- Calcul de la médiane

- Affichage du résultat


4. Compilation et exécution

Pour compiler le programme "mediane.c" ouvrez votre terminal et tapez la commande :

gcc calculmediane.c -o mediane

Ensuite, pour exécuter le programme tapez la commande :

./mediane


5. Exemple de sortie

Entrez la taille du tableau : 5
Entrez les éléments :
10 2 8 4 6

Tableau trié : 2 4 6 8 10
La médiane est : 6

Entrez la taille du tableau : 4
Entrez les éléments :
7 1 9 5

Tableau trié : 1 5 7 9
La médiane est : 6.0