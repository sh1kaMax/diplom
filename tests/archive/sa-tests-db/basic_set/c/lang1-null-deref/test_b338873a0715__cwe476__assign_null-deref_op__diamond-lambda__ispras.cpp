// Авторы теста: ИСП РАН
// CWE: 476
// Название: NULL Pointer Dereference
// Модельный вариант: assign_null-deref_op.json
//
// Нулевое значение присваивается явно.
// Разыменование указателя осуществляется непосредственно (с помощью операции
// разыменования).
//
// Поточный вариант: diamond-lambda.cpp
// Путь от источника до стока проходит через 2 условных выражения, зависящих от
// значения локальной переменной. Значение локальной переменной меняется
// лямбдой.

#include <stdlib.h>

void func(void) {
  int *pointer, other, dummy;
  pointer = &dummy;

  int local_var1 = 6;

  auto init = [&]() { local_var1 = 152; };

  if (local_var1 < 152) {
    pointer = NULL;
  }

  init();

  if (local_var1 < 152) {
    *pointer = 0;
  }
}
