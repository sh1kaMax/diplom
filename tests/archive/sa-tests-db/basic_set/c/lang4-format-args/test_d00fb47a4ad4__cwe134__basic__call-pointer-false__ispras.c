// Авторы теста: ИСП РАН
// CWE: 134
// Название: Use of Externally Controlled Format String
// Модельный вариант: basic.json
//
//
// Поточный вариант: call-pointer-false.c
// Недостижимый путь от источника до стока с проверкой возвращаемого значения
// функции, которое зависит от значения локальной для вызываемой функции
// переменной, адрес которой непосредственно передаётся в вызываемую функцию
// через её аргумент; возвращаемое из вызываемой функции значение равно единице,
// поэтому проверка в вызывающей функции успешна и выполнение завершается, не
// достигнув стока.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const char safe_format[] = "Safe format string";

int callee(int *pointer_param) {
  if (*pointer_param >= 0)
    return 1;
  else
    return 0;
}

void func(void) {
  char format[34] = "Initial format string";

  int var = 0;

  scanf("%33s", format);

  if (callee(&var)) {
    exit(0);
  }

  printf(format);
}
