#include <stdio.h>
#include <stdint.h>

#define MAX_NAME 60

typedef struct {
    uint8_t age;
    uint16_t height_in_mm;
    char name[MAX_NAME];
    uint16_t chess_score;
    uint8_t weight;
} person_t;

int main(){
    person_t p;
    
    printf("%lu\n", sizeof(p));
}