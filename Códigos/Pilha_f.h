#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <conio.h>

typedef struct operacao 
{
    char op;
    int predn;
    int index;
}operacao;

typedef struct numeros
{
    int num;
    int indexnum;
}numeros;
