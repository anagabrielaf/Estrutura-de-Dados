#include <stdio.h>
#include <string.h>
#include <time.h>

typedef struct {
    char nome[50];
    char cargo[30];
    float salario;
    time_t dataAdmissao; 
} Funcionario;

void darAumento(Funcionario *funcionario, float percentual) {
    funcionario->salario *= (1 + percentual / 100);
    printf("Aumento de %.2f%% aplicado ao salario de %s.\n", percentual, funcionario->nome);
}

int calcularTempoNaEmpresa(Funcionario funcionario) {
    time_t agora;
    time(&agora); 

    double diferencaSegundos = difftime(agora, funcionario.dataAdmissao);
    int diferencaDias = diferencaSegundos / (60 * 60 * 24); 

    return diferencaDias;
}

int main() {
    Funcionario funcionario1 = {"Carolina", "Analista", 3500.0, time(NULL) - (365 * 24 * 60 * 60)}; 
    Funcionario funcionario2 = {"Adriano", "Gerente", 5000.0, time(NULL) - (2 * 365 * 24 * 60 * 60)}; 

    printf("Dados dos funcionarios:\n");
    printf("Funcionario 1:\n");
    printf("Nome: %s\nCargo: %s\nSalário: %.2f\n", funcionario1.nome, funcionario1.cargo, funcionario1.salario);

    int diasNaEmpresa1 = calcularTempoNaEmpresa(funcionario1);
    printf("Tempo na empresa: %d dias\n", diasNaEmpresa1);

    printf("\nFuncionario 2:\n");
    printf("Nome: %s\nCargo: %s\nSalário: %.2f\n", funcionario2.nome, funcionario2.cargo, funcionario2.salario);

    int diasNaEmpresa2 = calcularTempoNaEmpresa(funcionario2);
    printf("Tempo na empresa: %d dias\n", diasNaEmpresa2);

    darAumento(&funcionario1, 10.0); /
    printf("Novo salario do funcionário 1: %.2f\n", funcionario1.salario);

    darAumento(&funcionario2, 15.0); 
    printf("Novo salario do funcionário 2: %.2f\n", funcionario2.salario);

    return 0;
}

