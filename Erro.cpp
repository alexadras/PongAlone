BOOL ErroSpriteOpen( const char * msn, const char * file_name);
//-----------------------------

BOOL ErroSpriteOpen( const char * name_obj, const char * file_name){
	
	FILE *arq;

    if((arq = fopen(file_name,"a")) == NULL){
		return false;
	}
	
	fprintf(arq, "It Doesn't open file %s",name_obj);

	return true;
	
}
