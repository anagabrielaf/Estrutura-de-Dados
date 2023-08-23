#include <stdio.h>
#include <stdbool.h>


struct Estudante {
    char nome[50];
    int matricula;
    float notas[3];
};


float calcularMedia(float notas[], int numNotas) {
    float soma = 0.0;
    for (int i = 0; i < numNotas; i++) {
        soma += notas[i];
    }
    return soma / numNotas;
}


bool estaAprovado(float media) {
    return media >= 7.0;
}

int main() {
    struct Estudante aluno;

    
    printf("Informe o nome do aluno: ");
    fgets(aluno.nome, sizeof(aluno.nome), stdin);
    
    printf("Informe a matrícula do aluno: ");
    scanf("%d", &aluno.matricula);
    
    for (int i = 0; i < 3; i++) {
        printf("Informe a nota %d do aluno: ", i + 1);
        scanf("%f", &aluno.notas[i]);
    }

    
    float media = calcularMedia(aluno.notas, 3);
    bool aprovado = estaAprovado(media);

    
    printf("\nDados do aluno:\n");
    printf("Nome: %s", aluno.nome);
    printf("Matrícula: %d\n", aluno.matricula);
    printf("Notas: %.2f, %.2f, %.2f\n", aluno.notas[0], aluno.notas[1], aluno.notas[2]);
    printf("Média: %.2f\n", media);
    
    if (aprovado) {
        printf("Situação: Aprovado\n");
    } else {
        printf("Situação: Reprovado\n");
    }

    return 0;
}

