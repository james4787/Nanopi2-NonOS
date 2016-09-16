/*
 * libc/string/strlen.c
 */

#include "../include/s5p4418.h"

/*
 * Calculate the length of a string
 */
uint32_t strlen(const char * s)
{
	const char * sc;

	for (sc = s; *sc != '\0'; ++sc);
	return sc - s;
}
