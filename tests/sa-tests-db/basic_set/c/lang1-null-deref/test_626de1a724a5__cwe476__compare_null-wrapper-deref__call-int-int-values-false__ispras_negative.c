// Авторы теста: ИСП РАН
// CWE: 476
// Название: NULL Pointer Dereference
// Модельный вариант: compare_null-wrapper-deref.json
//
// Указатель проверяется на возможное нулевое значение.
// Разыменование указателя осуществляется непосредственно (с помощью операции
// разыменования).
//
// Поточный вариант: call-int-int-values-false.c
// Достижимый путь от источника до стока с проверкой возвращаемого значения
// функции c двумя параметрами, в функцию передаётся по значению локальная
// переменная и константа, проверка в вызывающей функции успешна и выполнение не
// достигает стока

#include <stdlib.h>

void wrapper(int *ptr) { *ptr = 1; }

int callee(int par1, int par2) {
  if (par1 > par2)
    return 1;

  return -1;
}

int func(int *param) {
  int template_flag = 0;

  int other = 72;

  if (param == NULL) {
    template_flag = 38;
  }

  if (callee(other, 235) < 0) {
    exit(0);
  }

  wrapper(param);

  return 0;
}
