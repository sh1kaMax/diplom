// Авторы теста: ИСП РАН
// CWE: 908
// Название: Use of Uninitialized Resource
// Модельный вариант: read-and-call.json
//
// Чтение значения из неинициализированной памяти для передачи во внешнюю
// функцию.
//
// Поточный вариант: call-with-assign.c
// Достижимый путь от источника до стока с вызовом функции, которая присваивает
// значение через переданный указатель. Присвоенное значение сравнивается с
// константой, проверка неуспешна и выполнение достигает стока.

#include <stdlib.h>

void model_external_func(int external_param);

void callee(int *pointer_param) { *pointer_param = 65; }

int *func(void) {

  int var = 0;

  int *x = malloc(sizeof(int));

  callee(&var);

  if (var > 526) {
    exit(0);
  }

  if (x != NULL) {
    model_external_func(*x); // FLAW
  }

  return x;
}
