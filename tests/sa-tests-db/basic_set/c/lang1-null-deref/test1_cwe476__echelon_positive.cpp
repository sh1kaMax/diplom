#include <stdexcept>

int getData(char* ptr)
{
  if(ptr != nullptr & *ptr == 'a') // FLAW
    return 1;
  return 0;
}

int main(int argc, char* argv[]) {

  int data = getData(0);
  printf("data %d\n", data);

  return 0;
}
