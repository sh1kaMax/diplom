#include <stdio.h>
#include <string.h>

int main(int argc, char* argv[]) {
  if (argc != 2 || argv[1][0] != '/') {
    printf("Provide path argument\n");
    return 1;
  }

  char *pFolderName = strchr(argv[1] + 1, '/') + 1; // FLAW
  char foldername[20];
  strncpy(foldername, pFolderName, 20);
  printf("Folder %s\n", foldername);
  return 0;
}
