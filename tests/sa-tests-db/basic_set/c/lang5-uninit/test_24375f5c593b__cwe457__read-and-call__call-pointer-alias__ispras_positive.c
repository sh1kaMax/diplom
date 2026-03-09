// Авторы теста: ИСП РАН
// CWE: 457
// Название: Use of Uninitialized Variable
// Модельный вариант: read-and-call.json
//
// Чтение значения неинициализированной переменной для передачи во внешнюю
// функцию.
//
// Поточный вариант: call-pointer-alias.c
// Достижимый путь от источника до стока с проверкой возвращаемого значения
// функции, которое зависит от значения локальной для вызываемой функции
// переменной, адрес которой сначала сохраняется в локальную
// переменную-указатель, а затем с его помощью передаётся в вызываемую функцию
// через её аргумент; возвращаемое из вызываемой функции значение нулевое,
// поэтому проверка в вызывающей функции неуспешна и выполнение достигает стока.

#include <stdlib.h>

int model_external_func(int external_param);

int callee(int *pointer_param) {
  if (*pointer_param > 0)
    return 1;
  else
    return 0;
}

int func(void) {
  int result = 0;

  int local_var = 0, *local_pointer = &local_var;

  int x;

  if (callee(local_pointer)) {
    exit(0);
  }

  result = model_external_func(x); // FLAW

  return result;
}
