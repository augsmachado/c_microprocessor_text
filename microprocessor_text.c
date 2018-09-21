/*
Escreva um programa que leia um arquivo texto com o nome passado como parâmetro do programa e execute as seguintes funcionalidades através de um menu:

	

	1. Contar caracteres, linhas e palavras do arquivo;

	2. Encontrar e mostrar palavras que são palindromos (apenas palavras);

	3. Somar números inteiros e positivos e mostrar resultado na tela
*/

#include <stdio.h>
#include <stdlib.h>

void Count(FILE *arq);
void Palindrome(FILE *arq);
void Add(FILE *arq);

int main(int argc, char *argv[]){
	FILE *arq;
	char nomeArq[100];
	
	printf("Digite o nome do arquivo: ");
	scanf("%s", nomeArq);
	arq= fopen(nomeArq, "r+");
	
	if(arq == NULL){
		printf("Arquivo inexistente!\n");
		return 1;
	}
	
	/* Conta o numero de caracteres, linhas e palavras do arquivo */
	Count(arq);
	
	/* Encontra e mostra palavras que são palindromos (apenas palavras) */
	rewind(arq);
	Palindrome(arq);
	
	
	/*
	char *texto = malloc((size+1)*sizeof(char));
	
	rewind(arq);
	int i=0;
	while(fscanf(arq, "%c", &aux) != EOF){
		texto[i]= aux;
		i++;
	}
	texto[i] = '\0';
	printf("%s", texto);
	*/
	return 0;
}

/* Conta o numero de caracteres, linhas e palavras do arquivo */
void Count(FILE *arq){
	char aux;
	int size=0;  // tamanho do arquivo
	int word=1, line=1; //considera que havera ao menos um de caso
	while(fscanf(arq, "%c", &aux) != EOF){
		size++;
		
		if(size != 0){
			if (aux == ' ' || aux =='\n'){ //WARNING: conta linhas vazias como palavras
				word++;
			}
			
			if(aux == '\n')
				line++;

		} else{
			word=0;
			line=0;
		}
	}
	printf("\nNumero de caracteres: %d\nNumero de linhas: %d\nNumero de palavras: %d\n", size, line, word);
}

/* Encontra e mostra palavras que são palindromos (apenas palavras) */
void Palindrome(FILE *arq){	
}

/* Soma numeros inteiros e positivos */
void Add(FILE *arq){
}
