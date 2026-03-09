// Авторы теста: ИСП РАН
// CWE: 129
// Название: Basic improper validation of array index
// Модельный вариант: basic.json
//
// Чтение данных от пользователя с помощью функции scanf.
// Использование прочитанного значения без проверки в качестве индекса для
// чтения элемента массива фиксированного размера.
//
// Поточный вариант: switch-inverted-no-break.c
// Невыполнимый путь от источника до стока с проверкой условия в операторе
// выбора switch; выполнение завершается при переходе на ветку оператора выбора
// до достижения стока.

#include <stdio.h>
#include <stdlib.h>

int store;

void func(void) {
  int index = 0, array[5] = {0, 1, 2, 3, 4};

  int var;

  scanf("%d", &index);

  var = 0;

  switch (var) {
  case 0:
    exit(0);
  case 1:
    store = array[index];
    break;
  }
}
