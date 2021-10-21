#ifndef HASH_H
#define HASH_H

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

/* hash_node_s */

typedef struct hash_node_s{

	char *key;
	char *value;
	struct hash_node_s *next;
} hash_node_t;

typedef struct hash_table {
	unsigned long int size;
	hash_node_t **array;
} hash_t;

#endif /* HASH_H */
