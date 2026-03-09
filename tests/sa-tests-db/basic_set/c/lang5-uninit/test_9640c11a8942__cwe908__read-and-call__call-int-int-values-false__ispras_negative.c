// Авторы теста: ИСП РАН
// CWE: 908
// Название: Use of Uninitialized Resource
// Модельный вариант: read-and-call.json
//
// Чтение значения из неинициализированной памяти для передачи во внешнюю
// функцию.
//
// Поточный вариант: call-int-int-values-false.c
// Недостижимый путь от источника до стока с проверкой возвращаемого значения
// функции c двумя параметрами, в функцию передаётся по значению локальная
// переменная и константа, проверка в вызывающей функции успешна и выполнение
// завершается

#include <stdlib.h>

void model_external_func(int external_param);

int callee(int par1, int par2) {
  if (par1 < par2)
    return 1;

  return -1;
}

int *func(void) {

  int local_var = 0;

  int *x = malloc(sizeof(int));

  if (callee(local_var, 89) > 0) {
    exit(0);
  }

  if (x != NULL) {
    model_external_func(*x);
  }

  return x;
}
