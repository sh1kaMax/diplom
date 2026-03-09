// Авторы теста: ИСП РАН
// CWE: 824
// Название: Use of Uninitialized Pointer
// Модельный вариант: sometimes-init.json
//
// Запись значения по указателю, инициализированному не на всех путях.
//
// Поточный вариант: if-check-filtered.c
// Достижимый путь от источника до стока с проверкой условия наличия уязвимости
// между ними, фильтрация в случае истинности проверки.

#include <stdlib.h>

void func(int *input_ptr, int cond_param) {

  int *x;
  if (cond_param > 0) {
    x = input_ptr;
  }

  if (1) {
    x = input_ptr;
  }

  *x = 71;
}
