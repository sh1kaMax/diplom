// Авторы теста: ИСП РАН
// CWE: 457
// Название: Use of Uninitialized Variable
// Модельный вариант: read-and-call.json
//
// Чтение значения неинициализированной переменной для передачи во внешнюю
// функцию.
//
// Поточный вариант: call-int-int-values-false.c
// Недостижимый путь от источника до стока с проверкой возвращаемого значения
// функции c двумя параметрами, в функцию передаётся по значению локальная
// переменная и константа, проверка в вызывающей функции успешна и выполнение
// завершается

#include <stdlib.h>

int model_external_func(int external_param);

int callee(int par1, int par2) {
  if (par1 < par2)
    return 1;

  return -1;
}

int func(void) {
  int result = 0;

  int local_var = 35;

  int x;

  if (callee(local_var, 52) > 0) {
    exit(0);
  }

  result = model_external_func(x);

  return result;
}
