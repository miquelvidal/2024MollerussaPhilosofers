#ifndef UTILITATS_H
#define UTILITATS_H

#include <ctype.h>
#include <stdlib.h>
#include <sys/time.h>

typedef unsigned long long t_timestamp;

//només funciona per positius
//retorna negatiu en cas d'error

int utilitats_string2int(const char*);

t_timestamp utilitats_obte_timestamp(void);

#endif