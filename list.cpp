/*
	Name:   list.cpp
	Author: Alex Terolti
	Date: 24/07/19 00:04
	Description:
		Comjunto de funções que modifica as listas da engine sprite ascii v1
		O arquivo base para esse aquivo é declaration_general.cpp
*/

OB_L *CreatList();
void AddElement(OB_L *head,OBJ obj);
BOOL DeleteElemente( OB_L *head, OB_L *_elemente);
void TransformElementeInHead(OB_L *elemente);
void ListNULL(OB_L *head);
void DeleteList( OB_L *head );			

void ExecuteList(OB_L *head);

//------
//	devolve a cabeça de uma nova lista OB_l setada com null

OB_L *CreatList(){	
	OB_L *head= (OB_L *) malloc(sizeof(OB_L));
	head->_head = NULL;
	head->_next = NULL;
	head->_obj = NULL;
	
	return head;
}

// 	adiciona um novo elemento apontando para o obj passado para a
//	 primeira possição da lista movendo o reto para frente
//	ela recebe head que é a cabeça da lista
//	e o obj é o objeto a ser adicisionado
//  quando adicionado a variavel switched é setada como true
//  ativando o objeto na lista
//  a função fica responsavel por alocar toda a memoria necesaria
void AddElement(OB_L *head,OBJ obj){		
	OBJ *_obj = (OBJ*) malloc( sizeof(OBJ)) ;

	_obj->endSprite = obj.endSprite;
	_obj->_main = obj._main;
	_obj->pos = obj.pos;
	_obj->startSprite = obj.startSprite;
//	_obj->switched = obj.switched;  // não copia o switched pois ele vai ser modificado( ativado)
	_obj->s_ = obj.s_;

	_obj->switched  = true; // ativa o obj

	OB_L *ob = (OB_L*) malloc(sizeof(OB_L));
	ob->_head = head;
	ob->_obj = _obj;
	
	ob->_next = head->_next;

	head->_next = ob;
	
}

// 	deleta todos os elementos de uma lista restando só a cabeça head nula
//  head é a cabeça da lista que é ou vai virar nula
//  essa função não exclue os obj's
void ListNULL(OB_L *head){
//exclue todos os elementos de uma lista deixando só o head nulo
	for( OB_L *index = head->_next; index != NULL ;){
		DeleteElemente(head,index);
		index = head->_next;
	}
	TransformElementeInHead( head );
}

//  tranforma um elemento qualquer na cabeça de uma lista setada em Nulo
void TransformElementeInHead(OB_L *elemente){
	elemente->_head = NULL;
	elemente->_obj = NULL;
}

//  ele busca o _elemente na lista de cabeça head e o deleta da lista
//  além de liberar a memoria do elemento
//  não meche no objeto apontado pelo elmento deletado
//  obs: se não for salvo o obj em questão ele será pedido
// 		pois não á forma de recuperalo
//  retorna  false se o elemento não for achado
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

//  exclue todos os elementos de uma lista de cabeça head
//	além de leberar a memoria da propria cabeça
//  obs: o ponteiro não pode ser mais utilizado
//		 a função exclue os objs
void DeleteList( OB_L *head ){
	for( OB_L *index = head->_next; index != NULL ;){

		free( index->_obj );
		DeleteElemente(head,index);
		index = head->_next; 
	}
	ListNULL( head );
	free( head );
}

//  Principal Função relacionada com a execução principal de cada ciclo de procesamento
//	Ela executa todos os obj's validos de uma lista
//  Executando a função _main respectiva
//  e renderisando o sprite
//  Ela recebe como parametro head que é a cabeça da lista
//  Quando á um elemento desativado ( switched = false) ele é excluido da lsita automaticamente
//  obs:Essa função está na versão v1
//      essa é umas das pricipais funções da engine de prites e devese o devido respeito
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


