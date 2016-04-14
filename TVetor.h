#ifndef _TVETOR
#define _TVETOR

typedef struct{
    int al;
    double* coordenadas;
    int dimensao;
} TVetor;

void InicializaVetor(TVetor *);
int LeVetor(TVetor *);
int CriaVetor(TVetor *, int, ...);
int SomaVetor(TVetor *, TVetor, TVetor);
int SubtraiVetor(TVetor *, TVetor, TVetor);
int ProdutoEscalar(double *, TVetor, TVetor);
int ProdutoVetorial(TVetor *, TVetor, TVetor);
int ProdutoMisto(double *, TVetor, TVetor, TVetor);
void ImprimeVetor(TVetor);
void LiberaVetor(TVetor*);

#endif
