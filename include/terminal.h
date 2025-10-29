/*---------------------------------------
    Variaveis e Bibilotecas Importantes 
----------------------------------------*/

# include "pokemonlib.h"

# include "gcofo.h"



#ifndef _TERMINAL_H_
#define _TERMINAL_H_
#ifdef _TERMINAL_C_

void telaAbertura ();

int menuEscolha ();

gcofo * criandoPokedex ();

int addPokemon ( gcofo * gc, int nPokedex );

void mostrarPokemon (Pokemon * p);

void listarPokemons ( gcofo * gc );

int enviarPokemon ( );

# else

extern void telaAbertura ();

extern int menuEscolha ();

extern gcofo * criandoPokedex ();

extern int addPokemon ( gcofo * gc, int nPokedex );

extern void mostrarPokemon (Pokemon * p);

extern void listarPokemons ( gcofo * gc );

extern int enviarPokemon ( );

# endif

# endif


