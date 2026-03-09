// Авторы теста: ИСП РАН
// CWE: 129
// Название: Basic improper validation of array index
// Модельный вариант: basic.json
//
// Чтение данных от пользователя с помощью функции scanf.
// Использование прочитанного значения без проверки в качестве индекса для
// чтения элемента массива фиксированного размера.
//
// Поточный вариант: call-with-assign-false.c
// Достижимый путь от источника до стока с вызовом функции, которая присваивает
// значение через переданный указатель. Присвоенное значение сравнивается с
// константой, проверка успешна и выполнение завершается.

#include <stdio.h>
#include <stdlib.h>

int store;

void callee(int *pointer_param) { *pointer_param = 128; }

void func(void) {
  int index = 0, array[5] = {0, 1, 2, 3, 4};

  int var = 0;

  scanf("%d", &index);

  callee(&var);

  if (var > 114) {
    exit(0);
  }

  store = array[index];
}
