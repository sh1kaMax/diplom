// Авторы теста: ИСП РАН
// CWE: 457
// Название: Use of Uninitialized Variable
// Модельный вариант: sometimes-init.json
//
// Чтение значения переменной, инициализированной не на всех путях.
//
// Поточный вариант: call-global-false.c
// Недостижимый путь от источника до стока с проверкой возвращаемого значения
// функции, которое зависит от значения глобальной переменной, значение которой
// устанавливается перед вызовом; возвращаемое из вызываемой функции значение
// равно единице, поэтому проверка в вызывающей функции успешна и выполнение
// завершается, не достигнув стока.

#include <stdlib.h>

int global_var = 0;

int callee(void) {
  if (global_var > 0)
    return 1;
  else
    return 0;
}

int func(int cond_param) {
  int result = 0;

  global_var = 1;

  int x;
  if (cond_param > 0) {
    x = cond_param;
  }

  if (callee()) {
    exit(0);
  }

  result = x + 1;

  return result;
}
