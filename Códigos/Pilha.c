#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <conio.h>
#include "Pilha_f.h"

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

int main() 
{



    	printf("\n ************************************************");
    	printf("\n Trabalho 2  Estrutura de Dados I");
    	printf("\n Sistemas de informacao");
    	printf("\n Aluno: Rodrigo Alves - Matricula: 005008325");
    	printf("\n Analise  de Expressao  Aritmetica");
    	printf("\n ************************************************");

		char string[140]; 
    	struct operacao *oprarr, swap;
    	struct numeros *numarr;
    	int final = 0, i = 0, j = 0, k = 0, count, sum, countnum, m;
      
    do
    {	
		char string[140]; 
    	struct operacao *oprarr, swap;
    	struct numeros *numarr;
    	int final = 0, i = 0, j = 0, k = 0, cont, soma, contnum, m;
		    
			 printf(" \n Ola, meu nome eh Rodrigo, Entre com a expressao para que eu resolva:\n ");
   			 scanf("%[^\n\t]", string);
		    while(*(string + i) != '\0') {
			switch(*(string + i)){
			case '+':
			{
			    if(j != 0) {
				oprarr = (struct operacao *)realloc(oprarr, (j + 1) * sizeof(struct operacao));
				(oprarr + j) -> op = '+';
				(oprarr + j) -> predn = k * 10 + 1;
				(oprarr + j) -> index = j;
			    }
			    else {
				oprarr = (struct operacao *)malloc((j + 1) * sizeof(struct operacao));
				(oprarr + j) -> op = '+';
				(oprarr + j) -> predn = k * 10 + 1;
				(oprarr + j) -> index = j;
			    }
			    j++;
			    break;
			}
			case '-':
			{
			    if(j != 0) {
				oprarr = (struct operacao *)realloc(oprarr, (j + 1) * sizeof(struct operacao));
				(oprarr + j) -> op = '-';
				(oprarr + j) -> predn = k * 10 + 2;
				(oprarr + j) -> index = j;
			    }
			    else {
				oprarr = (struct operacao *)malloc((j + 1) * sizeof(struct operacao));
				(oprarr + j) -> op = '-';
				((oprarr + j) -> predn) = (k * 10 + 2);
				(oprarr + j) -> index = j;
			    }
			    j++;
			    break;
			}
			case '*':
			{	 
			    if(j != 0) {
				oprarr = (struct operacao *)realloc(oprarr, (j + 1) * sizeof(struct operacao));
				(oprarr + j) -> op = '*';
				(oprarr + j) -> predn = k * 10 + 3;
				(oprarr + j) -> index = j;
			    }
			    else {
				oprarr = (struct operacao *)malloc((j + 1) * sizeof(struct operacao));
				(oprarr + j) -> op = '*';
				(oprarr + j) -> predn = k * 10 + 3;
				(oprarr + j) -> index = j;
			    }
			    j++;
			    break;
			}
			case '/':
			{
			    if(j != 0) {
				oprarr = (struct operacao *)realloc(oprarr, (j + 1) * sizeof(struct operacao));
				(oprarr + j) -> op = '/';
				(oprarr + j) -> predn = k * 10 + 3;
				(oprarr + j) -> index = j;
			    }
			    else {
				oprarr = (struct operacao *)malloc((j + 1) * sizeof(struct operacao));
				(oprarr + j) -> op = '/';
				(oprarr + j) -> predn = k * 10 + 3;
				(oprarr + j) -> index = j;
			    }
			    j++;
			    break;
			}
			case '(':
			{
			    k++;
			    break;
			}
			case ')':
			{
			    k--;
			    break;
			}
			default:
			    break;
			}
			i++;
		    }
		    
			cont = j;
		    i = 0;
		    m = cont;
		    
			while(i < (m - 1)) {
				j = 1;
				while((j + i) < (m)) {
				    if(((oprarr + i) -> predn) < ((oprarr + j + i) -> predn)) {
					swap.op = ((oprarr + i) -> op);
					swap.predn = ((oprarr + i) -> predn);
					swap.index = ((oprarr + i) -> index);
					((oprarr + i) -> op) = ((oprarr + j + i) -> op);
					((oprarr + j + i) -> op) = swap.op;
					((oprarr + i) -> predn) = ((oprarr + j + i) -> predn);
					((oprarr + j + i) -> predn) = swap.predn;
					((oprarr + i) -> index) = ((oprarr + j + i) -> index);
					((oprarr + j + i) -> index) = swap.index;
				    }
				    j++;
				}
				i++;
		    }
		    
		    i = j = k = 0;
		    while(*(string + i) != '\0') {
				k = 0;
				soma = 0;
				while(isdigit(*(string + i)) && (*(string + i) != '\0')) {
				    soma = soma * 10 + (*(string + i)) - '0';
				    i++;
				    k = 1;
				}
				if(k == 1) {
				    if(j != 0) {
					numarr = (struct numeros*)realloc(numarr, (j + 1)*sizeof(struct numeros));
					(numarr + j) -> num = soma;
					(numarr + j) -> indexnum = j;
					j++;
				    }  
				    else {
					numarr = (struct numeros *)malloc(sizeof(struct numeros));
					(numarr + j) -> num = soma;
					(numarr + j) -> indexnum = j;
					j++;
				    }
				}
				i++;
		    }
		 
		    contnum--;
		    contnum = j;
		    
		    k = 0;
		    i = 0;
		    char optr;
		    int pos, n1, n2 ,res;
		    
		    while(k < cont) {
				optr = (oprarr + k) -> op;
				pos = (oprarr + k) -> index;
				n1 = (numarr + pos) -> num;
				n2 = (numarr + pos + 1) -> num;
				switch(optr) {
				case '+':
				    res = n1 + n2;
				    break;
				case '-':
				    res = n1 - n2;
				    break;
				case '/':
				    res = n1 / n2;
				    break;
				case '*':
				    res = n1 * n2;
				    break;
				}
				(numarr + pos) -> num = res;
				contnum--;
				i = 1;
				
				while((pos + i) < contnum) {
				    (numarr + pos + i) -> num = (numarr + pos + i + 1) -> num;
				    (numarr + pos + i) -> indexnum = (((numarr + pos + i + 1) -> indexnum)-1);
				    i++;
				}
				
				k++;
				m = k;
				
				while(m < cont) {
			   	 	if(((oprarr + m) -> index) > pos)
					((oprarr + m) -> index) -= 1;
			   		 m++;
				}
		    }
		    
		    printf("\n Obrigado, o resultado da sua expressao e: %d\n", ((numarr+0)->num));
		    printf("\n Deseja Continuar? (1 = s / 2 = n)\n");
			scanf("%i",&final);  
			
			
			
	}
	while(final == 1);

	printf("\n Fim!!!");
	getch();
	
    return (0);
}
