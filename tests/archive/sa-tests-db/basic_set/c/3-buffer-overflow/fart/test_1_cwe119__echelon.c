#include "test1_cwe119_1__echelon.h"

void buffer_strncpy(char * data);

void buffer_alloca()
{
    char * data;
    void (*funcPtr) (char *) = buffer_strncpy;
    char * dataBuffer = (char *)alloca(Size*sizeof(char));
    memset(dataBuffer, '1', Size-1);
    dataBuffer[Size-1] = '\0';
    data = dataBuffer + Offset;
	printf("dataBuffer:      %p\n", (void*)dataBuffer);
	printf("data:      		 %p\n", (void*)data);
    funcPtr(data);
}

int main(int argc, char * argv[])
{
    printf("Start  ---");
    buffer_alloca();
    printf("Finish ---");
    return 0;
}

