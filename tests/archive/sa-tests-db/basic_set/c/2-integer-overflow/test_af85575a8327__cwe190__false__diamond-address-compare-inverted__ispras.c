// Авторы теста: ИСП РАН
// CWE: 190
// Название: Integer Overflow or Wraparound
// Модельный вариант: false.json
//
// Знаковое значение вводится с помощью функции scanf.
// Введенное значение без проверки используется в для вычисления аргумента
// вызова функции malloc.
//
// Поточный вариант: diamond-address-compare-inverted.c
// Недостижимый путь от источника до стока с проверками похожих условий, которые
// сравнивают адреса полей.

#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

int *global;

struct struct_type {
  int field1;
  int field2;
  int field3;
};

struct struct_type struct_glob;

void func(void) {
  int number = 0;

  int *addr1 = &struct_glob.field1;
  int *addr2 = &struct_glob.field2;

  if (addr2 > addr1) {
    scanf("%d", &number);
  }

  if (addr2 < addr1) {
    global = (int *)malloc(number * sizeof(int));
  }

  free(global);
}
