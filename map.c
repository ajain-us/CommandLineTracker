#include <stdio.h>
#include <stdlib.h>
#include "map.h"

#define STARTING_SIZE 4
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
    main->map = calloc(sizeof(Bucket*),STARTING_SIZE);
    if (!main->map){
        return NULL;
    }
    return main;
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