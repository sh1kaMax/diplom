// Авторы теста: ИСП РАН
// CWE: 476
// Название: NULL Pointer Dereference
// Модельный вариант: compare_null-wrapper-deref.json
//
// Указатель проверяется на возможное нулевое значение.
// Разыменование указателя осуществляется непосредственно (с помощью операции
// разыменования).
//
// Поточный вариант: call-with-no-assign-if-false.c
// Недостижимый путь от источника до стока с вызовом функции, которая
// присваивает значение через переданный указатель, если 2й параметр больше
// нуля. При вызове функции 2й параметр больше нуля, поэтому присвоение не
// происходит. Присвоенное значение сравнивается с константой, проверка
// неуспешна и выполнение не достигает стока.

#include <stdlib.h>

void wrapper(int *ptr) { *ptr = 1; }

void callee(int *pointer_param, int param1) {
  if (param1 < 0)
    *pointer_param = 390;
}

int func(int *param) {
  int template_flag = 0;

  int var = 0;

  if (param == NULL) {
    template_flag = 57;
  }

  callee(&var, 57);

  if (var < 505) {
    exit(0);
  }

  wrapper(param);

  return 0;
}
