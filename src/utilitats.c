#include "utilitats.h"


int utilitats_string2int(const char* string){
    int iterador = 0;

    if (string==NULL) return -1;
    while(string[iterador] != '\0')
    {
        if (isdigit(string[iterador]) == 0)
            return (-1);
        iterador++;
    }
    return (atoi(string));    
}

t_timestamp utilitats_obte_timestamp(void)
{
    struct timeval tv;
    t_timestamp time;

    gettimeofday(&tv, NULL);
//    time = tv.tv_sec*1000LL + tv.tv_usec / 1000LL;
    time = tv.tv_sec*1000LL + tv.tv_usec;
    return (time);
}
