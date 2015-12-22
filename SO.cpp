#include <iostream>
#include <stdlib.h>
 
using namespace std;
 
typedef struct{
        int inicio;
        int fim;
}area;
 
typedef struct {
        area b_area;
        int id;
}area_sobreposicao;
 
typedef struct{
        area *principal;
        area sobreposicao;
}descricao_memoria;
 
typedef struct {
        area principal;
        area_sobreposicao *sobreposicao;
        int quantidade_sobreposicao;
}descricao_processo;
 
typedef struct memoria{
        int tam, *val;
        descricao_memoria dm;
}memoria;
 
typedef struct processo{
        int tam,regB,regL,id;
        descricao_processo dp;
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
 
descricao_memoria get_descricao_memoria(memoria *m){
        return m->dm;
}
 
descricao_processo get_descricao_processo(processo *p){
        return p->dp;
}
 
bool alocar_processo_sobreposicao(memoria *m, processo *p,int id){
       
        if(p->dp.sobreposicao[id].b_area.fim - p->dp.sobreposicao[id].b_area.inicio > m->dm.sobreposicao.fim - m->dm.sobreposicao.inicio)return false;
       
        return true;
}
                       
bool alocar_processo_simples(memoria *m, processo *p){
        if(p->tam <= m->tam){
                escreverProcesso(p, m);
                return true;
        }
        return false;
}
 
bool trocar_area_sobreposicao(memoria *m, processo *p, int identificador){
        if(identificador >= p->dp.quantidade_sobreposicao)return false;
        return true;
}
int main(){
    return 0;
}
