// Авторы теста: ИСП РАН
// CWE: 129
// Название: Basic improper validation of array index
// Модельный вариант: basic.json
//
// Чтение данных от пользователя с помощью функции scanf.
// Использование прочитанного значения без проверки в качестве индекса для
// чтения элемента массива фиксированного размера.
//
// Поточный вариант: diamond-and.c
// Достижимый путь от источника до стока с проверками одного и того же условия с
// использованием битового и.

#include <stdio.h>
#include <stdlib.h>

int store;

void func(int param) {
  int index = 0, array[5] = {0, 1, 2, 3, 4};

  if (param & 0x1D) {
    scanf("%d", &index);
  }

  if (param & 0x1D) {
    store = array[index]; // FLAW
  }
}
