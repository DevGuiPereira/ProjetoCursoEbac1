#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <windows.h>
#include <string.h>

struct tipocadastro 
{
    char cpf[41];
    char arquivo[41];
    char nome[41];
    char sobrenome[41];
    char cargo[41];
};

void cadastro();
void consulta();
void deletar();

int main()
{
    int op;

    do //loop menu
    {
        setlocale(LC_ALL,"portuguese");

        printf("### MENU ###\n\n");
        printf("Escolha uma opção:\n");
        printf("\t1: CADASTRO\n");
        printf("\t2: CONSULTA\n");    //menu
        printf("\t3: DELETAR\n");
        printf("\t0: SAIR\n");
        printf("opção: ");
        scanf("%d",&op);

        switch (op) //ver qual a opção do usuário para seguir em frente com a função desejada
        {
            case 0:
                system("cls");//limpar o prompt
                return 0;  //sair do prograna
            case 1:
                cadastro();
                Sleep(1000);//esperar 1000 milisegundos para ir para próxima ação
                system("cls");
                break;
            case 2:
                consulta();
                Sleep(1000);
                system("cls");
                break; 
            case 3:
                deletar();
                Sleep(1000);
                system("cls");
                break;
            default:
                printf("escolha uma opção válida...");
                Sleep(1000);
                system("cls");
                break;
        }

    }while(op!=0);
    
    return 0;
}

void cadastro()//função de cadastrar alunos
{
    setlocale(LC_ALL,"portuguese");

    struct tipocadastro pessoa;

    printf("Digite o Cpf: ");
    scanf("%s",pessoa.cpf);

    strcpy(pessoa.arquivo, pessoa.cpf);

    FILE *file;
    file = fopen(pessoa.arquivo,"w");

    if(file == NULL){
        printf("erro ao abrir o arquivo!\n");
        return;
    }

    printf("qual o nome: ");
    scanf("%s", pessoa.nome);
    printf("qual o sobrenome: ");
    scanf("%s", pessoa.sobrenome);
    printf("qual o cargo: ");
    scanf("%s", pessoa.cargo);

    fprintf(file, "Cpf:%s\tNome:%s\tSobrenome:%s\tCargo:%s", pessoa.cpf , pessoa.nome , pessoa.sobrenome , pessoa.cargo);

    fclose(file);
    
    printf("cadastro realizado com sucesso");

}

void consulta()//função de consultar alunos
{
    setlocale(LC_ALL,"portuguese");

    char Cpf[41];
    char Consulta[200];

    printf("Digite o CPF que deseja consultar: ");
    scanf("%s",Cpf);

    FILE *file;
    file = fopen(Cpf,"r");

    if(file == NULL)
    {
        printf("Não foi possivel abrir o arquivo, não localizado\n");
    }

    while(fgets(Consulta, 200, file) != NULL)
    {
        printf("Informações do Usuário: ");
        printf("%s\n\n", Consulta);
    }

    system("pause");

}

void deletar()//função deletar alunos
{
    
    char Cpf[41];

    printf("Digite o CPF que deseja deletar: ");
    scanf("%s",Cpf);

    FILE *file;
    file = fopen(Cpf,"r");

    if(file == NULL)
    {
        printf("Não foi possivel abrir o arquivo, não localizado\n");
        system("pause");
    }
    else
    {
        fclose(file);
        remove(Cpf);
        printf("arquivo deletado com sucesso...\n\n");
    }

    system("pause");
}