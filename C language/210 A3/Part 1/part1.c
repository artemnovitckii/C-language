#include <stdio.h>
#include <stdlib.h>

    int f = 15;
    int hello;
    FILE *file;
    char line[45];
    file = fopen(argv[1],"r");
    while (fgets (line, 4, file) != NULL)
    {
        hello = ( line[0]*4096) + (line[1] * 256) + (line[3] * 16) +(li$
        printf("%d\n",hello);

    }


    /* printf("Data from the file:%s\n",numbers); */
    fclose(file);

    return 0;
}
