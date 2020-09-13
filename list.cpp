/*
	Name:   list.cpp
	Author: Alex Terolti
	Date: 24/07/19 00:04
	Description:
		Comjunto de fun��es que modifica as listas da engine sprite ascii v1
		O arquivo base para esse aquivo � declaration_general.cpp
*/

OB_L *CreatList();
void AddElement(OB_L *head,OBJ obj);
BOOL DeleteElemente( OB_L *head, OB_L *_elemente);
void TransformElementeInHead(OB_L *elemente);
void ListNULL(OB_L *head);
void DeleteList( OB_L *head );			

void ExecuteList(OB_L *head);

//------
//	devolve a cabe�a de uma nova lista OB_l setada com null

OB_L *CreatList(){	
	OB_L *head= (OB_L *) malloc(sizeof(OB_L));
	head->_head = NULL;
	head->_next = NULL;
	head->_obj = NULL;
	
	return head;
}

// 	adiciona um novo elemento apontando para o obj passado para a
//	 primeira possi��o da lista movendo o reto para frente
//	ela recebe head que � a cabe�a da lista
//	e o obj � o objeto a ser adicisionado
//  quando adicionado a variavel switched � setada como true
//  ativando o objeto na lista
//  a fun��o fica responsavel por alocar toda a memoria necesaria
void AddElement(OB_L *head,OBJ obj){		
	OBJ *_obj = (OBJ*) malloc( sizeof(OBJ)) ;

	_obj->endSprite = obj.endSprite;
	_obj->_main = obj._main;
	_obj->pos = obj.pos;
	_obj->startSprite = obj.startSprite;
//	_obj->switched = obj.switched;  // n�o copia o switched pois ele vai ser modificado( ativado)
	_obj->s_ = obj.s_;

	_obj->switched  = true; // ativa o obj

	OB_L *ob = (OB_L*) malloc(sizeof(OB_L));
	ob->_head = head;
	ob->_obj = _obj;
	
	ob->_next = head->_next;

	head->_next = ob;
	
}

// 	deleta todos os elementos de uma lista restando s� a cabe�a head nula
//  head � a cabe�a da lista que � ou vai virar nula
//  essa fun��o n�o exclue os obj's
void ListNULL(OB_L *head){
//exclue todos os elementos de uma lista deixando s� o head nulo
	for( OB_L *index = head->_next; index != NULL ;){
		DeleteElemente(head,index);
		index = head->_next;
	}
	TransformElementeInHead( head );
}

//  tranforma um elemento qualquer na cabe�a de uma lista setada em Nulo
void TransformElementeInHead(OB_L *elemente){
	elemente->_head = NULL;
	elemente->_obj = NULL;
}

//  ele busca o _elemente na lista de cabe�a head e o deleta da lista
//  al�m de liberar a memoria do elemento
//  n�o meche no objeto apontado pelo elmento deletado
//  obs: se n�o for salvo o obj em quest�o ele ser� pedido
// 		pois n�o � forma de recuperalo
//  retorna  false se o elemento n�o for achado
//  retorna true se o elemnto for achado
BOOL DeleteElemente( OB_L *head, OB_L *_elemente){
//	procura o elemento antes do _elemento
	for(OB_L *index = head ; index != NULL ; index = index->_next)
		if(index->_next == _elemente ){

			index->_next = _elemente->_next;
			
			free(_elemente);
			return true;
		}

	return false;
}

//  exclue todos os elementos de uma lista de cabe�a head
//	al�m de leberar a memoria da propria cabe�a
//  obs: o ponteiro n�o pode ser mais utilizado
//		 a fun��o exclue os objs
void DeleteList( OB_L *head ){
	for( OB_L *index = head->_next; index != NULL ;){

		free( index->_obj );
		DeleteElemente(head,index);
		index = head->_next; 
	}
	ListNULL( head );
	free( head );
}

//  Principal Fun��o relacionada com a execu��o principal de cada ciclo de procesamento
//	Ela executa todos os obj's validos de uma lista
//  Executando a fun��o _main respectiva
//  e renderisando o sprite
//  Ela recebe como parametro head que � a cabe�a da lista
//  Quando � um elemento desativado ( switched = false) ele � excluido da lsita automaticamente
//  obs:Essa fun��o est� na vers�o v1
//      essa � umas das pricipais fun��es da engine de prites e devese o devido respeito
void ExecuteList(OB_L *head){
	for( OB_L *index = head ; index->_next != NULL ; ){
		if(index->_next->_obj->switched){
			
			index->_next->_obj->_main( (void *) head,
									    (void *)index->_next->_obj 
									   );

			RenderSprite( &index->_next->_obj->s_, index->_next->_obj->pos );

			index = index->_next;

		}else{
			DeleteElemente( head, index->_next );
		}

	}
}


