#include <stdlib.h>

class SimpeStruct {
    int a, b;
public:
    int foo() {return a+b;} 
};

void use_after_free() {
    SimpeStruct* ptr = (SimpeStruct*)malloc (sizeof(SimpeStruct));
    int abrt;
    
    abrt = 1;
    free(ptr);
    

    if (abrt) {
        int d = ptr->foo(); // FLAW
    }

}

int main(int argc, char** argv) {
    use_after_free();
    return 0;
}

