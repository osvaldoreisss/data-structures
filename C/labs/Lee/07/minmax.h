#ifndef MINMAX_H
#define MINMAX_H

#include <stdbool.h>

#define TAM_MAX_HEAP 516

typedef struct heapMinMax {
    int valores[TAM_MAX_HEAP + 1];
    int tamanho;
} HeapMinMax;


void swap( int *n1, int *n2 );

void iniciar( HeapMinMax *heapMinMax );

bool estaVazio( HeapMinMax *heapMinMax );

bool ehMinimo( int posicao );

void subirMaximo( HeapMinMax *heapMinMax, int posicao );

void subirMinimo( HeapMinMax *heapMinMax, int posicao );

void subir( HeapMinMax *heapMinMax, int posicao );

int indiceMaiorPrioridade( HeapMinMax *heapMinMax );

int indiceMenorDescendente( HeapMinMax *heapMinMax, int posicao );

int indiceMaiorDescendente( HeapMinMax *heapMinMax, int posicao );

void descerMinimo( HeapMinMax *heapMinMax, int posicao );

void descerMaximo( HeapMinMax *heapMinMax, int posicao );

void descer( HeapMinMax *heapMinMax, int posicao );

void heapfy( HeapMinMax *heapMinMax, int raiz, int tamanho );

void inserir( HeapMinMax *heapMinMax, int valor );

int removerMenorPrioridade( HeapMinMax *heapMinMax );

int removerMaiorPrioridade( HeapMinMax *heapMinMax );

int consultarMenorPrioridade( HeapMinMax *heapMinMax );

int consultarMaiorPrioridade( HeapMinMax *heapMinMax );

void esvaziar( HeapMinMax *heapMinMax );

void imprimir( HeapMinMax *heapMinMax );

void preOrderMinimo( HeapMinMax *heapMinMax );

void preOrderMaximo( HeapMinMax *heapMinMax );

#endif

