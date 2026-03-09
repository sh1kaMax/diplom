// Авторы теста: ИСП РАН
// CWE: 824
// Название: Use of Uninitialized Pointer
// Модельный вариант: read-and-return.json
//
// Возврат значения неинициализированного указателя из функции.
//
// Поточный вариант: if-check-inverted-filtered.c
// Достижимый путь от источника до стока с проверкой условия наличия уязвимости
// между ними, фильтрация в случае ложности проверки.

#include <stdlib.h>

int *func(void) {
  int *result = NULL;

  int *x;

  if (!(1)) {
    x = malloc(sizeof(int));
  }

  result = x; // FLAW

  return result;
}
