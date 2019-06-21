#include <stdio.h>
#include <stdlib.h>
#include <dlfcn.h>
#include <string.h>


typedef struct cc {
	float d;
	float m;
} cc;
typedef struct plug
{
	char nameplug[15];
	char namebib[15];
	char namefunc[15];
	struct plug *next;
} plug;
void menu ();
