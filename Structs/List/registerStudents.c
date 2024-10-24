#include <stdio.h>
#include <string.h>
#include <ctype.h>
/* Structs - List 2 - Exercise 5 */
typedef struct {
    int day;
    int month;
    int year;
} Date;

typedef struct {
    char street[30];
    char city[30];
    char uf[3];
    char cep[9];
} Address;

typedef struct {
    char name[50];
    Date birthDate;
    char rg[10];
    char sex;
    Address address;
    char studentCode[10];
    float cr;
} Student;

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

void toUpper(char *str) {
    for (int i = 0; str[i] != '\0'; i++) {
        str[i] = toupper(str[i]);
    }
}

void initializePresetStudents(Student students[]) {
    // Student 1 - Maria
    strcpy(students[0].name, "Maria Silva");
    students[0].birthDate.day = 15;
    students[0].birthDate.month = 3;
    students[0].birthDate.year = 2000;
    strcpy(students[0].rg, "1234567");
    students[0].sex = 'F';
    strcpy(students[0].address.street, "Rua das Flores");
    strcpy(students[0].address.city, "Sao Paulo");
    strcpy(students[0].address.uf, "SP");
    strcpy(students[0].address.cep, "12345678");
    strcpy(students[0].studentCode, "2020001");
    students[0].cr = 0.85;

    // Student 2 - Carlos
    strcpy(students[1].name, "Carlos Santos");
    students[1].birthDate.day = 22;
    students[1].birthDate.month = 7;
    students[1].birthDate.year = 2001;
    strcpy(students[1].rg, "7654321");
    students[1].sex = 'M';
    strcpy(students[1].address.street, "Av Principal");
    strcpy(students[1].address.city, "Rio de Janeiro");
    strcpy(students[1].address.uf, "RJ");
    strcpy(students[1].address.cep, "87654321");
    strcpy(students[1].studentCode, "2020002");
    students[1].cr = 0.78;

    // Student 3 - Ana
    strcpy(students[2].name, "Ana Oliveira");
    students[2].birthDate.day = 10;
    students[2].birthDate.month = 12;
    students[2].birthDate.year = 2002;
    strcpy(students[2].rg, "9876543");
    students[2].sex = 'F';
    strcpy(students[2].address.street, "Rua do Comercio");
    strcpy(students[2].address.city, "Curitiba");
    strcpy(students[2].address.uf, "PR");
    strcpy(students[2].address.cep, "54321678");
    strcpy(students[2].studentCode, "2020003");
    students[2].cr = 0.92;

    // Update the global count
    count = 3;
}

void newRegister(Student students[]) {
    printf("Digite o nome do aluno:\n");
    fgets(students[count].name, 50, stdin);
    treatSentence(students[count].name);

    printf("Digite a data de nascimento do aluno (dd/mm/yyyy):\n");
    scanf("%d/%d/%d", &students[count].birthDate.day,&students[count].birthDate.month,&students[count].birthDate.year);
    clearBuffer();

    printf("Digite o RG do aluno:\n");
    fgets(students[count].rg, 10, stdin);
    treatSentence(students[count].rg);

    printf("Qual o sexo do aluno?:\n");
    printf("Digite M - Masculino e F - Feminino\n");
    scanf(" %c", &students[count].sex);
    clearBuffer();

    printf("Digite o endereco do aluno\n");

    printf("Digite a rua do aluno:\n");
    fgets(students[count].address.street, 30, stdin);
    treatSentence(students[count].address.street);

    printf("Digite a cidade do aluno:\n");
    fgets(students[count].address.city, 30, stdin);
    treatSentence(students[count].address.city);

    printf("Digite o estado do aluno:\n");
    fgets(students[count].address.uf, 3, stdin);
    treatSentence(students[count].address.uf);
    
    printf("Digite o cep do aluno:\n");
    fgets(students[count].address.cep, 9, stdin);
    treatSentence(students[count].address.cep);

    printf("Digite o numero de matricula do estudante:\n");
    fgets(students[count].studentCode, 10, stdin);
    treatSentence(students[count].studentCode);
    
    printf("Digite o CR do aluno:\n");
    scanf("%f", &students[count].cr);
    clearBuffer(); 

    count++;
}

void sortAlpha(Student students[]) {
    Student temp;
    
    for (int i = 0; i < count - 1; i++) {
        for (int j = i + 1; j < count; j++) {
            if(strcmp(students[i].name, students[j].name) > 0) {
                temp = students[i];
                students[i] = students[j];
                students[j] = temp;
            }
        }
    }
}

void sortByCr(Student students[]) {
    Student temp;

    for (int i = 0; i < count - 1; i++) {
        for (int j = i + 1; j < count; j++) {
            if(students[i].cr < students[j].cr) {
                temp = students[i];
                students[i] = students[j];
                students[j] = temp;
            }
        }
    }
}

void searchByCode(Student students[], char studentCode[]) {
    int error = 0;
    int found = 0;

    for (int i = 0; i < count; i++) {
        error = 0;
        for (int j = 0; students[i].studentCode[j] != '\0' && error == 0; j++) {
            if (students[i].studentCode[j] != studentCode[j]) {
                error = 1;
            }
        }
        if (!error) {
            printf("\n=== Segue o Aluno com o RA (%s) ===\n", students[i].studentCode);
            printf("Nome: %s\n", students[i].name);
            printf("Data de nascimento: %02d/%02d/%d\n", 
                students[i].birthDate.day, 
                students[i].birthDate.month, 
                students[i].birthDate.year);
            printf("RG: %s\n", students[i].rg);
            printf("Sexo: %c\n", students[i].sex);
            printf("Endereço: %s, %s-%s, CEP: %s\n", 
                students[i].address.street, 
                students[i].address.city, 
                students[i].address.uf, 
                students[i].address.cep);
            printf("Código: %s\n", students[i].studentCode);
            printf("CR: %.2f\n", students[i].cr);
            found = 1;
        }
    }

    if (!found) {
        printf("\nNenhum aluno encontrado com o RA: %s\n", studentCode);
    }


}

void showStudents(Student students[]) {
    if (count == 0) {
        printf("Nenhum aluno cadastrado!\n");
        return;
    }

    for (int i = 0; i < count; i++) {
        printf("\n=== Aluno %d ===\n", i + 1);
        printf("Nome: %s\n", students[i].name);
        printf("Data de nascimento: %02d/%02d/%d\n", 
               students[i].birthDate.day, 
               students[i].birthDate.month, 
               students[i].birthDate.year);
        printf("RG: %s\n", students[i].rg);
        printf("Sexo: %c\n", students[i].sex);
        printf("Endereço: %s, %s-%s, CEP: %s\n", 
               students[i].address.street, 
               students[i].address.city, 
               students[i].address.uf, 
               students[i].address.cep);
        printf("Código: %s\n", students[i].studentCode);
        printf("CR: %.2f\n", students[i].cr);
    }
}

int main() {
    // vai ter que conter reprocessamento
    int op;
    Student students[100];
    char searchRA[10];
    
    // Initialize with preset students
    initializePresetStudents(students);

    do {
        printf("\n=== Menu de Opcoes ===\n");
        printf("1 - Cadastrar novo aluno\n");
        printf("2 - Ordenar alunos por nome\n");
        printf("3 - Ordenar alunos por CR\n");
        printf("4 - Buscar aluno por RA\n");
        printf("5 - Mostrar todos os alunos\n");
        printf("0 - Sair\n");
        printf("Digite sua opcao: ");
        scanf("%d", &op);
        clearBuffer();

        switch (op) {
        case 1:
            newRegister(students);
            break;
        case 2:
            sortAlpha(students);
            printf("\nAlunos ordenados por nome:\n");
            showStudents(students);
            break;
        case 3:
            sortByCr(students);
            printf("\nAlunos ordenados por CR:\n");
            showStudents(students);
            break;
        case 4:
            printf("\nDigite o RA do aluno: ");
            fgets(searchRA, 10, stdin);
            treatSentence(searchRA);
            searchByCode(students, searchRA);
            break;
        case 5:
            showStudents(students);
            break;
        case 0:
            printf("\nEncerrando o programa...\n");
            break;
        default:
            printf("\nOpcao invalida! Tente novamente.\n");
            break;
        }
    } while (op != 0);

    return 0;
}
 