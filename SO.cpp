#include <iostream>
#include <stdlib.h>

using namespace std;


typedef struct memoria{
        int tam, *val;
}memoria;


void criarMemoria(int t,memoria *m){
        m->tam = t;
        m->val = (int*) malloc(t * sizeof(int));
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

