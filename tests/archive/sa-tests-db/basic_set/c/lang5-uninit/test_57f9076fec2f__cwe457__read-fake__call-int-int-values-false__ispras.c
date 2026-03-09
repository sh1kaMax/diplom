// Авторы теста: ИСП РАН
// CWE: 457
// Название: Use of Uninitialized Variable
// Модельный вариант: read-fake.json
//
// Отсутствие чтения значения неинициализированной переменной, несмотря не ее
// использование при вычислении выражения.
//
// Поточный вариант: call-int-int-values-false.c
// Недостижимый путь от источника до стока с проверкой возвращаемого значения
// функции c двумя параметрами, в функцию передаётся по значению локальная
// переменная и константа, проверка в вызывающей функции успешна и выполнение
// завершается

#include <stdlib.h>

int callee(int par1, int par2) {
  if (par1 < par2)
    return 1;

  return -1;
}

int func(void) {
  int result = 0;

  int local_var = 11;

  int x;

  if (callee(local_var, 63) > 0) {
    exit(0);
  }

  result = sizeof x + 1;

  return result;
}
