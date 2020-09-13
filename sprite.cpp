/*
	Name:sprite.cpp
	Author: Alex Terolti
	Date: 24/07/19 01:26
	Description:
		Aquivo destinado as funções do sistema grafico do sistema ascii v1
		
*/



/* TODO (pode_fazer_depois#1#): evoluir a função RenderSprite
                                fazer com que ela tenha "tamparencia" */

BOOL OpenSprite(const char *name,OBJ *obj);
void RenderSprite(SPRITE *s_, COORD pos);
void SetSPRITENULL( SPRITE * sprite);
void DeleteSpriteScreen(SPRITE formate , COORD pos);

//-----------------------------------------

void DeleteSpriteScreen(SPRITE formate , COORD pos){

	for(int x = pos.X; x < formate.width + pos.X ; x++)
		for(int y = pos.Y; y < formate.height + pos.Y ; y++){
			GotoXY(x,y);
			putchar(' ');
		}
	
}


//  prenche a estrutura sprite de obj->s_ com informações estraidas
//	do arquivo name de formato expecfico Sprite
//// retorna 0(false) se deu erro na arbertura do arquivo
// retorna 1(true) se ocoreu a arbertura do arquivo
//  essa função não verifica o formato do aquivo expecifica
//	se ele não estiver no padrão causar bugs no sprite
//  o aquivo deve ser encabesado com "(_alturaX_larguraX_num)"
//  onde: _altura indica altura de cada imagens
//		_largura a largura
//		_num a quantidade de sprites no aquivo
//  essas informações são usadas para perencher a estrutura SPRITE
//  O resto do arquivo é armasenada em obj->s_->img
BOOL OpenSprite(const char *name,OBJ *obj){
//abre um strite,preece a estrutura e coloca em um objeto
// retorna 0(false) se deu erro
	
    FILE *arq;

    if((arq = fopen(name,"r")) == NULL){
		return false;
	}

	fscanf(arq,"(%dX%dX%d)",&obj->s_.height,
							&obj->s_.width,
							&obj->s_.num);

	int size =obj->s_.num * obj->s_.height * (obj->s_.width + 1) +1;
	obj->s_.img = (char*) malloc(sizeof(char) * size);

	fread(obj->s_.img,sizeof(char), sizeof(char) * size, arq);
	
	obj->s_.img[size - 1] = NULL ; // o útimo igual a null para formar uma string 
	
	
	fclose(arq);

	return true;
}

// função tempraria vai ser modifiada depois
void RenderSprite(SPRITE *s_, COORD pos){

// int x = 0 , y =0;
//	char read = CHAR_NULL +1;   //faz com que esse caracter seja sempre valido

//	for(y=0; y<s_->height ; y++){
//
//		GotoXY(pos.X + x, pos.Y + y );
//
//		for(x=0; x<s_->width  ; x++ ){
//			if(s_->img[x + y *s_->height] == '\n' || s_->img[x + y *s_->height] == CHAR_NULL)
//				GotoXY(pos.X + x +1, pos.Y + y );
//			else
//				putchar(s_->img[x + y *s_->height]);
//		}
//
//	}

	if(s_->img == NULL)
		return ;

	for(int i = 0 ; i < s_->height * (s_->width + 1); i++){
		if(s_->img[i] != '\n')
			if(s_->img[i] != CHAR_NULL )
				putchar(s_->img[i]);
  			else
  				putchar(' ');


		else{
			GotoCoord(pos);
				pos.Y ++;
			}

	}
		
//GotoCoord(pos);putchar('3');

}

void SetSPRITENULL( SPRITE *sprite){
	sprite->height = sprite->width = sprite->num = 0;
	sprite->img = NULL;
}
