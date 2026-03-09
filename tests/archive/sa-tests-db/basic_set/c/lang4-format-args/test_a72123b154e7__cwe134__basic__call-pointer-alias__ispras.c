// Авторы теста: ИСП РАН
// CWE: 134
// Название: Use of Externally Controlled Format String
// Модельный вариант: basic.json
//
//
// Поточный вариант: call-pointer-alias.c
// Достижимый путь от источника до стока с проверкой возвращаемого значения
// функции, которое зависит от значения локальной для вызываемой функции
// переменной, адрес которой сначала сохраняется в локальную
// переменную-указатель, а затем с его помощью передаётся в вызываемую функцию
// через её аргумент; возвращаемое из вызываемой функции значение нулевое,
// поэтому проверка в вызывающей функции неуспешна и выполнение достигает стока.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const char safe_format[] = "Safe format string";

int callee(int *pointer_param) {
  if (*pointer_param > 0)
    return 1;
  else
    return 0;
}

void func(void) {
  char format[36] = "Initial format string";

  int local_var = 0, *local_pointer = &local_var;

  scanf("%35s", format);

  if (callee(local_pointer)) {
    exit(0);
  }

  printf(format); // FLAW
}
