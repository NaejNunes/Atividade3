#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <locale.h>
#include <string.h>

typedef struct
{
    char nomeCliente[30];
    int anoNascimentoClient;
    float montanteGastoCliente;
}Cliente;

typedef struct
{
    Cliente *pCliente;
}ListaCliente;

    int quantidadeCliente = 0;

    ListaCliente novaListaCliente;
    Cliente novoCliente;

void CadastrarCliente()
{
     if(quantidadeCliente >= 10)
        novaListaCliente.pCliente = (Cliente *) realloc(novaListaCliente.pCliente, 10 * sizeof(Cliente));

    printf("----------CADASTRO DE CLIENTE----------\n\n");

    printf("Insira o nome do cliente\n");
    scanf("%s", &novaListaCliente.pCliente[quantidadeCliente].nomeCliente);

    printf("Insira o ano de nascimento do cliente\n");
    scanf("%d", &novaListaCliente.pCliente[quantidadeCliente].anoNascimentoClient);

    printf("Insira o montante gasto pelo cliente\n");
    scanf("%f", &novaListaCliente.pCliente[quantidadeCliente].montanteGastoCliente);

    quantidadeCliente++;

    system("cls");

    MostrarMenu();
}
void ExcluirCliente()
{
    char nomeClienteAuxiliar[30];

        printf("----------Exluir Cliente----------\n\n");

        printf("Informe o nome do cliente que deseja excluir\n");
        scanf("%s", nomeClienteAuxiliar);

        for(int i = 0; i < quantidadeCliente; i++)
        {
            int check;

            check = strcmp(novaListaCliente.pCliente[i].nomeCliente, nomeClienteAuxiliar);

            if(check == 0)
            {
                remover(i);
                printf("Cliente Excluido com sucesso!\n\n");

                MostrarMenu();
            }
             if(check == 1)
            {
                printf("Esse cliente não consta em nossos registros\n\n");
                MostrarMenu();
            }
        }

    system("cls");
}

void remover(int index)
{
    for(int i = index; i < quantidadeCliente; i++)
    {
        memcpy(&novaListaCliente.pCliente[i], &novaListaCliente.pCliente[i+1], sizeof(Cliente));
    }
    quantidadeCliente--;
}

void ViradaMes()
{
    for(int i = 0; i < quantidadeCliente; i++)
    {
         novaListaCliente.pCliente[i].montanteGastoCliente = 0;
    }

    printf("Virada de Mês! Todos clientes tiveram seus gastos zerados\n\n");
    MostrarMenu();
}
void ClienteMelhorComprador()
{
    int i, iAuxiliar;
    float auxiliarMelhorComprar;

    for(i = 0; i <= quantidadeCliente; i++)
    {
        if(auxiliarMelhorComprar < novaListaCliente.pCliente[i].montanteGastoCliente)
        {
            auxiliarMelhorComprar = novaListaCliente.pCliente[i].montanteGastoCliente;
            iAuxiliar = i;
        }

        if(i >= quantidadeCliente)
        {
            printf("O melhor comprar até agora:\n");
            printf("Nome: %s\n", novaListaCliente.pCliente[iAuxiliar].nomeCliente);
            printf("Valor gasto: R$:%2.f,00 \n", auxiliarMelhorComprar);

            MostrarMenu();
        }
    }
}

void ExibirContasClienteEspecifico()
{
    if(quantidadeCliente == 0)
    {
        printf("Lista de clientes vazia!\n\n");
        MostrarMenu();
    }

    else
    {
        char nomeClienteAuxiliar[30];

        printf("----------EXIBIR CONTAS DO CLIENTE----------\n\n");

        printf("Informe o nome do cliente que deseja saber as informações\n");
        scanf("%s", nomeClienteAuxiliar);

        for(int i = 0; i < quantidadeCliente; i++)
        {
            int check;

            check = strcmp(novaListaCliente.pCliente[i].nomeCliente, nomeClienteAuxiliar);

            if(check == 0)
            {
                printf("----CLIENTE----\n");

                printf("Nome: %s \n", novaListaCliente.pCliente[i].nomeCliente);
                printf("Valor gasto: R$:%2.f,00 \n", novaListaCliente.pCliente[i].montanteGastoCliente);

                MostrarMenu();
            }
             if(check == 1)
            {
                printf("Cliente nao cadastrado!\n");
                MostrarMenu();
            }
        }
    }
}

void MostrarMenu()
{
    int indexMenu;
    printf("----------TELA DE MENU-----------\n\n");

    printf("(1) - Cadastrar cliente\n");
    printf("(2) - Excluir cliente\n");
    printf("(3) - Virada do mês (zerar gastos)\n");
    printf("(4) - Listar cliente melhor comprador\n");
    printf("(5) - Mostrar montante gasto por cliente especifico\n");
    printf("(6) - Fechar o sistema\n\n");

    printf("Insira o número conforme a opção desejada\n");
    scanf("%d", &indexMenu);

    OpcoesMenu(indexMenu);
}

void OpcoesMenu(int index)
{
    switch(index)
    {
        case 1:
            CadastrarCliente();
            system("cls");
        break;

        case 2:
            ExcluirCliente();
            system("cls");
        break;

        case 3:
            ViradaMes();
            system("cls");
        break;

        case 4:
            ClienteMelhorComprador();
            system("cls");
        break;

        case 5:
            ExibirContasClienteEspecifico();
            system("cls");
        break;

        case 6:
            system("cls");
        break;
    }
}
int main()
{
    setlocale(LC_ALL, "Portuguese");

    novaListaCliente.pCliente = (Cliente *)malloc(10 * sizeof(Cliente));

    MostrarMenu();

    return 0;
}
