// Авторы теста: ИСП РАН
// CWE: 457
// Название: Use of Uninitialized Variable
// Модельный вариант: read-fake.json
//
// Отсутствие чтения значения неинициализированной переменной, несмотря не ее
// использование при вычислении выражения.
//
// Поточный вариант: if-check-param-interval.c
// Достижимый путь от источника до стока с проверкой составного условия,
// результат которого зависит от параметра функции.

#include <stdlib.h>

int func(int param) {
  int result = 0;

  int x;

  if (param > 48 && param < 65) {
    result = sizeof x + 1;
  }

  return result;
}
