#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define o tamanho máximo da lista
#define MAX_REGISTROS 100

// Define o arquivo que será utilizado para persistir os dados
const char *NOME_ARQUIVO = "registrosFuncionario.dat";

// Define a struct que representa um registro
struct RegistroFuncionario
{
    int codigo, idade, data; 
    char nome[50], cidade[50], email[50], celular[50], cpf[50];
};

// Define a lista de registros
struct RegistroFuncionario lista[MAX_REGISTROS];

// Define o tamanho atual da lista
int tamanho = 0;

void menuFuncionario(){


	
	printf("1. Cadastrar\n");
    printf("2. Buscar\n");
    printf("3. Listar\n");
    printf("4. Atualizar\n");
    printf("6. Excluir\n");
    printf("digite uma opcao: ");
    
}


void cadastrarFuncionario()
{

	if (tamanho >= MAX_REGISTROS)
    {
        printf("Nao e possivel cadastrar mais registros.\n");
        return;
    }
    

    struct RegistroFuncionario registro;
    printf("Digite o codigo: ");
    scanf("%d", &registro.codigo);
    
    printf("Digite o nome: ");
    scanf("%s", &registro.nome);
    
    printf("Digite a idade: ");
    scanf("%d", &registro.idade);
    
    printf("Digite o numero de telefone: ");
    scanf("%s", &registro.celular);
    
    printf("Digite o cpf: ");
    scanf("%s", &registro.cpf);
    
    printf("Ano de nascimento: ");
    scanf("%d", &registro.data);
    
    printf("Digite a cidade:  ");
    scanf("%s", &registro.cidade);
    //regsitro.endereco=gets();
    
    printf("Digite o e-mail:  ");
    scanf("%s", &registro.email);

    

    lista[tamanho] = registro;
    tamanho++;

    printf("Registro cadastrado com sucesso.\n");

	
}






// Função para buscar um registro pelo código
void buscar()
{
    int codigo;
    printf("Digite o codigo: ");
    scanf("%d", &codigo);

    int i;
    for (i = 0; i < tamanho; i++)
    {
        if (lista[i].codigo == codigo)
        {
            printf("Codigo: %d\n", lista[i].codigo);
            printf("Nome: %s\n", lista[i].nome);
            printf("Idade: %d\n", lista[i].idade);
            printf("Celular: %d\n", lista[i].celular);
            printf("Cpf: %d\n", lista[i].cpf);
            printf("Ano de nascimento: %d\n", lista[i].data);
            printf("cidade: %s\n", lista[i].cidade);
            printf("E-mail: %s\n", lista[i].email);
            return;
        }
    }

    printf("Registro nao encontrado.\n");
}

// Funcao para listar todos os registros
void listar()
{
    int i;
    for (i = 0; i < tamanho; i++)
    {
        printf("Codigo: %d\n", lista[i].codigo);
        printf("Nome: %s\n", lista[i].nome);
        printf("Idade: %d\n", lista[i].idade);
        printf("Celular: %d\n", lista[i].celular);
        printf("Cpf: %d\n", lista[i].cpf);
        printf("Data de Aniversario: %d\n", lista[i].data);
        printf("Cidade: %s\n", lista[i].cidade);
        printf("E-mail: %s\n", lista[i].email);
        printf("\n");
    }
}

// Funo para atualizar um registro pelo codigo
void atualizar()
{
    int codigo;
    printf("Digite o codigo: ");
    scanf("%d", &codigo);

    int i;
    for (i = 0; i < tamanho; i++)
    {
        if (lista[i].codigo == codigo)
        {
            printf("Digite o novo nome: ");
            scanf("%s", lista[i].nome);
            printf("Digite a idade: ");
            scanf("%d", lista[i].idade);
            printf("Digite o numero de telefone: ");
            scanf("%s", lista[i].celular);
            printf("Digite o cpf: ");
            scanf("%s", lista[i].cpf);
            printf("Digite a data do aniversario: ");
            scanf("%s", lista[i].data);
            printf("Digite a cidade: ");
            scanf("%s", lista[i].cidade);
            printf("Digite o e-mail: ");
            scanf("%s", lista[i].email);
            
            printf("Registro atualizado com sucesso.\n");
            return;
        }
    }

    printf("Registro nao encontrado.\n");
}

// Funo para excluir um registro pelo codigo
void excluir()
{
    int codigo;
    printf("Digite o codigo: ");
    scanf("%d", &codigo);

    int i;
    for (i = 0; i < tamanho; i++)
    {
        if (lista[i].codigo == codigo)
        {
            int j;
            for (j = i; j < tamanho - 1; j++)
            {
                lista[j] = lista[j + 1];
            }
            tamanho--;
            printf("Registro excluido com sucesso.\n");
            return;
        }

        printf("Registro nao encontrado.\n");
    }
}
// Funo para salvar os registros em um arquivo
void Salvar()
{
    FILE *arquivo = fopen(NOME_ARQUIVO, "wb");

    if (!arquivo)
    {
        printf("Nao foi possivel abrir o arquivo para escrita.\n");
        return;
    }

    fwrite(lista, sizeof(struct RegistroFuncionario), tamanho, arquivo);
    fclose(arquivo);

    printf("Registros salvos com sucesso.\n");
}

// Funo para carregar os registros do arquivo
void carregar()
{
    FILE *arquivo = fopen(NOME_ARQUIVO, "rb");

    if (!arquivo)
    {
        printf("Nao foi possivel abrir o arquivo para leitura.\n");
        return;
    }

    tamanho = fread(lista, sizeof(struct RegistroFuncionario), MAX_REGISTROS, arquivo);
    fclose(arquivo);

    printf("Registros carregados com sucesso.\n");
}
