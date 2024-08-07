#if !defined(MAP_H)

#define MAP_H

void *create_map(int (*hash)(void*), int (*compare)(void*,void*));

int add_pair(void *key, void *value);

int remove_pair(void *key);

void *get_value(void *key);

int delete_map();


#endif