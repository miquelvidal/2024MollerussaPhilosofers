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

