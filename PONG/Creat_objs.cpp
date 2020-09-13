#include "Function.cpp"



//-----------------------
void	CreatBall(OB_L *head);

void	CreatVerticalWall(OB_L *head);
void	CreatVerticalWall2(OB_L *head);

void	CreatHorizontalWall(OB_L *head);
void	CreatHorizontalWall2(OB_L *head);

void	CreatPlayer(OB_L *head);

void	CreatScoreboard(OB_L *head);

void 	CreatPlayerTest(OB_L *head);

//--------------
void 	CreatPlayerTest(OB_L *head){
		
	OBJ  player ;
	SetOBJNULL(&player);

	if(!OpenSprite("PONG\\binarios\\player.txt",&player) ){
		ErroSpriteOpen("player.txt","PONG\\ERRO\\Erro.txt");
		SetSPRITENULL( &player.s_);
		
	}

	player.pos.X =  PLAYER_X_BEGIN +10;	//Essa possição é os n° caracteres
	player.pos.Y = PLAYER_Y_BEGIN;	

	player._main = Function_PlayerTest;

	AddElement(head, player);

}

void	CreatScoreboard(OB_L *head){
	OBJ  scoreboard ;
	SetOBJNULL(&scoreboard);
	
	scoreboard.pos.X = SCOREBOARD_X;
	scoreboard.pos.Y = SCOREBOARD_Y;
	
	scoreboard._main = Function_Scoreboard;
	
	AddElement(head, scoreboard);
}

void	CreatBall(OB_L *head){
	OBJ  ball ;
	SetOBJNULL(&ball);

	if(!OpenSprite("PONG\\binarios\\ball.txt",&ball) ){
		ErroSpriteOpen("Ball.txt","PONG\\ERRO\\Erro.txt");
		SetSPRITENULL( &ball.s_);
	}

	ball.pos.X = POSS_BALL_BEGIN_X;
	ball.pos.Y = POSS_BALL_BEGIN_Y;
	
	ball._main = Function_Ball;
	
	// pequena gambiara
		// vai ser usado o final de *ing do sprite para armasenar os valores do vertor
		// isso não muda nada em relação a renderização
		// isso é a forma mais fácil de gardar o vetor sem mudar toda a engine
		// para tal maravilhosa ganiara vai ter que realocar tudo de novo
	char *aux =  ball.s_.img;
	
	int size_now = 0;// quantidade de bytes alocado originalemte 
	for(; aux[size_now] != NULL; size_now++ )
			;

	ball.s_.img = (char *) malloc( sizeof(char) * size_now  +  2 ); // + vetor
	
	for(int i = 0; aux[i] != NULL; i++ )
		ball.s_.img[i] = aux[i];
	
	free(aux); // libera a velha memoria 

	// cada byte pode armasenar de -99 até 99

	ball.s_.img[size_now +1] =  AXIS_X_SPEED_BALL ; //garda a parte inteira de x	
	
	ball.s_.img[size_now+2] = AXIS_Y_SPEED_BALL;	//garda y

	ball.s_.img[size_now] = NULL; // finalsiza a lista 
	
	//printf("%d,%d,%d",	ball.s_.img[size_now] ,ball.s_.img[size_now+1], ball.s_.img[size_now+2]);
	
	AddElement(head, ball);

}

void	CreatVerticalWall(OB_L *head){
	OBJ  vertical_wall ;
	SetOBJNULL(&vertical_wall);

	if(!OpenSprite("PONG\\binarios\\vertical wall.txt",&vertical_wall) ){
		ErroSpriteOpen("vertical wall.txt","PONG\\ERRO\\Erro.txt");
		SetSPRITENULL( &vertical_wall.s_);
		
	}

	vertical_wall.pos.X =  LEFT_SPACE ;	//Essa possição é os n° caracteres
	vertical_wall.pos.Y = TOP_SPACE +1;	

	vertical_wall._main = Function_VerticalWall;

	AddElement(head, vertical_wall);
}

void	CreatVerticalWall2(OB_L *head){
	OBJ  vertical_wall ;
	SetOBJNULL(&vertical_wall);

	if(!OpenSprite("PONG\\binarios\\vertical wall.txt",&vertical_wall) ){
		ErroSpriteOpen("vertical wall.txt","PONG\\ERRO\\Erro.txt");
		SetSPRITENULL( &vertical_wall.s_);
	}

	vertical_wall.pos.X = RIGHT_SPACE   ;	//Essa possição é os n° caracteres
	vertical_wall.pos.Y = TOP_SPACE +1 ;	

	vertical_wall._main = Function_VerticalWall;

	AddElement(head, vertical_wall);
}

void	CreatHorizontalWall(OB_L *head){
	OBJ  Horizontal_wall ;
	SetOBJNULL(&Horizontal_wall);

	if(!OpenSprite("PONG\\binarios\\horizontal wall.txt",&Horizontal_wall) ){
		ErroSpriteOpen("Horizontal wall.txt","PONG\\ERRO\\Erro.txt");
		SetSPRITENULL( &Horizontal_wall.s_);
	}

	Horizontal_wall.pos.X =  LEFT_SPACE +1 ;	//Essa possição é os n° caracteres
	Horizontal_wall.pos.Y = TOP_SPACE;	

	Horizontal_wall._main = Function_HorizontalWall;

	AddElement(head, Horizontal_wall);
}

void	CreatHorizontalWall2(OB_L *head){
	OBJ  Horizontal_wall ;
	SetOBJNULL(&Horizontal_wall);

	if(!OpenSprite("PONG\\binarios\\horizontal wall.txt",&Horizontal_wall) ){
		ErroSpriteOpen("Horizontal wall.txt","PONG\\ERRO\\Erro.txt");
		SetSPRITENULL( &Horizontal_wall.s_);
	}

	Horizontal_wall.pos.X =  LEFT_SPACE +1;	//Essa possição é os n° caracteres
	Horizontal_wall.pos.Y = BOTTOM_SPACE;	

	Horizontal_wall._main = Function_HorizontalWall;

	AddElement(head, Horizontal_wall);
}

void	CreatPlayer(OB_L *head){
	
	OBJ  player ;
	SetOBJNULL(&player);

	if(!OpenSprite("PONG\\binarios\\player.txt",&player) ){
		ErroSpriteOpen("player.txt","PONG\\ERRO\\Erro.txt");
		SetSPRITENULL( &player.s_);
		
	}

	player.pos.X =  PLAYER_X_BEGIN;	//Essa possição é os n° caracteres
	player.pos.Y = PLAYER_Y_BEGIN;	

	player._main = Function_Player;

	AddElement(head,player);
}


