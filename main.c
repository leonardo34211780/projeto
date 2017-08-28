#include "projeto.c"

int main(){

	DimensaoMatriz a;
	DimensaoMatriz b;
	
	FILE *A = fopen("matriz_a.txt", "r");
	FILE *B = fopen("matriz_b.txt", "r");
	
	if(A == NULL && B == NULL){
		printf("Problema na abertura dos arquivos\n");
		exit(EXIT_FAILURE);
	}
	
	a = getDimensao(A);
	b = getDimensao(B);

	printf("%d %d\n", a.i, a.j);
	printf("%d %d\n", b.i, b.j);
	fclose(A);
	fclose(B);
	return 0;
}