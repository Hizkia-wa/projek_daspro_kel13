#include <stdio.h>

int main() {
    char biner[50];
    int i, pjg = 0;
    printf("Input biner: ");
    scanf("%s", biner);
    while(biner[pjg] != '\0') {
        if(biner[pjg] != '0' && biner[pjg] != '1') {
            printf("Error: Hanya 0 dan 1\n");
            return 1;
        }
        pjg++;
    }
    printf("Polinomial: ");
    
   
    for(i = 0; i < pjg; i++) {
        if(biner[i] == '1') {
            if(i > 0) printf(" + ");
            int pangkat = pjg - 1 - i;
            if(pangkat == 0) printf("1");
            else if(pangkat == 1) printf("x");
            else printf("x^%d", pangkat);
        }
    }
    printf("\n");
    
    return 0;
}

