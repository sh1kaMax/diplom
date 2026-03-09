// Авторы теста: ИСП РАН
// CWE: 129
// Название: Basic improper validation of array index
// Модельный вариант: basic.json
//
// Чтение данных от пользователя с помощью функции scanf.
// Использование прочитанного значения без проверки в качестве индекса для
// чтения элемента массива фиксированного размера.
//
// Поточный вариант: diamond-plus-call-false.c
// Недостижимый путь от источника до стока с проверками одного и того же
// выражения, результат которого является сложением аргумента функции и
// результата вызова функции.

#include <stdio.h>
#include <stdlib.h>

int store;

int ret_func(int param1) { return param1; }

void func(int param) {
  int index = 0, array[5] = {0, 1, 2, 3, 4};

  int func_res = ret_func(10);

  if (param + func_res > 39) {
    scanf("%d", &index);
  }

  if (param + func_res < 39) {
    store = array[index];
  }
}
