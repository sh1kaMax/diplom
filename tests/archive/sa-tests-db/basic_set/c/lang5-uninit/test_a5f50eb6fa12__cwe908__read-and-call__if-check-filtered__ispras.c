// Авторы теста: ИСП РАН
// CWE: 908
// Название: Use of Uninitialized Resource
// Модельный вариант: read-and-call.json
//
// Чтение значения из неинициализированной памяти для передачи во внешнюю
// функцию.
//
// Поточный вариант: if-check-filtered.c
// Достижимый путь от источника до стока с проверкой условия наличия уязвимости
// между ними, фильтрация в случае истинности проверки.

#include <stdlib.h>

void model_external_func(int external_param);

int *func(void) {

  int *x = malloc(sizeof(int));

  if (1) {
    if (x != NULL) {
      *x = 10;
    }
  }

  if (x != NULL) {
    model_external_func(*x);
  }

  return x;
}
