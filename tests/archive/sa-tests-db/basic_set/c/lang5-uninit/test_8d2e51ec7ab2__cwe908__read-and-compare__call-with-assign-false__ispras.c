// Авторы теста: ИСП РАН
// CWE: 908
// Название: Use of Uninitialized Resource
// Модельный вариант: read-and-compare.json
//
// Чтение значения из неинициализированной памяти для использования в условном
// операторе.
//
// Поточный вариант: call-with-assign-false.c
// Достижимый путь от источника до стока с вызовом функции, которая присваивает
// значение через переданный указатель. Присвоенное значение сравнивается с
// константой, проверка успешна и выполнение завершается.

#include <stdlib.h>

void callee(int *pointer_param) { *pointer_param = 460; }

int *func(void) {

  int var = 0;

  int *x = malloc(sizeof(int));

  callee(&var);

  if (var > 275) {
    exit(0);
  }

  if (x != NULL && *x < 0) {
    *x = 0;
  }

  return x;
}
