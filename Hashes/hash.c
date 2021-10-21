#include "hash.h"

int main(void){

	hash_t *has_t;
	hash_node_t *list;

	list = malloc(sizeof(hash_node_t));
	has_t = malloc(sizeof(hash_t));
	if(has_t == NULL || list == NULL){
		return(1);
	}

	has_t->size = 100;
	has_t->array =  list->next;
	printf("%i\n",has_t->array);
	printf("%i\n", has_t->size);
	
	return 0;
}
