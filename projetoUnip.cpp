#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define o tamanho máximo do nome
#define MAX_NOME 60

// Define a struct que representa um registro
struct Registro
{
    int codigo, idade,  cpf, data;
    double celular;
    char nome[MAX_NOME], endereco[50], email[50];
};

// Define o tamanho máximo da lista
#define MAX_REGISTROS 100

// Define o arquivo que será utilizado para persistir os dados
const char *NOME_ARQUIVO = "registros.dat";

// Define a lista de registros
struct Registro lista[MAX_REGISTROS];

// Define o tamanho atual da lista
int tamanho = 0;

// Fun��o para cadastrar um cliente
void Cliente()
{
    if (tamanho >= MAX_REGISTROS)
    {
        printf("Nao e possivel cadastrar mais registros.\n");
        return;
    }
    
    struct Registro registro;
    printf("Digite o codigo: ");
    scanf("%d", &registro.codigo);
    
    printf("Digite o nome: ");
    scanf("%s", &registro.nome);
    
    printf("Digite a idade: ");
    scanf("%d", &registro.idade);
    
    printf("Digite o numero de telefone: ");
    scanf("%f", &registro.celular);
    
    printf("Digite o cpf: ");
    scanf("%d", &registro.cpf);
    
    printf("Digite a data do aniversario:  ");
    scanf("%d", &registro.data);
    
    printf("Digite o endere�o:  ");
    scanf("%s", &registro.endereco);
    
    printf("Digite o e-mail:  ");
    scanf("%s", &registro.email);
    

    lista[tamanho] = registro;
    tamanho++;

    printf("Registro cadastrado com sucesso.\n");
}

void Funcionario(){
	
	printf("5. Cadastrar\n");
    printf("6. Buscar\n");
    printf("7. Listar\n");
    printf("8. Atualizar\n");
    printf("9. Excluir\n");
    printf("digite uma opcao: ");
    
}



void cadastrar()
{

	if (tamanho >= MAX_REGISTROS)
    {
        printf("Nao e possivel cadastrar mais registros.\n");
        return;
    }
    

    struct Registro registro;
    printf("Digite o codigo: ");
    scanf("%d", &registro.codigo);
    
    printf("Digite o nome: ");
    scanf("%s", &registro.nome);
    
    printf("Digite a idade: ");
    scanf("%d", &registro.idade);
    
    printf("Digite o numero de telefone: ");
    scanf("%f", &registro.celular);
    
    printf("Digite o cpf: ");
    scanf("%d", &registro.cpf);
    
    printf("Ano de nascimento: ");
    scanf("%d", &registro.data);
    
    printf("Digite o endere�o:  ");
    scanf("%s", &registro.endereco);
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
            printf("Data de Aniversario: %d\n", lista[i].data);
            printf("Endere�o: %s\n", lista[i].endereco);
            printf("E-mail: %s\n", lista[i].email);
            return;
        }
    }

    printf("Registro nao encontrado.\n");
}

// Fun��o para listar todos os registros
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
        printf("Endere�o: %s\n", lista[i].endereco);
        printf("E-mail: %s\n", lista[i].email);
        printf("\n");
    }
}

// Fun��o para atualizar um registro pelo codigo
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
            scanf("%d", lista[i].celular);
            printf("Digite o cpf: ");
            scanf("%d", lista[i].cpf);
            printf("Digite a data do aniversario: ");
            scanf("%d", lista[i].data);
            printf("Digite o endere�o: ");
            scanf("%s", lista[i].endereco);
            printf("Digite o e-mail: ");
            scanf("%s", lista[i].email);
            
            printf("Registro atualizado com sucesso.\n");
            return;
        }
    }

    printf("Registro nao encontrado.\n");
}

// Fun��o para excluir um registro pelo codigo
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
// Fun��o para salvar os registros em um arquivo
void salvar()
{
    FILE *arquivo = fopen(NOME_ARQUIVO, "wb");

    if (!arquivo)
    {
        printf("Nao foi possivel abrir o arquivo para escrita.\n");
        return;
    }

    fwrite(lista, sizeof(struct Registro), tamanho, arquivo);
    fclose(arquivo);

    printf("Registros salvos com sucesso.\n");
}

// Fun��o para carregar os registros do arquivo
void carregar()
{
    FILE *arquivo = fopen(NOME_ARQUIVO, "rb");

    if (!arquivo)
    {
        printf("Nao foi possivel abrir o arquivo para leitura.\n");
        return;
    }

    tamanho = fread(lista, sizeof(struct Registro), MAX_REGISTROS, arquivo);
    fclose(arquivo);

    printf("Registros carregados com sucesso.\n");
}

// Fun��o para exibir o menu
void exibirMenu()
{
    printf("\n-- MENU --\n");
    printf("1. cliente\n");
    printf("2. funcionario\n");
    printf("3. Salvar\n");
    printf("4. Carregar\n");
    printf("0. Sair\n");
    printf("Digite uma opcao: ");
}

// Fun��o principal
int main()
{
    //carregar();

    int opcao;
    do
    {
        exibirMenu();
        scanf("%d", &opcao);
        
        Funcionario();
        scanf("%d", &opcao);

        switch (opcao)
        {
        case 0:
            break;
        case 1:
            Cliente();
            break;
        case 2:
        	Funcionario();
        	break;
        case 3:
            salvar();
            break;
        case 4:
            carregar();
            break;
            
        
        case 5:
            cadastrar();
            break;
        case 6:
            buscar();
            break;
        case 7:
            listar();
            break;
        case 8:
            atualizar();
            break;
        case 9:
        	excluir();
        	break;
        default:
            printf("Opcao invalida.\n");
        }
    } while (opcao != 0);

    salvar();

    return 0;
}
