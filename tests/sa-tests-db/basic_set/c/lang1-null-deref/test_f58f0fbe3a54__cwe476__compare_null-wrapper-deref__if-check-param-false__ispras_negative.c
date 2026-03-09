// Авторы теста: ИСП РАН
// CWE: 476
// Название: NULL Pointer Dereference
// Модельный вариант: compare_null-wrapper-deref.json
//
// Указатель проверяется на возможное нулевое значение.
// Разыменование указателя осуществляется непосредственно (с помощью операции
// разыменования).
//
// Поточный вариант: if-check-param-false.c
// Недостижимый путь от источника до стока с проверкой всегда ложного составного
// условия, зависящего от параметра функции

#include <stdlib.h>

void wrapper(int *ptr) { *ptr = 1; }

int func(int *param, int param2) {
  int template_flag = 0;

  if (param == NULL) {
    template_flag = 60;
  }

  if (param2 > 47 && param2 < 48) {
    wrapper(param);
  }

  return 0;
}
