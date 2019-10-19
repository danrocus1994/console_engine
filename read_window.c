#include <stdio.h>
#include <stdlib.h>
#include "englibs.h"
#include <time.h>
#include <limits.h>
#include <stdbool.h>
#include <pthread.h>

int *read_window(void)
{
        FILE *wfile = popen("tput cols", "r");
        FILE *hfile = popen("tput lines", "r");
        char wid[4];
        char hei[4];
        char type[100];
        int width, height;
        fgets(wid, 4, wfile);
        fgets(hei, 4, hfile);
        pclose(wfile);
        pclose(hfile);
        width = _atoi(wid);
        height = _atoi(hei);
        int *dim = malloc(sizeof(int) * 2);
        if (dim == NULL)
          {
            printf("\e[32mError allocating space for dimensions\e[30m");
            return(NULL);
          }
        *dim = width - 1;
        *(dim + 1) = height -4;
        return (dim);
}
