# include <stdio.h>

# include <stdlib.h>

# include "terminal.h"

# include "pokemonlib.h"

# include "gcofo.h"

int main (void){

    // flags 

    int escolha; /* acao a ser feita  */    
    
    int add = false; /* add pokemon deu certo */  

    int env; /*Como Enviar */
    
    int journey = true; /* Controle do Fluxo do Programa */

    int end = false; /* Finalizar o Programa */


    // atributos pokemons

    gcofo * myPokedex = NULL;  // Pokedex

    Pokemon * p, * aux; // Pokemon para Manipulacao

    char nomePokemon [TAM_STRING]; // nome para Manipulacao

    int nPokedex; int i, j;// int para manipulacao

    int tPokemons = 0; // totoais de pokemons

    int maxPokemons;



    telaAbertura ();

    while ( journey == true ){

        printf("\033[2J\033[H"); 
        
        escolha = menuEscolha();

        switch (escolha){
            case 0:
            
            if ( myPokedex == NULL){

                myPokedex = criandoPokedex ();

                if ( myPokedex != NULL ){
                    printf ("\n\nP o k e d e x  C r i a d a  C o m  S u c e s s o\n\n");
                }
                else {
                    printf ("\n\nE r r o  a o  C r i a r  a  P o k e d e x\n\n");
                }
                
            } else {
                printf ("\n\nA  s u a  P o k e d e x  j a  f o i  C r i a d a  ( M A X :  %d  P o k e m o n s )\n\n", getMaxItens(myPokedex));
            }

            break;
            
            case 1:

            if ( myPokedex != NULL){
                
                tPokemons++;
    
                add = addPokemon (myPokedex, tPokemons);
    
                if ( add == true ){
                    printf ("P o k e m o n  R e g i s t r a d o  n a  P o k e d e x  C o m  S u c e s s o !!!\n");
                }
    
                else{
                     printf ("E r r o  a o  R e g i s t r a r  P o k e m o n \n\n");
                }
            } 

            else {
                printf ("C r i e  S u a  P o k e d e x  P r i m e i r o !\n\n");
            }

            break;

            case 2:

            if ( myPokedex != NULL){
                
                if ( tPokemons > 0 ){


                    listarPokemons ( myPokedex );
    
                    printf ("\n\nE s s e s  s a o  T o d o s  S e u s  P o k e m o n s\n\n");
                }
    
                else {
                    printf ("\n\nA  P o k e d e x  e s t a  V a z i a \n\n");
                }
            }

            else {
                printf ("\n\nC r i e  S u a  P o k e d e x  P r i m e i r o !\n\n");
            }

            break;

            case 3:        

            if ( myPokedex != NULL){
                if ( tPokemons > 0 ){

                    printf ("\n\nE n v i a n d o  T o d o s  O s  P o k e m o n\n\n");

                    env = enviarPokemon ( );

                    if ( env == 0){

                        printf ("D i g i t e  o  n o m e  d o  P o k e m o n : ");

                        scanf ("%s", nomePokemon);

                        p = gcofoRemove (myPokedex, (void *) nomePokemon, cmpNomePokemon );

                        if ( p != NULL ){
                            
                            mostrarPokemon ( p );

                            i = getNPokedex ( p );

                            gcofoSetCurrent ( myPokedex, i);

                            aux = gcofoCurrent ( myPokedex );

                            while (aux != NULL ){
                                setNPokedex (aux, getNPokedex ( aux) - 1 );
                                aux = gcofoGetNext( myPokedex );
                            }                           

                            free ( p );
    
                            tPokemons--; 
    
                            printf ("\n\nP o k e m o n  E n v i a d o  C o m  S u c e s s o  A o  P r o f e s s o r  C a r v a l h o\n\n");



                        }

                        else {
                            printf ("\n\nP o k e m o n  n a o  E n c o n t r a d o\n\n");
                        }

                    }

                    if ( env == 1){

                        printf ("D i g i t e  o  N u m e r o  d a  P o k e d e x : ");

                        scanf ("%d", &nPokedex);

                        p = gcofoRemove (myPokedex, (void *) &nPokedex, cmpNPokedexPokemon);

                        if ( p != NULL ){
                            
                            mostrarPokemon ( p );

                            i = getNPokedex ( p );

                            gcofoSetCurrent ( myPokedex, i);

                            aux = gcofoCurrent ( myPokedex );

                            while (aux != NULL ){
                                setNPokedex (aux, getNPokedex ( aux) - 1 );
                                aux = gcofoGetNext( myPokedex );
                            }                           

                            free ( p );
    
                            tPokemons--; 
    
                            printf ("\n\nP o k e m o n  E n v i a d o  C o m  S u c e s s o  A o  P r o f e s s o r  C a r v a l h o\n\n");

                        }

                        else {
                            printf ("\n\nP o k e m o n  n a o  E n c o n t r a d o\n\n");
                        }

                    }

                }

                else {
                    printf ("\n\nA d i c i o n e  um P o k e m o n   P r i m e i r o !\n\n");
                }

            }

            else {
                printf ("\n\nC r i e  S u a  P o k e d e x  P r i m e i r o !\n\n");
            }

            break;

            case 4:          

            if ( myPokedex != NULL){
                if ( tPokemons > 0 ){

                    env = enviarPokemon ( );

                    if ( env == 0){

                        printf ("D i g i t e  o  n o m e  d o  P o k e m o n : ");

                        scanf ("%s", nomePokemon);

                        p = gcofoQuery (myPokedex, (void *) nomePokemon, cmpNomePokemon );

                        if ( p != NULL ){
                            
                            mostrarPokemon ( p );
    
                            printf ("\n\nP o k e m o n  E n c o n t r a d o ! \n\n");



                        }

                        else {
                            printf ("\n\nP o k e m o n  n a o  E n c o n t r a d o\n\n");
                        }

                    }

                    if ( env == 1){

                        printf ("D i g i t e  o  N u m e r o  d a  P o k e d e x : ");

                        scanf ("%d", &nPokedex);

                        p = gcofoQuery (myPokedex, (void *) &nPokedex, cmpNPokedexPokemon);

                        if ( p != NULL ){
                            
                            mostrarPokemon ( p );
    
                            printf ("\n\nP o k e m o n  E n c o n t r a d o ! \n\n");

                        }

                        else {
                            printf ("\n\nP o k e m o n  n a o  E n c o n t r a d o\n\n");
                        }
                    }

                }

                else {
                    printf ("\n\nA d i c i o n e  um P o k e m o n   P r i m e i r o !\n\n");
                }

            }

            else {
                printf ("\n\nC r i e  S u a  P o k e d e x  P r i m e i r o !\n\n");
            }

            break;
            
            case 5:

            if ( myPokedex != NULL){
                if ( tPokemons > 0 ){

                    printf ("\n\nE n v i a n d o  T o d o s  O s  P o k e m o n\n\n");

                    aux = gcofoGetFirst ( myPokedex );

                    while ( aux != NULL ){
                        p = gcofoRemove ( myPokedex, (void*) getNome ( aux ), cmpNomePokemon);

                        free ( p );

                        aux = gcofoGetFirst ( myPokedex );

                        tPokemons--;
                    }

                    printf ("\n\nT o d o s P o k e m o n  E n v i a d o  C o m  S u c e s s o  A o  P r o f e s s o r  C a r v a l h o\n\n");

                }

                else {
                    printf ("\n\nA d i c i o n e  um P o k e m o n   P r i m e i r o !\n\n");
                }

            }

            else {
                printf ("\n\nC r i e  S u a  P o k e d e x  P r i m e i r o !\n\n");
            }

            break;

            case 6:

           end = gcofoDestroy ( myPokedex );


            if ( end == true ){
                printf ("\n\nF o i   u m a   b e l i s s i m a   J o r n a d a   P o k e m o n \n\n");
                journey = false;
            }
            else{
                printf ("\n\nA   J o r n a d a   a i n d a   n a o   p o d e   a c a b a r\n\n");
            }

            printf ("\n");

            break;

        }

        printf ("\n\n( C l i q u e  Q u a l q u e r  t e c l a  p a r a  C o n t i n u a r )\n\n");
    
        getchar ();

        getchar();
    
        printf("\033[2J\033[H"); 


    }




}