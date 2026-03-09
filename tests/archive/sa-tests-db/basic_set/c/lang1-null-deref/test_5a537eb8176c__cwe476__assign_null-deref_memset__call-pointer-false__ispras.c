// Авторы теста: ИСП РАН
// CWE: 476
// Название: NULL Pointer Dereference
// Модельный вариант: assign_null-deref_memset.json
//
// Нулевое значение присваивается явно.
// Разыменование указателя в вызове стандартной функции memset.
//
// Поточный вариант: call-pointer-false.c
// Недостижимый путь от источника до стока с проверкой возвращаемого значения
// функции, которое зависит от значения локальной для вызываемой функции
// переменной, адрес которой непосредственно передаётся в вызываемую функцию
// через её аргумент; возвращаемое из вызываемой функции значение равно единице,
// поэтому проверка в вызывающей функции успешна и выполнение завершается, не
// достигнув стока.

#include <stdlib.h>
#include <string.h>

void use_mem_to_keep_memset(int *);

int callee(int *pointer_param) {
  if (*pointer_param >= 0)
    return 1;
  else
    return 0;
}

void func(void) {
  int *pointer, other, dummy;
  pointer = &dummy;

  int var = 0;

  pointer = NULL;

  if (callee(&var)) {
    exit(0);
  }

  memset(pointer, 0, sizeof(int));
  use_mem_to_keep_memset(pointer);
}
