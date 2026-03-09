// Авторы теста: ИСП РАН
// CWE: 908
// Название: Use of Uninitialized Resource
// Модельный вариант: read-and-compare.json
//
// Чтение значения из неинициализированной памяти для использования в условном
// операторе.
//
// Поточный вариант: if-check-inverted-filtered.c
// Достижимый путь от источника до стока с проверкой условия наличия уязвимости
// между ними, фильтрация в случае ложности проверки.

#include <stdlib.h>

int *func(void) {

  int *x = malloc(sizeof(int));

  if (!(1)) {
    if (x != NULL) {
      *x = 14;
    }
  }

  if (x != NULL && *x < 0) { // FLAW
    *x = 0;
  }

  return x;
}
