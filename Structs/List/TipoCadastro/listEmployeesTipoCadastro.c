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

void inicializaFuncionariosPreDefinidos(TipoCadastro *cadastro) {
    // Funcionário 1
    strcpy(cadastro->Funcionario[0].name, "Maria Silva");
    cadastro->Funcionario[0].birthDate.day = 15;
    cadastro->Funcionario[0].birthDate.month = 3;
    cadastro->Funcionario[0].birthDate.year = 1990;
    strcpy(cadastro->Funcionario[0].rg, "1234567");
    cadastro->Funcionario[0].sex = 'F';
    cadastro->Funcionario[0].salario = 5000.00;

    // Funcionário 2
    strcpy(cadastro->Funcionario[1].name, "João Santos");
    cadastro->Funcionario[1].birthDate.day = 22;
    cadastro->Funcionario[1].birthDate.month = 7;
    cadastro->Funcionario[1].birthDate.year = 1985;
    strcpy(cadastro->Funcionario[1].rg, "7654321");
    cadastro->Funcionario[1].sex = 'M';
    cadastro->Funcionario[1].salario = 6500.00;

    // Funcionário 3
    strcpy(cadastro->Funcionario[2].name, "Ana Oliveira");
    cadastro->Funcionario[2].birthDate.day = 10;
    cadastro->Funcionario[2].birthDate.month = 12;
    cadastro->Funcionario[2].birthDate.year = 1992;
    strcpy(cadastro->Funcionario[2].rg, "9876543");
    cadastro->Funcionario[2].sex = 'F';
    cadastro->Funcionario[2].salario = 4500.00;

    cadastro->quant = 3;
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
        
        printf("Digite o salario do funcionario:\n");
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

void ListaFuncionarios(TipoCadastro cadastro) {
    // Imprime os funcionários cadastrados
    printf("\n=== Funcionarios cadastrados ===\n");
    for(int i = 0; i < cadastro.quant; i++) {
        printf("\nFuncionario %d:\n", i + 1);
        printf("Nome: %s\n", cadastro.Funcionario[i].name);
        printf("RG: %s\n", cadastro.Funcionario[i].rg);
        printf("Data de Nascimento: %02d/%02d/%d\n", 
               cadastro.Funcionario[i].birthDate.day,
               cadastro.Funcionario[i].birthDate.month,
               cadastro.Funcionario[i].birthDate.year);
        printf("Sexo: %c\n", cadastro.Funcionario[i].sex);
        printf("Salario: %.2f\n", cadastro.Funcionario[i].salario);
        printf("----------------------------------------\n");
    }
}

int main() {
    TipoCadastro cadastro;
    
    // Teste de inicialização
    IniciaCadastro(&cadastro);
    printf("Inicializacao do cadastro: quantidade = %d\n", cadastro.quant);

    // Inicializa com funcionários pré-definidos
    inicializaFuncionariosPreDefinidos(&cadastro);
    printf("\n=== Adicionando cadastros para teste ===\n");
    printf("Inicializacao do cadastro: quantidade = %d\n", cadastro.quant);
    
    ListaFuncionarios(cadastro);

    // Teste de cadastro de funcionários
    printf("\n=== Iniciando cadastro de funcionarios ===\n");
    LeFuncionarios(&cadastro);

    
    return 0;
}