// Авторы теста: ИСП РАН
// CWE: 732
// Название: Incorrect Permission Assignment for Critical Resource
// Модельный вариант: basic.json
//
// Создание файла с помощью системного вызова open.
// Права для создаваемого файла позволяют модифицировать его любому
// пользователю.
//
// Поточный вариант: linear-inverted.c
// Прямолинейный участок кода с источником после стока.

#include <fcntl.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

int file;

void func(void) {
  int mode = 0;

  file = open("dummy.txt", O_WRONLY | O_CREAT, mode);

  mode = 0777;

  close(file);
}
