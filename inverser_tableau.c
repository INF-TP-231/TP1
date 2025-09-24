#include <stdio.h>

int T[5] = {1, 2, 3, 4, 5};


int main() {
   

    int n = 5;
    int debut = 0, fin = n - 1, temp;

    for (int i = 0; i < n; i++) {
        printf("%d ", T[i]);
    }
    
    printf("inverse...\n");

    while (debut < fin) {
        temp = T[debut];
        T[debut] = T[fin];
        T[fin] = temp;
        debut++;
        fin--;
    }

    for (int i = 0; i < n; i++) {
        printf("%d ", T[i]);
    }

    return 0;
}
