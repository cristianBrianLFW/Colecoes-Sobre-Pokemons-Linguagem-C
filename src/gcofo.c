# define _GCOFO_C_
# include "gcofo.h"
# include <stdlib.h>
# define true 1
# define false 0

/*---------------------------------------------------
            Requisitos do Cofo Genérico
    O cofo é uma estrutura de dados que representa uma 
    
    coleção de dados

    Assim, a sua biblioteca deve permitir:

    --> Criar o cofo 

    --> Inserir um elemento no cofo

    --> Pegar o primeiro elemento do cofo

    --> Pegar o próximo elemento do cofo

    --> checar se um elemento existe no cofo

    --> Remover um elemento do cofo

    --> Destruir o cofo
----------------------------------------------------*/


/*----------------------------------------------------
                    gcofoCreate                       

    Para se criar um cofo, é preciso saber:           

    qual a quantidade máxima de elementos nesse cofo

    então:

    --> precisa alocar o cofo

    --> testar se alocação deu certo 

    --> definir o numItens como 0

    --> definir o maxItens como maxItens

    --> definir o vetor itens com tamanho maxItens
----------------------------------------------------*/

gcofo * gcofoCreate (int maxItens ){

    gcofo * c;

    c = ( gcofo * ) malloc (sizeof ( gcofo));

    if ( c != NULL ){
        if ( maxItens > 0 ){
            c -> numItens = 0;
            c -> maxItens = maxItens;
            c ->itens = ( void ** ) malloc ( sizeof ( void *) * maxItens);
            c -> cur = -1;
            return c;
        }
        free ( c );
    }
    return NULL;
}

/*-----------------------------------------------------------
                        gcofoInsert
    Para inserir um elmento do cofo é preciso algumas coisas

    --> se o cofo existe

    --> se o cofo não está completamente cheio

    então eu o insiro na posição numItens

    incremento numItens

    retorno true se deu tudo certo

    false se deu algo errado    
----------------------------------------------------------------*/

int gcofoInsert ( gcofo * c,  void * item){

    if ( c != NULL ){
        if ( c ->numItens < c->maxItens ){
            c->itens[c->numItens] = item;
            c->numItens++;
            return true;
        }
    }
    return false;
}

/*---------------------------------------------------------------
                        gCofoGetFirst
    O cofo precisa existir

    O cofo precisa ter pelo menos um elemento
----------------------------------------------------------------*/

void * gcofoGetFirst ( gcofo * c ){
    if ( c != NULL ){
        if ( c -> numItens > 0){
            c -> cur = 0;
            return c -> itens [ c -> cur];
        }
    }
    return NULL;
}

/*---------------------------------------------------------------
                        gCofoGetNext
    O cofo precisa existir

    O elemento cur do cofo precisa ser menor que numItens - 1
----------------------------------------------------------------*/


void * gcofoGetNext ( gcofo * c){
    if ( c != NULL ){
        if ( c -> cur < c -> numItens - 1){
            c -> cur++;
            return c -> itens [ c ->cur ];
        }
    }

    return NULL;
}

/*---------------------------------------------------------------
                            gCofoQuery
    O cofo precisa existir

    Como o cofo é estrutura que pode colecionar dados / estruturas 

    que contém vários dados é preciso criar uma função que compara

    as duas coisas

    E o cofo não pode estar vazio
----------------------------------------------------------------*/

void * gcofoQuery ( gcofo * c, void * key, int (*cmp) ( void *, void *)){
    void * data; int status, i; 
    if ( c != NULL ){
        if ( c -> numItens > 0 ){
            i = 0;
            status = cmp ( key, c ->itens[i]);
            if ( i < c -> numItens && status != true ){
                i++;
                status = cmp ( key, c->itens[i]);
            }

            if ( status == true ){
                data = c->itens[i];
                return data;
            }
        }
    }
    return NULL;
}

void * gcofoRemove ( gcofo * c, void * data, int (*cmp) ( void *, void *)){
    void * aux; int status, i, j;
    if ( c != NULL ){
        if ( c -> numItens > 0 ){
            i = 0;
            status = cmp ( data, c->itens[i]);
            while ( i < c -> numItens && status == false ){
                i++;
                status = cmp ( data, c->itens[i]);
            }

            if ( status == true ){
                aux = c -> itens[i];
                j = i;
                while ( j < c -> numItens - 1){
                    c->itens[j] = c ->itens[j + 1];
                    j++;
                }
                c->numItens--;
                return aux;
            }

        }
    }

    return NULL;
}

int gcofoDestroy ( gcofo * c ){
    if ( c != NULL ){
        if ( c -> numItens == 0 ){
            free ( c -> itens);
            free (c);
            return true;
        }
    }
    return false;
}

int getMaxItens (gcofo * gc ){
    if ( gc != NULL ){
        return gc->maxItens;
    }
}

void gcofoSetCurrent (gcofo * gc, int i ){
    gc -> cur = i;    
}

void * gcofoCurrent ( gcofo * gc ){
    return gc -> itens [ gc -> cur];
}