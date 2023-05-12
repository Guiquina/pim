#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define o tamanho m�ximo da listaFuncionario
#define MAX_REGISTROS 100

// Define o arquivo que ser� utilizado para persistir os dados
const char *NOME_ARQUIVO_FUNCIONARIO = "registrosFuncionario.dat";

// Define a struct que representa um registro
struct RegistroFuncionario
{
    int codigo, idade, data;
    char nome[50], endereco[50], email[50], celular[50], cpf[50];
};

// Define a listaFuncionario de registros
struct RegistroFuncionario listaFuncionario[MAX_REGISTROS];

// Define o tamanho atual da listaFuncionario
int tamanhoFuncionario = 0;
int opcaoFuncionario;
        
void menuFuncionario(){


	
	printf("1. Cadastrar\n");
    printf("2. Buscar\n");
    printf("3. Listar\n");
    printf("4. Atualizar\n");
    printf("5. Excluir\n");
    printf("0. sair\n");
    printf("digite uma opcao: ");

}

void carregarFuncionario()
{
    FILE *arquivo = fopen(NOME_ARQUIVO_FUNCIONARIO, "rb");

    if (!arquivo)
    {
        printf("Nao foi possivel abrir o arquivo para leitura.\n");
        return;
    }

    tamanhoFuncionario = fread(listaFuncionario, sizeof(struct RegistroFuncionario), MAX_REGISTROS, arquivo);
    fclose(arquivo);

    printf("Registros carregados com sucesso.\n");
}

void salvarFuncionario()
{
    FILE *arquivo = fopen(NOME_ARQUIVO_FUNCIONARIO, "wb");

    if (!arquivo)
    {
        printf("Nao foi possivel abrir o arquivo para escrita.\n");
        return;
    }
    

    fwrite(listaFuncionario, sizeof(struct RegistroFuncionario), tamanhoFuncionario, arquivo);
    fclose(arquivo);

    printf("Registros salvos com sucesso.\n");
}



void cadastrarFuncionario()
{

	if (tamanhoFuncionario >= MAX_REGISTROS)
    {
        printf("Nao e possivel cadastrar mais registros.\n");
        return;
    }

     
    struct RegistroFuncionario registro;
    
    
    printf("Digite o nome: ");
    scanf("%s", &registro.nome);
    fflush(stdin);
    
    
    
    printf("Digite a idade: ");
    scanf("%d", &registro.idade);
    fflush(stdin);
    
    printf("Digite o numero de telefone: ");
    fgets( registro.celular,50,stdin);
    registro.celular[strcspn(registro.celular,"\n")]=0;
    
    
    printf("Digite o cpf: ");
    fgets(registro.cpf,50,stdin);
    registro.cpf[strcspn(registro.cpf,"\n")]=0;
    
    printf("Ano de nascimento: ");
    scanf("%d", &registro.data);
    fflush(stdin);
    
    printf("Digite o endereco:  ");
    fgets(registro.endereco,50,stdin);
    registro.endereco[strcspn(registro.endereco,"\n")]=0;
    
    printf("Digite o e-mail:  ");
    fgets(registro.email,50,stdin);


    carregarFuncionario();
    registro.codigo = tamanhoFuncionario;
    
    listaFuncionario[tamanhoFuncionario] = registro;
    tamanhoFuncionario++;
    salvarFuncionario();
    printf("Registro cadastrado com sucesso.\n");

	
}




// Fun��o para buscar um registro pelo c�digo
void buscarFuncionario()
{
    int codigo;
    printf("Digite o codigo: ");
    scanf("%d", &codigo);

    int i;
    for (i = 0; i < tamanhoFuncionario; i++)
    {
        if (listaFuncionario[i].codigo == codigo)
        {
            printf("Codigo: %d\n", listaFuncionario[i].codigo);
            printf("Nome: %s\n", listaFuncionario[i].nome);
            printf("Idade: %d\n", listaFuncionario[i].idade);
            printf("Celular: %s\n", listaFuncionario[i].celular);
            printf("Cpf: %s\n", listaFuncionario[i].cpf);
            printf("Ano de nascimento: %d\n", listaFuncionario[i].data);
            printf("endereco: %s\n", listaFuncionario[i].endereco);
            printf("E-mail: %s\n", listaFuncionario[i].email);
            return;
        }
    }

    printf("Registro nao encontrado.\n");
}


void listarFuncionario()
{

    carregarFuncionario();
    int i;
    for (i = 0; i < tamanhoFuncionario; i++)
    {
        printf("Codigo: %d\n", listaFuncionario[i].codigo);
        printf("Nome: %s\n", listaFuncionario[i].nome);
        printf("Idade: %d\n", listaFuncionario[i].idade);
        printf("Celular: %s\n", listaFuncionario[i].celular);
        printf("Cpf: %s\n", listaFuncionario[i].cpf);
        printf("Data de Aniversario: %d\n", listaFuncionario[i].data);
        printf("endereco: %s\n", listaFuncionario[i].endereco);
        printf("E-mail: %s\n", listaFuncionario[i].email);
        printf("\n");
    }
}
// Funcao para listar todos os registros


// Fun��o para atualizar um registro pelo codigo
void atualizarFuncionario()
{
    int codigo;
    printf("Digite o codigo: ");
    scanf("%d", &codigo);
    fflush(stdin);

    int i;
    for (i = 0; i < tamanhoFuncionario; i++)
    {
        if (listaFuncionario[i].codigo == codigo)
        {
    
    printf("Digite o nome: ");
    fgets(listaFuncionario[i].nome,50,stdin);
    listaFuncionario[i].nome[strcspn(listaFuncionario[i].nome,"\n")]=0;
    
    printf("Digite a idade: ");
    scanf("%d", &listaFuncionario[i].idade);
    fflush(stdin);
    
    printf("Digite o numero de telefone: ");
    fgets( listaFuncionario[i].celular,50,stdin);
    listaFuncionario[i].celular[strcspn(listaFuncionario[i].celular,"\n")]=0;
    
    
    printf("Digite o cpf: ");
    fgets(listaFuncionario[i].cpf,50,stdin);
    listaFuncionario[i].cpf[strcspn(listaFuncionario[i].cpf,"\n")]=0;
    
    printf("Ano de nascimento:");
    scanf("%d", &listaFuncionario[i].data);
    fflush(stdin);
    
    printf("Digite o endereco:  ");
    fgets(listaFuncionario[i].endereco,50,stdin);
    listaFuncionario[i].endereco[strcspn(listaFuncionario[i].endereco,"\n")]=0;
    
    printf("Digite o e-mail:  ");
    fgets(listaFuncionario[i].email,50,stdin);
            
            
            printf("Registro atualizado com sucesso.\n");
            return;
        }
    }

    printf("Registro nao encontrado.\n");
}

// Fun��o para excluir um registro pelo codigo
void excluirFuncionario()
{
    int codigo;
    printf("Digite o codigo: ");
    scanf("%d", &codigo);

    int i;
    for (i = 0; i < tamanhoFuncionario; i++)
    {
        if (listaFuncionario[i].codigo == codigo)
        {
            int j;
            for (j = i; j < tamanhoFuncionario - 1; j++)
            {
                listaFuncionario[j] = listaFuncionario[j + 1];
            }
            tamanhoFuncionario--;
            printf("Registro excluido com sucesso.\n");
            return;
        }

        printf("Registro nao encontrado.\n");
    }
}
// Fun��o para salvar os registros em um arquivo


// Fun��o para carregar os registros do arquivo

int Funcionario()
{

    int opcaoFuncionario;
do
{
    menuFuncionario();
    scanf("%d", &opcaoFuncionario);
    

    switch (opcaoFuncionario)
    {
    case 1:
        cadastrarFuncionario();
        break;
    case 2:
        buscarFuncionario();
        break;
    case 3:
         listarFuncionario();
         break;
    case 4:
        atualizarFuncionario();
        break;
    case 5:
        excluirFuncionario();
        break;
    
    default:
        printf("Opcao invalida. \n");
    }
}




while (opcaoFuncionario == 0 );

    salvarFuncionario();

    return 0;
}