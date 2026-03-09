// Авторы теста: ИСП РАН
// CWE: 457
// Название: Use of Uninitialized Variable
// Модельный вариант: read-and-call.json
//
// Чтение значения неинициализированной переменной для передачи во внешнюю
// функцию.
//
// Поточный вариант: if-check-param.c
// Достижимый путь от источника до стока с проверкой простого условия,
// зависящего от параметра функции.

#include <stdlib.h>

int model_external_func(int external_param);

int func(int param) {
  int result = 0;

  int x;

  if (param > 9) {
    result = model_external_func(x); // FLAW
  }

  return result;
}
