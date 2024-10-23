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
    
    // printf("Escolha uma opcao");
    // printf("Digite x para y:");
    // scanf("%d", &op);
    // clearBuffer();

    newRegister(students);
    showStudents(students);

    // switch (op) {
    // case 1:
    //     newRegister(students);
    //     break;
    // case 2:
    //     sortAlpha(students);
    //     break;
    // case 3:
    //     sortByCr();
    //     break;
    // case 4:
    //     searchByCode();
    //     break;
    // case 5:
    //     showStudents();
    //     break;
    // default:
    //     break;
    // }

    return 0;
}

 