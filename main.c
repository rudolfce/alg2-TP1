#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include "TVetor.h"
#include "TConj.h"

int main(void){
    double r;
    double tempo;
    clock_t start, end;
    TVetor v1, v2, v3;
    TConj c1, c2;

    InicializaVetor(&v1);
    InicializaVetor(&v2);
    InicializaVetor(&v3);
    Conj_InicializaConj(&c1);
    Conj_InicializaConj(&c2);

    if(LeVetor(&v1)){
        fprintf(stderr, "Falha em alocar memoria.");
        LiberaVetor(&v1);
        LiberaVetor(&v2);
        LiberaVetor(&v3);
        exit(EXIT_FAILURE);
    }
    if(LeVetor(&v2)){
        fprintf(stderr, "Falha em alocar memoria.");
        LiberaVetor(&v1);
        LiberaVetor(&v2);
        LiberaVetor(&v3);
        exit(EXIT_FAILURE);
    }
    printf("\nV1:");
    ImprimeVetor(v1);
    printf("\nV2:");
    ImprimeVetor(v2);
    start = clock();
    switch(SomaVetor(&v3, v1, v2)){
        case -1:
            fprintf(stderr, "Falha em alocar memoria.\n");
            LiberaVetor(&v1);
            LiberaVetor(&v2);
            LiberaVetor(&v3);
            exit(EXIT_FAILURE);
            break;
        case 1:
            fprintf(stderr, "Nao e possível somar os vetores. Prosseguindo.\n");
            break;
        case 2:
            fprintf(stderr, "Vetor nao alocado para soma. Prosseguindo\n");
            break;
        default:
            printf("\nSoma:");
            ImprimeVetor(v3);
            LiberaVetor(&v3);
            end = clock();
            tempo = (float) (end - start) / CLOCKS_PER_SEC;
            printf("\nTempo levado para soma: %lf\n", tempo);
    }
    start = clock();
    switch(SubtraiVetor(&v3, v1, v2)){
        case -1:
            fprintf(stderr, "Falha em alocar memoria.\n");
            LiberaVetor(&v1);
            LiberaVetor(&v2);
            LiberaVetor(&v3);
            exit(EXIT_FAILURE);
            break;
        case 1:
            fprintf(stderr, "Nao e possivel subtrair os vetores. Prosseguindo.\n");
            break;
        case 2:
            fprintf(stderr, "Vetor nao alocado para subtracao. Prosseguindo\n");
            break;
        default:
            printf("\nSubtracao:");
            ImprimeVetor(v3);
            LiberaVetor(&v3);
            end = clock();
            tempo = (float) (end - start) / CLOCKS_PER_SEC;
            printf("\nTempo levado para subtracao: %lf\n", tempo);
    }
    start = clock();
    switch(ProdutoEscalar(&r, v1, v2)){
        case -1:
            fprintf(stderr, "Falha em alocar memoria.\n");
            exit(EXIT_FAILURE);
            break;
        case 1:
            fprintf(stderr, "Nao e possivel realizar o produto escalar dos vetores. Prosseguindo.\n");
            break;
        case 2:
            fprintf(stderr, "Vetor nao alocado para produto escalar. Prosseguindo\n");
            break;
        default:
            printf("\nProduto escalar:");
            printf("%lf\n", r);
            end = clock();
            tempo = (float) (end - start) / CLOCKS_PER_SEC;
            printf("\nTempo levado para produto escalar: %lf\n", tempo);
    }
    start = clock();
    switch(ProdutoVetorial(&v3, v1, v2)){
        case -1:
            fprintf(stderr, "Falha em alocar memoria.\n");
            LiberaVetor(&v1);
            LiberaVetor(&v2);
            LiberaVetor(&v3);
            exit(EXIT_FAILURE);
            break;
        case 1:
            fprintf(stderr, "Nao e possivel realizar o produto vetorial dos vetores. Prosseguindo.\n");
            break;
        case 2:
            fprintf(stderr, "Vetor nao alocado para ProdutoVetorial. Prosseguindo.\n");
            break;
        default:
            printf("\nProduto vetorial:");
            ImprimeVetor(v3);
            end = clock();
            tempo = (float) (end - start) / CLOCKS_PER_SEC;
            printf("\nTempo levado para produto vetorial: %lf\n", tempo);
    }
    start = clock();
    switch(ProdutoMisto(&r, v1, v2, v3)){
        case -1:
            fprintf(stderr, "Falha em alocar memoria.\n");
            LiberaVetor(&v1);
            LiberaVetor(&v2);
            LiberaVetor(&v3);
            exit(EXIT_FAILURE);
            break;
        case 1:
            fprintf(stderr, "Nao e possivel realizar o produto misto dos vetores. Prosseguindo.\n");
            //LiberaVetor(&v3);
            break;
        case 2:
            fprintf(stderr, "Vetor nao alocado para o produto misto. Prosseguindo.\n");
            break;
        default:
            printf("\nProduto misto:");
            printf("%lf\n", r);
            end = clock();
            tempo = (float) (end - start) / CLOCKS_PER_SEC;
            printf("\nTempo levado para produto misto: %lf\n", tempo);
    }

    printf("Operacoes com TConjs:\n");
    printf("Utilizando os seguintes vetores da execucao anterior:\n");
    printf("v1: ");
    ImprimeVetor(v1);
    printf("\nv2: ");
    ImprimeVetor(v2);
    printf("\nv3: ");
    ImprimeVetor(v3);

    Conj_AdicionaVetor(&c1, v1);
    Conj_AdicionaVetor(&c1, v2);
    Conj_AdicionaVetor(&c1, v3);
    printf("\nConjunto c1 criado:\n");
    Conj_ImprimeConjunto(c1);
    Conj_AdicionaVetor(&c2, v3);
    Conj_AdicionaVetor(&c2, v2);
    Conj_AdicionaVetor(&c2, v1);
    printf("\nConjunto c2 criado:\n");
    Conj_ImprimeConjunto(c2);

    Conj_UneConjuntos(&c1, c2);
    printf("\nNovo conjunto c1 gerado a partir da uniao de c1 e c2:\n");
    Conj_ImprimeConjunto(c1);

    printf("Somando os elementos de c1 ampliado:\n");
    LiberaVetor(&v1);
    Conj_SomaVetores(&v1, c1);
    ImprimeVetor(v1);


    LiberaVetor(&v1);
    LiberaVetor(&v2);
    LiberaVetor(&v3);
    Conj_LiberaConjunto(&c1);
    Conj_LiberaConjunto(&c2);

    printf("\n");
    return 0;
}
