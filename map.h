#if !defined(MAP_H)

#define MAP_H

typedef struct bucket{
    void *key;
    void *value;
    struct bucket *next;
} Bucket;

typedef struct map{
    void *map;
    int (*hash)(void*);
    int (*compare)(void*,void*);
    int pairs, capacity;
} Map;

void *create_map(int (*hash)(void*), int (*compare)(void*,void*));

int add_pair(void *key, void *value, void *map);

int remove_pair(void *key, void *map);

void *get_value(void *key, void *map);

int delete_map(void *map);


#endif