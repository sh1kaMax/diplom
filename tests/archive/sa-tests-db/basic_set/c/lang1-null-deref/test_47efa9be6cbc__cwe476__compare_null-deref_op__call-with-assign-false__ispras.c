// Авторы теста: ИСП РАН
// CWE: 476
// Название: NULL Pointer Dereference
// Модельный вариант: compare_null-deref_op.json
//
// Указатель проверяется на возможное нулевое значение.
// Разыменование указателя осуществляется непосредственно (с помощью операции
// разыменования).
//
// Поточный вариант: call-with-assign-false.c
// Недостижимый путь от источника до стока с вызовом функции, которая
// присваивает значение через переданный указатель. Присвоенное значение
// сравнивается с константой, проверка неуспешна и выполнение не достигает
// стока.

#include <stdlib.h>

void callee(int *pointer_param) { *pointer_param = 224; }

int func(int *param) {
  int template_flag = 0;

  int var = 0;
  int other = -38;

  if (param == NULL) {
    template_flag = 57;
  }

  callee(&var);

  if (var > other) {
    exit(0);
  }

  *param = 0;

  return 0;
}
