#include <stdio.h>

int numero[5];



int acharNumeroPar(){
   int ultimoPar = -1;
   for(int i=0; i < 5; i++){
        if ( numero[i] % 2 == 0){
            ultimoPar = numero[i];
        }

   }

    return ultimoPar;
}

int main()
{
    numero[0]=1;
    numero[1]=5;
    numero[2]=-4;
    numero[3]=9;
    numero[4]=2;
    int excluir = -1;
    printf("Digite o número para excluir");
    scanf("%d", &excluir );

    int novaLista[5];
    int posicaoNovaLista=0;
    for(int i=0 ; i < 5; i++){
        if ( numero[i] != excluir ){
            novaLista[posicaoNovaLista]= numero[i];
            posicaoNovaLista++;
        }
    }

    for(int i=0; i < 5; i++){
        printf("%d = %d\n", i, numero[i]);
    }


}
