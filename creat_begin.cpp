extern OBJ begin;

void Creat_begin();
void Function_begin(void* head, void* obj);
//---------
void Creat_begin(){
	SetOBJNULL(&begin);

	if(!OpenSprite("PONG\\binarios\\boll.txt",&begin) )
		puts("deu merda amigão");
	
	begin.pos.X = 10;
	begin.pos.Y = 10;
	
	begin._main = Function_begin;
	
}

void Function_begin(void* head, void* obj){
	OBJ * aux = (OBJ*) obj;
	aux->pos.X ++;
	aux->pos.Y += 2;

//	GotoCoord(begin.pos);
	//putchar('0' + begin.s_.height);
}

