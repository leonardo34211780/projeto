#include "./biblioteca/projeto.c"

int main(){


	Matriz a;
	Matriz b;
	
	FILE *A = fopen("matriz_a.txt", "r");
	FILE *B = fopen("matriz_b.txt", "r");
	
	if(A == NULL && B == NULL){
		printf("Problema na abertura dos arquivos\n");
		exit(EXIT_FAILURE);
	}
	
	a = getMatriz(A);
	b = getMatriz(B);

	multiplicaMatriz(a, b);
	
	fclose(A);
	fclose(B);
	
	return 0;
}