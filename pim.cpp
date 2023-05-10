#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funcionario.cpp"
#include "cliente.cpp"




void exibirMenu()
{
    printf("\n-- MENU --\n");
    printf("1. cliente\n");
    printf("2. funcionario\n");
    printf("0. Sair\n");
    printf("Digite uma opcao: ");
}


// Função principal
int main()
{
    carregar();

    int opcao;
    do
    {
        exibirMenu();
        scanf("%d", &opcao);

        switch (opcao)
        {

        case 1:
            //Cliente();
            break;
        case 2:
        	menuFuncionario();
        	break;
        default:
            printf("Opcao invalida.\n");
        }
        
    
    } while (opcao != 0);
    
    Salvar();

    return 0;
    
}


