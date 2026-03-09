// Авторы теста: ИСП РАН
// CWE: 129
// Название: Basic improper validation of array index
// Модельный вариант: basic.json
//
// Чтение данных от пользователя с помощью функции scanf.
// Использование прочитанного значения без проверки в качестве индекса для
// чтения элемента массива фиксированного размера.
//
// Поточный вариант: loop-dowhile.c
// Участок кода от источника до стока с циклом do-while с фиксированным
// количеством итераций между ними.

#include <stdio.h>
#include <stdlib.h>

int store;

void func(void) {
  int index = 0, array[5] = {0, 1, 2, 3, 4};

  int var;

  scanf("%d", &index);

  var = 0;

  do {
    var++;
  } while (var < 16);

  store = array[index]; // FLAW
}
