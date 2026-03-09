// Авторы теста: ИСП РАН
// CWE: 457
// Название: Use of Uninitialized Variable
// Модельный вариант: read-global.json
//
// Чтение значения неинициализированной глобальной переменной для использования
// при вычислении выражения.
//
// Поточный вариант: linear-filtered.c
// Прямолинейный участок кода от источника до стока с фильтрацией между ними.

#include <stdlib.h>

int x;

int func(void) {
  int result = 0;

  x = 46;

  result = x + 1;

  return result;
}
