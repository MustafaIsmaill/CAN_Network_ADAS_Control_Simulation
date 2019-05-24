#ifndef __STD_LIB_H__
#define __STD_LIB_H__

#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>

size_t str_len(const char * string);
char *strrev(char * str);
char *itoa(int8_t n, char * s, int8_t b);

#endif /*__STD_LIB_H__*/
