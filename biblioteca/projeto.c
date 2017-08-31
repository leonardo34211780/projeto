#include "projeto.h"


Matriz getMatriz(FILE *arq){
	Matriz matriz;
	int i, j;
	
	matriz.i = 0;
	matriz.j = 0;

	char c;
	
	/*Percorre o arquivo verificando os caracteres presensetes, se for diferente de espaço ou salto
	 *de linha, incrementa a coluna, se for igual a salto de linha incrementa linha.
	*/
	while(fscanf(arq, "%c", &c) != EOF){ 		
		if(c != ' ' && c != '\n'){
			matriz.j++;
		}
		else if(c == '\n'){
			matriz.i++;
		}		
	}

	/*Correção do número de linhas e colunas*/
	matriz.i += 1;
	matriz.j /= matriz.i;

	matriz.dados = malloc(sizeof(int*)*matriz.i);

	for(i = 0; i < matriz.i; i++){
			matriz.dados[i] = malloc(sizeof(int)*matriz.j);
		
	}

	fseek(arq, 0, SEEK_SET);

	for (i = 0; i < matriz.i; ++i){
		for (j = 0; j < matriz.j; ++j){
			fscanf(arq, "%d", &matriz.dados[i][j]); 
		}
	}

	return matriz;
}
void limpaDados(Matriz a){
	int i, j;

	for(i = 0; i < a.i; i++){
		free(a.dados[i]);
	}
	free(a.dados);
}

void multiplicaMatriz(Matriz a, Matriz b){
	if(a.i == b.j){
		int i, j, k;

		Matriz c;

		c.i = a.i;
		c.j = b.j;

		printf("%d %d\n", c.i, c.j);

		c.dados = malloc(sizeof(int*)*c.i);

		for(i = 0; i < c.i; i++){
			c.dados[i] = malloc(sizeof(int)*c.j);
		}

		for(i = 0; i < a.i; i++){
			for(j =  0; j < b.j; j++){
				c.dados[i][j] = 0;
				for (k = 0; k < b.i ; k++){
					c.dados[i][j] += a.dados[i][k]*b.dados[k][j];
				}
			}
		}

		limpaDados(a);
		limpaDados(b);
		
		for (i = 0; i < c.i; i++){
			for (j = 0; j < c.j; j++){
				printf("%d ", c.dados[i][j]);
			}
			printf("\n");
		}

		criaArquivo(c);
	}
	else{
		printf("As matrizes não pode ser multiplicadas.\n");
		exit(EXIT_FAILURE);
	}
		
}

void criaArquivo(Matriz a){
	int i, j;

	FILE *arq = fopen("Produto.txt", "w");

	for(i = 0; i < a.i; i++){
		for(j = 0; j< a.j; j++){
			fprintf(arq, "%d ", a.dados[i][j]);
		}
		fprintf(arq, "\n");
	}

	fclose(arq);
}