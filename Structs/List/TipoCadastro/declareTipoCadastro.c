#include <stdio.h>
/* Structs - List 2 - Exercise 8 */
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

int main() {
    return 0;
}