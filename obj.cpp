OBJ *CreatOBJNULL(void);
BOOL DeleteOBJ( OBJ* obj, OB_L *head );
BOOL ExitList( OB_L *head );
void SetOBJNULL(OBJ *obj);
OBJ* FindOBJ( FUNCTION * function_obj, OB_L *head);

//---------------------------------
OBJ *CreatOBJNULL(void){
	OBJ *aux = (OBJ*) malloc(sizeof(OBJ));
	SetOBJNULL( aux );
	
	return aux;
}

BOOL DeleteOBJ( OBJ* obj, OB_L *head ){		//deleta um OBJ liberando memoria;	
}

BOOL ExitList( OB_L *head ){				// deleta um elemeto da lista e liberando a memeria de toda a lista, inclusive o head, além de liberar os obj's
}
void SetOBJNULL(OBJ *obj){
	obj->endSprite = obj->startSprite = 0;
	obj->pos.X = obj->pos.Y = 0;
	obj->switched = false;
	obj->_main = NULL;
	
	SetSPRITENULL( &obj->s_);
}


// essa função retorna o ponteiro obj de uma lista atravez de sua função main
// retorna um ponteiro nulo se não achar  
OBJ* FindOBJ( FUNCTION  function_obj, OB_L *head){
	
	for( OB_L *index = head->_next; index != NULL; index = index->_next )
			if(index->_obj->_main == function_obj )
				return index->_obj;
	
	return NULL;
}
