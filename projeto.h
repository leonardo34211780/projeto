#ifndef PROJ_H
#define PROJ_H
#include <stdio.h>
#include <stdlib.h>

typedef struct dimensao_matriz{
	int i;
	int j;
} DimensaoMatriz;

DimensaoMatriz getDimensao(FILE *arq);

#endif