/********************************************************************
Programa: array.h
Autor: Rodrigo Surita (RA:139095)

Descricao: Define algumas operaçoes com arrays de inteiros.
********************************************************************/


/* Retorna indice da primeira ocorrencia de menor valor num array */
int MinArrayId(int Arr[], int Size);

/* Retorna o elemento de maior valor em um array */
int MaxArray(int Arr[], int Size);

/* Ordena um Array e usando o algoritimo BubbleSort, mantendo um
indice da posicao original dos elementos */
void BubbleSortIds(int** Ids, int Arr[], int nT);

