// Авторы теста: ИСП РАН
// CWE: 457
// Название: Use of Uninitialized Variable
// Модельный вариант: read-and-call.json
//
// Чтение значения неинициализированной переменной для передачи во внешнюю
// функцию.
//
// Поточный вариант: ternary.c
// Достижимый путь от источника до стока с проверкой условия наличия уязвимости
// между ними с помощью тернарного оператора, выполнение достигает стока в
// случае истинности проверки.

#include <stdlib.h>

int model_external_func(int external_param);

int func(void) {
  int result = 0;

  int var;

  int x;

  var = (1 ? 1 : 0);

  if (var) {
    result = model_external_func(x); // FLAW
  }

  return result;
}
