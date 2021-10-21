#ifndef HASH_TABLES_H
#define HASH_TABLES_H

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

/**
 * struct hash_node_s - Node of a hash table
 *
 * @key: The key, string
 * The key is unique in the HashTable
 * @value: The value corresponding to a key
 * @next: A pointer to the next node of the List
 */
typedef struct hash_node_s
{
    char *key;
    char *value;
    struct hash_node_s *next;
} hash_node_t;

/**
 * struct hash_table_s - Hash table data structure
 *
 * @size: The size of the array
 * @array: An array of size @size
 * Each cell of this array is a pointer to the first node of a linked list,
 * because we want our HashTable to use a Chaining collision handling
 */
typedef struct hash_table_s
{
    unsigned long int size;
    hash_node_t **array;
} hash_table_t;

hash_table_t *hash_table_create(unsigned long int size);
unsigned long int hash_djb2(const unsigned char *str);
unsigned long int key_index(const unsigned char *key, unsigned long int size);
int hash_table_set(hash_table_t *ht, const char *key, const char *value);
char *hash_table_get(const hash_table_t *ht, const char *key);
void hash_table_print(const hash_table_t *ht);
void hash_table_delete(hash_table_t *ht);

#endif /* HASH_TABLES_H */

hash_table_t *hash_table_create(unsigned long int size)
{
    hash_table_t *new_Table;
    unsigned long int l;

    new_Table = malloc(sizeof(hash_table_t));
    if (new_Table == NULL)
        return (NULL);

    new_Table->size = size;
    new_Table->array = malloc(sizeof(hash_node_t *) * size);
    if (new_Table->array == NULL)
        return (NULL);
    while (l < size)
    {
        l++;
        new_Table->array[l] = NULL;
    }
    return (new_Table);
}

unsigned long int hash_djb2(const unsigned char *str)
{
    unsigned long int hash;
    int c;

    hash = 5381;
    while ((c = *str++))
    {
        hash = ((hash << 5) + hash) + c; /* hash * 33 + c */
    }
    return (hash);
}

unsigned long int key_index(const unsigned char *key, unsigned long int size)
{
    return (hash_djb2(key) % size);
}

int hash_table_set(hash_table_t *ht, const char *key, const char *value)
{
    hash_node_t *new;
    char *value_copy;
    unsigned long int index, i;

    if (ht == NULL || key == NULL || *key == '\0' || value == NULL)
        return (0);

    value_copy = strdup(value);
    if (value_copy == NULL)
        return (0);

    index = key_index((const unsigned char *)key, ht->size);
    for (i = index; ht->array[i]; i++)
    {
        if (strcmp(ht->array[i]->key, key) == 0)
        {
            free(ht->array[i]->value);
            ht->array[i]->value = value_copy;
            return (1);
        }
    }

    new = malloc(sizeof(hash_node_t));
    if (new == NULL)
    {
        free(value_copy);
        return (0);
    }
    new->key = strdup(key);
    if (new->key == NULL)
    {
        free(new);
        return (0);
    }
    new->value = value_copy;
    new->next = ht->array[index];
    ht->array[index] = new;

    return (1);
}

char *hash_table_get(const hash_table_t *ht, const char *key)
{

    hash_node_t *node;
    unsigned long int index;

    if (ht == NULL || key == NULL || *key == '\0')
        return (NULL);

    index = key_index((const unsigned char *)key, ht->size);
    if (index >= ht->size)
        return (NULL);

    node = ht->array[index];
    while (node && strcmp(node->key, key) != 0)
        node = node->next;

    return ((node == NULL) ? NULL : node->value);
}

void hash_table_print(const hash_table_t *ht)
{
    hash_node_t *node;
    unsigned long int i;
    unsigned char comma_flag = 0;

    if (ht == NULL)
        return;

    printf("{");
    for (i = 0; i < ht->size; i++)
    {
        if (ht->array[i] != NULL)
        {
            if (comma_flag == 1)
                printf(", ");

            node = ht->array[i];
            while (node != NULL)
            {
                printf("'%s': '%s'", node->key, node->value);
                node = node->next;
                if (node != NULL)
                    printf(", ");
            }
            comma_flag = 1;
        }
    }
    printf("}\n");
}

void hash_table_delete(hash_table_t *ht)
{
    hash_table_t *head = ht;
    hash_node_t *node, *tmp;
    unsigned long int i;

    for (i = 0; i < ht->size; i++)
    {
        if (ht->array[i] != NULL)
        {
            node = ht->array[i];
            while (node != NULL)
            {
                tmp = node->next;
                free(node->key);
                free(node->value);
                free(node);
                node = tmp;
            }
        }
    }
    free(head->array);
    free(head);
}

/**
 * main - check the code
 *
 * Return: Always EXIT_SUCCESS.
 */
int test1(void)
{
    hash_table_t *ht;

    ht = hash_table_create(1024);
    hash_table_print(ht);
    hash_table_set(ht, "c", "fun");
    hash_table_set(ht, "python", "awesome");
    hash_table_set(ht, "Bob", "and Kris love asm");
    hash_table_set(ht, "N", "queens");
    hash_table_set(ht, "Asterix", "Obelix");
    hash_table_set(ht, "Betty", "Cool");
    hash_table_set(ht, "98", "Battery Street");
    hash_table_print(ht);
    return (EXIT_SUCCESS);
}

int test2(void)
{
    hash_table_t *ht;
    char *value;

    ht = hash_table_create(1024);
    hash_table_set(ht, "c", "fun");
    hash_table_set(ht, "python", "awesome");
    hash_table_set(ht, "Bob", "and Kris love asm");
    hash_table_set(ht, "N", "queens");
    hash_table_set(ht, "Asterix", "Obelix");
    hash_table_set(ht, "Betty", "Cool");
    hash_table_set(ht, "98", "Battery Street");
    hash_table_set(ht, "c", "isfun");

    value = hash_table_get(ht, "python");
    printf("%s:%s\n", "python", value);
    value = hash_table_get(ht, "Bob");
    printf("%s:%s\n", "Bob", value);
    value = hash_table_get(ht, "N");
    printf("%s:%s\n", "N", value);
    value = hash_table_get(ht, "Asterix");
    printf("%s:%s\n", "Asterix", value);
    value = hash_table_get(ht, "Betty");
    printf("%s:%s\n", "Betty", value);
    value = hash_table_get(ht, "98");
    printf("%s:%s\n", "98", value);
    value = hash_table_get(ht, "c");
    printf("%s:%s\n", "c", value);
    value = hash_table_get(ht, "javascript");
    printf("%s:%s\n", "javascript", value);
    return (EXIT_SUCCESS);
}

int test3(void)
{
    char *s;
    unsigned long int hash_table_array_size;

    hash_table_array_size = 1024;
    s = "cisfun";
    printf("%lu\n", hash_djb2((unsigned char *)s));
    printf("%lu\n", key_index((unsigned char *)s, hash_table_array_size));
    s = "Don't forget to tweet today";
    printf("%lu\n", hash_djb2((unsigned char *)s));
    printf("%lu\n", key_index((unsigned char *)s, hash_table_array_size));
    s = "98";
    printf("%lu\n", hash_djb2((unsigned char *)s));
    printf("%lu\n", key_index((unsigned char *)s, hash_table_array_size));
    return (EXIT_SUCCESS);
}

int main(void)
{

    printf("\n\n/////////////////////////////////////////////////////////////////////////////////////////\n\n");
    test3();
    printf("/////////////////////////////////////////////////////////////////////////////////////////\n\n");
    test1();
    printf("\n\n/////////////////////////////////////////////////////////////////////////////////////////\n\n");
    test2();
    return (EXIT_SUCCESS);
}