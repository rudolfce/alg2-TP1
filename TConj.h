#ifndef _TCONJ
#define _TCONJ

#include "TVetor.h"

typedef struct{
    TVetor* vs;
    int n;
    int max;
    int al;
} TConj;

int Conj_InicializaConj(TConj *);
int Conj_AmpliaConj(TConj *);
int Conj_ReduzConj(TConj *);
int ClonaVetor(TVetor*, TVetor);
int Conj_VerificaDimensao(TConj);
int Conj_AdicionaVetor(TConj *, TVetor);
int Conj_RemoveVetor(TConj *, int);
int Conj_UneConjuntos(TConj *, TConj);
int Conj_SomaVetores(TVetor *, TConj);
void Conj_ImprimeConjunto(TConj);
void Conj_LiberaConjunto(TConj*);

#endif
