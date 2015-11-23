#include <iostream>
#include <stdlib.h>

using namespace std;

typedef struct memoria{
        int tam, *val;
}memoria;

typedef struct processo{
	int tam,regB,regL,id;
}processo;

memoria* criarMemoria(int t){ 
        memoria *m = (memoria*) malloc(sizeof(memoria)*t);
		m->tam = t;
        m->val = (int*) malloc(t * sizeof(int));
		return m;
}

processo* criarProcesso(int base, int lim, int id){
        processo *p = (processo*) malloc(sizeof(processo));                                                                          
        	p->regB = base; 
		p->regL = lim;
		p->id = id;
		p->tam = lim-base;
		return p;
}

void preencherMemoria(int in,int fi,int v, memoria *m){
        for(int i = in; i < fi; i++){
                m->val[i] = v; 
        }
}

void zerarMemoria(memoria *m){
        for(int i = 0; i < m->tam; i++){ 
                m->val[i] = 0;
        }
}

void liberarMemoria(memoria *m){
        free(m); 
        m = NULL;
}

void liberarProcesso(processo *p){
        free(p);
        p = NULL;
}

void escreverProcesso(processo *p,memoria *m){
	preencherMemoria(p->regB,p->regL,p->id,m);
}

void guardarProcesso(int in,int val, processo *p, memoria *m){
	preencherMemoria(in,p->regL,val,m);
}

void zerarProcesso(processo *p,memoria *m){
	preencherMemoria(p->regB,p->regL,0,m);
}

