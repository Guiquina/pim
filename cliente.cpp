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
RegistroCliente listaCliente[MAX_REGISTROS];
RegistroCliente novaListacliente[MAX_REGISTROS];
// Define o tamanho atual da listaCliente
int tamanhoCliente = 0;
int opcaoCliente;
void menuCliente()
{
    system("cls");
    printf("1. Cadastrar\n");
    printf("2. Buscar\n");
    printf("3. Listar\n");
    printf("4. Atualizar\n");
    printf("5. Excluir\n");
    printf("0. sair\n");
    printf("digite uma opcao: ");
}

void carregarCliente()
{
    FILE *arquivo = fopen(NOME_ARQUIVO_CLIENTE, "rb");

    if (!arquivo)
    {
        printf("Nao foi possivel abrir o arquivo para leitura.\n");
        return;
    }

    tamanhoCliente = fread(listaCliente, sizeof(struct RegistroCliente), MAX_REGISTROS, arquivo);
    fclose(arquivo);

    printf("Registros carregados com sucesso.\n");
}

void salvarCliente()
{
    FILE *arquivo = fopen(NOME_ARQUIVO_CLIENTE, "wb");

    if (!arquivo)
    {
        printf("Nao foi possivel abrir o arquivo para escrita.\n");
        return;
    }

    fwrite(listaCliente, sizeof(struct RegistroCliente), tamanhoCliente, arquivo);
    fclose(arquivo);

    printf("Registros salvos com sucesso.\n");
}

int gerarCodigoCliente()
{

    int i, codigo = 0, adicionar = 0;
    for (i = 0; i < tamanhoCliente; i++)
    {

        if (listaCliente[i].codigo != codigo)
        {

            adicionar = listaCliente[i].codigo;
        }
    }
    return adicionar + 1;
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
    fgets(registro.celular, 50, stdin);
    registro.celular[strcspn(registro.celular, "\n")] = 0;

    printf("Digite o cpf: ");
    fgets(registro.cpf, 50, stdin);
    registro.cpf[strcspn(registro.cpf, "\n")] = 0;

    printf("Ano de nascimento:");
    scanf("%d", &registro.data);
    fflush(stdin);

    printf("Digite o endereco:  ");
    fgets(registro.endereco, 50, stdin);
    registro.endereco[strcspn(registro.endereco, "\n")] = 0;

    printf("Digite o e-mail:  ");
    fgets(registro.email, 50, stdin);

    carregarCliente();
    registro.codigo = gerarCodigoCliente();
    listaCliente[tamanhoCliente] = registro;
    tamanhoCliente++;
    salvarCliente();
    printf("Registro cadastrado com sucesso.\n");
    system("cls");
}


void buscarCliente()
{
    int codigo;
    printf("Digite o codigo: ");
    scanf("%d", &codigo);

    int i;
    for (i = 0; i < tamanhoCliente; i++)
    {
        if (codigo == listaCliente[i].codigo)
        {
            printf("Codigo: %d\n", listaCliente[i].codigo);
            printf("Nome: %s\n", listaCliente[i].nome);
            printf("Idade: %d\n", listaCliente[i].idade);
            printf("Celular: %s\n", listaCliente[i].celular);
            printf("Cpf: %s\n", listaCliente[i].cpf);
            printf("Ano de nascimento: %d\n", listaCliente[i].data);
            printf("endereco: %s\n", listaCliente[i].endereco);
            printf("E-mail: %s\n", listaCliente[i].email);
            
        }
       
    }
    if(codigo > tamanhoCliente){
        printf("Registro nao encontrado.\n");
    }
     getch();
        system("cls");
        return menuCliente();
}


void listarCliente()
{

    carregarCliente();

    int i;
    printf("==================================================================================================================================================\n");
        
    printf("%-10s%-25s%-6s%-15s%-6s%-30s\n","Codigo","Nome","Idade","Cpf","Ano","Endereco");
    
    printf("==================================================================================================================================================\n");

    for (i = 0; i < tamanhoFuncionario; i++)
    {
        printf("%-10d%-25s%-6d%-15s%-6d%-30s*\n",
            listaFuncionario[i].codigo,
            listaFuncionario[i].nome,
            listaFuncionario[i].idade,
            listaFuncionario[i].cpf,
            listaFuncionario[i].data,
            listaFuncionario[i].endereco);
    
    }
    getch();
    system("cls");

    return  menuFuncionario();
}

// Funcao para atualizar um registro pelo codigo
void atualizarCliente()
{
    int codigo;
    printf("Digite o codigo: ");
    scanf("%d", &codigo);
    fflush(stdin);

    int i;
    for (i = 0; i < tamanhoCliente; i++)
    {
        if (listaCliente[i].codigo == codigo)
        {

            printf("Digite o nome: ");
            fgets(listaCliente[i].nome, 50, stdin);
            listaCliente[i].nome[strcspn(listaCliente[i].nome, "\n")] = 0;

            printf("Digite a idade: ");
            scanf("%d", &listaCliente[i].idade);
            fflush(stdin);

            printf("Digite o numero de telefone: ");
            fgets(listaCliente[i].celular, 50, stdin);
            listaCliente[i].celular[strcspn(listaCliente[i].celular, "\n")] = 0;

            printf("Digite o cpf: ");
            fgets(listaCliente[i].cpf, 50, stdin);
            listaCliente[i].cpf[strcspn(listaCliente[i].cpf, "\n")] = 0;

            printf("Ano de nascimento:");
            scanf("%d", &listaCliente[i].data);
            fflush(stdin);

            printf("Digite o endereco:  ");
            fgets(listaCliente[i].endereco, 50, stdin);
            listaCliente[i].endereco[strcspn(listaCliente[i].endereco, "\n")] = 0;

            printf("Digite o e-mail:  ");
            fgets(listaCliente[i].email, 50, stdin);

            printf("Registro atualizado com sucesso.\n");
            salvarCliente();
            
        }
        getch();
        system("cls");

        return menuFuncionario();
    }

    printf("Registro nao encontrado.\n");
}

// Fun��o para excluir um registro pelo codigo
void excluirCliente()
{
    int codigo;
    printf("Digite o codigo: ");
    scanf("%d", &codigo);

    int posicaoNovalistacliente = 0;
    int i;
    for (i = 0; i < tamanhoCliente; i++)
    {
        if (listaCliente[i].codigo != codigo)
        {
            novaListacliente[posicaoNovalistacliente] = listaCliente[i];

            posicaoNovalistacliente++;

            FILE *arquivo = fopen(NOME_ARQUIVO_CLIENTE, "wb");

            if (!arquivo)
            {
                printf("Nao foi possivel abrir o arquivo para escrita.\n");
                return;
            }

            fwrite(novaListacliente, sizeof(struct RegistroCliente), posicaoNovalistacliente, arquivo);
            fclose(arquivo);
        }
        else if(listaCliente[i].codigo == codigo){

            tamanhoCliente - 1;
        }
        else
        {
          printf("Registro nao encontrado.\n");
        }
     
    }
    printf("registro excluido com sucesso.\n");
    getch();
    system("cls");
    return menuFuncionario();
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
        }
    }

    while (opcaocliente != 0);

    salvarCliente();

    return 0;
}