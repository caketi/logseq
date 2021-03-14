#include <stdlib.h>
#include <stdio.h>
#include <types.h>
#include<unistd.h>

long get_mem_usage(){
    struct rusage myusage;

    getrusage(RUSAGE_SELF, &myusage);
    return myusage.ru_maxrss;
}