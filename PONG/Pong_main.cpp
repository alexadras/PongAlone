extern OBJ begin;

void Creat_begin(OB_L * head);

//------
#define TOP_SPACE		5 		
#define	BOTTOM_SPACE	20
#define RIGHT_SPACE		40
#define LEFT_SPACE		5
//--------------------------
#define POSS_BALL_BEGIN_X   LEFT_SPACE +10
#define POSS_BALL_BEGIN_Y   TOP_SPACE +7

#define SPEED_BALL  2.1

#define AXIS_X_SPEED_BALL 86 // numeros de 0 a 100, depois trandormados em .0 a 1.00
#define AXIS_Y_SPEED_BALL 50
//------
#define PLAYER_X_BEGIN LEFT_SPACE + 5
#define PLAYER_Y_BEGIN TOP_SPACE +7
//--------------------------
int score = 0;
int max_score = 0;
#define SCOREBOARD_X 	1
#define	SCOREBOARD_Y 	1
//---------------------------
#include "Creat_objs.cpp"
//----------------------
void Creat_begin(OB_L * head){

//	CreatPlayerTest(head);
//	
	CreatBall(head);
//	
	CreatVerticalWall(head);
	CreatVerticalWall2(head);
	
	CreatHorizontalWall(head);
	CreatHorizontalWall2(head);
//	
	CreatPlayer(head);
//	
	CreatScoreboard(head);
}
