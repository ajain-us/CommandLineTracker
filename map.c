#include <stdio.h>
#include <stdlib.h>
#include "map.h"

#define STARTING_SIZE 4
#define RESIZE_FACTOR 2
#define MAX_LOAD 1.7

int simple_string_hash(void *string);


void *create_map(int (*hash)(void*), int (*compare)(void*,void*)){
    Map *main;
    if(!(main = malloc(sizeof(Map)))){
        return NULL;
    }
    main->compare = compare;
    main->hash = hash;
    main->capacity = STARTING_SIZE;
    main->pairs = 0;
    main->arr = calloc(STARTING_SIZE, sizeof(Bucket*));
    if (!main->arr){
        return NULL;
    }
    return main;
}

int add_pair(void *key, void *value, void *map){
    Map *local_map = (Map *)map;
    if(MAX_LOAD < ((local_map->pairs + 1.0)/local_map->capacity)){
        local_map->capacity = local_map->capacity * RESIZE_FACTOR;
        void *new_arr = calloc(local_map->capacity, sizeof(Bucket*));
        for(int i = 0; i < local_map->capacity/2;i++){
            Bucket *curr = local_map->arr[i];
            while(curr){
                int new_location = local_map->hash(curr->key);
                
            }

        }

    }else{

    }
}





int main(){
    Map *test = create_map(NULL,NULL);
    printf("%d",test->capacity);
    char* simple_string = "bye bye world";
    printf("This is the result of a simple hash: %d", simple_string_hash(simple_string));

    return 0;
}

int simple_string_hash(void *string){
    int total = 0;
    while(*(char *)(string) != '\0'){
        total += *(char *)string;
        string++;
    }
    return total;
}