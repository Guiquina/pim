#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funcionario.cpp"
#include "cliente.cpp"

void exibirMenu()
{
    system("cls");
    printf("\n-- MENU --\n");
    printf("1. cliente\n");
    printf("2. funcionario\n");
    printf("0. Sair\n");
    printf("Digite uma opcao: ");
}

// Fun��o principal
int main()
{
    carregarFuncionario();
    carregarCliente();

    int opcao;
    do
    {
        exibirMenu();
        scanf("%d", &opcao);

        switch (opcao)
        {

        case 1:
            Cliente();
            break;
        case 2:
            Funcionario();
            break;

        
        }
    }

    while (opcao != 0);


    return 0;
}
