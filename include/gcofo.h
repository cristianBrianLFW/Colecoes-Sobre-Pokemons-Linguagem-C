# ifndef _GCOFO_H_
# define _GCOFO_H_
# ifdef _GCOFO_C_

/*----------------------------------------------
    O que esse arquivo faz:

    Basicamente ele define o header _GCOFO_H_

    É uma biblioteca do nosso cofo genérico

    Aqui ele precisa estar ligado a outro arquivo

    com a extensão .c para estar completo
-----------------------------------------------*/

typedef struct _gcofo_{
    int numItens;
    int maxItens;
    int cur;
    void ** itens; 
} gcofo;

gcofo * gcofoCreate ( int maxItens );

int gcofoInsert ( gcofo * c,  void * item);

void * gcofoGetFirst ( gcofo *c );

void * gcofoGetNext ( gcofo * c);

void * gcofoQuery ( gcofo * c, void * item, int (*cmp) ( void *, void *));

void * gcofoRemove ( gcofo *c, void * item , int (*cmp) ( void *, void *));

int gcofoDestroy ( gcofo * c);

int getMaxItens (gcofo * gc );

void gcofoSetCurrent (gcofo * gc, int i );

void * gcofoCurrent ( gcofo * gc );

#else

typedef struct _gcofo_ gcofo;

extern gcofo * gcofoCreate ( int maxItens );

extern int gcofoInsert ( gcofo * c,  void * item);

extern void * gcofoRemove ( gcofo *c, void * item , int (*cmp) ( void *, void *));

extern void * gcofoQuery ( gcofo * c, void * item, int (*cmp) ( void *, void *));

extern void * gcofoGetFirst ( gcofo *c );

extern void * gcofoGetNext ( gcofo * c);

extern int gcofoDestroy ( gcofo * c);

extern int getMaxItens (gcofo * gc );

extern void gcofoSetCurrent (gcofo * gc, int i );

extern void * gcofoCurrent ( gcofo * gc );


# endif
# endif