// importa os recursos 
#include "includes.cpp"

// importa o progama/projeto que vai ser executado 
#include "PONG\\Pong_main.cpp" 

OB_L *head_main= CreatList();


int main(int argc , char *argv[]){

	BeginWindows();

	Creat_begin( head_main );

	while(head_main->_next != NULL){
		
		//CleanScreen();
		ExecuteList(head_main);
		Time_();
		
	}
	// termina a execução
//	AddElement( head_main, begin);
	DeleteList(head_main);
	exit(0);

 exit(0);
 
}




