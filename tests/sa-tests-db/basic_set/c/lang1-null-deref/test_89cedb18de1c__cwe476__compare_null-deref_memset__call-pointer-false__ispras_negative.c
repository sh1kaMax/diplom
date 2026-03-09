// Авторы теста: ИСП РАН
// CWE: 476
// Название: NULL Pointer Dereference
// Модельный вариант: compare_null-deref_memset.json
//
// Указатель проверяется на возможное нулевое значение.
// Разыменование указателя в вызове стандартной функции memset.
//
// Поточный вариант: call-pointer-false.c
// Недостижимый путь от источника до стока с проверкой возвращаемого значения
// функции, которое зависит от значения локальной для вызываемой функции
// переменной, адрес которой непосредственно передаётся в вызываемую функцию
// через её аргумент; возвращаемое из вызываемой функции значение равно единице,
// поэтому проверка в вызывающей функции успешна и выполнение завершается, не
// достигнув стока

#include <stdlib.h>
#include <string.h>

void use_mem_to_keep_memset(int *);

int callee(int *pointer_param) {
  if (*pointer_param >= 0)
    return 1;
  else
    return 0;
}

int func(int *param) {
  int template_flag;

  int var = 0;

  if (param == NULL) {
    template_flag = 60;
  }

  if (callee(&var)) {
    exit(0);
  }

  memset(param, 0, sizeof(int));
  use_mem_to_keep_memset(param);

  return 0;
}
