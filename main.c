#include "./biblioteca/projeto.c"

int main(){


	Matriz a;
	Matriz b;

	char pathA[100];
	char pathB[100];
	
	while(1){
		int op;

		printf("Entre com o caminho da Matriz A:");
		scanf("%s", pathA);
		printf("Entre com o caminho da Matriz B:");
		scanf("%s", pathB);

		FILE *A = fopen(pathA, "r");
		FILE *B = fopen(pathB, "r");
	
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

		printf("\n\nDeseja multiplicar outras Matriz: S\\N\n");
		scanf("%d", &op);
		
		if(op == 0) break;
	}

	return 0;
}