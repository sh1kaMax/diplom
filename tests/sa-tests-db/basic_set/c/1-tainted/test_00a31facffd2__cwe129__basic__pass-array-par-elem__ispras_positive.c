// Авторы теста: ИСП РАН
// CWE: 129
// Название: Basic improper validation of array index
// Модельный вариант: basic.json
//
// Чтение данных от пользователя с помощью функции scanf.
// Использование прочитанного значения без проверки в качестве индекса для
// чтения элемента массива фиксированного размера.
//
// Поточный вариант: pass-array-par-elem.c
// Достижимый путь от источника до стока. И источник и сток находятся под
// условиями, значения которых проходят через элемент массива.

#include <stdio.h>
#include <stdlib.h>

int store;

void func(int param) {
  int index = 0, array[5] = {0, 1, 2, 3, 4};

  int arr[100];
  int some_var = 28;
  if (param < 0 || param > 99)
    exit(0);
  arr[param] = some_var;
  arr[93] = 7;

  if (some_var) {
    scanf("%d", &index);
  }

  if (arr[param]) {
    store = array[index]; // FLAW
  }
}
