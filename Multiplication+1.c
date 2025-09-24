#include <stdio.h>

int a, b, produit;

int main(){
    printf("entrer un entier positif\n");
    scanf("%d", &a);

    printf("entrer encore un entier positif\n");
    scanf("%d", &b);

    for (int i = 0; i < b; i++) {        
        for (int j = 0; j < a; j++) {      
            produit = produit + 1;
        }
    }

    printf("%d × %d = %d\n", a, b, produit);
    
    return 0;
}