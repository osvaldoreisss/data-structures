#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include "minmax.h"

void swap( int *n1, int *n2 ) {
    int temp = *n1;
    *n1 = *n2;
    *n2 = temp;
}


void iniciar( HeapMinMax *heapMinMax )
{
    heapMinMax->tamanho = 0;
}


bool estaVazio( HeapMinMax *heapMinMax )
{

    if ( heapMinMax->tamanho == 0 )
    {
        return true;
    } 
    else
    {
        return false;
    }

}


bool ehMinimo(int posicao)
{
    int nivel = ( (int) ( log( posicao ) / log( 2 ) ) ) + 1;
    if ( nivel % 2 == 0 )
    {
        return false;
    } else
    {
        return true;
    }

}


void subirMaximo( HeapMinMax *heapMinMax, int posicao )
{

    int avo = posicao / 4; 
    if ( avo >= 1 && heapMinMax->valores[posicao] > heapMinMax->valores[avo] )
    {
        swap( &(heapMinMax->valores[posicao]), &(heapMinMax->valores[avo]) );
        subirMaximo( heapMinMax, avo );
    }
}

void subirMinimo( HeapMinMax *heapMinMax, int posicao )
{

    int avo = posicao / 4;
    
    if ( avo >= 1 && heapMinMax->valores[posicao] < heapMinMax->valores[avo] ) {
        swap( &(heapMinMax->valores[posicao]), &(heapMinMax->valores[avo]) );
        subirMinimo( heapMinMax, avo );
    }

}


void subir( HeapMinMax *heapMinMax, int posicao )
{

    int pai = posicao / 2; 
    if ( ehMinimo( posicao ) ) {

        if ( pai >= 1 ) {
            if ( heapMinMax->valores[posicao] > heapMinMax->valores[pai] ) {
                swap( &(heapMinMax->valores[posicao]), &(heapMinMax->valores[pai]) );
                subirMaximo( heapMinMax, pai );
            } else {
                subirMinimo( heapMinMax, posicao );
            }
        }

    } else {

        if ( pai >= 1 ) {
            if ( heapMinMax->valores[posicao] < heapMinMax->valores[pai] ) {
                swap( &(heapMinMax->valores[posicao]), &(heapMinMax->valores[pai]) );
                subirMinimo( heapMinMax, pai );
            } else {
                subirMaximo( heapMinMax, posicao );
            }
        }
    }
}

int indiceMaiorPrioridade( HeapMinMax *heapMinMax ) {

    if ( heapMinMax->tamanho == 1 ) {
        return 1;
    } else if ( heapMinMax->tamanho > 2 &&
                heapMinMax->valores[3] > heapMinMax->valores[2] ) {
        return 3;
    } else {
        return 2;
    }
}

int indiceMenorDescendente( HeapMinMax *heapMinMax, int posicao ) {

    int i;
    int menor = 0; // �ndice do menor elemento

    if ( 2 * posicao <= heapMinMax->tamanho ) {

        menor = 2 * posicao; // �ndice do menor (primeiro filho)

        // verifica o menor filho
        if ( heapMinMax->valores[menor+1] < heapMinMax->valores[menor] ) {
            menor++;
        }

        // verifica o menor neto
        for ( i = 4 * posicao;
              (i <= 4 * posicao + 3) && i <= heapMinMax->tamanho; i++ ) {

            if ( heapMinMax->valores[i] < heapMinMax->valores[menor] ) {
                menor = i;
            }
        }
    }
    return menor;
}


int indiceMaiorDescendente( HeapMinMax *heapMinMax, int posicao ) {

    int i;
    int maior = 0; // �ndice do maior elemento

    if ( 2 * posicao <= heapMinMax->tamanho ) {

        maior = 2 * posicao; // �ndice do maior (primeiro filho)

        // verifica o maior filho
        if ( heapMinMax->valores[maior+1] > heapMinMax->valores[maior] ) {
            maior++;
        }

        // verifica o maior neto
        for ( i = 4 * posicao;
              (i <= 4 * posicao + 3) && i <= heapMinMax->tamanho; i++ ) {

            if ( heapMinMax->valores[i] > heapMinMax->valores[maior] ) {
                maior = i;
            }
        }
    }
    return maior;
}


void descerMinimo( HeapMinMax *heapMinMax, int posicao ) {

    if ( 2 * posicao <= heapMinMax->tamanho ) {

        int menor = indiceMenorDescendente( heapMinMax, posicao );

        if ( heapMinMax->valores[posicao] > heapMinMax->valores[menor] ) {

            swap( &(heapMinMax->valores[posicao]), &(heapMinMax->valores[menor]) );

            if ( menor >= 4 * posicao ) {

                int pai = menor / 2;

                if ( heapMinMax->valores[pai] < heapMinMax->valores[menor] ) {
                    swap( &(heapMinMax->valores[pai]), &(heapMinMax->valores[menor]) );
                }
                descerMinimo( heapMinMax, menor );
            }
        }
    }
}

void descerMaximo( HeapMinMax *heapMinMax, int posicao ) {

    // posi��o tem filhos
    if ( 2 * posicao <= heapMinMax->tamanho ) {

        // maior dos descendentes entre filhos e netos
        int maior = indiceMaiorDescendente( heapMinMax, posicao );

        if ( heapMinMax->valores[posicao] < heapMinMax->valores[maior] ) {

            swap( &(heapMinMax->valores[posicao]), &(heapMinMax->valores[maior]) );

            if ( maior >= 4 * posicao ) {

                int pai = maior / 2;

                if ( heapMinMax->valores[pai] > heapMinMax->valores[maior] ) {
                    swap( &(heapMinMax->valores[pai]), &(heapMinMax->valores[maior]) );
                }

                descerMaximo( heapMinMax, maior );
            }
        }
    }
}


void descer( HeapMinMax *heapMinMax, int posicao ) {

    if ( ehMinimo( posicao ) ) {
        descerMinimo( heapMinMax, posicao );
    } else {
        descerMaximo( heapMinMax, posicao );
    }
}

void inserir( HeapMinMax *heapMinMax, int valor ) {

    if ( heapMinMax->tamanho < TAM_MAX_HEAP ) {

        heapMinMax->tamanho++;

        heapMinMax->valores[heapMinMax->tamanho] = valor;
        subir( heapMinMax, heapMinMax->tamanho );

    } else {

        printf( "Heap min-max cheio - Overflow!" );
        exit( 1 );

    }
}

int removerMenorPrioridade( HeapMinMax *heapMinMax ) {

    if ( estaVazio( heapMinMax ) ) {

        printf( "Heap min-max vazio - Underflow!" );
        exit( 1 );

    } else {

        int menor = heapMinMax->valores[1];
        heapMinMax->valores[1] = heapMinMax->valores[heapMinMax->tamanho];
        heapMinMax->tamanho--;

        descer( heapMinMax, 1 );

        return menor;
    }
}

int removerMaiorPrioridade( HeapMinMax *heapMinMax ) {

    if ( estaVazio( heapMinMax ) ) {

        printf( "Heap min-max vazio - Underflow!" );
        exit( 1 );

    } else {

        int indiceMaior = indiceMaiorPrioridade( heapMinMax );
        int maior = heapMinMax->valores[indiceMaior];
        heapMinMax->valores[indiceMaior] = heapMinMax->valores[heapMinMax->tamanho];
        heapMinMax->tamanho--;

        descer( heapMinMax, indiceMaior );

        return maior;
    }
}

int consultarMenorPrioridade( HeapMinMax *heapMinMax ) {

    if ( estaVazio( heapMinMax ) ) {
        printf( "Heap min-max vazio - Underflow!" );
        exit( 1 );
    } else {
        return heapMinMax->valores[1];
    }
}

int consultarMaiorPrioridade( HeapMinMax *heapMinMax ) {

    if ( estaVazio( heapMinMax ) ) {
        printf( "Heap min-max vazio - Underflow!" );
        exit( 1 );
    } else {
        return heapMinMax->valores[indiceMaiorPrioridade( heapMinMax )];
    }
}


void imprimir( HeapMinMax *heapMinMax )
{
    int i;

    for ( i = 1; i <= heapMinMax->tamanho; i++ ) {
        printf( "%d ", heapMinMax->valores[i] );
    }

    printf( "\n" );
}

void preOrderMinimo( HeapMinMax *heapMinMax )
{
    int i;
    
    for ( i = 1; i < 

void preOrderMaximo( HeapMinMax *heapMinMax );

