#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define o tamanho m�ximo da listaCliente
#define MAX_REGISTROS 100

// Define o arquivo que ser� utilizado para persistir os dados
const char *NOME_ARQUIVO_CLIENTE = "registrosCliente.dat";

// Define a struct que representa um registro
struct RegistroCliente
{
    int codigo, idade, data; 
    char nome[50], endereco[50], email[50], celular[50], cpf[50];
};

// Define a listaCliente de registros
struct RegistroCliente listaCliente[MAX_REGISTROS];

// Define o tamanho atual da listaCliente
int tamanhoCliente = 0;

void menuCliente(){


	
	printf("1. Cadastrar\n");
    printf("2. Buscar\n");
    printf("3. Listar\n");
    printf("4. Atualizar\n");
    printf("5. Excluir\n");
    printf("6. salvar\n");
    printf("0. sair\n");
    printf("digite uma opcao: ");


    
    
}



void cadastrarcliente()
{

	if (tamanhoCliente >= MAX_REGISTROS)
    {
        printf("Nao e possivel cadastrar mais registros.\n");
        return;
    }


    struct RegistroCliente registro;
    
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
    
    printf("Ano de nascimento:");
    scanf("%d", &registro.data);
    fflush(stdin);
    
    printf("Digite o endereco:  ");
    fgets(registro.endereco,50,stdin);
    registro.endereco[strcspn(registro.endereco,"\n")]=0;
    
    printf("Digite o e-mail:  ");
    fgets(registro.email,50,stdin);
    
    registro.codigo = tamanhoCliente;

    

 listaCliente[tamanhoCliente] = registro;
    tamanhoCliente++;

    printf("Registro cadastrado com sucesso.\n");

	
}






// Fun��o para buscar um registro pelo c�digo
void buscarCliente()
{
    int codigo;
    printf("Digite o codigo: ");
    scanf("%d", &codigo);

    int i ;
    for (i = 1; i < tamanhoCliente; i++)
    {
        if  (listaCliente[i].codigo == codigo)
        {
            printf("Codigo: %d\n", listaCliente[i].codigo);
            printf("Nome: %s\n", listaCliente[i].nome);
            printf("Idade: %d\n", listaCliente[i].idade);
            printf("Celular: %s\n", listaCliente[i].celular);
            printf("Cpf: %s\n", listaCliente[i].cpf);
            printf("Ano de nascimento: %d\n", listaCliente[i].data);
            printf("endereco: %s\n", listaCliente[i].endereco);
            printf("E-mail: %s\n", listaCliente[i].email);
            return;
        }
    }

    printf("Registro nao encontrado.\n");
}

// Funcao para listar todos os registros
void listarCliente()
{
    int i;
    for (i = 1; i < tamanhoCliente; i++)
    {
        printf("Codigo: %d\n", listaCliente[i].codigo);
        printf("Nome: %s\n", listaCliente[i].nome);
        printf("Idade: %d\n", listaCliente[i].idade);
        printf("Celular: %s\n", listaCliente[i].celular);
        printf("Cpf: %s\n", listaCliente[i].cpf);
        printf("Data de Aniversario: %d\n", listaCliente[i].data);
        printf("endereco: %s\n", listaCliente[i].endereco);
        printf("E-mail: %s\n", listaCliente[i].email);
        printf("\n");
    }
}

// Funcao para atualizar um registro pelo codigo
void atualizarCliente()
{
    int codigo;
    printf("Digite o codigo: ");
    scanf("%d", &codigo);
    fflush(stdin);

    int i;
    for (i = 1; i < tamanhoCliente; i++)
    {
        if  (listaCliente[i].codigo == codigo)
        {
    
    printf("Digite o nome: ");
    fgets (listaCliente[i].nome,50,stdin);
 listaCliente[i].nome[strcspn (listaCliente[i].nome,"\n")]=0;
    
    printf("Digite a idade: ");
    scanf("%d",  listaCliente[i].idade);
    fflush(stdin);
    
    printf("Digite o numero de telefone: ");
    fgets( listaCliente[i].celular,50,stdin);
 listaCliente[i].celular[strcspn (listaCliente[i].celular,"\n")]=0;
    
    
    printf("Digite o cpf: ");
    fgets (listaCliente[i].cpf,50,stdin);
 listaCliente[i].cpf[strcspn (listaCliente[i].cpf,"\n")]=0;
    
    printf("Ano de nascimento:");
    scanf("%d",  listaCliente[i].data);
    fflush(stdin);
    
    printf("Digite o endereco:  ");
    fgets (listaCliente[i].endereco,50,stdin);
 listaCliente[i].endereco[strcspn (listaCliente[i].endereco,"\n")]=0;
    
    printf("Digite o e-mail:  ");
    fgets (listaCliente[i].email,50,stdin);
            
            
            printf("Registro atualizado com sucesso.\n");
            return;
        }
    }

    printf("Registro nao encontrado.\n");
}

// Fun��o para excluir um registro pelo codigo
void excluirCliente()
{
    int codigo;
    printf("Digite o codigo: ");
    scanf("%d", &codigo);

    int i;
    for (i = 0; i < tamanhoCliente; i++)
    {
        if  (listaCliente[i].codigo == codigo)
        {
            int j;
            for (j = i; j < tamanhoCliente - 1; j++)
            {
             listaCliente[j] = listaCliente[j + 1];
            }
            tamanhoCliente--;
            printf("Registro excluido com sucesso.\n");
            return;
        }

        printf("Registro nao encontrado.\n");
    }
}
// Função para salvar os registros em um arquivo
void salvarCliente()
{
    FILE *arquivo = fopen(NOME_ARQUIVO_CLIENTE, "wb");

    if (!arquivo)
    {
        printf("Nao foi possivel abrir o arquivo para escrita.\n");
        return;
    }

    fwrite (listaCliente, sizeof(struct RegistroCliente), tamanhoCliente, arquivo);
    fclose(arquivo);

    printf("Registros salvos com sucesso.\n");
}

// Função para carregar os registros do arquivo
void carregarCliente()
{
    FILE *arquivo = fopen(NOME_ARQUIVO_CLIENTE, "rb");

    if (!arquivo)
    {
        printf("Nao foi possivel abrir o arquivo para leitura.\n");
        return;
    }

    tamanhoCliente = fread (listaCliente, sizeof(struct RegistroCliente), MAX_REGISTROS, arquivo);
    fclose(arquivo);

    printf("Registros carregados com sucesso.\n");
}


int Cliente()
{

    int opcaocliente;
do
{
    menuCliente();
    scanf("%d", &opcaocliente);
    

    switch (opcaocliente)
    {
    case 1:
        cadastrarcliente();
        break;
    case 2:
        buscarCliente();
        break;
    case 3:
        listarCliente();
        break;
    case 4:
        atualizarCliente();
        break;
    case 5:
        excluirCliente();
        break;
    case 6:
        salvarCliente();
        break;

    default:
        printf("Opcao invalida. \n");
    }
}




while (opcaocliente != 0 );

    salvarCliente();

    return 0;
}