// Авторы теста: ИСП РАН
// CWE: 457
// Название: Use of Uninitialized Variable
// Модельный вариант: read-global.json
//
// Чтение значения неинициализированной глобальной переменной для использования
// при вычислении выражения.
//
// Поточный вариант: call-int-int-values-false.c
// Недостижимый путь от источника до стока с проверкой возвращаемого значения
// функции c двумя параметрами, в функцию передаётся по значению локальная
// переменная и константа, проверка в вызывающей функции успешна и выполнение
// завершается

#include <stdlib.h>

int x;

int callee(int par1, int par2) {
  if (par1 < par2)
    return 1;

  return -1;
}

int func(void) {
  int result = 0;

  int local_var = 44;

  if (callee(local_var, 53) > 0) {
    exit(0);
  }

  result = x + 1;

  return result;
}
