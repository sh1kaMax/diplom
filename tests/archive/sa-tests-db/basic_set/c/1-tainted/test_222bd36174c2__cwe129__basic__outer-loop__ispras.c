// Авторы теста: ИСП РАН
// CWE: 129
// Название: Basic improper validation of array index
// Модельный вариант: basic.json
//
// Чтение данных от пользователя с помощью функции scanf.
// Использование прочитанного значения без проверки в качестве индекса для
// чтения элемента массива фиксированного размера.
//
// Поточный вариант: outer-loop.c
// Прямолинейный участок кода от источника до стока внутри цикла.

#include <stdio.h>
#include <stdlib.h>

int store;

void func(void) {
  int iter_var;

  int index = 0, array[5] = {0, 1, 2, 3, 4};

  for (iter_var = 4; iter_var < 10; iter_var++) {
    scanf("%d", &index);

    store = array[index]; // FLAW
  }
}
