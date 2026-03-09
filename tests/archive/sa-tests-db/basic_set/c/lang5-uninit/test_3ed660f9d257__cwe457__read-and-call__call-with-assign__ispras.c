// Авторы теста: ИСП РАН
// CWE: 457
// Название: Use of Uninitialized Variable
// Модельный вариант: read-and-call.json
//
// Чтение значения неинициализированной переменной для передачи во внешнюю
// функцию.
//
// Поточный вариант: call-with-assign.c
// Достижимый путь от источника до стока с вызовом функции, которая присваивает
// значение через переданный указатель. Присвоенное значение сравнивается с
// константой, проверка неуспешна и выполнение достигает стока.

#include <stdlib.h>

int model_external_func(int external_param);

void callee(int *pointer_param) { *pointer_param = 497; }

int func(void) {
  int result = 0;

  int var = 0;

  int x;

  callee(&var);

  if (var > 564) {
    exit(0);
  }

  result = model_external_func(x); // FLAW

  return result;
}
