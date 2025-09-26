Cahier de suivi individuel — INF231 (TP)
===============================================

#ASSOGO MANGA GEORGES MATHURIN <br>

#Matricule:24G2280 <br>

#Exercice attribué: Inverser un tableau <br>

1. Description
Ce programme e lanage C permet de renvoyer un tableau avec ses éléments placés dans l'ordre inverse de mmeur ordre de départ. Il parcoure le tableau dans les deux sens jusqu'à la moitié et permute les éléments symétriques par rapport au milieu.

2. Fonctionnement
 - L'utilisateur entre la taille du tableau N.
 - En fonction de N, on faire correspond à l'élément d'indice i, un élément d'indice j, symétrique par rapport à milieu du tableau, en application de la formule, j = N - i - 1.

3. Résultat
  Le tableau est renvoyé dans l'ordre contraire de l'ordre de départ.

4. Compilation et exécution
 Pour compiler le programme "inverser_tableau.c" ouvrez le terminal et tapez la commande: ./permutation

5. Exemple de sortie
Entrer la taille du tableau
6
Entrer la valeur numéro 1
2
Entrer la valeur numéro 2
7
Entrer la valeur numéro 3
4
Entrer la valeur numéro 4
3
Entrer la valeur numéro 5
1
Entrer la valeur numéro 6
5
Avant
2 7 4 3 1 5
Après
5 1 3 4 7 2