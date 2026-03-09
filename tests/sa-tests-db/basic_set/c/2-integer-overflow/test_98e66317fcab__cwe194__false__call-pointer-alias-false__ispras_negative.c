// Авторы теста: ИСП РАН
// CWE: 194
// Название: Unexpected Sign Extension
// Модельный вариант: false.json
//
// Знаковое значение вводится с помощью функции scanf.
// Сконвертированное в более широкое беззнаковое возможно отрицательное значение
// используется в вызове функции strncpy.
//
// Поточный вариант: call-pointer-alias-false.c
// Недостижимый путь от источника до стока с проверкой возвращаемого значения
// функции, которое зависит от значения локальной для вызываемой функции
// переменной, адрес которой сначала сохраняется в локальную
// переменную-указатель, а затем с его помощью передаётся в вызываемую функцию
// через её аргумент; возвращаемое из вызываемой функции значение равно единице,
// поэтому проверка в вызывающей функции успешна и выполнение завершается, не
// достигнув стока.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *source_string;

int callee(int *pointer_param) {
  if (*pointer_param >= 0)
    return 1;
  else
    return 0;
}

void func(void) {
  char string[27];
  short number = 26;

  int local_var = 0, *local_pointer = &local_var;

  scanf("%hd", &number);
  if (number > 26)
    number = 26;

  if (callee(local_pointer)) {
    exit(0);
  }

  strncpy(string, source_string, number);
  string[26] = '\0';
}
