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

    int status; // checar se true ou false


    // atributos pokemons

    gcofo * myPokedex = NULL;  // Pokedex

    Pokemon * p, * aux; // Pokemon para Manipulacao

    char nomePokemon [TAM_STRING]; // nome para Manipulacao

    int nPokedex; // numero da Pokedex
    
    int i, j;// int para manipulacao

    int tPokemons = 0; // totoais de pokemons

    int maxPokemons; // capacidade Pokedex

    double pesoPokemon; // manipulacao do peso

    int nAtributos; // quantos atributos

    int atr; // atributo em si

    char ** atributos; // string dos atributos

    int cor; // cor do pokemon



    telaAbertura ();

    while ( journey == true ){

        printf("\033[2J\033[H"); 
        
        escolha = menuEscolha();

        switch (escolha){
            case 0:
            
            if ( myPokedex == NULL){

                printf ("\n\nC r i a n d o  a  P o k e d e x . . . \n\n");

                printf ("D i g i t e  q u a n t o s   P o k e m o s   d e s e j a   s a l v a r \n\n");
                
                printf ("S u a  R e s p o s t a : ");

                scanf ("%d", &maxPokemons);

                myPokedex = gcofoCreate ( maxPokemons );


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
    
                printf ("A d i c i o n a n d o  u m  P o k e m o n . . .\n\n\n");

                printf ("D i g i t e  o  n o m e  d o  P o k e m o n: ");

                scanf ("%s", nomePokemon);

                printf ("\n\n\n");

                printf ("A t u a l m e n t e  s e u  P o k e m o n  s e  E n c o n t r a  n a  P o s i c a o %d d a  P o k e d e x \n", nPokedex);

                printf ("\n\n\n");

                printf ("D i g i t e  o  p e s o  d o  P o k e m o n : ");

                scanf ("%lf", &pesoPokemon);

                printf ("\n\n\n");

                printf ("I n f o r m e  a  Q u a n t i d a d e  d e  A t r i b u t o s  q u e  S e u  P o k e m o n  P o s s u i : ");

                scanf ("%d", &nAtributos);

                atributos = ( char ** ) malloc ( sizeof ( char ) * nAtributos);

                if ( atributos != NULL ){

                    i = 0;

                    while ( i < nAtributos){
                        atributos[i] = ( char * ) malloc ( sizeof ( char )*  TAM_STRING);
                        i++;

                        if ( atributos [ i ] == NULL ){
                            j = i - 1;
                            while ( j >= 0){
                                free ( atributos [j] );
                                j--;
                            }

                            free ( atributos);

                            status = false;

                        }
                    }

                    i = 0;

                    while ( i < nAtributos ){

        printf ("\n\n\n");
    
        printf ("□═════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════□\n\n\n");

        printf("E s c o l h a  d o  A t r i b u t o  ( %d )\n\n\n", i + 1);


        printf (" □  F O G O              A p e r t e  0                  □ A G U A               A p e r t e  1\n\n\n");

        printf (" □  E L E T R I C O      A p e r t e  2                  □ P L A N T A           A p e r t e  3\n\n\n");

        printf (" □  N O R M A L          A p e r t e  4                  □ L  U T A D O  R       A p e r t e  5\n\n\n");

        printf (" □  V E N E N O          A p e r t e  6                  □ F A D A               A p e r t e  7\n\n\n");

        printf (" □  G E L O              A p e r t e  8                  □ M E T A L             A p e r t e  9\n\n\n");

        printf (" □  V O A D O R          A p e r t e  10                 □ I N S E T O           A p e r t e  11\n\n\n");

        printf ("□═════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════□\n\n" );

        printf ("D  e f i n a  o  A t r i b u t o :  ");

        scanf ("%d", &atr);

        if ( atr >= 0 && atr <= 11 ){
            switch ( atr ){

                case 0:
                    sAtributos[i]  = "F O G O";
                   
                    break;

                case 1:
                    
                    sAtributos[i]  = "A G U A";
                    break;

                case 2: 

                    sAtributos[i]  = "E L E T R I C O";
                    break;

                case 3:

                    sAtributos[i]  = "P L A N T A";
                    break;

                case 4:
                
                    sAtributos[i]  = "N O R M A L";
                    break;

                case 5:
                    
                    sAtributos[i]  = "L U T A D O R";
                   
                    break;
                
                case 6:
                    
                    sAtributos[i]  = "V E N E N O";
    
                    break;

                case 7:

                    sAtributos[i]  = "F A D A";
                    
                    break;

                case 8:
                    
                    sAtributos[i]  = "G E L O";
                    
                    break;

                case 9: 

                    sAtributos[i]  = " M E T A L";
                    
                    break;

                case 10:

                    sAtributos[i]  = "V O A D O R";
                    break;

                case 11:
                
                    sAtributos[i]  = "I N S E T O";
                    break;
            }

            if ( i == 0 ){
                cor = atr;
            }

            i++;
        }

        else {
            printf ("\n\nR e s p o s t a  I n v a l i d a ( C l i q u e  Q u a l q u e r  t e c l a  p a r a  C o n t i n u a r )\n\n");

            getchar ();

            getchar();

            printf("\033[2J\033[H"); 
        }

    }
                    }

                }
    
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
                        p = gcofoRemove ( myPokedex, (void*) getNPokedex ( aux ), cmpNPokedexPokemon);

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