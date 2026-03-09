// Авторы теста: ИСП РАН
// CWE: 457
// Название: Use of Uninitialized Variable
// Модельный вариант: read-global.json
//
// Чтение значения неинициализированной глобальной переменной для использования
// при вычислении выражения.
//
// Поточный вариант: linear.c
// Прямолинейный участок кода от источника до стока.

#include <stdlib.h>

int x;

int func(void) {
  int result = 0;

  result = x + 1;

  return result;
}
