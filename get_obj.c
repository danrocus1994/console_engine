#include <stdio.h>
#include "englibs.h"
#include <stdlib.h>

char ***_obj(int n)
{
	char ***ob = malloc(n * sizeof(char **));
	if (ob == NULL)
		return (NULL);
	return (ob);
}
