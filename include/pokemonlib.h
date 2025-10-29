/*-------------------------------------
         Definicoes Globais  
-------------------------------------*/

# define TAM_STRING 30

# ifndef true

# define true 1

#endif

# ifndef false

# define false 0

# endif

typedef const char* CORES_POKEMON[13];


/*--------------------------------------------------------
    Definicoes Para Criacao da Biblioteca
    
        --> PokemonLib

        --> Primeiro a Definimos ( caso não esteja definida)

        --> Depois vemos se PokemonLib.c estiver definida Passamos
    
            as funcoes normalmente

        --> se nao, elas sao externas 
---------------------------------------------------------*/

# ifndef _POKEMONLIB_H_
# define _POKEMONLIB_H_
# ifdef _POKEMONLIB_C_

typedef struct _POKEMON_ {
    
    char nome [TAM_STRING];

    int nPokedex; // numero Pokedex

    char ** sAtributos; // conjuntos de String dos Atributos
    
    int nAtributos; // numero Atributos

    int cor;  // cor de acordo com uma tabela Enum 

    double peso; // peso do pokemon
}Pokemon;

typedef enum _Atributos_{
    FOGO,
    AGUA,
    NORMAL,
    PLANTA,
    ELETRICO,
    VENENO,
    LUTADOR,
    FADA,
    GELO,
    METAL,
    VOADOR,
    INSETO
    
} Atributos;


CORES_POKEMON coresPokemon = {
    "\033[91m",  // 0 FOGO
    "\033[94m",  // 1 AGUA
    "\033[93m",  // 2 ELETRICO (amarelo visível)
    "\033[92m",  // 3 PLANTA
    "\033[37m",  // 4 NORMAL
    "\033[31m",  // 5 LUTADOR
    "\033[95m",  // 6 VENENO
    "\033[1;95m",// 7 FADA
    "\033[96m",  // 8 GELO
    "\033[90m",  // 9 METAL
    "\033[94m",  // 10 VOADOR
    "\033[32m",  // 11 INSETO
    "\033[0m"    // 12 RESET
};

int setNome (Pokemon * p, char * nome);

int setNPokedex ( Pokemon * p, int nPokedex);

int setAtributos (Pokemon * p, char ** sAtributos, int nAtributos);

int setCor ( Pokemon * p, int cor );

int setPeso ( Pokemon * p, double peso );

Pokemon * pokemonCreate (char * nome, int nPokedex, char ** sAtributos, int nAtributos, int cor, double peso);

char * getNome ( Pokemon * p );

int getNPokedex ( Pokemon * p);

char ** getSAtributos (Pokemon * p);

int getNAtributos (Pokemon * p);

int getCor ( Pokemon * p);

double getPeso ( Pokemon * p);

int cmpNomePokemon (void * a, void * b);

int cmpNPokedexPokemon ( void * a, void * b);


# else 

typedef struct _POKEMON_ Pokemon;

typedef enum _Atributos_ Atributos;

extern CORES_POKEMON coresPokemon;

extern int setNome (Pokemon * p, char * nome);

extern int setNPokedex ( Pokemon * p, int nPokedex);

extern int setAtributos (Pokemon * p, char ** sAtributos, int nAtributos);

extern int setCor ( Pokemon * p, int cor );

extern int setPeso ( Pokemon * p, double peso );

extern Pokemon * pokemonCreate (char * nome, int nPokedex, char ** sAtributos, int nAtributos, int cor, double peso);

extern char * getNome ( Pokemon * p );

extern int getNPokedex ( Pokemon * p);

extern char ** getSAtributos (Pokemon * p);

extern int getNAtributos (Pokemon * p);

extern int getCor ( Pokemon * p);

extern double getPeso ( Pokemon * p);

extern int cmpNomePokemon (void * a, void * b);

extern int cmpNPokedexPokemon ( void * a, void * b);

# endif
# endif





