// Авторы теста: ИСП РАН
// CWE: 732
// Название: Incorrect Permission Assignment for Critical Resource
// Модельный вариант: basic.json
//
// Создание файла с помощью системного вызова open.
// Права для создаваемого файла позволяют модифицировать его любому
// пользователю.
//
// Поточный вариант: if-check-inverted.c
// Достижимый путь от источника до стока с проверкой условия наличия уязвимости
// между ними, выход в случае ложности проверки.

#include <fcntl.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

int file;

void func(void) {
  int mode = 0;

  mode = 0777;

  if (!(mode & S_IRWXO)) {
    exit(0);
  }

  file = open("dummy.txt", O_WRONLY | O_CREAT, mode); // FLAW

  close(file);
}
