/*
Escreva um programa que leia um arquivo texto com o nome passado como parâmetro do programa
e execute as seguintes funcionalidades através de um menu:
	1. Contar caracteres, linhas e palavras do arquivo;
	2. Encontrar e mostrar palavras que são palindromos (apenas palavras);
	3. Somar números inteiros e positivos e mostrar resultado na tela
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

void abertura(){
	system("cls");
	printf("\t  Trabalho de Linguagem de Programacao\n");
	printf("\t\t******** Menu ********\nDigite:\n");
	
	printf("\t1 - Para contar caracteres, linhas e palavras do arquivo;\n");
	printf("\t2 - Para encontrar e mostrar palavras que sao palindromos (apenas palavras);\n");
	printf("\t3 - Para somar numeros inteiros e positivos;\n");
	printf("\t4 - Para Trocar o arquivo .txt aberto;\n");
	printf("\t0 - Para sair do programa.\n");

	printf("Digite o numero correspondente a opcao desejada: ");
		
}

void printarTxt(FILE *f){
	rewind(f);
	char aux;
	while(fscanf(f, "%c", &aux) != EOF){
		printf("%c", aux);
	}
	printf("\n");
}

void contagens(FILE *f){
	
	char auxc, *v = NULL;
	int tam = 0, carc = 0, linha =1, palavra = 0, i=0;
		
	//printador do .txt
	printf("\nConteudo do arquivo: \n");
	printarTxt(f);
	
	rewind(f);
	
	//leitura e contagem de caracter para um array
	while(fscanf(f, "%c", &auxc) != EOF){
		if(auxc != '\n' && auxc != '\t' && auxc != '\0')
			carc++;
			
		if (auxc == '\n')
			linha++;
				
			i++;
	}
	
	//voltando ao ponto 0 do txt
	rewind(f);
	
	//criaï¿½ï¿½o do vetor
	v = (char*)malloc(i+1*sizeof(char));
	tam = i;
	i =0;
	//alocaï¿½ï¿½o
	while(fscanf(f, "%c", &auxc) != EOF){
		v[i] = auxc;
		i++;
	}
		
	//contagem das palavras
	for(i=0; i < tam; i++){
		if ((v[i] != ' ' && v[i+1] == '\0') || (v[i] != ' ' && v[i+1] == ' '))
		 palavra++;
	}
	
	printf("\nTotal de Palavras: %d", palavra);
	printf("\nTotal de Linhas: %d", linha);
	printf("\nTotal de Caracteres: %d\n\n", carc);
	
}

void somas(FILE *f){
	
	char auxc, *v = NULL;
	int tam = 0, x = 0, i=0, ind =0;
	
	printf("\nConteudo do arquivo: \n");
	
	//voltando ao ponto 0 do txt
	rewind(f);
	
	//leitura e contagem de caracter para um array
	while(fscanf(f, "%c", &auxc) != EOF){
		printf("%c", auxc);
		i++;
	}
	printf("\n");
	
	//voltando ao ponto 0 do txt
	rewind(f);
	
	//criaï¿½ï¿½o do vetor
	v = (char*)malloc(i+1*sizeof(char));
	tam = i;
	i =0;
	
	rewind(f);
	// le o texto para o vetor geristrado como mallc e pega sï¿½ oque ï¿½ numero
	while(fscanf(f, "%c", &auxc) != EOF){
		if ((auxc >= 47 && auxc <= 57)|| auxc=='-'){
			v[i] = auxc;
			i++;
		}
		//se nï¿½o ï¿½ numero, ï¿½ colocado um espaï¿½o. Apanas coloca 1 espaï¿½o por entre numero
		else{
			if (v[i-1] != ' '){
				v[i] = ' ';
				i++;
			}
		}	
	}
	
	//pega o tamanho para saber o tamho do vetor de numeros
	tam =  i;
	
	// se ele detectar um - indicando numero negativo, sai colocando espaï¿½os atï¿½ substituir todo numero negativo
	for(i=0; i <tam ; i++){
		if (v[i] == '-'){
			while (v[i] != ' '){
				if (i == tam)
					break;
				v[i] = ' ';
				i++;
			}
		}
	}

	//percorre o verotr de trï¿½s para frente, fazendo a multiplicaï¿½ï¿½o pela base elevado pela posiï¿½ï¿½o do numero	
	for(i=tam-1; i >= 0; i--){	
		if(v[i] != ' '){
			int q = v[i] - '0';
			x += (q * (pow(10, ind)));
			ind++;
		}
		else
			ind =0;	
	}
	//printa o total da soma
	printf("\nTotal dos numeros positivos: %d\n\n", x);
}

void palindromos(FILE *f){
	char auxc, *p= NULL, *v = NULL;
	int pali = 0, tam = 0, auxd = 0, i=0, ini=0, fim=0, j=0;
	
	printf("\nConteudo do arquivo: \n");
	
	rewind(f);
	
	//conta o tamanho do txt
	while(fscanf(f, "%c", &auxc) != EOF){
		printf("%c", auxc);
		i ++;
	}
	
	//cria o espaï¿½o para a locaï¿½ï¿½o do txt
	v = (char*) malloc(i*sizeof(char));
	
	// volta ao comeï¿½o do texto pra alocar
	tam = i;
	rewind(f);
	i =0;
	
	//pega do txt e aloca
	while(fscanf(f, "%c", &auxc) != EOF){
		v[i] = auxc;
		i ++;
	}
	
	//percorre o veotor para verificaï¿½ï¿½es
	for(i=0; i<tam; i++){
		//verifica se o caracter ï¿½ uma letra
		if(v[i] >=97 && v[i] <= 122 && v[i] != ' '){
			
			//faz o inicio sr a posiï¿½ï¿½o de i
			ini = i;
			//zera o final
			fim = 0;
			//percorre os n proximos caracteres para descobir o final da palavra.
			while(v[fim+i] != ' ' && (v[i+fim] >=97 && v[i+fim] <= 122)){
				fim++;
			}
			
			//faz o final da palavra ser atual
			fim += i;
			
			//tira 1 para se adequar ao indice do vetor
			fim--;
			
			//registra o valor do fim, pois a variavel fim serï¿½ decrementada no for abaixo
			auxd= fim;	    	
			
			// se a palavra tiver mais de uma letra
			if(fim>1){
				//percorre o indice do inicio ao fim da palavra comparando suas letras
				for(ini; ini<=fim; ini++){
					//verifica se os extremos sï¿½o iguais
					if(v[ini] == v[fim])
						j =1;
					else{
						//caso nï¿½o sejam, zera minha variavel j sentinela e para a busca
						j =0;
						break;
					}
					
					fim--;
				}
				
				//verifica se foi detectado um palindromo
				if (j==1){
					pali++;
				}
				
				//faz o i, que percorre o vetor com os chars do txt acompanhar, pois ele deve verificar da proxima palavra para frente.
				i = auxd;
			}
		}
		
	}
	
	printf("\n\n Total de Palindromos = %d\n\n", pali);
	
}


int main(){
	int op=0;
	char nome[30], aux;
	FILE *f = NULL;
	
	inicio:
	abertura();
	scanf("%d", &op);
	
	
	while(1){
		if(op < 0 || op > 4){
			printf("\nOpï¿½ï¿½o invalida!");
		}
		else {
			if(op == 0){
				fclose(f);
				system("cls");
				printf("Obrigado e Volte sempre ;)");
				break;
			}
			
			if(f == NULL || op==4){
				if(op==4)
					fclose(f);
				
				//leitura do .txt
				printf("\n Digite o nome do arquivo .txt que deseja abrir (sem a extensao): ");
				scanf("%s", nome);
				strcat(nome, ".txt");
				
				//abertura do .txt
				f = fopen(nome, "r");
				
				//impedimento de leituras invalidas
				while(f == NULL){
					printf("\nArquivo nao encontrado, por favor digite o nome novamente: ");
					scanf("%s", nome);
					strcat(nome, ".txt");
					
					f = fopen(nome, "r");
				}
				
				if(op==4){
					printf("\nArquivo carregado com sucesso!\n");
					system("pause");
					goto inicio;
				}
				
			}
			
			if(op == 1){
				system("cls");
				contagens(f);
				system("pause");
				goto inicio;
			}	
			else if(op == 2){
				system("cls");
				palindromos(f);
				system("pause");
				goto inicio;
			}	
			else if(op == 3){
				system("cls");
				somas(f);
				system("pause");
				goto inicio;
				
			}
		}
		
	}
	
	return 0;
}
