// Авторы теста: ИСП РАН
// CWE: 476
// Название: NULL Pointer Dereference
// Модельный вариант: assign_ret_null-deref_op.json
//
// Нулевое значение присваивается с помощью вызова функции, которая всегда
// возвращает ноль. Разыменование указателя осуществляется непосредственно (с
// помощью операции разыменования).
//
// Поточный вариант: error-path-external.c
// Достижимый путь от источника до стока с проверкой результата вызова
// неизвестной внешней функции между ними, переход по метке со стоком в случае
// истинности проверки.

#include <stdlib.h>

int external_func(void);

int *null_func(int null_func_arg) { return NULL; }

void func(void) {
  int *pointer, other, dummy;
  pointer = &dummy;

  pointer = null_func(75);

  if (external_func())
    goto error_label;

  pointer = &other;

  exit(0);

error_label:
  *pointer = 0; // FLAW
}
