// Авторы теста: ИСП РАН
// CWE: 457
// Название: Use of Uninitialized Variable
// Модельный вариант: read-and-call.json
//
// Чтение значения неинициализированной переменной для передачи во внешнюю
// функцию.
//
// Поточный вариант: error-path-check.c
// Достижимый путь от источника до стока с проверкой условия наличия уязвимости
// между ними, переход по метке в случае истинности проверки.

#include <stdlib.h>

int model_external_func(int external_param);

int func(void) {
  int result = 0;

  int x;

  if (1)
    goto error_label;

  x = -58;

  exit(0);

error_label:
  result = model_external_func(x); // FLAW

  return result;
}
