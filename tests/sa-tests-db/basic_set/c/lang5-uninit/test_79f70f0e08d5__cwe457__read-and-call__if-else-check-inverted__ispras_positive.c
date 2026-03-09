// Авторы теста: ИСП РАН
// CWE: 457
// Название: Use of Uninitialized Variable
// Модельный вариант: read-and-call.json
//
// Чтение значения неинициализированной переменной для передачи во внешнюю
// функцию.
//
// Поточный вариант: if-else-check-inverted.c
// Достижимый путь от источника до стока в блоке else условного оператора,
// условием которого является отрицание условия наличия уязвимости.

#include <stdlib.h>

int model_external_func(int external_param);

int func(void) {
  int result = 0;

  int x;

  if (!(1)) {
    exit(0);
  } else {
    result = model_external_func(x); // FLAW
  }

  return result;
}
