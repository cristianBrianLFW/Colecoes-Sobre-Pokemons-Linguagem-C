# define _POKEMONLIB_C_

# include <stdio.h>

# include <stdlib.h>

# include <string.h>

# include "pokemonlib.h"



int setNome (Pokemon * p, char * nome){

    if ( p != NULL && nome != NULL){
        strcpy( p->nome, nome);        
    }

    else {
        return false;
    }

    if ( !strcmp ( p->nome, nome)){
        return true;
    }
    return false;
    

}

int setNPokedex ( Pokemon * p, int nPokedex){

    if ( p != NULL ){
        if ( nPokedex >= 0){
            p->nPokedex = nPokedex;
            return true;
        }
    }

    return false;
}

int setAtributos (Pokemon * p, char ** sAtributos, int nAtributos){

    int i, j;

    if ( p != NULL ){
        if (sAtributos != NULL ){
            if ( nAtributos > 0 ){

                p->nAtributos = nAtributos;

                p->sAtributos = (char **) malloc (sizeof (char *) * p->nAtributos);


                if ( p -> sAtributos != NULL ){

                    i = 0;

                    while ( i < nAtributos ){
    
                        p->sAtributos [i] = ( char*) malloc (sizeof (char) * TAM_STRING);

                        
                        if ( p -> sAtributos[ i ] == NULL ){
                            j = i - 1;
                            
                            while ( j >= 0 ){
                                free ( p ->sAtributos [j]);
                                j--;
                            }
                            
                            free ( p -> sAtributos);
                            
                            return false;
                        }
                        
                        strcpy ( p->sAtributos[i], sAtributos[i]);
                        
                        i++;
                    }

                }

                return true;
            }
        }
    }

    return false;

}

int setCor ( Pokemon * p, int cor ){
    if ( p != NULL){
        if ( cor  >= 0){
            p->cor = cor;
            return true;
        }
    }

    return false;
}

int setPeso ( Pokemon * p, double peso ){
    if ( p != NULL ){
        if ( peso >= 0){
            p->peso = peso;
            return true;
        }
    }
    return false;
}

Pokemon * pokemonCreate (char * nome, int nPokedex, char ** sAtributos, int nAtributos, int cor, double peso){

    Pokemon * p = ( Pokemon * ) malloc ( sizeof ( Pokemon ));
    
    int check [5] = { 0, 0, 0, 0, 0};

    int i = 0;

    if ( p != NULL ){
        
    
        check [0] = setNome ( p, nome);
    
        check [1] = setNPokedex ( p, nPokedex);
    
        check [2] = setAtributos (p, sAtributos, nAtributos);

        check [3] = setCor (p, cor);

        check [4] = setPeso ( p, peso );

    }

    while ( i < 5 ){
        if ( check [i] == false ){
            free ( p );
            return NULL;
        }

        i++;
    }

    return p;   
}

char * getNome ( Pokemon * p ){
    if ( p != NULL ){
        return p -> nome;
    }
}

int getNPokedex ( Pokemon * p){
    if ( p != NULL ){
        return p->nPokedex;
    }
}

char ** getSAtributos (Pokemon * p){
    if ( p != NULL ){
        return p->sAtributos;
    }
}

int getNAtributos (Pokemon * p){
    if ( p != NULL ){
        return p->nAtributos;
    }
}

int getCor ( Pokemon * p){
    if ( p != NULL ){
        return p->cor;
    }
}

double getPeso ( Pokemon * p){
    if ( p != NULL ){
        return p -> peso;
    }
}

int cmpNomePokemon (void * a, void * b){

    char * ptrs = NULL; Pokemon * ptrp = NULL;

    ptrs = (char *) a; ptrp = (Pokemon *) b;

    if ( !(strcmp (ptrs, ptrp ->nome))){
        return true;
    }

    return false;
}

int cmpNPokedexPokemon ( void * a, void * b){

    int * pa;  Pokemon * pPokemon;

    pa = ( int * ) a; pPokemon = (Pokemon *) b;

    if ( *pa == getNPokedex ( pPokemon)){
        return true;
    }

    return false;
}