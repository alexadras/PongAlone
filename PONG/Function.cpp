void Function_Ball(void* head, void* obj);
void Function_VerticalWall(void* head, void* obj);
void Function_HorizontalWall(void* head, void* obj);
void Function_Player(void* head, void* obj);
void Function_Scoreboard(void* head, void* obj);

void Function_PlayerTest(void* head, void* obj);

extern int score;
extern int max_score;
//----------------------

void Function_PlayerTest(void* head, void* obj){
	OBJ *player = (OBJ *) obj;
	
	int c = 0;	
	
	if( kbhit()  ){			
		c = getch();	
		if( c == -32){	
			c = getch();
			
			switch(c){
				case C_TOP:
						DeleteSpriteScreen(player->s_, player->pos);
						player->pos.Y--;	
						//poss  = player->pos;
					break;
					
				case C_BOTTOM:
							DeleteSpriteScreen(player->s_, player->pos);
							player->pos.Y++;
							//poss  = player->pos;
							
					break;
				
			}
		
		}
	}
	
}

void Function_Scoreboard(void* head, void* obj){

	OBJ *ball  = FindOBJ( Function_Ball,(OB_L *) head );

	if(score >= 0){
		score ++;
		// perder o jogo 

		if( ball->pos.X < PLAYER_X_BEGIN){
			if(score > max_score )
				max_score = score ;
			
			score = -1;
		}
		
	}else 	if( ball->pos.X > PLAYER_X_BEGIN)
				score = 0;
			else
				score--;

	// exibe o resultado	
	GotoXY( SCOREBOARD_X, SCOREBOARD_Y );
	printf("    (score) %d", score / 10 );
	
	GotoXY( SCOREBOARD_X, SCOREBOARD_Y+1 );
	printf("(max score) %d", max_score /10);
}

void Function_Ball(void* head, void* obj){
	OBJ *ball = (OBJ *) obj;
	
	//cleam screen
	static COORD  p  = ball->pos;
	DeleteSpriteScreen(ball->s_,p);
	
	int size_now = 0;// quantidade de bytes alocado 

	for(; ball->s_.img[size_now] != NULL; size_now++ )
			;
	
	double x_vector = (double)ball->s_.img[size_now +1] /100;	//garda  x

	double y_vector = (double) ball->s_.img[size_now +2] /100; 	//garda  y
	
//	printf("\n%f,%f,%d",x_vector ,y_vector, size_now);
	
	static double x = ball->pos.X,	// armasena a possição com um número flutuante
				 y = ball->pos.Y;
	//move
	x +=   x_vector * SPEED_BALL;
	y +=  y_vector * SPEED_BALL;
	
	ball->pos.X = x; // Devolve de forma coprimida
	ball->pos.Y = y; 
	
	p= 	ball->pos;

}

void Function_VerticalWall(void* head, void* obj){
	OBJ *wall = (OBJ *) obj;
//	OB_L *list = ;
//  o processamento 

//>>> localiza o vetor img na ball	
	OBJ *ball  = FindOBJ( Function_Ball,(OB_L *) head );
//	if( ball == NULL) puts("dssd");
	
	int size_now = 0;// quantidade de bytes alocado em img
	for(; ball->s_.img[size_now] != NULL; size_now++ )
			;
			// só usa o x
	double x_vector = (double)ball->s_.img[size_now + 1] /100;	//garda  x

//>>> Caucula o tempo para o encotro 
	double t = (x_vector * SPEED_BALL != 0) 
			?(wall->pos.X  - ball->pos.X) / ( x_vector * SPEED_BALL ) 
			: 2; // nunca se encontra 
			// o +1 é para q a ball não sobreponha na parede 

	if( t>= -1 && t <= 1){ // se na proxima execução a ball pasar por wall
		ball->pos.X = 2*wall->pos.X  - ball->pos.X;
		x_vector =  - x_vector; 
	}
	
	// retorna o valor 
	ball->s_.img[size_now +1] = x_vector * 100 ; 
	
// faz o render sprite para ser uma linha de sprites 
	 COORD coord = wall->pos;
	
	for( ; coord.Y < BOTTOM_SPACE ; coord.Y ++ ){
		// o 1 e -1 são para deixar oas pontas vazias
		RenderSprite(&wall->s_,coord);
		
	}
	
}

void Function_HorizontalWall(void* head, void* obj){
		OBJ *wall = (OBJ *) obj;
//	OB_L *list = ;
//  o processamento 

//>>> localiza o vetor img na ball	
	OBJ *ball  = FindOBJ( Function_Ball,(OB_L *) head );
//	if( ball == NULL) puts("dssd");
	
	int size_now = 0;// quantidade de bytes alocado em img
	for(; ball->s_.img[size_now] != NULL; size_now++ )
			;
			// só usa o Y
	double y_vector = (double)ball->s_.img[size_now + 2] /100;	//garda  y

//>>> Caucula o tempo para o encotro 
	double t = (y_vector * SPEED_BALL != 0) 
			?(wall->pos.Y  - ball->pos.Y) / ( y_vector * SPEED_BALL ) 
			: 2; // nunca se encontra 
			// o +1 é para q a ball não sobreponha na parede 

	if( t>= -1 && t <= 1){ // se na proxima execução a ball pasar por wall
		ball->pos.Y = 2*wall->pos.Y  - ball->pos.Y;
		y_vector =  - y_vector; 
	}
	
	// retorna o valor 
	ball->s_.img[size_now +2] = y_vector * 100 ; 
	
// faz o render sprite para ser uma linha de sprites 
	 COORD coord = wall->pos;
	
	for( ; coord.X < RIGHT_SPACE  ; coord.X ++ ){
		// o 1 e -1 são para deixar oas pontas vazias
		RenderSprite(&wall->s_,coord);
		
	}	
}

void Function_Player(void* head, void* obj){
	OBJ * player = (OBJ *) obj;
	OBJ *ball  = FindOBJ( Function_Ball,(OB_L *) head );

// block	
	int size_now = 0;// quantidade de bytes alocado em img
	for(; ball->s_.img[size_now] != NULL; size_now++ )
			;
			// só usa o x
	double x_vector = (double)ball->s_.img[size_now + 1] /100;	//garda  x

//>>> Caucula o tempo para o encotro 
	double t = (x_vector * SPEED_BALL != 0) 
			?(player->pos.X  - ball->pos.X) / ( x_vector * SPEED_BALL ) 
			: 2; // nunca se encontra 
			// o +1 é para q a ball não sobreponha na parede 

	if( (t>= -1 && t <= 1) 
		 &&(player->pos.Y <= ball->pos.Y)
	 	 &&(player->pos.Y + player->s_.height > ball->pos.Y )
		){ 
		// se na proxima execução a ball pasar pelo player
		ball->pos.X = 2*player->pos.X  - ball->pos.X;
		x_vector =  - x_vector; 
	}
	
	// retorna o valor 
	ball->s_.img[size_now +1] = x_vector * 100 ; 

	// MOVIEMNTAÇÃO
	char c;
	static COORD  poss  = player->pos;
	
	
	if( kbhit()  ){			
		c = getch();	
		if( c == -32){	
			c = getch();
			
			switch(c){
				case C_TOP:
						if( player->pos.Y - 1 > TOP_SPACE){
							DeleteSpriteScreen(player->s_, poss);
							player->pos.Y--;
							
							poss  = player->pos;
						} 
						
					break;
				case C_BOTTOM:
						if( player->pos.Y + player->s_.height  < BOTTOM_SPACE){
							DeleteSpriteScreen(player->s_, poss);
							player->pos.Y++;
							poss  = player->pos;
						
						} 
						
					break;
				
			}
		
		}
	}





}	



