// Авторы теста: ИСП РАН
// CWE: 476
// Название: NULL Pointer Dereference
// Модельный вариант: compare_null-deref_op.json
//
// Указатель проверяется на возможное нулевое значение.
// Разыменование указателя осуществляется непосредственно (с помощью операции
// разыменования).
//
// Поточный вариант: if-check-param-interval.c
// Достижимый путь от источника до стока с проверкой составного условия,
// результат которого зависит от параметра функции

#include <stdlib.h>

int func(int *param, int param2) {
  int template_flag = 0;

  if (param == NULL) {
    template_flag = 64;
  }

  if (param2 > 16 && param2 < 55) {
    *param = 0; // FLAW
  }

  return 0;
}
