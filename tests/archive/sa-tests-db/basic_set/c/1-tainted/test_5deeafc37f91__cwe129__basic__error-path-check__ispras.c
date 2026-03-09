// Авторы теста: ИСП РАН
// CWE: 129
// Название: Basic improper validation of array index
// Модельный вариант: basic.json
//
// Чтение данных от пользователя с помощью функции scanf.
// Использование прочитанного значения без проверки в качестве индекса для
// чтения элемента массива фиксированного размера.
//
// Поточный вариант: error-path-check.c
// Достижимый путь от источника до стока с проверкой условия наличия уязвимости
// между ними, переход по метке в случае истинности проверки.

#include <stdio.h>
#include <stdlib.h>

int store;

void func(void) {
  int index = 0, array[5] = {0, 1, 2, 3, 4};

  scanf("%d", &index);

  if ((index < 0 || index > 4))
    goto error_label;

  index = 0;

  exit(0);

error_label:
  store = array[index]; // FLAW
}
