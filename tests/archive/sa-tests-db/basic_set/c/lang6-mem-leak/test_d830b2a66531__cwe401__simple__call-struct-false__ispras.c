// Авторы теста: ИСП РАН
// CWE: 401
// Название: Missing Release of Memory after Effective Lifetime
// Модельный вариант: simple.json
//
// Утечка памяти при выходе из области видимости переменной,
// хранящей указатель на динамическую память, или перезаписи переменной перед
// вызовом free().
//
// Поточный вариант: call-struct-false.c
// Недостижимый путь от источника до стока с проверкой возвращаемого значения
// функции, которое зависит от значения второго поля локальной для вызывающей
// функции структуры с константными значениями; структура передаётся по значению
// в вызываемую функцию через её аргумент; возвращаемое из вызываемой функции
// значение равно единице, поэтому проверка в вызывающей функции успешна и
// выполнение завершается, не достигнув стока.

#include <stdio.h>
#include <stdlib.h>

struct struct_type {
  int field1;
  int field2;
  int field3;
};

int callee(struct struct_type struct_param) {
  if (struct_param.field2 >= 0)
    return 1;
  else
    return 0;
}

void func(size_t size) {
  void *f = NULL;

  struct struct_type struct_var = {-5, 0, 5};

  f = malloc(size);

  if (callee(struct_var)) {
    exit(0);
  }

  if (f != NULL) {
    free(f);
  }
}
