#include <stdio.h>
#include <string.h>
#include <ctype.h>
/* Structs - List 2 - Exercise 11 */
typedef struct {
    int day;
    int month;
    int year;
} Date;

typedef struct {
    char name[50];
    char rg[10];
    float salario;
    char sex;
    Date birthDate;
} TipoReg;

typedef struct {
    TipoReg Funcionario[100];
    int quant;
} TipoCadastro;

int count = 0;

void clearBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

void treatSentence(char *sentence) {
    char *p;

    if(p=strchr(sentence, '\n')) {
        *p = 0;
    }
    else {
        scanf("%[^\n]");
        scanf("%*c");
    }
}

void IniciaCadastro(TipoCadastro *cadastro) {
    cadastro->quant = 0;
}

void LeFuncionarios(TipoCadastro *cadastro) {
    int userOption = 1;
    do {
        if (cadastro->quant >= 100) {
            printf("Ja foram cadastrados todos os funcionarios possiveis %d\n", cadastro->quant);
            userOption = 0;
        }

        printf("Digite o nome do funcionario:\n");
        fgets(cadastro->Funcionario[cadastro->quant].name, 50, stdin);
        treatSentence(cadastro->Funcionario[cadastro->quant].name);

        printf("Digite a data de nascimento do funcionario (dd/mm/yyyy):\n");
        scanf("%d/%d/%d", &cadastro->Funcionario[cadastro->quant].birthDate.day,&cadastro->Funcionario[cadastro->quant].birthDate.month,&cadastro->Funcionario[cadastro->quant].birthDate.year);
        clearBuffer();

        printf("Digite o RG do funcionario:\n");
        fgets(cadastro->Funcionario[cadastro->quant].rg, 10, stdin);
        treatSentence(cadastro->Funcionario[cadastro->quant].rg);

        printf("Qual o sexo do funcionario?:\n");
        printf("Digite M - Masculino e F - Feminino\n");
        scanf(" %c", &cadastro->Funcionario[cadastro->quant].sex);
        clearBuffer();
        
        printf("Digite o CR do funcionario:\n");
        scanf("%f", &cadastro->Funcionario[cadastro->quant].salario);
        clearBuffer();

        cadastro->quant++;

        do {
            printf("Deseja continuar registrando novos funcionarios?\nDigite 1 - Sim | Digite 0 - Nao\n");
            scanf("%d", &userOption);
        } while (userOption != 1 && userOption != 0);
        clearBuffer();


    } while (userOption);
}

void ListaFuncionarios(TipoCadastro *cadastro) {
    // Imprime os funcionários cadastrados
    printf("\n=== Funcionarios cadastrados ===\n");
    for(int i = 0; i < cadastro->quant; i++) {
        printf("\nFuncionario %d:\n", i + 1);
        printf("Nome: %s\n", cadastro->Funcionario[i].name);
        printf("RG: %s\n", cadastro->Funcionario[i].rg);
        printf("Data de Nascimento: %02d/%02d/%d\n", 
               cadastro->Funcionario[i].birthDate.day,
               cadastro->Funcionario[i].birthDate.month,
               cadastro->Funcionario[i].birthDate.year);
        printf("Sexo: %c\n", cadastro->Funcionario[i].sex);
        printf("Salario: %.2f\n", cadastro->Funcionario[i].salario);
        printf("----------------------------------------\n");
    }
}

int main() {
    TipoCadastro cadastro;
    
    // Teste de inicialização
    IniciaCadastro(&cadastro);
    printf("Inicializacao do cadastro: quantidade = %d\n", cadastro.quant);
    
    // Teste de cadastro de funcionários
    printf("\n=== Iniciando cadastro de funcionarios ===\n");
    LeFuncionarios(&cadastro);

    ListaFuncionarios(&cadastro);
    
    return 0;
}