// Авторы теста: ИСП РАН
// CWE: 476
// Название: NULL Pointer Dereference
// Модельный вариант: compare_null-wrapper-deref.json
//
// Указатель проверяется на возможное нулевое значение.
// Разыменование указателя осуществляется непосредственно (с помощью операции
// разыменования).
//
// Поточный вариант: if-check-param.c
// Достижимый путь от источника до стока с проверкой простого условия,
// зависящего от параметра функции

#include <stdlib.h>

void wrapper(int *ptr) { *ptr = 1; }

int func(int *param, int param2) {
  int template_flag = 0;

  if (param == NULL) {
    template_flag = 6;
  }

  if (param2 > 20) {
    wrapper(param); // FLAW
  }

  return 0;
}
