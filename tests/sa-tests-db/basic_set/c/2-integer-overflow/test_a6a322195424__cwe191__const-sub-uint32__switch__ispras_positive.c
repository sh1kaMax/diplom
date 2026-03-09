// Авторы теста: ИСП РАН
// CWE: 191
// Название: Integer Underflow or Wraparound
// Модельный вариант: const-sub-uint32.json
//
// Беззнаковое значение задается с помощью константы 0.
// Данное значение без проверки используется в качестве уменьшаемого для
// вычисления, которое приводит к переполнению снизу.
//
// Поточный вариант: switch.c
// Выполнимый путь от источника до стока с проверкой условия в операторе выбора
// switch; сток расположен в выполняемой ветке оператора выбора.

#include <limits.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

void func(void) {
  uint32_t data = 1;
  uint32_t result;

  int var;

  data = 0;

  var = 0;

  switch (var) {
  case 0:
    result = data - 1; // FLAW
    break;
  case 1:
    exit(0);
  }
}
