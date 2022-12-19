#include <stdio.h>
#define OSUTA 100
void stergere_operand(float operand[], int indice, int N) {
    for (int i = indice; i < N-1; i++) {
        operand[i] = operand[i+1];
    }
}

void stergere_operatie(char operatie[], int indice, int N) {
    for (int i = indice; i < N-1; i++) {
        operatie[i] = operatie[i+1];
    }
}

int main() {
    int N = 0;
    char operatie[OSUTA];
    float operand[OSUTA];
    scanf("%d\n", &N);
    for (int i = 0; i < N; i++) {
        scanf("%f\n", &operand[i]);
    }
    for (int i = 0; i < N-1; i++) {
        scanf("%c", &operatie[i]);
    }
    for (int i = 0; i < N-1; i++) {
        if (operatie[i] == '*') {
            operand[i] = operand[i] * operand[i+1];
            stergere_operand(operand, i+1, N);
            stergere_operatie(operatie, i, N-1);
            N--;
            i--;
        }
        if (operatie[i] == '/') {
            operand[i] = operand[i] / operand[i+1];
            stergere_operand(operand, i+1, N);
            stergere_operatie(operatie, i, N-1);
            N--;
            i--;
        }
    }
    for (int i = 0; i < N-1; i++) {
        if (operatie[i] == '#') {
            operand[i] = (operand[i] + operand[i+1])
            *(operand[i] + operand[i+1]);
            stergere_operand(operand, i+1, N);
            stergere_operatie(operatie, i, N-1);
            N--;
            i--;
        }
    }
    for (int i = 0; i < N-1; i++) {
        if (operatie[i] == '+') {
            operand[i] = operand[i] + operand[i+1];
            stergere_operand(operand, i+1, N);
            stergere_operatie(operatie, i, N-1);
            N--;
            i--;
        }
        if (operatie[i] == '-') {
            operand[i] = operand[i] - operand[i+1];
            stergere_operand(operand, i+1, N);
            stergere_operatie(operatie, i, N-1);
            N--;
            i--;
        }
    }
    printf("%f\n", operand[0]);
    return 0;
}
