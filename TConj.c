#include<stdlib.h>
#include<stdio.h>
#include "TVetor.h"
#include "TConj.h"

int Conj_InicializaConj(TConj* c){
    if((c->vs=(TVetor *)malloc(20*sizeof(TVetor)))==NULL) return -1;
    c->n=0;
    c->max=20;
    c->al=1;

    return 0;
}

int Conj_AmpliaConj(TConj* c){
    int max;

    max = c->max + 20;
    if((c->vs=(TVetor *)realloc(c->vs, max*sizeof(TVetor)))==NULL) return -1;
    c->max = max;

    return 0;
}

int Conj_ReduzConj(TConj* c){
    int max;

    max = c->max - 20;
    if(!max) return 1;
    if((c->vs=(TVetor *)realloc(c->vs, max*sizeof(TVetor)))==NULL) return -1;
    c->max = max;

    return 0;
}

int ClonaVetor(TVetor* clone, TVetor v){
    int i;

    if(!(v.al)) return 2;

    if((clone->coordenadas=(double *)malloc(v.dimensao*sizeof(double)))==NULL) return -1;
    clone->dimensao = v.dimensao;
    for(i=0; i<v.dimensao; i++){
        clone->coordenadas[i] = v.coordenadas[i];
    }
    clone->al=1;
    return 0;
}

int Conj_VerificaDimensao(TConj c){ // Verifica se todos os vetores de um TConj tem a mesma dimensao.
    int i, dim, ok;

    if(!c.al) return 2;

    dim = c.vs[0].dimensao;
    i=1;
    ok=1;
    while((i<c.n) && ok){
        if(c.vs[i].dimensao!=dim) ok=0;
        i++;
    }
    return ok;
}

int Conj_AdicionaVetor(TConj* c, TVetor v){

    if(!(c->al)) return 2;

    if(c->n == c->max)
        if(Conj_AmpliaConj(c)==-1) return -1;
    c->n = c->n + 1;
    ClonaVetor(&(c->vs[c->n-1]), v);

    return 0;
}

int Conj_RemoveVetor(TConj* c, int idx){
    int i;

    if(!(c->al)) return 2;

    c->n = c->n - 1;
    LiberaVetor(&(c->vs[idx]));
    for(i=idx; i<c->n; i++){
        c->vs[i] = c->vs[i+1];
    }
    if((c->n <= (c->max-20)) && (c->max > 20)) Conj_ReduzConj(c);
    return 0;
}

int Conj_UneConjuntos(TConj* c1, TConj c2){
    int i, n0, newn;

    if(!(c1->al) || !(c2.al)) return 2;

    newn = c1->n + c2.n;
    while(c1->max < newn)
        if(Conj_AmpliaConj(c1)==-1) return -1;

    n0 = c1->n;
    c1->n = c1->n + c2.n;
    for(i=n0; i<c1->n; i++){
        //ImprimeVetor(c2.vs[i-n0]);
        InicializaVetor(&(c1->vs[i]));
        ClonaVetor(&(c1->vs[i]), c2.vs[i-n0]);
    }
    return 0;
}

int Conj_SomaVetores(TVetor* result, TConj c){
    int i;
    TVetor aux;


    if(result->al || !(c.al)) return 2;

    if(!Conj_VerificaDimensao(c)) return 1;
    ClonaVetor(result, c.vs[0]);
    for(i=1; i<c.n; i++){
        ClonaVetor(&aux, *result);
        LiberaVetor(result);
        SomaVetor(result, aux, c.vs[i]);
    }
    return 0;
}

void Conj_ImprimeConjunto(TConj c){
    int i;

    if(c.al){
        for(i=0; i<c.n; i++){
            ImprimeVetor(c.vs[i]);
            printf("\n");
        }
    }
}

void Conj_LiberaConjunto(TConj* c){
    int i;

    if(c->al){
        for(i=0; i<c->n; i++) LiberaVetor(&(c->vs[i]));
        free(c->vs);
    }
}
