#include "./biblioteca/projeto.c"
#include <string.h>
#include <dirent.h>

int main(){

	
	Matriz a;
	Matriz b;
	
	FILE *A = fopen("A150_50_5.txt", "r");
	FILE *B = fopen("B150_50_30.txt", "r");
	
	//Verifica se houve a algum erro na abertura do arquivo. Se sim, termina a excução do programa.
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
	return 0;
}