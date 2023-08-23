#include <stdio.h>
#include <stdbool.h>
#include <string.h>

typedef struct {
    char nomeTitular[50];
    int numeroConta;
    float saldo;
} ContaBancaria;

ContaBancaria criarConta(const char nome[], int numeroConta, float saldoInicial) {
    ContaBancaria conta;
    strcpy(conta.nomeTitular, nome);
    conta.numeroConta = numeroConta;
    conta.saldo = saldoInicial;
    return conta;
}

void depositar(ContaBancaria *conta, float valor) {
    if (valor > 0) {
        conta->saldo += valor;
        printf("Depósito de %.2f realizado com sucesso.\n", valor);
    } else {
        printf("Valor inválido para depósito.\n");
    }
}

bool sacar(ContaBancaria *conta, float valor) {
    if (valor > 0 && valor <= conta->saldo) {
        conta->saldo -= valor;
        printf("Saque de %.2f realizado com sucesso.\n", valor);
        return true;
    } else {
        printf("Saldo insuficiente ou valor inválido para saque.\n");
        return false;
    }
}

float verificarSaldo(ContaBancaria conta) {
    return conta.saldo;
}

int main() {
    ContaBancaria minhaConta = criarConta("João Silva", 12345, 1000.0);
    
    printf("Saldo inicial: %.2f\n", verificarSaldo(minhaConta));
    
    depositar(&minhaConta, 500.0);
    printf("Saldo após depósito: %.2f\n", verificarSaldo(minhaConta));
    
    sacar(&minhaConta, 200.0);
    printf("Saldo após saque: %.2f\n", verificarSaldo(minhaConta));
    
    return 0;
}

