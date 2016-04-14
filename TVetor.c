#include<stdio.h>
#include<stdarg.h>
#include<malloc.h>
#include "TVetor.h"

void InicializaVetor(TVetor *vec){
    vec->al=0;
    vec->coordenadas=NULL;
}

int LeVetor(TVetor *vec){
    int dim,i;

    if(vec->al) return 2;
    printf("Digite o valor da dimensao: ");
    scanf("%d", &dim);
    while(dim<1){
        printf("Valor invalido. Tente novamente.\n");
        scanf("%d", &dim);
    }
    if((vec->coordenadas = (double *)malloc(dim*sizeof(double)))==NULL) return -1;
    vec->dimensao = dim;

    for(i=0; i<dim; i++){
        printf("Digite o valor da coordenada %d: ", i);
        scanf("%lf", &(vec->coordenadas[i]));
    }
    vec->al=1;
    return 0;
}

int CriaVetor(TVetor *vec, int dim, ...){
    int i;
    va_list ap;

    if(vec->al) return 2;
    if((vec->coordenadas = (double *)malloc(dim*sizeof(double)))==NULL) return -1;
    vec->dimensao = dim;
    va_start(ap, dim);
    for(i=0; i<dim; i++){
        vec->coordenadas[i] = va_arg(ap, double);
    }
    va_end(ap);
    vec->al=1;
    return 0;

}

int SomaVetor(TVetor *result, TVetor v1, TVetor v2){
    int i, dim;

    if(result->al) return 2;
    if(v1.dimensao!=v2.dimensao) return 1;
    dim = v1.dimensao;

    if((result->coordenadas = (double *)malloc(dim*sizeof(double)))==NULL) return -1;
    result->dimensao = dim;
    for(i=0; i<dim; i++){
        result->coordenadas[i] = v1.coordenadas[i] + v2.coordenadas[i];
    }
    result->al=1;
    return 0;
}

int SubtraiVetor(TVetor *result, TVetor v1, TVetor v2){
    int i, dim;

    if(result->al) return 2;
    if(v1.dimensao!=v2.dimensao) return 1;
    dim = v1.dimensao;

    if((result->coordenadas = (double *)malloc(dim*sizeof(double)))==NULL) return -1;
    result->dimensao = dim;
    for(i=0; i<dim; i++){
        result->coordenadas[i] = v1.coordenadas[i] - v2.coordenadas[i];
    }
    result->al=1;
    return 0;
}

int ProdutoEscalar(double *result, TVetor v1, TVetor v2){
    int i, dim;

    if(v1.dimensao!=v2.dimensao) return 1;
    dim = v1.dimensao;

    *result=0;
    for(i=0; i<dim; i++){
        *result += v1.coordenadas[i] + v2.coordenadas[i];
    }
    return 0;
}

int ProdutoVetorial(TVetor *result, TVetor v1, TVetor v2){
    int i, j, id, dim;

    if(result->al) return 2;
    if(v1.dimensao!=3){
        result->dimensao=-1;
        return 1;
    }
    if(v2.dimensao!=3){
        result->dimensao=-2;
        return 1;
    }
    dim = 3;

    if(CriaVetor(result, 3, 0, 0, 0) == -1) return -1;
    for(i=0; i<dim; i++){
        for(j=0; j<dim; j++){
            if(i!=j){
                id = (2*(i + j))%3;
                result->coordenadas[id] += v1.coordenadas[i] * v2.coordenadas[j] * (i<j? 1 : -1);
            }
        }
    }
    return 0;
}

int ProdutoMisto(double *result, TVetor v1, TVetor v2, TVetor v3){
    int return_value;
    TVetor t;

    return_value = ProdutoVetorial(&t, v2, v3);
    if(return_value) return return_value;
    return_value = ProdutoEscalar(result, t, v1);
    if(return_value) return return_value;

    LiberaVetor(&t);

    return 0;
}

void ImprimeVetor(TVetor vec){
    int i;

    printf("[ ");
    for(i=0; i<vec.dimensao; i++){
        printf("%0.2lf ", vec.coordenadas[i]);
    }
    printf("]");
}

void LiberaVetor(TVetor *vec){
    if(vec->al){
        free(vec->coordenadas);
        vec->dimensao=0;
        vec->al=0;
        vec->coordenadas=NULL;
    }
}
