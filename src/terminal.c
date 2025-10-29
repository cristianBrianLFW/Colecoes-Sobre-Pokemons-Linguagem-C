# define _TERMINAL_C_

# include <stdio.h>

# include <stdlib.h>

# include <string.h>

# include "terminal.h"

# include "gcofo.h"


void telaAbertura (){


    printf("\n");
    printf ("\n");
    printf("██████╗ ███████╗███╗   ███╗      ██╗   ██╗██╗███╗   ██╗██████╗  ██████╗  \n");
    printf("██╔══██╗██╔════╝████╗ ████║      ██║   ██║██║████╗  ██║██╔══██╗██╔═══██╗ \n");
    printf("██████╔╝█████╗  ██╔████╔██║█████╗██║   ██║██║██╔██╗ ██║██║  ██║██║   ██║ \n");
    printf("██╔══██╗██╔══╝  ██║╚██╔╝██║╚════╝╚██╗ ██╔╝██║██║╚██╗██║██║  ██║██║   ██║ \n");
    printf("██████╔╝███████╗██║ ╚═╝ ██║       ╚████╔╝ ██║██║ ╚████║██████╔╝╚██████╔╝ \n");
    printf("╚═════╝ ╚══════╝╚═╝     ╚═╝        ╚═══╝  ╚═╝╚═╝  ╚═══╝╚═════╝  ╚═════╝  \n");
    printf("\n");

     
    printf("█████╗  ██████╗ \n");
    printf("██╔══██╗██╔═══██╗\n");
    printf("███████║██║   ██║\n");
    printf("██╔══██║██║   ██║\n");
    printf("██║  ██║╚██████╔╝\n");
    printf("╚═╝  ╚═╝ ╚═════╝ \n");
    printf("\n");

     
    printf("███╗   ███╗██╗   ██╗███╗   ██╗██████╗  ██████╗ \n");
    printf("████╗ ████║██║   ██║████╗  ██║██╔══██╗██╔═══██╗\n");
    printf("██╔████╔██║██║   ██║██╔██╗ ██║██║  ██║██║   ██║\n");
    printf("██║╚██╔╝██║██║   ██║██║╚██╗██║██║  ██║██║   ██║\n");
    printf("██║ ╚═╝ ██║╚██████╔╝██║ ╚████║██████╔╝╚██████╔╝\n");
    printf("╚═╝     ╚═╝ ╚═════╝ ╚═╝  ╚═══╝╚═════╝  ╚═════╝ \n");
    printf("\n");


    printf("██████╗  ██████╗ ██╗  ██╗███████╗███╗   ███╗ ██████╗ ███╗   ██╗\n");
    printf("██╔══██╗██╔═══██╗██║ ██╔╝██╔════╝████╗ ████║██╔═══██╗████╗  ██║\n");
    printf("██████╔╝██║   ██║█████╔╝ █████╗  ██╔████╔██║██║   ██║██╔██╗ ██║\n");
    printf("██╔═══╝ ██║   ██║██╔═██╗ ██╔══╝  ██║╚██╔╝██║██║   ██║██║╚██╗██║\n");
    printf("██║     ╚██████╔╝██║  ██╗███████╗██║ ╚═╝ ██║╚██████╔╝██║ ╚████║\n");
    printf("╚═╝      ╚═════╝ ╚═╝  ╚═╝╚══════╝╚═╝     ╚═╝ ╚═════╝ ╚═╝  ╚═══╝\n");
    printf ("\n\n");
    printf ("( A p e r t e  Q u a l q u e r  t e c l a  p a r a  C o n t i n u a r . . . )  ");
    printf("\n");
    getchar ();
    printf("\033[2J\033[H"); 

}


int menuEscolha () {

    int escolha;

    while ( true ){
        
        printf ("\n\n");
        
        printf ("□═════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════□\n\n\n" );
    
        printf (" □  C r i a r  a  P o k e d e x                                                                             A p e r t e  0\n\n\n");
    
        printf (" □  A d i c i o n a r  u m  P o k e m o n                                                                   A p e r t e  1\n\n\n");
    
        printf (" □  L i s t a r  t o d o s  o s  P o k e m o n s                                                            A p e r t e  2\n\n\n");
    
        printf (" □  E n v i a r  u m  P o k e m o n  a o  P r o f e s s o r  C a r v a l h o                                A p e r t e  3\n\n\n");
    
        printf (" □  P r o c u r a r  a l g u m  P o k e m o n  n a  S u a  P o k e d e x                                    A p e r t e  4\n\n\n");
    
        printf (" □  E n v i a r  t o d o s  o s  P o k e m o n s  p a r a  o  P r o f e s s o r  C a r v a l h o            A p e r t e  5\n\n\n");
    
        printf (" □  E n c e r r a r  J o r n a d a  P o k e m o n                                                           A p e r t e  6\n\n\n");
    
        printf ("□═════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════□\n\n\n" );

        printf ("S u a  E s c o l h a :  ");  // tente apenas numeros 

        scanf ("%d", &escolha);

        if ( escolha >= 0 && escolha <= 6){

            printf("\033[2J\033[H"); 

            return escolha;
        }

        else {
            printf ("\n\nR e s p o s t a  I n v a l i d a ( C l i q u e  Q u a l q u e r  t e c l a  p a r a  C o n t i n u a r )\n\n");
    
            getchar ();
    
            getchar();
    
            printf("\033[2J\033[H"); 

        }
    }
}

gcofo * criandoPokedex (){

    int tPokedex;

    printf ("\n\nC r i a n d o  a  P o k e d e x . . . \n\n");

    printf ("D i g i t e  q u a n t o s   P o k e m o s   d e s e j a   s a l v a r \n\n");
    
    printf ("S u a  R e s p o s t a : ");

    scanf ("%d", &tPokedex);

    gcofo * gc = gcofoCreate (tPokedex);

    if ( gc != NULL ){
        return gc;
    } 
    
    else {
        return NULL;
    }
}

int addPokemon ( gcofo * gc, int nPokedex ){

    char nome [TAM_STRING];

    double peso; int cor;
    
    char ** sAtributos;
    
    int nAtributos, valido = false, atr;

    int i, j;

    int status = false;
    
    printf ("A d i c i o n a n d o  u m  P o k e m o n . . .\n\n\n");

    printf ("D i g i t e  o  n o m e  d o  P o k e m o n: ");

    scanf ("%s", nome);

    printf ("\n\n\n");


    printf ("A t u a l m e n t e  s e u  P o k e m o n  s e  E n c o n t r a  n a  P o s i c a o %d d a  P o k e d e x \n", nPokedex);

    printf ("\n\n\n");

    printf ("D i g i t e  o  p e s o  d o  P o k e m o n : ");

    scanf ("%lf", &peso);

    printf ("\n\n\n");

    printf ("I n f o r m e  a  Q u a n t i d a d e  d e  A t r i b u t o s  q u e  S e u  P o k e m o n  P o s s u i : ");

    scanf ("%d", &nAtributos);

    sAtributos = ( char ** ) malloc ( sizeof ( char *) * nAtributos);

    if ( sAtributos != NULL) {

        i = 0;

        while ( i < nAtributos){
            
            sAtributos[i] = ( char *)  malloc ( sizeof ( char) * TAM_STRING);
    
            if ( sAtributos[i] == NULL ){
                j = i - 1;
                while ( j >= 0 ){
                    free (sAtributos[j]);
                    j--;
                }
    
                free ( sAtributos);
    
                return false;
            }

            i++;
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
                strcpy ( sAtributos[i], "F O G O" );   
                break;

                case 1:
                strcpy ( sAtributos[i], "A G U A" );
                break;

                case 2:
                strcpy ( sAtributos[i], "E L E T R I C O" );
                break;


                case 3:
                strcpy ( sAtributos[i], "P L A N T A" );
                break;                    

                case 4:
                strcpy ( sAtributos[i], "N O R M A L" );
                break;
                

                case 5:
                strcpy ( sAtributos[i], "L U  T A D O R" );
                break;
                    
                
                case 6:
                strcpy ( sAtributos[i], "V E N E N O" );
                break;
                   

                case 7:
                strcpy ( sAtributos[i], "F A D A " );
                break;

                case 8:
                strcpy ( sAtributos[i], "G E L O" );
                break;
                    
                   

                case 9: 
                strcpy ( sAtributos[i], "M E T A L" );
                break;

                case 10:

                strcpy ( sAtributos[i], "V O A D O R" );
                break;

                    
                case 11:
                strcpy ( sAtributos[i], "I N S E T O" );
                break;
                
                    
            }

            if ( i == 0 ){
                cor = atr;
            }

            i++;

            printf("\033[2J\033[H"); 


        }

        else {
            printf ("\n\nR e s p o s t a  I n v a l i d a  !\n\n");

        }

    }

    Pokemon * p = pokemonCreate(nome, nPokedex, sAtributos, nAtributos, cor, peso);

    // liberando estrutura alocada

    i = 0;

    while ( i < nAtributos){
        free ( sAtributos [i]);
        i++;
    }

    free ( sAtributos);


    if ( p != NULL){
        return gcofoInsert ( gc, (void *) p);
    }

    else {
        return false;
    }

}

void mostrarPokemon (Pokemon * p){

    int tString;

    int i, j;

    if ( p != NULL ){

        printf ("\n\nP o k e m o n : %03d\n\n", getNPokedex( p ));

        tString = strlen ( getNome( p ));

        i = 0;

        printf("%s", coresPokemon[getCor ( p )]);

        while ( getNome ( p ) [i] != '\0'){
            printf ("%c ", getNome( p ) [i]);
            i++;
        }

        printf("\n\n");

        printf("P e s o  P o k e m o n : %4.2lf\n\n", getPeso( p ));

        j = 0;

        printf ("A t r i b u t o s :\n");

        while ( j  < getNAtributos ( p )){
            printf ("%s\n", getSAtributos( p )[j]);
            j++;
        }

        printf ("%s", coresPokemon[12]);

    }

}

void listarPokemons ( gcofo * gc ){

    Pokemon * p = gcofoGetFirst (gc);

    while ( p != NULL ){
        mostrarPokemon ( p );
        p = gcofoGetNext ( gc );
    }
}


int enviarPokemon ( ){

    int valido = false;

    int escolha;
    
    while ( valido == false ){
    
        printf ("□═════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════□" );
    
        printf("E s c o l h a  p o r  Q u a l   C a r a c t e r i s t i c a \n\n\n");
    
        printf (" □  N o m e             A p e r t e  0                  □ N u m e r o  P o k e b o l a              A p e r t e  1\n\n\n");
       
        printf ("□═════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════□\n\n" );

        printf ("S u a  R e s p o s t a : ");

        scanf ("%d", &escolha);

        if ( escolha >= 0 && escolha <= 1){
            return escolha;
        }

        else {

            printf ("\n\nR e s p o s t a  I n v a l i d a ( C l i q u e  Q u a l q u e r  t e c l a  p a r a  C o n t i n u a r )\n\n");

            getchar ();

            getchar();

            printf("\033[2J\033[H"); 

        }
    }

    
}