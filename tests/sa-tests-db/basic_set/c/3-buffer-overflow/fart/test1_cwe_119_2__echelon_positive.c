#include "test1_cwe119_1__echelon.h"

void buffer_strncpy(char * data)
{
    {
        char source[Size];
        memset(source, '2', Size-1);
        source[Size-1] = '\0';

        strncpy(data, source, Size-1); // FLAW
        data[Size-1] = '\0';
        printf("%s\n", data);
    }
}

