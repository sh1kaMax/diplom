// Авторы теста: ИСП РАН
// CWE: 195
// Название: Signed to Unsigned Conversion Error
// Модельный вариант: basic.json
//
// Знаковое значение вводится с помощью функции scanf.
// Сконвертированное в беззнаковое возможно отрицательное значение
// используется в вызове функции strncpy.
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

char *source_string;

int callee(int *pointer_param) {
  if (*pointer_param > 0)
    return 1;
  else
    return 0;
}

void func(void) {
  char string[27];
  int number = 26;

  int local_var = 0, *local_pointer = &local_var;

  scanf("%d", &number);
  if (number > 26)
    number = 26;

  if (callee(local_pointer)) {
    exit(0);
  }

  strncpy(string, source_string, number); // FLAW
  string[26] = '\0';
}
