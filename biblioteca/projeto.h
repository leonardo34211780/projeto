#ifndef PROJ_H
#define PROJ_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct matriz{
	int i;
	int j;
	double **dados;
} Matriz;

Matriz getMatriz(FILE *arq);

void limpaDados(Matriz a);

void criaArquivo(Matriz a);

#endif