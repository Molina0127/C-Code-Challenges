#include <stdio.h>
/* Struct - List 2 - Exercise 6 */
typedef struct {
    int day;
    int month;
    int year;
} DMY;

int verifyIsNatural(int num) {
    if (num > 0) {
        return 1;
    }
    else {
        return 0;
    }
}

void validatingDate (DMY dmy) {
    int isValid = 1;
    int isLeap = 0;
    
    if ((!verifyIsNatural(dmy.day)) || (!verifyIsNatural(dmy.month))) {
        isValid = 0;;
    }
    
    if (dmy.year < 0 || dmy.year > 9999) {
        isValid = 0;
    }
    
    if (dmy.year % 4 == 0) { 
        isLeap = 1;
    }

    if (dmy.month < 0 || dmy.month > 12) {
        isValid = 0;
    }

    if (isValid) {
        int maxDays;
        
        switch (dmy.month) {
            case 4: case 6: case 9: case 11:
                maxDays = 30;
                break;
            case 2: 
                maxDays = isLeap ? 29 : 28;
                break; 
            default:
                maxDays = 31;
                break;
        }

        if (dmy.day > maxDays) {
            isValid = 0;
        }
    }

    printf(isValid ? "Data valida\n" : "Data invalida\n");

}

int main() {
     // Exemplos de teste
    DMY test1 = {29, 2, 2000};  // válida (ano bissexto)
    DMY test2 = {29, 2, 2001};  // inválida (não é bissexto)
    DMY test3 = {31, 4, 2023};  // inválida (abril tem 30 dias)
    DMY test4 = {31, 12, 2023}; // válida
    
    printf("Teste 1 (29/02/2000): ");
    validatingDate(test1);
    
    printf("Teste 2 (29/02/2001): ");
    validatingDate(test2);
    
    printf("Teste 3 (31/04/2023): ");
    validatingDate(test3);
    
    printf("Teste 4 (31/12/2023): ");
    validatingDate(test4);

    return 0;
}
