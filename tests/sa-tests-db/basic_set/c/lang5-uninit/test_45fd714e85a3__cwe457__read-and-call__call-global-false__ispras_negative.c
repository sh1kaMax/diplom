// Авторы теста: ИСП РАН
// CWE: 457
// Название: Use of Uninitialized Variable
// Модельный вариант: read-and-call.json
//
// Чтение значения неинициализированной переменной для передачи во внешнюю
// функцию.
//
// Поточный вариант: call-global-false.c
// Недостижимый путь от источника до стока с проверкой возвращаемого значения
// функции, которое зависит от значения глобальной переменной, значение которой
// устанавливается перед вызовом; возвращаемое из вызываемой функции значение
// равно единице, поэтому проверка в вызывающей функции успешна и выполнение
// завершается, не достигнув стока.

#include <stdlib.h>

int model_external_func(int external_param);

int global_var = 0;

int callee(void) {
  if (global_var > 0)
    return 1;
  else
    return 0;
}

int func(void) {
  int result = 0;

  global_var = 1;

  int x;

  if (callee()) {
    exit(0);
  }

  result = model_external_func(x);

  return result;
}
