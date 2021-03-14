// #define USE_LINKED_LIST
// #define WASTE_MEMORY

#ifdef USE_LINKED_LIST
    #define add_number(v) add_number_ll(v)
    #define delete_number(v) delete_number_ll(v)
#else
    #ifdef WASTE_MEMORY
        #define add_number(v) add_number_array_wasteful(v)
    #else
        #define add_number(v) add_number_array_reuse(v)
    #endif
    #define delete_number(v) delete_number_array(v)
#endif

#include <stdio.h>
#include <limits.h>
#include <stdlib.h>
#include <unistd.h>
#include "resource.h"

#include "linkedlist.h"
#define AVALABLE INT_MIN
#define NOT_FOUND (-1)
#define INITIAL_ARRAY_SIZE 100
#define ARRAY_INCREMENT 1000
#define MAX_VALUE 500000
#define NUM_ITERATIONS 2000
#define INSERT_NUM 100
#define DELETE_NUM 50
#define TRAVERSALS 1

node *head = NULL;

int *myvalues = NULL;
int listlength = INITIAL_ARRAY_SIZE;

void add_number_ll(int value){
    node *newnode = create_new_node(value);
    insert_at_head(&head, newnode);
}
int find_value(int value){
    for (int i = 0; i < listlength; i++){
        if (myvalues[i] == value){
            return i;
        }
    }
    return NOT_FOUND;
}

void add_number_array_wasteful(int value){
    static int last_loc = -1;

    last_loc++;

    if (last_loc >= listlength){
        int newlength = listlength + ARRAY_INCREMENT;
        myvalues = realloc(myvalues, newlength * sizeof(int));
        for (int i = listlength; i < newlength; i++){
            myvalues[i] = AVALABLE;
        }
        listlength = newlength;
    }
    myvalues[last_loc] = value;
    return;
}

void add_number_array_reuse(int value){
    int loc = find_value(AVALABLE);

    if (loc == NOT_FOUND){
        int newlength = listlength * ARRAY_INCREMENT;
        myvalues = realloc(myvalues, newlength * sizeof(int));
        for (int i = listlength; i < newlength; i++){
            myvalues[i] = AVALABLE;
        }
        listlength = newlength;
    }else{
        myvalues[loc] = value;
    }
    return;
}

void delete_number_ll(int value){ remove_value(&head, value); }

void delete_number_array(int value){
    int loc = find_value(value);
    if (loc != NOT_FOUND){
        myvalues[loc] = AVALABLE;
    }
}

long double tv_to_seconds(struct timeval *tv){
    long double result = tv->tv_sec;
    result += ((long double)tv->tv_usec) / 1000000.0;
    return result;
}

int main(){
#ifndef USE_LINKED_LIST
    myvalues = malloc(sizeof(int) * listlength);
    for (int i = 0; i < listlength; i++){
        myvalues[i] = AVALABLE;
    }
#endif

    struct rusage myusage;
    getrusage(RUSAGE_SELF, &myusage);
    long baseline_memory = myusage.ru_maxrss;
    long double start_time =  tv_to_seconds(&myusage.ru_utime);

    srand(0);

    long double last_time = start_time, insert_time = 0.0, delete_time = 0.0;

    for(__int32 i = 0; i<NUM_ITERATIONS; i++){
        for(int i = 0; i<INSERT_NUM; i++){
            add_number(rand() % MAX_VALUE);
        }
        getrusage(RUSAGE_SELF, &myusage);
        long double current = tv_to_secondsa(&myusage.ru_utime);
        insert_time += (current - last_time);
        last_time = current;

        for (int i = 0; i < DELETE_NUM; i++){
            delete_number(rand() % MAX_VALUE);
        }

        getrusage(RUSAGE_SELF, &myusage);
        current = tv_to_seconds(&myusage.ru_utime);
        delete_time = (current - last_time);
        last_time = current;
    }

    long double add_delete_time = last_time;

    for (int i = 0; i < TRAVERSALS; i++){
        delete_number(MAX_VALUE + 1);
    }

    getrusage(RUSAGE_SELF, &myusage);
    long double traverse_time = tv_to_seconds(&myusage.ru_utime);

    printf("Memory:         \t%f\t + %ld\n", baseline_memory,myusage.ru_maxrss - baseline_memory);
    printf("Insert Time:     \t%f\n", insert_time);
    printf("Delete Time:    \t%f\n", delete_time);
    printf("Add/Del Time:    \t%f\n", add_delete_time - start_time);
    printf("Traversal Time: \t%f\n", traverse_time - add_delete_time);
    printf("TotalUserTime: \t%f\n", tv_to_seconds(&myusage.ru_utime));
    printf("SysTime:    \t%f\n", tv_to_seconds(&myusage.ru_stime));

    return 0;
}