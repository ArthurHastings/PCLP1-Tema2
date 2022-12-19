#include <stdio.h>

#define OSUTA 100
int main() {
    int  N = 0;
    char operatie[OSUTA];
    float rezultat = 0, operand[OSUTA], zero = 0;
    scanf("%d", &N);
    if (N == 0) {
        printf("%f\n", zero);
        return 0;
    }
    for (int i = 0; i < N; i++) {
        scanf("%f\n", &operand[i]);
    }
    for (int i = 0; i < N-1; i++) {
        scanf("%c", &operatie[i]);
    }

    rezultat = operand[0];
    for (int i = 0; i < N-1; i++) {
        if (operatie[i] == '*') {
            rezultat *= operand[i+1];
        }
        if (operatie[i] == '/') {
            rezultat /= operand[i+1];
        }
        if (operatie[i] == '+') {
            rezultat += operand[i+1];
        }
        if (operatie[i] == '-') {
            rezultat -= operand[i+1];
        }
    }
    printf("%f\n", rezultat);

    return 0;
}
