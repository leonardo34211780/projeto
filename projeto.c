#include "projeto.h"


DimensaoMatriz getDimensao(FILE *arq){
	DimensaoMatriz matriz;
	
	matriz.i = 0;
	matriz.j = 0;

	char c;

	while(fscanf(arq, "%c", &c) != EOF){		
		if(c != ' ' && c != '\n'){
			matriz.j++;
		}
		else if(c == '\n'){
			matriz.i++;
		}
	}	

	if(matriz.i == 0 && matriz.j == 0){
		printf("Arquivo vazio.\n");
		exit(EXIT_FAILURE);
	}
	
	matriz.i += 1;
	matriz.j /= matriz.i;

	return matriz;
}

