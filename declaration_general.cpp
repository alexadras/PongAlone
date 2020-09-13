/*
	Name:declaration_general.cpp
	Author: Alex Terolti
	Date: 24/07/19 01:19
	Description:
		Arquivo base para o esto dos arquivos da engine sprite asii V1
		Aqui é declarado tudo que é nesesario para funcionamento geral do sistema
*/


//Const Defines
#define CHAR_NULL '°'    //caracter que não vai ser mostrado na tela
#define TITLE_MAIN "title Pong Alone - Copyright (c) 2020 Alex Terolti "

#define SIZE_FONTE  20

#define WIDTH_SCREEN    50 * SIZE_FONTE
#define HEIGHT_SCREEN   25 * SIZE_FONTE

#define POSS_SCREEN_X   50
#define POSS_SCREEN_Y   50

// tecla do teclado
#define	C_RIGHT  77 // direita
#define C_LEFT  75 // esqueda
#define C_TOP  72 // cima
#define C_BOTTOM 80  // baixo



#define COLOR_MAIN "color 0f"
//transformadores 
#define TRANSFORM_VARIABLE_PONT(i,type) ((type*)&i)	//variavel em ponteiro
#define TRANSFORM_PONT_VARIABLE(i,type) ((type*)&i)// ponteiro em variavel
#define TRANSFORM_PONT_PONT(i,type) ((type*)i)


#define TRANSFORM_ARY(x,y,w) (x + w*y)
///-----------------------

//-------------------
typedef void (*FUNCTION)(void*, void*); // *lista // obj
//-------------------
typedef struct SPRITE{
		char *img;			//garda a informação em si
		int width, height;	//a larguar e altura de cada imagens
		int num;		// a quantidade de sprites de  arquivo
	}SPRITE;
	
typedef struct OBJ{
		SPRITE s_;	//garda um sprite 
		COORD pos;	//sua possição na tela
		int startSprite, endSprite;	//quais sprites serão usados 
		FUNCTION _main;	//função que agê no jogo
		BOOL switched;	//diz se o obj está ativo
	}OBJ;

typedef struct OB_L{
		OBJ *_obj;	//obj apontado
		OB_L *_next;	//o proximo elemento da lista
		OB_L *_head;	// o primeiro elemento da lista que sempre tem um*obj = NULL;
	}OB_L;
//-------------

void FunctionNULL(void* a, void* b){
	return;
}
