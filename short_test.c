#include<stdio.h>
#include<stdlib.h>
int main(){
	int n;
	int i;
	int d = 1;
	printf("saisir le nombre d'elements du tableau");
	scanf("%d",&n);
	int *tab = malloc(n * sizeof(int));
	if(tab == NULL){
		printf("erreur d'allocation memoire");
		return 1;
		}
	printf("veuiller remplir le tableau");
	for(i = 0; i < n; i++){
		printf("saisir la valeur %d \n", i);
		scanf("%d", &tab[i]);
	}
	
	for(i = 0; i < n-1; i++){
		
		if(tab[i] >tab[i+1] ){
			printf("tableau non trie");
			return 1;
		}
	}
		printf("tableau trie");
	
}	
