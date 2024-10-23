#include <stdio.h>
#include <string.h>
/* Structs - List 2 - Exercise 4 */

typedef struct {
    int day;
    int month;
    int year;
} Date;

typedef struct {
    char street[30];
    char city[30];
    char uf[2];
    char cep[8];
} Address;

typedef struct {
    char name[50];
    Date birthDate;
    char rg[9];
    char sex;
    Address address;
} personalData;