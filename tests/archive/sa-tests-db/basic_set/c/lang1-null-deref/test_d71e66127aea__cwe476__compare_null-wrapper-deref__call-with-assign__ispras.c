// Авторы теста: ИСП РАН
// CWE: 476
// Название: NULL Pointer Dereference
// Модельный вариант: compare_null-wrapper-deref.json
//
// Указатель проверяется на возможное нулевое значение.
// Разыменование указателя осуществляется непосредственно (с помощью операции
// разыменования).
//
// Поточный вариант: call-with-assign.c
// Достижимый путь от источника до стока с вызовом функции, которая присваивает
// значение через переданный указатель. Присвоенное значение сравнивается с
// константой, проверка неуспешна и выполнение достигает стока.

#include <stdlib.h>

void wrapper(int *ptr) { *ptr = 1; }

void callee(int *pointer_param) { *pointer_param = 281; }

int func(int *param) {
  int template_flag = 0;

  int var = 0;
  int other = 118;

  if (param == NULL) {
    template_flag = 5;
  }

  callee(&var);

  if (var < other) {
    exit(0);
  }

  wrapper(param); // FLAW

  return 0;
}
