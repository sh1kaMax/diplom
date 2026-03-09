#include <stdlib.h>

struct Df {
    int* p;
};

void foo(int *x) {
    free(x);
}

void bar(int *y) {
    free(y); // FLAW
}

void double_free() {
    Df a;
	a.p = (int*)malloc(sizeof(int));
    foo(a.p);  
    bar(a.p);
}

int main(int argc, char** argv) {
    double_free();
    return 0;
}
