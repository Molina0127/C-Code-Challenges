#include <stdio.h>
#include <string.h>
#include <ctype.h>
/* Structs - List 2 - Exercise 14 */
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
    // Verifica se há funcionários cadastrados
    if (cadastro.quant == 0) {
        printf("\n=== Nao ha nenhum funcionario cadastrado '-' ===\n");
        return;
    }

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

void OrdenaNome(TipoCadastro *cadastro) {
    TipoCadastro temp;
    
    for (int i = 0; i < cadastro->quant-1; i++) {
        for (int j = i + 1; j < cadastro->quant; j++) {
            if (strcmp(cadastro->Funcionario[i].name, cadastro->Funcionario[j].name) > 0) {
                temp.Funcionario[0] = cadastro->Funcionario[i];
                cadastro->Funcionario[i] = cadastro->Funcionario[j];
                cadastro->Funcionario[j] = temp.Funcionario[0];
            }
        }
    }
}

void OrdenaSalario(TipoCadastro *cadastro) {
    TipoCadastro temp;
    
    for (int i = 0; i < cadastro->quant-1; i++) {
        for (int j = i + 1; j < cadastro->quant; j++) {
            if (cadastro->Funcionario[i].salario < cadastro->Funcionario[j].salario) {
                temp.Funcionario[0] = cadastro->Funcionario[i];
                cadastro->Funcionario[i] = cadastro->Funcionario[j];
                cadastro->Funcionario[j] = temp.Funcionario[0];
            }
        }
    }
}

void SalarioIntevalo(TipoCadastro cadastro, float v1, float v2) {
    float salario;
    int found = 0;

    // Ordena os salarios
    if (v1 > v2) {
        salario = v1;
        v1 = v2;
        v2 = salario;
    }
    salario = 0;

    // Imprime os funcionários nessa faixa de salario
    printf("\n=== Segue os funcionarios que recebem entre (R$ %.2f) e (R$ %.2f) ===\n", v1, v2);
    for(int i = 0; i < cadastro.quant; i++) {
        if (cadastro.Funcionario[i].salario >= v1 && cadastro.Funcionario[i].salario <= v2) {
            printf("Nome: %s\n", cadastro.Funcionario[i].name);
            printf("RG: %s\n", cadastro.Funcionario[i].rg);
            printf("Data de Nascimento: %02d/%02d/%d\n", 
                cadastro.Funcionario[i].birthDate.day,
                cadastro.Funcionario[i].birthDate.month,
                cadastro.Funcionario[i].birthDate.year);
            printf("Sexo: %c\n", cadastro.Funcionario[i].sex);
            printf("Salario: %.2f\n", cadastro.Funcionario[i].salario);
            printf("----------------------------------------\n");
            salario += cadastro.Funcionario[i].salario;
            found++;
        }
    }
    printf("\n=== A media dos salarios encontrados eh (R$ %.2f) ===\n", salario/found);

    if (!found) {
        printf("\n=== Nao ha nenhum funcionario que receba nessa faixa de valor '-' ===\n", v1, v2);
    }
}

void Imposto(TipoCadastro cadastro, char *name) {
    int taxLimit[] = {1000, 2000, 3500};
    float taxValue = 0;
    int found = 0;
    
    for(int i = 0; i < cadastro.quant; i++) {
        if (strcmp(cadastro.Funcionario[i].name, name) == 0) {
            found = 1;
            
            if (cadastro.Funcionario[i].salario <= 0) {
                printf("\nFuncionario(a): %s tem salario invalido\n", cadastro.Funcionario[i].name);
            }
            else if (cadastro.Funcionario[i].salario <= taxLimit[0]) {
                printf("\nFuncionario(a): %s tem isencao de imposto\n", cadastro.Funcionario[i].name);
            }
            else if (cadastro.Funcionario[i].salario <= taxLimit[1]) {
                taxValue = (cadastro.Funcionario[i].salario * 0.10);
                printf("\nFuncionario(a): %s tem R$ %.2f imposto retido na fonte\n", 
                       cadastro.Funcionario[i].name, taxValue);
            }
            else if (cadastro.Funcionario[i].salario <= taxLimit[2]) {
                taxValue = (cadastro.Funcionario[i].salario * 0.15);
                printf("\nFuncionario(a): %s tem R$ %.2f imposto retido na fonte\n", 
                       cadastro.Funcionario[i].name, taxValue);
            }
            else if (cadastro.Funcionario[i].salario > taxLimit[2]) {
                taxValue = (cadastro.Funcionario[i].salario * 0.25);
                printf("\nFuncionario(a): %s tem R$ %.2f imposto retido na fonte\n", 
                       cadastro.Funcionario[i].name, taxValue);
            }
        }
    }
    
    if (!found) {
        printf("\n=== Funcionario '%s' nao encontrado '-' ===\n", name);
    }
}

int main() {
    TipoCadastro cadastro;
    int opcao;
    
    // Teste de inicialização
    IniciaCadastro(&cadastro);
    printf("Inicializacao do cadastro: quantidade = %d\n", cadastro.quant);
    
    // Inicializa com funcionários pré-definidos
    inicializaFuncionariosPreDefinidos(&cadastro);
    printf("\n=== Adicionando cadastros para teste ===\n");
    printf("Inicializacao do cadastro: quantidade = %d\n", cadastro.quant);
    
    do {
        printf("\n=== Menu de Gerenciamento de Funcionarios ===\n");
        printf("1 - Cadastrar novo funcionario\n");
        printf("2 - Ordenar funcionarios por nome\n");
        printf("3 - Ordenar funcionarios por salario\n");
        printf("4 - Listar funcionarios em uma faixa de salario\n");
        printf("5 - Listar todos os funcionarios\n");
        printf("6 - Calcular imposto retido na fonte\n");
        printf("0 - Sair\n");
        printf("Digite sua opcao: ");
        scanf("%d", &opcao);
        clearBuffer();

        switch(opcao) {
            case 1:
                LeFuncionarios(&cadastro);
                break;

            case 2:
                OrdenaNome(&cadastro);
                printf("\nFuncionários ordenados por nome:\n");
                ListaFuncionarios(cadastro);
                break;
                
            case 3:
                OrdenaSalario(&cadastro);
                printf("\nFuncionários ordenados por salário:\n");
                ListaFuncionarios(cadastro);
                break;

            case 4: {
                float v1, v2;
                printf("Digite o valor do primeiro salario que deseja comparar:\n");
                scanf("%f", &v1);
                printf("Digite o valor do segundo salario que deseja comparar:\n");
                scanf("%f", &v2);
                SalarioIntevalo(cadastro, v1, v2);
                break;
            }
            
            case 5:
                ListaFuncionarios(cadastro);
                break;

            case 6: {
                char nome[50];
                printf("Digite o nome do funcionario para calcular o imposto:\n");
                fgets(nome, 50, stdin);
                treatSentence(nome);
                Imposto(cadastro, nome);
                break;
            }
            
            case 0:
                printf("\nEncerrando o programa...\n");
                break;
                
            default:
                printf("\nOpção inválida!\n");
        }
    } while(opcao != 0);

    return 0;
}