// Авторы теста: ИСП РАН
// CWE: 129
// Название: Basic improper validation of array index
// Модельный вариант: basic.json
//
// Чтение данных от пользователя с помощью функции scanf.
// Использование прочитанного значения без проверки в качестве индекса для
// чтения элемента массива фиксированного размера.
//
// Поточный вариант: switch-flipped-no-break.c
// Выполнимый путь от источника до стока с проверкой условия в операторе выбора
// switch; сток расположен в выполняемой ветке оператора выбора.

#include <stdio.h>
#include <stdlib.h>

int store;

void func(void) {
  int index = 0, array[5] = {0, 1, 2, 3, 4};

  int var;

  scanf("%d", &index);

  var = 0;

  switch (var) {
  case 1:
    exit(0);
  case 0:
    store = array[index]; // FLAW
    break;
  }
}
